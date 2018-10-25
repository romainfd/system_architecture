/* 
 * INF559 Data Lab 
 * 
 * <Romain Fouilland romain.fouilland>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif

/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* bit manipulation */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    /* uses the negation of the negation of x & y */
  return ~((~x) | (~y));
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
    /* Uses arithmetic right shift to pad with ones */
// v1
//    int nb = 0xFFFFFFFF;
//    nb = nb - ((1 << (32 - n)) - 1);
// v2 - Works
    /* I use the complement to have 1 at the beginning and I get rid of the 1 at the end by adding +1 */
//    int nb = !!n; // = 0 iff n = 0, 1 else
//    nb = nb << (32 - n - !n); // -!n to stay under 32 even for n = 0 ( !n == 1 in this case )
//    return (~nb) + 1;
// v3
    return (!!n << 31) >> (n + (~0) + !n);
    // !n to stay over 0 even for n = 0 ( !n == 1 in this case )
    // ~0 = -1
// v4 : pbm with the n = 0 case : we do 0 >> (-1) and expect 0 all the time
    // return (!!n << 31) >> (n + (~0));
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
    /* we intersect with even bit nb and if we check if it's 0 */
    int half_mask = 0x55 + (0x55 << 8);
    int mask = half_mask + (half_mask << 16);
    // x = (x & 0x55) + (x & (0x55 << 8)) + (x & (0x55 << 16)) + (x & (0x55 << 24));
    return !!(x & mask);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    /* Uses masks to find the 2 bytes and then swap them using +/- */
    int byte1;
    int byte2;
    n = n << 3; // to shift by byte => 8 bits
    m = m << 3; // << 3 is *8
    byte1 = (x >> n) & 0xFF; // final & 0xFF to keep only one byte
    byte2 = (x >> m) & 0xFF;
    // on update les bytes en pos n puis m en soustrayant (mettant a zero le byte) puis ajoutant le swipe
    return (((x & (~(0xFF << n))) + (byte2 << n)) & (~(0xFF << m))) + (byte1 << m);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    /* we do a bitwise if then else structure after generating the 'extented' x value with the 32 same bits */
    // we generate a 32 bit long int with 0 or 1 depending on the value of x
    x = ((!x) << 31) >> 31;
    return (y & (~x)) | (z & x);
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    /* digits range from 110000 to 111001
       The end is either 110XXX or 11100X (ie we check x >> 1 = 11100 = 0x1C) */
    return (!((x >> 3) ^ 0x06)) | (!((x >> 1) ^ 0x1C));
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    /* we count by pairs, then by group of 4, then 8, 16 and 32 */
    int half_to2 = 0x55 + (0x55 << 8);
    int to2 = half_to2 + (half_to2 << 16);
    int half_to4 = 0x33 + (0x33 << 8);
    int to4 = half_to4 + (half_to4 << 16);
    int half_to8 = 0x0F + (0x0F << 8);
    int to8 = half_to8 + (half_to8 << 16);
    x = (x & to2) + ((x >> 1) & to2);
    // now we sum group the pairs (ie group 4 initial digits)
    x = (x & to4) + ((x >> 2) & to4);
    // now we sum group the groups of 4 (ie group 8 initial digits)
    // we can sum first before the & to8 because we have au plus 4 (ie 1000 en base 2) 1, ce qui est enfin capté par le toN (ca depassait avant avec 100 pour 0011 par ex)
    x = (x + (x >> 4)) & to8;
    // Plus besoin de masquer maintenant parce qu'on aura au plus 32 bits egaux à 1 ie 100000 en base 2 ce qui ne dépassera pas le dernier bloc de 8 => calculer pour tous les blocs de 8 et ne garder que le dernier à la fin
    // now we sum group the groups of 8 (ie group 16 initial digits)
    x = x + (x >> 8);
    // now we sum group the 2 groups of 16 (ie group 32 initial digits = all of them)
    // and we only take the last group of 8 (cf comment above)
    return (x + (x >> 16)) & 0xff;
}
/* 2's complement */
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
    /* tmax = 01...1 and we get there using its negation */
    //return (1 << 31) + (~0);
    return ~(1 << 31);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    /* we use the def of 2s complement */
  return (~x) + 1;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    /* -2^(n-1) <= x < 2^(n-1) => small = x / 2^(n - 1) (ou avec + 1) = 0 */
    int small = x >> (n + (~0));
  return !small | !(small + 1);
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    /* isigne different => OK, sinon verifier que la somme est du meme signe (pas d'overflow) */
    int sign_x = !(x >> 31); // 1 = positif
    int sign_y = !(y >> 31); // 1 = positif
    // return !x | !y | (sign_x ^ sign_y) | !(sign_x ^ !((x + y) >> 31));
    // pas besoin de tester les cas nul, 0 est un nb positif comme un autre
    // return (sign_x ^ sign_y) | !(sign_x ^ !((x + y) >> 31));
    // optimised to
    return (sign_x ^ sign_y) | ((sign_x ^ ((x + y) >> 31)) & 0x01);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    /* if x >= 0 and y < 0 => yes; Else, if different and not (x < 0 and y >= 0), just check the sign of the difference (same sign => no overflow) */
    int sign_x = !(x >> 31); // 1 = positif
    int sign_y = !(y >> 31); // 1 = positif
    //int moins_y = (~y) + 1;
    //return (sign_x & !sign_y) | ((!!(x ^ y)) & !(sign_y & !sign_x) & !((x + moins_y) >> 31)); // ssi la somme est positive, apres le >> 31, elle vaut 0
    // on peut en fait fusionner x != y et x - y >= 0 en x + y > 0 ie x + (~y + 1) > 0 soit x + (~y) >= 0
    // return (sign_x & !sign_y) | (!(sign_y & !sign_x) & !((x + (~y)) >> 31));
    // règle de logique basique sur la negation !
    return (sign_x & !sign_y) | ((!sign_y) | sign_x) & !((x + (~y)) >> 31);

    // v2 : based on the bits analysis
    // we are trying to find the one with a leftmost 1 bit (we add 1 << 31 to make positive bigger than negative on that scale)
    /* doesn't work for some cases... and too many operators to be better than v1
    int sign_bit = 1 << 31;
    int x2 = x + sign_bit;
    int y2 = y + sign_bit;
    int bit_diffs = x2 ^ y2;  // are all the different bits
    int x_diff = x2 & bit_diffs;  // the bits that were only in x2
    int y_diff = y2 & bit_diffs;  // the bits that were only in y2
    // x_diff != y_diff => different biggest bit => sum no overflow
    // 2 cases : x_diff has a 1 at the 31st bit OR 2*x_diff >= x_diff + y_diff with some diffs to become strictly bigger
    return !!(x_diff >> 31) | (!(((x_diff << 1) + ~(x_diff + y_diff) + 1)>>31) & !!x_diff);
     */
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
    /* -x = ~x + 1. Or, O ^ x = x et 1...1 ^ x = ~x. On a juste a générer 0 ou 1..1 en etendant is_negatif et à ajouter ce boolean */
  int full_line = x >> 31;
  return (full_line ^ x) + (full_line & 0x01);
}
