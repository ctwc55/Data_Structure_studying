#include <stdio.h>

#define LEN 100 //ť�� �ִ�ũ�� ����

int Queue[LEN];// ť�� ����
int head = -1; //���� -1���� �����մϴ� : ()�� ǥ���߽��ϴ�
int tail = 0; //������ �迭�� ���������� 0���� �����մϴ� : ||�� ǥ���߽��ϴ�

//��� ����
void Enqueue(int element); //������ ����
void Dequeue(); //������ ����
void PrintQue(); //ť ��ü ��ȯ(���)
void ReturnFront(); //����Ʈ�� �ִ� ������ ��ȯ(���)
void FullCheck(); //ť�� ���� á���� Ȯ��
void EmptyCheck(); //ť�� ��� �ִ��� Ȯ��
void DataNum(); //�� ������ �� ��ȯ(���)
void ReturnHead(); //��� �ε��� ��ȯ(���)
void ReturnTail(); //���� �ε��� ��ȯ(���)
void DataSearch(int sub); //Ư�� ���� ť �ȿ� �ִ��� Ȯ��
void ReplaceTail(int element); //���Ͽ� �ִ� �� ��ü(��ȯ)
void ClearQue(); //ť�� ��� �� �����(ť ����)

// ADT�� ������� main�Լ� ����
int main()
{
	Enqueue(100); // () |100|
	Enqueue(200); // () 100 |200|
	Enqueue(300); // () 100 200 |300|
	Enqueue(400); // () 100 200 300 |400|
	Enqueue(500); // () 100 200 300 400 |500|
	PrintQue();
	ReturnFront(); 
	FullCheck(); 
	ReplaceTail(700); // () 100 200 300 400 |700|
	ReturnHead();
	ReturnTail();
	Dequeue(); // () 200 300 400 |700|
	Dequeue(); // () 300 400 |700|
	PrintQue();
	DataNum();
	ClearQue(); //

	ReturnHead();
	ReturnTail();
	EmptyCheck();
	Enqueue(500); // () |500|
	Enqueue(600); // () 500 |600|
	Enqueue(700); // () 500 600 |700|
	Enqueue(800); // () 500 600 700 |800|
	Enqueue(900); // () 500 600 700 800 |900|
	PrintQue();
	DataNum();
	DataSearch(1000);
	DataSearch(700);
	Dequeue(); // () 600 700 800 |900|
	Dequeue(); // () 700 800 |900|
	Dequeue(); // () 800 |900|
	ReturnFront();
	PrintQue();
	ClearQue(); //

	system("pause");
	return 0;
}

//--------------------------------
// ��� ������
// ����ڴ� ���� ��ɸ���� ���� ��븸 �ϸ� ��
// ����ڴ� �� ��(�۵�����)�� ���ɵ� ���� �� �ʿ䵵 ����

void Enqueue(int element) {
	Queue[tail] = element;
	tail++;
	return;
}

void Dequeue() {
	head++;
	Queue[head] = 0;
	return;
}

void PrintQue() {
	printf("Queue : ");
	for (int i = head + 1; i < tail; i++) {
		printf("%d ", Queue[i]);
	}
	printf("\n");
	return;
}

void ReturnFront() {
	printf("Front_Data : %d\n", Queue[head + 1]);
	return;
}

void FullCheck() {
	if (tail == LEN) {
		printf("Full_Check_Result : True\n");
	}
	else {
		printf("Full_Check_Result : False\n");
	}
	return;
}

void EmptyCheck() {
	if (tail - head == 1) {
		printf("Empty_Check_Result : True\n");
	}
	else {
		printf("Empty_Check_Result : False\n");
	}
	return;
}

void DataNum() {
	printf("Data_Num : %d\n", (tail - 1) - head);
	return;
}

void ReturnHead() {
	printf("Head Index : %d\n", head);
	return;
}

void ReturnTail() {
	printf("Tail Index : %d\n", tail-1);
	return;
}

void DataSearch(int sub) {
	for (int i = head + 1; i < tail; i++) {
		if (Queue[i] == sub) {
			printf("%d is in the Queue\n", sub);
			return;
		}
	}
	printf("%d is not in the Queue\n", sub);
	return;
}

void ReplaceTail(int element) {
	Queue[tail-1] = element;
	return;
}

void ClearQue() {
	for (int i = head + 1; i < tail; i++) {
		Queue[i] = 0;
	}
	printf("\n");
	head = tail - 1;
	return;
}