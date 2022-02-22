/*
Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

19. Remove Nth Node From End of List
Medium

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head;                     
        ListNode *second = head;                        
        int i, j;
        
        for(i = 0; i < n; i++){                         //second pointer runs n nodes ahead of first
            second = second -> next;
        }
        
        if (!second)                                    //if second pointer is null, remove first node
            return head -> next;
        
        while(second -> next != NULL){                  //both pointer move ahead together with a diffference of n nodes between them
            first = first -> next;
            second = second -> next;
        }
        
        first -> next = first -> next -> next;          //next pointer of (n-1)th node should point to (n+1)th node, thus removing nth node
      
        return head;
    }
};

/*
This is a one-pass solution.
*/