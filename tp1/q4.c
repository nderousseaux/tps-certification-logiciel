// Copier le contenu d’un tableau dans un autre
// (les deux tableaux sont de même taille et sont pris en argument).

/*@
requires \valid(&s[0..size-1]);
requires \valid(&t[0..size-1]);
requires \separated(&s[0..size-1],&t[0..size-1]);
requires size>=0;
assigns t[0..size-1];
ensures (\forall integer i; 0 <= i < size ==> t[i] == s[i]);
*/
void array_copy(int s[], int t[], int size) {
	/*@
	loop invariant 0 <= i <= size;
	loop invariant (\forall integer j; 0 <= j < i ==> t[j] == s[j]);
	loop assigns i;
	loop assigns t[0..size-1];
	loop variant size-i;
	*/
	for (int i = 0; i < size; i++) {
		t[i] = s[i];
	}
}