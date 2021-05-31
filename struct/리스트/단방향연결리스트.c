#include <stdio.h>

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct {
	Node* head; // 노드를 가리킬 수 있는 타입이 와야한다.
}HeadNode;

/* 함수 작성방법
1. 함수명을 쓰고 안에 내용을 채운다
2. 내용은 함수 호출시 활동할 내용들을 채운다
(동적할당)
할당크기는 만들것의 크기(지금은 헤드노드 구조체를 만들거기 때문)
앞에 동적할당을 리턴받기 위해 자료형을 선언(지금은 리스트라서 화살표인 포인터로 지정)
3. 함수를 다 만들고 함수에 출력과 입력을 알려준다*/

/* 헤더를 생성하는 함수 */
HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode)); // h라는 상자에 크기를 지정해준셈
	if (h != NULL) h->head = NULL; // h가 동적할당을 받아서 NULL이 아니므로 if실행 / h가 head를 가리키고있고 그 값에 NULL을 넣어준 상황
	return h;
}
/*전위 노드*/
void preinsertNode(HeadNode* h, int data)
{
	Node* newNode= (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = h->head; // 헤더가 가리키던 값을 newNode의 next에 가져온거
		h->head = newNode;
	}
}
/*후위 노드*/
void rearinsertNode(HeadNode* header, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;

		if (header->head == NULL)
		{
			header->head = newNode;
		}
		else if (header->head != NULL) // h 다음 노드가 있는 경우
		{
			Node* curr = header->head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = newNode;
		}
	}
}
/*출력*/
void print_nodeData(HeadNode *h)
{
	Node* curr = h->head;
	int i = 1;

	while (curr != NULL)
	{
		printf("%d번째 노드 데이터 %d\n", i, curr->data);
		curr = curr->next;
		i++;
	}
}
/*전체 노드 삭제*/
void allDelNode(HeadNode* h)
{
	// temp = h->head;
	// h->head = temp->next;
	// free(temp);
	Node* temp;
	while (h->head != NULL)
	{
		temp = h->head;
		h->head = temp->next;
		free(temp);
	}
	free(h);
}

Node* searchNode(HeadNode* h, int data)
{
	Node* s = h->head;

	while (s != NULL)
	{
		if (s->data == data)
		{
			printf("지금 찾고 있는 데이터 값은 : %d \n", data); 
			return s;
		}
		else s = s->next;
	}
	return s;
}

void searchdelNode(HeadNode* h,  Node* s)
{
	Node* temp = h->head;
	if (h->head == s)
	{
		h->head = temp->next;
	}

	if (s == NULL) return;
	else if (temp == NULL) return;
	else if (temp->next == s)
	{
		temp->next = s->next;
		free(s); // 헤드가 첫번째를 가리킬때 첫번째가 s이면
	}
	else 
	{
		while (temp != s) // s이전까지 계속 돌린다
		{
			temp = temp->next;
		}
		temp->next = s->next;
		printf("검색된 데이터 %d를 삭제합니다\n", s->data);
		free(s);
		
	}
	// 1. h->head == NULL
	
	// 2. s == NULL
	// 3. h->head->next == NULL : 리스트에 노드가 1개
	// 4. else 
	//		if (temp == s)  : 리스트에 노드가 2개 이상, 첫번째 
	// 	    else
}

/* 입력값 3개
헤드, 앞노드의 정보,
*/

/* 중간 노드 삽입 */
void midInsertNode(HeadNode* h, Node* pn, int data)
{
	Node* insertNode = (Node*)malloc(sizeof(Node));
	
	/* 검색된 노드 이전에 넣는 코드 */ //** 순서 확인 꼭!!
	Node* temp = h->head;
	while (temp->next != pn)
	{
		temp = temp->next;
	}
	insertNode->next = temp->next;
	temp->next = insertNode;
	insertNode->data = data;

	/* 검색된 노드 후에 넣는데 마지막 노드일 경우*/ //** 순서 확인 꼭!!
	if (insertNode != NULL) {
		insertNode->data = data;
		insertNode->next = NULL;
		if (h->head == NULL) h->head = insertNode;
		else if (pn == NULL) printf("삽입할 위치를 찾을 수 없습니다.");
		else {
			insertNode->next = pn->next;
			pn->next = insertNode;
		}
	}
	
}

/*메인*/
int main() {

	HeadNode* h = createHead();
	preinsertNode(h, 30);
	rearinsertNode(h, 10);
	rearinsertNode(h, 20);
	
	printf("노드입력 끝\n");
	printf("-----------------\n");
	print_nodeData(h);
	printf("-----------------\n");
	Node* s = searchNode(h, 10);
	midInsertNode(h, s, 40);
	printf("-----------------\n");
	//searchdelNode(h, s);
	printf("-----------------\n");
	print_nodeData(h);
	//printf("-----------------");

	//allDelNode(h);

	//print_nodeData(h);
	return 0;
}

