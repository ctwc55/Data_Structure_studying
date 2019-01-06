#include <stdio.h>

#define LEN 100 //배열 최대길이 저장
#define FIRST 0
#define LAST  -2
#define NEXT  -1
#define PREV  -2

int ARR[LEN];
int index = 0;
int size = 0;

//기능 나열
void InsertData(int n); //데이터 삽입
void MoveIndexFL(int n); //처음 or 마지막 인덱스로 이동
void MoveIndexOne(int n); //다음 or 전 인덱스로 이동
void ReturnCurData(); //현재 인덱스의 데이터 반환(출력)
void ReplaceCurData(int n); //현재 인덱스의 데이터 대체(변환)
void ClearArray(); //배열의 모든 값 지우기
void ShiftData(int n); //현재 인덱스의 데이터를 전/	다음/끝 또는 원하는 인덱스로 옮기기
void ReturnArray(); //배열 전체 반환(출력)

// ADT를 기반으로 main함수 정의
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
// 기능 구현부
// 사용자는 위의 기능목록을 보고 사용만 하면 됨
// 사용자는 이 밑(작동원리)에 관심도 없고 볼 필요도 없음

void InsertData(int n) {
	if (size >= LEN) {
		printf("배열의 최대 용량을 초과합니다!! 데이터를 추가할 수 없습니다!!\n");
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
			printf("배열의 마지막 인덱스입니다!! 다음 인덱스로 이동할 수 없습니다!!\n");
			return;
		}
		index++;
	}
	else if (n == PREV) {
		if (index == 0) {
			printf("배열의 첫번째 인덱스입니다!! 이전 인덱스로 이동할 수 없습니다!!\n");
			return;
		}
		index--;
	}
	return;
}

void ReturnCurData() {
	if (size == 0) {
		printf("배열에 아무 원소도 들어있지 않습니다!!\n");
		return;
	}
	printf("%d번째 인덱스의 데이터 : %d\n", index, ARR[index]);
	return;
}

void ReplaceCurData(int n) {
	if (size == 0) {
		printf("배열에 아무 원소도 들어있지 않습니다!!\n");
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
		printf("배열에 아무 원소도 들어있지 않습니다!!\n");
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
			printf("배열의 마지막 인덱스입니다!! 데이터를 옮길 수 없습니다!!\n");
			return;
		}
		ARR[index] = ARR[index + 1];
		ARR[index + 1] = tmp;
		index += 1;
	}
	else if (n == PREV) {
		if (index == 0) {
			printf("배열의 첫번째 인덱스입니다!! 데이터를 옮길 수 없습니다!!\n");
			return;
		}
		ARR[index] = ARR[index - 1];
		ARR[index - 1] = tmp;
		index -= 1;
	}
	else if (n >= size) {
		printf("배열의 최대 인덱스를 넘어갑니다!! 데이터를 옮길 수 없습니다!!\n");
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
		printf("배열에 아무 원소도 들어있지 않습니다!!\n");
		return;
	}
	printf("ARR : ");
	for (i = 0; i < size; i++) {
		printf("%d ", ARR[i]);
	}
	printf("\n");
	return;
}