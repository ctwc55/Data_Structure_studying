#include <stdio.h>

#define LEN 100 //큐의 최대크기 저장

int Queue[LEN];// 큐의 선언
int head = -1; //헤드는 -1에서 시작합니다 : ()로 표현했습니다
int tail = 0; //테일은 배열과 마찬가지로 0부터 시작합니다 : ||로 표현했습니다

//기능 나열
void Enqueue(int element); //데이터 삽입
void Dequeue(); //데이터 제거
void PrintQue(); //큐 전체 반환(출력)
void ReturnFront(); //프론트에 있는 데이터 반환(출력)
void FullCheck(); //큐가 가득 찼는지 확인
void EmptyCheck(); //큐가 비어 있는지 확인
void DataNum(); //총 데이터 수 반환(출력)
void ReturnHead(); //헤드 인덱스 반환(출력)
void ReturnTail(); //테일 인덱스 반환(출력)
void DataSearch(int sub); //특정 값이 큐 안에 있는지 확인
void ReplaceTail(int element); //테일에 있는 값 대체(변환)
void ClearQue(); //큐의 모든 값 지우기(큐 비우기)

// ADT를 기반으로 main함수 정의
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
// 기능 구현부
// 사용자는 위의 기능목록을 보고 사용만 하면 됨
// 사용자는 이 밑(작동원리)에 관심도 없고 볼 필요도 없음

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