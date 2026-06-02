#include <iostream>
#include <vector>
using namespace std;

// Hàm đếm số nhiệm vụ còn lại (chưa bằng -1)
int countRemaining(const vector<int>& tasks) {
    int count = 0;
    for (int x : tasks) {
        if (x != -1) count++;
    }
    return count;
}

int main() {
    int sl;
    if (!(cin >> sl)) return 0;

    vector<int> tasks(sl);
    for (int i = 0; i < sl; i++) {
        cin >> tasks[i];
    }

    int n; cin >> n;

    int pos = 0;
    // Lặp cho đến khi chỉ còn đúng 1 phần tử
    while (countRemaining(tasks) > 1) {
        int step = 0;

        // Đếm đủ n phần tử CÒN SỐNG
        while (step < n) {
            if (tasks[pos] != -1) {
                step++;
                if (step == n) {
                    tasks[pos] = -1; // Loại bỏ phần tử thứ n
                    break;
                }
            }
            pos = (pos + 1) % sl; // Di chuyển vòng tròn an toàn
        }
        // Sau khi xóa, phần tử tiếp theo sẽ bắt đầu đếm
        pos = (pos + 1) % sl;
    }

    // In ra phần tử cuối cùng còn sót lại
    for (int i = 0; i < sl; i++) {
        if (tasks[i] != -1) {
            cout << tasks[i] << endl;
            break;
        }
    }

    return 0;
}
