//Programmer en c une fonction qui prend en arguments trois entiers et qui renvoie le maximum
// des trois.


/*@
ensures \result == a || \result == b || \result == c;
ensures \result >= a && \result >= b && \result >= c;
*/
int max3(int a, int b, int c){
	int max = a;
	if (b > max)
	{
		max = b;
	}
	if (c > max)
	{
		max = c;
	}
	return max;
}