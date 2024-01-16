// Remplir un tableau avec une valeur donnée


/*@
requires \valid(&t[0..n-1]);
requires n >= 0;
assigns t[0..n-1];
ensures (\forall int i; 0 <= i < n ==> t[i] == k);
*/
void array_fill(int t[], int n, int k) {
	/*@
		loop invariant 0 <= i <= n;
		loop invariant \forall int j; 0 <= j < i ==> t[j] == k;
		loop assigns i;
		loop assigns t[0..n-1];
		loop variant n-i;
	*/
	for(int i=0; i<n; i++){
			t[i]=k;
	}
}