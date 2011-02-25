#include <stdio.h>
#include <string.h>

#define DIGITS 1000
#define EON 255

typedef struct big_int_struct {
    int negative;
    unsigned char number[DIGITS];
} big_int;

big_int bi_init(char* str) {
    big_int num;
    int j = 0;
    int i = 0;
    for (i = 0; i < DIGITS; i ++) {
        num.number[i] = 0;
    }
    num.number[strlen(str)] = EON;
    for (i = strlen(str) - 1; i >= 0; i--) {
        //printf("Setting idx: %d to value %c,%d\n", j, str[i],i);
        num.number[j] = str[i] - 48;
        j++;
    }
    return num;
}

char* bi_get(big_int n) {
    int i = 0;
    for(i = 0; i < DIGITS; i++) {
        if (n.number[i] == EON) {
            break;
        }
    }
    //printf("Number is %d long", i);
    int j;
    char s[i];
    for (j = 0; j < i; j++) {
        //printf("Getting %d and setting to %d", n.number[j], i - j);
        s[i - j - 1] = 48 + n.number[j];
    }
    s[i] = '\0';
    return strdup(s);
}

big_int bi_add(big_int a, big_int b) {
    big_int c = bi_init("0");
    int i;
    int carry = 0;
    int aFlag = 1;
    int bFlag = 1;
    //printf("A: %s, B: %s\n",bi_get(a),bi_get(b));
    for(i = 0; i < DIGITS; i++) {
        if (a.number[i] == EON) aFlag = 0;
        if (b.number[i] == EON) bFlag = 0;
        
        if (aFlag && bFlag) {//both numbers have the current digit
            c.number[i] = a.number[i] + b.number[i] + carry;
        }
        else if (aFlag) {//only a has current digit
            c.number[i] = a.number[i] + carry;
        }
        else if (bFlag) {//only b
            c.number[i] = b.number[i] + carry;
        }
        else {//we've looped over both a and b, so end our number
            if (carry) {
                c.number[i] = carry;
                c.number[i + 1] = EON;
            }
            else {
                c.number[i] = EON;
            }
            break;
        }
        //handle the carry digit
        carry = c.number[i] / 10;
        if (carry) {
            c.number[i] = c.number[i] - (carry * 10);
        }
    }
    return c;
}

big_int bi_mult(big_int a, big_int b) {
    big_int c = bi_init("0");
    int i, j, carry;
    for (i = 0; i < DIGITS; i++) {
        if (b.number[i] == EON) break;
        carry = 0;
        for(j = 0; j < DIGITS; j++) {
            if (a.number[j] == EON) break;
            //printf("Digit %d = %d * %d + %d\n",j+i, a.number[j], b.number[i],carry);
            c.number[j + i] = a.number[j] * b.number[i] + carry;
            carry = c.number[j + i] / 10;
            if (carry) {
                c.number[j + i] = c.number[j + i] - (carry * 10);
            }
            
        }
        //handle any extra carry we might have
        int x = 0;
        while (carry) {
            if (c.number[j + i + x] == EON) {
                c.number[j + i + x] = 0;
            }

            c.number[j + i + x] += carry;
            carry = c.number[j + i + x] / 10;
            if (carry) {
                c.number[j + i + x] = c.number[j + i + x] - (carry * 10);
            }
            x++;
        }
        c.number[j + i + x] = EON;
    }
    //printf("Final: %s\n", bi_get(c));
    return c;
}

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
}


int test_add_double() {
    big_int a= bi_init("99");
    big_int b= bi_init("1");
    if (0 == strcmp(bi_get(bi_add(a,b)), "100")) {
        return 1;
    }
    printf("\nUnexpected Value: %s\n", bi_get(bi_add(a,b)));
}

int test_add_two_size() {
    big_int a= bi_init("1234");
    big_int b= bi_init("9876543");
    if (0 == strcmp(bi_get(bi_add(a,b)), "9877777")) {
        return 1;
    }
    printf("\nUnexpected Value: %s\n", bi_get(bi_add(a,b)));
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
