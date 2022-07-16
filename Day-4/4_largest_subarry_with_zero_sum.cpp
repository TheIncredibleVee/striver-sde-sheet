//Efficient using hashing TC O(n) and SC O(n)
int maxLen(vector<int>&A, int n){   
    unordered_map<int, int> mp;
    int res = 0;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += A[i];
        if(sum == 0){
            res = i + 1;
        }
        if(mp.find(sum) != mp.end()){
            res = max(res, i - mp[sum]);
        }else{
            mp[sum] = i;
        }
    }
    return res;
}
//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
//https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/
