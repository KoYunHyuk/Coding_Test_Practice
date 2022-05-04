#include <iostream>
#include <vector>
#include <queue>

using namespace std; // G5

int M, N;
int result = 0;
int dist[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
	cin >> M >> N;
	queue<vector<int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> dist[i][j];
			if (dist[i][j] == 1) q.push({ i, j });
		}
	}

	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;

			if (dist[xx][yy] == 0) {
				dist[xx][yy] = dist[x][y] + 1;
				q.push({ xx, yy });
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			result = max(result, dist[i][j]);
		}
	}
	cout << result - 1;
}