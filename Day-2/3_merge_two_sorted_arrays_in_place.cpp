//Efficient time complexity O(n+m) and space complexity O(1)

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int mx=arr1[0];
	for(auto x:arr1){
		mx=max(x, mx);
	}
	for(auto x:arr2){
		mx=max(mx, x);
	}
	mx++;
	int i=0;
	int j=0;
	int k=0;
	while(i<m && j<n && k<n+m){
		int elem1=arr1[i]%mx;
		int elem2=arr2[j]%mx;
		if(elem1>elem2){
			if(k>=m){
				arr2[k-m]+=elem2*mx;
			}
			else{
				arr1[k]+=elem2*mx;
			}
			j++;
		}else{
			if(k>=m){
				arr2[k-m]+=elem1*mx;
			}
			else{
				arr1[k]+=elem1*mx;
			}
			i++;
		}
		k++;
		
	}
	while(i<m){
		int elem1=arr1[i]%mx;
		if(k>=m){
			arr2[k-m]+=elem1*mx;
		}
		else{
			arr1[k]+=elem1*mx;
		}
		i++;
		k++;
	}
	
	while(j<n){
		int elem2=arr2[j]%mx;
		if(k>=m){
			arr2[k-m]+=elem2*mx;
		}
		else{
			arr1[k]+=elem2*mx;
		}
		j++;
		k++;
	}
	vector<int> res;
	for(int i=0;i<m;++i){
		arr1[i]/=mx;
		res.push_back(arr1[i]);
	}
	for(auto x:arr2){
		x/=mx;
		res.push_back(x);
	}
	return res;
}

//https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/
//https://www.codingninjas.com/codestudio/problems/1214628?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1