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
    // ListNode *reverseList(ListNode *head)
    // {
    //     if(head == nullptr)
    //         return nullptr;

    //     ListNode *prev = nullptr, *c = head, *next = head->next;
    //     while (next != nullptr)
    //     {
    //         c->next = prev;

    //         prev = c;
    //         c = next;
    //         next = next->next;
    //     }
    //     c->next = prev;

    //     return c;
    // }
    
    ListNode *reverseList(ListNode *head)
    {

        ListNode* hd = nullptr, *next = head;
        while(next != nullptr)
        {
            next = head->next;
            head->next = hd;
            hd = head;
            head = next;
        }

        return hd;
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