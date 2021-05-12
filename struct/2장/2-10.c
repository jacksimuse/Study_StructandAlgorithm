#include <stdio.h>

void main()
{
	int i;
	char* ptrArray[4] = { {"Korea"}, {"Seoul"},{"Mapo"},{"152¹øÁö 2 / 3"} };
	for (i = 0; i < 4; i++)
	{
		printf("\n %s", ptrArray[i]);
	}
	printf("\n\n");
	ptrArray[2] = "Jongno";
	for (i = 0; i < 4; i++)
	{
		printf("\n %s", ptrArray[i]);
	}

	getchar();
}