#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph;
bool visited[1001];

void DFS(int node) {
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]] == false) {
			DFS(graph[node][i]);
		}
	}
}

int main() {
	cin >> N >> M;
	graph.resize(N + 1);

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			DFS(i);
			result++;
		}
	}
	cout << result;
}