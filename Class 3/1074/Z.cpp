#include <iostream>


using namespace std;
int r = 0;
int c = 0;
int result = 0;

int pow(int n) {
	int num = 1;
	for (int i = 0; i < n; i++) {
		num *= 2;
	}
	return num;
}

void DFS(int p, int x, int y) {
	if (x == r && y == c) {
		cout << result << "\n";
		return;
	}

	// ���ϴ� ��ǥ�� ���� ��и� ���� ���� �ϸ�
	if (r < x + p && r >= x && c < y + p && c >= y) {
		DFS(p / 2, x, y); // 1��и�
		DFS(p / 2, x, y + p / 2); // 2��и�
		DFS(p / 2, x + p / 2, y); // 3��и�
		DFS(p / 2, x + p / 2, y + p / 2); // 4��и�
	}
	else {
		result += p * p;
	}
}

int main() {
	int N;
	cin >> N >> r >> c;

	int p = pow(N); // ����,���� ����

	DFS(p, 0, 0);

	return 0;
}