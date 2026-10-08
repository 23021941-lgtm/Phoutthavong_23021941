#include <iostream>
#include <vector>
using namespace std;

long long sumMatrix(const vector<vector<int>> &a) {
    long long sum = 0;
    for (const auto &row : a) {
        for (int val : row) sum += val;
    }
    return sum;
}

void deleteRow(vector<vector<int>> &a, int i) {
    if (i >= 1 && i <= (int)a.size()) {
        a.erase(a.begin() + (i - 1));
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> a[r][c];
        }
    }

    cout << sumMatrix(a) << endl;

    int i;
    cin >> i;
    deleteRow(a, i);

    for (const auto &row : a) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
// Độ phức tạp thời gian (Time Complexity): O(N * M)
// Độ phức tạp không gian (Space Complexity): O(N * M)