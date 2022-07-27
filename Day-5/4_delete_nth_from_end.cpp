//Efficient using two pointers one to move n from start and one at staring TC O(n) SC O(1)

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(n--){
        fast = fast->next;
    }
    if(!fast){
        ListNode* temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* temp = slow->next;
    slow->next = slow->next ? slow->next->next : NULL;
    delete(temp);
    return head;
}

//https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
//https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/
