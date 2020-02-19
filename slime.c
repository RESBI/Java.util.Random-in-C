#include <stdio.h>
#include "lcg.c"

void getSeed(long long *RndSeed, long long MinecraftSeed, int xPosition, int zPosition);

int main() {
  long long *RndSeed;
  long long MinecraftSeed = -2013662552565141358;

  RndSeed = (long long *)malloc(sizeof(long long));
  
  for (int x=0; x<16; x+=1) {
    for (int z=0; z<16; z+=1) {
      getSeed(RndSeed, MinecraftSeed, x, z);
      setSeed(RndSeed);
  
      //printf("MCSeed: %lld\n", MinecraftSeed);
      //printf("RndSeed: %lld\n", RndSeed[0]);
      //printf("RandNum: %d\n", nextInt(10, RndSeed));
      if (nextInt(10, RndSeed) == 0) {
	printf("x=%d\tz=%d\tis a slime chunk!\n", x, z);//x*16, z*16);
      }
    }
  }
  return 0;
}

void getSeed(long long *RndSeed, long long MinecraftSeed, int xPosition, int zPosition) {
  RndSeed[0] = (MinecraftSeed
		+ (int) (xPosition * xPosition * 0x4c1906)
		+ (int) (xPosition * 0x5ac0db)
		+ (int) (zPosition * zPosition) * 0x4307a7L
		+ (int) (zPosition * 0x5f24f)) ^ 0x3ad8025f;
}
