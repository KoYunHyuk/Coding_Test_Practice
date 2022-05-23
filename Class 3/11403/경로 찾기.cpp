#include <iostream>
#include <cstring>

using namespace std; // S1

int N;
int graph[101][101];
bool visited[101];

void DFS(int vertex) {
	for (int i = 0; i < N; i++) {
		if (graph[vertex][i] == 1 && !visited[i]) {
			visited[i] = true;
			DFS(i);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

 	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 1 && !visited[j]) {
				visited[j] = true;
				DFS(j);
			}
		}

		for (int k = 0; k < N; k++) {
			cout << visited[k] << " ";
		}
		cout << "\n";
		
		memset(visited, 0, sizeof(visited));
	}
}