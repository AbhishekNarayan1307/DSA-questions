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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for(int i : arr){
            ListNode* random = new ListNode(i);
            curr->next = random;
            curr=curr->next;
        }
        ListNode* head_ = dummy->next;
        delete dummy;
        return head_;
    }
};