#include <stdio.h>
#include <stdlib.h>

// Java's config.
#define M 281474976710656LL // 2**48
#define A 25214903917LL
#define C 11LL

unsigned long long next(int bits, unsigned long long *seed);
void setSeed(unsigned long long *seed);
int nextInt(int n, unsigned long long *seed);

/*
  Java code:
  protected synchronized int next(int bits)
  {
    seed = (seed * 0x5DEECE66DL + 0xBL) & ((1L << 48) - 1);
    return (int) (seed >>> (48 - bits));
  }
 */
unsigned long long next(int bits, unsigned long long *seed) {
  //printf("RndSeed: %lld\n", seed[0]);
  //seed[0] *= A;
  //seed[0] += C;
  //seed[0] %= M;
  //printf("RndSeed: %lld\n", seed[0]);
  //printf("%d\n", (int)(seed[0] >> (48 - bits)));
  seed[0] = (seed[0] * A + C) % M;
  return (seed[0] >> (48 - bits));
}

/*
  Java code:
  public synchronized void setSeed(long seed)
  {
    this.seed = (seed ^ 0x5DEECE66DL) & ((1L << 48) - 1);
    haveNextNextGaussian = false;
  }
 */
void setSeed(unsigned long long *seed) {
  seed[0] = (seed[0] ^ A) % M;
}

/*
  Java code:
  public int nextInt(int n)
  {
    if (n <= 0)
      throw new IllegalArgumentException("n must be positive");
    if ((n & -n) == n) // i.e., n is a power of 2
      return (int) ((n * (long) next(31)) >> 31);
    int bits, val;
    do
    {
      bits = next(31);
      val = bits % n;
    }
    while (bits - val + (n - 1) < 0);
    return val;
  }
 */
int nextInt(int n, unsigned long long *seed) {
  unsigned long long bits, val;
  // Have no chance to do this in this program, so just delete it.
  /*
  if ((n & (-n)) == n) {
    return (int)((n * (long long)next(31, seed)) >> 31);
  }
  */  
  do {
    //printf("RndSeed: %lld\n", seed[0]);
    bits = next(31, seed);
    val = bits % n;
  } while ((long long)(bits - val + (n - 1)) < 0);
  return val;
}
