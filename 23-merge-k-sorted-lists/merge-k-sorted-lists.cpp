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
 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        //min heap
        priority_queue<int,vector<int>,greater<int>> pq;
       
        for(int i=0; i<n; i++){
            // push in min heap
           ListNode*temp=lists[i];
           while(temp){
            pq.push(temp->val);
            temp=temp->next;
           }
        }
        if(pq.size()==0) return NULL;
       
       ListNode*head=new ListNode(pq.top());
       ListNode*temp=head;
       pq.pop();
       while(pq.size()>0){
         ListNode*temp1=new ListNode(pq.top());
         temp->next=temp1;
         temp=temp1;
        pq.pop();
       }
       return head;

    }
};