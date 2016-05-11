#if 0


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

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


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
//1
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  //check the rule and shift the bits every 8 bits.
  return  ((0x49 << 24) | ((0x24 << 16) | ((0x92 << 8) | 0x49)));
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  //only zero and Tmin reverse themselves and still get themselves.
  return (!!x) & !((~x + 1) ^ x);
}
//2
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  //x XOR y will get 0 if they are the same.
  return !!(x ^ y);
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
    //check the rule and shift the bits every 8 bits.
    return !!(x & ((0xaa) | (0xaa << 8) | (0xaa << 16) | (0xaa << 24)));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //reverse and plus one.
  return ~x + 1;
}
//3
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //mask a mask = 0xffffffff if x == 0 or mask = 0 if x == 1;
  //then use and xor to keep the value we want
  int mask = ((!x << 31) >> 31);
  return (mask & z) ^ (~mask & y);
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  //if x and y have the same sign 
  //or (x - y) has the same sign with x. 
  int xSign = x >> 31;
  int ySign = y >> 31;
  int isSame = xSign ^ ySign;
  return !(isSame & (xSign ^ ((x + (~y + 1)) >> 31)));
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /* check if x is positive and y is negative
  *  check if x - y >= 0 
  *  and x != y 
  *  and xSign is not equal ySign
  */
  int xSign = x >> 31;
  int ySign = y >> 31;
  int bit = !((x + (~y + 1)) >> 31) & (!!(x ^ y));
  bit &= !(xSign & !ySign);
  bit |= !(xSign) & (ySign);
  return  bit;
}
//4
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  // Xor can offset the two same numbers.
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;

  return x &  1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
/*  check the high 16 bits if there is a 1, if yes, plus count by 16.
 * if not, check the low 16 bits, and then 8 bits, 4 bits until 1 bits
 * finally use a mask to make the result adjust to the sign bit
 * Be caruful with the count value.
 */
  int count = 0;
  int mask = 0;
  x = x ^ (x >> 31);
  count += !!((x >> 16)) << 4;
  count += !!(x >> (count + 8)) << 3;
  count += !!(x >> (count + 4)) << 2;
  count += !!(x >> (count + 2)) << 1;
  count += !!(x >> (count + 1));

  mask = ((!x << 31) >> 31);
  return (mask & 1) ^ (~mask & (count + 2));
  
}
//float
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
   /* 
    *  first get the sign bit. then get the exp value, if
    *  exp != 0x00, we need to sub exp by 1; else we just
    *  need to right shift it by one. Be careful with rounding.
    */ 
    unsigned mask = 0x80 << 24;
    unsigned sign = uf & mask;
    unsigned newUF = uf;
    unsigned EXP = 0;
    if(sign > 0) {
      newUF ^= mask; 
    }

    if(newUF == 0) {
      return newUF ^ sign;
    }

    EXP = newUF >> 23;
    if(EXP > 1) {
      if(EXP == 0xff) {
        return newUF ^ sign; 
      }

      newUF -= (1 << 23);

    } else {
      if((newUF & 0x03) == 3) {
            //printf("%x\n", newUF);
        newUF >>= 1;
        newUF++; 
      } else {
        newUF >>= 1;
      }
    }
    return newUF ^ sign;
} 
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  /* First get the sign bit, then get the exp value. With this value,
  * we can found out the number we need to shift. Finally we add every
  * part together.
  * Be careful with rounding.
  */
  unsigned mask = 0;
  unsigned mask2 = 0;
  unsigned sign = 0;
  unsigned temp = 0;
  unsigned frac = 0;
  int count = 0;
  int e = 0;
  int shift = 0;
  int checkHigh = 0;
  if(x == 0) {
    return 0;
  }

  //get the sign bit
  mask = 0x80 << 24;
  sign = x & mask;
  
  //make x = -x if x < 0
  if(x < 0) {
    x = -x;
  }


  //get exp value;
  temp = x;
  while(temp > 1) {
    temp >>= 1;
    count++;
  }

  e = count + 127;
  e <<= 23;

  //get the shift bit.
  mask2 = (1 << count) - 1;
  x = x & mask2;
  shift = 23 - count;
  if(shift >= 0)
    x <<= shift;
  else {
    frac = x;
    checkHigh = 1 << 31;

    x >>= (count - 23);
    frac <<= (55 - count);

    //rounding process
    if((frac == checkHigh && (x & 0x01)) || (frac > checkHigh)) {
      x += 1;
    }
    
    
  }

  x += e;
    
  return x ^ sign;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
/*
 *  get the sign bit and exp value.
 *  calculate different result according to different exp value.
 */

  unsigned sign = uf >> 31;
  int mask = 0x80 << 16; 
  unsigned E = (uf >> 23) & 0xff;
  uf = (uf & (mask - 1) | mask);

  if(E == 0xff) {
    return 1 << 31;
  }
  
  //if uf < 1;
  if(E < 127) {
    return 0;
  }

  E -= 127;
  //if uf overflows.         
  if(E >= 31) {
    return 1 << 31;
  } 

  //shift the uf by abs(exp - 23);
  if(E >= 23) {

     uf <<= (E - 23);
  } else {
     uf >>= (23 - E);

  }

  if(sign) {
    uf = -uf;
  }
      

  return uf;
}
