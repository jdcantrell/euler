#include <stdio.h>
#include <string.h>

int main() {
    char* ones[] = {"","one","two","three","four","five","six","seven","eight","nine"};
    char* teens[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char* tens[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    
    int i = 0;
    int charCount = 0;
    for(i = 1; i < 1000; i++) {
        int num = i;
        char number[1000] = "";
        while(num > 0) {
            if (num < 10) {
                strcat(number, ones[num]);
                num = 0;
            }
            else if (num < 100) {
                if (num > 19) {
                    strcat(number, tens[num / 10]);
                    num = num % 10;
                }
                else if (num > 9) {
                    strcat(number, teens[num - 10]);
                    num = 0;
                }
            }
            else if (num < 1000) {
                strcat(number, ones[num/100]);
                strcat(number, "hundred");
                num = num % 100;
                if (num > 0) {
                    strcat(number, "and");
                }
            }
        }
        charCount += strlen(number);
        printf("Word: %s len: %lu\n", number, strlen(number));
    }
    charCount += strlen("onethousand");
    printf("Length: %d\n", charCount);
}
