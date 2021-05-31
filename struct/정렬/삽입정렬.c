/* 삽입정렬 : 두번째 자료부터 앞 자료를 비교하여 정렬한다.*/
#include <stdio.h>

void insertionSort(int*, int);
void print(int*, int);

int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	insertionSort(ary, size);
	return;
}

void insertionSort(int* pary, int sz)
{
	int temp;
	for (int i = 1; i < sz; i++) // 두번째자리에서 앞자리를 비교해서 i = 1 로 시작
	{
		for (int j = i; j > 0; j--) // 진행되고 있는데부터 맨 앞까지 비교를 해줘야되서 j--,
		{						    // 두번째부터 시작해서 j - 1이 있으므로 j > 0
			if (pary[j - 1] > pary[j]) { // 앞자리가 지금보다 크면 스왑
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
		printf("\n%d단계 : ", i);
		for (int k = 0; k < sz; k++)
		{
			printf("%d  ", pary[k]);
		}
	}
}
void print(int* pary, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("apr[%d] = %d  \n", i, pary[i]);
	}
}