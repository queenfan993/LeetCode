/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;
bool hasCycle(Node *head) {
    Node* fast =NULL, *slow = NULL;
    if(head == NULL || head->next == NULL || head->next->next == NULL) { 
        return false;
    }
    else {
        slow = head;
        if(head->next->next) {
            fast = head->next->next;
        }
    }
    while(fast != slow) {
        if(fast->next && fast->next->next) {
                fast = fast->next->next;
        }
        else return false;
        slow = slow->next;
    }
    return true;
}
