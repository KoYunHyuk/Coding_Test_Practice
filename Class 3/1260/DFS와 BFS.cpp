#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
int graph[1001][1001];
int visit[1001];
queue<int> q;


void DFS(int v) {
	visit[v] = true;
	cout << v << " ";
	
	for (int i = 1; i <= N; i++) {
		if (!visit[i] && graph[v][i] == true) {
			DFS(i);
		}
	}
}

void BFS(int start) {
	q.push(start);
	visit[start] = true;
	cout << start << " ";

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		
		for (int i = 1; i <= N; i++) {
			if (graph[node][i] == 1 && !visit[i]) {
				q.push(i);
				visit[i] = true;
				cout << i << " ";
			}
		}
	}

}

int main() {
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int v, w;
		cin >> v >> w;

		graph[v][w] = 1;
		graph[w][v] = 1;
	}

	DFS(V);
	cout << endl;

	for (int i = 1; i <= N; i++) {
		visit[i] = false;
	}

	BFS(V);
	return 0;
}