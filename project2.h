/*holds the functions called in main and definitions
Taron Osifo*/
#ifndef PROJECT2_H
#define PROJECT2_H
#include "account.h"
#include <iomanip>
#include <vector>
#include <algorithm>
	enum Choices{OPEN=1, DEPOSIT, WITHDRAW, PRINT, EXIT};//Enum choices for switch case
	
	void List(){
	/*Prints the display menu*/
    cout << setfill(' ');
	for(int i=0; i<14; ++i)
	{
		cout<<"*";
	}
	cout << " Menu ";
	for(int i=0; i<14; ++i)
	{
		cout<<"*";
	}
	cout << endl;
	
	cout << "| 1. Open Account"<< setw(18) << "|\n"<<"| 2. Deposit into Account" << setw(10) <<"|\n";
	cout<<"| 3. Withdraw from Account" << setw(9)<<"|\n"<< "| 4. Print List of Accounts"<< setw(8)<<"|\n";
	cout<<"| 5. Exit Program"<< setw(18)<<"|\n";
		for(int i=0; i<34; ++i)
	{
		cout<<"*";
	}
	cout << endl;
}
	
	void PrintAcct(vector<Account> acct, int i){//Prints account info for new account opened
		cout << "Account opened: " << acct[i].GetAcctNum() << " ---- " << acct[i].GetName();
		cout << ": $" << fixed << setprecision(2) << acct[i].GetBalance() << endl;
	}	
	void OpenAcct(vector<Account> &acct, int i){ //Opens new account
		string name;//new name to be added
		float deposit; //new deposit amount
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter Deposit amount: ";
		cin >> deposit;
		acct.push_back(Account(name, deposit));//Constructor called to hold new info
		PrintAcct(acct, i);
	}	
	void DepositAmt(vector<Account> &acct){ //Deposits amount into an account
		int acctnum;//holds to search for matching account number
		int index=-1;//to check if there is a match
		cout << "Enter the account number: ";
		cin >> acctnum;
		for(int i=0; i<acct.size(); ++i){
			if (acctnum==acct[i].GetAcctNum()){
			index=i;}
		}
		if(index==-1){
			cout << "Account number was not found.\n";
		}
		else{
			float deposit;
			cout << "Enter the amount you would like to deposit: ";
			cin >> deposit;
			acct[index].AddBalance(deposit);
			cout << "Deposit Successful. New balance: $";
			cout << fixed << setprecision(2) << acct[index].GetBalance()<<endl;
		}
	}
	void WithdrawAmt(vector<Account> &acct){
		int acctnum;
		int index=-1;
		cout << "Enter the account number: ";
		cin >> acctnum;
		for(int i=0; i<acct.size(); ++i){
			if (acctnum==acct[i].GetAcctNum()){
			index=i;}
		}
		if(index==-1){
			cout << "Account number was not found.\n";
		}
		else{
			float withdraw;
			cout << "Enter the amount you would like to withdraw: ";
			cin >> withdraw;
			if(withdraw>acct[index].GetBalance()){
				cout << "Insuffiecient funds.\n";
			}
			else{
				acct[index].SubWithdraw(withdraw);
				cout << "Withdraw Successful. New balance: $";
				cout << fixed << setprecision(2) << acct[index].GetBalance()<<endl;
			}
		}
	}		
	void PrintInfo(vector<Account> acct){//Prints all info of the accounts
		cout << "+" << setfill('-') << setw(37) <<"+" << endl;
		cout << "| Acct Number | Name" << setfill(' ') << setw(10) << "| Balance" << setw(9) << "|\n";
		cout << "+" << setfill('-') << setw(37) <<"+" << endl;
		for(int i=0; i<acct.size();++i){
			cout << "|" <<setfill(' ') << setw(10);
			acct[i].Print();//calls the function print
		}			
		
		cout << "+" << setfill('-') << setw(37) <<"+" << endl;
	}
	void Euid(){
	/*Prints student information*/
	 cout << "+" << setw(40) << setfill('-') << "+\n";
   for(int i=0; i<4; ++i)
   {
   cout << "|" << setw(40) << setfill(' ') << "|\n";
   if(i==0)
   {
       cout << "|" << setw(15) << setfill(' ') <<"  Computer Science and Engineering "<< setw(5) << "|\n";
   }
   else if(i==1)
   {
       cout << "|" << setw(15) << setfill(' ') <<"   CSCE 1040 - Computer Science II "<< setw(5) << "|\n";
   }
   else if(i==2)
   {
       cout << "|" << setw(10) << setfill(' ') <<" Taron Osifo to0150 to0150@my.unt.edu"<< setw(3) << "|\n";
   }
   }
   cout << "+" << setw(40) << setfill('-') << "+\n" << endl;
	
}

#endif