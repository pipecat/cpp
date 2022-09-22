#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool valid(int x, int y, int n, int m) {
    return x>=0 && x < n && y>=0 && y < m;
}

// void visit(int x, int y, queue<vector<int>>& q, vector<vector<int>>& visited, int& result) {

// }

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> arr;
    vector<vector<bool>> visited;
    queue<vector<int>> q;
    int result=0;
    for (int i=0; i<n; i++ ){
        string tmp;
        cin >> tmp;
        vector<bool> tmp2(m, false);
        arr.push_back(tmp);
        visited.push_back(tmp2);
    }
    q.push({0,0});
    while (!q.empty() && result < n*m) {
        // cout << "qsize: " << q.size() << endl;
        // cout << "result: " << result << endl;
        int l=q.size();
        for (int i=0; i<l;i++) {
            int x, y;
            vector<int> tmp=q.front();
            q.pop();
            x = tmp[0];
            y = tmp[1];
            if (x == n-1 && y == m-1) {
                cout << result << endl;
                return 0;
            }
            if (valid(x-1, y, n, m) && !((arr[x][y] == 'r' && arr[x-1][y] =='d') || (arr[x][y] == 'e' && arr[x-1][y] =='r') || (arr[x][y] == 'd' && arr[x-1][y] =='e')) && !visited[x-1][y]) {
                q.push({x-1, y});
                visited[x-1][y] = true;
            }
            if (valid(x+1, y, n, m) && !((arr[x][y] == 'r' && arr[x+1][y] =='d') || (arr[x][y] == 'e' && arr[x+1][y] =='r') || (arr[x][y] == 'd' && arr[x+1][y] =='e')) && !visited[x+1][y]) {
                q.push({x+1, y});
                visited[x+1][y] = true;
            }
            if (valid(x, y-1, n, m) && !((arr[x][y] == 'r' && arr[x][y-1] =='d') || (arr[x][y] == 'e' && arr[x][y-1] =='r') || (arr[x][y] == 'd' && arr[x][y-1] =='e')) && !visited[x][y-1]) {
                q.push({x, y-1});
                visited[x][y-1] = true;
            }
            if (valid(x, y+1, n, m) && !((arr[x][y] == 'r' && arr[x][y+1] =='d') || (arr[x][y] == 'e' && arr[x][y+1] =='r') || (arr[x][y] == 'd' && arr[x][y+1] =='e')) && !visited[x][y+1]) {
                q.push({x, y+1});
                visited[x][y+1] = true;
            }
        }
        result++;
    }
    cout << -1 << endl;
    return 0;
}