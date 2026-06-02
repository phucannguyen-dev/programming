/*
 * Bài toán Josephus có một công thức truy hồi cực kỳ nổi tiếng. Nếu chúng ta quy ước chỉ số mảng bắt đầu từ 0 đến N-1:
 * Gọi J(N, n) là vị trí của người sống sót trong vòng tròn có N người, bước nhảy n.
 * Công thức:
 * J(1, n) = 0
 * J(N, n) = (J(N-1, n) + n) \% N
 */

#include <iostream>
#include <vector>
using namespace std;

int josephus(int N, int n) {
    int res = 0; // Trường hợp cơ bản: 1 người thì vị trí là 0
    for (int i = 2; i <= N; i++) {
        res = (res + n) % i;
    }
    return res;
}

int main() {
    int sl; cin >> sl;
    vector<int> tasks(sl);
    for (int i = 0; i < sl; i++) cin >> tasks[i];
    int n; cin >> n;

    // Tìm index của nhiệm vụ sống sót
    int survivor_index = josephus(sl, n);

    // In ra giá trị tương ứng
    cout << tasks[survivor_index] << endl;

    return 0;
}
