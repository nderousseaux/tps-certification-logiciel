// Ecrire une fonction int up_and_down (int tll, int taille, int u) qui prend en argument un tableau t, sa taille taille et une position u dans le tableau.
// Cette fonction vérifiera que le tableau est bien trié par ordre croissant jusqu'à la case u, puis que le tableau est trié par ordre décroissant de la case u jusqu'à la fin.
// On utilisera de préférence une boucle for et on choisira d'exécuter l'instruction return 0 que al condition ne sera pas vérifiée.

/*@
requires \valid(&t[0..taille-1]);
requires taille > 0;
requires 0 <= u && u < taille;
assigns \nothing;
ensures (\forall int i ; 0 <= i < u && t[i] <= t[i+1]) ==> \result == 1;
ensures (\forall int i ; u <= i < taille-1 && t[i] >= t[i+1]) ==> \result == 1;
ensures ((\exists int i ; 0 <= i < u && t[i] > t[i+1]) && (\exists int i ; u <= i < taille-1 && t[i] < t[i+1])) ==> \result == 0;
*/
int up_and_down(int t[], int taille, int u){

	/*@ 
		loop invariant 0 <= i <= u;
		loop invariant \forall int j; 0 <= j < i ==> t[j] <= t[j+1];
		loop assigns i;
		loop variant u-i;
	*/
	for(int i=0; i<u; i++){
		if(t[i]>t[i+1]){
			return 0;
			}
	}
	/*@ 
		loop invariant u <= i <= taille-1;
		loop invariant \forall int j; u <= j < i ==> t[j] >= t[j+1];
		loop assigns i;
		loop variant taille-i;
	*/
	for(int i=u; i<taille-1; i++){
		if(t[i]<t[i+1]){
			return 0;
		}
	}
	return 1;
}