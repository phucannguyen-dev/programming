#include <iostream>
#include <vector>
using namespace std;

int checkOne(vector<int> tasks_rv) {
    int count = 0;
    for (int i = 0; i < tasks_rv.size() - 1; i++) {
        if (tasks_rv[i] != -1) {
            count++;
        }
    }
    return count;
}

int main() {
    int sl; cin >> sl;
    vector<int> tasks(sl);

    for (int i = 0; i < sl; i++) { cin >> tasks[i]; }

    int n; cin >> n;
    // n = 3

    int step = 1;
    int pos = 0;

    while (checkOne(tasks) >= 1) {
        if (pos > (tasks.size() - 1)) {
            pos = pos - tasks.size();
        }
        if (step == n) {
            tasks[pos] = -1;
            step = 1;
            pos++;
            continue;
        }
        pos++;
        step++;
    }

    for (int i = 0; i < sl; i++) {
        if (tasks[i] != -1) {
            cout << tasks[i];
        }
    }

    return 0;
}
