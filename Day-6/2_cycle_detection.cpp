//Efficient using Floyd Algo TC O(n) and SC O(1)

bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    if(!head || !head->next){
        return false;
    }
    do{
        fast = fast->next->next;
        slow = slow->next;
    }while(slow && fast && fast->next && slow != fast);
    if(fast == slow){
        return true;
    }else{
        return false;
    }
}

//https://leetcode.com/problems/linked-list-cycle/
//https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/