
#include "stdlib.h"
/*@
requires val > INT_MIN;
assigns \nothing;
ensures \result >= 0;
behavior pos:
	assumes 0 < val;
	ensures \result == val;

behavior neg:
	assumes val < 0;
	ensures \result == -val;

disjoint behaviors;
*/
// Si val est positif, retourne val, sinon retourne -val
// Si val est null, retourne 1
int abs_or_get_ten(int val){
	if (val == 0)
		return 1;
	if (val > 0)
		return val;
	return -val;	
}

/*@
assigns \nothing;

ensures \result == a || \result == b || \result == c;
ensures \result >= a;
ensures \result >= b;
ensures \result >= c;
*/
int max3(int a, int b, int c){
	int res = a;
	if (b > res)
		res = b;
	if (c > res)
		res = c;
	return res;
}

/*@ 
requires \valid(&t[0..taille-1]);
requires 0 < taille;

assigns \nothing;

ensures (\forall int i ; 0 <= i < taille-1 && t[i] <= t[i+1]) ==> \result == 1;
ensures (\exists int i ; 0 <= i < taille-1 && t[i] > t[i+1]) ==> \result == 0;
*/
int increasing(int t[], int taille){
	/*@ 
		loop invariant 0 <= i <= taille-1;
		loop invariant \forall int j; 0 <= j < i ==> t[j] <= t[j+1];

		loop assigns i;

		loop variant taille-i;
	*/
	for(int i=0; i<taille-1; i++){
		if(t[i]>t[i+1])
			return 0;
	}

	return 1;
}

// Tester si un tableau est trié par ordre décroissant

/*@
requires \valid(&t[0..taille-1]);
requires 0 < taille;

assigns \nothing;

ensures (\forall int i ; 0 <= i < taille-1 && t[i] >= t[i+1]) ==> \result == 1;
ensures (\exists int i ; 0 <= i < taille-1 && t[i] < t[i+1]) ==> \result == 0;
*/
int decreasing(int t[], int taille){
	/*@ 
		loop invariant 0 <= i <= taille-1;
		loop invariant \forall int j; 0 <= j < i ==> t[j] >= t[j+1];

		loop assigns i;

		loop variant taille-i;
	*/
	for(int i=0; i<taille-1; i++){
		if(t[i]<t[i+1])
			return 0;
	}

	return 1;
}

/*@
requires \valid(&t[0..taille-1]);
requires 0 < taille;

assigns \nothing;

ensures (\forall int i ; 0 <= i < taille-1 && t[i] <= t[i+1]) ==> \result == 1;
ensures (\forall int i ; 0 <= i < taille-1 && t[i] >= t[i+1]) ==> \result == 1;
ensures (
	(\exists int i ; 0 <= i < taille-1 && t[i] > t[i+1]) &&
	(\exists int i ; 0 <= i < taille-1 && t[i] < t[i+1])
)
	==> \result == 0;
*/
int monotonic(int t[], int taille){
	return increasing(t, taille) || decreasing(t, taille);
}