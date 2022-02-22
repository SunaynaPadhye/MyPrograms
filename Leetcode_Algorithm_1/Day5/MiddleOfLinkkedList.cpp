/*
Problem: https://leetcode.com/problems/middle-of-the-linked-list/

876. Middle of the Linked List
Easy

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:

    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100

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
    ListNode* middleNode(ListNode* head) {
        int n = 1, mid, i;                     
        ListNode *temp = head;                      //a temp node pointer which initially points to head node
        
        while(temp -> next != NULL){                //counting n = total no. of nodes present
            n++;
            temp = temp -> next;
        }
        
        mid = (n/2) + 1;                            //According to definition of middle node (for both even or odd n)
        temp = head;                                //temp again pointing to the head node
        
        for(i = 1; i < mid; i++){                   //traversing linked list till mid node
            temp = temp-> next;
        }
        return temp;                                //returns pointer to the mid node
    }
};

/*
if n is odd:
n = 7 (say), middle node will be 4 i.e. (7/2)+1
if n is even:
n = 8 (say), middle node will be 5 (second of the two middle nodes 4 & 5) i.e. (8/2)+1

Therefore, mid is calculated as mid = (n/2) + 1; always.
*/