//Efficient using temp pointers TC O(n + m) and SC O(1)

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(!list1){
        return list2;
    }
    if(!list2){
        return list1;
    }
    ListNode* res = NULL;
    ListNode* head = NULL; 
    while(list1 && list2){
        if(list1->val < list2->val){
            if(!res){
                head = list1;
                res = list1;
            }else{
                res->next = list1;
                res = res->next;
            }
            list1 = list1->next;
        }else{
            if(!res){
                res = list2;
                head = list2;
            }else{
                res->next = list2;
                res = res->next;
            }
            list2 = list2->next;
        }
    }
    if(list1){
        res->next = list1;
    }
    if(list2){
        res->next = list2;
    }
    return head;
}

//Alternate modifying links in smaller list TC O(n) and SC O(1)

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1->val > list2->val){
        swap(list1, list2);
    }
    ListNode* head = list1;
    while(list1->next && list2){
        if(list1->next->val > list2->val){
            ListNode* temp = list1->next;
            list1->next = list2;
            list2 = list2->next;
            list1->next->next = temp;
        }
        list1 = list1->next;
    }
    if(list2){
        list1->next = list2;
    }
    return head;
}

//https://leetcode.com/problems/merge-two-sorted-lists/submissions/
//https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/
