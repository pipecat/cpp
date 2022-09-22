#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<char> m = {'a', 'e', 'i', 'o', 'u'};
    string s;
    string baidu="baidu";
    int result=0;
    cin >> s;
    for (int i=0; i<s.size()-4; i++) {
        unordered_set<char> letter;
        for (int j=0;j<5;j++) {
            if (!letter.count(s[i+j]) && (m.count(s[i+j]) == m.count(baidu[j]))) letter.insert(s[i+j]);
        }
        if (letter.size() == 5) result++;
    }
    cout << result << endl;
    
}