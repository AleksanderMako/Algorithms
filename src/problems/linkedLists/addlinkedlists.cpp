

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

#include<iostream>
#include<stack>
using namespace std;
  struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*>s1;
        stack<ListNode*>s2;
        stack<ListNode*>result;

        auto it = l1; 

        while(it){
            s1.push(it);
            it = it->next;
        }
        it = l2;
        while (it)
        {
            s2.push(it);
            it = it->next;
        }

        int carry =0 ; 
        int digit = 0; 
        while(true)
        {
            auto t1 = !s1.empty() ? s1.top()->val:0;
            if (!s1.empty())s1.pop();

            auto t2 = !s2.empty() ? s2.top()->val:0;
            if (!s2.empty())s2.pop();


            digit = (t1+t2 + carry)%10;
            carry=(t1+t2+carry)/10;
            result.push( new ListNode(digit));

            if (s1.empty() && s2.empty())break;
        }
        if (carry !=0 )result.push(new ListNode(carry));
        auto head = result.top(); result.pop();
        it = head;
        while(!result.empty())
        {
            it->next = result.top();result.pop();
            it = it->next;
        }
        return head;
        
    }
};