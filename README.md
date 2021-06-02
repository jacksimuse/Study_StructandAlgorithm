# Study_StructandAlgorithm
자료구조와 알고리즘

# Raspberry_pi
라즈베리파이 리포지토리

## 대소문자 구분없이 알파벳 입력후 대소문자를 판별하여 분류하고 사전순으로 정렬하기(평가)

---
1. 배열 사용
2. 연결리스트 사용
---
### 배열
```C
#include <stdio.h>
#include <string.h>

void insertionSort(char*, int);
void print(char*, int);

int main()
{
	char input_ary[10];
	char lower_ary[10], upper_ary[10];
	int j = 0, k = 0;
	
	printf("문자를 입력하세요(알파벳 10글자만 가능) : ");
	for (int i = 0; i < 10; i++)
	{
		scanf(" %c", &input_ary[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		if (input_ary[i] >= 65 && input_ary[i] <= 90)
		{
			upper_ary[j] = input_ary[i];
			j++;
		}
		else if (input_ary[i] >= 97 && input_ary[i] <= 122)
		{
			lower_ary[k] = input_ary[i];
			k++;
		}
	}
	
	insertionSort(upper_ary, j);
	insertionSort(lower_ary, k);
	printf("대문자 : ");
	print(upper_ary, j);
	printf("\n소문자 : ");
	print(lower_ary, k);
	printf("\n");
}

void insertionSort(char *ary, int count )
{
	char temp;
	for (int i = 1; i < count; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (ary[j - 1] > ary[j])
			{
				temp = ary[j];
				ary[j] = ary[j - 1];
				ary[j - 1] = temp;
			}
		}
	}
}
void print(char* ary, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%c ", ary[i]);
	}
	
}
```
### 연결리스트
```C
#include <stdio.h>

void insertionSort(char *, int);

typedef struct node {
	char alpabet;
	struct node* next;
} Node;

typedef struct {
	Node* head;
}HeadNode;

HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}

void insertNode(HeadNode* h, char alpa)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->alpabet = alpa;
		newNode->next = NULL;

		if (h->head == NULL) h->head = newNode;
		else if (h->head != NULL)
		{
			Node* curr = h->head;
			while (curr->next != NULL) curr = curr->next;
			curr->next = newNode;
		}
	}
}

void printNode(HeadNode* h)
{
	Node* curr = h->head;
	int i = 1;

	while (curr != NULL)
	{
		printf("%d번째 노드 데이터 %c\n", i, curr->alpabet);
		curr = curr->next;
		i++;
	}
	curr = h->head;
	printf("\n대문자가 들어간 노드 데이터 : ");
	while (curr != NULL)
	{
		if (curr->alpabet >= 65 && curr->alpabet <= 90)
			printf("%c ", curr->alpabet);
		curr = curr->next;
	}
	curr = h->head;
	printf("\n소문자가 들어간 노드 데이터 : ");
	while (curr != NULL)
	{
		if (curr->alpabet >= 97 && curr->alpabet <= 122)
			printf("%c ", curr->alpabet);
		curr = curr->next;
	}
}
int main()
{
	HeadNode* h = createHead();

	char input_ary[10];
	int j = 0,k = 0;
	
	printf("문자를 입력하세요(알파벳 10글자만 가능) : ");
	for (int i = 0; i < 10; i++)
	{
		scanf("%c", &input_ary[i]);
	}
	
	insertionSort(input_ary, 10);
	
	for (int i = 0; i < 10; i++)
	{
		insertNode(h, input_ary[i]);
	}
	printNode(h);
}

void insertionSort(char* ary, int count)
{
	char temp;
	for (int i = 1; i < count; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (ary[j - 1] > ary[j])
			{
				temp = ary[j];
				ary[j] = ary[j - 1];
				ary[j - 1] = temp;
			}
		}
	}
}
```
