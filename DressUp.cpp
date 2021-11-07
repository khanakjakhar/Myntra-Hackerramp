#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
class Points
{
  friend class List;
 int day;
 int dailylogin;
 int outfitsuploaded;
 int outfitssold;
 int points;
 Points *next;

  public:

  Points(int);
  Points* print() const;
};

Points::Points(int day)
{
 this->day=day; 
 dailylogin=(rand()%2);
 if(dailylogin)
  outfitsuploaded=(rand()%4);
 else
  outfitsuploaded=0;
 if(outfitsuploaded)
  outfitssold=(rand()%10);
 else 
  outfitssold=0;
 points=dailylogin*50-outfitsuploaded*200+outfitssold*500;
 next=NULL;
}

Points *Points::print() const
{
 cout<<"Day : "<<day;
 if(day>=100)
  cout<<"  Daily Login : ";
 else if(day>=10)
  cout<<"   Daily Login : ";
 else
  cout<<"    Daily Login : ";
 if(dailylogin)
  cout<<"Yes   ";
else
  cout<<"No    ";
cout<<"Outfits Uploaded : "<<outfitsuploaded<<"    Outfits Sold : "<<outfitssold<<"\n";
 return next;
}

class List
{
  Points *start,*last;
 public:
  List();
  void append(int); 
  void print() const;
  int totalpoints();
};

List::List()
{
 start=last=NULL;
}

void List::append(int day)
{
 Points *nd=new Points(day);
 if(start==NULL)
  start=nd;
 else
  last->next=nd;  
 last=nd;
}

void List::print() const
{
 Points *ptr=start;
 while(ptr)
 {
  ptr=ptr->print();
 }
}

int List::totalpoints()
{
  int total,outfits=0;
  Points *ptr=start;
  while(ptr)
  {
    total+=ptr->points;
    outfits+=ptr->outfitssold;
    ptr=ptr->next;
  }
  if(outfits>=100)
    cout<<"\nCongratulations!! You're an Influencer!!\n";
  if(outfits>=50)
    cout<<"\nCongratulations!! You're a Fashion Advisor!!\n";
  if(outfits>=10)
  {
    total+=1000;
    cout<<"\nCongratulations!! You've received 1000 points extra on selling 10 outfits!!\n";
  }
  if(outfits>=1)
  {
    total+=50;
    cout<<"\nCongratulations!! You've received 50 points extra on selling your first outfit!!\n";
  }
  return total;
}

main()
{
 List p;

 srand((unsigned)time(0));
 cout<<"\nWelcome to the demo of DRESS UP Points Updation System  \n                                                          \nRules are as follows :       Daily login  +50 points      \n                           Upload Outfit  -200 points     \n                             Outfit Sold  +500 points     \n                         1st Outfit Sold  +50 points      \n                         10 Outfits Sold  +1000 points    \n                         50 Outfits Sold  Fashion Advisor \n                        100 Outfits Sold  Influencer      \n";
 cout<<"\n**One point is worth 0.01 Rs.**\n";
 int n;
 cout<<"\nEnter Number of Days of Demo to be Displayed : ";
 cin>>n;

 for(int i=0;i<n;i++)
  p.append(i);

cout<<"\nPoints Updation for "<<n<<" Days  \n\n";
p.print();
cout<<"\nTotal Points : "<<p.totalpoints()<<"          \n";

}