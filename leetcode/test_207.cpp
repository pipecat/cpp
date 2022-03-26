#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool dfs(int i, vector<int>& visited,  vector< vector<int> >& v) {
        cout << "visiting: " << i << endl;
        cout << "visited:";
        for (int k = 0; k < visited.size(); k++) {
            cout << " " << visited[k];
        }
        cout << endl;
        visited[i] = 1;
        for (int j = 0; j < v[i].size(); j++) {
            if (visited[v[i][j]] == 0) {
                return dfs(v[i][j], visited, v);
                // cout << "i:" << i << "j" << j << "vij" << v[i][j] << endl;
            } else if (visited[v[i][j]] == 1) {
                // cout << 1 << endl;
                return false;
            } else continue;
        }
        visited[i] = 2;
        return true;
    }


    bool canFinish(int numCourses, vector< vector<int> >& prerequisites) {
        vector< vector<int> > v;
        vector<int> visited(numCourses, 0);
        v.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 ) {
                bool result = dfs(i, visited, v);
                // cout << "result:" << result << endl;
                if (!result) return false;
            }
        }
        return true;
    }
};

int main() {
    int numCourses, v_num;
    vector< vector<int> > input_vec;
    cin >> numCourses;
    cin >> v_num;
    for (int i = 0; i < v_num; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        input_vec.push_back(temp);
    }
    Solution* solu = new Solution();
    cout << solu->canFinish(numCourses, input_vec) << endl;

    return 0;
}

