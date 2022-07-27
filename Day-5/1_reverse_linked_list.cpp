//Iterative TC O(n) SC O(1)

ListNode* reverseList(ListNode* head) {
    ListNode* node = head;
    ListNode* prev = NULL; 
    while(node){
        ListNode* temp = node->next;
        node->next = prev;
        prev = node;
        node = temp;
    }
    return prev;
}

//Recursion TC O(n^2) and SC O(n) 

ListNode* reverseList(ListNode* head) {
    if(!head || !head->next){
        return head;
    }
    ListNode* res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}


//Stack based solution TC O(n) SC O(n)

ListNode* reverseList(ListNode* head) {
    if(!head || !head->next){
        return head;
    }
    ListNode* res = NULL;
    stack<ListNode*> st;
    while(head){
        st.push(head);
        head = head->next;
    }
    res = st.top();
    st.pop();
    ListNode* node = res;
    while(!st.empty()){
        node->next = st.top();
        node = node->next;
        st.pop();
    }
    node->next = NULL;
    return res;
}
//https://leetcode.com/problems/reverse-linked-list/submissions/
//https://takeuforward.org/data-structure/reverse-a-linked-list/
