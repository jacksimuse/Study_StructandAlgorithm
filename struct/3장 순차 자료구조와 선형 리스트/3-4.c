#include <stdio.h>
#define MAX(a, b) ((a>b)?a:b) // a > b 가 참인가? 참 -> a 출력 : 거짓 - > b 출력 
#define MAX_DEGREE 50

typedef struct 
{
	int degree;
	float coef[MAX_DEGREE]; // coef[50]이란말
} polynomial;

polynomial addPoly(polynomial, polynomial); // polyenomial 이라는 출력에 addPoly라는 함수명에 polynomial 입력
void printPoly(polynomial);

void main() {
	polynomial A = { 3, {4, 3, 5, 0} };
	polynomial B = { 4, {3, 1, 0, 2, 1} };

	polynomial C;
	C = addPoly(A, B);

	printf("\n A(x) ="); printPoly(A);
	printf("\n B(x) ="); printPoly(B);
	printf("\n C(x) ="); printPoly(C);

	getchar();
}

polynomial addPoly(polynomial A, polynomial B)
{
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree) {
		if (A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if (A_degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else {
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;
}

void printPoly(polynomial P) {
	int i, degree;
	degree = P.degree;

	for (i = 0; i <= P.degree; i++)
	{
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}