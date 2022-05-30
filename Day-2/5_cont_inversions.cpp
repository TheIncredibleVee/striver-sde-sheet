//Efficeint Time complexity O(n*logn) and space complexity O(n)

long long merge(vector<long long> &vec, int start, int mid , int end){
	vector<long long> left(vec.begin()+start, vec.begin()+mid);
	vector<long long> right(vec.begin()+mid, vec.begin()+end+1);
	long long  i = 0;
	long long j = 0;
	long long k = start;
	long long res = 0;
	while(i < left.size() && j < right.size()){
		if(left[i] > right[j]){
			vec[k] = right[j];
			res += left.size()-i;
			j++;
		}else{
			vec[k] = left[i];
			i++;
		}
		k++;
	}
	while(i < left.size()){
		vec[k] = left[i];
		i++;
		k++;
	}
	while(j < right.size()){
		vec[k] = right [j];
		j++;
		k++;
	}
	return res;
}

long long rec(vector<long long> &vec, int start, int end){
	long long res = 0;
	if(start<end){
		int mid = (start + end ) / 2;
		res += rec(vec, start, mid);
		res += rec(vec, mid+1, end);
		res += merge(vec, start, mid + 1, end);
	}
	return res;
}


long long getInversions(long long *arr, int n){
	vector<long long> vec(arr, arr+n);
	long long res = rec(vec, 0, n-1);
	return res;
}

//https://takeuforward.org/data-structure/count-inversions-in-an-array/
//https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1