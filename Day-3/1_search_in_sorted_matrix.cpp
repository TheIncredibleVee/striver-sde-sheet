//Efficient time complexity O(log(m*n)) and space complexity O(1)

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
	int low = 0;
	int high = m*n-1;
	while(low <= high){
		int mid = (low + high)/2;
		if(mat[mid/n][mid%n] == target){
			return true;
		}
		if(mat[mid/n][mid%n] > target){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return false;
}


//ALternate Time complexity O(m+n) and space complexity O(1)

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
	int starty = n-1;
	int startx = 0;
	while(starty >= 0 && startx < m){
		if(mat[startx][starty] == target){
			return true;
		}
		if(mat[startx][starty] > target){
			starty--;
		}else{
			startx++;
		}
	}
	return false;
}


//time Time complexity O(log(n)*log(m)) and space complexity O(1)
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
	int start = 0;
	int end = m-1;
	while(end>=start){
		int mid = (end + start) / 2;
		if(mat[mid][0] > target){
			start = mid-1;
		}
		else{
			return binary_search(mat[mid].begin(), mat[mid].end(), target) || binary_search(mat[mid+1].begin(), mat[mid+1].end(), target);
		}
	}
	return false;
}


//https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/
//https://www.codingninjas.com/codestudio/problems/980531?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1