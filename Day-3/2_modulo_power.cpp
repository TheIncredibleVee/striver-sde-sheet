//Efficient Time complexity O(log(n)) and space complexity O(1)

int modularExponentiation(int x, int n, int m) {
	int answer = 1;

	// Run a loop until 'N' > 0.
	while (n > 0) {
		// If bitwise and of 'N' with 1 is 1 then multiply answer with 'X'.
		if (n & 1)  {
			answer = (1LL * answer * x) % m;
		}
		// Do modular squaring of 'X'.
		x = (1LL * x * x ) % m;

		// Right shift 'N' by 1 bit for next iteration.
		n >>= 1;
	}
	// Return the answer.
	return answer;
}



//Alterante Time complexity O(log(n)) and space complexity O(log(n))
int modularExponentiation(int x, int n, int m) {
	if(n == 1){
		return x % m;
	}
	else{
		if(n%2){
			return ( 1LL * x % m * (modularExponentiation(x, n-1, m) % m) % m);
		}else{
			return ( 1LL * modularExponentiation(( 1LL * x * x) % m, n/2, m) ) % m;
		}
	}
}

//https://takeuforward.org/data-structure/implement-powxn-x-raised-to-the-power-n/
//https://www.codingninjas.com/codestudio/problems/1082146?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2
