#include<fstream.h>
#include<conio.h>
#include<stdio.h>
class product
{
 int prodid;
 char prodname[30];
 int prodprice;
 public:
 void input()
 {
 cout<<"Enter product id:";
 cin>>prodid;
 cout<<"Enter product name:";
 gets(prodname);
 cout<<"Enter product price:";
 cin>>prodprice;
 }
  void output()
 {
 cout<<"Product id : "<<prodid<<endl;
 cout<<"Product name : "<<prodname<<endl;
 cout<<"Product price : "<<prodprice<<endl;
 }
 };
 void main()
 {
 clrscr();
 product p;
 int n;
 fstream f;
 f.open("PRODUCT.dat",ios::out|ios::binary);
 cin>>n;
 for(int i=0;i<n;++i)
 {
 p.input();
 f.write((char*)&p,sizeof(p));
 }
 getch();
 }