#include<stdio.h>
#include<string.h>

int main(void) 
{
	char srcStr[30] = "helloworld";
	char dstStr[30] = { 0, };
	int Len = strlen(srcStr); // string length 
	
	__asm 
	{
		LEA ESI, srcStr; // Leave esi to source
		LEA EDI, dstStr; // Leave edi to destination
		MOV ECX, Len; // ecx = len ;
		REP MOVS BYTE PTR[EDI], BYTE PTR[ESI]; // mov -> copy to byte 
		MOV BYTE PTR[EDI], 0x00; //finaly edi <- '\0'
	}
	printf("%s\n",dstStr);
	return 0;
}
