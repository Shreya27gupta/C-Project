#include<iostream>
#include<dos.h>
#include<iomanip>
#include<fstream>
// #include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

using namespace std;

class itemlist
{
public:
 int item_no;
 char name[20],remark[30], cate[30],company[30];
 int quantity;
 float price;
  public:

  void getdata();
  void dispdata();
  void tdispdata();
  char *getcate()
  {
  return cate;
  }
  int retitemno()
  {
    return item_no;
  }
}I;
struct item
{
int item_no;
 char name[20],remark[30], cate[30],company[30];
 int quantity;
 float price,amount,d;
};
class basket
{
public:
char Cust_name[20],cust_add[30],cust_pin[15],cust_phone[15];
item CI[20];
int noofitem;
float Bill_amt,d,dis_amt;
char mode[10],cnumber[20],ctype[30];
public:
void basgetdata();
void basdisplaydata();
};
basket b;
void basket::basgetdata()
{
char rep;
int flag=0,i=0;
Bill_amt=0;
dis_amt=0;

start:
cout<<"\n Enter Item no   : ";
cin>>CI[i].item_no;
fstream fin("item.dat",ios::in|ios::binary);
while(fin.read((char *)&I,sizeof(I)))
{
if(I.retitemno()  ==CI[i].item_no)
{
flag=1;
break;
}
}
if(flag==0)
{
cout<<"\n No such Item";
goto start;
}
 strcpy(CI[i].name,I.name);
 cout<<"\nDescription              :  "<<I.name;
 strcpy(CI[i].remark,I.remark);
 cout<<"\nCategroy                  :  "<<I.cate;
 strcpy(CI[i].cate,I.cate);
 strcpy(CI[i].company,I.company);
 cout<<"\nEnter Quantity  : ";
 cin>>CI[i].quantity ;
 CI[i].price=I.price;
 CI[i].amount=CI[i].price*CI[i].quantity;

 if(I.price<=0&&I.price<=1000)
 {CI[i].d=10;}
 if(I.price>=1000&&I.price<=10000)
 {CI[i].d=15;}
 if(I.price>=10000)
 {CI[i].d=20;}
 CI[i].amount=CI[i].amount-(CI[i].d/100*CI[i].amount);
 Bill_amt+=CI[i].amount;
 dis_amt+=(CI[i].price*CI[i].quantity*(CI[i].d/100));
  cout<<"\nDiscount Given          : "<<CI[i].d<<"%";
 cout <<"\nWant to buy more item\n(Enter Y For YES And N For NO)\n";
 cin>>rep;
 i++;
 if (rep=='y' ||rep=='y')
 {
  goto start;
 }
 noofitem=i;
 //code to accept customer details
 clrscr();
 cout<<"\n\n\tEnter Customer information";
 cout<<"\n\tEnter Your Name             : ";
 gets(Cust_name);
 cout<<"\n\tEnter Your Shipping Address : ";
 gets(cust_add);
 cout<<"\n\tEnter You Pincode           : ";
 gets(cust_pin);
 cout<<"\n\tEnter Your Contact No       : ";
 gets(cust_phone);
 cout<<"\n No of items bought           : "<<noofitem;
 int c;
 cout<<"\n\tSelect Mode of Payment      : ";
 cout<<"\n\t1.Credit/Debit Card";
 cout<<"\n\t2.Cash On Delivery\n";
 cin>>c;
 if(c==1)
 {
 strcpy(mode,"Card");
 cout<<"\n\tEnter Credit/Debit card no  : ";
 gets(cnumber);
 cout<<"\n\tEnter Card Type             : ";
 gets(ctype);
 }
 else
 {
 strcpy(mode,"COD");
 strcpy(cnumber,"NULL");
 strcpy(ctype,"NULL");
 }
 }
void basket::basdisplaydata()
{
 clrscr();
 cout<<"\n\n\t\tBILL";
 cout<<"\n\n\t\tCustomer information";
 cout<<"\n\tCustomer Name             : "<<Cust_name;
 cout<<"\n\tShipping Address          : "<<cust_add;
 cout<<"\n\tPincode                   : "<<cust_pin;
 cout<<"\n\tContact No                : "<<cust_phone;
 cout<<"\n---------------------------------------------------------------";
 cout<<"\n";
 cout.setf(ios::left);
 cout<<setw(6)<<"I.No"<<setw(15)<<"Description"<<setw(15)
     <<"Category"<<setw(10)<<"Quantity"<<setw(8)<<"Price"
     <<setw(8)<<"Amount"<<setw(12)<<"Amt Payable";
for(int i=0;i<noofitem;i++)
{
 cout<<"\n"<<setw(6)<<CI[i].item_no;
 cout<<setw(15)<<CI[i].name;
 cout<<setw(15)<<CI[i].cate;
 cout<<setw(10)<<CI[i].quantity ;
 cout<<setw(8)<<CI[i].price;
 cout<<setw(12)<<CI[i].quantity*CI[i].price;
 cout<<setw(10)<<CI[i].amount;
 }
 cout<<"\n-----------------------------------------------------------";
 cout<<"\n\tBill Amount                 : "<<Bill_amt;
 cout<<"\n\t Dicount Given              : "<<dis_amt;
 cout<<"\n---------------------------------------------------------";
 cout<<"\n\tNode of Payment             : "<<mode;
 cout<<"\n\tCredit/Debit card no        : "<<cnumber;
 cout<<"\n\tCard Type                   : "<<ctype;
 }

void itemlist::getdata()
{ cout<<"\nEnter Category : ";
  gets(cate);
  cout<<"\nEnter Item.No  : ";
  cin>>item_no;
  cout<<"\nEnter Name     : ";
  gets(name);
  cout<<"\nEnter Quantity : ";
  cin>>quantity;
  cout<<"\nEnter Price    : ";
  cin>>price;
}
void itemlist::dispdata()
{ cout<<"\nCategory : "<<cate;
  cout<<"\nItem no. : "<<item_no;
  cout<<"\nName     : "<<name;
  cout<<"\nQuantiy  : "<<quantity;
  cout<<"\nPrice    : "<<price;
}
void itemlist::tdispdata()
{  cout<<"\n";
  cout<<setw(6)<<item_no;
  cout<<setw(15)<<name;
  cout<<setw(15)<<cate;
  cout<<setw(15)<<price;
}


itemlist S;
void bcreate()
{
  ofstream fout ("item.dat",ios::in|ios::binary);
    char rep;
  do
  {
    S.getdata();
    fout.write((char*)&S, sizeof(S));
    cout<<"\nWant to add more data?? (Enter Y for yes and N for no)";
    cin>>rep;
  }while (rep=='y' || rep=='Y');
  fout.close();
}
void badd()
{
  ofstream fout ("item.dat",ios::in|ios::binary);
  char rep;
  do
  {
    S.getdata();
    fout.write((char*)&S, sizeof(S));
    cout<<"\nWant to add more data?? (Enter Y for yes and N for no)";
    cin>>rep;
  }while (rep=='y' || rep=='Y');
  fout.close();
}
void bdisplay()
{
  ifstream fin ("item.dat",ios::in|ios::binary);
  while(fin.read((char*)&S,sizeof(S)))
  {
    S.dispdata();
  }
  getch();
}
void tbdisplay()
{
  ifstream fin ("item.dat",ios::in|ios::binary);
  cout<<"\n";
  cout<<setw(6)<<"item_no";
  cout<<setw(15)<<"name";
  cout<<setw(15)<<"category";
  cout<<setw(15)<<"price";

  while(fin.read((char*)&S,sizeof(S)))
  {
    S.tdispdata();
  }
  getch();
}


void bdelete()
{
  ifstream fin ("item.dat",ios::in|ios::binary);
  ofstream fout ("new.dat", ios::binary);
  itemlist S;
  int mitemno;
  cout<<"Enter Item no. of record to be deleted: ";
  cin>>mitemno;
  while(fin.read((char*)&S,sizeof(S)))
  {
    if (S.retitemno() == mitemno)
    {
      cout<<"Deleting this record"<<endl;
      S.dispdata();
    }
    else
      fout.write((char*)&S, sizeof(S));
  }
  fin.close();
  fout.close();
  remove ("item.dat");
  rename ("new.dat", "item.dat");
}

void bmodify()
{
  ifstream fin ("item.dat",ios::in|ios::binary);
  ofstream fout ("new.dat", ios::binary);
  itemlist S;
  int mitemno;
  cout<<"Enter item no. of record to be modified: ";
  cin>>mitemno;
  while(fin.read((char*)&S,sizeof(S)))
  {
    if (S.retitemno() == mitemno)
    {
      S.getdata();
      fout.write((char*)&S, sizeof(S));
    }
    else
      fout.write((char*)&S, sizeof(S));
  }
  fin.close();
  fout.close();
  remove ("item.dat");
  rename ("new.dat", "item.dat");
}
void search()
{ char x[30];
cout<<"enter category to search :"<<endl;
  gets(x);
  ifstream fin ("item.dat",ios::in|ios::binary);
  while(fin.read((char*)&S,sizeof(S)))
  {  if (strcmp(x,S.getcate())==0)
     S.dispdata();
  }
  getch();
}
void aadd()
{
  fstream fout ("bill.dat",ios::out|ios::binary);
  char per;
  do
  { b.basgetdata();
    fout.write((char*)&b, sizeof(b));
    cout<<"\nWant to add more data?? (Enter Y for yes and N for no)";
    cin>>per;
  }while (per=='y' || per=='Y');
  fout.close();
}
void adisplay()
{
  ifstream fin ("bill.dat",ios::binary);
  while(fin.read((char*)&b,sizeof(b)))
  {
    b.basdisplaydata();
  }
  getch();
}
void adelete()
{
  ifstream fin ("bill.dat" , ios::binary);
  fstream fout ("bnew.dat", ios::app|ios::binary);
  basket b;
  fin.read((char*)&b,sizeof(b));
  b.basdisplaydata();
  fout.write((char *)&b,sizeof(b));
  fin.close();
  fout.close();
  remove ("bill.dat");
}
void password()
{wpas:
clrscr();
char pass[20];
cout<<"USERNAME :: admin"<<"\nPassword :: ";
gets(pass);
if(strcmp(pass,"password")==0)
{ cout << "\nAccess granted :\n";
sleep(2);}
else if(strcmp(pass,"password")!=0)
{ cout << "\nAccess aborted...\n";
sleep (2);
goto wpas;
 }
 }


void submenu1()
{
int sr;
do
{
clrscr();
cout<<"\n1. ADD AN ITEM"
	<<"\n2. Add New Product"
	<<"\n3. Delete a File"
	<<"\n4. Modify records"
	<<"\n5. Exit";
    cout<<"\nEnter Your Choice"<<endl;
    cin>>sr;
    switch (sr)
    {
    case 1: bcreate();
	    break;
    case 2: badd();
	    break;

    case 3: bdelete();
	    break;
    case 4: bmodify();
	    break;
    case 5: return;

    default: cout<<"INVALID CHOICE";
    }
    getch();
    }while(sr!=5);
}
void submenu2()
{
int fp;
do
{
clrscr();
cout<<"display your data"<<endl;
     cout<<"\n1. Category wise"
	<<"\n2. All items"
	<<"\n3. Return to MAIN MENU";
    cout<<"\nEnter Your Choice"<<endl;
    cin>>fp;
    switch (fp)
    {
     case 1 :search();
     break;
     case 2: bdisplay();
     break;
     case 3: return;


    default: cout<<"INVALID CHOICE";
       }
       getch();
       }while(fp!=3);
    }
void submenu3()
{
int bas;
do
{
clrscr();

cout<<"\n1. See the items"
	<<"\n2. Add in Basket"
	<<"\n3. View"
	<<"\n4. Generate Bill"
	<<"\n5. Exit";
	cout<<"\nEnter Your Choice"<<endl;
    cin>>bas;
    switch (bas)
    {
     case 1:tbdisplay();
	    break;
     case 2 :aadd();
     break;
     case 3: adisplay();
     break;
     case 4 :adelete();
     case 5: return;


    default: cout<<"INVALID CHOICE";
       }
       getch();
       }while(bas!=4);
       }


void main()
{
  clrscr();
  int ch,sr,fp;

  do
  {
  clrscr();

  cout<<"\t\t         ****MENU****"<<endl;
  cout<<"\n1.Adminstrator"
      <<"\n2.Item Menu"
      <<"\n3.Basket"
       <<"\n4.Exit"<<endl;
  cout<<"\n\nEnter your choice: "<<endl;
  cin>>ch;
  switch (ch)
  {
    case 1:password();//password add
    submenu1();break;

    case 2:submenu2();break;
    case 3: submenu3();break;
    case 4:clrscr();
           cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tThank You For Shopping With Us";
           sleep(2);
           exit(0);

  }
  getch();
  }
  while(ch!=5);
}