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

	// 원하는 좌표가 현재 사분면 내에 존재 하면
	if (r < x + p && r >= x && c < y + p && c >= y) {
		DFS(p / 2, x, y); // 1사분면
		DFS(p / 2, x, y + p / 2); // 2사분면
		DFS(p / 2, x + p / 2, y); // 3사분면
		DFS(p / 2, x + p / 2, y + p / 2); // 4사분면
	}
	else {
		result += p * p;
	}
}

int main() {
	int N;
	cin >> N >> r >> c;

	int p = pow(N); // 가로,세로 길이

	DFS(p, 0, 0);

	return 0;
}