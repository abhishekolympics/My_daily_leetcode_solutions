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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        auto temp=head;
        vector<int>vc;
        while(temp!=NULL)
        {
            vc.push_back(temp->val);
            temp=temp->next;
        }
        int n=vc.size();
        temp=head;
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            temp->val=vc[i];
            temp=temp->next;
            temp->val=vc[j];
            temp=temp->next;
        }

        if (n % 2 != 0)
            temp->val = vc[n / 2];
    }
};
