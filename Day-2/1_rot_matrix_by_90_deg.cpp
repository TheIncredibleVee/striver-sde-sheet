//Efficient time complexity O(n*m) and space complexity O(1)

void rotate(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size();++i){
        for(int j=0;j<i;++j){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0;i<matrix.size();++i){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


//Alternate implementation Space complexity O(1)
vector < vector < int >> rotate(vector < vector < int >> & matrix) {
  int n = matrix.size();
  vector < vector < int >> rotated(n, vector < int > (n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      rotated[j][n - i - 1] = matrix[i][j];
    }
  }
  return rotated;
}



//https://takeuforward.org/data-structure/rotate-image-by-90-degree/
//https://leetcode.com/problems/rotate-image/solution/