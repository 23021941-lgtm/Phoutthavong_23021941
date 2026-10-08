#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum << endl;
    return 0;
}
// Độ phức tạp thời gian (Time Complexity): O(N)
// Độ phức tạp không gian (Space Complexity): O(1)