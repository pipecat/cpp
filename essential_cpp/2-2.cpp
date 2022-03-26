#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<int>* pentagonal_seq(int size) 
{
    static vector<int> seq;
    if (size == 0)
    {
        return nullptr;
    }
    
    for (int i = 0; i <= size; i++)
    {
        seq.push_back(i * (3*i - 1) / 2);
    }
    
    return &seq;
}

void display(const vector<int> &seq, string s) 
{
    for (int i = 0; i < seq.size(); i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl;
    
}

int main()
{
    const vector<int> *v;
    v = pentagonal_seq(10);
    display(*v, "t");
    return 0;
}