//Efficient by the use of PriorityQueue 


class cmp{
	public:
		int operator()(const pair<int, Node*> a, const pair<int, Node*> b){
			return a.first > b.first;
		}
};

Node *flatten(Node *head)
{
    if(!head){
		return NULL;
	}
	priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, cmp> pq;
	Node * curr = head;
	Node * resHead = NULL;
	while(curr){
		pq.push({curr->data, curr});
		curr = curr->next;
	}
	auto first = pq.top().second;
	resHead = first;
	if(first->bottom){
		pq.push({first->bottom->data, first->bottom});
	}
	pq.pop();
	Node * res = resHead;
	while(!pq.empty()){
		auto next = pq.top().second;
// 		cout<<pq.top().first<<endl;
		pq.pop();
		if(next->bottom){
			pq.push({next->bottom->data, next->bottom});
		}
		res->bottom = next;
		res = res->bottom;
	}
	
	return resHead;
}


//Alternate Using merging
Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}

//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
//https://takeuforward.org/data-structure/flattening-a-linked-list/