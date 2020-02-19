#include <stdio.h>
#include "lcg.c"

void getSeed(long long *RndSeed, long long MinecraftSeed, int xPosition, int zPosition);

int main() {
  long long *RndSeed; // The seed must be pointer type.
  long long MinecraftSeed = -2013662552565141358; // You can replace it with your seed of Minecraft.

  RndSeed = (long long *)malloc(sizeof(long long)); // There're some bugs if you delete this.
  
  for (int x=0; x<16; x+=1) { // actuall x / 16
    for (int z=0; z<16; z+=1) { // actuall z / 16
      getSeed(RndSeed, MinecraftSeed, x, z);
      setSeed(RndSeed);
  
      //printf("MCSeed: %lld\n", MinecraftSeed);
      //printf("RndSeed: %lld\n", RndSeed[0]);
      //printf("RandNum: %d\n", nextInt(10, RndSeed));
      if (nextInt(10, RndSeed) == 0) {
	printf("x=%d\tz=%d\tis a slime chunk!\n", x*16, z*16); // Turn to the real location.
      }
    }
  }
  
  free(RndSeed); // Let it go.
  return 0;
}

void getSeed(long long *RndSeed, long long MinecraftSeed, int xPosition, int zPosition) {
  RndSeed[0] = (MinecraftSeed
		+ (int) (xPosition * xPosition * 0x4c1906)
		+ (int) (xPosition * 0x5ac0db)
		+ (int) (zPosition * zPosition) * 0x4307a7L
		+ (int) (zPosition * 0x5f24f)) ^ 0x3ad8025f;
}
