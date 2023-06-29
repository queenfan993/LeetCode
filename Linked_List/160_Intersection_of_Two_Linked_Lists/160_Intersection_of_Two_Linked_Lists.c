/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode *iterA = headA, *iterB = headB;
    while (iterA || iterB) 
    {
        //there is an intersection
        if (iterA == iterB)
            return iterA;
        
        //iterate while not null, if null start from other head
        iterA = iterA ? iterA->next : headB;
        iterB = iterB ? iterB->next : headA;
    }
    
    return iterA;
}