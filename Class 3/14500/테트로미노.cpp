#include <iostream>
#include <algorithm>

using namespace std; // G5

int N, M;
int graph[501][501];
bool visited[501][501];
int result;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void DFS(int x, int y, int sum, int count) {
	if (count == 4) {
		if (sum > result) result = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= M || visited[xx][yy]) continue;

		visited[xx][yy] = true;
		DFS(xx, yy, sum + graph[xx][yy], count + 1);
		visited[xx][yy] = false;
	}

	if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < N) { // っ
		result = max(result, graph[x - 1][y] + graph[x][y - 1] + graph[x][y] + graph[x + 1][y]);
	}
	if (x - 1 >= 0 && y + 1 < M && x + 1 < N) { // た
		result = max(result, graph[x - 1][y] + graph[x][y + 1] + graph[x][y] + graph[x + 1][y]);
	}
	if (y - 1 >= 0 && y + 1 < M && x + 1 < N) { // で
		result = max(result, graph[x][y] + graph[x + 1][y] + graph[x + 1][y - 1] + graph[x + 1][y + 1]);
	}
	if (y - 1 >= 0 && y + 1 < M && x + 1 < N) { // ぬ
		result = max(result, graph[x][y - 1] + graph[x][y] + graph[x][y + 1] + graph[x + 1][y]);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			DFS(i, j, graph[i][j], 1);
			visited[i][j] = false;
		}
	}


	cout << result;
}