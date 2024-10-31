// gcc -o stack3a stack3a.c -mpreferred-stack-boundary=4 -fno-stack-protector -z execstack -no-pie -fno-pic
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void win(void) {
	printf("Done! Code flow changed\n");
}

int main(int argc, char **argv) {
	volatile void (*fp)();
	char buffer[64];
	
	fp = win;

	gets(buffer);
	
	if(fp) {
		printf("Calling a function pointer, jumping to %p\n", fp);
		fp();
	}
	
	return 0;
}
