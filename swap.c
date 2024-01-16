/*@
requires \valid(a);
requires \valid(b);
requires \separated(a,b);
assigns *a;
assigns *b;
ensures *a == \old(*b);
ensures *b == \old(*a);
*/
void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}
/*@
requires \valid(a);
requires \valid(b);
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
requires \valid(a);
requires \valid(b);
requires \valid(c);
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

//@ assigns \nothing;
void test() {
int a = 1, b = 3, c = 2;
order3(&a, &b, &c);
//@ assert a == 1 && b == 2 && c == 3;
a = 2, b = 1, c = 0;
order3(&a, &b, &c);
//@ assert a == 0 && b == 1 && c == 2;
a = 2, b = 2, c = 1;
order3(&a, &b, &c);
//@ assert a == 1 && b == 2 && c == 2;
a = 1, b = 2, c = 1;
order3(&a, &b, &c);
//@ assert a == 1 && b == 1 && c == 2;
}