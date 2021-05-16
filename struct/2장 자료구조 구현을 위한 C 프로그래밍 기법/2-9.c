#include <stdio.h>

void main()
{
	int i;
	char string1[20] = "Dreams come true!", string2[20], * ptr1, * ptr2;

	ptr1 = string1;
	printf("\n string1의 주소 = %u  \t ptr = %u", string1, ptr1);
	printf("\n string1 = %s  \n ptr = %s", string1, ptr1);
	printf("\n\n %s", ptr1 + 7); // ptr1에서 7번째부터 나옴
	ptr2 = &string1[7];
	printf("\n %s \n\n", ptr2);

	for (i = 16; i >= 0; i--)
	{
		putchar(*(ptr1 + i));  // 16번째부터 0번까지 거꾸로 하나씩 출력
	}
	for (i = 0; i < 20; i++)
	{
		string2[i] = *(ptr1 + i);
	}
	printf("\n\n string1 = %s", string1);
	printf("\n string2 = %s", string2);

	*ptr1 = 'P';
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("\n\n string1 = %s\n", string1);

	getchar();
}