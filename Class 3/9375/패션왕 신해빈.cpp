#include <iostream>
#include <string>
#include <map>

using namespace std; // S3

int test_case;

int main() {
	cin >> test_case;

	while (test_case--) {
		int n;
		cin >> n;
		
		map<string, int> m;
		string name, type;
		for (int i = 0; i < n; i++) {
			cin >> name >> type;

			if (m.find(type) == m.end()) { // map�� �ش� ���� ������ ���� ��
				m.insert({ type, 1 });
			}
			else { // map�� �ش� ���� ������ �� �� �̻� ���� ��
				m[type]++;
			}
		}

		int answer = 1;
		for (auto i : m) {
			answer *= (i.second + 1);
		}
		answer -= 1;
		cout << answer << "\n";
	}

}