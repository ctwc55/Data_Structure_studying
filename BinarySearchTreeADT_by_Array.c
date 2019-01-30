#include <stdio.h>

#define LEN 2049 //����Ž��Ʈ���� �ִ�ũ�� ����
#define NULLV 1000000000 //NULL�� ����

int BST[LEN]; //����Ž��Ʈ���� ���� �޸� ���� ����
int MAXN, MINN; //Ʈ�� ������ �ִ밪�� �ּڰ��� ����
int Deep; //Ʈ���� ���� ����
int Nnode; //����� ���� ����

//��ɳ���
void CreateBST(int element); //����Ž��Ʈ������ (��Ʈ������)
void InsertNode(int element, int node); //����߰�
void PreorderTraversal(int node); //Ʈ���� ���� ��ȸ
void InorderTraversal(int node); //Ʈ���� ���� ��ȸ
void PostorderTraversal(int node); //Ʈ���� ���� ��ȸ
void GetMin(int node); //�ּҰ� ã��
void GetMax(int node); //�ִ밪 ã��
void FindNode(int element, int node); //Ư�� ����� ��ġ ã��
void DeleteNode(int element, int node); //Ư�� ��� ����
void HeightBST(int node, int height); //Ʈ���� ���� ��ȯ(���)
void GetRightChild(int element, int node); //������ �ڽĳ�� �� ��ȯ(���)
void GetLeftChild(int element, int node); //���� �ڽĳ�� �� ��ȯ(���)
void CountNodeBST(int node); //����Ž��Ʈ���� ��尳���� ��ȯ(���)
void ClearBST(); //����Ž��Ʈ�� �ʱ�ȭ

//ADT�� ������� main�Լ� ����
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
// ��� ������
// ����ڴ� ���� ��ɸ���� ���� ��븸 �ϸ� ��
// ����ڴ� �� ��(�۵�����)�� ���ɵ� ���� �� �ʿ䵵 ����

void CreateBST(int element) {
	int i;
	for (i = 1; i < LEN; i++) {
		BST[i] = NULLV;
	}
	BST[1] = element;
	MAXN = -NULLV; //���⼭�� NULLV�� NULL�� �ǹ̿ʹ� ������ ������ ���ڿ��� �����.
	MINN = NULLV; //���� ������ ����.
	Deep = 1;
	return;
}

void InsertNode(int element, int node) {
	
	if (BST[node] == element) {
		printf("���� �̹� �����մϴ�!\n");
		return;
	}
	else if (node >= LEN) {
		printf("Ʈ���� �ִ� ������ ����ϴ�!\n");
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
		printf("Ʈ���� �������� �ʾҽ��ϴ�!\n");
		return;
	}
	
	if (node == 1) {
		printf("���� ��ȸ : ");
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
		printf("Ʈ���� �������� �ʾҽ��ϴ�!\n");
		return;
	}

	if (node == 1) {
		printf("���� ��ȸ : ");
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
		printf("Ʈ���� �������� �ʾҽ��ϴ�!\n");
		return;
	}

	if (node == 1) {
		printf("���� ��ȸ : ");
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
		printf("�ּҰ� : %d\n", MINN);
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
		printf("�ִ밪 : %d\n", MAXN);
	}
	return;
}

void FindNode(int element, int node) {
	if (node == 1) {
		printf("��� ��ġ : ��Ʈ > ");
	}
	
	if (BST[node] == element) {
		printf("%d", BST[node]);
		return;
	}
	else if (element < BST[node]) {
		printf("���� > ");
		FindNode(element, node * 2);
	}
	else if (element > BST[node]) {
		printf("������ > ");
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
		printf("%d�� ���ŵǾ����ϴ�.\n", element);
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
		printf("Ʈ���� ���� : %d\n", Deep);
	}
	return;
}

void GetRightChild(int element, int node) {
	if (BST[node] == element) {
		if (BST[node * 2 + 1] != NULLV) {
			printf("%d�� ������ �ڽ� ��� : %d\n", BST[node], BST[node * 2 + 1]);
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
			printf("%d�� ���� �ڽ� ��� : %d\n", BST[node], BST[node * 2]);
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
		printf("����� ���� : %d\n", Nnode);
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
