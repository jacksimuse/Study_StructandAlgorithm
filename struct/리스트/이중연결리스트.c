#include <stdio.h>

typedef struct dlistnode {
	int data;
	struct dlistnode* next; // 뒤를 가리킴
	struct dlistnode* prev; // 이전을 가리킴
} DListnode;

typedef struct HeadNode {
	DListnode* head;
} HeadNode;

HeadNode* creatHeadNode() {
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}
DListnode* createNode(int data)
{
	DListnode* newNode = (DListnode*)malloc(sizeof(DListnode));
	if (newNode == NULL)
	{
		printf("메모리 할당 실패!");
		exit(1);
	}
	else {
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
}
void insertNode(HeadNode* phead, DListnode* preNode, DListnode* newNode)
{
	if (phead->head == NULL) { // 헤드가 옮겨가면서 newNode가 됨 헤드가 있는 곳이 현재위치
		newNode->next = NULL;
		newNode->prev = NULL;
		phead->head = newNode;
	}
	else {
		newNode->next = preNode->next;
		preNode->next = newNode;
		newNode->prev = preNode;
		if (newNode->next != NULL)
			newNode->next->prev = newNode;
	}	
}
DListnode* findNode(HeadNode* phead, int data)
{
	DListnode* temp = phead->head;
	while (phead->head != data)
	{
		if (temp->data == data)
		{
			printf("찾은 노드 데이터는 %d입니다.\n", temp->data);
			return temp;
		}
		else temp = temp->next;
	}
	return temp;
}

void findDel(HeadNode* phead, DListnode* fn)
{
	DListnode* temp = phead->head;
	if (temp == fn) phead->head = temp->next;
	else if (fn == NULL) return;
	else if (temp->next == fn)
	{
		temp->next = fn->next;
		if (fn->next != NULL) fn->next->prev = temp;
	}
	while (temp->next != fn) // temp가 검색노드 이전노드
	{
		temp = temp->next;
	}
	temp->next = fn->next;
	fn->prev = temp;
	printf("검색된 노드를 삭제합니다\n");
	free(fn);
}
void allDelNode(HeadNode* phead)
{
	DListnode* temp;
	while (phead->head != NULL)
	{
		temp = phead->head;
		phead->head = temp->next;
		free(temp);
	}
	printf("모두 삭제합니다\n");
	free(phead);
}
void printallNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("연결된 노드가 없습니다.\n");
	}
	else
	{
		DListnode* curr = phead->head;
		int i = 1;
		while (curr != NULL)
		{
			printf("%d번째 노드 데이터 %d\n", i, curr->data);
			//printf("이전 주소: %u / 현재 주소: %u / 다음 주소: %u\n", curr->prev, curr, curr->next);
			curr = curr->next;
			i++;
		}
	}
}
int main()
{
	HeadNode* h = creatHeadNode();
	DListnode* newNode1 = createNode(10);
	DListnode* newNode2 = createNode(20);
	DListnode* newNode3 = createNode(30);
	insertNode(h, NULL, newNode1);
	insertNode(h, newNode1, newNode2);
	insertNode(h, newNode2, newNode3);


	printallNode(h);

	DListnode* fn = findNode(h, 20);
	findDel(h, fn);

	allDelNode(h);
	
	return 0;
}