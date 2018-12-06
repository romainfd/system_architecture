/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 * 
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "Team SF",
    /* First member's full name */
    "Romain Fouilland",
    /* First member's email address */
    "romain.fouilland@polytechnique.edu",
    /* Second member's full name (leave blank if none) */
    "Vincent Dallard",
    /* Second member's email address (leave blank if none) */
    "vincent.dallard.x16@polytechnique.edu"
};

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* The number of buckets used */
#define NB_OF_BUCKETS 20

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))

#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))

#define MAX_SIZE *((int*) mem_heap_lo())

#define BIG_BUCKET ((int) mem_heap_lo() + sizeof(int) + (NB_OF_BUCKETS - 1) * (sizeof(int) + sizeof(size_t*)))

#define GET_BLOCK_LEN(ptr) ((*((int*)(((void*) ptr) - SIZE_T_SIZE))) & (~1))

#define IS_FREE(ptr) (1 - ((*((int*)(((void*) ptr) - SIZE_T_SIZE))) & 1))

#define GET_NEXT(ptr) ((size_t**) *ptr)

#define GET_PREV(ptr) ((size_t**) *(ptr + 1))

#define WRITE_HEADER(ptr, val)  *(int*)((void*)ptr - SIZE_T_SIZE) = val

#define WRITE_FOOTER(ptr, val)  *(int*)((void*)ptr + GET_BLOCK_LEN(ptr)) = val


// CHECKER
int mm_check(void) {
    //printf("################# //mm_check #################\n");
    int* start = (int*) mem_heap_lo();
    int l;
    //printf("Size of the biggest bucket: %u\n", *(start++));
    for (l = 0; l < NB_OF_BUCKETS - 1; l++) {
        //printf("Size of the bucket: %u\n", *(start++));
        //printf("Address of the head: %x pointing to %x\n", (int) start, (int) *start);
        // we loop through the list
        size_t** head = (size_t**) *(start++);
        while (head != NULL) {
            // we print the current block information
            //printf("Block length: %u, address: %x\n", GET_BLOCK_LEN(head), (int) head);
            //printf("Prev: %x\n", (int) GET_PREV(head));
            //printf("Next: %x\n", (int) GET_NEXT(head));
            if (IS_FREE(head) != 1) {
                //printf("ERROR: THE BLOCK SHOULD BE FREE\n\n");
            }
            head = (size_t**) *head;
        }
    }
    //printf("Address of the big bucket: %x pointing to %x\n", (int) start, (int) *start);
    // we loop through the big empty spaces
    size_t** head = (size_t**) *start;
    while (head != NULL) {
        // we print the current block information
        //printf("Block length: %u, address: %x\n", GET_BLOCK_LEN(head), (int) head);
        //printf("Prev: %x\n", (int) GET_PREV(head));
        //printf("Next: %x\n", (int) GET_NEXT(head));
        if (IS_FREE(head) != 1) {
            //printf("ERROR: THE BLOCK SHOULD BE FREE");
        }
        head = (size_t**) *head;
    }
    //printf("################# //mm_check #################\n\n");    
    return 0;
}

/* 
 * mm_init - initialize the malloc package.
 */
int mm_init(void) {
    //printf("%s", "\n####################################### Call to mm_init #######################################\n");
    //printf("Mem_heap_low: %x\n", (int) mem_heap_lo());
    // we ask for the memory for our structure
    mem_sbrk(NB_OF_BUCKETS * (sizeof(int) + sizeof(size_t*)));
    //printf("Mem_heap_high: %x\n", (int) mem_heap_hi());

    // we add our buckets structure on the top of the heap
    int *size;
    size = (int*) mem_heap_lo();
    // *(size++) = NB_OF_BUCKETS;  // useless since we can use directly NB_OF_BUCKETS
    *(size++) = (8 << (NB_OF_BUCKETS - 2));
    // loop to build all the sizes (leave 1 bucket for the big ones)
    int current_size = 8;
    size_t **list = (size_t**) size;
    int l;
    for (l = 0; l < NB_OF_BUCKETS - 1; l++) {
        //printf("Current bucket address: %x\n",(int) (list));
        size = (int*) list;
        *(size++) = current_size;
        list = (size_t**) size;
        *list++ = NULL;
        current_size *= 2;
    }
    // for the big ones
    *list++=NULL;
    

    // From now on, list is useless (we have already stored our buckets structure)
    // BUt we have to write our first block directly here
    //*list = (size_t*) (list + 1);
    //size_t* head = (size_t*) list;
    //*head = 153;
    ////printf("END1: %u\n", *((int*) list));
    ////printf("END2: %u\n", (int) **(list - 1));

        // +1 to say its allocated
    //mm_check();
    // TODO: we use the end of the initial heap (for the moment we have no free memory !)
    // 1. compute its size
    // 2. add it to the correct bucket during construction
    // OR add it to the infinite one if no match
    return 0;
}

/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc_naif(size_t size) {
    int newsize = ALIGN(size + SIZE_T_SIZE);
    void *p = mem_sbrk(newsize);
    if (p == (void *)-1)
	return NULL;
    else {
        *(size_t *)p = size;
        return (void *)((char *)p + SIZE_T_SIZE);
    }
}


/* ;
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size_asked) {
    //printf("Malloc size asked: %u\n",(int) (size_asked));
    // //printf("Asked for: %u\n",(int) (size_asked));
    int newsize = ALIGN(size_asked);

    // 1. We find the good list
    size_t** list;
    int* size = ((int*) mem_heap_lo()) + 1;
    int sizeInt;  // the size of the block we are writing in
    int noBucketFound = 1;
    size_t* curr;
    int blockLen = -1;   
    if (newsize <= MAX_SIZE) {
        // we have to go through our buckets
        list = (size_t**) (size + 1); 
        while (*size < newsize) { // bucket_index < NB_OF_BUCKETS - 1  useless thanks to the if / else
            // //printf("Current address: %u\n",(int) (size));        
            // we move to the next block
            size = (int*) (list + 1);
            list = (size_t**) (size + 1);
        }

        // 2. We go through the list to find a good spot AND through the lists after
        sizeInt = *size;
        while (noBucketFound == 1 && sizeInt <= MAX_SIZE) { 
            // we go through the list
            curr = *list;  // curr points to the current empty block
            while (noBucketFound == 1 && curr != NULL) {
                blockLen = *((int*) ((void*) curr - SIZE_T_SIZE));
                if (blockLen >= newsize) {
                    // it fits !!
                    noBucketFound = 0;
                    break;
                } else {
                    curr = (size_t*) *curr;
                }
            }
            // we move to the next bucket
            size = (int*) (list + 1); 
            if (sizeInt == MAX_SIZE){
                sizeInt = MAX_SIZE + 1;
            } else {
                sizeInt = *size;
            }
            list = (size_t**) (size + 1);
        }
    }
    if (noBucketFound == 1) {
        // in all cases, we loop through the bucket of the big ones
        list = (size_t**) BIG_BUCKET;
        curr = *list;  // we point to the fist big empty block
        while (noBucketFound == 1 && curr != NULL) {
            blockLen = *((int*) ((void*) curr - SIZE_T_SIZE));
            if (blockLen >= newsize) {
                // it fits !!
                noBucketFound = 0;
            } else {
                curr = (size_t*) *curr;
            }
        }
    }
    
    if (noBucketFound == 0) {
        // 3. We found a match
        // 3.a Remove it from its list
        size_t** start = (size_t**) curr;
        // we maj the block nf61bf01cext / prev
        // PREV
        size_t** prev = (size_t**) *(start + 1); // can never be null
        // we change the next of this block
        *(prev) = *start;

        // NEXT
        if (*start != NULL) {
            // in that case, start is a size_t**
            size_t** next = (size_t**) *start;
            // we change the previous of this block
            *(next + 1) = *(start + 1);
        }
        
        // 3.b add the rest back in the buckets 
        // 3.b.1 Find the good list
        int restSize = blockLen - newsize - 2 * SIZE_T_SIZE;
        if (restSize < 8) {
            // extend our block to take this useless thing
            newsize = blockLen;
        } else {
            // else we put it back in our bucket list
            size_t** list;
            int* size = ((int*) mem_heap_lo()) + 1;
            if (restSize <= MAX_SIZE) {
                // we have to go through our buckets
                list = (size_t**) (size + 1); 
                while (*size < restSize) {
                    // we move to the next block
                    size = (int*) (list + 1);
                    list = (size_t**) (size + 1);
                }
            } else {
                list = (size_t**) BIG_BUCKET;
            }
            // list contains the list in which we should add the rest

            // 3.b.2 Write the headers
            size_t** restStart = (size_t**) ((void*) start + newsize + 2 * SIZE_T_SIZE);
            WRITE_HEADER(restStart, restSize);
            WRITE_FOOTER(restStart, restSize);
            //printf("Start: %x, restStart %x\n", (int) start, (int) restStart);

            // 3.b.3 Add it to the list
            if (*list == NULL) {
                // we add the first block to this list
                // we set our next to next (to know when to stop the loop in a list)
                *restStart = NULL;
                *(restStart + 1) = (size_t*) list;
                *list = (size_t*) restStart;
            } else {
                // we add a new head
                size_t** formerHead = (size_t**) *list;
                *list = (size_t*) restStart;
                *restStart = (size_t*) formerHead;
                *(restStart + 1) = (size_t*) list;
                *(formerHead + 1) = (size_t*) restStart;
            }
        } /*else {
            // there is a too small block to be kept => mark it as used (to avoid bad coalesce)
            void* nextBlock = (void*) ((void*)start + blockLen + SIZE_T_SIZE);
            int* toEmpty = (int*) ((void*)start + newsize + SIZE_T_SIZE);
            while ((void*) toEmpty < nextBlock) {
                *toEmpty = 1;  // say occupied
                toEmpty++;  // we move to the next
            }
        }*/

        // 3.c We write the header / footer
        WRITE_HEADER(start, newsize + 1);
        // we write the footer
        // +1 to say its allocated        
        WRITE_FOOTER(start, newsize + 1);

        // 3.d return the memory location
        //printf("Allocated pointer: %x\n",(int) (start));   
        //mm_check();         
        return (void *) start;
    } else {
        // 4. We found NO match => simply ask for memory
        int* p = mem_sbrk(newsize + 2 * SIZE_T_SIZE);
        if (p == (int*)-1)
            return NULL;
        else {
            // we write the header
            // +1 to say its allocated
            *p = (int) newsize + 1;
            // we write the footer
            // +1 to say its allocated        
            *(int*)(((void*)p) + newsize + SIZE_T_SIZE) = newsize + 1;
            //printf("Allocated pointer: %x\n",(int) ((void *)p + SIZE_T_SIZE));    
            //mm_check();
            return ((void *)p + SIZE_T_SIZE);
        }
    }
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free_naif(void *ptr) {

}

void mm_free(void *ptr) {
    //printf("Free: pointer: %x\n",(int) (ptr));    
    // 1. Should we coalesce with the block left
    int footerLeft = *(int*)(ptr - 2 * SIZE_T_SIZE);
    int mergeLeft = 1 - (footerLeft & 1);

    // 2. Should we coalesce with the block Right
    int len = GET_BLOCK_LEN(ptr);  // -1 because it was occupied
    int headerRight = *(int*)(ptr + len + SIZE_T_SIZE);
    int mergeRight = 1 - (headerRight & 1);

    // 3. we compute the length of the coalesced block
    size_t** start = (size_t**) ptr;
    if (mergeLeft == 1) {
        if ((int) (ptr - 2 * SIZE_T_SIZE) > (int) BIG_BUCKET) {  //we make sure not to coalesce with the empty space outside of our heap
            //printf("Coalesce left");        
            start = (size_t**) (ptr - footerLeft - 2 * SIZE_T_SIZE);  // our block starts on the start of the block Left
            len += footerLeft + 2 * SIZE_T_SIZE;

            // we maj the block Left next / prev
            // PREV
            size_t** prevOfLeft = (size_t**) *(start + 1); // can never be null
            // we change the next of this block
            *(prevOfLeft) = *start;  // we jump over the left block

            // NEXT
            if (*start != NULL) {
                // in that case, start is a size_t**
                size_t** nextOfLeft = (size_t**) *start;
                // we change the previous of this block
                *(nextOfLeft + 1) = *(start + 1);
            }
        } else {
            // we don't coalesce on the left
            start = (size_t**) ptr;
        }
    }
    if (mergeRight == 1) {
        //printf("Coalesce right");
        size_t** rightStart = (size_t**) (((void*)start) + len + 2 * SIZE_T_SIZE);
        if ((int) rightStart < (int) mem_heap_hi()) {  //we make sure not to coalesce with the empty space outside of our heap
            len += headerRight + 2 * SIZE_T_SIZE;
            // we maj the block right next / prev
            // PREV
            size_t** prevOfRight = (size_t**) *(rightStart + 1); // can never be null
            // we change the next of this block
            *(prevOfRight) = *rightStart;  // we jump over the Right block

            // NEXT
            if (*rightStart != NULL) {
                // in that case, rightStart BIG_BUCKETis a size_t**
                size_t** nextOfRight = (size_t**) *rightStart;
                // we change the previous of this block
                *(nextOfRight + 1) = *(rightStart + 1);
            }
        }
    }
    // we have the length, the start and the left/right blocks have eventually been removed from their lists

    // 4. Write header and footer
    size_t* header = (size_t*) (((void*)start) - SIZE_T_SIZE);
    *header = len;
    size_t* footer = (size_t*) (((void*)start) + len);
    *footer = len;

    // 5. We find the good bucket size in our bucket list structure
    size_t** list;
    if (len <= MAX_SIZE) {
        // we have to go through our buckets
        int* size = ((int*) mem_heap_lo()) + 1;
        list = (size_t**) (size + 1); 
        while (*size < len) { // bucket_index < NB_OF_BUCKETS - 1  useless thanks to the if / else
            // //printf("Current address: %u\n",(int) (size));        
            // we move to the next block
            size = (int*) (list + 1);
            list = (size_t**) (size + 1);
        }
    } else {
        // we are a big space !
        list = (size_t**) BIG_BUCKET;
    }
    // list is a pointer to the head of the list of the correct size for our empyt space

    // 6. We add our space at the start of the list
    if (*list == NULL) {
        // we add the first block to this list
        // we set our next to next (to know when to stop the loop in a list)
        *start = NULL;
        *(start + 1) = (size_t*) list;
        *list = (size_t*) start;
    } else {
        // we add a new head
        size_t** formerHead = (size_t**) *list;
        *list = (size_t*) start;
        *start = (size_t*) formerHead;
        *(start + 1) = (size_t*) list;
        *(formerHead + 1) = (size_t*) start;
    }
    //mm_check();
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    } else if (size == 0) {
        free(ptr);
        return NULL;
    } else {
        if (size <= (int) GET_BLOCK_LEN(ptr)) {
            int restSize = (int) GET_BLOCK_LEN(ptr) - size - 2 * SIZE_T_SIZE;
            if (restSize < 8) {
                // we can't use the rest => do nothing
                return ptr;
            } else {
                // we can just write on part of our current block and put the rest in the bucket list
                // we alloc the first part
                WRITE_HEADER(ptr, size + 1);  // +1 to say allocated
                WRITE_FOOTER(ptr, size + 1);  // reads the header to get the position     
                // we free the rest       
                size_t** restStart = (size_t**) (ptr + size + 2 * SIZE_T_SIZE);
                WRITE_HEADER(restStart, restSize);
                WRITE_FOOTER(restStart, restSize);
                free(restStart);
                return ptr;
            }
        } else {
            // not enough space => simply malloc somewhere else and free
            void* newptr = mm_malloc(size);
            if (newptr == NULL)
                return NULL;
            memcpy(newptr, ptr, size);
            mm_free(ptr);
            return newptr;
        }
    }
}









