#include "types.h"

// used to search for a target string in an array
//target here will be the primary account number user entered
// array is the primary account numbers in the data base
uint8_t linearSearch(struct ST_accountBalance_t *dataBase, uint8_t size, uint8_t *target) {
        for (int i = 0; i < size; i++) {
            // check whether the two strings are equal or not
            if (strcmp((char *) dataBase[i].primaryAccountNumber, (char *) target) == 0)
                // if found return index of the customer
                return i;
        }
        return -1;
    }
// function used to print the array-> used to show the update in database after each transaction
    void printArray(struct ST_accountBalance_t *dataBase, uint32_t size) {
        printf("\n");
        for (int i = 0; i < size; i++)
            printf("%s\t%0.2f\n", dataBase[i].primaryAccountNumber, dataBase[i].balance);

    }



