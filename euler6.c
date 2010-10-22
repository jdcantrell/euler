#include <stdio.h>
#include <math.h>

int sum_of_squares(num) {
    return (num * (num + 1) * (2 * num + 1)) / 6;
}

int sum(num) {
    return (num * (num + 1)) / 2;
}

main() {
    int diff;
    int squares = sum_of_squares(100);
    int sumN = sum(100);
    diff = (sumN * sumN) - squares;
    printf("The difference between the (sum of 1 to 100)^2 and the sum of 1^2 to 100^2 is %d", diff);

}
