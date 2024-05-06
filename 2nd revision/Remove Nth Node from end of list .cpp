//watch https://www.youtube.com/watch?v=3kMKYQ2wNIU
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
    //BRUTE FORCE
    // first find the length of the LL then traverse to that node's previous node
    // then switch the next pointer values and delete the node
    //TC=O(L)+ O(L+N)
    //SC=O(1)
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if(head==NULL) return NULL;

    //     int size=0;
    //     ListNode* temp=head;
    //     while(temp!=NULL)
    //     {
    //         size++;
    //         temp=temp->next;
    //     }

    //     if(size==n)
    //     {
    //         ListNode* newHead=head->next;
    //         delete (head);
    //         return newHead;
    //     }
        
    //     int res=size-n;
    //     temp=head;

    //     while(temp!=NULL)
    //     {
    //         res--;
    //         if(res==0)
    //         {
    //             break;
    //         }
    //         temp=temp->next;
    //     }

    //     ListNode* delNode=temp->next;
    //     temp->next=temp->next->next;
    //     delete (delNode);
    //     return head;
    // }

    //OPTIMAL APPROACH
    //We are maintaining a window here using fast and slow pointers
    //which finally helps us to locate the penultimate node before the node which needs
    // to be deleted
    // 
    //TC=O(L)
    //SC=O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;

        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }

        if(fast == NULL)
        {
            ListNode* newHead=head->next;
            delete (head);
            return newHead;
        }

        while(fast->next !=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* delNode = slow->next;
        slow->next=slow->next->next;
        delete delNode;
        return head;
    }
};