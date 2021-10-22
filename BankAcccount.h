/*Namrata Parekar -BT19CSE075 -assignment1 -Q7 3feb2021
This program is for bank user to check his login and if its correct to do various desired tasks.*/
#ifndef BANKACCCOUNT_H
#define BANKACCCOUNT_H
#include<string.h>
#include<string>
using namespace std;

class BankAcccount
{
	private:					//data members of class declared here
		string userID;
		string password;
		double balance;
	public:						//member functions,getter,setter,constructor declared here
		BankAcccount();
		BankAcccount(string id,string pass,double bal);
		
		string getID();
		string getPassword();
		double getBalance();
		void setID(string id);
		void setPassword(string pass);
		void setBalance(double bal);
		void withdraw();
		void deposit();
		void balanceCheck();
		void displaymenu();
		void quit();
		void checkDetails();
		void Start();
		void createAcc();
		
};

#endif
