// 큐를 이용해서 연결리스트처럼 만들기
#include <stdio.h>
#include <stdbool.h>

typedef struct qnode {
	int data;
	struct qnode* link;
}QNode;

typedef struct {
	QNode* pq;
}FQueue;

FQueue* createHead()
{
	FQueue* f = (FQueue*)malloc(sizeof(FQueue));
	if (f != NULL) f->pq = NULL;
	return f;
}
int isEmpty(FQueue* ptqueue)
{
	if (ptqueue->pq == NULL) return true;
	else return false;
}
int enQueue(FQueue* ptqueue, int data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (isEmpty(ptqueue)) {
		ptqueue->pq = newNode;
		newNode->data = data;
		newNode->link = NULL;
	}
	else {
		newNode->data = data;
		newNode->link = ptqueue->pq;
	}
}
void deQueue(QNode* newNode, int data)
{
	QNode* temp = newNode->link;
	if (temp == NULL)
	{
		newNode->link = temp;

		free(newNode);
	}
	
}