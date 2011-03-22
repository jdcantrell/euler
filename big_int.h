#ifndef BIG_INT_GUARD
#define BIG_INT_GUARD

#define DIGITS 1000
#define EON 255
typedef struct big_int_struct {
    int negative;
    unsigned char number[DIGITS];
} big_int;

big_int bi_init(char* str);
void bi_set_int(big_int *n, int);
char* bi_get(big_int n); 
big_int bi_add(big_int a, big_int b);
big_int bi_mult(big_int a, big_int b);
#endif
