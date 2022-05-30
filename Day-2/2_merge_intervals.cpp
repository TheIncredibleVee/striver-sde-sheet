//Efficient time complexity O(n) and space complexity O(n)

/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
	vector<pair<int, int>> temp;
	vector<vector<int>> res;
	for(auto x:intervals){
		temp.push_back({x[0], x[1]});
	}
	sort(temp.begin(), temp.end());
	int start=temp[0].first;
	int end= temp[0].second;
	for(int i=0;i<temp.size()-1;++i){
		if(end>=temp[i+1].first){
			end=max(temp[i+1].second, end);
		}else{
			vector<int> x;
			x.push_back(start);
			x.push_back(end);
			res.push_back(x);
			start=temp[i+1].first;
			end=temp[i+1].second;
		}
	}
	vector<int> x;
	x.push_back(start);
	x.push_back(end);
	res.push_back(x);
	return res;
}


//https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
//https://www.codingninjas.com/codestudio/problems/699917?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1