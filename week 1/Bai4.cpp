#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void simplifyFraction(int a, int b) {
    if (b == 0) return;
    int g = gcd(a, b);
    a /= g;
    b /= g;
    if (b < 0) {
        a = -a;
        b = -b;
    }
    cout << a << "/" << b << endl;
}

int main() {
    int a, b;
    cin >> a >> b;
    simplifyFraction(a, b);
    return 0;
}
// Độ phức tạp thời gian (Time Complexity): O(min(a, b))
// Độ phức tạp không gian (Space Complexity): O(1)