//Efficient using reversing after middle elements and then comparing each elem RC O(n) and SC O(1)

ListNode* reverse(ListNode* head, ListNode* prev){
    if(!head || !head->next){
        return head;
    }
    ListNode* restHead = reverse(head->next, head);
    head->next->next = head;
    head->next = prev;
    return restHead;
}

bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = NULL;
    if(!head || !head->next){
        return true;
    }
    do{
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }while(fast && fast->next);
    if(!fast){
        prev->next = reverse(slow, NULL);
        prev = prev->next;
    }else{
        slow->next = reverse(slow->next,NULL);
        prev = slow->next;
    }
    while(prev){
        if(head->val != prev->val){
            return false;
        }
        prev = prev->next;
        head = head->next;
    }
    return true;
}

//https://leetcode.com/problems/palindrome-linked-list/
//https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/