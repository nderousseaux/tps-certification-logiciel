// Tester si un tableau est un palindrome

/*@
requires \valid(&t[0..n-1]);
requires n > 0;
assigns \nothing;
ensures (\forall int i ; 0 <= i < n && t[i] == t[n-i-1]) ==> \result == 1;
ensures (\exists int i ; 0 <= i < n && t[i] != t[n-i-1]) ==> \result == 0;
*/
int array_palindrome(int t[], int n){	
	/*@
		loop invariant 0 <= i <= n;
		loop invariant \forall int j; 0 <= j < i ==> t[j] == t[n-j-1];
		loop assigns i;
		loop variant n-i;
	*/
	for(int i=0; i<n; i++){
		if(t[i]!=t[n-i-1]){
			return 0;
		}
	}

	return 1;
}