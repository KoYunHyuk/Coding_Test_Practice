#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std; // S1

int N;
int graph[26][26];
bool visit[26][26];
int result[676];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void DFS(int x, int y, int count) {
	visit[x][y] = true;
	graph[x][y] = count;
	result[count]++;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= N || y < 0 || y >= N) continue;
		if (graph[xx][yy] == 1 && !visit[xx][yy]) {
			DFS(xx, yy, count);
		}
	}
}

int main() {
	cin >> N;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			graph[i][j] = str[j] - '0';
		}
	}

	int count = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 1 && !visit[i][j]) {
				DFS(i, j, count);
				count++;
			}
		}
	}

	cout << count - 1 << "\n";

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i < count; i++) {
		pq.push(result[i]);
	}

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
}