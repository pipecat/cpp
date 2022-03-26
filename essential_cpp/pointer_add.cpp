#include<iostream>
#include<vector>

using namespace std;

template <typename T>
T* find(vector<T> &vec, T value)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == value)
        {
            return &vec[i];
        }
    }
    return 0;
    
}

int main() 
{
    vector<int> a;
    int at[] = {1,2,3,4,5};
    vector<float> b;
    float bt[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    for (int i = 0; i < 5; i++)
    {
        a.push_back(at[i]);
        b.push_back(bt[i]);
    }
    
    int* p1 = find(a, 4);
    float v = 4.4;
    float* p2 = find(b, v);
    cout << "p1" << ": " << p1 << endl;
    cout << "p2" << ": " << p2 << endl;
    return 0;
}