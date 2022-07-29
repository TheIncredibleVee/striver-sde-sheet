//Efficient TC O(n) and SC O(1)

int findMaxConsecutiveOnes(vector<int>& nums) {
    int res =0;
    for(int i=0;i<nums.size();++i){
        int curr =0;
        while(i< nums.size() && nums[i]==1){
            i++;
            curr++;
        }
        res= max(res, curr);
    }
    return res;
}

//https://leetcode.com/problems/max-consecutive-ones/
//https://takeuforward.org/data-structure/count-maximum-consecutive-ones-in-the-array/