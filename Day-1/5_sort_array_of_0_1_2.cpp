//Efficeint Time complexity O(n) and space complexity O(1) 1 pass sol.

void sort012(int *arr, int n)
{
	int low=0;
	int high=n-1;
	int mid=0;
	while(mid<=high){
		if(arr[mid]==0){
			swap(arr[mid++], arr[low++]);
		}
		else if(arr[mid]==1){
			mid++;
		}
		else if(arr[mid]==2){
			swap(arr[mid], arr[high--]);
		}
	}    
}


//https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
//https://www.codingninjas.com/codestudio/problems/631055?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website