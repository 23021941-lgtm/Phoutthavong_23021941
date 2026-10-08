#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    double avg = sum / n;
    for (double x : a) {
        if (x >= avg) cout << x << " ";
    }
    cout << endl;
    return 0;
}
// Độ phức tạp thời gian (Time Complexity): O(N)
// Độ phức tạp không gian (Space Complexity): O(N)