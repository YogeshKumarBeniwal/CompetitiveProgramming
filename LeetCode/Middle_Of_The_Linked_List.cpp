// Given the head of a singly linked list,
// return the middle node of the linked list.

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

ListNode *middleNode(ListNode *head)
{
    ListNode* slow = head;

    while(head != NULL && head->next != NULL)
    {
        head = head->next->next;
        slow = slow->next;
    }

    return slow;
}
