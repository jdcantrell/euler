#include <stdio.h>
#include <math.h>

int is_palindrome(num) {
    int mag = 0, top, h = 0, exp;

    //find out the length of the umber
    while (pow(10,mag) < num) {
        mag++;
    }

    //grab the top half
    top = num / pow(10,mag/2);
    if (mag % 2) {
        top = top / 10;
    }

    //reverse the bottom half
    exp = mag/2 - 1;
    while (exp >= 0) {
        h += (num % 10) * pow(10, exp);
        num = num / 10;
        exp--;
    }

    if (top == h) return 1;
    return 0;
}

main() {
    int i, j, num, maxj, maxi;
    int max = 0;
    //this checks some numbers twice
    //The main way to speed this up is to be
    //more selective about what numbers we use for the multiples
    for(i = 999; i >100; i--) {
        for(j = 999; j > 100; j--) {
            if (is_palindrome(j * i) == 1) {
                printf("Palindrome found: %d = %d * %d\n",j*i,i,j);
                if (j* i > max) {
                    max = j * i;
                    maxj = j;
                    maxi = i;
                }
            }
        }
    }
    printf("Max %d = %d * %d\n", max, maxj, maxi); 
}
