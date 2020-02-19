#include <stdio.h>
#include <stdlib.h>

// Java's config.
#define M 281474976710655LL // 2**48 - 1
#define A 25214903917LL
#define C 11LL

int next(int bits, long long *seed);
void setSeed(long long *seed);
int nextInt(int n, long long *seed);

/*
  Java code:
  protected synchronized int next(int bits)
  {
    seed = (seed * 0x5DEECE66DL + 0xBL) & ((1L << 48) - 1);
    return (int) (seed >>> (48 - bits));
  }
 */
int next(int bits, long long *seed) {
  seed[0] = (seed[0] * A + C) & M;
  return (int)(seed[0] >> (48 - bits));
}

/*
  Java code:
  public synchronized void setSeed(long seed)
  {
    this.seed = (seed ^ 0x5DEECE66DL) & ((1L << 48) - 1);
    haveNextNextGaussian = false;
  }
 */
void setSeed(long long *seed) {
  seed[0] = (seed[0] ^ A) & M;
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
int nextInt(int n, long long *seed) {
  int bits;
  int val;

  if ((n & (-n)) == n) {
    return (int)((n * (long long)next(31, seed)) >> 31);
  }
  
  do {
    bits = next(31, seed);
    val = bits % n;
    //printf("val=%d, bits=%d\n", val, bits);
  } while ((bits - val + (n - 1)) < 0);
  return val;
}
