//Efficient time complexity O(n) and space complexity O(1)
vector<int> majorityElementII(vector<int> &arr){
	int cnta = 0;
	int cntb = 0;
	int pota = -1;
	int potb = -1;
	int n = arr.size();
	for(auto x: arr){
		if(cnta == 0){
			pota = x;
		}
		else if(cntb == 0){
			potb = x;
		}
		if(pota == x){
			cnta++;
		}else if(potb == x){
			cntb++;
		}
		else{
			cnta--;
			cntb--;
		}
	}
	cnta = cntb = 0;
	for(auto x: arr){
		if(x == pota){
			cnta++;
		}
		else if(x == potb){
			cntb++;
		}
	}
	vector<int> res;
	if(cnta > n/3){
		res.push_back(pota);
	}
	if(cntb > n/3){
		res.push_back(potb);
	}
	return res;
}



//https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/
//https://www.codingninjas.com/codestudio/problems/893027?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1