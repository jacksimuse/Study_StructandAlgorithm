#include <stdio.h>

int BSearch(int* pary, int sz, int tg)
{
	for (int i = 0; i < sz; i++)
	{
		int first = 0;
		int last = sz - 1;
		int mid;
		while (first <= last) { // 계속 반으로 나눠서 비교할거라서 첫번째랑 마지막이 같아질때까지 반복함
			mid = (first + last) / 2; // 중간값을 mid에 저장
			if (tg == pary[mid]) return mid; // 검색값이 중간위치면 중간 위치 반환
			else {
				if (tg > pary[mid]) first = mid + 1; // 검색값이 중간위치보다 크면 검색값보다 작은쪽 버리고 첫번째를 중간 뒤부터 재정의
				else last = mid - 1; // 검색값이 중간위치보다 작으면 뒤쪽을 버리고 맨뒤는 중간 앞자리로 재정의
			}
		}
	}
	return -1;
}

int main()
{
	int ary[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int index;

	index = BSearch(ary, size, 1);
	if (index == -1) printf("탐색 실패!!\n");
	else printf("찾는 값은 %d번째 있습니다.\n", index + 1);

	return 0;
}