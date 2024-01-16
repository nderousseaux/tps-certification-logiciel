//Tester si tout les éléments d'un tableau sont nuls

/*@
requires \valid(&t[0..n-1]);
requires n >= 0;
assigns \nothing;
ensures (\forall int i ; 0 <= i && i <= n && t[i] == 0) ==> \result == 1;
ensures \exists int i ; 0 <= i && i <= n && t[i] != 0 ==> \result == 0;
*/
int all_zeros(int t[], int n){
	/*@
		loop invariant i >= 0 && i <= n;
		loop invariant \forall int j; j >= 0 && j < i ==> t[j] == 0;
		loop assigns i;
		loop variant n-i;
	*/
	for(int i=0; i<n; i++){
		if(t[i]!=0){
			return 0;
		}
	}

	return 1;
}