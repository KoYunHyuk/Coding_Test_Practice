#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std; // S1

int N, M;
int result = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<string> graph;
vector<vector<bool>> visit;


void BFS(int row, int col) {
	queue<tuple<int, int, int>> q;
	q.push({ row, col, 1 });

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int count = get<2>(q.front());
		q.pop();

		if (x == N - 1 && y == M - 1) {
			result = count;
			break;
		}
		
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && xx < N && yy >= 0 && yy < M && !visit[xx][yy] && graph[xx][yy] == '1') {
				q.push({ xx, yy, count + 1 });
				visit[xx][yy] = true;
			}
		}

	}
}

int main() {
	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		graph.push_back(str);
	}

	for (int i = 0; i < N; i++) {
		vector<bool> temp(M, false);
		visit.push_back(temp);
	}
		
	BFS(0, 0);
	cout << result;
}