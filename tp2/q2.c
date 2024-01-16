/*@
requires \valid(a) && \valid(b);
requires \separated(a,b);
assigns *a;
assigns *b;
ensures *a == \old(*b);
ensures *b == \old(*a);
*/
void swap(int* a, int* b){
    int tmp = *a;
		*a=*b;
		*b=tmp;
}

/*@
requires \valid(a) && \valid(b);
requires \separated(a,b);
assigns *a;
assigns *b;
ensures *a <= *b;
ensures *a == \old(*a) && *b == \old(*b) || *a == \old(*b) && *b == \old(*a);
ensures {*a, *b} == {\old(*a), \old(*b)};
*/
void order2(int* a, int* b){
	if (*b <= *a)
	{
		swap(a,b);
	}
}

/*@
requires \valid(a) && \valid(b) && \valid(c);
requires \separated(a,b,c);
assigns *a;
assigns *b;
assigns *c;
ensures *a <= *b <= *c;
*/
void order3(int* a, int* b, int *c){
	order2(b,c);
	order2(a,b);
	order2(a,c);
}

