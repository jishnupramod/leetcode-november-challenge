/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
private:
    string add_strings(string num1, string num2) {
        string ans = "";
        int n1 = num1.length()-1;
        int n2 = num2.length()-1;
        int carry = 0;
        int sum = 0;
        while (n1 >= 0 and n2 >= 0) {
            sum = num1[n1]-'0' + num2[n2]-'0' + carry;
            ans += to_string(sum%10);
            carry = sum/10;
            --n1;
            --n2;
        }
        while (n1 >= 0) {
            sum = num1[n1]-'0' + carry;
            ans += to_string(sum%10);
            carry = sum/10;
            --n1;
        }
        while (n2 >= 0) {
            sum = num2[n2]-'0' + carry;
            ans += to_string(sum%10);
            carry = sum/10;
            --n2;
        }
        if (carry > 0) {
            ans += to_string(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = l1;
        string num1 = "", num2 = "";
        while (temp) {
            num1 += to_string(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while (temp) {
            num2 += to_string(temp->val);
            temp = temp->next;
        }
        string num = add_strings(num1, num2);
        ListNode* l3 = new ListNode(num[0]-'0');
        ListNode* head = l3;
        for (int i=1; i<num.length(); ++i) {
            l3->next = new ListNode(num[i]-'0');
            l3 = l3->next;
        }
        l3->next = nullptr;
        return head;
    }
};
