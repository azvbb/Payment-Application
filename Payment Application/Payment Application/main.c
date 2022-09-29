#pragma warning(suppress : 4996)

#include<stdio.h>
#include<string.h>
#include"Server\Server.h"
#include"Application\APP.h"

//extern ST_accountsDB_t accountsDB[255] = { {5240.0,RUNNING,"5399314267210006"},{9200.0,RUNNING, "5399314267210220"},{1200.0,RUNNING,"5399314267210360"},{22000.0,RUNNING,"5399314267210428"},{7623.0,BLOCKED,"5399314267210881"} };

/*void getCardHolderNameTest(void);
void getCardExpiryDateTest(void);
void getCardPANTest(void);
void getTransactionDateTest(void);
void isCardExpiredTest(void);
void getTransactionAmountTest(void);
void isBelowMaxAmountTest(void);
void  isValidCardPANTest(void);
void setMaxAmountTest(void);
void isValidAccountTest(void);
void isBlockedAccountTest(void);
void isAmountAvailableTest(void);
*/
void main()
{
		appStart();
			
}





//Test Functions

/*void getCardHolderNameTest(void)
{
	ST_cardData_t NAME;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getCardHolderName\n");
	printf("Test case 1 : less or extra name letters number\n");
	printf("Input Data : Ahmed\n");
	printf("Expected Result : 1\n");
	int check = getCardHolderName(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getCardHolderName\n");
	printf("Test case 2 : Valid Date\n");
	printf("Input Data : ahmed el azab bakryyy\n");
	printf("Expected Result : 0\n");
	check = getCardHolderName(&NAME);
	printf("\nActual Result : %d\n\n\n", check);

}

void getCardExpiryDateTest(void)
{
	ST_cardData_t NAME;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getCardExpiryDate\n");
	printf("Test case 1 : Wrong Date Format\n");
	printf("Input Data : 12 23\n");
	printf("Expected Result : 2\n");
	int check = getCardExpiryDate(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getCardExpiryDate\n");
	printf("Test case 2 : Valid Date\n");
	printf("Input Data : 12/23\n");
	printf("Expected Result : 0\n");
	check = getCardExpiryDate(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
}
void getCardPANTest(void)
{
	ST_cardData_t NAME;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getCardPAN\n");
	printf("Test case 1 : Few PAN Numbers\n");
	printf("Input Data : 560089811\n");
	printf("Expected Result : 3\n");
	int check = getCardPAN(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getCardPAN\n");
	printf("Test case 2 : Valid PAN\n");
	printf("Input Data : 5399351243621789\n");
	printf("Expected Result : 0\n");
	check = getCardPAN(&NAME);
	printf("\nActual Result : %d\n\n\n", check);

}
void getTransactionDateTest(void)
{
	ST_terminalData_t NAME;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getTransactionDate\n");
	printf("Test case 1 : Wrong Format\n");
	printf("Input Data : 11/12/22\n");
	printf("Expected Result : 1\n");
	int check = getTransactionDate(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getTransactionDate\n");
	printf("Test case 2 : Valid Date\n");
	printf("Input Data : 11/12/2022\n");
	printf("Expected Result : 0\n");
	check = getTransactionDate(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
}
void isCardExpiredTest(void)
{
	ST_cardData_t NAME;
	ST_terminalData_t TERM1;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isCardExpired\n");
	printf("Test case 1 : Expire Date < Current Date\n");
	printf("Input Data : 11/12/2022 - 12/21\n");
	printf("Expected Result : 2\n");
	getCardExpiryDate(&NAME);
	getTransactionDate(&TERM1);
	int check = isCardExpired(&NAME,&TERM1);
	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isCardExpired\n");
	printf("Test case 2 : Expire Date > Current Date\n");
	printf("Input Data : 11/12/2022 - 12/23\n");
	printf("Expected Result : 0\n");
	getCardExpiryDate(&NAME);
	getTransactionDate(&TERM1);
	check = isCardExpired(&NAME,&TERM1);
	printf("\nActual Result : %d\n\n\n", check);

}
void getTransactionAmountTest(void)
{

	ST_terminalData_t NAME;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getTransactionAmount\n");
	printf("Test case 1 : Invalid Amount\n");
	printf("Input Data : 0\n");
	printf("Expected Result : 4\n");
	int check = getTransactionAmount(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getTransactionAmount\n");
	printf("Test case 2 : Valid Amount\n");
	printf("Input Data : 7000\n");
	printf("Expected Result : 0\n");
	check = getTransactionAmount(&NAME);
	printf("\nActual Result : %d\n\n\n", check);

}
void isBelowMaxAmountTest(void)
{
	ST_terminalData_t NAME;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isBelowMaxAmount\n");
	printf("Test case 1 : Amount more than max\n");
	printf("Input Data : 7000 - 20000\n");
	printf("Expected Result : 5\n");
	setMaxAmount(&NAME, 7000);
	getTransactionAmount(&NAME);
	int check = isBelowMaxAmount(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isBelowMaxAmount\n");
	printf("Test case 2 : Amount less or equal to the max\n");
	printf("Input Data : 7000 - 200\n");
	printf("Expected Result : 0\n");
	setMaxAmount(&NAME, 7000);
	getTransactionAmount(&NAME);
	check = isBelowMaxAmount(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
}
void  isValidCardPANTest(void)
{
	ST_cardData_t NAME;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isValidCardPAN\n");
	printf("Test case 1 : Wrong PAN Format\n");
	printf("Input Data : 4321091098277654\n");
	printf("Expected Result : 3\n");
	getCardPAN(&NAME);
	int check = isValidCardPAN(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isValidCardPAN\n");
	printf("Test case 2 : Valid PAN Format\n");
	printf("Input Data : 5399091098277654\n");
	printf("Expected Result : 0\n");
	getCardPAN(&NAME);
	check = isValidCardPAN(&NAME);
	printf("\nActual Result : %d\n\n\n", check);
}
void setMaxAmountTest(void)
{
	ST_terminalData_t NAME;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : setMaxAmount\n");
	printf("Test case 1 : Invalid Max Amount\n");
	printf("Input Data : 0in the code\n");
	printf("Expected Result : 6\n");
	int check = setMaxAmount(&NAME,0);
	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : getTransactionAmount\n");
	printf("Test case 2 : Valid Max Amount\n");
	printf("Input Data : 7000 in the code\n");
	printf("Expected Result : 0\n");
	check = setMaxAmount(&NAME,7000);
	printf("\nActual Result : %d\n\n\n", check);
}
void isValidAccountTest(void)
{
	ST_cardData_t NAME;
	ST_transaction_t server;
	ST_terminalData_t TERM1;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isValidAccount\n");
	printf("Test case 1 : PAN not in DB\n");
	printf("Input Data : 5399314267210000\n");
	printf("Expected Result : 3\n");
	getCardPAN(&NAME);
	int check = isValidAccount(&NAME, &accountsDB);
	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isValidAccount\n");
	printf("Test case 2 : PAN in DB\n");
	printf("Input Data : 5399314267210006\n");
	printf("Expected Result : 0\n");
	getCardPAN(&NAME);
	check = isValidAccount(&NAME, &accountsDB);
	printf("\nActual Result : %d\n\n\n", check);


}
void isBlockedAccountTest(void)
{
	ST_cardData_t NAME;
	ST_transaction_t server;
	ST_terminalData_t TERM1;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isBlockedAccount\n");
	printf("Test case 1 : Blocked Account\n");
	printf("Input Data : 5399314267210881\n");
	printf("Expected Result : 5\n");
	getCardPAN(&NAME);
	isValidAccount(&NAME, &accountsDB);
	int check = isBlockedAccount(&accountsDB);

	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isBlockedAccount\n");
	printf("Test case 2 : Running Account\n");
	printf("Input Data : 5399314267210006\n");
	printf("Expected Result : 0\n");
	getCardPAN(&NAME);
	isValidAccount(&NAME, &accountsDB);
	check = isBlockedAccount(&accountsDB);

	printf("\nActual Result : %d\n\n\n", check);

}

void isAmountAvailableTest(void)
{

	ST_cardData_t NAME;
	ST_transaction_t server;
	ST_terminalData_t TERM1;
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isAmountAvailable\n");
	printf("Test case 1 : Not enough balance\n");
	printf("Input Data : 5399314267210006 - 20000\n");
	printf("Expected Result : 4\n");
	getCardPAN(&NAME);
	getTransactionAmount(&TERM1);
	isValidAccount(&NAME, &accountsDB);
	int check = isAmountAvailable(&TERM1,&accountsDB);

	printf("\nActual Result : %d\n\n\n", check);
	printf("Tester Name : Ahmed El Azab\n");
	printf("Function Name : isAmountAvailable\n");
	printf("Test case 2 : Enough Balance\n");
	printf("Input Data : 5399314267210006 - 3000\n");
	printf("Expected Result : 0\n");
	getchar();
	getCardPAN(&NAME);
	getTransactionAmount(&TERM1);
	isValidAccount(&NAME, &accountsDB);
	check = isAmountAvailable (&TERM1,&accountsDB);

	printf("\nActual Result : %d\n\n\n", check);

}*/
