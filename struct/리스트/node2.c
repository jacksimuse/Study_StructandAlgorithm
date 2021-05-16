#include <stdio.h>
typedef struct node {
	int data;
	struct node* link;
} Node;

void addNode(Node* target, int data)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = target->link;
	target->link = newNode;
}
int main()
{

	Node* head = (Node*)malloc(sizeof(Node));
	head->link = NULL;

	int i = 0;
	addNode(head, 40);
	addNode(head, 30);
	addNode(head, 20);
	addNode(head, 10);
	
	Node* curr = head->link;
	while (curr != NULL) {
		printf("%d번째 노드 데이터 : %d \n", i + 1, curr->data);
		curr = curr->link;
		i++;
	}

	Node* temp;
	for (curr; curr != NULL; curr->link)
	{
		temp = curr->link;
		free(curr);
		curr = temp;
	}
	free(head);
	return 0;
}
	
