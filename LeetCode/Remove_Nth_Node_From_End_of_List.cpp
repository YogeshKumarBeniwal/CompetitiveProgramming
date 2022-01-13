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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = new ListNode(0, head);
    ListNode *first = temp;
    ListNode *nodeToRemove = temp;

    while (first->next != NULL && first != NULL)
    {
        first = first->next;

        if (n-- > 0)
            continue;

        nodeToRemove = nodeToRemove->next;
    }

    if (nodeToRemove == temp)
    {
        head = nodeToRemove->next->next;
    }
    else
    {
        nodeToRemove->next = nodeToRemove->next->next;
    }

    return head;
}

int main()
{
    ListNode *forth = new ListNode(5);
    ListNode *third = new ListNode(4, forth);
    ListNode *second = new ListNode(3, third);
    ListNode *first = new ListNode(2);
    ListNode *head = new ListNode(1, first);

    head = removeNthFromEnd(head, 1);

    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
}
