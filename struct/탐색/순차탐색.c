#include <stdio.h>

int LSearch(int* pary, int sz, int tg)
{
	for (int i = 0; i < sz; i++) {
		if (pary[i] == tg) return i + 1;
	}
	return -1;
}
int main()
{
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int size = sizeof(ary) / sizeof(ary[0]); // int크기 X 요소 / int 한칸 크기 = 4 X 7 / 4 = 7
	int index;
	index = LSearch(ary, size, 2);
	if (index == -1) printf("찾기 실패!!\n");
	else printf("검색결과 %d번째에 있습니다.\n", index);
	return 0;
}