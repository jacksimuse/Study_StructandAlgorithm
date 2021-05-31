/* 선택정렬 : 0번방을 최소값이라고 가정한다.*/
#include <stdio.h>

void selectSort(int*, int);
int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	selectSort(ary, size);
	return 0;
}
void selectSort(int* pary, int size)
{
	int i,j,min,temp;
	for (i = 0; i < size - 1; i++) // size -1 ? 0 ~ size까지면 배열을 벗어남
	{
		min = i; // 최솟값번째를 i번째로 함
		for (j = i + 1; j < size; j++) { // 두번째부터 비교하니 i + 1
			if (pary[min] > pary[j]) min = j; // 작다고 생각한게 j번째보다 크면 j번째가 작은 번째가 됨
		}
		temp = pary[min]; // 해당번째 요소를 스왑
		pary[min] = pary[i];
		pary[i] = temp;
		printf("\n%d 단계 : ", i + 1);
		for (int k = 0; k < size; k++)
		{
			printf("%d  ", pary[k]);
		}
	}
}