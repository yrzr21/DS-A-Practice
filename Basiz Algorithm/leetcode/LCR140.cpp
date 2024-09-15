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
    // ListNode *trainingPlan(ListNode *head, int cnt)
    // {
    //     int count = 1;
    //     ListNode *c = head;
    //     while (c->next != nullptr)
    //     {
    //         c = c->next;
    //         count++;
    //     }
    //     c = head;
    //     for (int i = 0; i < count - cnt; i++)
    //         c = c->next;

    //     return c;
    // }

    ListNode *trainingPlan(ListNode *head, int cnt)
    { // 快慢指针
        ListNode *f = head, *s = head;
        for (int i = 1; i < cnt; i++)
            f = f->next;

        while (f->next != nullptr)
        {
            f = f->next;
            s = s->next;
        }
        return s;
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