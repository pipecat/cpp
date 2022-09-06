#include <string>
#include <iostream>
#include <vector>

using namespace std;

void get_next(string t, vector<int> &next)
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < t.size() - 1)
    {
        if (j == -1 || t[i] == t[j] || t[i] == '*' || t[j] == '*')
        {
            next[++i] = ++j;
        }
        else
        {
            j = next[j];
        }
    }
}

int KMP_search(string s, string t)
{
    int i = 0, j = 0, result=0;
    vector<int> next(t.size());
    get_next(t, next);
    while (j == -1 || (i < s.size() && j < t.size()))
    {
        if (j == -1 || s[i] == t[j] || t[j] == '*')
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
        if (j == t.size()) {
        result++;
        i = i - j + 1;
        j = 0;
    }
    }
    return result;
}

int main()
{
    int m, n;
    string s, t;
    cin >> m >> n;
    cin >> s;
    cin >> t;
    cout << KMP_search(s, t) << endl;
    return 0;
}