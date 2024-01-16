// Calcule le minimum entre deux entiers

/*@
assigns \nothing;
ensures \result == p || \result == q;
ensures \result <= p && \result <= q;
*/
int min(int p, int q){
	if (p < q){
		return p;
	}
	else{
		return q;
	}
}