//  Définir une fonction min2 : int min2 (int a, int b) qui retourne el minimum des deux arguments a et b.

/*@
assigns \nothing;
ensures \result == a || \result == b;
ensures \result <= a && \result <= b;
*/
int min2(int a, int b){
	if (a < b)
	{
		return a;
	}
	return b;
}

/*
assigns \nothing;
ensures \result == a || \result == b || \result == c;
ensures \result <= a && \result <= b && \result <= c;
*/
int min3(int a, int b, int c){
	return min2(min2(a,b),c);
}

/*@
assigns \nothing;
ensures \result == a || \result == b || \result == c || \result == d;
ensures \result <= a && \result <= b && \result <= c && \result <= d;
*/
int min4(int a, int b, int c, int d){
	return min2(min2(min2(a,b),c),d);
}