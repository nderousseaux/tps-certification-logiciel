// Tester si un tableau est trié par ordre croissant

/*@ 
requires \valid(&t[0..taille-1]);
requires taille > 0;
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
		if(t[i]>t[i+1]){
			return 0;
		}
	}

	return 1;
}

// Tester si un tableau est trié par ordre décroissant

/*@
requires \valid(&t[0..taille-1]);
requires taille > 0;
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
		if(t[i]<t[i+1]){
			return 0;
		}
	}

	return 1;
}


// Tester si un tableau est trié par ordre croissant ou décroissant

/*@
requires \valid(&t[0..taille-1]);
requires taille > 0;
assigns \nothing;
ensures (\forall int i ; 0 <= i < taille-1 && t[i] <= t[i+1]) ==> \result == 1;
ensures (\forall int i ; 0 <= i < taille-1 && t[i] >= t[i+1]) ==> \result == 1;
ensures ((\exists int i ; 0 <= i < taille-1 && t[i] > t[i+1]) && (\exists int i ; 0 <= i < taille-1 && t[i] < t[i+1])) ==> \result == 0;
*/
int monotonic(int t[], int taille){
	return increasing(t, taille) || decreasing(t, taille);
}