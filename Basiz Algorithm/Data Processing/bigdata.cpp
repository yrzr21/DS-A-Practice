#include <iostream>
// #include <math.h>
#include <vector>
#include <cstdio>
// #include <cstring>
#include <algorithm>
#include <string>
using namespace std;

void read_data(vector<int> &v)
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        int num = s[i] - '0';
        v.push_back(num);
    }

    cout << "read data: ";
    for (int i : v)
        cout << i;
    cout << endl;
}

// 要求res为空
void add(vector<int> &v1, vector<int> &v2, vector<int> &res)
{
    int c = 0, s = 0, a, b;                   // 进位&本位&加数
    int i = v1.size() - 1, j = v2.size() - 1; // index
    vector<int> res;

    while (1)
    {
        a = i < 0 ? 0 : v1[i];
        b = j < 0 ? 0 : v2[j];
        int product = a + b + c;

        res.push_back(product % 10);
        c = product / 10;

        i--, j--;
        if (i < 0 && j < 0 && c == 0)
            break;
    }
    reverse(res.begin(), res.end());

    cout << "add res = ";
    for (int i : res)
        cout << i;
    cout << endl;
}

// 正大数-正小数
void normal_sub_(vector<int> &v1, vector<int> &v2, vector<int> &res)
{
    // 借位&本位&减数
    int borrow = 0, s = 0, a, b;
    // index
    int i = v1.size() - 1, j = v2.size() - 1;

    // 相减
    while (1)
    {
        a = i < 0 ? 0 : v1[i];
        b = j < 0 ? 0 : v2[j];

        int product = a - b - borrow;
        if (product < 0 && i > 0)
        {
            borrow = 1;
            product = 10 + product;
        }
        else
        {
            borrow = 0;
        }
        res.push_back(product);

        i--, j--;
        if (i < 0 && j < 0 && borrow == 0)
            break;
    }
    reverse(res.begin(), res.end());

    // 去除前导0
    auto iter = res.begin();
    for (; iter != res.end() && *iter == 0; ++iter)
        ;
    res.erase(res.begin(), iter);
    if (res.size() == 0)
        res.push_back(0);
}

// 被调用的减法
// todo:增加负数减法
void sub(vector<int> &v1, vector<int> &v2, vector<int> &res)
{
    int borrow = 0, s = 0, a, b; // 借位&本位&减数

    // 变为大数减小数
    bool isNegative = false;
    if (v2.size() > v1.size())
    {
        isNegative = true;
        v1.swap(v2);
    }
    else if (v1.size() == v2.size())
    {
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] > v2[i])
                break;
            else if (v1[i] < v2[i])
            {
                isNegative = true;
                v1.swap(v2);
            }
        }
    }

    normal_sub_(v1, v2, res);

    if (isNegative)
        res[0] = -res[0];

    cout << "sub res = ";
    for (int i : res)
        cout << i;
    cout << endl;
}

// 未完成
void mul(vector<int> &v1, vector<int> &v2, vector<int> &res)
{
    vector<int> res{0};

    for (int i = 0; i < v2.size(); i++)
    {
        vector<int> tmp, tmp1{0};
        int c = 0, j = v1.size() - 1;
        while (1)
        {
            int product = v1[j] * v2[i] + c;
            c = product / 10;
            tmp.push_back(product % 10);
            j--;
            if (c == 0 && j < 0)
                break;
        }
        reverse(tmp.begin(), tmp.end());

        // 乘10
        for (int j = 0; j < i; j++)
            res.push_back(0);
    }

    cout << "mul res = ";
    for (int i : res)
        cout << i;
    cout << endl;
}

int main()
{
    vector<int> res;

    vector<int> n1;
    read_data(n1);

    vector<int> n2;
    read_data(n2);

    add(n1, n2, res);
    res.clear();
    sub(n1, n2, res);
    res.clear();
    // mul(n1, n2, res);
    res.clear();
}