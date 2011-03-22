#include "big_int.h"
#include <stdio.h>
#include <string.h>


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
void bi_set_int(big_int *n, int val) {
    int i;

    //not really needed since the EON should keep 
    //use from reading incorrect data
    for (i = 0; i < DIGITS; i ++) {
        if ( (*n).number[i] != EON) (*n).number[i] = 0;
        else {
            (*n).number[i] = 0;
            break;
        }
    }

    i = 0;
    while (val) {
        (*n).number[i] = val % 10;
        val = val / 10;
        i++;
    }
    (*n).number[i] = EON;
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
            if (c.number[j + i] == EON) {
                c.number[j + i] = 0;
                c.number[j + i + 1] = EON;
            }
            //printf("Digit %d =%d + %d * %d + %d\n",j+i, c.number[j + i], a.number[j], b.number[i],carry);
            c.number[j + i] += a.number[j] * b.number[i] + carry;
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
