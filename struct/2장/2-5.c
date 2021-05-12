#include <stdio.h>

void main() {
	int i, length = 0;
	char str[50];
	printf("\n문자열을 입력하세요 : ");
	gets(str);
	printf("\n입력된 문자열 \n \"");
	for (i = 0; str[i]; i++) // for문의 조건문은 무조건 참이고 정수 0이거나 틀린조건이면 for문 탈출
	{
		printf("%c", str[i]);
		length += 1;
	}
	printf("\" \n입니다");
	printf("\n\n입력된 문자열의 길이  = %d \n", length);

	getchar();
}