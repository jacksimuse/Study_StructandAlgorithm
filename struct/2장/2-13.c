#include <stdio.h>
#include <string.h>

struct employee {
	char name[10];
	int year;
	int pay;
};

void main()
{
	struct employee Lee;
	struct employee* Sptr = &Lee;
	strcpy(Sptr->name, "이순신");
	Sptr->year = 2015;
	Sptr->pay = 5900;

	printf("\n 이름 : %s", Sptr->name);
	printf("\n 입사 : %d", Sptr->year);
	printf("\n 연봉 : %d", Sptr->pay);

	getchar();
}