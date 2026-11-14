class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> st;
        ListNode* temp = head;

        while(temp) {
            st.push(temp);
            temp = temp->next;
        }

        while(n-- > 1) {
            st.pop();
        }

        ListNode* del = st.top();
        st.pop();

        if(st.empty()) {
            head = head->next;
            delete del;
            return head;
        }

        ListNode* prev = st.top();
        prev->next = del->next;
        delete del;

        return head;
    }
};