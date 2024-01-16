// Rechercher l'indice minimum d'un tableau

/*@
requires \valid(&t[0..n-1]);
requires n > 0;
assigns \nothing;
ensures 0 <= \result < n;
ensures \forall int i; 0 <= i < n ==> t[i] >= t[\result];
*/
int array_min(int t[], int n){
	int min = 0;

	/*@
	loop invariant 1 <= i <= n;
	loop invariant 0 <= min < n;
	loop invariant \forall int j; 0 <= j < i ==> t[j] >= t[min];
	loop assigns i;
	loop assigns min;
	loop variant n - i;
	*/
	for (int i = 1; i < n; i++)
	{
		if (t[i] <= t[min])
			min = i;
	}

	return min;
}
