//Efficient TC O(nlogn) & SC O(n) Using merge sort
int rec(vector<int>& arr, int start, int end){
    if(start >= end){
        return 0;
    }
    int mid = start + ( (end - start) / 2);
    int res = rec(arr, start, mid) + rec(arr, mid + 1, end);
    vector<int> merge(end - start + 1);
    int i = start;
    int j = mid + 1;
    int k = 0;
    int idx = j;
    while(i <=  mid){
        while(idx <= end && arr[i] > 2L * arr[idx]){
            ++idx;
        }
        res += idx - (mid + 1);
        while(j <= end &&  arr[i] > arr[j]){
            merge[k++] = arr[j++];
        }
        merge[k++] = arr[i++];
    }
    while(j <= end){
        merge[k++] = arr[j++];
    }
    for(int i = 0; i < end - start + 1; ++i){
        arr[start + i] = merge[i];
    }
    return res;
}
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    return rec(nums, 0, n - 1);
}

//Alternate using BIT
int getSum(int *bit, int idx) {
    int s = 0;
    for(; idx; idx -= idx & -idx) s += bit[idx];
    return s;
}
void update(int *bit, int n, int idx, int val) {
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}
int reversePairs(vector<int>& nums) {
    if (!nums.size()) return 0;
    int n = nums.size(), inversions = 0;
    int temp[n];
    for (int i=0; i<n; i++) temp[i] = nums[i];
    sort(temp, temp+n);
    int bit[n+1] = {0};
    for (int i=0; i<n; i++) {
        int index = upper_bound(temp, temp+n, 2L * nums[i]) - temp;
        inversions += i - getSum(bit, index);
        index = upper_bound(temp, temp+n, nums[i]) - temp;
        update(bit, n, index, 1);
    }
    return inversions;
}

//Alternate Using Augmented-BST TC O(n^2)
class Node {
    int val, cnt;
    Node left, right;
        
    Node(int val) {
        this.val = val;
        this.cnt = 1;
    }
}
private int search(Node root, long val) {
    if (root == null) {
    	return 0;
    } else if (val == root.val) {
    	return root.cnt;
    } else if (val < root.val) {
    	return root.cnt + search(root.left, val);
    } else {
    	return search(root.right, val);
    }
}

private Node insert(Node root, int val) {
    if (root == null) {
        root = new Node(val);
    } else if (val == root.val) {
        root.cnt++;
    } else if (val < root.val) {
        root.left = insert(root.left, val);
    } else {
        root.cnt++;
        root.right = insert(root.right, val);
    }
    
    return root;
}

//https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22
//https://takeuforward.org/data-structure/count-reverse-pairs/
//https://leetcode.com/problems/reverse-pairs/
