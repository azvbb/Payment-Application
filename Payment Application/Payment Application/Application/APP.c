#pragma warning(suppress : 4996)
#include<stdio.h>
#include"App.h"
#include<string.h>

extern ST_accountsDB_t accountsDB[255] = { {5240.0,RUNNING,"5399314267210006"},{9200.0,RUNNING, "5399314267210220"},{1200.0,RUNNING,"5399314267210360"},{22000.0,RUNNING,"5399314267210428"},{7623.0,BLOCKED,"5399314267210881"} };
void appStart(void)
{
	uint32_t flag = 1;
	ST_cardData_t user;
	ST_terminalData_t terminal_device_data;

	printf("\n\n\nTransaction  State Note : 0-APPROVED   1-DECLINED INSUFECCIENT FUND   2-DECLINED STOLEN CARD   3-FRAUD CARD\n\n");

	while (flag == 1)
	{
		
		uint8_t block_flag = 0;
		uint8_t acc_id = 0;
		printf("\t\t___________________Welcome to Udacity Payment System_____________________\n\n\n");
		printf("\n\nFor Transaction press 0   -   For Blocking Transactions press 1 :  ");
		scanf("%c", &block_flag);
		getchar();
		if (block_flag == '1')
		{
			printf("Enter your Account ID : ");
			scanf("%c", &acc_id);
			getchar();
			accountsDB[acc_id].state = BLOCKED;
			printf("\n\nAccount Blocked\n\n");
			break;
		}
		printf("\n\n\t\tEnter Valid Data\n\n");
		uint8_t name_check = getCardHolderName(&user);
		uint8_t exp_check = getCardExpiryDate(&user);
		uint8_t pan_check = getCardPAN(&user);
		uint8_t pan_serial = isValidCardPAN(&user);
		if (name_check == WRONG_NAME || exp_check == WRONG_EXP_DATE || pan_check == WRONG_PAN || pan_serial == INVALID_CARD)
		{
			printf("\nInvalid Entered Data");
			return;
		}
		uint8_t tran_date = getTransactionDate(&terminal_device_data);
		if (tran_date == WRONG_DATE)
		{
			printf("\nInvalid date format");
			return;
		}
		uint8_t if_expired = isCardExpired(&user, &terminal_device_data);
		if (if_expired == EXPIRED_CARD)
		{
			printf("\nCard Expired");
			return;
		}
		setMaxAmount(&terminal_device_data, 7000.0);
		uint8_t amount_check = getTransactionAmount(&terminal_device_data);
		if (amount_check == INVALID_AMOUNT)
		{
			printf("\nInvalid Amount Entered");
			return;
		}
		uint8_t exceeded_amount = isBelowMaxAmount(&terminal_device_data);
		if (exceeded_amount == EXCEED_MAX_AMOUNT)
		{
			printf("\nExceeded Allowed Max Amount");
			return;
		}
		ST_transaction_t server_data;
		server_data.cardHolderData = user;
		server_data.terminalData = terminal_device_data;
		uint8_t server_check = recieveTransactionData(&server_data);
		if (server_check == APPROVED)
		{
			printf("\nTransaction Success");
			server_data.transState = APPROVED;

		}
		if (server_check == FRAUD_CARD)
		{
			printf("\nEntered Card isn't registered");
			server_data.transState = FRAUD_CARD;

		}
		if (server_check == DECLINED_INSUFFECIENT_FUND)
		{
			printf("\nNo Enough Funds");
			server_data.transState = DECLINED_INSUFFECIENT_FUND;

		}
		if (server_check == DECLINED_STOLEN_CARD)
		{
			printf("\nThis Card is Blocked");
			server_data.transState = DECLINED_STOLEN_CARD;

		}
		saveTransaction(&server_data);
		listSavedTransactions();
		flag = 1;
		printf("\nFor another Transaction press -1-  To End press -0- : ");
		scanf("%d", &flag);
		getchar();
		

	}

}
