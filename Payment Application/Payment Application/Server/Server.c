#pragma warning(suppress : 4996)
#include<stdio.h>
#include"Server.h"
#include<string.h>

uint32_t user_number = 0;
uint32_t transNumber = 0;
ST_accountsDB_t accountsDB[255];
ST_transaction_t transactionsDB[255] = { 0 };

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	if ((isValidAccount(&transData->cardHolderData, &accountsDB)) == ACCOUNT_NOT_FOUND)
	{
		return FRAUD_CARD;
	}
	if ((isBlockedAccount(&accountsDB)) == BLOCKED_ACCOUNT)
	{
		return DECLINED_STOLEN_CARD;
	}
	if ((isAmountAvailable(&transData->terminalData, &accountsDB)) == LOW_BALANCE)
	{
		return DECLINED_INSUFFECIENT_FUND;
	}
	if ((saveTransaction(transData)) == SAVING_FAILED)
	{
		return INTERNAL_SERVER_ERROR;
	}
	else
	{
		accountsDB[user_number].balance = accountsDB[user_number].balance - transData->terminalData.transAmount;
		return APPROVED;
	}
}
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
{
	uint32_t counter1;
	for (counter1 = 0; counter1 < 255; counter1++)
	{
		if ((strcmp(cardData->primaryAccountNumber, accountRefrence[counter1].primaryAccountNumber)) == 0)
		{
			user_number = counter1;
			return SERVER_OK;
			break;
		}
		
	}
	user_number = 0;
	return ACCOUNT_NOT_FOUND;
}
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	if (accountRefrence[user_number].state == BLOCKED)
	{
		return BLOCKED_ACCOUNT;
	}
	else return SERVER_OK;

}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	if (accountRefrence[user_number].balance < termData->transAmount)
	{
		return LOW_BALANCE;
	}
	else return SERVER_OK;
}
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	if (transactionsDB[transNumber].transactionSequenceNumber < 255)
	{
		transactionsDB[transNumber].cardHolderData = transData->cardHolderData;
		transactionsDB[transNumber].terminalData = transData->terminalData;
		transactionsDB[transNumber].transState = transData->transState;
		transData->transactionSequenceNumber = transNumber;
		transactionsDB[transNumber].transactionSequenceNumber = transData->transactionSequenceNumber;
		return SERVER_OK;
	}
	return SAVING_FAILED;

}
void listSavedTransactions(void)
{
	int counter2;
	for (counter2 = 0; counter2 <= transNumber; counter2++)
	{
		    printf("\n#############################");
			printf("\nTransaction Number : %d", transactionsDB[counter2].transactionSequenceNumber);
			printf("\nTransaction Date : %s", transactionsDB[counter2].terminalData.transactionDate);
			printf("\nTransaction Amount : %0.2f", transactionsDB[counter2].terminalData.transAmount);
			printf("\nTransaction State : %d", transactionsDB[counter2].transState);
			printf("\nTerimnal Max Amount : %0.2f", transactionsDB[counter2].terminalData.maxTransAmount);
			printf("\nCard Holder Name : %s", transactionsDB[counter2].cardHolderData.cardHolderName);
			printf("\nPAN : %s", transactionsDB[counter2].cardHolderData.primaryAccountNumber);
			printf("\nCard Expiration Date : %s", transactionsDB[counter2].cardHolderData.cardExpirationDate);
			printf("\n#############################");

	}
	transNumber++;
}






