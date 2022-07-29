//Efficient using fast and slow pointers TC O(n) and SC O(1)

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    if(!head || !head->next){
        return NULL;
    }
    do{
        fast = fast->next->next;
        slow = slow->next;
    }while(fast && fast->next && slow != fast);
    if(slow != fast){
        return NULL;
    }
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

//https://leetcode.com/problems/linked-list-cycle-ii/
//https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
