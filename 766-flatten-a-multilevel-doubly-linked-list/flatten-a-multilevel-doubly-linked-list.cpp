/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return NULL;
        Node* curr = head;
        while(curr){
            if(curr->child == NULL){
                curr = curr->next;
            }
            else{
                Node* nextNode = curr->next;
                Node* childHead = flatten(curr->child);
                curr->next = childHead;
                childHead ->prev = curr;
                curr->child = NULL;
                Node* temp = childHead;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = nextNode;
                if(nextNode) nextNode->prev = temp;
                curr = nextNode;
            }
        }
        return head;
    }
};