/* 
 * CS:APP Data Lab 
 * 
 * <lh>
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
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
      //~(x&y)将x和y中都是1的位 置为0（1）
      //~(~x&~y)将x和y中都是0的位 置为0（2）
      //（1）&（2）将x和y中都是0和都是1的位 置为0
  return ~(~x&~y)&~(x&y);

}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ |+
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  return !(((x^(x+1))+1)|!(x+1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
int y;
y=170<<24|170<<16|170<<8|170;
  return !((x&y)^y);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
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
int t;
t=1<<31;
  return !(((~0x30+1+x)&t)|((~x+1+0X39)&t)) ;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
int t;
t=!(x^0);
t=~t+1;
  return (y&~t)|(z&t);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
int t;
int k;//k is x's sign bit
int u;//u is y's sign bit
int w;
t=1<<31;
k=(x&t)>>31;
u=(y&t)>>31;
k=k&1;
u=u&1;
k=k+(~u+1);//k-u=0: return y-x, =1 return 1,=-1 return 0
w=k<<31;
w=w^k;
w=w>>31;
w=~w;
x=~x+1;
  return !( ((((x+y)|k))&w) &t );
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
int t;
int k;
int u;
t=1<<31;
k=t&x;
u=(k>>31)^t;
u=u+(~x+1);
u=u&t;
u=((u^k)>>31)&1;

  return u;
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
int howManyBits(int x1) {
int x;
int t;
int k;
int c;
int n;
int m;
int f;
int n1;
int t1;
m=x1>>31;
t=!(x1^(0));
x1=(x1^m) ;
m=m&1;
x1=x1+m;
n=1;
n1=0;
x=x1;
c=0;
x=x>>16;
k=(~(~(!x)+1))&16;
c=c+k;
x=x1>>c;
x=x>>8;
k=(~(~(!x)+1))&8;

c=c+k;
x=x1>>c;
x=x>>4;
k=(~(~(!x)+1))&4;

c=c+k;
x=x1>>c;
x=x>>2;
k=(~(~(!x)+1))&2;
c=c+k;

x=x1>>c;
f=(x&1);
n1=n1+f;

x=x>>1;
f=(x&1);
n1=n1+f;
n=n+f;
//printf("%d ",c);
t1=31+(~c+1);
x=x1<<t1;
x=x<<1; 
t1=!(x^0);
//printf("%d ",x);

t1=t1&m;
//printf("%d ",t1);

t1=t1&(n1&1);

t=t1|t;
  return n+c+(~t+1)+1 ;
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
unsigned f;
unsigned f1;
unsigned f2;
unsigned f3;
unsigned f4;
unsigned f5;
f4=0xff800000;
f=0x007fffff;
f1=0x7f800000;
f2=0x00800000;
f5=0;
if((uf&f1)==f1){f2=0;return uf; }
if((uf&f1)==0){f2=0; }
f3=(f&uf)|f2;
f3=f3+f3;
if(f2)f3=f3>>1;
uf=((uf&f4)|(f3&f))+(f3&f1);
if((uf&f1)==f1)f5=1;
if(f5)uf=uf&f4;

 return uf;
}
unsigned float_i2f(int x) {
     unsigned sign, exp, frac;
     unsigned x1;
     unsigned i;
     unsigned roundTail;
     unsigned t;	
     if (!x) {
         return 0;
     }
     x1= x;
     i=0;
     t=0;
     sign = 0;
     if (x < 0) {
       x1 = -x;
         sign= 0x80000000;
     }
     while (!(0x80000000 & x1)) {
         x1 = x1 << 1;
         i+= 1;
     }
    
     x= x1& 0xff;
     frac = (0x007fffff) & (x1 >> 8);
     if (x > 0x80)t= 1; 
         else if (0x80 == x) 
            if (frac & 1) t= 1;           
      exp = 127 + 31 - i;
     return (sign| (exp << 23) | frac)+t;
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
/*unsigned float_i2f(int x2) {

 
}*/

/*unsigned float_i2f(int x) {
unsigned i;
unsigned k;
unsigned x1;
unsigned frac;
unsigned exp;
unsigned sign;
unsigned f;
unsigned t;
t=0;
sign=0;
if(x==0)return 0;
if(x<0){sign=0x80000000;x=-x; }
f=0x007fffff;
i=0;
k=0;
while(0x80000000&x==0 ){
x=x<<1;
i=i+1;
}

frac=f&(x>>8);
x1=x&0xff;
k=127+31-i;
exp=k<<23;
x=((sign|exp)|frac);
if(x1>0x80)x=x+1; //she ru
else
 {if(x1==0x80)if(frac&1)x=x+1;}


  return x;
}*/
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
int exp;
int frac;
exp=uf>>23;
exp=(exp&0xff)-127;
if(exp<0)return 0;
frac=uf&0x007fffff;
frac=frac|0x00800000;
if(exp>=31)return 0x80000000u;
if(exp<23)frac=frac>>(23-exp);
else frac=frac<<(exp-23);
if(uf&0x80000000)frac=-frac;
  return frac;
}
