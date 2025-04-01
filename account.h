/*Header function holding class and Definitions
Taron Osifo*/
#ifndef ACCOUNT_H
#define	ACCOUNT_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Account{
		private:
			int acctnum; //holds account number
			string name; //holds account owner name
			float balance; //holds acount balance
		
			
		public:
			static int avail; //value to assign acct number
			static void updateInt(int var); //updates static value
			Account(); //constructor
			Account(string name, float balance); //Overload constructor
			~Account(); //Destructor
			void SetAcctNum(int acctnum);//Setter
			int GetAcctNum(); //Accessor
			void SetName(string name); //Setter
			string GetName(); //Accessor
			void SetBalance(float balance); //Setter
			float GetBalance(); //Accessor
			void AddBalance(float balance); //Adds to selected account balance
			void SubWithdraw(float balance); //Subtracts from selected account balance
			void Print(); //Prints the info of the account
	
};
#endif