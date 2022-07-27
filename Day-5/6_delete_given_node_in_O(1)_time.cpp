//Efficient by copying the next node's val to current node and then deleting the next node
//TC O(1) SC O(1)

void deleteNode(ListNode* node) {
    ListNode* next = node->next; 
    if(!next){
        delete(node);
        return;
    }
    node->val = next->val;
    node->next = next->next;
    delete(next);
    return;
}

//https://leetcode.com/problems/delete-node-in-a-linked-list/
//https://takeuforward.org/data-structure/delete-given-node-in-a-linked-list-o1-approach/