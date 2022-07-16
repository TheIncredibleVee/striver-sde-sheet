//Using hashing TC O(n) SC O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> mp;
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        if(mp.find(target - nums[i]) != mp.end()){
            return vector<int>({i, mp[target - nums[i]]});
        }
        mp[nums[i]] = i;
    }
    return res;
}

//https://leetcode.com/problems/two-sum/submissions/
//https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/
