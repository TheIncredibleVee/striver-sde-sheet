int findDuplicate(vector<int> &a, int n){
	int slow=a[0];
	int fast=a[0];
	slow=a[slow];
	fast=a[a[fast]];
	while(fast!=slow){
		slow=a[slow];
		fast=a[a[fast]];
	}
	slow=a[0];
	while(slow!=fast){
		fast=a[fast];
		slow=a[slow];
	}
	return slow;
}

//https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/
//https://www.codingninjas.com/codestudio/problems/1112602?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0