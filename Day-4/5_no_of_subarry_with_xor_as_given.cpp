//Efficient using hashing TC O(n) SC O(n)
int subarraysXor(vector<int> &arr, int x){
	int n= arr.size();
	unordered_map<int, int> hm;
	int curr=0;
	int res=0;
	hm[0]++;				//x ^ 0 = x and x ^ x =0
	for(int i=0;i<n;++i){
		curr ^= arr[i];
// 		if(curr == x){ 		// eithter this if st. or hm[0] anything will works
// 			res++;
// 		}
		if(hm.find(x ^ curr) != hm.end()){
			res += hm[x ^ curr];
		}
		hm[curr]++;
	}
	return res;
}
//https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/
//https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2
