/*
	A model of a movie ticket booking portal, based on the BookmyShow website using concepts of file management
	and object oriented programming.
*/
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
int ce=-1,ce1=-1,cc=0,u,v=1,yes=0;//change five
char tpass[15],password[15],CVV[3];;
double del_cost,norm_cost;
int y5=6;
struct date1
{
  int dd,mm,yy;
  struct time1
  {
	 int h,m;
  }t1,t2,t3;
};
class m_det
{
  int pm_no;
  public:

  int m_no()
  {
	 return pm_no;
  }
  date1 d,d1,d2;//d-release date
  char m_name[50];
  char lang[10];
  float rat;
  char seat1[10][10],seat2[10][10],seat3[10][10],seat4[10][10],seat5[10][10],seat6[10][10];
  char des[100];
  void create_new();
  void mov_det();
}mo,m1;
int count1();
void custdel(int);
void m_det::create_new()
{
	 //To insert details of a new movie
	 clrscr();
	 gotoxy(24,2);
	 cout<<"WELCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
	 gotoxy(28,3);
	 cout<<"EMPLOYEE SECTION"<<endl;
	 cout<<"\nPLEASE ENTER THE FOLLOWING DETAILS"<<endl;
	 cout<<"\nMovie code"<<endl;
	 cin>>pm_no;
	 cout<<"\nMovie name"<<endl;
	 gets(m_name);
	 cout<<"\nMovie language"<<endl;
	 gets(lang);
	 cout<<"\nMovie rating"<<endl;
	 cin>>rat;
	 cout<<"\nMovie description(only 100 characters)"<<endl;
	 gets(des);
	 cout<<"\nEnter release date"<<endl;
	 cin>>d.dd;
	 cin>>d.mm;
	 cin>>d.yy;
	 cout<<"\nEnter dates of shows"<<endl;
	 cout<<"Date 1"<<endl;
	 cin>>d1.dd;
	 cin>>d1.mm;
	 cin>>d1.yy;
	 cout<<"\nEnter time of shows on "<<d1.dd<<" / "<<d1.mm<<" / "<<d1.yy<<endl;
	 cout<<"Show 1"<<endl;
	 cin>>d1.t1.h;
	 cin>>d1.t1.m;
	 cout<<"\nShow 2"<<endl;
	 cin>>d1.t2.h;
	 cin>>d1.t2.m;
	 cout<<"\nShow 3"<<endl;
	 cin>>d1.t3.h;
	 cin>>d1.t3.m;
	 cout<<"Date 2"<<endl;
	 cin>>d2.dd;
	 cin>>d2.mm;
	 cin>>d2.yy;
	 cout<<"\nEnter time of shows on "<<d2.dd<<" / "<<d2.mm<<" / "<<d2.yy<<endl;
	 cout<<"Show 1"<<endl;
	 cin>>d2.t1.h;
	 cin>>d2.t1.m;
	 cout<<"\nShow 2"<<endl;
	 cin>>d2.t2.h;
	 cin>>d2.t2.m;
	 cout<<"\nShow 3"<<endl;
	 cin>>d2.t3.h;
	 cin>>d2.t3.m;
	 del_cost=500;
	 norm_cost=300;
	 for(int i=0;i<10;i++)
	 {
	  for(int j=0;j<10;j++)
	  {
		 seat1[i][j]=151;
		 seat2[i][j]=151;
		 seat3[i][j]=151;
		 seat4[i][j]=151;
		 seat5[i][j]=151;
		 seat6[i][j]=151;
	  }
	 }
}
void m_det::mov_det()
{
	 //To show movie details

	 y5+=2;
	 gotoxy(0,y5);
	 cout<<"Movie code :";
	 gotoxy(25,y5);
	 cout<<pm_no;
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Movie name :";
	 gotoxy(25,y5);
	 puts(m_name);
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Movie language :";
	 gotoxy(25,y5);
	 puts(lang);
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Movie rating :";
	 gotoxy(25,y5);
	 cout<<rat;
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Description :";
	 gotoxy(25,y5);
	 puts(des);
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Release date :";
	 gotoxy(25,y5);
	 cout<<d.dd<<" / "<<d.mm<<" / "<<d.yy;
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Dates of shows :";
	 y5+=2;
	 gotoxy(0,y5);
	 cout<<"Date 1 :";
	 gotoxy(25,y5);
	 cout<<d1.dd<<" / "<<d1.mm<<" / "<<d1.yy;
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Show timings";
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Show 1 :";
	 gotoxy(25,y5);
	 cout<<d1.t1.h<<" : "<<d1.t1.m;
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Show 2 :";
	 gotoxy(25,y5);
	 cout<<d1.t2.h<<" : "<<d2.t2.m;
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Show 3 :";
	 gotoxy(25,y5);
	 cout<<d1.t3.h<<" : "<<d1.t3.m;
	 y5+=2;
	 gotoxy(0,y5);
	 cout<<"Date 2 :";
	 gotoxy(25,y5);
	 cout<<d2.dd<<" / "<<d2.mm<<" / "<<d2.yy;
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Show timings";
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Show 1 :";
	 gotoxy(25,y5);
	 cout<<d2.t1.h<<" : "<<d2.t1.m;
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Show 2 :";
	 gotoxy(25,y5);
	 cout<<d2.t2.h<<" : "<<d2.t2.m;
	 y5++;
	 gotoxy(0,y5);
	 cout<<"Show 3 :";
	 gotoxy(25,y5);
	 cout<<d2.t3.h<<" : "<<d2.t3.m;
	 y5++;
	 gotoxy(0,y5);
}

void create()
{
  //to insert movie details into file
  clrscr();
  fstream f;
  f.open("movie.dat",ios::app|ios::binary);
  int n;
  cout<<"\nEnter number of movies"<<endl;
  cin>>n;
  int i=0;
  while(i<n)
  {
	 mo.create_new();
	 clrscr();
	 i++;
	 f.write((char*)&mo,sizeof(mo));
  }
  f.close();
}
void disp_mov()
{
 //to view movie details from file
 ce=-1;
 clrscr();
 fstream f;
 y5=3;
 gotoxy(24,2);
 cout<<"\n\t\t\tWELCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
 gotoxy(24,4);
 cout<<"\t\t MOVIE DETAILS"<<endl;
 f.open("movie.dat",ios::in|ios::binary);
 while(f.read((char*)&mo,sizeof(mo)))
 {
  mo.mov_det();
  cout<<"\nPress any key to continue"<<endl;
  getch();

  clrscr();
  gotoxy(24,2);
  cout<<"\n\t\t\tWELCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
  gotoxy(24,4);
  cout<<"\t\t MOVIE DETAILS"<<endl;
  y5=6;
  ce++;
 }
 if(ce==-1)
  cout<<"\nSorry no films are running at this point.Come back later"<<endl;
 f.close();
}
void update_file()
{
 //to change movie details
 fstream f,f1,f3,f4;
 int op,chk=-1,op1;
 int pos1=-1;
 float rat1;
 long int temp;
 date1 t1d1,t1d2,td1,td2,td3;
 clrscr();
 C:cout<<"\nDo you want to :\n\t1.Update existing data\n\t2.Delete movies\n\t3.Go Back"<<endl;
 cin>>op;
 switch(op)
 {
	case 1:
			 chk=-1;
			 f.open("movie.dat",ios::in|ios::out|ios::binary);
			 cout<<"\nEnter movie number whose data is to be updated?"<<endl;
			 cin>>temp;
			 while(f.read((char*)&mo,sizeof(mo)))
			 {
				if(mo.m_no()==temp)
				{
				 chk++;
				 B:cout<<"\nEnter which data should be updated:\n\t1.Rating\n\t2.Date of shows\n\t3.Time of shows"<<endl;
				 cin>>op1;
				 clrscr();
				 switch(op1)
				 {
				  case 1:
							pos1=(-1*sizeof(mo));
							cout<<"\nThe old rating was "<<mo.rat<<endl;
							cout<<"\nEnter new rating"<<endl;
							cin>>rat1;
							mo.rat=rat1;
							f.seekp(pos1,ios::cur);
							f.write((char*)&mo,sizeof(mo));
							break;
				  case 2:
							pos1=(-1*sizeof(mo));
							t1d1=mo.d1;
							t1d2=mo.d2;
							cout<<"\nThe old dates were "<<mo.d1.dd<<"/"<<mo.d1.mm<<"/"<<mo.d1.yy<<" and "<<mo.d2.dd<<"/"<<mo.d2.mm<<"/"<<mo.d2.yy<<endl;
							cout<<"\nEnter new dates"<<endl;
							cout<<"Date 1 "<<endl;
							cin>>t1d1.dd;
							cin>>t1d1.mm;
							cin>>t1d1.yy;
							mo.d1=t1d1;
							cout<<"\nDate 2 "<<endl;
							cin>>t1d2.dd;
							cin>>t1d2.mm;
							cin>>t1d2.yy;
							cout<<endl;
							mo.d2=t1d2;
							f.seekp(pos1,ios::cur);
							f.write((char*)&mo,sizeof(mo));
							break;
				  case 3:
							pos1=(-1*sizeof(mo));
							cout<<"\nThe old timings on "<<mo.d1.dd<<" / "<<mo.d1.mm<<" / "<<mo.d1.yy<<" were "<<mo.d1.t1.h<<" : "<<mo.d1.t1.m<<" , "<<mo.d1.t2.h<<" : "<<mo.d1.t2.m<<" and "<<mo.d1.t3.h<<" : "<<mo.d1.t3.m<<endl;
							cout<<"\nEnter new time of shows on "<<mo.d1.dd<<" / "<<mo.d1.mm<<" / "<<mo.d1.yy<<endl;
							td1=mo.d1;
							cout<<"Show 1 Time "<<endl;
							cin>>td1.t1.h;
							cin>>td1.t1.m;
							cin>>td1.t2.h;
							cin>>td1.t2.m;
							cout<<"Show 3 Time "<<endl;
							cin>>td1.t3.h;
							cin>>td1.t3.m;
							mo.d1=td1;
							cout<<"\nThe old timings on "<<mo.d2.dd<<" / "<<mo.d2.mm<<" / "<<mo.d2.yy<<" were "<<mo.d2.t1.h<<" : "<<mo.d2.t1.m<<" , "<<mo.d2.t2.h<<" : "<<mo.d2.t2.m<<" and "<<mo.d2.t3.h<<" : "<<mo.d2.t3.m<<endl;
							cout<<"\nEnter new time of shows on "<<mo.d2.dd<<" / "<<mo.d2.mm<<" / "<<mo.d2.yy<<endl;
							td2=mo.d2;
							cout<<"Show 1 Time "<<endl;
							cin>>td2.t1.h;
							cin>>td2.t1.m;
							cout<<"Show 2 Time "<<endl;
							cin>>td2.t2.h;
							cin>>td2.t2.m;
							cout<<"Show 3 Time "<<endl;
							cin>>td2.t3.h;
							cin>>td2.t3.m;
							mo.d2=td2;
							cout<<endl;
							pos1=(-1*sizeof(mo));
							f.seekp(pos1,ios::cur);
							f.write((char*)&mo,sizeof(mo));
							break;
				  default:
							cout<<"\nEnter valid choice"<<endl;
							goto B;

				  }
				}
			 }
			 if(chk==-1)
			 {
			  cout<<"\nSorry no record found"<<endl;
			 }
			 else cout<<"\nUpdation complete"<<endl;
			 f.close();
			 break;
	case 2:
			 chk=-1;
			 f.open("movie.dat",ios::in|ios::binary);
			 f1.open("tmpmov.dat",ios::out|ios::binary);
			 cout<<"Enter movie number whose data is to be deleted?"<<endl;
			 cin>>temp;
			 while(f.read((char*)&mo,sizeof(mo)))
			 {
				if(mo.m_no()!=temp)
				{
				  f1.write((char*)&mo,sizeof(mo));
				}
				else chk++;
			 }
			 if(chk==-1)
			 cout<<"\nSorry movie details were not found"<<endl;
			  else cout<<"\nRecord was deleted"<<endl;
			 f1.close();
			 f.close();
			 remove("movie.dat");
			 rename("tmpmov.dat","movie.dat");
			 if(count1()!=-1)
			 {
				custdel(temp);
			 }
			 break;
	case 3:
			 clrscr();
			 break;
	default:
			 cout<<"\Sorry!Invalid option..Enter again"<<endl;
			 goto C;
 }
}
class mov_cust
{
  int pc_code;
  char popt1,popt2;
  int pcm_no;
  public:

  int c_code()
  {
	 return pc_code;
  }
  char opt1()
  {
	 return popt1;
  }
  char opt2()
  {
	 return popt2;
  }
  int cm_no()
  {
	 return pcm_no;
  }
  char c_name[30];
  char c_mail[100];
  char c_mobile[15];
  int c_comp;
  int ct_no;
  char c_crd_no[10];
  double price;
  date1 c_exp;
  char seat_no[10][5];
  void view_mov_det();
  void book(int);
  void view_book();
  void seat_book(int,int,char,char);
  void cust_det(int,int,char,char,char[][5],int);
  void seat_disp(int,char,char);
  mov_cust()
  {
	 price=0;
  }
}mc,mc1;
void tcust_det(int,int,char,char,char[][5],int);
int count1()
{
  fstream f;
  ce1=-1;
  f.open("movcust.dat",ios::in);
  while(f.read((char*)&mc1,sizeof(mc1)))
	ce1++;
  return ce1;
}
void custdel(int temp)
{
  fstream f3,f4;
  f3.open("movcust.dat",ios::in|ios::binary);
  f4.open("tmpmvc.dat",ios::out|ios::binary);
  while(f3.read((char*)&mc,sizeof(mc)))
  {
	 if(mc.cm_no()!=temp)
	 f4.write((char*)&mc,sizeof(mc));
  }
  f3.close();
  f4.close();
  remove("movcust.dat");
  rename("tmpmvc.dat","movcust.dat");
}
void view_cust()
{
 //To view customer details
  int pos=-1;
  fstream f1,f;
  clrscr();
  int x1=0,y1=4;
  f.open("movcust.dat",ios::in|ios::app|ios::binary);
  f.seekp(0);
  gotoxy(24,2);
  cout<<"WElCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
  gotoxy(28,3);
  cout<<"BOOKING DETAILS";
  gotoxy(0,4);
  cout<<"The details of the ticket(s) are "<<endl;
  while(f.read((char*)&mc,sizeof(mc)))
  {
	y1++;
	gotoxy(x1,y1);
	cout<<"Customer Number";
	x1+=20;
	gotoxy(x1,y1);
	cout<<mc.c_code();
	y1++;
	x1=0;
	gotoxy(x1,y1);
	cout<<"Name";
	x1+=20;
	gotoxy(x1,y1);
	puts(mc.c_name);
	y1++;
	x1=0;
	gotoxy(x1,y1);
	cout<<"Movie code";
	x1+=20;
	gotoxy(x1,y1);
	cout<<mc.cm_no();
	y1++;
	x1=0;
	f1.open("movie.dat",ios::in|ios::binary);
	while(f1.read((char*)&mo,sizeof(mo)))
	{
	 if(mc.cm_no()==mo.m_no())
	 {
	  gotoxy(x1,y1);
	  cout<<"Movie Name";
	  x1+=20;
	  gotoxy(x1,y1);
	  puts(mo.m_name);
	  y1++;
	  x1=0;
	  gotoxy(x1,y1);
	  cout<<"Language";
	  x1+=20;
	  gotoxy(x1,y1);
	  puts(mo.lang);
	  y1++;
	  x1=0;
	  gotoxy(x1,y1);
	  cout<<"Rating";
	  x1+=20;
	  gotoxy(x1,y1);
	  cout<<mo.rat;
	  y1++;
	  x1=0;
	  gotoxy(x1,y1);
	  cout<<"Seat numbers";
	  x1=20;
	  gotoxy(x1,y1);
	  for(int i=0;i<mc.ct_no;i++)
	  {
		 for(int j=0;mc.seat_no[i][j]!='\0';j++)
		 cout<<mc.seat_no[i][j];
		 cout<<"  ";
	  }
	  y1++;
	  x1=0;
	  gotoxy(x1,y1);
	  cout<<"Date of show";
	  x1+=20;
	  gotoxy(x1,y1);
	  if(mc.opt1()=='A'||mc.opt1()=='a')
		 cout<<mo.d1.dd<<" / "<<mo.d1.mm<<" / "<<mo.d1.yy;
	  else if(mc.opt1()=='B'||mc.opt1()=='b')
		 cout<<mo.d2.dd<<" / "<<mo.d2.mm<<" / "<<mo.d2.yy;
	  y1++;
	  x1=0;
	  gotoxy(x1,y1);
	  cout<<"Show Time";
	  x1+=20;
	  gotoxy(x1,y1);
	  if((mc.opt2()=='P'||mc.opt2()=='p')&&(mc.opt1()=='A'||mc.opt1()=='a'))
		 cout<<mo.d1.t1.h<<" : "<<mo.d1.t1.m;
	  else if((mc.opt2()=='Q'||mc.opt2()=='q')&&(mc.opt1()=='A'||mc.opt1()=='a'))
		 cout<<mo.d1.t2.h<<" : "<<mo.d1.t2.m;
	  else if((mc.opt2()=='R'||mc.opt2()=='r')&&(mc.opt1()=='A'||mc.opt1()=='a'))
		 cout<<mo.d1.t3.h<<" : "<<mo.d1.t3.m;
	  else if((mc.opt2()=='P'||mc.opt2()=='p')&&(mc.opt1()=='B'||mc.opt1()=='b'))
		 cout<<mo.d2.t1.h<<" : "<<mo.d2.t1.m;
	  else if((mc.opt2()=='Q'||mc.opt2()=='q')&&(mc.opt1()=='B'||mc.opt1()=='b'))
		 cout<<mo.d2.t2.h<<" : "<<mo.d2.t2.m;
	  else if((mc.opt2()=='R'||mc.opt2()=='r')&&(mc.opt1()=='C'||mc.opt1()=='c'))
		 cout<<mo.d2.t3.h<<" : "<<mo.d2.t3.m;
	  y1++;
	  x1=0;
	  gotoxy(x1,y1);
	  cout<<"Total price";
	  x1+=20;
	  gotoxy(x1,y1);
	  cout<<mc.price;
	  x1=0;
	  y1++;
	  gotoxy(x1,y1);
	  cout<<"Mobile number";
	  x1+=20;
	  gotoxy(x1,y1);
	  puts(mc.c_mobile);
	  x1=0;
	  y1++;
	  gotoxy(x1,y1);
	  cout<<"Email id";
	  x1+=20;
	  gotoxy(x1,y1);
	  puts(mc.c_mail);
	  pos++;
	  cout<<"\nPress enter to continue"<<endl;
	  getch();
	  clrscr();
	}
  }
 }
 if(pos==-1)
  cout<<"\nSorry no customer data found"<<endl;
 f1.close();
 f.close();
}
void mov_cust::view_mov_det()
{
	 disp_mov();
	 fstream f;
	 int op;
	 int chk=-1;
	 int tm_no;
	 cout<<"\nDo you want to :\n\t1.Book a movie \n\t2.Go back to customer menu"<<endl;
	 cin>>op;
	 char h=65;
	 switch(op)
	 {
	  case 1:
				clrscr();
				f.open("movie.dat",ios::in|ios::binary);
				cout<<"\nChoose a movie : "<<endl;
				while(f.read((char*)&mo,sizeof(mo)))
				{
				  cout<<"\n"<<h++<<") ";
				  puts(mo.m_name);
				  cout<<"\nMovie code "<<mo.m_no()<<endl;
				  cout<<endl;
				}
				f.close();
				D:cout<<"\nEnter movie code of the movie you want to book tickets for"<<endl;
				cin>>tm_no;
				f.open("movie.dat",ios::in|ios::binary);
				while(f.read((char*)&mo,sizeof(mo)))
				{
				  if(tm_no==mo.m_no())
				  {
					 chk++;
					 book(tm_no);
				  }
				}
				f.close();
				if(chk==-1)
				{
				 clrscr();
				 cout<<"\nSorry please enter valid movie no"<<endl;
				 goto D;
				}

				break;
	  case 2:
				clrscr();
				break;
	 }
}
void mov_cust::book(int tm_no)
{
	 fstream f,f1;
	 char op,op1,op2;
	 clrscr();
	 cc=1;
	 f.open("movie.dat",ios::in|ios::out|ios::binary);
	 f1.open("movcust.dat",ios::app|ios::in|ios::binary);
	 while(f1.read((char*)&mc1,sizeof(mc1)))
	 {
		if(mc1.c_code()>=cc)
		{
		 if(yes==0)      //change six
		  cc=mc1.c_code()+1;
		 else cc=mc1.c_code(); //change seven

	 }
	 f1.close();
	 clrscr();
	 f1.open("movcust.dat",ios::out|ios::in|ios::binary);
	 cout<<"\nDetails of your chosen movie are "<<endl;
	 while(f.read((char*)&mo,sizeof(mo)))
	 {
		if(tm_no==mo.m_no())
		{
		 y5=5;
		 mo.mov_det();
		 pcm_no=mo.m_no();
		 break;
		}
	 }
	 cout<<"\nDo you want to continue(Y/N)?"<<endl;
	 cin>>op;
	 clrscr();
	 if(op=='y'||op=='Y')
	 {
	  pc_code=cc;
	  X:cout<<"\nYou are customer number : "<<cc<<endl;
	  cout<<"\nEnter which date do you want to go on"<<endl;
	  cout<<"\n\t1. "<<mo.d1.dd<<" / "<<mo.d1.mm<<" / "<<mo.d1.yy<<" (A) "<<endl;
	  cout<<"\n\t\tOR"<<endl;
	  cout<<"\n\t2. "<<mo.d2.dd<<" / "<<mo.d2.mm<<" / "<<mo.d2.yy<<" (B)? "<<endl;
	  cin>>op1;
	  if(op1=='A'||op1=='a')
	  {
		 clrscr();
		 X1:popt1=op1;
		 cout<<"\nEnter which timing"<<endl;
		 cout<<"\n\t1. "<<mo.d1.t1.h<<" : "<<mo.d1.t1.m<<" (P) "<<endl;
		 cout<<"\n\t\tOR"<<endl;
		 cout<<"\n\t2. "<<mo.d1.t2.h<<" : "<<mo.d1.t2.m<<" (Q) "<<endl;
		 cout<<"\n\t\tOR"<<endl;
		 cout<<"\n\t3. "<<mo.d1.t3.h<<" : "<<mo.d1.t3.m<<" (R) "<<endl;
		 cin>>op2;
		 if(op2=='P'||op2=='p')
		 {
			clrscr();
			popt2=op2;
			f1.write((char*)&mc,sizeof(mc));
			f.close();
			f1.close();
			seat_book(mo.m_no(),cc,op1,op2);
		 }
		 else if(op2=='Q'||op2=='q')
		 {
			clrscr();
			popt2=op2;
			f1.write((char*)&mc,sizeof(mc));
			f.close();
			f1.close();
			seat_book(mo.m_no(),cc,op1,op2);
		 }
		 else if(op2=='R'||op2=='r')
		 {
			clrscr();
			popt2=op2;
			f1.write((char*)&mc,sizeof(mc));
			f.close();
			f1.close();
			seat_book(mo.m_no(),cc,op1,op2);
		 }
		 else
		 {
		  clrscr();
		  cout<<"Please enter valid data"<<endl;
		  goto X1;
		 }
	  }
	  else if(op1=='B'||op1=='b')
	  {
		 clrscr();
		 popt1=op1;
		 Y1:cout<<"\nEnter which timing"<<endl;
		 cout<<"\n\t1. "<<mo.d2.t1.h<<" : "<<mo.d2.t1.m<<" (P) "<<endl;
		 cout<<"\n\t\tOR"<<endl;
		 cout<<"\n\t2. "<<mo.d2.t2.h<<" : "<<mo.d2.t2.m<<" (Q) "<<endl;
		 cout<<"\n\t\tOR"<<endl;
		 cout<<"\n\t3. "<<mo.d2.t3.h<<" : "<<mo.d2.t3.m<<" (R) "<<endl;
		 cin>>op2;
		 if(op2=='P'||op2=='p')
		 {
			clrscr();
			popt2=op2;
			f1.write((char*)&mc,sizeof(mc));
			f.close();
			f1.close();
			seat_book(mo.m_no(),cc,op1,op2);
		 }
		 else if(op2=='Q'||op2=='q')
		 {
			clrscr();
			popt2=op2;
			f1.write((char*)&mc,sizeof(mc));
			f.close();
			f1.close();
			seat_book(mo.m_no(),cc,op1,op2);
		 }
		 else if(op2=='R'||op2=='r')
		 {
			clrscr();
			popt2=op2;
			f1.write((char*)&mc,sizeof(mc));
			f.close();
			f1.close();
			seat_book(mo.m_no(),cc,op1,op2);
		 }
		 else
		 {
		  clrscr();
		  cout<<"Please enter valid data"<<endl;
		  goto Y1;
		 }
	  }
	  else
	  {
		clrscr();
		cout<<"Please enter valid data"<<endl;
		goto X;
	  }
	 }
	 else if(op=='N'||op=='n')
	 {
	  clrscr();
	  f.close();
	  f1.close();
	  char n;
	  cout<<"\nAre you sure(y/n)?"<<endl;
	  cin>>n;
	  if(n=='y'||n=='Y')
	  {
		clrscr();
		gotoxy(35,10);
		cout<<"GOOD BYE!! :( ";
		gotoxy(30,12);
		cout<<"PLEASE VISIT US AGAIN!!"<<endl;
		exit(0);
	  }
	  else view_mov_det();
	 }
	}
}
void mov_cust::seat_book(int tm_no,int tc_code,char op1,char op2)
{
	 clrscr();
	 fstream f,f1;
	 char h=65;
	 int x=5,y=1,r=0,x1=0,y1=3;
	 int chk=-1;
	 int tno;
	 char op;
	 int k=0;
	 int pos=-1*sizeof(mc);
	 int pos2=-1*sizeof(mo);
	 int z=0;
	 char op3,op4;
	 char tc1;
	 char tr1;
	 clrscr();
	 cout<<"\nYou are customer number : "<<tc_code<<endl;
	 K:f1.open("movcust.dat",ios::in|ios::out|ios::binary);
	 f.open("movie.dat",ios::in|ios::out|ios::binary);
	 cout<<"\nDo you want to book seats(y/n)"<<endl;
	 cin>>op;
	 chk=-1;
	 if(op=='y'||op=='Y')
	  goto F;
	 else
	 {
		yes=1;     //change eight
		view_mov_det();
	 }
	 F:
	 clrscr();
	 yes=0;    //change nine
	 while(f.read((char*)&mo,sizeof(mo)))
	 {
		cout<<mo.m_no();
		if(cm_no()==mo.m_no())
		{
		  clrscr();
		  x=5;y=1;r=0;x1=0;y1=3;
		  for(int i=0;i<10;i++)
		  {
			 gotoxy(x,y);
			 cout<<h++;
			 x=x+7;
		  }
		  for(i=0;i<10;i++)
		  {
			 gotoxy(x1,y1);
			 cout<<r++;
			 y1+=2;
		  }
		  x=5;y=3;
		  for(i=0;i<10;i++)
		  {
			 gotoxy(x,y);
			 for(int j=0;j<10;j++)
			 {
				gotoxy(x,y);
				if(op1=='A'||op1=='a')
				{
				 if(op2=='P'||op2=='p')
				  cout<<mo.seat1[i][j]<<"       ";
				 else if(op2=='Q'||op2=='q')
				  cout<<mo.seat2[i][j]<<"       ";
				 else cout<<mo.seat3[i][j]<<"       ";
				}
				if(op1=='B'||op1=='b')
				{
				 if(op2=='P'||op2=='p')
				  cout<<mo.seat4[i][j]<<"       ";
				 else if(op2=='Q'||op2=='q')
				  cout<<mo.seat5[i][j]<<"       ";
				 else cout<<mo.seat6[i][j]<<"       ";
				}
				x+=7;
			 }
			 x=5;
			 y+=2;
		  }
		  gotoxy(0,22);
		  cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
		  gotoxy(37,24);
		  cout<<"SCREEN";
		  Y:cout<<"\nEnter number of seats you want to book(0 - 6 : max. 6 at a time)"<<endl;
		  cin>>tno;
		  if(tno>6)
		  {
			 cout<<"\nSorry you are only allowed to book 6 at a time"<<endl;
			 goto Y;
		  }
		  else if(tno<=0)
		  {
			 cout<<"\nSorry please enter valid number"<<endl;
			 goto Y;
		  }
		  else
		  {
			 ct_no=tno;
			 cout<<"Pricing : 2-9:Normal seats(Rs.300) , 0-1:Deluxe seats(Rs.500)"<<endl;
			 for(int p=0;p<ct_no;p++)
			 {
				if(chk>-1)
				{
				 f1.open("movcust.dat",ios::in|ios::out|ios::binary);
				 f.open("movie.dat",ios::in|ios::out|ios::binary);
				}
				P1:cout<<"\nEnter column number(A-J)"<<endl;
				cin>>tc1;
				tc1=toupper(tc1);
				if(tc1<65||tc1>74)
				{
				 cout<<"Sorry enter valid column number"<<endl;
				 goto P1;
				}
				cout<<"\nEnter row number(0-9)"<<endl;
				cin>>tr1;
				if(tr1<48||tr1>57)
				{
				 cout<<"Sorry enter valid column number"<<endl;
				 goto P1;
				}
				h=65;
				int ttr1=tr1-48,ttc1=tc1-65;
				if((op1=='A'||op1=='a')&&(op2=='P'||op2=='p'))
				{
				  if(mo.seat1[ttr1][ttc1]==char(164))
				  {
					 cout<<"\nSorry that is already booked.Enter again"<<endl;
					 goto P1;
				  }
				}
				if((op1=='A'||op1=='a')&&(op2=='Q'||op2=='q'))
				{
				  if(mo.seat2[ttr1][ttc1]==char(164))
				  {
					 cout<<"\nSorry that is already booked.Enter again"<<endl;
					 goto P1;
				  }
				}
				if((op1=='A'||op1=='a')&&(op2=='R'||op2=='r'))
				{
				  if(mo.seat3[ttr1][ttc1]==char(164))
				  {
					 cout<<"\nSorry that is already booked.Enter again"<<endl;
					 goto P1;
				  }
				}
				if((op1=='B'||op1=='b')&&(op2=='P'||op2=='p'))
				{
				  if(mo.seat4[ttr1][ttc1]==char(164))
				  {
					 cout<<"\nSorry that is already booked.Enter again"<<endl;
					 goto P1;
				  }
				}
				if((op1=='B'||op1=='b')&&(op2=='Q'||op2=='q'))
				{
				  if(mo.seat5[ttr1][ttc1]==char(164))
				  {
					 cout<<"\nSorry that is already booked.Enter again"<<endl;
					 goto P1;
				  }
				}
				if((op1=='B'||op1=='b')&&(op2=='R'||op2=='r'))
				{
				  if(mo.seat6[ttr1][ttc1]==char(164))
				  {
					 cout<<"\nSorry that is already booked.Enter again"<<endl;
					 goto P1;
				  }
				}
				for(i=48,k=0;i<58,k<10;i++,k++)
				{
				 if(tr1==i)
				 {
				  for(int j=0,jr=65;j<10,jr<75;j++,jr++)
				  {
					 if(tc1==jr)
					 {
						cout<<"\nAre you sure you want to book this seat(Y/N)(If you click Y-your seats are\nnon refundable)?"<<endl;
						cin>>op3;
						if(op3=='Y'||op3=='y')
						{
						  if(op1=='A'||op1=='a')
						  {
							 if(op2=='P'||op2=='p')
							 {
							  mo.seat1[k][j]=164;
							 }
							 else if(op2=='Q'||op2=='q')
							 {
							  mo.seat2[k][j]=164;
							 }
							 else
							 {
							  mo.seat3[k][j]=164;
							 }
						  }
						  else if(op1=='B'||op1=='b')
						  {
							 if(op2=='P'||op2=='p')
							 {
							  mo.seat4[k][j]=164;
							 }
							 else if(op2=='Q'||op2=='q')
							 {
							  mo.seat5[k][j]=164;
							 }
							 else
							 {
							  mo.seat6[k][j]=164;
							 }
						  }
						  chk++;
						  char tmpstr[10];
						  tmpstr[0]=tc1;
						  tmpstr[1]=tr1;
						  tmpstr[2]='\0';
						  z++;
						  if(tr1==48||tr1==49)
							price+=500;
						  else price+=300;
						  f1.seekp(0);
						  while(f1.read((char*)&mc1,sizeof(mc1)))
						  {
							  if(mc1.c_code()==c_code())
							  {
								 f1.seekp(pos,ios::cur);
								 f1.write((char*)&mc,sizeof(mc));
								 break;
							  }
						  }
						  f.seekp(0);
						  while(f.read((char*)&m1,sizeof(m1)))
						  {
							  if(m1.m_no()==cm_no())
							  {
								 f.seekp(pos2,ios::cur);
								 f.write((char*)&mo,sizeof(mo));
								 break;
							  }
						  }
						  f1.close();
						  f.close();
						  clrscr();

						  seat_disp(tm_no,op1,op2);
						}

						else if(op3=='N'||op3=='n')
						{
						  cout<<"\nAre you sure you want to exit?(Y/N)"<<endl;
						  cin>>op4;
						  if(op4=='Y'||op4=='y')
							 break;
						  else if(op4=='N'||op4=='n')
						  {
							 clrscr();
							 f.close();
							 f1.close();
							 goto K;
						  }
						}
					 }
				  }
				 }
				}
			 }
		  }
		  seat_disp(tm_no,op1,op2);
		  cout<<"\nPress Y to continue"<<endl;
		  cin>>op;                                                 \
		  if((op=='Y'||op=='y')&&(chk>-1))
				tcust_det(tm_no,tc_code,op1,op2,seat_no,tno);
		  else if((op=='Y'||op=='y')&&(chk==-1))
		  {
				cout<<"\nSorry you haven't booked any seats"<<endl;
				goto K;
			 }
		  }
		}
}
void tcust_det(int tm_no,int tc_code,char op1,char op2,char tseat_no[][5],int tno)
{
	 fstream f;
	 f.open("movcust.dat",ios::in|ios::binary);
	 while(f.read((char*)&mc,sizeof(mc)))
	 {
		if(tc_code==mc.c_code())
		 mc.cust_det(tm_no,tc_code,op1,op2,tseat_no,tno);
	 }
	 f.close();
}
void mov_cust::cust_det(int tm_no,int tc_code,char op1,char op2,char tseat_no[][5],int tno)
{
	 clrscr();
	 int op,u;
	 fstream f,f1;
	 X1:f1.open("movcust.dat",ios::in|ios::out|ios::binary);
	 f.open("movie.dat",ios::in|ios::out|ios::binary);
	 gotoxy(24,2);
	 cout<<"WELCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
	 gotoxy(24,3);
	 cout<<"CUSTOMER DETAILS"<<endl;
	 cout<<"\nPLEASE ENTER THE FOLLOWING DETAILS"<<endl;
	 cout<<"\nYou are customer number :"<<tc_code<<endl;
	 cout<<"\nName(max. 30 characters long) : ";
	 gets(c_name);
	 cout<<"\nYour email : ";
	 gets(c_mail);
	 W:cout<<"\nYour contact number : ";
	 gets(c_mobile);
	 if(strlen(c_mobile)>10)
	 {
	  cout<<"\nSorry that number is not valid"<<endl;
	  goto W;
	 }
	 cout<<"\nPAYMENT(CREDIT CARD ONLY)"<<endl;
	 V:cout<<"\nChoose credit card type:\n\t1.Visa\n\t2.Master card\n\t3.American Express\n\t4.RuPay"<<endl;
	 cout<<"(Enter option number : 1 or 2 or 3 or 4)"<<endl;
	 cin>>c_comp;
	 switch(c_comp)
	 {
		case 1:
		clrscr();
		cout<<"\nDo you want to :\t1.Enter details\t2.Go back"<<endl;
		cin>>op;
		if(op==2)
		 goto V;
		else if(op==1)
		{
		  clrscr();
		  cout<<"WELCOME TO VISA ONLINE PAYMENT COUNTER"<<endl;
		  cout<<"\nEnter credit card number : ";
		  gets(c_crd_no);
		  cout<<"\nEnter card expiry date : "<<endl;
		  cin>>c_exp.dd;
		  cin>>c_exp.mm;
		  cin>>c_exp.yy;
		  cout<<"\nEnter CVV"<<endl;
		  for(u=0;u<3;u++)
		  {
			CVV[0]=getch();
			if(CVV[0]!='\r')
			{
			 putch('*');
			}
		  }
		  CVV[u]='\0';
		}
		break;
		case 2:
		clrscr();
		cout<<"\nDo you want to :\t1.Enter details\t2.Go back"<<endl;
		cin>>op;
		if(op==2)
		 goto V;
		else if(op==1)
		{
		  clrscr();
		  cout<<"WELCOME TO MASTER CARD ONLINE PAYMENT COUNTER"<<endl;
		  cout<<"\nEnter credit card number : ";
		  gets(c_crd_no);
		  cout<<"\nEnter card expiry date : "<<endl;
		  cin>>c_exp.dd;
		  cin>>c_exp.mm;
		  cin>>c_exp.yy;
		  cout<<"\nEnter CVV"<<endl;
		  for(u=0;u<3;u++)
		  {
			CVV[0]=getch();
			if(CVV[0]!='\r')
			{
			 putch('*');
			}
		  }
		  CVV[u]='\0';
		}
		break;
		case 3:
		clrscr();
		cout<<"\nDo you want to :\t1.Enter details\t2.Go back"<<endl;
		cin>>op;
		if(op==2)
		 goto V;
		else if(op==1)
		{
		  clrscr();
		  cout<<"WELCOME TO AMERICAN EXPRESS ONLINE PAYMENT COUNTER"<<endl;
		  cout<<"\nEnter credit card number : ";
		  gets(c_crd_no);
		  cout<<"\nEnter card expiry date : "<<endl;
		  cin>>c_exp.dd;
		  cin>>c_exp.mm;
		  cin>>c_exp.yy;
		  cout<<"\nEnter CVV"<<endl;
		  for(u=0;u<3;u++)
		  {
			CVV[0]=getch();
			if(CVV[0]!='\r')
			{
			 putch('*');
			}
		  }
		  CVV[u]='\0';
		}
		break;
		case 4:
		clrscr();
		cout<<"\nDo you want to :\t1.Enter details\t2.Go back"<<endl;
		cin>>op;
		if(op==2)
		 goto V;
		else if(op==1)
		{
		  clrscr();
		  cout<<"WELCOME TO RuPay ONLINE PAYMENT COUNTER"<<endl;
		  cout<<"\nEnter credit card number : ";
		  gets(c_crd_no);
		  cout<<"\nEnter card expiry date : "<<endl;
		  cin>>c_exp.dd;
		  cin>>c_exp.mm;
		  cin>>c_exp.yy;
		  cout<<"\nEnter CVV"<<endl;
		  for(u=0;u<3;u++)
		  {
			CVV[0]=getch();
			if(CVV[0]!='\r')
			{
			 putch('*');
			}
		  }
		  CVV[u]='\0';
		}
		break;
	 }
	 cout<<"\nPress any key to continue"<<endl;
	 getch();
	 clrscr();
	 int x1=0,y1=6;
	 gotoxy(24,2);
	 cout<<"WElCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
	 gotoxy(28,3);
	 cout<<"BOOKING DETAILS";
	 gotoxy(0,5);
	 cout<<"\nThe details of your ticket are ";
	 y1++;
	 gotoxy(x1,y1);
	 cout<<"Customer Number";
	 x1+=20;
	 gotoxy(x1,y1);
	 cout<<tc_code;
	 y1++;
	 x1=0;
	 gotoxy(x1,y1);
	 cout<<"Name";
	 x1+=20;
	 gotoxy(x1,y1);
	 puts(c_name);
	 y1++;
	 x1=0;
	 gotoxy(x1,y1);
	 cout<<"Movie code";
	 x1+=20;
	 gotoxy(x1,y1);
	 cout<<tm_no;
	 y1++;
	 x1=0;
	 gotoxy(x1,y1);
	 while(f.read((char*)&mo,sizeof(mo)))
	 {
			if(tm_no==mo.m_no())
			{
			  gotoxy(x1,y1);
			  cout<<"Movie Name";
			  x1+=20;
			  gotoxy(x1,y1);
			  puts(mo.m_name);
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Language";
			  x1+=20;
			  gotoxy(x1,y1);
			  puts(mo.lang);
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Rating";
			  x1+=20;
			  gotoxy(x1,y1);
			  cout<<mo.rat;
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Your seat numbers";
			  x1+=20;
			  gotoxy(x1,y1);
			  for(int i=0,j=0;i<tno,seat_no[i][j]!='\0';i++)
			  {
				 //for(int j=0;seat_no[i][j]!='\0';j++)
				  cout<<seat_no[i];
				 cout<<"  ";
			  }
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Date of show";
			  x1+=20;
			  gotoxy(x1,y1);
			  if(op1=='A'||op1=='a')
				cout<<mo.d1.dd<<" / "<<mo.d1.mm<<" / "<<mo.d1.yy;
			  else if(op1=='B')
				cout<<mo.d2.dd<<" / "<<mo.d2.mm<<" / "<<mo.d2.yy;
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Show Time";
			  x1+=20;
			  gotoxy(x1,y1);
			  if((op2=='P'||op2=='p')&&(op1=='A'||op1=='a'))
				cout<<mo.d1.t1.h<<" : "<<mo.d1.t1.m;
			  else if((op2=='Q'||op2=='q')&&(op1=='A'||op1=='a'))
				cout<<mo.d1.t2.h<<" : "<<mo.d1.t2.m;
			  else if((op2=='R'||op2=='r')&&(op1=='A'||op1=='a'))
				cout<<mo.d1.t3.h<<" : "<<mo.d1.t3.m;
			  else if((op2=='P'||op2=='p')&&(op1=='B'||op1=='b'))
				cout<<mo.d2.t1.h<<" : "<<mo.d2.t1.m;
			  else if((op2=='Q'||op2=='q')&&(op1=='B'||op1=='b'))
				cout<<mo.d2.t2.h<<" : "<<mo.d2.t2.m;
			  else if((op2=='R'||op2=='r')&&(op1=='C'||op1=='c'))
				cout<<mo.d2.t3.h<<" : "<<mo.d2.t3.m;
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Total price";
			  x1+=20;
			  gotoxy(x1,y1);
			  cout<<price;
			  break;
			}
	 }
	 x1=0;
	 y1++;
	 gotoxy(x1,y1);
	 cout<<"Mobile number";
	 x1+=20;
	 gotoxy(x1,y1);
	 puts(c_mobile);
	 x1=0;
	 y1++;
	 gotoxy(x1,y1);
	 cout<<"Email id";
	 x1+=20;
	 gotoxy(x1,y1);
	 puts(c_mail);
	 char fc;
	 cout<<"\n\nPress Y to confirm"<<endl;
	 cin>>fc;
	 if(fc=='Y'||fc=='y')
	 {
		f1.write((char*)&mc,sizeof(mc));

		f.close();
		f1.close();
		clrscr();
		cout<<"\nThankyou for booking at PVR(ORION).Your booking has been confirmed :D "<<endl;
		cout<<"\nEnjoy your show!! :D :D "<<endl;
		cout<<"\nPress any key to exit"<<endl;
		getch();
		clrscr();
		gotoxy(35,10);
		cout<<"GOOD BYE!! :( ";
		gotoxy(30,12);
		cout<<"PLEASE VISIT US AGAIN!!"<<endl;
		exit(0);
	 }
}
void mov_cust::view_book()
{
	 fstream f;
	 f.open("movie.dat",ios::in|ios::binary);
	 clrscr();
	 int x1=0,y1=6;
	 gotoxy(24,2);
	 cout<<"WElCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
	 gotoxy(28,3);
	 cout<<"BOOKING DETAILS";
	 gotoxy(0,5);
	 cout<<"\nThe details of the ticket(s) are "<<endl;
	 y1++;
	 gotoxy(x1,y1);
	 cout<<"Customer Number";
	 x1+=20;
	 gotoxy(x1,y1);
	 cout<<c_code();
	 y1++;
	 x1=0;
	 gotoxy(x1,y1);
	 cout<<"Name";
	 x1+=20;
	 gotoxy(x1,y1);
	 puts(c_name);
	 y1++;
	 x1=0;
	 gotoxy(x1,y1);
	 cout<<"Movie code";
	 x1+=20;
	 gotoxy(x1,y1);
	 cout<<cm_no();
	 y1++;
	 x1=0;
	 gotoxy(x1,y1);
	 while(f.read((char*)&mo,sizeof(mo)))
	 {
			if(cm_no()==mo.m_no())
			{
			  cout<<"Movie Name";
			  x1+=20;
			  gotoxy(x1,y1);
			  puts(mo.m_name);
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Language";
			  x1+=20;
			  gotoxy(x1,y1);
			  puts(mo.lang);
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Rating";
			  x1+=20;
			  gotoxy(x1,y1);
			  cout<<mo.rat;
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Your seat numbers";
			  x1=20;
			  gotoxy(x1,y1);
			  for(int i=0;i<ct_no;i++)
			  {
				 for(int j=0;seat_no[i][j]!='\0';j++)
				  cout<<seat_no[i][j];
				 cout<<"  ";
			  }
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Date of show";
			  x1+=20;
			  gotoxy(x1,y1);
			  if(opt1()=='A'||opt1()=='a')
				cout<<mo.d1.dd<<" / "<<mo.d1.mm<<" / "<<mo.d1.yy;
			  else if(opt1()=='B'||opt1()=='b')
				cout<<mo.d2.dd<<" / "<<mo.d2.mm<<" / "<<mo.d2.yy;
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Show Time";
			  x1+=20;
			  gotoxy(x1,y1);
			  if((opt2()=='P'||opt2()=='p')&&(opt1()=='A'||opt1()=='a'))
				cout<<mo.d1.t1.h<<" : "<<mo.d1.t1.m;
			  else if((opt2()=='Q'||opt2()=='q')&&(opt1()=='A'||opt1()=='a'))
				cout<<mo.d1.t2.h<<" : "<<mo.d1.t2.m;
			  else if((opt2()=='R'||opt2()=='r')&&(opt1()=='A'||opt1()=='a'))
				cout<<mo.d1.t3.h<<" : "<<mo.d1.t3.m;
			  else if((opt2()=='P'||opt2()=='p')&&(opt1()=='B'||opt1()=='b'))
				cout<<mo.d2.t1.h<<" : "<<mo.d2.t1.m;
			  else if((opt2()=='Q'||opt2()=='q')&&(opt1()=='B'||opt1()=='b'))
				cout<<mo.d2.t2.h<<" : "<<mo.d2.t2.m;
			  else if((opt2()=='R'||opt2()=='r')&&(opt1()=='C'||opt1()=='c'))
				cout<<mo.d2.t3.h<<" : "<<mo.d2.t3.m;
			  y1++;
			  x1=0;
			  gotoxy(x1,y1);
			  cout<<"Total price";
			  x1+=20;
			  gotoxy(x1,y1);
			  cout<<price;
			}
	 }
	 x1=0;
	 y1++;
	 gotoxy(x1,y1);
	 cout<<"Mobile number";
	 x1+=20;
	 gotoxy(x1,y1);
	 puts(c_mobile);
	 x1=0;
	 y1++;
	 gotoxy(x1,y1);
	 cout<<"Email id";
	 x1+=20;
	 gotoxy(x1,y1);
	 puts(c_mail);
}
void mov_cust::seat_disp(int tm_no,char op1,char op2)
{
	 clrscr();
	 fstream f;
	 int x=5,y=1,r=0,x1=0,y1=3;
	 char h1=65;
	 f.open("movie.dat",ios::in|ios::out|ios::binary);
	 while(f.read((char*)&mo,sizeof(mo)))
	 {
		if(tm_no==mo.m_no())
		{
		  clrscr();
		  x=5;y=1;r=0;x1=0;y1=3;
		  for(int i=0;i<10;i++)
		  {
			 gotoxy(x,y);
			 cout<<h1++;
			 x=x+7;
		  }
		  for(i=0;i<10;i++)
		  {
			 gotoxy(x1,y1);
			 cout<<r++;
			 y1+=2;
		  }
		  x=5;y=3;
		  for(i=0;i<10;i++)
		  {
			 gotoxy(x,y);
			 for(int j=0;j<10;j++)
			 {
				gotoxy(x,y);
				if(op1=='A'||op1=='a')
				{
				 if(op2=='P'||op2=='p')
				  cout<<mo.seat1[i][j]<<"       ";
				 else if(op2=='Q'||op2=='q')
				  cout<<mo.seat2[i][j]<<"       ";
				 else cout<<mo.seat3[i][j]<<"       ";
				}
				else if(op1=='B'||op1=='b')
				{
				 if(op2=='P'||op2=='p')
				  cout<<mo.seat4[i][j]<<"       ";
				 else if(op2=='Q'||op2=='q')
				  cout<<mo.seat5[i][j]<<"       ";
				 else cout<<mo.seat6[i][j]<<"       ";
				}
				x+=7;
			 }
			 x=5;
			 y+=2;
		  }
		  gotoxy(0,22);
		  cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
		  gotoxy(37,24);
		  cout<<"SCREEN";
		  break;
	  }
	 }
	 f.close();
}
void pwd_chk()
{
  for(u=0;;u++)
  {
	 tpass[u]=getch();
	 if(tpass[u]!='\r')
	 {
		if(tpass[u]==' ')
		{
		 cout<<"\b"; //change three
		 u-=2;      //change four
		 continue;
		}
		else
		{
		 putch('*');
		}
	 }
	 else if(tpass[u]=='\r')
	  break;
  }

  tpass[u]='\0';
}
void main()
{
  int op,op1,op2;
  int tcc,chk=-1,tmno;
  fstream f;
  strcpy(password,"employee123");
  G:clrscr();
  gotoxy(24,2);
  cout<<"\n\t\t\t\tHELLO!!\n\t\t  WELCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
  cout<<"\n\nWatch The best movies here for the best experience!! :D "<<endl;
  cout<<"\n1.Do you want to continue on to our wonderful website :D \n\t\tOR\n2.Do you want to exit? :("<<endl;
  cin>>op1;
  switch(op1)
  {
	 case 1:
	 W:clrscr();
	 cout<<"\n\nWe are always here to help... :) You are ? :\n\t1.Employee\n\t2.Customer"<<endl;
	 cin>>op;
	 switch(op)
	 {
		case 1:
		A:clrscr();
		tpass[0]='\0';
		gotoxy(24,2);
		cout<<"WELCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
		gotoxy(24,3);
		cout<<"\t\t EMPLOYEES SECTION"<<endl;
		cout<<"\nPlease confirm that you are an an employee by entering the password(use space to delete) "<<endl;
		cout<<"PASSWORD : ";
		do
		{
		  if(v>1)
		  {
			 tpass[0]='\0';  //change two
			 cout<<"\nIncorrect password,re enter password please(use space to delete)"<<endl;
			 cout<<"PASSWORD : ";
		  }
		  pwd_chk();
		  if(v==5&&strcmpi(password,tpass)!=0)
		  {
			 clrscr();
			 v=1;
			 cout<<"\nNot more than 5 attempts"<<endl;
			 goto G;
		  }
		  v++;
		}while(strcmpi(password,tpass)!=0);
		if(strcmpi(password,tpass)==0)
		{
		  clrscr();
		  v=1;       //change one
		  gotoxy(24,2);
		  cout<<"WELCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
		  gotoxy(24,3);
		  cout<<"EMPLOYEES SECTION"<<endl;
		  A1:cout<<"\nDo you want to :\n\t1.Insert a new movie\n\t2.View all running movies\n\t3.Update existing movie details\n\t4.View customer details\n\t5.Go back to main menu"<<endl;
		  cin>>op2;
		  switch(op2)
		  {
			 case 1:
				clrscr();
				create();
				goto A1;
				break;
			 case 2:
				clrscr();
				disp_mov();
				goto A1;
				break;
			 case 3:
				clrscr();
				update_file();
				goto A1;
				break;
			 case 4:
				clrscr();
				view_cust();
				goto A1;
				break;
			 case 5:
				clrscr();
				goto G;
				break;
			 default:
				clrscr();
				cout<<"\nEnter valid option"<<endl;
				goto A1;
		  }
		}
		break;
		case 2:
		clrscr();
		chk=-1;
		gotoxy(24,2);
		cout<<"WELCOME TO PVR(ORION) ONLINE BOOKING"<<endl;
		gotoxy(24,3);
		cout<<"\t\t  CUSTOMER AREA"<<endl;
		Q:cout<<"\nDo you want to :\n\t1.View Current Showning Movies and Book tickets :D\n\t2.View your booking details\n\t3.Return to main menu"<<endl;
		cin>>op2;
		yes=0;           //change ten
		switch(op2)
		{
		  case 1:
		  clrscr();
		  yes=0;       //change eleven
		  mc.view_mov_det();
		  goto Q;
		  break;
		  case 2:
		  clrscr();
		  cout<<"\nEnter your customer code"<<endl;
		  cin>>tcc;
		  f.open("movcust.dat",ios::in|ios::binary);
		  while(f.read((char*)&mc,sizeof(mc)))
		  {

			 if(mc.c_code()==tcc)
			 {
				mc.view_book();
				chk++;
			 }
		  }
		  if(chk==-1)
		  {
			cout<<"\nSorry no record was found "<<endl;
			f.close();
			goto Q;
		  }
		  f.close();
		  goto Q;
		  break;
		  case 3:
		  clrscr();
		  goto G;
		  break;
		  default:
		  clrscr();
		  cout<<"\nEnter valid option"<<endl;
		  goto Q;
		}
		break;
		default :
		clrscr();
		goto W;
  }
  break;
  case 2:
  clrscr();
  gotoxy(35,10);
  cout<<"GOOD BYE!! :( ";
  gotoxy(30,12);
  cout<<"PLEASE VISIT US AGAIN!!"<<endl;
  exit(0);
  break;
  default:
  goto G;
  }
}
