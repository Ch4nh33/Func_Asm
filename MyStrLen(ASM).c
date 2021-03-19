#include<stdio.h>

char strlen_1(char* a) 
{
	int res = 0;
	__asm 
	{
		   MOV ESI, a;
	loops: MOV AL, BYTE PTR[ESI] // move to AL for byte string
		   CMP AL, 0X00; // '\0'
	       JE exit; // if al == '\0' -> goto exit
		   INC res; // res++;
		   INC ESI; // esi++;
		   JMP loops; // goto loops;
	exit:
	}
	return res;
}
int main(void) 
{
	char input[] = "helloworld";
	int len = strlen_1(input);
	printf("%d",len);
	
	return 0;
}
