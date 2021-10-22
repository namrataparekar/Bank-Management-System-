/*Namrata Parekar -BT19CSE075 -assignment1 -Q7 3feb2021
This program is for bank user to check his login and if its correct to do various desired tasks.*/
#include "BankAcccount.h"
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

BankAcccount::BankAcccount()											//default constructor
{
	userID= "unknown";
	password ="error";
	balance = 0;
}
BankAcccount::BankAcccount(string id,string pass,double bal){		//parameterized constructor
	setID(id);
	setPassword(pass);
	setBalance(bal);
}
																	//getter and setter functions
string BankAcccount::getID(){
	return userID;
}
string BankAcccount::getPassword(){
	return password;
}
double BankAcccount::getBalance(){
	return balance;
}
void BankAcccount::setID(string id){
	userID=id;
}
void BankAcccount::setPassword(string pass){
	password=pass;
}
void BankAcccount::setBalance(double bal){
	balance=bal;
}


void BankAcccount::Start(){												//start of the program
	int i;
	cout<<"1.Create a account."<<endl;
	cout<<"2.Login to check details."<<endl;
	
	cout<<"Enter your choice:";
	cin>> i;
	switch(i){
		case 1:
			createAcc();
			break;
		case 2:
			checkDetails();
			break;
		default:
			cout<<"Wrong option!"<<endl;
	}
}
void BankAcccount::createAcc()											//member function for creating account
{
    string id,pass;
    cout<<"\nEnter what user Id you want : ";
    cin>>id;
    setID(id);
    cout<<"Enter the password : ";
    cin>>pass;
    setPassword(pass);
    setBalance(0);
    cout<<"\nBank Account Successfully Created\n";
    Start();
}
void BankAcccount::checkDetails(){										//member functions to checkdetails if login is correct or not
	string id,pass;
    cout<<"\nEnter your User ID : ";
    cin>>id;
    cout<<"Enter your Password : ";
    cin>>pass;

    if(id==getID() && pass==getPassword())
    {
        cout<<"\nLog In Successful\n";
        displaymenu();
    }
    else
    {
        cout<<"\nWrong User ID or Password\n";
        Start();
    }
}
void BankAcccount::displaymenu(){									//if login is correct this menu function will come
	int i;
	cout << "\n1. Wihdraw money"<<endl;
	cout << "2. Deposit money"<<endl;
	cout << "3. Request Balance" << endl;
	cout << "4. Quit Program"<<endl;
	
	cout<<"Enter your choice:"<<endl;
	cin>>i;
	
	switch(i){
		case 1:
			withdraw();
			break;
		case 2:
			deposit();
			break;
		case 3:
			balanceCheck();
			break;
		case 4:
			quit();
			break;
		default :
			cout << "Wrong option";
		
	}
	
}
void BankAcccount::withdraw(){								//member function to withdraw money
	int amount;
    cout<<"\nEnter the amount to Withdraw : ";
    cin>>amount;

    if(amount>getBalance())
    {
        cout<<"\nOPERATION INVALID\n";
        cout<<"Not Sufficient Balance\n";
    }
    else
    {
        setBalance(getBalance()-amount);
        cout<<"\nAmount withdraw Successfully\n";
        cout<<"After withdraw balance is: "<<getBalance();
    }
    displaymenu();
}
void BankAcccount::deposit(){								//member function to deposit money
	int amount;
    cout<<"\nEnter the amount you want to deposit: ";;
    cin>>amount;
    setBalance(getBalance()+amount);
    cout<<"\nAmount Deposited Successfully\n";
    cout<<"After Deposit balance is : "<<getBalance();
    displaymenu();
}
void BankAcccount::balanceCheck(){							//member function to check balance
	cout<<"\nYour Current Balance is : "<<getBalance();
    displaymenu();
}

void BankAcccount::quit(){									//member function to quit program
	cout << "Thanks for visiting!";
}

