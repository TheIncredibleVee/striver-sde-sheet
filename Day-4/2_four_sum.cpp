//Efficient TC O(n^3) and space complexity O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    if(n < 4){
        return res;
    }
    int one,two,three,four;
    for(int i = 0; i < n - 3; ++i){
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        one = nums[i];
        for(int j = i + 1; j < n - 2; ++j){
            if(j > i +1 && nums[j] == nums[j - 1]){
                continue;
            }
            two = nums[j];
            three = j + 1;
            four = n - 1;
            while(three < four){
                long long sum = (long long)nums[three] + (long long )nums[four] + (long long)one + (long long)two;
                if(sum == target){
                    vector<int> curr;
                    curr.reserve(4);
                    curr.emplace_back(one);
                    curr.emplace_back(two);
                    curr.emplace_back(nums[three]);
                    curr.emplace_back(nums[four]);
                    res.emplace_back(curr);
                    three++;
                    four--;
                    while(three < four && nums[three] == nums[three - 1]){
                        three++;
                    }
                    while(three < four && nums[four] == nums[four + 1]){
                        four--;
                    }
                }else if(sum > target){
                    four--;
                }else{
                    three++;
                }
            }
        }
    }
    return res;
}

// Alternate using hashmap for KSUM TC O(n^3) and SC O(N)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 4);
}

vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
    vector<vector<int>> res;
    
    // If we have run out of numbers to add, return res.
    if (start == nums.size()) {
        return res;
    }
    
    // There are k remaining values to add to the sum. The 
    // average of these values is at least target / k.
    long long average_value = target / k;
    
    // We cannot obtain a sum of target if the smallest value
    // in nums is greater than target / k or if the largest 
    // value in nums is smaller than target / k.
    if  (nums[start] > average_value || average_value > nums.back()) {
        return res;
    }
        
    if (k == 2) {
        return twoSum(nums, target, start);
    }

    for (int i = start; i < nums.size(); ++i) {
        if (i == start || nums[i - 1] != nums[i]) {
            for (vector<int>& subset : kSum(nums, static_cast<long>(target) - nums[i], i + 1, k - 1)) {
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(subset), end(subset));
            }
        }
    }
                                        
    return res;
}

vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
    vector<vector<int>> res;
    unordered_set<long long> s;

    for (int i = start; i < nums.size(); ++i) {
        if (res.empty() || res.back()[1] != nums[i]) {
            if (s.count(target - nums[i])) {
                res.push_back({int(target - nums[i]), nums[i]});
            }
        }
        s.insert(nums[i]);
    }
                                            
    return res;
}  

//Alternate using just sorting TC O(n^3) and SC O(K)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 4);
}

vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
    vector<vector<int>> res;
    
    // If we have run out of numbers to add, return res.
    if (start == nums.size()) {
        return res;
    }
    
    // There are k remaining values to add to the sum. The 
    // average of these values is at least target / k.
    long long average_value = target / k;
    
    // We cannot obtain a sum of target if the smallest value
    // in nums is greater than target / k or if the largest 
    // value in nums is smaller than target / k.
    if  (nums[start] > average_value || average_value > nums.back()) {
        return res;
    }
        
    if (k == 2) {
        return twoSum(nums, target, start);
    }

    for (int i = start; i < nums.size(); ++i) {
        if (i == start || nums[i - 1] != nums[i]) {
            for (vector<int>& subset : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1)) {
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(subset), end(subset));
            }
        }
    }
                                        
    return res;
}

vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
    vector<vector<int>> res;
    int lo = start, hi = int(nums.size()) - 1;

    while (lo < hi) {
        int curr_sum = nums[lo] + nums[hi];
        if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
            ++lo;
        } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
            --hi;
        } else {
            res.push_back({ nums[lo++], nums[hi--] });
        }
    }
                                                        
    return res;
}


//https://leetcode.com/problems/4sum/
//https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/
//https://leetcode.com/problems/4sum/solution/
