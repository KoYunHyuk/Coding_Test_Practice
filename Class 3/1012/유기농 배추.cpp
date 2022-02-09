#include <iostream>
#include <cstring>

using namespace std;

int result = 0;
int graph[51][51];
int visit[51][51] = { false };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void DFS(int M, int N, int X, int Y) {
	visit[X][Y] = true;

	for (int i = 0; i < 4; i++) {
		int xx = X + dx[i];
		int yy = Y + dy[i];

		if (xx >= 0 && xx < M && yy >= 0 && yy < N && graph[xx][yy]==1 && !visit[xx][yy]) {
			DFS(M, N, xx, yy);
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int M, N, K;
		cin >> M >> N >> K;

		// graph, visit, result 초기화
		memset(graph, 0, sizeof(graph));
		memset(visit, false, sizeof(visit));
		result = 0;

		// graph 생성
		for (int j = 0; j < K; j++) {
			int X, Y;
			cin >> X >> Y;

			graph[X][Y] = 1;
		}
		
		// DFS
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (graph[j][k] == 1 && !visit[j][k]) {
					DFS(M, N, j, k);
					result++;
				}
			}
		}
		
		cout << result << endl;
	}
}