#include <stdio.h>
#include <stdbool.h>

#define STACK_SZ 3 // 해당 글자가 보이면 숫자로 변환
//#define TRUE 1
//#define FALSE 2 <stdbool.h>쓰면 T/F 안해도됨

int isEmpty();  // 공백체크
int isFull();	// 포화체크
void push(int); // 스택에 입력
int pop();		// 스택에 출력
int peek();		// 맨위의 스택확인
void printStack();

int stack[STACK_SZ];
int top = -1;   // 현재 스택 위치, 항상 스택의 맨 위를 가리킨다.
int main()
{
	push(10);
	push(11);
	push(12);
	pop();
	push(13);

	printStack();
	return 0;
}

int isEmpty()
{
	if (top <= -1) return true;
	else return false;
}
int isFull()
{
	if (top >= STACK_SZ - 1) true;
	else return false;
}
void push(int data)
{
	if (isFull()) // 호출값이 참인경우도 조건에 해당
	{
		printf("STACK overflow!!\n");
		return;
	}
	else {
		stack[++top] = data; // 첫 top은 -1 이므로 증가시켜서 0부터 사용
	}
}
int pop()
{
	if (isEmpty()) {
		printf("STACK underflow!!\n");
		return;
	}
	else {
		return stack[top--]; // 탑에서 빼고 다음에 연산
	}
}
int peek()
{
	if (isEmpty())
	{
		printf("\n\n STACK is Empty! \n");
		return;
	}
	else return stack[top];
}
void printStack()
{
	int i;
	if (!isEmpty()) {
		for (i = 0; i <= top; i++) {
			printf("%d   ", stack[i]);
		}
	}
}