#include<iostream>
#include<conio.h> //getch
#include<iosfwd>
#include<string>
#include<iomanip> //setw
#include<unistd.h>//sleep
#include<fstream>//Files
#include<cstdlib>
using namespace std;

class ARUBANK{
	private: //-
		int AccountNo;
		string Name;
		float Deposit;
		char Type;
		
	public:	//+
		//Extras
		void createAccount();
		void showAccounts(); //show on the screen
		
		//Sets
		char setType(char type);
		void setDeposit(float deposit);
		void setAccountNo(int accountNo);
		
		//Gets
		char getType()const;
		string getName()const;
		float getDeposit()const;
		int getAccountNo()const;
};


int ARUBANK::getAccountNo()const{
	return AccountNo;
}

float ARUBANK::getDeposit()const{
	return Deposit;
}


string ARUBANK::getName()const{
	return Name;
}

char ARUBANK::getType()const{
	return Type;
}

char ARUBANK::setType(char type){
	Type=type;
}

void ARUBANK::setDeposit(float deposit){
	Deposit=deposit;
}

void ARUBANK::setAccountNo(int accountNo){
	AccountNo=accountNo;
}

void ARUBANK::showAccounts(){ //on screen
	cout<<setw(18)<<"Account Number"<<setw(18)<<"Account Holder"<<setw(18)<<"Type of Account"<<setw(18)<<"Initial Amount"<<endl;
	cout<<setw(18)<<AccountNo<<setw(18)<<Name<<setw(18)<<Type<<setw(18)<<Deposit<<endl<<endl<<endl;
}

void ARUBANK::createAccount(){
	cout<<"Enter The Account No: ";									cin>>AccountNo;
	
	cout<<"Enter The Name of The Account Holder :";					cin>>Name;
	do{
	cout<<"Enter The Type of Account [C/S] :";						cin>>Type;
	}while(Type!='C' && Type!='c' && Type!='s' && Type!='S'); 	//not any wrong option for type
	if(Type!='C' || Type!='S')				Type=toupper(Type);	 	//transfer to upper letter.
	do{
	cout<<"Enter Your Initial Amount: ";							cin>>Deposit;
	}while(Deposit<=0);		//not any wrong option for Deposit
}

//Functions
void letStart();	
void create_Account(); //Function to take infos
void showMoney();	//show only my money
void WithdrawMoney(); //take money from bank
void InvestMoney(); //Give money
void showAll(); //show all of them
void delete_account();
void supportUs();

int main(){
	letStart();	//Purpose is doing the shorter program
	//getch();
}



void letStart(){
	int decision;
	do{
	system("cls");
	cout<<"WELCOME TO MY BANK"<<endl<<endl;
	cout<<"MAIN MENU"<<endl;
	cout<<"_______________"<<endl;
	cout<<"01. NEW ACCOUNT"<<endl;
	cout<<"02. DEPOSIT AMOUNT"<<endl;
	cout<<"03. WITHDRAW AMOUNT"<<endl;
	cout<<"04. INVEST MONEY"<<endl;
	cout<<"05. SHOW ALL ACCOUNTS"<<endl;
	cout<<"06. CLOSE AN ACCOUNT"<<endl;
	cout<<"07. SATISFACTION TEST"<<endl;
	cout<<"08. EXIT"<<endl;
	cin>>decision;
	system("cls");
	
	switch(decision){
	case 1: 			
		create_Account(); //Taking infos here	
		break;
		
	case 2:
		
		showMoney();
		break;
	case 3:
		WithdrawMoney();
		break;
		
	case 4:
		InvestMoney();
		break;
		
	case 5:
		showAll();
		break;
	
	case 6:
		delete_account();
		break;
		
	case 7:
		supportUs();
		break; 
		
		} //End of switch
	}while(decision!=8);			//8 - Exit Now
	system("cls");
	cout<<"Thank you for using my program..."<<endl;
}





void showMoney(){
		string num;
		cout<<"Enter the Account Number: ";					cin>>num;
		ARUBANK A1;	//Object of my class
		fstream myfile;		//myfile object of fstream
		string line;
		myfile.open("ARUBANK.txt",ios::in);	//for reading,
		if(myfile.is_open()){ //found the file
		do{			
			myfile>>line;
			if(line==num){
			system("cls");
			cout<<setw(18)<<"Account Number"<<setw(18)<<"Account Holder"<<setw(18)<<"Type of Account"<<setw(18)<<"Initial Amount"<<endl;
			cout<<setw(18)<<line<<setw(18);
			myfile>>line; 
			cout<<line<<setw(18);
			myfile>>line;
			cout<<line<<setw(18);
			myfile>>line;
			cout<<line<<endl<<endl<<endl;
			break;
			}//end of if						
		}while(!myfile.eof());
		sleep(4);
		}
		else{ //not found file
			system("cls");
			cout<<"Error! File not found!"<<endl;
		}
		myfile.close();
}



void create_Account(){
		ARUBANK A1;	//Object of my class
		fstream myfile;		//myfile object of fstream
		myfile.open("ARUBANK.txt",ios::out|ios::app);	//append so we can add more
		
		if(myfile.fail()){		//If couldnt open the file
		system("cls");
		cout<<"The file could not be found!\n\n";
		sleep(3);	
		}
		A1.createAccount(); //Taking infos
		myfile<<setw(18)<<"Account Number"<<setw(18)<<"Account Holder"<<setw(18)<<"Type of Account"<<setw(18)<<"Initial Amount"<<endl;
		myfile<<setw(18)<<A1.getAccountNo()<<setw(18)<<A1.getName()<<setw(18)<<A1.getType()<<setw(18)<<A1.getDeposit()<<endl<<endl<<endl;
		myfile.close();
		cout<<"The Account is Successfully Created"<<endl;
		sleep(3);
		myfile.close();
	}
	
	
	
	
void delete_account(){
	ARUBANK A1;
	string num;
	string line;
	fstream inFile;
	fstream myfile;
	inFile.open("ARUBANK.txt",ios::binary|ios::in);
	if(!inFile.is_open())
	{
		cout<<"File could not be open !!"<<endl;
		sleep(3);
	}
	myfile.open("ARUBANK2.txt",ios::binary|ios::out);
	if(!myfile.is_open())
	{
		cout<<"File could not be open !!"<<endl;
		sleep(3);
	}
		cout<<"Enter the Account Number: "; 		cin>>num;

	while(!inFile.eof()){
		inFile>>line;
		if(line==num){
			inFile>>line;
			inFile>>line;
			inFile>>line;
			getline(inFile,line);
		}
		else{
			//myfile<<setw(18)<<"Account Number"<<setw(18)<<"Account Holder"<<setw(18)<<"Type of Account"<<setw(18)<<"Initial Amount";
			myfile<<setw(18)<<line;
			getline(inFile,line);
			myfile<<line<<endl<<endl;
			//inFile>>line;
			//myfile<<line<<setw(18);
			//inFile>>line;
			//myfile<<line<<endl<<endl<<endl;
			
			}//end of if
	}
	inFile.close();
	myfile.close();
	remove("ARUBANK.txt");
	rename("ARUBANK2.txt","ARUBANK.txt");
	/*cout<<"Record Deleted .."<<endl;
	sleep(3);																					*/
}
	
	
	
	
	
void WithdrawMoney(){
		string num;
		int newMoney;
		int withdmoney;
		char *ptr;
		cout<<"Enter the Account Number: ";					cin>>num;
		ARUBANK A1;	//Object of my class
		fstream myfile;		//myfile object of fstream
		string line;
		myfile.open("ARUBANK.txt",ios::in);	//for reading,
		if(myfile.is_open()){ //found the file
			cout<<"Enter how many dolar you want to withdraw: ";				cin>>withdmoney;
		do{			
			myfile>>line;
			if(line==num){
			system("cls");
			myfile>>line;	//holder name
			myfile>>line;	//type of account
			myfile>>line;	//money
			for(int i=0;i<line.size();i++)
				ptr[i]=line[i];
			newMoney=atoi(ptr);
			if(withdmoney<=newMoney){
				cout<<"Your withdraw "<<newMoney<<" dolar."<<endl;
				sleep(4);
				break;	
			}
			//else if(newMoney.size()>line.size()){
			//	cout<<"ERROR! \n Not suitable amount for withdraw"<<endl;
			//	} //end of else
			}//end of if						
		}while(!myfile.eof());
		sleep(4);
		}
		else{ //not found file
			system("cls");
			cout<<"Error! File not found!"<<endl;
		}
		myfile.close();
	}



void InvestMoney(){
		string num;
		float newMoney;
		cout<<"Enter the Account Number: ";					cin>>num;
		ARUBANK A1;	//Object of my class
		fstream myfile;		//myfile object of fstream
		string line;
		myfile.open("ARUBANK.txt",ios::in);	//for reading,
		if(myfile.is_open()){ //found the file
			cout<<"Enter how many dolar you want to invest: ";				cin>>newMoney;
		do{			
			myfile>>line;
			if(line==num){
			system("cls");
			myfile>>line;	//holder name
			myfile>>line;	//type of account
			myfile>>line;	//money
			if(newMoney>=0){
				cout<<"Your invest "<<newMoney<<" dolar."<<endl;
				sleep(4);
				break;	
			}

			}//end of if						
		}while(!myfile.eof());
		sleep(4);
		}
		else{ //not found file
			system("cls");
			cout<<"Error! File not found!"<<endl;
		}
		myfile.close();
	}
	
	
	
	
	
	
void showAll(){		
		ARUBANK A1;	//Object of my class
		fstream myfile;		//myfile object of fstream
		string line;
		string password;
		myfile.open("ARUBANK.txt",ios::in);	//for reading,
		cout<<"Enter the password: ";			cin>>password;
		if(password=="MUSTAFA" || password=="mustafa"){
		if(myfile.is_open()){ //found the file
		do{	
		//cout<<endl;
		getline(myfile,line);
		cout<<line<<endl;				
		}while(!myfile.eof());
		sleep(9);
		}
		else{ //not found file
			system("cls");
			cout<<"Error! File not found!"<<endl;
		}
		myfile.close();
	}
	}
	
	
	
	
	
	void supportUs(){
		int note1;
		cout<<"The branch staff have the required skills and knowledge about the bank’s products and services: [1/5] ";		cin>>note1;	
		int note2;
		cout<<"The branch staff are friendly and behave in a courteous manner when dealing with you: [1/5] ";			cin>>note2;
		int note3;
		cout<<"The branch staff are professional and have a pleasing and presentable appearance: [1/5] ";			cin>>note3;
		int note4;
		cout<<"The branch staff are willing to listen and respond to your needs on time: [1/5] ";			cin>>note4;
		int note5;
		cout<<"Overall, I am satisfied with the branch staff: [1/5] ";			cin>>note5;
		system("cls");
		cout<<"Thank you for giving feed back. "<<endl;
		int totalNote=note1+note2+note3+note4+note5;
		if(totalNote>=10){
			cout<<"Your total vote is "<<totalNote<<endl<<"We have been dealing with being better bank with your customer satisfaction."<<endl;
		}
		sleep(7);
	}
