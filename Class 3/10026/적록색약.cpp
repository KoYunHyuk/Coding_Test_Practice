#include <iostream>
#include <vector>
#include <cstring>

using namespace std; // G5

int N;
char section[101][101];
bool visited[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int result = 0;

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || xx >= N || yy < 0 || yy >= N) continue;
		if (section[xx][yy] == section[x][y] && !visited[xx][yy]) {
			DFS(xx, yy);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> section[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				DFS(i, j);
				result++;
			}
		}
	}

	cout << result << " ";
	result = 0;
	
	memset(visited, 0, sizeof(visited));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (section[i][j] == 'R') section[i][j] = 'G';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				DFS(i, j);
				result++;
			}
		}
	}
	cout << result;

}