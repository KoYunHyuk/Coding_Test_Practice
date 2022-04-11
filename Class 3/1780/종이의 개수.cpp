#include <iostream>
#include <vector>


using namespace std; // S2

int N;
int graph[2188][2188];
int result[3];

bool isSame(int x1, int x2, int y1, int y2) {
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			if (graph[x1][y1] != graph[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void Solve(int x1, int x2, int y1, int y2) {
	if (isSame(x1, x2, y1, y2) == true) {
		if (graph[x1][y1] == -1) result[0]++;
		else if (graph[x1][y1] == 0) result[1]++;
		else result[2]++;
	}
	else {
		int div = (x2 - x1 + 1) / 3;
		Solve(x1, x1 + div, y1, y1 + div);
		Solve(x1, x1 + div, y1 + div, y1 + 2 * div);
		Solve(x1, x1 + div, y1 + 2 * div, y2);

		Solve(x1 + div, x1 + 2 * div, y1, y1 + div);
		Solve(x1 + div, x1 + 2 * div, y1 + div, y1 + 2 * div);
		Solve(x1 + div, x1 + 2 * div, y1 + 2 * div, y2);

		Solve(x1 + 2 * div, x2, y1, y1 + div);
		Solve(x1 + 2 * div, x2, y1 + div, y1 + 2 * div);
		Solve(x1 + 2 * div, x2, y1 + 2 * div, y2);
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	Solve(0, N, 0, N);

	for (int i = 0; i < 3; i++) {
		cout << result[i] << endl;
	}

	return 0;
}