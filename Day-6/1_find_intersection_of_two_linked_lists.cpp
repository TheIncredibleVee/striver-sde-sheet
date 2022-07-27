//Efficient using distance difference between the two lists TC O(max(n,m))  SC O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    int ctr = 0;
    while(temp1 != temp2){
        if(!temp1 || !temp2){
            ctr++;
        }
        if(ctr > 4){
            return NULL;
        }
        temp1 = temp1? temp1->next: headB;
        temp2 = temp2 ? temp2->next : headA;
    }
    return temp1;
}


//Less Efficient using distance difference between the two lists but calc. size and moving larger list fwd TC O(max(n,m)) and SC O(1)


int getSize(ListNode* node){
    ListNode* curr = node;
    int res = 0;
    while(curr){
        res++;
        curr= curr->next;
    }
    return res;
}

ListNode * findIntersectionRec(ListNode *headA, ListNode *headB, int n, int m){
    if(n > m){
        return findIntersectionRec(headB, headA, m, n);
    }
    while(m > n){
        headB = headB->next;
        m--;
    }
    while(headA!=headB){
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int n = getSize(headA);
    int m = getSize(headB);
    return findIntersectionRec(headA, headB, n, m);
}

//https://leetcode.com/problems/intersection-of-two-linked-lists/
//https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
