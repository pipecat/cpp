#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> vec)
{
    int ix, i;
    for (int ix = 0; ix < vec.size(); ix++)
    {
        cout << vec[ix] << ' ';
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void bubble_sort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size()-i-1; j++)
        {
            if (vec[j] < vec[j+1])
            {
                swap(vec[j], vec[j+1]);
            }   
        }   
    }
}

int main()
{
    int ia[8] = {2,3,5,3,4,7,8,1};
    vector<int> vec(ia, ia+8);


    cout << "vector before sort:" << endl;
    display(vec);
    cout << "vector after sort:" << endl;
    bubble_sort(vec);
    display(vec);
    return 0;
}