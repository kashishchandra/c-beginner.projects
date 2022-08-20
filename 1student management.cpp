#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cstring>
#include<limits>
using namespace std;

struct std_data
{	
	
	string name;
	short roll_no;
	char section;
	int level;	
	float marks[5];			
};

int main ()
{   
    std_data e[100]; int confirm;
    int roll;
	string ch;
	char sec;
	float sum;
	int counter=0;
	char k;
	int count=0;
	int enter;
	int p=0;
label:{		int y=0;
			cout<<"------------------------------------------\n"<<"Operations\n"<<"------------------------------------------\n"<<"Press 1 to enter new record " <<"\n"<<"Press 2 to modify existing record " <<"\n"<<"Press 3 to delete specific student's data "<<"\n"<<"Press 4 to delete all data: "<<"\n"<<"Press 5 to show data of student: "<<"\n"<<"Press 6 to show all data: "<<"\n"<<"------------------------------------------\n"<<"\nEnter number b/w 1-6 to perform action: ";      			
			
			while(!(cin >> enter))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. \a  Try again: ";
			}
			if((enter<1)||(enter>6))
			{ cout<<"Enter proper number: \a ";	goto label;}
			switch(enter)
			{
				case 1:
				{	
					
				{	while(counter<100)
					{	if(y==0)
						
						{		
							
							y=1;
						level:
								cout<<"\nEnter class:: ";
								
										while(!(cin >> e[counter].level))
													{
														cin.clear();
														cin.ignore(numeric_limits<streamsize>::max(), '\n');
														cout << "Invalid input. \a  Try again: ";
													}
								if((e[counter].level<=12)&&(e[counter].level>0))
								{
								}
								else
								{	cout<<"INVALID CLASS!!!   Please re-enter class:\a";
									
									goto level;
								}
								
						section:	cout<<"\nEnter section:: ";
							cin.sync();
							
							string str;
							
							cin>>str;
							char ch[str.length()];
							if(str.length()==1)
							{
							//char ch[str.length()];
							for (int i = 0; i < sizeof(ch); i++) 
							{
								ch[i] = str[i];
							}
							}
							else{
								cout<<"invalid section entered: \a"; goto section;
								
							}
							if( ((ch[0]>64)&&(ch[0]<91))|| ((ch[0]>96)&&(ch[0]<123))  )
							{
								e[counter].section=ch[0];
							}
							else
							{	cout<<"Please enter proper section ...!!! \a"; goto section;}
	
	
					    roll:	cout<<"\nEnter Roll number of student::  ";
							cin.sync();
							
							 while(!(cin >> roll))
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input. \a  Try again: ";
							}
							cin.ignore(1,'\n');
							for(int j=0;j<count;j++)
						
							{	
								if(e[j].roll_no==roll)
								{
										cout<<"\nROLL NUMBER ALREADY EXIST\a";
										
								goto roll;
										
								}
							}
							e[counter].roll_no=roll;
							
							
							
							cout<<"\nEnter name of student::  ";
							cin.sync();
							getline(cin,e[counter].name);
							
							
							{
								for(int j=0;j<5;j++)
								{	
									marks1:	cout<<"\nEnter marks(out of 100) of subject "<<j+1<<"  :";
										while(!(cin >> e[counter].marks[j]))
										{
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											cout << "Invalid input.  Try again: ";
										}
									if((e[counter].marks[j]<0)||(e[counter].marks[j]>100))
									{
										cout<<"INVALID MARKS!!! please re-enter marks \a";
										goto marks1;
									}
								}
							}
							++count; ++counter;
							cout<<"\n"<<"\nPress 0 to create new record else enter any number to continue ";
							cin>>y;
							
							if(y!=0)
							{
								goto label1;
								break;
							}
					
						}
					}
				}
				label1: {
							cout<<"\n"<<"\n"<<"Press 1 to see the operations menu else enter any number to exit ";
							while(!(cin >> p))
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input. \a  Try again: ";
							}
							
							if(p==1)
							{
								goto label;
								p=0;
							}
							
						}
					break;
				}
				
				
				case 2:
				{	int y=0,z=0,kc;
					if(counter!=0)
					{	kc=1;
							cout<<"\nEnter roll no of data to be edited:: "; cin.clear();
							 while(!(cin >> roll))
									{
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Invalid input. \a  Try again: ";
									}
							for(int i=0;i<100;i++)
							{
								if(roll == e[i].roll_no)
								{	y=1;
									edit:
									{
										int k;
										cout<<"\nPress 1 to edit Name"<<"\n"<<"Press 2 to edit Section"<<"\n"<<"Press 3 to edit Roll no"<<"\n"<<"Press 4 to edit Class"<<"\n"<<"Press 5 to edit marks\n";
										
									while(!(cin >> k))
									{
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Invalid input. \a  Try again: ";
									}
										switch(k)
										{
											case 1: {
													cout<<"Enter new name ";
													cin.sync();
													getline(cin,e[i].name);
													break;  
													}
											case 2: {
												 	
												 section1:	cout<<"Enter new section ";
														cin.sync();
														string str;
														cin>>str;
														char ch[str.length()];
														if(str.length()==1)
														{
															for (int i = 0; i < sizeof(ch); i++) 
															{
																ch[i] = str[i];
															}
														}
														else
														{
															cout<<"invalid section entered: \a"; goto section1;	
														}
														if( ((ch[0]>64)&&(ch[0]<91))|| ((ch[0]>96)&&(ch[0]<123))  )
														{	
															e[counter].section=ch[0];
														}
														else
														{	
															cout<<"Please enter proper section ...!!! \a"; goto section1;
														}
			
													break;
													}
											case 3:{
													cout<<"Enter roll no ";
		
															while(!(cin >> e[i].roll_no))
															{
																cin.clear();
																cin.ignore(numeric_limits<streamsize>::max(), '\n');
																cout << "Invalid input. \a  Try again: ";
															}
													break;
													}
											case 4:{
													level1: cout<<"Enter Class ";
													
															while(!(cin >> e[counter].level))
															{
																cin.clear();
																cin.ignore(numeric_limits<streamsize>::max(), '\n');
																cout << "Invalid input. \a  Try again: ";
															}
															if((e[counter].level<=12)&&(e[counter].level>0))
															{
															}
															else
															{	cout<<"INVALID CLASS!!!   Please re-enter class:\a";
																
																goto level1;
															}
													break;
													}
											case 5:{
												marks:	int sub;
													cout<<"\nWhich subject marks you want to change(1,2,3,4,5)? ";
															while(!(cin >> sub))
															{
																cin.clear();
																cin.ignore(numeric_limits<streamsize>::max(), '\n');
																cout << "Invalid input. \a  Try again: ";
															}
													cout<<"\nEnter new marks ";
													
													 while(!(cin >>e[i].marks[sub-1] ))
													{
														cin.clear();
														cin.ignore(numeric_limits<streamsize>::max(), '\n');
														cout << "Invalid input. \a  Try again: ";
													}
													if((e[i].marks[sub-1]<0)||(e[i].marks[sub-1]>100))
													{
														cout<<"INVALID MARKS!!! please re-enter marks \a";
														goto marks;
													}
														break;
													}
											default:cout<<"\nEnter valid number !!! \a";goto edit;
										
										}
										cout<<"\nInsertion successful";
										cout<<"\nPress 1 to edit more fields else enter any number to continue ";
									
										while(!(cin >>z))
													{
														cin.clear();
														cin.ignore(numeric_limits<streamsize>::max(), '\n');
														cout << "Invalid input. \a  Try again: ";
													}
										
										if(z==1)
										goto edit;
										else 
										goto label1; 
									}
									
								}
						}
				}
				else{ cout<<"No data exists!!! \a";	}
						if(y!=1 && kc!=1)
						{
							cout<<"\nROLL NO DOES NOT EXIST";
							goto label1;
						}
					
					break;
					
				}
				
				case 3:
				{
					cout<<"\n"<<"Enter roll no whose information is to be deleted:: ";
				
					while(!(cin >> roll))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input. \a  Try again: ";
					}
					int x =0;
				
				
				
				
					for(int i=0;i<count;i++)
					{	
						
						if( e[i].roll_no==roll)
						{		
							   x=1;
							   for(int k=i;k<count-1;k++)
							   {
							   		e[k].name=e[k+1].name;
							   		e[k].level=e[k+1].level;
							   		e[k].section=e[k+1].section;
							   		e[k].roll_no=e[k+1].roll_no;
							   		for(int m=0;m<5;m++)
							   			e[k].marks[m]=e[k+1].marks[m];
							   }
						}
						if(i==count-1)
						{
							e[i].name=" ";
							e[i].level=0;
							e[i].roll_no=0; 
							e[i].section=' ';
							for(int j=0;j<5;j++)
								e[i].marks[j]=0;	
						} 
					}
					count--;counter--;
					if(x==1)
						cout<<"\n DELETION SUCCESSFUL";
					if(x==0)
						cout<<"\n ROLL NO DOES NOT EXIST";
					goto label1;
					break;
				}
				
				
				case 4:
				{
					
					cout<<"\nAre you sure you want to delete all records?"<<"\n"<<"Press 1 to confirm  ";
					while(!(cin >> confirm))
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input. \a  Try again: ";
							}
					if(confirm==1)
					{	count =0; counter=0;
						for(int i=0;i<100;i++)
						{
							e[i].name=" ";
							e[i].level=0;
							e[i].roll_no=0; 
							e[i].section=' ';
							for(int j=0;j<5;j++)
							e[i].marks[j]=0;
						}
						cout<<"\nDeletion successful";
					}
					
					goto label1;
					break;
				}
				
				
				case 5:
				{
					cout<<"\nEnter roll no whose information is to be displayed:: ";
					while(!(cin >> roll))
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input. \a  Try again: ";
							}
					int x =0;
					for(int i=0;i<100;i++)
					{
						if( e[i].roll_no==roll)
						{
							x=1;
							cout<<"\nSTUDENT DATA\n";
							cout<<"\nRoll no: "<<e[i].roll_no;
							cout<<"\nName: "<<e[i].name;
							cout<<"\nClass: "<<e[i].level;
							cout<<"\nSection: "<<e[i].section;
							cout<<"\nMarks(out of 100):\n";
							for(int j=0;j<5;j++)
							{
								cout<<"Subject "<<j+1<<"-"<<e[i].marks[j]<<"\n";
								sum=sum+e[i].marks[j];
								
							}
							cout<<"Percentage of the student is:: "<<(sum*100)/500<<"%"<<"\n------------------------------------------\n";
							sum=0;
							break;
						}
					}
						if(x!=1)
						{
							cout<<"\nROLL NO DOES NOT EXIST";
						}
					goto label1;
					break;
				}
				case 6:
				{		if(count==0)
						{
							cout<<"NO STUDENT DATA EXISTS";
							goto label1;
							confirm=0;
						}
						
				//sort
				for(int z=0;z<count;z++)
				{		std_data k;
						for(int y=0;y<count-1;y++)
					{
						if(e[y].roll_no>e[y+1].roll_no)
						{
							k=e[y];
							e[y]=e[y+1];
							e[y+1]=k;
						}
					}
				} 
				
					for(int i=0;i<count;i++)
					{
						
						
							cout<<"\nSTUDENT DATA\n";
							cout<<"\nRoll no: "<<e[i].roll_no;
							cout<<"\nName: "<<e[i].name;
							cout<<"\nClass: "<<e[i].level;
							cout<<"\nSection: "<<e[i].section;
							cout<<"\nMarks(out of 100):\n";
							for(int j=0;j<5;j++)
							{
								cout<<"Subject "<<j+1<<"-"<<e[i].marks[j]<<"\n";
								sum=sum+e[i].marks[j];
								
							}
							cout<<"Percentage of the student is :: "<<(sum*100)/500<<"%"<<"\n------------------------------------------\n";
							sum=0;
					}
					goto label1;
					break;
				}
			}	
		}
		
	}
