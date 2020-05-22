/******************** Add Two Numbers ************************************
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

**********************************************************************/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        ListNode* l3; ListNode* temp;int carry=0;
        ListNode* l4;int flag =0;
        while(l1 != NULL && l2 != NULL)
        {
            temp = new ListNode((carry + (l1->val + l2->val))%10) ;
            carry = (carry  + l1->val + l2->val)/10;
            temp->next =NULL;
            if(flag ==0){flag =1;l3 = temp;l4 = l3;}
            else l3 -> next = temp;
            l3 = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL)
        {
            temp = new ListNode((carry + l1->val)%10 ) ;
            carry =(carry + l1->val)/10;
            //carry = 0;
            temp->next =NULL;
            if(flag ==0){flag =1;l3 = temp;l4 = l3;}
            else l3 -> next = temp;
            l3 = temp;
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            temp= new ListNode(( carry + l2->val )%10) ;
            carry = (carry + l2->val)/10;
            //carry = 0;
            temp->next =NULL;
            if(flag ==0){flag =1;l3 = temp;l4 = l3;}
            else l3 -> next = temp;
            l3 = temp;
            l2 = l2->next;
        }
        if(l1 == NULL && l2 == NULL && carry !=0)
        {
            temp = new ListNode(carry);
            l3->next = temp;
            l3 = temp;
            carry =0;
        }
        return l4;
    }
};