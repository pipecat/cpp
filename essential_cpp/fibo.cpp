#include <iostream>
using namespace std;

bool fibo(int, int &);

int main() 
{
    while(1)
    {    
        int pos, elem;
        cout << "Input position: ";
        cin >> pos ;
        if (fibo(pos, elem))
        {
            cout << "Fibo value of position " << pos << ": " << elem << endl;
        }
        
}
}

bool fibo(int pos, int &elem) 
{
    int x1, x2, i;
    elem = 0;
    if (pos < 0 || pos >1024) 
    {
        elem = 0;
        return false;
    }
    if (pos == 1 || pos == 2)
    {
        elem = 1;
        return true;
    }
    x1 = 1;
    x2 = 1;
    i = 3;
    while (i <= pos)
    {
        elem = x1 + x2;
        x1 = x2;
        x2 = elem;
        i++;
    }
    return true;
}