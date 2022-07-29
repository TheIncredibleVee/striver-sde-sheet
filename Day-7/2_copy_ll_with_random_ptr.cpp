//Efficient by making new nodes between the list TC O(n) and SC O(n)

Node* copyRandomList(Node* head) {
    if(!head){
        return NULL;
    }
    // if(!head->next){
    //     Node* copy = new Node(head->val);
    //     copy->random = head->random;
    //     return copy;
    // }
    Node* curr = head;
    while(curr){
        Node* nxt = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = nxt;
        curr = nxt;
    }
    curr = head;
    while(curr){
        curr->next->random = curr->random ? curr->random->next : NULL;
        curr = curr->next->next;
    }
    Node* resHead = NULL;
    Node* res = NULL;
    curr = head;
    while(curr){
        Node* nxt = curr->next->next;
        if(!res){
            res = curr->next;
            resHead = curr->next;
        }else{
            res->next = curr->next;
            res = res->next;
        }
        curr->next = nxt;
        curr = nxt;
    }
    curr = head;
    res->next = NULL;
    return resHead;
}



//https://leetcode.com/problems/copy-list-with-random-pointer/
//https://www.youtube.com/watch?v=VNf6VynfpdM
