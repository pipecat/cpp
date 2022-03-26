#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void display(vector<int> vec) 
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
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



void bubble_sort(vector<int> &vec, ofstream &ofil) 
{
    for (int i = 0; i < vec.size()-1; i++)
    {
        for (int j = vec.size()-1; j > i ; j--)
        {
            ofil << j << endl;
            if (vec[j-1] > vec[j])
            {
                swap(vec[j-1], vec[j]);
            }
            
        }
        
    }
    
}

int main() {
    ofstream ofil( "text_out1");
    int ia[8] = {1,4,3,6,7,8,2,9};
    vector<int> vec(ia, ia+8);
    cout << "vec before sort: ";
    display(vec);

    bubble_sort(vec, ofil);

    cout << "vec after sort: ";
    display(vec);
}