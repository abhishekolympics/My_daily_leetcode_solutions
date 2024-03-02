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
        int sz=0;
        auto it=head;
        while(it!=NULL)
        {
            it=it->next;
            sz++;
        }
        if(sz==1)
        {
            return NULL;
        }
        else if(sz-n==0)
        {
            auto newHead=head->next;
            return newHead;
        }
        sz=sz-n;
        it=head;
        while(it!=NULL)
        {
            sz--;
            if(sz==0)
            {
                break;
            }
            it=it->next;
        }
        ListNode* temp=it->next;
        it->next=it->next->next;
        delete(temp);
        return head;
    }
//     ListNode* removeNthFromEnd(ListNode* head, int N) {
//     if (head == NULL) {
//         return NULL;
//     }
//     int cnt = 0;
//     ListNode* temp = head;
//     while (temp != NULL) {
//         cnt++;
//         temp = temp->next;
//     }
//     if (cnt == N) {
//         ListNode* newhead = head->next;
//         delete (head);
//         return newhead;
//     }
//     int res = cnt - N;
//     temp = head;
//     while (temp != NULL) {
//         res--;
//         if (res == 0) {
//             break;
//         }
//         temp = temp->next;
//     }
//     ListNode* delNode = temp->next;
//     temp->next = temp->next->next;
//     delete (delNode);
//     return head;
// }
};
