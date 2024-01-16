// Tester si deux tableaux sont égaux

/*@
requires \valid(&t[0..n-1]);
requires \valid(&u[0..n-1]);
requires n > 0;
assigns \nothing;
ensures (\forall int i ; 0 <= i && i <= n && t[i] == u[i]) ==> \result == 1;
ensures \exists int i ; 0 <= i && i <= n && t[i] != u[i] ==> \result == 0;
*/
int equal_array(int t[], int u[], int n){
	/*@
		loop invariant 0 <= i <= n;
		loop invariant \forall int j; 0 <= j < i ==> t[j] == u[j];
		loop assigns i;
		loop variant n-i;
	*/
	for(int i=0; i<n; i++){
		if(t[i]!=u[i]){
			return 0;
		}
	}

	return 1;
}