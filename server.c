#include"types.h"
// server function is created to search for the user in the data base and checks his balance if found
uint8_t server(struct ST_accountBalance_t *dataBase,struct ST_cardData_t *card, struct ST_terminalData_t *t) {
    // using linear search algorithm to search for the primary account number user entered
    uint8_t result = linearSearch(dataBase, 10, card->primaryAccountNumber);
    // 255 indicates not fount --> '-1'
    if (result == (255)) {
        printf("The Transaction is DECLINED\n");
        printf("Error: Account is not found !\n");
        return -1;
    }
    /*if code reached here it indicates that the account is found
     and the result variable hold index of the user account, balance
     */
    // checks whether the account balance is sufficient or not for the transaction
    if(dataBase[result].balance < t->transAmount){
        printf("The Transaction is DECLINED\n");
        printf("Error: Transaction amount > Account Balance.\n");
        return -1;
    }
    //function successfully ended if the code reached here
    printf("The Transaction is APPROVED.\n");
    // returning the result to update teh database
    return result;

}