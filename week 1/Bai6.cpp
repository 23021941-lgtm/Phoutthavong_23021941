#include <iostream>
#include <vector>
using namespace std;

void deleteAtK(vector<int> &a, int k) {
    if (k >= 1 && k <= (int)a.size()) {
        a.erase(a.begin() + (k - 1));
    }
}

void insertAtM(vector<int> &a, int y, int m) {
    if (m >= 1 && m <= (int)a.size() + 1) {
        a.insert(a.begin() + (m - 1), y);
    }
}

void printArray(const vector<int> &a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int k;
    cin >> k;
    deleteAtK(a, k);
    printArray(a);

    int y, m;
    cin >> y >> m;
    insertAtM(a, y, m);
    printArray(a);

    return 0;
}
// Độ phức tạp thời gian (Time Complexity): O(N)
// Độ phức tạp không gian (Space Complexity): O(N)