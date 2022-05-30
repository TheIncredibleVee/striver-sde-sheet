//Efficeint Time complexity O(n) and space complexity O(1)

vector<int> nextPermutation(vector<int> &arr, int n)
{
	int start = n-1;
	if(n==1){
		return arr;
	}
	while(start>0 && arr[start]<=arr[start-1]){
		start--;
	}
	if(start==0){
		reverse(arr.begin(),arr.end());
		return arr;
	}
	start--;
	int end = start;
	while(end < n && arr[start] <= arr[end]){
		end++;
	}
	end=end==start?end:end-1;
	swap(arr[start], arr[end]);
	reverse(arr.begin() + start + 1, arr.end());
	return arr;
}


//https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/
//https://www.codingninjas.com/codestudio/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website