#include <iostream>
#include <functional>
#include <vector>
#include <iterator>
using namespace std;

template <typename InputIterator, typename OutputIterator, typename Elemtype, typename Comp>
OutputIterator filter(InputIterator begin, InputIterator end, OutputIterator at, const Elemtype &value, Comp pred)
{
    while ((begin = 
                find_if(begin, end, 
                            bind2nd(pred, value))) != end)
    {
        std::cout << "found value: " << *begin << std::endl;
        *at++ = *begin++;
    }
    return at;
}

// template <typename InputIterator, typename OutputIterator, typename Elemtype, typename Comp>
// OutputIterator sub_vec(InputIterator begin, OutputIterator end, OutputIterator at, const Elemtype &value, Comp pred)
// {
//     vector<Elemtype>::iterator out, i;
//     i = begin;
//     out = at;
//     while (i != end)    
//     {
//         *out++ = *i++;
//     }
//     sort(at, out);
//     if (begin = 
//                 find_if(at, out, 
//                             bind2nd(pred, value)) != end)
//     {
        
//     }
    
    
//     return 0;
// }


int main()
{
    const int elem_size = 8;
    int ia[elem_size] = {12, 34, 5, 7, 21, 95, 52, 33};
    vector<int> vec(ia, ia+8);

    int ia2[elem_size];
    vector<int> out;
    vector<int>::iterator result;

    cout << "Filtering element less than 10" << endl;

    filter(ia, ia+elem_size, ia2, 10, less<int>());

    cout << "Filtering element greater than 20" << endl;

    filter(vec.begin(), vec.end(), back_inserter(out), 20, greater<int>());

    cout << "Elems in out - 「" << out.size() << "」 " << endl;

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }
    
    
    return 0;
}