#include <iostream>
#include <vector>

using namespace std; // S3

int N;
int graph[129][129];
int result[2];

bool isSame(int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (graph[x][y] != graph[i][j]) return false;
		}
	}
	return true;
}

void divide(int x, int y, int size) {
	if (isSame(x, y, size) == true) {
		result[graph[x][y]]++;
		return;
	}

	divide(x, y, size / 2);
	divide(x, y + size / 2, size / 2);
	divide(x + size / 2, y, size / 2);
	divide(x + size / 2, y + size / 2, size / 2);
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	divide(0, 0, N);
	cout << result[0] << "\n" << result[1];
}