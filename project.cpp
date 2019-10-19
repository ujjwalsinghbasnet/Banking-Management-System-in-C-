#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstring>
using namespace std;
//Global Variables
//************************************************************//
	int count = 0;
	int count1 = 0;
//************************************************************//
//Global Variables




//class for accounting
//************************************************************//
	
class createAccnt   //This class is for creating account
{
	private:
			string name, password,address,Name;
			int acc_num;
			char citizenship_No[20], DOB[13];
			float deposit;
			

	public:
		int createAcc();
		int edit_acnt();
		int withdraw();	
		int deposition();
		int read_data();
		int transfer();	
};


//************************************************************//
//creating account
int createAccnt::createAcc()  //this is method for the class create account
{
home1:
	string username;
	ofstream passw0rd;
	passw0rd.open("password.txt",ios::app);
	system("cls");
	cout<<"\t"<<"\t"<<"\t"<<"Create an Account"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"*****************"<<endl<<endl<<endl<<endl;
//	cout<<"Account number of the client:";
//	cin>>acc_num;
	cout<<"Choose Username for your account: ";
	cin>>username;

	//
				ofstream file;
				ofstream file1;
				file.open((username + "-details").c_str());	
				file1.open((username + "-amount").c_str());
				cout<<"Choose your password: ";
				cin>>password;
				passw0rd<<password<<endl;
				cout<<endl<<endl<<endl;
				cout<<"Enter Personal Details:"<<endl;
				cout<<"Name: ";
				cin>>Name;
				cout<<"DOB: ";
				cin>>DOB;
				cout<<"Citizenship Numnber: ";
				cin>>citizenship_No;
				cout<<"Deposition Amount: ";
				cin>>deposit;
				cout<<"Address: ";
				cin>>address;
				file1<<deposit;
				ofstream details;
				details.open("username.txt",ios::app);
				details<<username<<endl;
				file<<Name<<"\t"<<address<<"\t\t"<<citizenship_No<<"\t\t\t"<<DOB;
				cout<<"\t\tAccount Successfully created!!";
				file1.close();
				file.close();
			}	
		
	
	

//creating account
//************************************************************//


//#################################################################################################################################################//


//************************************************************//
//editing account

int createAccnt::edit_acnt() //this is for editing account
{
	string logUsername, log_pass;
	system("cls");
	cout<<"\t"<<"\t"<<"\t"<<"Edit an Account"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"*****************"<<endl<<endl<<endl<<endl;
	cout<<"\t\t"<<"Enter username of the account: ";
	cin>>logUsername;
	cout<<endl;
	cout<<"\t\t"<<"Enter the password of the account: ";
	cin>>log_pass;
	cout<<endl;
		
ifstream user;		
ifstream pass;
string name;
user.open("username.txt");
pass.open("password.txt");	
if(!user|| !pass)
{
	cout<<"Unable to open file.";
}
else
{
	while(getline(user,name))
		{
			if(logUsername.compare(name)==0)
			{	
				while(getline(pass,password))
				{
					if(log_pass.compare(password)==0&&count==count1)
					{
						system("cls");
						char name[20],address[20],dob[20];
//						int l = strlen(name);
//						int m = strlen(address);
//						int n = strlen(dob);
						
						cout<<"\t"<<"\t"<<"\t"<<"Edit an Account"<<endl;
						cout<<"\t"<<"\t"<<"\t"<<"*****************"<<endl<<endl<<endl<<endl;
						cout<<"\t\tEnter new details for your account: "<<endl<<endl;
						cout<<"\t\tName: ";
						cin>>name;
						cout<<"\t\tAddress: ";
						cin>>address;
						cout<<"\t\tDOB: ";
						cin>>dob;
						ofstream file;
						file.open((logUsername + "-details").c_str(),ios::out);
						file<<name<<"\t"<<address<<"\t"<<dob;	
						cout<<"Records have been updated."<<endl;
					}

					count1++;
				}
			}
			count++;
		}
		user.close();
		pass.close();
}
	
}
//editing account closed
//************************************************************//


//#################################################################################################################################################//


//************************************************************//
//displaying account details 

int createAccnt::read_data()
{
	string info;
	char item[300];
	string viewacnt;
	system("cls");
	cout<<"\t"<<"\t"<<"\t"<<"View Records"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"************"<<endl<<endl<<endl<<endl;
	cout<<"\t\tUsername of the account holder: ";
	cin>>viewacnt;
	ifstream user;	
	user.open("username.txt");
	while(getline(user,info))
		{
			if(viewacnt.compare(info)==0)
			{	
				ifstream readacnt;
				ifstream amnt;
				amnt.open((viewacnt + "-amount").c_str(),ios::in);
				readacnt.open((viewacnt + "-details").c_str(),ios::in);
				cout<<endl<<endl<<"\t\tThe Details Of The User Are: "<<endl;
				cout<<endl<<endl<<"\t\tName\tAddress\t\tCitizenship_No\t\tDOB"<<endl;
				while(!readacnt.eof())
					{
						readacnt.getline(item,200);	
						cout<<"\t\t"<<item;		
					}
				readacnt.close();
				int s;
				cout<<endl<<endl<<endl<<"\t\tThe total balance is: Rs. ";
				while(!amnt.eof())
				{
					amnt>>s;
					cout<<s;
				}
			}	
		}
}
//displaing closed
//************************************************************//


//#################################################################################################################################################//


//for withdraw option
//***********************************************************//

int createAccnt::withdraw()
{
	string with_name;
	string with_pass;
	system("cls");
	cout<<"\t"<<"\t"<<"\t"<<"Withdraw Amount"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"***************"<<endl<<endl<<endl<<endl;
	cout<<"\t\tEnter the Username of the account: ";
	cin>>with_name;
	cout<<endl<<"\t\tEnter the password for verification: ";
	cin>>with_pass;
	ifstream with;		
	ifstream draw;

with.open("username.txt");
draw.open("password.txt");	
if(!with|| !draw)
{
	cout<<"Unable to open file.";
}
else
{
	while(getline(with,name))
		{
			if(with_name.compare(name)==0)
			{	
				while(getline(draw,password))
				{
					if(with_pass.compare(password)==0&&count==count1)
					{
						int s;
						int t,result;
						system("cls");
						cout<<"\t"<<"\t"<<"\t"<<"Withdraw Amount"<<endl;
						cout<<"\t"<<"\t"<<"\t"<<"***************"<<endl<<endl<<endl<<endl;
						ifstream withdrawing;
						withdrawing.open((with_name + "-amount").c_str(),ios::in);
						while(!withdrawing.eof())
						{
							withdrawing>>s;
							cout<<"\t\tYou have Rs. "<<s<<" in your account."<<endl<<endl;
							cout<<"\t\tAmount to be withdrawn: ";
							cin>>t;	
							if(s>=t)
							{
								result = s -t;
								ofstream writing;
								writing.open((with_name + "-amount").c_str(),ios::out);
								cout<<endl<<endl<<endl<<"\t\t\tWithdrawn Successful!!";
								writing<<result;
								cout<<endl<<"\t\tYour current balance is: "<<result;
							}
							else
							{
								cout<<endl<<"\t\tYou don't have enough money.";
							}	
						}
						withdrawing.close();	
					}
					count1++;
				}
			}
			count++;
		}
	}	
}
//withdraw option closed
//***********************************************************//



//#############################################################################################################################################################//


//deposit option
//************************************************************//

int createAccnt::deposition()
{
	string dep_name;
	string dep_pass;
	system("cls");
	cout<<"\t"<<"\t"<<"\t"<<"Deposit Amount"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"**************"<<endl<<endl<<endl<<endl;
	cout<<"\t\tEnter the Username of the account: ";
	cin>>dep_name;
	cout<<endl<<"\t\tEnter the password for verification: ";
	cin>>dep_pass;
	ifstream dep;		
	ifstream osit;

dep.open("username.txt");
osit.open("password.txt");	
if(!dep|| !osit)
{
	cout<<"Unable to open file.";
}
else
{
	while(getline(dep,name))
		{
			if(dep_name.compare(name)==0)
			{	
				while(getline(osit,password))
				{
					if(dep_pass.compare(password)==0&&count==count1)
					{
						int s;
						int t,result;
						
						system("cls");
						cout<<"\t"<<"\t"<<"\t"<<"Deposit Amount"<<endl;
						cout<<"\t"<<"\t"<<"\t"<<"**************"<<endl<<endl<<endl<<endl;
						ifstream depositing;
						depositing.open((dep_name + "-amount").c_str(),ios::in);
						while(!depositing.eof())
						{
							depositing>>s;
							cout<<"\t\tYou have Rs. "<<s<<"in your account."<<endl<<endl;
							cout<<"\t\tAmount to be deposited: ";
							cin>>t;	
								result = s + t;
								ofstream writing;
								writing.open((dep_name + "-amount").c_str(),ios::out);
								writing<<result;
								cout<<endl<<endl<<endl<<"\t\t\tSuccessfully Deposited!!";
								cout<<endl<<setw(40)<<"\t\tYour current balance is: "<<result;
								
						}
						depositing.close();	
					}
					count1++;
				}
			}
			count++;
		}
	}	
}

//deposit option closed
//************************************************************//


//***********************************************************//
//transfer option closed

int createAccnt::transfer()
{
	string trans_name;
	string trans_pass;
	system("cls");
	cout<<"\t"<<"\t"<<"\t"<<"Transfer Amount"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"**************"<<endl<<endl<<endl<<endl;
	cout<<"\t\tEnter the Username of the account: ";
	cin>>trans_name;
	cout<<endl<<"\t\tEnter the password for verification: ";
	cin>>trans_pass;
	ifstream tran;		
	ifstream sfer;

tran.open("username.txt");
sfer.open("password.txt");	
if(!tran|| !sfer)
{
	cout<<"Unable to open file.";
}
else
{
	while(getline(tran,name))
		{
			if(trans_name.compare(name)==0)
			{	
				while(getline(sfer,password))
				{
					if(trans_pass.compare(password)==0&&count==count1)
					{
						int s;
						string dest_name;
						int t,result,dest_amnt;	
						int trans_amount;
						system("cls");
						cout<<"\t"<<"\t"<<"\t"<<"Transfer Amount"<<endl;
						cout<<"\t"<<"\t"<<"\t"<<"**************"<<endl<<endl<<endl<<endl;
						ifstream transferring;
						transferring.open((trans_name + "-amount").c_str(),ios::in);
						while(!transferring.eof())
						{
							transferring>>s;
							cout<<"\t\tYou have Rs. "<<s<<"in your account."<<endl<<endl;
							cout<<"\t\tAmount to be transferred: ";
							cin>>t;
							cout<<"\t\tUsername of the destination account: ";
							cin>>dest_name;	
								result = s - t;
								ofstream writing;
								writing.open((trans_name + "-amount").c_str(),ios::out);
								writing<<result;
								cout<<endl<<"\t\tTransfer Successful!!";
								cout<<endl<<"\t\tYour current balance is: "<<result;
								ifstream destination;
								destination.open((dest_name + "-amount").c_str(),ios::in);
								while(!destination.eof())
									{
										transferring>>dest_amnt;
											
									}
								ofstream transferred;
								transferred.open((dest_name + "-amount").c_str(),ios::out);
								trans_amount=dest_amnt+t;
								transferred<<trans_amount;
								destination.close();
								transferred.close();		
						}
						transferring.close();	
					}
					count1++;
				}
			}
			count++;
		}
	}	
}


//transfer option closed
//***********************************************************//


//##########################################################################################################################################################//
//main menu for the selection of various options
//***********************************************************//
int main_menu()
{
home:
	int num;
	int ch;
	system("cls");
	createAccnt s1;
	cout<<"\t"<<"\t"<<"\t"<<"Bank Management System"<<endl;
	cout<<"\t"<<"\t"<<"\t"<<"**********************"<<endl<<endl<<endl<<endl;
	cout<<"\t"<<"1. Create Account"<<endl;
//	cout<<"\t"<<"2. Delete Account"<<endl;
	cout<<"\t"<<"2. Edit Account"<<endl;
//	cout<<"\t"<<"4. Transaction"<<endl;
	cout<<"\t"<<"3. View List"<<endl;
	cout<<"\t"<<"4. Withdraw Balance"<<endl;
	cout<<"\t"<<"5. Deposit Balance"<<endl;
	cout<<"\t"<<"6. Transfer Balance"<<endl<<endl;	
	cout<<"Choose your choice number:";
	cin>>num;
	switch(num)
		{
			case 1:
				s1.createAcc();
				break;
			case 2:
				s1.edit_acnt();
				break;			
			case 3:
				s1.read_data();
				break;
			case 4:
				s1.withdraw();
				break;
			case 5:
				s1.deposition();
				break;
			case 6:
				s1.transfer();
				break;
		}
	cout<<setw(55)<<endl<<endl<<endl<<"*************************************"<<endl;
	cout<<"\t\t\tDo you want to continue??"<<endl;
	cout<<"\t\t\tPress 1 to continue";
	cin>>ch;
	if(ch==1)
	{
		goto home;
	}		
		
}

//main menu closed
//************************************************************//


//#################################################################################################################################################//


int main()
{
	char enter;
	cout<<"\t\t\tBANKING MANAGEMENT SYSTEM"<<endl;
	cout<<"\t\t\tA mini project in C++"<<endl;
	cout<<setw(55)<<"*************************************"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(55)<<"*************************************"<<endl;
	cout<<setw(55)<<"Press 'Enter' to continue.......";
	enter=fgetc(stdin);    //get the single caracter
	if (enter==10)
	{
		main_menu();
	}
}
