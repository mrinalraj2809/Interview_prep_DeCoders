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
