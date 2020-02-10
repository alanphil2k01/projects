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
 int getpid()
 {
 return prodid;
 }
};
class cart
{
 public:
 void append()
 {
 product p;
 fstream f1,f2;
 int x;
 f1.open("PRODUCT.dat",ios::binary|ios::in);
 f2.open("CART.dat",ios::binary|ios::out|ios::app);
 cout<<"Enter product id to add : ";
 cin>>x;
 while(f1.read((char*)&p,sizeof(p)))
 {
 if(x==p.getpid())
 f2.write((char*)&p,sizeof(p));
 }
 f1.close();
 f2.close();
 cout<<"Product Added"<<endl;
 }
 void del_ete()
 {
 int x;
 product p;
 fstream f1,f2;
 f1.open("TEMP.dat",ios::out|ios::binary);
 f2.open("CART.dat",ios::in|ios::binary);
  cout<<"Enter product id to delete:";
  cin>>x;
  while(f2.read((char *)&p,sizeof(p)))
  if(p.getpid()!=x)
  f1.write((char *)&p,sizeof(p));
  f1.close();
  f2.close();
  remove("CART.dat");
  rename("TEMP.dat","CART.dat");
  cout<<"Product Deleted"<<endl;
 }
void display()
{
product p;
fstream f;
f.open("CART.dat",ios::in|ios::binary);
while(f.read((char*)&p,sizeof(p)))
{
p.output();
}
f.close();
}
};
void main()
{
clrscr();
char c1;
int ch;
fstream f;
product p;
cart c;
cout<<"Welcome To GALATECH!"<<endl;
do
{
cout<<"Our Products:-"<<endl;
f.open("PRODUCT.dat",ios::binary|ios::in);
while(f.read((char*)&p,sizeof(p)))
p.output();
f.close();
cout<<"\n\n\tMenu\n1)Add item to cart\n2)Show products in cart\n3)Delete an item in cart\n";
cout<<"Enter choice:";
cin>>ch;
if(ch==1)
c.append();
if(ch==2)
c.display();
if(ch==3)
c.del_ete();
cout<<"Do you want to continue : ";
cin>>c1;
clrscr();
f.close();
}
while(c1=='y');
cout<<"Thanksfor shopping!";
remove("CART.dat");
getch();
}

