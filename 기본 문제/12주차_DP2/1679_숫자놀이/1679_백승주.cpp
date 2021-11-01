#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define MAX_INT 2147483647;

int main() {
	int n;				// �־����� ���� ����
	int limit;			// ���� ��� Ƚ�� <=50
	vector<int> numbers;// �־����� ���� �迭

	string str;
	string line;
	
	cin >> n;
	cin.ignore();

	getline(cin, line);
	stringstream ss(line);

	while (getline(ss, str, ' ')) {
		numbers.push_back(stoi(str));
	}
	
	cin >> limit;
	vector<int> min_numbers = {0};	//�� �ε��� ��ȣ�� ����µ� �ʿ��� ������ �ּ� ����
	int value = 0;					//����� �� ���� ����
	int min_cnt;
	vector<int>::iterator iter;
	/*
		1. min_nubers�� �� �ε������� �־��� �ε����� ���� �� �ִ� �ּ� ���� ������ ��
		2. ���� value���� �ּҷ� ���� �� �ִ� ������ ������ ������ ������� �ּ� ������ + 1�� ���� �� ����
			ex) ���� �Է����ǿ���
				value = 3 �϶� 
				min_number[3] = min_munber[0] + 1 OR min_number[2] + 1 �� �ɰ��� �� �� �� ���� ���� ��
				�� ������ ���� ��� ���� Ƚ���� �����Ҷ����� �ݺ�				
	*/
	while (true) {
		value++;	// ������ �� ������ ������� ������ �����÷���
		min_cnt = MAX_INT;	// ����� ������ �ּ� ����
		for (iter = numbers.begin(); iter != numbers.end(); ++iter) {
			int number = *iter;	// ���� �迭�� ����ִ� ����
			if (value - number >= 0) {
				//������ �ִ� ���ڸ� �ϳ� �� ����ؼ� ���� �� �ִ� �ּ� ������ ����
				min_cnt = min_cnt < min_numbers[value - number] + 1 ? min_cnt : min_numbers[value - number] + 1;
			}
			else break;
		}
		min_numbers.push_back(min_cnt);
		if (min_cnt > limit) break; //����� ������ ���� limit�̻��̸� while loop�� ��������
	}
	if (value % 2 == 0) {// Ȧ�� ��
		cout << "holsoon win at " << value;
	}
	else {				// ¦�� ��
		cout << "jjaksoon win at " << value;
	}

	return 0;
}