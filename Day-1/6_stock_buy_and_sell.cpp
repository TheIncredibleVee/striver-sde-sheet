//Efficient time complexity O(n) and space complexity O(1)

int maximumProfit(vector<int> &prices){
	int res=0;
	int minsofar=prices[0];
	for(auto x:prices){
		res=max(res,x-minsofar);
		minsofar=min(minsofar, x);
	}
	return res;
}

//https://takeuforward.org/data-structure/stock-buy-and-sell/
//https://www.codingninjas.com/codestudio/problems/893405?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2