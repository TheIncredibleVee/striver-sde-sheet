//The approach of this solution is very simple just use a for loop to calculate the m+n-2Cn-1  or m+n-2Cm-1 
//Time complexity O(n-1) or O(m-1)
int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = m - 1; 
        double res = 1;
        
        for (int i = 1; i <= r; i++)
            res = res * (N - r + i) / i;
        return (int)res;
} 
//Efficient time complexity O(N*M) and space complexity O(N)
int uniquePaths(int m,int n)
{
    // Reference array to store subproblems.
	int dp[n] = {1};                   

    // Bottom up approach.
    dp[0] = 1;

    for (int i = 0; i < m; i++) 
    {      
        for (int j = 1; j < n; j++) 
        { 
            dp[j] += dp[j - 1];  
        }
    } 
    
    //Returning answer. 
    return dp[n - 1];                  
}

//ALternate Time complexity O(N*M) and space complexity O(N*M)
int rec(int m, int n, vector<vector<int>> &dp){
	if(dp[m][n] != -1){
		return dp[m][n];
	}
	if(m <= 0 || n <= 0){
		dp[m][n] = 0;
		return 0;
	}
	if(m == 1 || n==1){
		dp[m][n] = 1;
		return 1;
	}
	dp[m][n] = rec(m-1, n, dp) + rec(m, n-1, dp);
	return dp[m][n];
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
	return rec(m, n, dp);
}

//Bottom Up

int uniquePaths(int m,int n)
{
    // Reference table to store subproblems.
	int dp[m][n];                   

    // Paths to reach a cell in column 1.
	for (int i = 0; i < m; i++) 
    {   
        dp[i][0] = 1; 
    }

    // Paths to reach a cell in row 1.
    for (int j = 0; j < n; j++) 
    {   
        dp[0][j] = 1; 
    }       

    // Bottom up approach.
    for (int i = 1; i < m; i++) 
    {   
        for (int j = 1; j < n; j++) 
        { 
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];  
        }
    } 

    // Returning answer.
    return dp[m - 1][n - 1];        
}



//https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/
//https://www.codingninjas.com/codestudio/problems/1081470?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2