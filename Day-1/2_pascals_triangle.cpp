//Efficient T.C O(n^2) S.C O(n^2)
vector<vector<long long int>> printPascal(int n) 
{
	vector<vector<long long int> > res;
	for(int i=0;i<n;++i){
		vector<long long int> temp;
		for(int j=0;j<=i;++j){
			if(j==0 || j==i){
				temp.push_back(1);
			}
			else{
				temp.push_back(res[i-1][j]+res[i-1][j-1]);
			}
		}
		res.push_back(temp);
	}
	return res;
}



//Alternate implementation

vector < vector < long long int >> printPascal(int n) {
    vector < vector < long long int >> triangle;
    vector < long long int > temp;

    for (int i = 1; i <= n; i++) {
        long long int rCe = 1;
        temp.clear();
        for (int j = 1; j <= i; j++) {
            temp.push_back(rCe);
            rCe = rCe * (i - j) / j;
        }

        triangle.push_back(temp);
    }
    return triangle;
}




//https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
//https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_1089580?topList=striver-sde-sheet-problems&leftPanelTab=2
