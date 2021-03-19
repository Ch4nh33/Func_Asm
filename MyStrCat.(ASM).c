#include<stdio.h>
#include<string.h>

int main(void) 
{
	char srcStr[20] = "Hello";
	char dstStr[10] = "World";
	int srcLen;
	int dstLen;

	dstLen = strlen(dstStr);
	srcLen = strlen(srcStr);
	
	__asm
	{
		LEA ESI, srcStr; // first string
		LEA EDI, dstStr; // second string
		ADD EDI, dstLen; // last string 
		MOV ECX, srcLen; // string size
		REP MOVS BYTE PTR[EDI], BYTE PTR[ESI]; // EDI++ , ESI++;
		MOV BYTE PTR[EDI], 0x00; // Null string ('\0')
	}
	printf("%s\n",dstStr);
	return 0;
}
