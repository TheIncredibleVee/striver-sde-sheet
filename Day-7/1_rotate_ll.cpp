//Efficient using changing links TC O(n) and SC O(1)

int getSize(ListNode* head){
    int res = 0;
    while(head){
        head= head->next;
        res++;
    }
    return res;
}
ListNode* rotateRight(ListNode* head, int k) {
    int n = getSize(head);
    if(n <= 0){
        return head;
    }
    k %= n;
    if(k <= 0){
        return head;
    }
    int num = k;
    ListNode* fast = head;
    ListNode* slow = head;
    while(num--){
        fast = fast->next;
    }
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return head;
}

//https://leetcode.com/problems/rotate-list/submissions/
//https://takeuforward.org/data-structure/rotate-a-linked-list/