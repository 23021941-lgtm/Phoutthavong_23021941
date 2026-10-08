#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortAscending(vector<int> &a) {
    sort(a.begin(), a.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sortAscending(a);

    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
// Độ phức tạp thời gian (Time Complexity): O(N log N)
// Độ phức tạp không gian (Space Complexity): O(N)