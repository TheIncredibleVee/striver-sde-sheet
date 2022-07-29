//Efficient using 2 pointers TC O(n) and SC O(1)

int trap(vector<int>& height) {
    int res = 0;
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    while(left< right){
        if(height[left] < height[right]){
            leftMax = max(leftMax, height[left]);
            res += (leftMax - height[left]);
            left++;
        }else{
            rightMax = max(rightMax, height[right]);
            res += (rightMax - height[right]);
            right--;
        }
    }
    return res;
}

/*
    Alternate Soln. using stack TC O(n) and SC O(n)
*/

int trap(vector<int>& height) {
    long long res = 0;
    stack<int> st;
    int n = height.size();
    st.push(0);
    for(int i = 1; i < n; ++i){
        while(!st.empty() && height[st.top()] < height[i]){
            int curr = st.top();
            st.pop();
            int nextGreater =  i;
            if(st.empty()){
                continue;
            }
            int prevGreater = st.top();
            long long w = nextGreater - prevGreater - 1;
            long long h = min(height[nextGreater], height[prevGreater]) - height[curr];
            res += h*w;
        }
        st.push(i);
    }
    return res;
}

//Alternate using 2 arrays for leftMax and rightMax TC O(n) and SC O(n)

int trap(vector < int > & arr) {
    int n = arr.size();
    int prefix[n], suffix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
    }
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
    }
    int waterTrapped = 0;
    for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }
    return waterTrapped;
}

//Brute Force

int trap(vector < int > & arr) {
    int n = arr.size();
    int waterTrapped = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0) {
        leftMax = max(leftMax, arr[j]);
        j--;
        }
        j = i;
        while (j < n) {
        rightMax = max(rightMax, arr[j]);
        j++;
        }
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;
}

//https://leetcode.com/problems/trapping-rain-water/submissions/
//https://www.youtube.com/watch?v=SQu1ZKaonrY&ab_channel=Pepcoding
//https://takeuforward.org/data-structure/trapping-rainwater/
