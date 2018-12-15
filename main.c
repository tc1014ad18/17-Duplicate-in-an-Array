#include <stdio.h>
#include <stdbool.h>

struct numbers {
    int number;
    bool processed;
};

int main() {
    int n;
    printf("Hullo, Mate!\nGive me a list of numbers and I'll tell you how many duplicates there are\n");
    printf("How many numbers are we dealing with? ");
    scanf("%d", n);

    if (n <= 0) {
        printf("If you don't want to work, just tell me, mate! See you around.\n");
        return 0;
    }

    struct numbers myNumbers[n];
    int duplicates = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &myNumbers[i].number);
        myNumbers[i].processed = false;
    }

    for (int i = 0; i < n - 1; i++) {
        int number = myNumbers[i].number;
        if (!myNumbers[i].processed) {
            myNumbers[i].processed = true;
            bool duplicate = false;
            for (int j = i + 1; j < n; j++) {
                if (myNumbers[j] == number) {
                    if (!duplicate) {
                        duplicate = true;
                        duplicates++;
                    }
                    myNumbers[j].processed = true;
                }
            }
        }
    }

    printf("There were a %d duplicates in your list.\n", duplicates);
    printf("See you around, mate!\n");
    
    return 0;
}