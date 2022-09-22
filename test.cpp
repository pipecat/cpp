#include <iostream>
using namespace std;

int main() {
    int a[10][10];
    for (auto line : a) {
        for (auto num : line) {
            cout << num << endl;
        }
    }
    return 0;
}