#include <stdio.h>

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
				//correct for leap year
				//if our range was larger we'd need to add a case for
				//leap year on a century non divisble by 400,
				//but since that is not required it is left out
                if (y % 4 == 0) {
                    eom = 29;
                }
            }

			//we are on the first of a month
			if (dayNumber % 7 == 0) {
				firstSundays++;
			}
			//advance to the next first of the month
			dayNumber+=eom;
        }
    }
    printf("First Sundays: %d\n", firstSundays);
    return 0;
}
