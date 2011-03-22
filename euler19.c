#include <stdio.h>

#define SIZE 15

int main() {
    int y, m, d, eom;
    int dayNumber = 1;
    int firstSundays = 0;
    for (y = 1901; y <= 2000; y++) {
        for(m = 1; m <= 12; m++) {
            eom = 31;
            if (m == 4 || m == 6 || m == 9) {
                eom = 30;
            }
            if (m == 2) {
                eom = 28;
                if (y % 4 == 0) {
                    eom = 29;
                }
            }
        
            for(d = 1; d <= eom; d++) {
                if (d == 1 && dayNumber % 7 == 0) {
                    firstSundays++;
                }
                dayNumber++;
            }
        }
    }
    printf("First Sundays: %d", firstSundays);
    return;
}
