//Efficient using Recursion TC O(n) and SC O(n) [Call Stack]

int getSize(ListNode* head){
    int res = 0;
    while(head){
        head = head->next;
        res++;
    }
    return res;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || !head->next || getSize(head) < k){
        return head;
    }
    ListNode* root = head;
    ListNode* prev = NULL;
    int num = k;
    while(root && num--){
        ListNode* next = root->next;
        root->next = prev;   
        prev = root;
        root = next;
    }
    ListNode* rest = reverseKGroup(root, k);
    head->next = rest;
    return prev;
}

//Alternate using iteration TC  O(N) and SC O(1)
int getSize(ListNode* head){
    int res = 0;
    while(head){
        head = head->next;
        res++;
    }
    return res;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL||head->next == NULL) return head;
    
    int len = getSize(head);
    
    ListNode* temp = new ListNode(0);
    temp->next = head;
    
    ListNode* pre = temp;
    ListNode* cur;
    ListNode* nex;
    
    while(len >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        len -= k;
    }
    return temp->next;
}  


//Also stack can used

//https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/
//https://www.codingninjas.com/codestudio/problems/763406?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
//https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/