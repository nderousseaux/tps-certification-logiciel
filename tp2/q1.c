enum kind { LOWER, UPPER, DIGIT, OTHER };

/*@
assigns \nothing;
ensures \result <==> c \in \union(('a' .. 'z'));
*/
int is_lower_alpha(char c) {
	return 'a' <= c && c <= 'z';
}

/*@
assigns \nothing;
ensures \result <==> c \in \union(('A' .. 'Z'));
*/
int is_upper_alpha(char c) {
	return 'A' <= c && c <= 'Z';
}

/*@
assigns \nothing;
ensures \result <==> c \in \union(('0' .. '9'));
*/
int is_digit(char c) {
	return '0' <= c && c <= '9';
}


/*@
assigns \nothing;
ensures \result <==>
	c \in \union(('a' .. 'z'), ('A' .. 'Z'), ('0' .. '9'));
*/
int is_alphanum(char c) {
	return is_lower_alpha(c) || is_upper_alpha(c) || is_digit(c);
}

/*@
assigns \nothing;
ensures \result == LOWER <==> c \in \union(('a' .. 'z'));
ensures \result == UPPER <==> c \in \union(('A' .. 'Z'));
ensures \result == DIGIT <==> c \in \union(('0' .. '9'));
ensures \result == OTHER <==> !(c \in \union(('0' .. '9'), ('A' .. 'Z'), ('a' .. 'z')));
*/
enum kind get_char_kind(char c) {
	if (is_lower_alpha(c)) {
		return LOWER;
	} else if (is_upper_alpha(c)) {
		return UPPER;
	} else if (is_digit(c)) {
		return DIGIT;
	} else {
		return OTHER;
	}
}

/*@
assigns \nothing;
*/
void test() {
	enum kind k = get_char_kind('a');
	//@ assert k == LOWER;
	k = get_char_kind('A');
	//@ assert k == UPPER;
	k = get_char_kind('0');
	//@ assert k == DIGIT;
	k = get_char_kind(' ');
	//@ assert k == OTHER;
}