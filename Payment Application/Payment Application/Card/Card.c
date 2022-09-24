#pragma warni++ng(suppress : 4996)

#include<stdio.h>
#include "Card.h"
#include<string.h>



EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("Enter the card owner name : ");
	fflush(stdin);
	gets(cardData->cardHolderName);
	if (cardData->cardHolderName == NULL)
	{
		return WRONG_NAME;
	}
	else if (strlen(cardData->cardHolderName) > 24 || strlen(cardData->cardHolderName) < 20)
	{
		return WRONG_NAME;
	}
	else return CARD_OK;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	printf("\nEnter Card Expiration Date MONTH/YY : ");
	fflush(stdin);
	gets(cardData->cardExpirationDate);
	if (((((cardData->cardExpirationDate[0]) - '0') * 10 + (cardData->cardExpirationDate[1]) - '0')) > 12)
	{
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[2] != '/' || strlen(cardData->cardExpirationDate) != 5 || cardData->cardExpirationDate == NULL)
	{
		return WRONG_EXP_DATE;
	}
	else return CARD_OK;
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("\nEnter Primary Account Number : ");
	fflush(stdin);
	gets(cardData->primaryAccountNumber);
	if (strlen(cardData->primaryAccountNumber) > 19 || strlen(cardData->primaryAccountNumber) < 16 || cardData->primaryAccountNumber == NULL)
	{
		return WRONG_PAN;
	}
	else return CARD_OK;
}