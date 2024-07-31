#include <iostream>
#include <vector>
#include <span>
#include <string>
#include "container_cout.h"

using std::vector;
using std::cout;
using std::endl;

vector<int> lastDigits1(const vector<int>& v)
{
    int sz = v.size();
    vector<int> res (sz, 0);
    for (int i = 0; i < sz; i++)
        res[i] = v[i] % 10;
    
    return res;
}


void lastDigits2(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++) 
        v[i] %= 10;
}

void lastDigits3(vector<int>* pv)
{
    for (int i = 0; i < pv->size(); i++) 
       pv->at(i) %= 10;
}

void lastDigits4(std::span<int> sp)
{
    for (int i = 0; i < sp.size(); i++)
        sp[i] %= 10;
}


int main()
{
    vector<int> v1 = {132, 12, 56, 0, 567};
    cout << lastDigits1(v1) << endl;

    vector<int> v2 = {132, 12, 56, 0, 567};
    lastDigits2(v2);
    cout << v2 << endl;

    vector<int> v3 = {132, 12, 56, 0, 567};
    vector<int>* pv3 = &v3;
    lastDigits3(pv3);
    cout << v3 << endl;

    vector<int> v4 = {132, 12, 56, 0, 567};
    lastDigits4(v4);
    cout << v4 << endl;

    return 0;
}
