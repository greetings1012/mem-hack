// 18011974 안영훈

// canary.c
// gcc -o no_canary canary.c -fno-stack-protector
#include <stdio.h>
#include <unistd.h>

int main(void) {
	char buf[8];
	read(0, buf, 32);
	return 0;
} 
