#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void move(vector<int> &A, vector<int> &B, vector<int> &C, int n)
    {
        // A：原柱子，B：中间柱子，C：目标柱子
        if (n == 1)
        {
            C.push_back(A.back());
            A.pop_back();
        }
        else
        {
            move(A, C, B, n - 1);
            move(A, B, C, 1);
            move(B, A, C, n - 1);
        }
    }

    void hanota(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        move(A, B, C, A.size());
    }
};

int main()
{
    vector<int> A, B, C;
    A.push_back(1);
    A.push_back(0);
    Solution sol;
    cout << "call hanoto:\n";
    sol.hanota(A, B, C);
    cout << "return hanoto:\n";
    for (int i : C)
        cout << i << " ";
}