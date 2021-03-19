#include<stdio.h>
#include<string.h>

int main(void) 
{
	char srcStr[30] = "helloworld";
	char dstStr[30] = { 0, };
	int result = 0;
	
	printf("input srting :");
	fgets(srcStr, 30, stdin);;
	__asm
	{
	XOR EAX, EAX;
		LEA ESI, srcStr;
		LEA EDI, dstStr;
	START:	MOV BL, BYTE PTR[ESI];
			MOV DL, BYTE PTR[EDI];
			CMP BL, DL; // cmp esi, edi 
			JA L_A;
			JB L_B; // first end  srcStr is to compare 00 | jmp to (srcStr < dstStr) = L_B
			JE L_E;
	L_A:	MOV EAX, 0x01; // srcStr > dstStr | eax = 1 | ret 1 ;
			JMP EXIT; 
	L_B:	MOV EAX, -0x01; // dstStr > srcStr | eax = -1 | ret -1 ;
			JMP EXIT;
	L_E:	INC ESI;
			INC EDI;
			CMP BL, 0x00; // final strig => compare '\0';
			JNE START; // not '\0' -> jump to START;
			MOV EAX, 0x00; // final string '\0'-> eax = 0;
	EXIT:	MOV result, EAX;
	}
	printf("result: %d\n",result);
	return 0;
}
