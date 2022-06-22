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
	
	int count = 1; // map�� �Ҵ� ���� ���� ���� ��� 0���� �ʱ�ȭ ��Ű�� ����
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