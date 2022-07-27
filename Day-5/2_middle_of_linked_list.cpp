// Efficient using fast and slow pointers TC O(n) and SC O(1)

ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//https://leetcode.com/problems/middle-of-the-linked-list/
//https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
