#include <stdio.h>

void main() {
	int i, n = 0, * ptr;
	int sale[2][4] = { {63, 84, 140, 130},
					   {157, 209, 251, 312} };
	ptr = &sale[0][0];
	int(*pptr)[4] = &sale;
	int** pptr2 = sale;
	for (i = 0; i < 8; i++)
	{
		printf("\n address : %u sale %d = %d", ptr, i, *ptr); // 2차원 배열인데 일반 포인터를 사용해서 
		ptr++;
	}
	printf("\n");
	printf("%d\n", pptr[1][1]); // 2차원 배열이 출력이 안됨
	printf("%u\n", pptr+1); // pptr = [0][0] pptr +1 = [1][0]
	printf("%u\n", *pptr2); // pptr2 ->sale, *pptr2 -> sale[0]
	printf("%d\n", pptr2); // 이중포인터과 배열 포인터는 같다
	printf("%d\n", pptr2+1);
	/*printf("%u\n", **pptr2);
	printf("%u\n", **pptr2);*/
	//printf("%d\n", pptr[1][1]);
	getchar();

}