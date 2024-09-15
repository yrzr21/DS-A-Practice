#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *f = head, *s = head;
        // a:非环长度，b:相遇点距离入口的长度，c:剩余环长
        // 快慢指针相遇时，慢指针一定未走过一圈
        // a + n(b+c) + b = 2(a + b) => a = (n-1)(b+c) + c
        // 慢指针和一个等速指针一起运动一段距离即可相遇
        while (f != nullptr)
        {
            s = s->next;
            f = f->next;
            if (f == nullptr)
                break;
            f = f->next;
            if (f == nullptr)
                break;

            if (f == s)
            {
                ListNode *p = head;
                while (s != p)
                {
                    p = p->next;
                    s = s->next;
                }
                return p;
            }
        }

        return nullptr;
    }
};

int main()
{
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};