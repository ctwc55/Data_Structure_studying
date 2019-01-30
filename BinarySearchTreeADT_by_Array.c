#include <stdio.h>

#define LEN 2049 //이진탐색트리의 최대크기 저장
#define NULLV 1000000000 //NULL값 지정

int BST[LEN]; //이진탐색트리를 위한 메모리 공간 마련
int MAXN, MINN; //트리 내부의 최대값과 최솟값이 저장
int Deep; //트리의 깊이 저장
int Nnode; //노드의 개수 저장

//기능나열
void CreateBST(int element); //이진탐색트리생성 (루트노드생성)
void InsertNode(int element, int node); //노드추가
void PreorderTraversal(int node); //트리의 전위 순회
void InorderTraversal(int node); //트리의 중위 순회
void PostorderTraversal(int node); //트리의 후위 순회
void GetMin(int node); //최소값 찾기
void GetMax(int node); //최대값 찾기
void FindNode(int element, int node); //특정 노드의 위치 찾기
void DeleteNode(int element, int node); //특정 노드 제거
void HeightBST(int node, int height); //트리의 높이 반환(출력)
void GetRightChild(int element, int node); //오른쪽 자식노드 값 반환(출력)
void GetLeftChild(int element, int node); //왼쪽 자식노드 값 반환(출력)
void CountNodeBST(int node); //이진탐색트리의 노드개수의 반환(출력)
void ClearBST(); //이진탐색트리 초기화

//ADT를 기반으로 main함수 정의
int main()
{
	CreateBST(33);
	InsertNode(22, 1);
	InsertNode(44, 1);
	InsertNode(30, 1);
	InsertNode(40, 1);
	PreorderTraversal(1);
	InorderTraversal(1);
	PostorderTraversal(1);
	GetMin(1);
	GetMax(1);
	FindNode(40, 1);
	DeleteNode(30, 1);
	PreorderTraversal(1);
	HeightBST(1,1);
	InsertNode(52, 1);
	GetLeftChild(44, 1);
	GetRightChild(44, 1);
	CountNodeBST(1);
	ClearBST();

	system("pause");
	return 0;
}

//--------------------------------
// 기능 구현부
// 사용자는 위의 기능목록을 보고 사용만 하면 됨
// 사용자는 이 밑(작동원리)에 관심도 없고 볼 필요도 없음

void CreateBST(int element) {
	int i;
	for (i = 1; i < LEN; i++) {
		BST[i] = NULLV;
	}
	BST[1] = element;
	MAXN = -NULLV; //여기서의 NULLV은 NULL의 의미와는 별개로 적당한 숫자여서 사용함.
	MINN = NULLV; //위와 동일한 이유.
	Deep = 1;
	return;
}

void InsertNode(int element, int node) {
	
	if (BST[node] == element) {
		printf("값이 이미 존재합니다!\n");
		return;
	}
	else if (node >= LEN) {
		printf("트리의 최대 범위를 벗어납니다!\n");
		return;
	}
	else if (BST[node] == NULLV) {
		BST[node] = element;
		return;
	}
	else if (element < BST[node]) {
		InsertNode(element, node * 2);
		return;
	}
	else if (element > BST[node]) {
		InsertNode(element, node * 2 + 1);
		return;
	}
}

void PreorderTraversal(int node) {
	if (node == 1 && BST[node] == NULLV) {
		printf("트리가 생성되지 않았습니다!\n");
		return;
	}
	
	if (node == 1) {
		printf("전위 순회 : ");
	}

	if (BST[node] != NULLV) {
		printf("%d ", BST[node]);
		PreorderTraversal(node * 2);
		PreorderTraversal(node * 2 + 1);
	}

	if (node == 1) {
		printf("\n");
	}
	return;
}

void InorderTraversal(int node) {
	if (node == 1 && BST[node] == NULLV) {
		printf("트리가 생성되지 않았습니다!\n");
		return;
	}

	if (node == 1) {
		printf("중위 순회 : ");
	}

	if (BST[node] != NULLV) {
		InorderTraversal(node * 2);
		printf("%d ", BST[node]);
		InorderTraversal(node * 2 + 1);
	}

	if (node == 1) {
		printf("\n");
	}
	return;
}

void PostorderTraversal(int node) {
	if (node == 1 && BST[node] == NULLV) {
		printf("트리가 생성되지 않았습니다!\n");
		return;
	}

	if (node == 1) {
		printf("후위 순회 : ");
	}

	if (BST[node] != NULLV) {
		PostorderTraversal(node * 2);
		PostorderTraversal(node * 2 + 1);
		printf("%d ", BST[node]);
	}

	if (node == 1) {
		printf("\n");
	}
	return;
}

void GetMin(int node) {
	if (BST[node] != NULLV) {
		MINN = (MINN > BST[node]) ? BST[node] : MINN;
		GetMin(node * 2);
		GetMin(node * 2 + 1);
	}
	if (node == 1) {
		printf("최소값 : %d\n", MINN);
	}
	return;
}

void GetMax(int node) {
	if (BST[node] != NULLV) {
		MAXN = (MAXN < BST[node]) ? BST[node] : MAXN;
		GetMax(node * 2);
		GetMax(node * 2 + 1);
	}
	if (node == 1) {
		printf("최대값 : %d\n", MAXN);
	}
	return;
}

void FindNode(int element, int node) {
	if (node == 1) {
		printf("노드 위치 : 루트 > ");
	}
	
	if (BST[node] == element) {
		printf("%d", BST[node]);
		return;
	}
	else if (element < BST[node]) {
		printf("왼쪽 > ");
		FindNode(element, node * 2);
	}
	else if (element > BST[node]) {
		printf("오른쪽 > ");
		FindNode(element, node * 2 + 1);
	}

	if (node == 1) {
		printf("\n");
	}
}

void DeleteNode(int element, int node) {
	if (BST[node] == element) {
		BST[node] = NULLV;
		return;
	}
	else if (element < BST[node]) {
		DeleteNode(element, node * 2);
	}
	else if (element > BST[node]) {
		DeleteNode(element, node * 2 + 1);
	}

	if (node == 1) {
		printf("%d이 제거되었습니다.\n", element);
	}
}

void HeightBST(int node, int height) {
	if (BST[node] == NULLV) {
		Deep = (Deep < height - 1) ? height - 1 : Deep;
	}
	else {
		HeightBST(node * 2, height + 1);
		HeightBST(node * 2 + 1, height + 1);
	}
	if (node == 1) {
		printf("트리의 깊이 : %d\n", Deep);
	}
	return;
}

void GetRightChild(int element, int node) {
	if (BST[node] == element) {
		if (BST[node * 2 + 1] != NULLV) {
			printf("%d의 오른쪽 자식 노드 : %d\n", BST[node], BST[node * 2 + 1]);
		}
	}
	else if (element < BST[node]) {
		GetRightChild(element, node * 2);
	}
	else if (element > BST[node]) {
		GetRightChild(element, node * 2 + 1);
	}
	return;
}

void GetLeftChild(int element, int node) {
	if (BST[node] == element) {
		if (BST[node * 2] != NULLV) {
			printf("%d의 왼쪽 자식 노드 : %d\n", BST[node], BST[node * 2]);
		}
	}
	else if (element < BST[node]) {
		GetLeftChild(element, node * 2);
	}
	else if (element > BST[node]) {
		GetLeftChild(element, node * 2 + 1);
	}
	return;
}

void CountNodeBST(int node) {
	if (node == 1) {
		Nnode = 0;
	}
	if (BST[node] == NULLV) {
		return;
	}
	else {
		Nnode++;
		CountNodeBST(node * 2);
		CountNodeBST(node * 2 + 1);
	}
	if (node == 1) {
		printf("노드의 개수 : %d\n", Nnode);
	}
}

void ClearBST() {
	int i;
	for (i = 1; i < LEN; i++) {
		BST[i] = NULLV;
	}
	MAXN = -NULLV;
	MINN = NULLV;
	Deep = 1;
	return;
}
