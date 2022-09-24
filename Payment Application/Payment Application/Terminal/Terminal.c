#pragma warning(suppress : 4996)

#include<stdio.h>
#include<string.h>
#include"Terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("\nEnter Date of the Transaction DD/MM/YYYY : ");
	fflush(stdin);
	gets(termData->transactionDate);

	if (termData->transactionDate == NULL || termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/')
	{
		return WRONG_DATE;
	}
	if (strlen(termData->transactionDate) < 10)
	{
		return WRONG_DATE;
	}
	else return TERMINAL_OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	int this_month,expire_month,this_year,expire_year;
	this_month = (((termData->transactionDate[3] - '0') * 10) + (termData->transactionDate[4] - '0'));
	expire_month = (((cardData->cardExpirationDate[0] - '0') * 10) + (cardData->cardExpirationDate[1] - '0'));
	this_year = (((termData->transactionDate[8] - '0') * 10) + (termData->transactionDate[9] - '0'));
	expire_year = (((cardData->cardExpirationDate[3] - '0') * 10) + (cardData->cardExpirationDate[4] - '0'));

	if ((this_month > expire_month && this_year >= expire_year) || (this_year > expire_year))
	{
		return EXPIRED_CARD;
	}
	else return TERMINAL_OK;

}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("\nEnter Desired Transaction Amount : ");
	fflush(stdin);
	scanf("%f", &termData->transAmount);
	fflush(stdin);
	if (termData->transAmount <= 0)
	{
		return INVALID_AMOUNT;
	}
	else return TERMINAL_OK;

}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	if (maxAmount <= 0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else {
		termData->maxTransAmount = maxAmount;
		return TERMINAL_OK;
	}
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		return EXCEED_MAX_AMOUNT;
	}
	else return TERMINAL_OK;

}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{
	if (cardData->primaryAccountNumber[0] != '5' || cardData->primaryAccountNumber[1] != '3' || cardData->primaryAccountNumber[2] != '9' || cardData->primaryAccountNumber[3] != '9')
	{
		return INVALID_CARD;
	}
	else return TERMINAL_OK;
}




















