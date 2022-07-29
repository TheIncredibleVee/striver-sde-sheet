//Efficient using Sorting and three pointers TC O(n^2) TC O(1)

vector<vector<int>> threeSum(vector<int>& nums) {
    int target = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for(int i = 0; i < n - 2; ++i){
        if(i> 0 && nums[i] == nums[i - 1]){
            continue;
        }
        int left = i + 1;
        int right = n - 1;
        while(left < right){
            long long sum = nums[i] + nums[left] + nums[right];
            if(sum == target){
                res.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                left++;
                right--;
                while(left < right && nums[left] == nums[left - 1]) left++;
                while(left < right && nums[right] == nums[right + 1]) right--;
            }else if(sum > target){
                right--;
            }else {
                left++;
            }
        }
    }
    return res;
}

//Generic code for K sum

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nsum(nums, 3, 0);
}
vector<vector<int>> nsum(const vector<int> & nums, int  n, int T){
    vector<vector<int>> res;
    if(n == 2){
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int tmp = nums[i] + nums[j];
            if(tmp == T){
                res.push_back(vector<int>({nums[i], nums[j]}));
                i++;
                j--;
                while(i < j && nums[i] == nums[i-1])
                    i++;
                while(i < j && nums[j] == nums[j+1])
                    j--;
            }else if(tmp < T)
                i++;
            else
                j--;
        }
        return res;
    }
    else{
        for(int i = 0; i < (int)nums.size()-n+1; i++){
            if (i && nums[i] == nums[i-1])
                continue;
            auto nm1_res = nsum(vector<int>(nums.begin()+i+1, nums.end()), n-1, T- nums[i]);
            for(auto x:nm1_res){
                x.push_back(nums[i]);
                res.push_back(x);
            }
        }
        return res;
    }
}

//https://leetcode.com/problems/3sum/
//https://leetcode.com/problems/3sum/discuss/7725/My-solution-for-kSums.-88ms-for-3sum.
//https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/