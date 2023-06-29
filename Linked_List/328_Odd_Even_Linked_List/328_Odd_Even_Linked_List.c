/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;

Node* oddEvenList(Node* head){
    if(!head||!(head->next)||(!head->next->next)){
        return head;
    }
    Node* odd, *even, *temp; //even node start point
    odd = head;
    even = odd->next;
    temp = even; 
    
    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = temp;
    return head;
}