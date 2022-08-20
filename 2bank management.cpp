#include<iostream> //final
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cstring>
using namespace std;

class account
{
	int acno;
	char name[50];
	char email[30];
	char pass[12];
	char address[200];
	long double amt;
	char phone[20];
public:
	static int n;
	void create_account();
	void show_account();
	void modify();
	void dep(long double);
	void draw(long double);
	void show();
	int retacno();
	long double retamt();
	char* p();
	void balance();
};
int account::n=0;
void account::balance() {
cout<<"\nName: "<<name;
cout<<"\nAccount number: "<<acno;
cout<<"\nRemaining balance: "<<amt;	
}
void account::create_account() {	
	fstream file; account ac;string d;
	file.open("account.bin",ios::binary|ios::in);
	file.seekg(0, ios::end);  
	if (file.tellg() == 0) 
		{acno=1000; }
	else { 
	file.seekg(0,ios::beg);
	while(file.read(reinterpret_cast<char*>(&ac), sizeof(account)))
	{	
		if(ac.retacno()>1000 )
			{	acno=ac.retacno(); }  
		if(ac.retacno()==1000)
			{ n=1; acno=1000; }
	}  
	}	
	acno=acno+n; 
	cout<<"\nEnter the Name: ";
	cin.sync();
	cin.getline(name,50);
con:{cout<<"\nEnter contact number: ";
	cin.sync();
	cin.getline(phone,20); }
	for(int i=0;i<strlen(phone);i++)
	{	
		if(phone[i]>=48 && phone[i]<=57)
		{
			if(strlen(phone)>10 || strlen(phone)<10)
				{ cout<<"\nContact number must have 10 digits(from 0-9).";goto con; }
			if(strlen(phone)==10){
				if(phone[0]=='0'){
					cout<<"\nFirst digit cannot be zero";goto con;}
			}
		}
		else
		   {cout<<"\nEnter digits from 0 to 9"; goto con; }
	}
	cout<<"\nEnter address: ";
	cin.sync();
	cin.getline(address,200);
amo:{amt=0;string st; 
	cout<<"\nEnter initial deposit amount: "; 
	while(getline(cin,st)){
		stringstream ss(st);
		if(ss>>amt){
			if(ss.eof()){
				break;
			}
		}
		cout<<"\nEnter only numbers";
		goto amo;
	}
	if(amt<1000) 
		{cout<<"\nMinimum initial deposit is Rs.1000"; goto amo; } 
    else
    	goto em;
    }
em:{	bool ch1=false,fo1=false;
	cout<<"\nEnter email: "; 
	cin.sync();
	cin.getline(email,30); 
	for(int i=0;i<strlen(email);i++)
    {	
    	if(email[i]=='@')
    		ch1=true;
    	if(email[i]=='.')
    	fo1=true;
    	if(email[i]==' ')
    	{cout<<"\nEmail cannot have spaces";goto em;}
    }
    if(fo1==true && ch1==true){
    		if( !((email[0]>='a' && email[0]<='z') || (email[0]>='A' && email[0]<='Z') ) )
   				{cout<<"\nFirst digit must be an alphabet";goto em;}	
    }
    else
    {cout<<"\nMust contain @ and .";goto em;}
}
pass:{	cout<<"\nEnter password(not more than 8 characters): ";
	cin.sync();
	cin.getline(pass,12); }
	if(strlen(pass)>8)
	{cout<<"\nPassword character limit reached.";goto pass;}
	cout<<"\nAccount created successfully."<<"\nYour account number is "<<acno;
	++n;
}
void account::show_account() {
	cout<<"\nAccount number: "<<acno;
	cout<<"\nName: "<<name;
	cout<<"\nContact number: "<<phone;
	cout<<"\nAddress: "<<address;
	cout<<"\nCurrent balance: "<<amt;
	cout<<"\nEmail: "<<email;
	cout<<"\nPassword: "<<pass;
} 
void account::show()  {
	cout<<left<<setw(10)<<setfill(' ')<<acno<<left<<setw(20)<<setfill(' ')<<name<<left<<setw(15)<<setfill(' ')<<phone<<left<<setw(20)<<setfill(' ')<<amt<<left<<setw(30)<<setfill(' ')<<address<<left<<setw(20)<<setfill(' ')<<email<<endl;
}
void account::modify() {	
	int op,b;string str,str1;
	label1: {
	cout<<"\nPress the corresponding number key to update credentials:";
	cout<<"\n1-Name"<<"\n2-Contact"<<"\n3-Address"<<"\n4-Email"<<"\n5-Password\n";
	while(getline(cin, str))
		{
			stringstream ss(str);
			if(ss >> op)
			{
				if(ss.eof())
				{
					break;
				}
			}
			cout<<"\nEnter correct option";
			goto label1;
		}
	switch(op) {
	case 1:{
		cout<<"\nEnter new name: ";cin.sync();cin.getline(name,50);break;
	}
	case 2: {
number:{		cout<<"\nEnter new contact: ";cin.sync();cin.getline(phone,12); }
		for(int i=0;i<strlen(phone);i++)
	{	
		if(phone[i]>47 && phone[i]<58)
		{
			if(strlen(phone)>10 || strlen(phone)<10)
				{ cout<<"\nContact number must have 10 digits(from 0-9).";goto number; }
			if(strlen(phone)==10){
				if(phone[0]=='0'){
					cout<<"\nFirst digit cannot be zero";goto number;}
			}
		}
		else
		   {cout<<"\nEnter digits from 0 to 9"; goto number; }
	}
		break;
	}
	case 3: {
		cout<<"\nEnter new address: ";cin.sync();cin.getline(address,200);break;
	}
	case 4: {
emm:{	bool ch1=false,fo1=false;
		cout<<"\nEnter new email: ";cin.sync();cin.getline(email,30); 
		for(int i=0;i<strlen(email);i++)
    {	
    	if(email[i]=='@')
    		{ch1=true;}
    	if(email[i]=='.')
    	{fo1=true;}
    	if(email[i]==' ')
    	{cout<<"\nEmail cannot have spaces";goto emm;}
    }
    	if(fo1==true && ch1==true){
    		if(!( (email[0]>='a' && email[0]<='z') || (email[0]>='A' && email[0]<='Z') ))
			{cout<<"\nFirst digit must be an alphabet";goto emm;}
		}
	    else
	    {cout<<"\nMust contain @ and .";goto emm;}
	}
	break;
	}
	case 5: {
pas:{		cout<<"\nEnter new password: ";cin.sync();cin.getline(pass,12); }
		if(strlen(pass)>8)
		{cout<<"\nPassword character limit reached.";goto pas;}
		break;
	}
	default: { cout<<"\nEnter correct number"; goto label1; break;}
	}
again:{	cout<<"\nPress 0 to update more credentials else any other number to return to menu- "; }
	while(getline(cin, str1))
		{
			stringstream ss(str1);
			if(ss >> b)
			{
				if(ss.eof())
				{
					break;
				}
			}
			cout<<"\nEnter correct number";
			goto again;
		}
	if(b==0)
		goto label1;
	else
		return;
	}
}
void account::dep(long double x){
	amt+=x;   }
void account::draw(long double x){
	amt-=x;	}
int account::retacno() {
	return acno; }
char* account::p(){
	return pass; }
long double account::retamt() {
	return amt; }

void bal(int);
void write_account();
void display(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int,int);
int admin(string);
int check(int,string);

int main() {
	int i=0,c; string a,pwd; string str;
	int num;
	cout<<"===============\n";
	cout<<"BANK MANAGEMENT\n";
	cout<<"===============\n";
	label:	
	{
		cout<<"\n\n1. Create account\n";
		cout<<"2. Deposit amount\n";
		cout<<"3. Withdraw account\n";
		cout<<"4. Balance enquiry\n";
		cout<<"5. View account holders list(admin access only)\n";
		cout<<"6. Close/Delete an account\n";
		cout<<"7. Update account credentials\n";
		cout<<"8. Show account details\n";
		cout<<"9. Exit program\n";
		cout<<"Select Your Option (1-9): "; 
		cin.clear(); 
		while(getline(cin, str))
		{
			stringstream ss(str);
			if(ss >> i)
			{
				if(ss.eof())
				{
					break;
				}
			}
			cout<<"\nEnter correct option(number only)!";
			goto label;
		}
		if(i>0 && i<10){
		switch(i)
		{
		case 1: { 
			write_account();
			goto label;
			break;
		}
		case 2: {
en:{			cout<<"\nEnter account number: ";}
			while(getline(cin, str))
		{
			stringstream ss(str);
			if(ss >> num)
			{
				if(ss.eof())
				{
					break;
				}
			}
			cout<<"\nERROR!";
			goto en;
		}
			cout<<"\nEnter password: "; cin.sync();getline(cin,pwd);
			c=check(num,pwd);
			if(c==2)
				{deposit_withdraw(num,1);goto label;}
			if(c==0)
			{	cout<<"\nAccount doesn't exist"; goto en;}
			if(c==1)
			{cout<<"\nPassword is wrong.Fill details again.";goto en;} 
			break;
		}
		case 3: {
ent:{			cout<<"\nEnter account number: "; }
			while(getline(cin, str))
		{
			stringstream ss(str);
			if(ss >> num)
			{
				if(ss.eof())
				{
					break;
				}
			}
			cout<<"\nEnter correct number";
			goto ent;
		}
			cout<<"\nEnter password: "; cin.sync();getline(cin,pwd);
			c=check(num,pwd);
			if(c==2)
				{deposit_withdraw(num,2); goto label;}
			if(c==0)
			{	cout<<"\nAccount doesn't exist";goto ent;}
			if(c==1)
			{cout<<"\nPassword is wrong.Fill details again.";goto ent;}
			break;
		}
		case 4: {
ente:{			cout<<"\nEnter account number: "; }
			while(getline(cin, str))
		{
			stringstream ss(str);
			if(ss >> num)
			{
				if(ss.eof())
				{
					break;
				}
			}
			cout<<"\nERROR!";
			goto ente;
		}
			cout<<"\nEnter password: "; cin.sync();getline(cin,pwd);
			c=check(num,pwd);
			if(c==2)
				{bal(num);goto label;}
			if(c==0)
			{	cout<<"\nAccount doesn't exist";goto ente;}
			if(c==1)
			{cout<<"\nPassword is wrong.Fill the details again.";goto ente;}
			break;
		}
		case 5:{
			cout<<"\nEnter password-";
			cin.sync();
			getline(cin,a);
			c=admin(a);
			if(c==1)
				display_all();
			else
				cout<<"\nWrong password";
			goto label;	
			break;
		}
		case 6:{
			int con;
six:{			cout<<"\nEnter account No. : "; }
			while(getline(cin, str))
		{
			stringstream ss(str);
			if(ss >> num)
			{
				if(ss.eof())
				{
					break;
				}
			}
			cout<<"\nERROR!";
			goto six;
		}
			cout<<"\nEnter password: "; cin.sync();getline(cin,pwd);
			c=check(num,pwd);	
			if(c==2)
			{	ccc:{
				cout<<"\nPress 1 to confirm else any other number to return to menu-"; }
				while(getline(cin, str))
				{
					stringstream ss(str);
					if(ss >> con)
					{
						if(ss.eof())
						{
							break;
						}
					}
					cout<<"\nEnter only number";
					goto ccc;
				}
				if(con==1)
				{delete_account(num); goto label;}
				else
				{goto label;}
			}
			if(c==0)
			{	cout<<"\nAccount doesn't exist";goto six;}
			if(c==1)
			{cout<<"\nPassword is wrong.Fill details again.";goto six;}
		
		break;
		}
		 case 7: {
seven:{			cout<<"\nEnter account number: "; }
			while(getline(cin, str))
		{
			stringstream ss(str);
			if(ss >> num)
			{
				if(ss.eof())
				{
					break;
				}
			}
			cout<<"\nEnter correct account number";
			goto seven;
		}
			cout<<"\nEnter password: "; cin.sync();getline(cin,pwd);
		 	c=check(num,pwd);
		 	if(c==2)
				{modify_account(num); goto label;}
			if(c==0)
				{cout<<"\nAccount doesn't exist";goto seven;}
			if(c==1)
				{cout<<"\nPassword is wrong.Fill details again";goto seven;}
			break;
		}
		 case 8:{
eight:{		 	cout<<"\nEnter account number: "; }
		 	while(getline(cin, str))
		{
			stringstream ss(str);
			if(ss >> num)
			{
				if(ss.eof())
				{
					break;
				}
			}
			cout<<"\nEnter numbers only!";
			goto eight;
		}
		 	cout<<"\nEnter password: "; cin.sync();getline(cin,pwd);
		 	c=check(num,pwd);
		 	if(c==2)
				 {display(num); goto label;}
			if(c==0)
			{	cout<<"\nAccount doesn't exist";goto eight;}
			if(c==1)
			{cout<<"\nPassword is wrong.Fill details again.";goto eight;}
		break;
		 	}
		case 9:{
			return 0;
		}
		}
	}
		else
			{cout<<"\nEnter correct option";
			goto label;}
}
}
void bal(int n){
	account ac; fstream file;
	file.open("account.bin",ios::binary|ios::in);
	if(!file)
		cout<<"\nFile could not be opened.";
	while(file.read(reinterpret_cast<char*>(&ac),sizeof(ac)))
	{
		if(ac.retacno()==n)
		{	cout<<"\nBALANCE DETAILS\n";
			ac.balance();
		}
	}
    file.close();
}
int check(int n,string p) {
	account ac;
	char a[p.length()+1]; bool flag=false;bool check=false;
    for(int i = 0; i < sizeof(a); i++) 
        a[i] = p[i];
    fstream file;
	file.open("account.bin",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\nFile could not be opened.";
	}
    	while(file.read(reinterpret_cast<char*>(&ac),sizeof(ac)))
	{       
		if(ac.retacno()==n)
		{	check=true;
			if(strcmp(a,ac.p())==0)	
				{flag=true; }
		}
	}
	if(check==false && flag==false)
		return 0;
	if(check==true && flag==false)
		return 1;
	if(check==true && flag==true)
		return 2;
	file.close();
}
void write_account() {
	account ac;
	ac.create_account();
	fstream ifile("account.bin",ios::binary|ios::out|ios::app);
	if(!ifile){
		cout<<"Error in creating file\n";
	}
	ifile.write((char*)(&ac),sizeof(ac));
	ifile.close();
}
int admin(string s) {
	string adminp="kash";
	int r=adminp.compare(s);
	if(r==0)
		return 1;
	else 
		return 0;
}
void display(int n) {
	account ac;
	fstream file;
	file.open("account.bin",ios::binary|ios::in);
	if(!file)
		cout<<"\nFile could not be opened.";
	while(file.read(reinterpret_cast<char*>(&ac),sizeof(ac)))
	{
		if(ac.retacno()==n)
		{	cout<<"\nACCOUNT DETAILS\n";
			ac.show_account();
		}
	}
    file.close();
} 
void modify_account(int n) {
	bool found=false;
	account ac;
	fstream File;
    File.open("account.bin",ios::binary|ios::in|ios::out);
	if(!File)
		cout<<"File could not be opened";
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur); 
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\nCredential Updated";
		    found=true;
		  }
	}
	File.close();
}
void delete_account(int n) {
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.bin",ios::binary);
	if(!inFile)
		cout<<"\nFile could not be opened.";
	outFile.open("Temp.bin",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.bin");
	rename("Temp.bin","account.bin");
	cout<<"\nAccount Deleted!";
}
void display_all() {
	account a; bool check=false;
	fstream rfile("account.bin",ios::binary|ios::in);
	if(!rfile)
		cout<<"\nFile not found!";
	else {
	rfile.seekg(0, ios::end);  
	if (rfile.tellg() == 0) 
		{cout<<"\nNo record found";return; }
	else
		check=true;
	rfile.close();
	}
	if(check==true) {
	fstream file("account.bin",ios::binary|ios::in);
	cout<<"=======================================================================================================\n";
	cout<<"A/c no.   NAME                Phone          Amount              Address                      Email\n";
	cout<<"=======================================================================================================\n";
	while(file.read(reinterpret_cast<char*>(&a),sizeof(account)))
	{
			a.show();cout<<"\n";
	}
	file.close();
	}
} 
void deposit_withdraw(int n,int option) 
{	long double amt=0; bool f=false; account ac; fstream file;string st;
    file.open("account.bin", ios::binary|ios::in|ios::out);
	if(!file)
		cout<<"File not found!";
	while(!file.eof() && f==false)
	{	
		file.read(reinterpret_cast<char*>(&ac), sizeof(ac));
		if(ac.retacno()==n)
		{
			if(option==1)
			{ 
			dep:{	cout<<"\nEnter the amount to be deposited: ";}
			while(getline(cin,st)){
				stringstream ss(st);
				if(ss>>amt){
					if(ss.eof()){
						break;
					}
				}
				cout<<"\nEnter only numbers";
				goto dep;
				}
			ac.dep(amt);
			ac.show_account();
			}
		    if(option==2)
			{
			wit:{	cout<<"\nEnter the amount to be withdraw: ";}
			while(getline(cin,st)){
				stringstream ss(st);
				if(ss>>amt){
					if(ss.eof()){
						break;
					}
				}
				cout<<"\nEnter only numbers";
				goto wit;
			}
			long double bal=ac.retamt()-amt; 
			if(bal<0)
				{cout<<"\nInsufficience balance"; break;  }
			else
			{ ac.draw(amt); ac.show_account();}
	    	}
	    	int pos=(-1)*static_cast<int>(sizeof(ac));
			file.seekp(pos,ios::cur);
			file.write(reinterpret_cast<char *>(&ac), sizeof(ac));
			cout<<"\nAmount Updated";
			f=true;
		}
    }
    file.close();
}

