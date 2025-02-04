/*
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode* temp = head, *maxNode = head;
        int len = 0;
        bool change = true;
        while (temp) {
            ++len;
            if (temp->val > maxNode->val)
                maxNode = temp;
            temp = temp->next;
        }
        ListNode* extraNode = new ListNode(maxNode->val);
        extraNode->next = head;
        head = extraNode;
        ListNode* insertNode = head, *prevNode = head;
        ++len;
        for (int i=1; i<len; ++i) {
            insertNode = head;
            for (int j=0; j<i; ++j) {
                if (j == i-1)
                    prevNode = insertNode;
                insertNode = insertNode->next;
            }
            ListNode* checkNode = head, *prev = nullptr;
            for (int j=0; j<i; ++j) {
                if (checkNode->val > insertNode->val) {
                    prevNode->next = insertNode->next;
                    insertNode->next = checkNode;
                    if (prev)
                        prev->next = insertNode;
                    else
                        head = insertNode;
                    break;
                }
                prev = checkNode;
                checkNode = checkNode->next;
            }
        }
        temp = head;
        while (temp->next->next)
            temp = temp->next;
        temp->next = nullptr;
        return head;
    }
};

