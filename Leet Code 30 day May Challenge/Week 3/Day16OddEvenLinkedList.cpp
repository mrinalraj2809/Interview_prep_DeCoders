/**********************************************
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
**********************************************/


/*********** Solution cpp *************/
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
//Approach 1: Runtime 12ms
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        if(head == NULL)return NULL;
        if(head->next == NULL || head->next->next ==NULL)return head;
        
        ListNode *temp2 = head->next->next;
        ListNode *oddTemp = new ListNode(head->val);
        ListNode *temp1 = oddTemp;
        ListNode *evenTemp = new ListNode(head->next->val) ;
        ListNode *temp3 = evenTemp;
        while(temp2!=NULL)
        {
            oddTemp->next = new ListNode(temp2->val);
            oddTemp = oddTemp->next;
            if(temp2->next == NULL)break;
            temp2 = temp2->next->next;
        }
        if(head->next->next->next != NULL)
            temp2 = head->next->next->next;
        else {
            oddTemp->next = temp3;
            return temp1;
        }
        while(temp2!=NULL)
        {
            evenTemp->next = new ListNode(temp2->val);
            evenTemp = evenTemp->next;
            if(temp2->next== NULL)break;
            temp2 = temp2->next->next;
        }
        oddTemp->next = temp3;
        return temp1;
    }
};

// Approach 2: Runtime 4ms
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even=new ListNode(0);
        ListNode *odd= new ListNode(0);
        
        ListNode *curr= head;
        
        ListNode *oddcurr=odd;
        ListNode *evencurr=even;
        int i=1;
        
        while(curr!=NULL)
        {
            if(i%2!=0)
            {
                oddcurr->next=curr;
                oddcurr=oddcurr->next;
            }
            else
            {
                evencurr->next=curr;
                evencurr=evencurr->next;
            }
            i++;
            curr=curr->next;
        }
        evencurr->next=NULL;
        oddcurr->next=even->next;
        odd=odd->next;
        return odd;
    }
   
    
};