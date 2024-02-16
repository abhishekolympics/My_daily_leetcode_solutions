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
    ListNode* mergeTwoList(auto l1, auto l2)
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val <l2->val)
        {
            l1->next=mergeTwoList(l1->next,l2);
            return l1;
        }
        l2->next = mergeTwoList(l1,l2->next);
        return l2;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        {
            return nullptr;
        }
        while(lists.size()>1)
        {
            lists.push_back(mergeTwoList(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};