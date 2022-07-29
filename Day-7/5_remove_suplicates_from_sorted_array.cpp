//Efficient using two pointers 1 for traversing and other for res TC O(n) and SC O(1)

int removeDuplicates(vector<int>& nums) {
    int finalIdx = 1;
    int n = nums.size();
    for(int i = 1; i < n; ++i){
        if(nums[i] != nums[i  - 1]){
            nums[finalIdx] = nums[i];
            finalIdx++;
        }
    }
    return finalIdx;
}

//Brute Force using set TC O(n) and SC O(n)

int removeDuplicates(int arr[]) {
    set<int> set;
    for (int i = 0; i < 7; i++) {
        set.insert(arr[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x: set) {
        arr[j++] = x;
    }
    return k;
}


//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/