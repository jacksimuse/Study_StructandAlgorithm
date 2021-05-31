#include <stdio.h>	
#include <stdbool.h>

#define SIZE 6

typedef struct qnode {
	int data;
	int rear, front;
}Qnode;

int queue[SIZE];

void initNode(Qnode* pq)
{
	pq->data = 0, pq->rear = 0, pq->front = 0;
}

int isEmpty(Qnode* pq)
{
	if (pq->front == pq->rear) return true;
	else return false;
}

int isFull(Qnode* pq)
{
	if (pq->front == (pq->rear + 1) % SIZE) return true;
	else return false;
}

void enQueue(Qnode* pq, int data)
{
	if (isFull(pq)) {
		printf("~~");
	}
	else {
		queue[(pq->rear++) % SIZE] = data;
	}
}

void deQueue(Qnode* pq)
{
	if (isEmpty(pq)) {
		printf("비어있습니다.\n");
		exit(1);
	}
	else {

	}
}
int main() {

	return;
}