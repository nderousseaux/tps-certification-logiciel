// Rechercher l'indice d'un élément dans un tableau

/*@
requires \valid(&t[0..n-1]);
requires n > 0;
assigns \nothing;
ensures 0 <= \result < n || \result == -1;
ensures t[\result] == x || \result == -1;
*/
int array_search(int t[], int n, int x){
	/*@
	loop invariant 0 <= i <= n;
	loop invariant \forall int j; 0 <= j < i ==> t[j] != x;
	loop assigns i;
	loop variant n - i;
	*/
	for(int i=0; i<n; i++){
		if(t[i]==x){
			return i;
		}
	}

	return -1;
}	