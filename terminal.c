#include"types.h"
// store terminal data user entered transaction amount and transaction date
uint8_t terminal(struct ST_cardData_t *c, struct ST_terminalData_t *t) {
    printf("\nPlease enter terminal data:\n");
    printf("Please Enter the transaction Amount:\n");
    scanf("%lf", &t->transAmount);
    // check if the transaction amount is bigger than the max terminal amount
    if (t->transAmount > t->maxTransAmount) {
        printf("The Transaction is DECLINED\n");
        printf("Error: Transaction Amount > Maximum Transaction Amount\n");
        return -1;
    }   //if the transaction amount < max transaction amount the code will proceed
        printf("Please Enter transaction Date:\t\t (DD/MM/YYYY)\n");
        scanf(" %s", t->transactionDate);
        // check whether the card is expired or not
        uint8_t dateValidation = checkDate(c->cardExpirationDate, t->transactionDate);
        if (dateValidation == 0) {
            printf("The Transaction is DECLINED\n");
            printf("Error: Card is Expired!\n");
            return -1;
        }
        // if the code reached this far it indicates that the terminal conditions are all passed successful
        return 1;
    }
    // fucntion used to compare the dates
uint8_t checkDate(uint8_t expirationDate[6], uint8_t terminalDate[11]){
    //creating pointers at exact locations at both character arrays

    //  expiration date example: MM/YY
    // last 2 digits indicates to year
    uint8_t *expirationDateYears  = &expirationDate[3];
    // first 2 digits indicates to month
    uint8_t *expirationDateMonths = &expirationDate[0];

    // terminal date example: DD/MM/YYYY
    // last 2 digits indicates to years that will be compared
    uint8_t *terminalDateYears    = &terminalDate[8];
    // Months digits that will be compared
    uint8_t *terminalDateMonths   = &terminalDate[3];
    //creating integers with a format of "YYMM" to compare between them
    uint32_t expirationDateInt = 100*atoi( expirationDateYears) + atoi(expirationDateMonths);
    uint32_t terminalDateInt = 100*atoi(terminalDateYears)+atoi(terminalDateMonths);
    // comparing
    if(terminalDateInt < expirationDateInt) return 1;
    else return 0;
}
