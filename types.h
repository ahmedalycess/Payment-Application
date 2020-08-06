#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef struct ST_cardData_t{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef struct ST_terminalData_t{
    double transAmount;
    double maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_transStat_t{
    DECLINED,APPROVED
}EN_transStat_t;

typedef struct ST_transaction_t{
    ST_cardData_t cardHolderData;
    ST_terminalData_t transData;
    EN_transStat_t transStat;
}ST_transaction;

typedef struct ST_accountBalance_t
{
    uint8_t primaryAccountNumber[20];
    double balance;
}ST_accountBalance_t;

extern void card(struct ST_cardData_t *card);

extern uint8_t terminal(struct ST_cardData_t *card, struct ST_terminalData_t *terminal);
extern uint8_t checkDate(uint8_t expirationDate[6], uint8_t terminalDate[11]);

extern uint8_t server(struct ST_accountBalance_t *dataBase,struct ST_cardData_t *card, struct ST_terminalData_t *terminal);
extern uint8_t linearSearch(struct ST_accountBalance_t *dataBase, uint8_t size,uint8_t *target);
extern void printArray(struct ST_accountBalance_t *dataBase, uint32_t size);



