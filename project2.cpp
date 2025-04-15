/*Taron Osifo
1040.001
03/22/25
Program displays a list of options to dealing with a bank account.
Accounts can be created or have a deposit or a withdrawal
Exits when the user is done using its functions.*/
#include "project2.h"

int main(){
	
	int *ch; //switch case value
	bool quit=false;//for while loop to continue
	vector <Account> acct;//Vector of Account type to hold values
	int i=0;//for index of vector when called in function
	do{//start of do while loop
	List();//calls list function
	ch = new int;//realloactes memory
	cout << "What would you like to do?: ";
	cin >> *ch;
	switch(*ch){//start of switch case
		case OPEN:
		OpenAcct(acct, i);
		++i;//increases the index of a vector
		break;
		
		case DEPOSIT:
		DepositAmt(acct);
		
		break;
		
		case WITHDRAW:
		WithdrawAmt(acct);
		
		break;
		
		case PRINT:
		if(acct.size()==0){//checks if there are elements in the vector
			cout << "There are not accounts. ";
		}
		else{
			PrintInfo(acct);
		}
		break;
		
		case EXIT:
		cout << "Thank you for your business. Goodbye!\n";
		quit=true;//breaks the loop
		break;
		
		default:
			cout << "Error. Incorrect Input.\n";
			
		break;
	};
	delete ch;//deletes memory
	}
	while(quit==false);//end of loop
	
	
	
	return 0;
}
