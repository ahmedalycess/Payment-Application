#include "types.h"
// data base of the payment application
struct ST_accountBalance_t dataBase[] =
        {
                {"123456789", 100.00},
                {"234567891",6000.00},
                {"567891234",3250.25},
                {"456789123",1500.12},
                {"258649173",500.00},
                {"654823719",2100.00},
                {"971362485",0.00},
                {"793148625",1.00 },
                {"123123456", 10.12},
                {"456789321", 0.55},
        };
// prototype of clear function, it is used to clear the structures after the transaction
void clear (struct ST_cardData_t *c, struct ST_terminalData_t *t);
int main() {
        //Initializing the card and terminal structures
        struct ST_cardData_t c = {"", "", ""};
        struct ST_terminalData_t t = {0.0, 6000.0, ""};
        //Initializing user input, 'y'--> yes, and 'n'--> no
        uint8_t userInput = 'y';
        // creating pointers to structs to pass by reference the structures to external functions
        struct ST_cardData_t *cptr = &c;
        struct ST_terminalData_t *tptr = &t;
        printf("\t\tWelcome\n");
        //program loop
        while(userInput == 'y'){
            //sending the card struct to the card function to store the card data in it
            card(cptr);
            //sending the terminal struct to the terminal function to store the terminal data in it
            /* the terminal function will return either 1, or 255
               -'1' if the terminal conditions are successfully completed
               -'255' if error happened during the conditions
             */
            uint8_t result = terminal(cptr, tptr);
            if (result == 1)
                // if terminal conditions are successfully done, the server function will be executed
                // the result variable here that this function will return is the index of the user
                // the index is used to update the data base with the new balance
                result = server(dataBase, cptr, tptr);
            if (result != 255) {
                // updating the balance of the user with index [result] with his new balance after transaction
                dataBase[result].balance = dataBase[result].balance - t.transAmount;
        }
        // print array function is used to print the database to show how it is automatically updated after each successful transaction
        printArray(dataBase, 10);
        // clear function is used after each transaction to clear the structs variables
        clear(cptr, tptr);
        // check whether user wants to create another transaction or not
        printf("Do you want to continue (y/n)?\n");
        scanf(" %c", &userInput);
        }
}
// implementation of clear function
// it is used in main() to clear the attributes of the struct after each transaction
void clear (struct ST_cardData_t *c, struct ST_terminalData_t *t){
    memset(c->primaryAccountNumber,0, 20);
    memset(c->cardHolderName,0, 25);
    memset(c->cardExpirationDate,0, 6);
    memset(t->transactionDate,0,11);
    t->transAmount = 0.0;
    t->maxTransAmount = 6000;
}



