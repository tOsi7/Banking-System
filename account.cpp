/*Holds all class functions
Taron Osifo*/
#include "account.h"

int Account::avail = 1000;//sets static value 
void Account::updateInt(int var){avail+=var;} //updates static functions
Account::Account(){ //initial constructor, sets values to null
	acctnum=0;
	name=" ";
	balance=0.0;
}

Account::Account(string name, float balance){ //overload setting acctnum to static int
	this->name=name;
	this->balance=balance;
	acctnum=avail;
	updateInt(1); //increase
}
Account::~Account(){}

void Account::SetAcctNum(int acctnum){
	int var=1;
	this->acctnum=acctnum;
	updateInt(var);
}

int Account::GetAcctNum(){return acctnum;}

void Account::SetName(string name){
	this->name=name;
}

string Account::GetName(){return name;}

void Account::SetBalance(float balance){
	this->balance=balance;
}

float Account::GetBalance(){return balance;}

void Account::AddBalance(float balance){
	this->balance+=balance; //adds to balance
}

void Account::SubWithdraw(float balance){
	this->balance-=balance; //subtacts from balance
}
void Account::Print(){ //called to print each value
	cout << acctnum << " | " << name << " | $";
	cout << fixed << setprecision(2) << balance << setfill(' ') << setw(3) << "|" << endl; 
}
