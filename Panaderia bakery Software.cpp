
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct FoodType	
{
	int FNo;
	string Name;
	double Price;
	
};

bool login()
{
	ifstream dtails;
	string user, pass, UN, PW;
	bool found = false;
	
	dtails.open("User detail.txt");
	
	cout<<"\n\nPlease enter your user name: ";
	cin>>user;
	cout<<"Please enter your password: ";
	cin>>pass;
	
	dtails>>UN>>PW; 
	while(dtails)
	{
		if (user == UN && pass == PW)
		{
			cout<<"Access Granted..."<<endl;
			found = true;
			break;
		}
		
	dtails>>UN>>PW;
	}
	if (found==false)
	{
		cout<<"Access Denied..."<<endl;
		return false;
	}
	else
	return true;
		
}

int menu()
{
	cout<<"\nWelcome to Panaderia bakery "<<endl;
	cout<<"++++++++++++++++++++++++++++"<<endl;
	
	int sel;
	system("pause");
	system("cls");
	cout <<"User Menu"<<endl;
	cout<<"1. List Available items"<<endl;
	cout<<"2. Add New Items"<<endl;
	cout<<"3. Search specific item " <<endl;
	cout<<"4. Help "<<endl;
	cout<<"0. Exit"<<endl;
	
	cout<<"\n\tInput your selection :";
	cin>>sel;
return sel;
}

int main()
{
	int opt, length;
	FoodType addItem();
	void printItem(FoodType Items);
	void printToFile(FoodType Items);
	int readFoodsfromFile(FoodType Itm[10]);
	void reWriteFile(FoodType Items[10],int length, int index=-1);

	FoodType Foods;	
	FoodType Items[10];	
	
	bool status = login();
	int index ;
if (status)
{
	do{
	length =readFoodsfromFile(Items);
	opt = menu();
		switch(opt)
		{
			case 1 : for (int a =0 ; a <length; a++)
							printItem(Items[a]);	
				break;
				
			case 2 : Foods = addItem();	
					printItem(Foods);	
					printToFile(Foods);
				
				break;
			
			case 4 :cout<<"Thank You for choose us Panaderia bakery.."<<endl; 
					cout<<"If you have any Doubt about this system CONTECT US "<<endl;
					cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
					cout<<"\nService Manager No: 0777575477"<<endl;
					cout<<"\nEmail : PanaderiaBakery@gmail.com"<<endl;
					cout<<"\nAddress : 152main_street_Kandy"<<endl;
				break;
			case 0: cout<<"Exit"<<endl;	
		}
	}while(opt!=0);
}
else
	cout<<"Sorry, Invalid User... "<<endl;
return 0;	
}

FoodType addItem()
{
		FoodType myItem;
	
	cout<<"Enter Item Code : ";
	cin>>myItem.FNo ;
	cout<<"Enter Food Name : ";
	cin>>myItem.Name;
	cout<<"Enter Price : ";
	cin>>myItem.Price;
	
	cout<<"\n\tfood Record added successfully..."<<endl;
	return myItem;	
}

void printItem(FoodType items)	
{
	cout<<"\nItem No    : "<<items.FNo<<endl;
	cout<<"Food Name : "<<items.Name;
	cout<<"\tPrice : "<<items.Price<<endl;
}
int readFoodsfromFile(FoodType Itm[10])
{
	ifstream FFile;
	FFile.open("Food Details.txt");
	int x = 0;
	
	FFile>>Itm[x].FNo>>Itm[x].Name>>Itm[x].Price;
	while(FFile)
	{
		x++;
		if(x>=20)
			{
				cout<<"\n\tRunning Out of Space ..."<<endl;
				break;
			}
		FFile>>Itm[x].FNo>>Itm[x].Name>>Itm[x].Price;
	}
	FFile.close();
	return x;
}

void printToFile(FoodType items)
{
	ofstream FFile;
	FFile.open("Food Details.txt",ios::app);
	
		FFile<<items.FNo<<"\t"<<items.Name<<"\t"<<items.Price<<endl;
	
	FFile.close();
	
}

void reWriteFile(FoodType items[10],int length, int index=-1)
{
	ofstream FFile;
	FFile.open("Food Details.txt");	
	
	for(int a=0; a<length; a++)
	{	if (a!= index)
		FFile<<items[a].FNo<<"\t"<<items[a].Name<<"\t"<<items[a].Price<<endl;
	}
	FFile.close();
	
}
