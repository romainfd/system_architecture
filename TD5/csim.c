// Romain Fouilland romain.fouilland
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cachelab.h"
#include <string.h>

/* Globals set by command line args */
int verbosity = 0; /* print trace if set */
int s = 0;         /* set index bits */
int b = 0;         /* block offset bits */
int E = 0;         /* associativity */
char* trace_file = NULL;

/*
 * printUsage - Print usage info
 */
void printUsage(char* argv[])
{
    printf("Usage: %s [-hv] -s <num> -E <num> -b <num> -t <file>\n", argv[0]);
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    printf("\nExamples:\n");
    printf("  linux>  %s -s 4 -E 1 -b 4 -t traces/yi.trace\n", argv[0]);
    printf("  linux>  %s -v -s 8 -E 2 -b 4 -t traces/yi.trace\n", argv[0]);
    exit(0);
}

int getSet() {
  return 1;
}


// converts an int to an array of its digits in the binary decomposition
void int_to_bin_digit(int in, char* out) {
    for (int i = 63; i >= 0; i--) {
        out[i] = (in & 1) ? '1' : '0';
        in >>= 1;
    }
}

// converts the binary decomposition into its int value
int bin_digit_to_int(char* in, int size) {
    int nb = 0;
    int pow = 1;
    for (int i = size - 1; i >= 0; i--) {
        nb += (in[i] == '1' ? 1 : 0) * pow;
        pow <<= 1;
    }
    return nb;
}

// inserts e as the most used by moving to the right a bloc of size bloc_len
void add_most_used(int* arr, int e, int bloc_len) {
    for (int i = 1 + (bloc_len - 1); i > 0; i --) {  // bloc_len --> 1 => bloc_len elements
        arr[i + 1] = arr[i];
    }
    arr[1] = e;
}

/*
 * main - Main routine 
 */
int main(int argc, char* argv[])
{
  char c;
  
  while( (c=getopt(argc,argv,"s:E:b:t:vh")) != -1){
    switch(c){
    case 's':
      s = atoi(optarg);
      break;
    case 'E':
      E = atoi(optarg);
      break;
    case 'b':
      b = atoi(optarg);
      break;
    case 't':
      trace_file = optarg;
      break;
    case 'v':
      verbosity = 1;
      break;
    case 'h':
      printUsage(argv);
      exit(0);
    default:
      printUsage(argv);
      exit(1);
    }
  }

  /* Make sure that all required command line args were specified */
  if (s == 0 || E == 0 || b == 0 || trace_file == NULL) {
    printf("%s: Missing required command line argument\n", argv[0]);
    printUsage(argv);
    exit(1);
  }

  // We build the cache
  char ***cache;
  int S = 1 << s;
  cache = (char***) malloc(sizeof(char**)*S);
  for (int i = 0; i < S; i++) {
    cache[i] = (char**) malloc(sizeof(char*) * E);
    for (int j = 0; j < E; j++) {
      cache[i][j] = (char*) malloc(sizeof(char) * (64 - s - b + 1));
      // we just store the tag because we don't need the rest: the mid bits are in the set encoding, the lowest are all stored
    }
  }

  // to implement the LRU (last recently used)
  // for each set, we store the list of the index of the lines stored in the cache
  // the first value for each set is the number of lines stored in this set
  // the more on the left, the more recently used the line was
  // | nbOfTags | index in the cache of the last used tag | index in the cache of the second last used tag ... |
    int **lines;
    lines = (int**) malloc(sizeof(int*)*S);
    for (int i = 0; i < S; i++) {
        lines[i] = (int*) malloc(sizeof(int) * (1 + E));
        lines[i][0] = 0;  // initially we don't store any line
    }
    // Remark: an alternative solution could have been to use a LinkedList of struct { tag, next }
    // in this case, the cache would just have stored the head
    // to update the last recently used, we would just have changed 3 pointers (the head, the predecessor of our tag_node, the tag_node)
    // instead of moving everybody to the right in the array
    // however, I assumed that E was quite small and that it was faster to have an array instead of a LinkedList of struct

  // the containers for the values just read
    char op;
    int adr, size;
    // the containers for the parsed values: complete address and the deduced tag and set
  char *tag = malloc(sizeof(char) * (64 - s - b + 1));
  char *set = malloc(sizeof(char) * s);
  char *adr_bin = malloc(sizeof(char) * 64);

  // our global variables
  int nbLines;
  int hits = 0, misses = 0, evictions = 0;

  // we read the input of reference traces
    int r;
    FILE *file  = fopen(trace_file, "r"); // read only
    // test for file not existing.
    if (file == NULL) {
        printf("Error! Could not open file\n");
        exit(-1);
    }
    r = fscanf(file, " %c %x,%d\n", &op, &adr, &size);
  while (r != EOF) {
    if (r == 3) {  // correct parsing of the input trace
        if (op != 'I') {  // we don't consider instruction loads
            if (verbosity == 1) { printf("%c %x,%d", op, adr, size); }
            // CACHE LOGIC:
            // 1. we compute the set and tag from the address (in binary decomposition) based on the given values of s and b
            int_to_bin_digit(adr, adr_bin);
            for (int j = 0; j < 64 - s - b; j++) {
                tag[j] = adr_bin[j];
            }
            tag[64 - s - b] = '\0';  // we end the string
            for (int i = 0; i < s; i++) {
                set[i] = adr_bin[64 - s - b + i];
            }
            // no need to end here because we will give the size to convert from binary decomposition to int

            /* DEBUG: Display of set and tag
            printf("%s", "set: ");
            for (int i = 0; i < s; i++) { printf("%c", set[i]); }
            printf("%s", "\ntag: ");
            for (int i = 0; i < 64 - s - b; i++) { printf("%c", tag[i]); }
            printf("%c", '\n');
            */

            // we go through the cache to know if we hit, we follow the MRU order : most recently used to last recently used by using lines[]:
            int set_int = bin_digit_to_int(set, s);  // the index of the set
            nbLines = lines[set_int][0];  // the nb of lines stored in our set
            char hit = '0';
            int l = 1, MRU_index;
            for (; l < 1 + nbLines; l++) { // offset of one because of nbLines
                MRU_index = lines[set_int][l];
                if (strcmp(cache[set_int][MRU_index], tag) == 0) {  // the value we wanted was stored in our cache !
                    hit = '1';
                    break;  // useless to go further as there is at most 1 match
                }
            }
            if (hit == '1') {
                if (verbosity == 1) { printf(" %s", "hit"); }
                hits++;
                // we have to move the tag of the trace since it was the most recently used
                add_most_used(lines[set_int], lines[set_int][l], l - 1);
                // we move the l - 1 indices below
                // and eventually add the hit index in the first position
            } else {
                if (verbosity == 1) { printf(" %s", "miss"); }
                misses++;
                // we have to cache it
                int index;  // at the index position of the cache[set_int][]
                // Case 1: our set isn't full => just add it
                if (nbLines < E) {
                    index = nbLines;
                    lines[set_int][0]++;  // nbLines++
                    // and put its index in the first position
                    add_most_used(lines[set_int], index, nbLines);
                } else {
                // Case 2: full => replace the least used
                    index = lines[set_int][1 + (E - 1)];  // offset + the last stored elem in MRU order => least used
                    // we will overwrite it with our just-asked value => put its index in the first position
                    add_most_used(lines[set_int], index, E - 1);  // no need to move the last one as we will get overwritten
                    if (verbosity == 1) { printf(" %s", "eviction"); }
                    evictions++;
                }
                // in all cases we cache our tag
                strncpy(cache[set_int][index], tag, 64 - s - b + 1);
            }
            if (op == 'M') {
                // we just stored the value for the load => we hit for the store
                if (verbosity == 1) { printf(" %s", "hit"); }
                hits++;
            }
            if (verbosity == 1) { printf("%c", '\n'); }
        }
    } else {
      printf("Error, line in wrong format!\n\n");
      return 1;
    }
    r = fscanf(file, " %c %x,%d\n", &op, &adr, &size);
  }
  // we free the allocated memory
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < E; j++) {
            free(cache[i][j]);
        }
        free(cache[i]);
    }
    free(cache);
    for (int i = 0; i < S; i++) {
        free(lines[i]);
    }
    free(lines);
    free(tag);
    free(set);
    free(adr_bin);
  printSummary(hits, misses, evictions);
  return 0;
}
