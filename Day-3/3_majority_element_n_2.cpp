//Efficient time complexity O(n) and space complexity O(1)
int findMajorityElement(int a[], int n) {
	vector<int> arr(a, a+n);
	int pot = arr[0];
	int cnt = 0;
	for(auto x: arr){
		if(x == pot){
			cnt++;
		}else{
			cnt--;
			if(cnt == 0){
				pot = x;
				cnt = 1;
			}
		}
	}
	cnt = 0;
	for(auto x: arr){
		if(x == pot){
			cnt++;
		}
	}
	if(cnt > n/2){
		return pot;
	}
	return -1;
}



//https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/
//https://www.codingninjas.com/codestudio/problems/842495?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
