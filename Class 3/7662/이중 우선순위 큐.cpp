#include <iostream>
#include <set>

using namespace std; // G4

int T, k;
string str;

int main() {
	cin >> T;
	char c;
	int n;
	while (T--) {
		cin >> k;
		multiset<int> ms;

		while (k--) {
			cin >> c >> n;
			if (c == 'I') { // Insert
				ms.insert(n);
			}
			else { // Delete
				if (!ms.empty() && n == -1) { // 최소값 삭제
					ms.erase(ms.begin());
				}
				else if (!ms.empty() && n == 1) { // 최댓값 삭제
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
			}
		}

		if (ms.empty()) {
			cout << "EMPTY\n";
		}
		else {
			auto end_iter = ms.end();
			end_iter--;
			cout << *end_iter << " " << *ms.begin() << "\n";
		}

	}
}