//Efficient O(n) and space O(1)

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int sum=0;
	int reqsum=(n*(n+1))/2;
	int rep=0;
	for(auto x:arr){
		int y =abs(x)-1;
		sum+=y+1;
		arr[y]=-arr[y];
		if(arr[y]>0){
			rep=y+1;
		}
	}
	return {abs(sum-rep-reqsum),rep};
}


//https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
//https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1




