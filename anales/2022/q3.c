// Programmer une fonction en langage C qui prend en argument un tableau t et sa taille n, et qui retourne
// • 1 si tous les éléments d'indice pair du tableau sont pairs et si tous les éléments d'indice impair du tableau sont impairs.
// • O sinon.

/*@
requires \valid(&t[0..n-1]);
requires n > 0;
assigns \nothing;
ensures \result == 1 || \result == 0;
ensures (\forall int i; 0 <= i < n ==> t[i]%2 == i%2) ==> \result == 1;
ensures (\exists int i; 0 <= i < n && t[i]%2 != i%2) ==> \result == 0;
*/
int pair_impair(int t[], int n){
	/*@
		loop invariant 0 <= i <= n;
		loop invariant \forall int j; 0 <= j < i ==> t[j]%2 == j%2;
		loop assigns i;
		loop variant n-i;
	*/
	for(int i=0; i<n; i++){
		if(i%2 == 0 && t[i]%2 != 0){
			return 0;
		}
		if(i%2 == 1 && t[i]%2 != 1){
			return 0;
		}
	}
	return 1;
}