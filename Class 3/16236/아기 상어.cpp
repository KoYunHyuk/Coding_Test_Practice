#include <iostream>
#include <queue>

using namespace std; // G3

int N;
int fish_count;
int shark_size = 2;
int result;

int map[21][21];
int dist[21][21];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	cin >> N;

	int shark_row, shark_col;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark_row = i;
				shark_col = j;
			}
		}
	}

	while (1) {
		queue<pair<int, int>> q;
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				dist[i][j] = -1;
			}
		}

		q.push({ shark_row, shark_col });
		dist[shark_row][shark_col] = 0;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];

				if (xx < 0 || xx >= N || yy < 0 || yy >= N) continue;
				if (dist[xx][yy] != -1 || map[xx][yy] > shark_size) continue;

				dist[xx][yy] = dist[x][y] + 1;
				q.push({ xx, yy });
			}
		}

		int distance = 987654321;
		int min_row = 22;
		int min_col = 22;

		for (int i = N - 1; i >= 0; i--) {
			for (int j = N - 1; j >= 0; j--) {
				if (map[i][j] == 0 || map[i][j] == 9 || map[i][j] >= shark_size || dist[i][j] == -1) continue;

				if (dist[i][j] <= distance) {
					distance = dist[i][j];
					min_row = i;
					min_col = j;
				}
			}
		}

		if (distance == 987654321) {
			cout << result;
			return 0;
		}

		map[shark_row][shark_col] = 0;
		shark_row = min_row;
		shark_col = min_col;
		fish_count++;

		if (fish_count == shark_size) {
			fish_count = 0;
			shark_size++;
		}
		map[min_row][min_col] = 9;
		result += dist[min_row][min_col];
	}
}