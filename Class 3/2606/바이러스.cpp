#include <iostream>
#include <vector>

using namespace std; // S3

int N, M;
int graph[101][101];
bool visit[101];


void DFS(int start) {
	visit[start] = true;

	for (int i = 1; i <= N; i++) {
		if (graph[start][i] == 1 && !visit[i]) {
			DFS(i);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	DFS(1);

	int result = 0;
	for (int i = 2; i <= N; i++) {
		if (visit[i] == true) result++;
	}
	cout << result;
}