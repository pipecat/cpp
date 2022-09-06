#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0}
        };
        bool result = false;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                ssearch(board, word, visited, 0, i, j, result);
                if (result == true) return result;
            }
        }
        return result;
    }
    void ssearch(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int index, int x, int y, bool& result) {
        if (result || index >= word.size()) {
            result = true;
            return;
        }
        if (!valid(x, y, board.size(), board[0].size()) || visited[x][y]) return;
        if (board[x][y] == word[index]) {
            visited[x][y] = true;
            ssearch(board, word, visited, index+1, x+1, y, result);
            ssearch(board, word, visited, index+1, x-1, y, result);
            ssearch(board, word, visited, index+1, x, y+1, result);
            ssearch(board, word, visited, index+1, x, y-1, result);
            visited[x][y] = false;
        }
    }
    bool valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};

int main() {
    Solution* solu = new Solution();
    vector<char> line1={'A', 'E'};
    vector<char> line2={'S', 'F'};
    vector<vector<char>> a;
    a.push_back(line1);
    a.push_back(line2);
    string word="EFS";
    bool result;
    result = solu->exist(a, word);
    cout << result << endl;
    return 0;
}