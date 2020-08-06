#include"types.h"
// reading card data from user
// placing data entered in the struct that will be passed to this function
void card(struct ST_cardData_t *client) {
    printf("Please enter card data:\n");
    printf("Please enter card holder name:\n");
    scanf( "%[^\n]%*c",client->cardHolderName);
    printf("Please enter account number:\n");
    scanf(" %s", client->primaryAccountNumber);
    printf( "Please enter card Expiry Date:\t\t(MM/YY)\n");
    scanf(" %s",client->cardExpirationDate);
}

