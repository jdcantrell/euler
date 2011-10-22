#include <stdio.h>
#include <string.h>
#include "big_int.h"


//unit tests - note to self - find a good unit test library
//and never do this again
int test_set_from_string() {
    big_int a = bi_init("500");
    if (a.number[3] == EON && a.number[2] ==5 && a.number[1] == 0 && a.number[0] == 0) {
        return 1;
    }
    printf("\nUnexpected Values: %d, %d, %d, %d\n", a.number[3], a.number[2], a.number[1], a.number[0]);
    return 0;
}

int test_get_from_string() {
    big_int a = bi_init("500");
    if (0 != strcmp(bi_get(a), "500")) {
        printf("\nUnexpected Value: *%s*\n", bi_get(a));
        return 0;
    }
    return 1;
}

int test_add_single() {
    big_int a= bi_init("3");
    big_int b= bi_init("4");
    if (0 == strcmp(bi_get(bi_add(a,b)), "7")) {
        return 1;
    }
    printf("\nUnexpected Value: %s\n", bi_get(bi_add(a,b)));
    return 0;
}


int test_add_double() {
    big_int a= bi_init("99");
    big_int b= bi_init("1");
    if (0 == strcmp(bi_get(bi_add(a,b)), "100")) {
        return 1;
    }
    printf("\nUnexpected Value: %s\n", bi_get(bi_add(a,b)));
    return 0;
}

int test_add_two_size() {
    big_int a= bi_init("1234");
    big_int b= bi_init("9876543");
    if (0 == strcmp(bi_get(bi_add(a,b)), "9877777")) {
        return 1;
    }
    printf("\nUnexpected Value: %s\n", bi_get(bi_add(a,b)));
    return 0;
}

int test_mult_single() {
    big_int a= bi_init("3");
    big_int b= bi_init("3");
    if (0 == strcmp(bi_get(bi_mult(a,b)), "9")) {
        return 1;
    }
    printf("\nUnexpected Value: %s\n", bi_get(bi_mult(a,b)));
    return 0;
}

int test_mult_double() {
    big_int a= bi_init("105");
    big_int b= bi_init("5");
    if (0 == strcmp(bi_get(bi_mult(a,b)), "525")) {
        return 1;
    }
    printf("\nUnexpected Value: %s\n", bi_get(bi_mult(a,b)));
    return 0;
}

int test_mult_increase() {
    big_int a= bi_init("64");
    big_int b= bi_init("2");
    if (0 == strcmp(bi_get(bi_mult(a,b)), "128")) {
        return 1;
    }
    printf("\nUnexpected Value: %s\n", bi_get(bi_mult(a,b)));
    return 0;
}

int main() {
    //unit tests
    printf("Test set_from_string ");
    if (test_set_from_string() == 1) {
        printf("pass\n");
    }
    else printf("fail\n");

    printf("Test get_from_string ");
    if (test_get_from_string() == 1) {
        printf("pass\n");
    }
    else printf("fail\n");

    printf("Test add_single ");
    if (test_add_single() == 1) {
        printf("pass\n");
    }
    else printf("fail\n");

    printf("Test add_double ");
    if (test_add_double() == 1) {
        printf("pass\n");
    }
    else printf("fail\n");

    printf("Test add_two_size ");
    if (test_add_two_size() == 1) {
        printf("pass\n");
    }
    else printf("fail\n");

    printf("Test mult_single ");
    if (test_mult_single() == 1) {
        printf("pass\n");
    }
    else printf("fail\n");
    
    printf("Test mult_double ");
    if (test_mult_double() == 1) {
        printf("pass\n");
    }
    else printf("fail\n");
    
    printf("Test mult_increase ");
    if (test_mult_increase() == 1) {
        printf("pass\n");
    }
    else printf("fail\n");

    //actual problem 16 code
    big_int a = bi_init("1");
    big_int two = bi_init("2");
    int i = 0;
    for(i = 0; i < DIGITS; i++) {
        a = bi_mult(a, two);
    }
    printf("2**1000: %s\n", bi_get(a));
    
    int sum = 0;
    for (i = 0; i < DIGITS; i++) {
        if (a.number[i] == EON) {
            break;
        }
        sum += a.number[i];
    }
    printf("Sum of digits: %d\n", sum);
}
