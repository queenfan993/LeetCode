/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node; 
Node* reverse(Node* start, Node* end, int length){
    Node* pre= NULL, *nex = NULL;
    if(end->next){
        pre = end->next;
    }
    else pre = NULL;

    for(int i=0; i<length; i++){   
        if(start->next){
            nex = start->next;
            start->next = pre;
            pre = start;
            start = nex;
        }
        else{
            start->next = pre;
            pre = start;
        }
    }
    return pre;
}
Node* reverseBetween(Node* head, int left, int right){
    Node* L = head;
    Node* R = NULL;
    for(int i = 0; i<left-1;i++){
        L = L->next;
    }
    R = L;
    for(int i =0; i<(right-left);i++){
        R = R->next;
    }
    if(left == right){  
        return head;
    }
    else if(left == 1){  
        return reverse(L, R, (right-left+1));
    }
    else{
        Node* temp = head;
        for(int i = 0; i<left-2;i++){
            temp = temp->next;
        }
        temp->next = reverse(L, R, (right-left+1));
    }
    return head;
    
}