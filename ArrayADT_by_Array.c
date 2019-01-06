#include <stdio.h>

#define LEN 100 //�迭 �ִ���� ����
#define FIRST 0
#define LAST  -2
#define NEXT  -1
#define PREV  -2

int ARR[LEN];
int index = 0;
int size = 0;

//��� ����
void InsertData(int n); //������ ����
void MoveIndexFL(int n); //ó�� or ������ �ε����� �̵�
void MoveIndexOne(int n); //���� or �� �ε����� �̵�
void ReturnCurData(); //���� �ε����� ������ ��ȯ(���)
void ReplaceCurData(int n); //���� �ε����� ������ ��ü(��ȯ)
void ClearArray(); //�迭�� ��� �� �����
void ShiftData(int n); //���� �ε����� �����͸� ��/	����/�� �Ǵ� ���ϴ� �ε����� �ű��
void ReturnArray(); //�迭 ��ü ��ȯ(���)

// ADT�� ������� main�Լ� ����
int main()
{
	InsertData(100); // |100|
	InsertData(200); // 100 |200|
	InsertData(300); // 100 200 |300|
	InsertData(400); // 100 200 300 |400|
	InsertData(500); // 100 200 300 400 |500|
	ReturnArray();
	MoveIndexFL(FIRST); // |100| 200 300 400 500
	MoveIndexOne(NEXT); // 100 |200| 300 400 500
	ReturnCurData();
	ReplaceCurData(700); // 100 |700| 300 400 500
	MoveIndexFL(LAST); // 100 700 300 400 |500|
	ShiftData(1); // 100 |500| 700 300 400
	ReturnArray();
	ClearArray(); //

	InsertData(500); // |500|
	InsertData(600); // 500 |600|
	InsertData(700); // 500 600 |700|
	InsertData(800); // 500 600 700 |800|
	InsertData(900); // 500 600 700 800 |900|
	ReturnArray();
	ShiftData(2); // 500 600 |900| 700 800
	MoveIndexOne(NEXT); // 500 600 900 |700| 800
	ShiftData(FIRST); // |700| 500 600 900 800
	MoveIndexFL(LAST); // 700 500 600 900 |800|
	MoveIndexOne(PREV); // 700 500 600 |900| 800
	ReturnCurData();
	ReturnArray();
	ClearArray(); //

	system("pause");
	return 0;
}

//--------------------------------
// ��� ������
// ����ڴ� ���� ��ɸ���� ���� ��븸 �ϸ� ��
// ����ڴ� �� ��(�۵�����)�� ���ɵ� ���� �� �ʿ䵵 ����

void InsertData(int n) {
	if (size >= LEN) {
		printf("�迭�� �ִ� �뷮�� �ʰ��մϴ�!! �����͸� �߰��� �� �����ϴ�!!\n");
		return;
	}
	ARR[size] = n;
	size++;
	index = size - 1;
	return;
}

void MoveIndexFL(int n) {
	if (n == FIRST) {
		index = 0;
	}
	else if (n == LAST) {
		index = size-1;
	}
	return;
}

void MoveIndexOne(int n) {
	if (n == NEXT) {
		if (index == size-1) {
			printf("�迭�� ������ �ε����Դϴ�!! ���� �ε����� �̵��� �� �����ϴ�!!\n");
			return;
		}
		index++;
	}
	else if (n == PREV) {
		if (index == 0) {
			printf("�迭�� ù��° �ε����Դϴ�!! ���� �ε����� �̵��� �� �����ϴ�!!\n");
			return;
		}
		index--;
	}
	return;
}

void ReturnCurData() {
	if (size == 0) {
		printf("�迭�� �ƹ� ���ҵ� ������� �ʽ��ϴ�!!\n");
		return;
	}
	printf("%d��° �ε����� ������ : %d\n", index, ARR[index]);
	return;
}

void ReplaceCurData(int n) {
	if (size == 0) {
		printf("�迭�� �ƹ� ���ҵ� ������� �ʽ��ϴ�!!\n");
		return;
	}
	ARR[index] = n;
	return;
}

void ClearArray() {
	int i; 

	for (i = 0; i < size; i++) {
		ARR[i] = 0;
	}
	index = 0;
	size = 0;
	return;
}

void ShiftData(int n) {
	int i, tmp;
	
	if (size == 0) {
		printf("�迭�� �ƹ� ���ҵ� ������� �ʽ��ϴ�!!\n");
		return;
	}

	tmp = ARR[index];
	if (n == FIRST) {
		for (i = index; i > 0; i--) {
			ARR[i] = ARR[i - 1];
		}
		ARR[0] = tmp;
		index = 0;
	}
	else if (n == LAST) {
		for (i = index; i < size-1; i++) {
			ARR[i] = ARR[i + 1];
		}
		ARR[size - 1] = tmp;
		index = size - 1;
	}
	else if (n == NEXT) {
		if (index == size - 1) {
			printf("�迭�� ������ �ε����Դϴ�!! �����͸� �ű� �� �����ϴ�!!\n");
			return;
		}
		ARR[index] = ARR[index + 1];
		ARR[index + 1] = tmp;
		index += 1;
	}
	else if (n == PREV) {
		if (index == 0) {
			printf("�迭�� ù��° �ε����Դϴ�!! �����͸� �ű� �� �����ϴ�!!\n");
			return;
		}
		ARR[index] = ARR[index - 1];
		ARR[index - 1] = tmp;
		index -= 1;
	}
	else if (n >= size) {
		printf("�迭�� �ִ� �ε����� �Ѿ�ϴ�!! �����͸� �ű� �� �����ϴ�!!\n");
		return;
	}
	else {
		if (n > index) {
			for (i = index; i < n; i++) {
				ARR[i] = ARR[i + 1];
			}
		}
		else if (n < index) {
			for (i = index; i > n; i--) {
				ARR[i] = ARR[i - 1];
			}
		}
		ARR[n] = tmp;
		index = n;
	}
	return;
}

void ReturnArray() {
	int i;
	
	if (size == 0) {
		printf("�迭�� �ƹ� ���ҵ� ������� �ʽ��ϴ�!!\n");
		return;
	}
	printf("ARR : ");
	for (i = 0; i < size; i++) {
		printf("%d ", ARR[i]);
	}
	printf("\n");
	return;
}