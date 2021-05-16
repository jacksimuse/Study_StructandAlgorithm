#include <stdio.h>

void main()
{
	int i = 0, n;
	
	while (1) {

		printf("\n1~9의 정수를 입력하세요 : ");

		scanf("%d", &n);

		for (i = 0; i < 9; i++)
		{
			printf("%d x %d = %d\n", n, i + 1, n * (i + 1));
		}

		printf("계속 / 끝내기 : 1 / 2 중에 눌러주세요");

		scanf("%d", &n);

		if (n == 2) break;
	}
}