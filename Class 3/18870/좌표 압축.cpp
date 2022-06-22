#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N;
map<int, int> m;

int main() {
	cin >> N;

	vector<int> line1, line2;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		line1.push_back(num);
		line2.push_back(num);
	}

	sort(line2.begin(), line2.end());
	
	int count = 1; // map은 할당 되지 않은 값을 모두 0으로 초기화 시키기 때문
	for (int i = 0; i < N; i++) {
		if (!m[line2[i]]) {
			m[line2[i]] = count;
			count++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << m[line1[i]] - 1 << " ";
	}
}