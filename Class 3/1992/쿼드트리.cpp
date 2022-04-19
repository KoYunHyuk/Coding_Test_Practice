#include <iostream>
#include <vector>
#include <string>

using namespace std; // S1

int N;
vector<string> graph;

bool isSame(int size, int x, int y) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (graph[i][j] != graph[x][y]) return false;
		}
	}
	return true;
}

void divide(int size, int x, int y) {
	if (isSame(size, x, y) == true) {
		cout << graph[x][y];
	}
	else {
		cout << "(";
		divide(size / 2, x, y);
		divide(size / 2, x, y + size / 2);
		divide(size / 2, x + size / 2, y);
		divide(size / 2, x + size / 2, y + size / 2);
		cout << ")";
	}

}

int main() {
	cin >> N;
	
	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		graph.push_back(str);
	}

	divide(N, 0, 0);
}