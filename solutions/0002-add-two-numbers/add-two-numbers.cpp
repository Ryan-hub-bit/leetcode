// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
//
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummyHead = new ListNode(0);
        ListNode * p = l1, * q = l2;
        ListNode * cur = dummyHead;
        int carry = 0;
        while(p != NULL || q != NULL || carry != 0){
            int x = (p == NULL) ? 0 : (p -> val);
            int y = (q == NULL) ? 0 : (q -> val);
            int sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode * n = new ListNode(sum);
            cur -> next = n;
            cur = cur -> next;
            if(p != NULL) p = p -> next;
            if(q != NULL) q = q -> next;
        }
        return dummyHead -> next;
    }
};
