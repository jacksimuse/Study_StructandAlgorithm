#include <stdio.h>

typedef struct node{
	int data;  // data 멤버
	struct node* link; // 다음 노드의 주소를 저장할 멤버
} Node;

int main()
{
	int i = 0;
	scanf("%d", &n);
	Node* head=(Node*)malloc(sizeof(Node)); // 헤더 생성

	Node* node1 = malloc(sizeof(Node)); // 노드 생성
	Node* node2 = malloc(sizeof(Node));
	Node* node3 = malloc(sizeof(Node));
	Node* node4 = malloc(sizeof(Node));
	Node* node5 = malloc(sizeof(Node));

	if (node1 == NULL) return;

	node1->data = 10;
	node1->link = node2;
	node2->data = 20;
	node2->link = node3;
	node3->data = 30;
	node3->link = node4;
	node4->data = 40;
	node4->link = node5;
	node5->data = 50;
	node5->link = NULL;

	head->link = node1; // 헤더노드에 첫번째 노드의 주소값을 넣는다
	head->data = NULL;

	Node* curr = head->link;
	while (curr != NULL) {
		printf("%d번째 노드 데이터 : %d \n", i + 1, curr->data);
		curr = curr->link;
		i++;
	}
	
	free(head);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);

	return 0;
}