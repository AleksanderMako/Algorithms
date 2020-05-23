#include<iostream>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         if(!head)return NULL;
        auto fake = new ListNode(-1);
        fake->next=head;
        ListNode* slow=fake;
        ListNode*fast=fake;
        int steps =n;

        for (int i=0 ; i < n;i++)fast=fast->next;
        while(fast->next)
        {
            fast=fast->next;
            slow =slow->next;
        }
        slow->next = slow->next->next;
        return fake->next;
    }
};
void printL(ListNode* l)
{
    while(l)
    {
        cout<< l->val <<"->";
        l=l->next;
    }
}

int main()
{
    //1->2->3->4->5
    auto n5=new ListNode(5);
    auto n4=new ListNode(4,n5);
    auto n3=new ListNode(3,n4);
    auto n2= new ListNode(2,n3);
    auto head = new ListNode(1,n2);
    Solution s ;

    s.removeNthFromEnd(head,2);
    printL(head);
    
    
}
