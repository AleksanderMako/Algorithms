#include<iostream>

using namespace std;
  struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode* mergeSortLL(ListNode*head)
  {
      if (!head)return head;
      ListNode* temp;
      ListNode*slow=head;
      ListNode*fast=head->next->next;

      while (fast && fast->next)
      {
          temp=slow;
          slow=slow->next;
          fast=fast->next->next;
      }
      temp->next=NULL;
      auto l = mergeSortLL(head);
      auto r =mergeSortLL(slow);
      return sortLinkedList(l,r);
      
  }

  ListNode* sortLinkedList(ListNode* headA,ListNode* headB)
  {
      if (!headA)return headB;
      if (!headB)return headA;

      ListNode* head;
      ListNode* tail;

      if (headA->val <=headB->val)
      {
          head=headA;
          tail=headA;
          headA=headA->next;
      }else 
      {
          head=headB;
          tail=headB;
          headB=headB->next;
      }
      

     while (headA && headB)
     {
         if(headA->val <=headB->val)
         {
             tail->next =headA;
             headA=headA->next;
         }else
         {
             tail->next=headB;
             headB=headB->next;
         }
         
     }
     if(headB)tail->next=headB;
     if(headA)tail->next=headA;
     return head;
           
  }

  int main()
  {

  }
