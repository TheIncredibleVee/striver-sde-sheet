//Efficeint Time complexity O(n) and space complexity O(1)

long long maxSubarraySum(int arr[], int n)
{
	long long curr=0;
	long long int res=0;
	for(int i=0;i<n;++i){
		curr=max(curr+arr[i], (long long int)arr[i]);
		res=max(res, curr);
	}
	return res;
}



//https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
//https://www.codingninjas.com/codestudio/problems/630526?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website