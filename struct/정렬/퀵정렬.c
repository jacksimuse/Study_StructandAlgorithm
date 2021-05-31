/* 퀵 정렬 : 대표적인 분할 정복 알고리즘
	정렬이 되어 있지않은 구조에서 사용하면 빠르다.
	1. 원소들 중에서 pivot을 고른다.
	2. 이 pivot을 기준으로 앞에는 작은 값, 뒤에는 큰 값들을 위치시킨다. (분할)
	3. 분할된 작은 리스트를 재귀적으로 동작 시킨다. (정복)
	4. 정렬된 작은 리스트들을 결합한다. (결합)
*/
#include <stdio.h>

void quickSort(int*, int, int);

int main() 
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, 0, size - 1);
	
	return 0;
}
void quickSort(int* pary, int left, int right)
{
	int lidx = left, ridx = right;
	int temp;
	int pivot = (left + right) / 2;
	printf("pivot - index : %d, value : %d\n", pivot, pary[pivot]);
	while (lidx <= ridx)
	{
		while (pary[lidx] < pary[pivot]) lidx++;
		while (pary[ridx] > pary[pivot]) ridx--;
		if (lidx <= ridx) {
			temp = pary[ridx];
			pary[ridx] = pary[lidx];
			pary[lidx] = temp;
			printf("%d : %d\n", temp, pary[ridx]);
			lidx++;
			ridx--;
		}
	}
	for (int i = 0; i <= right; i++) printf("%3d", pary[i]);
	printf("\n");
	if (left < ridx) quickSort(pary, left, ridx);
	if (lidx < right) quickSort(pary, lidx, right);
	
}