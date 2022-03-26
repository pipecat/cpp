#include <iostream>
#include <vector>
using namespace std;

int f(int n) {
    if (n == 1 || n == 2)
    {
        return 1;
    } else {
        return f(n-1) + f(n-2);
    }
}

int main() {
    vector<int> fibo;
    for (int i = 1; i <= 1000; i++)
    {
        if (i == 1 || i == 2)
        {
            fibo.push_back(1);
        } else {
            fibo.push_back(fibo[i-1] + fibo[i-2]);
        }
    }
    cout << f(8) << endl;
    cout << fibo[7] << endl;
    
}