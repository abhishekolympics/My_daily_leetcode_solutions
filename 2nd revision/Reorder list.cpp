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
    // void reorderList(ListNode* head) {

        //brute force
        //CANT USE THIS SOLUTION BECAUSE IT IS WRITTEN IN QUESTION THAT WE CAN'T USE 
        //store all the values of the linkedlist in a vector
        //store reverse of that vector
        //store the values one-by-one from original and reversed vector in linkedlist
        //if odd number of values then store middle value of original vector in linkedlist
        //TC=O(n)
        //SC=O(n) 
        // ListNode* temp=head;
        // vector<int>orig;
        // while(temp!=NULL)
        // {
        //     orig.push_back(temp->val);
        //     temp=temp->next;
        // }
        // vector<int>rev(orig.size());
        // copy(orig.rbegin(),orig.rend(),rev.begin());

        // int n=orig.size()/2,i=0,j=0;
        // while(n>0)
        // {
        //     n--;
        //     head->val=orig[i++];
        //     head=head->next;
        //     head->val=rev[j++];
        //     head=head->next;
        // }
        // if(orig.size()%2!=0)
        //     head->val=orig[i];

        //BRUTE FORCE --recursive
        // I need to find the penultimate element so that I can push the ultimate element
        // in the second position

        // Base case if there are only three elements
        // if(!head || !head->next || !head->next->next) 
        //     return;

        // ListNode* penultimate=head;
        
        // //find penultimate node
        // while(penultimate->next->next)
        //     penultimate=penultimate->next;
        
        // //allocate the ultimate to second node
        // penultimate->next->next=head->next;
        // head->next=penultimate->next;

        // penultimate->next=NULL;

        // reorderList(head->next->next);

        //BRUTE FORCE --Iterative
        
        // if(!head || !head->next || !head->next->next)
        //     return;

        // ListNode* penultimate;
        // while(head && head->next && head->next->next)
        // {
        //     penultimate=head;
        //     while(penultimate->next->next)
        //         penultimate=penultimate->next;
            
        //     penultimate->next->next=head->next;
        //     head->next=penultimate->next;

        //     penultimate->next=NULL;
        //     head=head->next->next;
        // }
        
        //optimized approach
        //we can reverse the linkedlist from mid node to last node
        
    // }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=NULL;
        
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        //step 1 - using slow and fast pointer approach to find the mid of the list
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //step 2 - reverse the second half and split the List into two.
        ListNode* second=reverse(slow->next); // independent list second
        slow->next=NULL;
        ListNode* first=head; // independent list first
        
        //step 3 - merging the two list
        // second list can be shorter when LL size is odd
        while(second)
        {
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};