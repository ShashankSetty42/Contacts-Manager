#include<iostream>
#include<string>
#include<c:\timeanddate.h>
#include<fstream>
#include<windows.h>

using namespace std;
int flag=0;
int in=0;

void Output(char a[200])
{
 int n=0;
 while(a[n]!='\0')
 {
  cout <<a[n];
	Sleep(5);
	n++;
 };
}

class Contact
{
    private:

     char Name[50];
     char Num[10];

    public:
    //operator overloading
        friend istream& operator >> (istream &in, Contact &str)
        {
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout<<"\nenter contact name: ";
            in>>str.Name;
            cout<<"\nenter contact number: ";
            in>>str.Num;
            if(strlen(str.Num)<10||isalpha(str.Num[1]))
               {
                     cout<<"\nPlease Enter a valid Number\n";
                     cin>>str.Num;
               }
            return in;
        }

        friend ostream& operator << (ostream &out, Contact &str)
        {
            if( str.Name[0]=='*') return out;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout<<"\ncontact details are:\n";
            out<<"Name: "<<str.Name<<"\n"<<"Number: "<<str.Num<<endl;
            return out;
        }
        void DeleteC()
        {
            Name[0]='*';
        }
        friend string GetName(Contact);
        friend string GetNum(Contact);
        friend void SetName(Contact &,string);
        friend void SetNum(Contact &,string);
        friend char Getd(Contact);
};
//set and get methods
char Getd(Contact obj)
{
    return obj.Name[0];
}
string GetName(Contact obj)
{
    return obj.Name;
}
string GetNum(Contact obj)
{
    return obj.Num;
}
void SetName(Contact &obj, string name)
{
    name.copy(obj.Name,50);
}
void SetNum(Contact &obj, string num)
{
    num.copy(obj.Num,10);
}

class AddressBook
{

    public:
        static int n;
        Contact Rec[];
        void Choice()
        {
            int c;
            for(;;)
            {
               cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
               Output("\n1. Add\n2. Display\n3. Find contact\n4. update\n5. Delete Contact\n6. Go back\n");
               cout<<"enter your choice: ";
               cin>>c;
               switch(c)
               {
                   case 1 : Add();
                            n++;
                            break;
                   case 2 : Display();
                            break;
                   case 3 : FindContact();
                            break;
                   case 4 : Update();
                            break;
                   case 5 : DeleteContact();
                            break;
                   case 6 : return;

                   default :cout<<"Invalid Option!!\n";
                            return;

               }
            }
        }
        void Add()
        {
            cin>>Rec[n];
        }
        void Display()
        {
            for(int i=0;i<n;i++)
            cout<<Rec[i]<<endl;
        }



        void FindContact()
        {
            char name[50]; int flag;
            cout<<"enter the name you want to find\n";
            cin>>name;
            for(int i=0;i<=n;i++)
            {
                if(name==GetName(Rec[i]))
                   {
                        cout<<"\ncontact found!\n";
                        flag=1;
                        cout<<Rec[i];
                        break;
                   }
                else
                    {
                        flag=0;
                    }
            }
            if(flag);
            else cout<<"\nContact not found!\n";

        }
        void Update()
        {
            char input[50];
            int choice;
            char number[10],name[50];
            cout<<"\nenter the name or number of the contact you want to update\n";
            cin>>input;
            if(isdigit(input[1]))
               {
                for(int i=0;i<=n;i++)
                {
                    if(input==GetNum(Rec[i]))
                    {
                        cout<<"\ncontact found!\n\nwhat do you want to edit?\n1. Name\n2. Number\nenter your choice\n";
                        cin>>choice;
                        switch(choice)
                        {
                            case 1 : cout<<"\nenter new name\n";
                                     cin>>name;
                                     SetName(Rec[i],name);
                                     cout<<"\ncontact updated!\n";
                                     break;
                            case 2 : cout<<"\nenter new number\n";
                                     cin>>number;
                                     SetNum(Rec[i],number);
                                     cout<<"\ncontact updated!\n";
                                     break;
                        }
                        flag=1;
                        break;
                    }
                    else
                    {
                        flag=0;
                    }

                }
                if(flag);
                else cout<<"\nContact not found\n";
               }
               else if(isalpha(input[1]))
               {
                   for(int i=0;i<=n;i++)
                   {
                    if(input==GetName(Rec[i]))
                    {
                        cout<<"\ncontact found\nwhat do you want to edit?\n1. Name\n2. Number\nenter your choice\n";
                        cin>>choice;
                        switch(choice)
                        {
                            case 1 : cout<<"\nenter new name\n";
                                     cin>>name;
                                     SetName(Rec[i],name);
                                     cout<<"\ncontact updated!\n";
                                     break;
                            case 2 : cout<<"\nenter new number\n";
                                     cin>>number;
                                     SetNum(Rec[i],number);
                                     cout<<"\ncontact updated!\n";
                                      break;
                        }flag=1; break;
                    }
                    else
                    {
                        flag=0;
                    }

                }
                if(flag);
                else cout<<"\nContact not found\n";

               }

        }
        void DeleteContact()
        {
            int contact=1,choice;
            for(int i=0;i<n;i++)
            {
                cout<<contact<<". "<<GetName(Rec[i])<<endl;
                contact++;
            }
            cout<<"enter the index of the contact that you want to delete\n";
            cin>>choice;
            Rec[choice-1].DeleteC();
            cout<<"\nContact deleted!\n";
        }
};
int AddressBook::n=0;

class CallLogData
{
    public:
        char ContactName[50];
        int hour,mins,sec,day,month,year;
        char status;
};

void SetLogName(CallLogData &obj, string name)
{
    name.copy(obj.ContactName,50);
}
class Log: public AddressBook
{
    public:
            static int log;
            CallLogData obj[];
            void LogChoice()
            {
                int c;
                for(;;)
                {
                    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                    Output("\n1. Manage Contacts\n2. Call\n3. view call log\n4. list outgoing calls\n5. save call logs\n6. exit\n");
                    cout<<"enter your choice: ";
                    cin>>c;
                    switch(c)
                    {
                        case 1 : Choice();
                                 break;
                        case 2 : Call();
                                 break;
                        case 3 : ViewCallLog();
                                 break;
                        case 4 : ListOutCalls();
                                 break;
                        case 5 : SaveLog();
                                 break;
                        case 6 : cout<<"\n---------------------------------------------\n";
                                 cout<<"|            By Shashank Setty              |\n";
                                 cout<<"---------------------------------------------\n";
                                 Sleep(100);
                                 exit(0);


                        default :cout<<"enter valid option\n";
                                 break;

                    }

                }
            }
            void CopyNames()
            {
                for(int i=0;i<n;i++)
                {
                    SetLogName(obj[i],GetName(Rec[i]));
                }
            }
            void PlaceCall(string str)
            {
                char c;
                str.copy(obj[in].ContactName,50);
                obj[in].hour=Hour24();
                obj[in].mins=Min();
                obj[in].sec=Sec();
                obj[in].status='o';
                obj[in].day=Day();
                obj[in].month=Month();
                obj[in].year=Year();
                cout<<"\nCall Connected\n";
                cout<<"press y when you want to hang up\n";
                cin>>c;
                if(c=='Y'||c=='y')
                    {
                       int h=Hour24();
                       int m=Min();
                       int s=Sec();
                       int nh=h-obj[in].hour;
                       int nm=m-obj[in].mins;
                       int ns=s-obj[in].sec;
                       cout<<"Call Duration: "<<nh<<":"<<nm<<":"<<ns<<endl;
                       in++;
                    }
                else
                    cout<<"\nplease enter a valid option\n";

            }

            void Call()
            {
                int contact=1,choice;
                for(int i=0;i<n;i++)
                {
                    if( Getd(Rec[i])=='*')
                        continue;
                    cout<<contact<<". "<<GetName(Rec[i])<<endl;
                    contact++;
                }
                cout<<"enter the index of the contact that you want to call\n";
                cin>>choice;
                char temp[50];
                GetName(Rec[choice-1]).copy(temp,50);
                PlaceCall(temp);
                log++;
            }
            void ViewCallLog()
            {
                int i;
                cout<<"\nCall log:\n";
                for(i=0;i<=log;i++)
                    {
                        if(obj[i].status=='o')
                        {
                            cout<<"\nName: "<<obj[i].ContactName<<"\t";
                            cout<<"\nCall time: "<<obj[i].hour<<":"<<obj[i].mins<<":"<<obj[i].sec<<endl;
                            cout<<"Call Date: "<<obj[i].day<<"/"<<obj[i].month<<"/"<<obj[i].year<<endl;
                            cout<<"Status: "<<"Outgoing\n";
                        }
                    }
                    if(i=0)
                        cout<<"\nno calls.";
            }
            void ListOutCalls()
            {
                int i;
                cout<<"\nOutgoing calls:\n";
                for(i=0;i<=log;i++)
                {
                    if(obj[i].status=='o')
                    {
                        cout<<obj[i].ContactName<<"  called at->  "<<obj[i].hour<<":"<<obj[i].mins<<":"<<obj[i].sec;
                    }
                }
                    if(i=0)
                    {
                        cout<<"\nno outgoing calls\n";
                    }
            }
            void SaveLog()
            {
                char d[10],m[10],y[10];
                char temp[20];
                itoa(Day(),d,10);
                itoa(Month(),m,10);
                itoa(Year(),y,10);
                strcpy(temp,d);
                strcat(temp,"-");
                strcat(temp,m);
                strcat(temp,"-");
                strcat(temp,y);
                strcat(temp,".txt");
                ofstream files;
                files.open (temp);

                int i;
                files<<"\nCall log:\n";
                for(i=0;i<=log;i++)
                    {
                        if(obj[i].status=='o')
                        {
                            files<<"\nName: "<<obj[i].ContactName<<"\t";
                            files<<"\nCall time: "<<obj[i].hour<<":"<<obj[i].mins<<":"<<obj[i].sec<<endl;
                        }
                    }
                    if(i=0)
                        files<<"\nno calls.\n";
                files.close();
                cout<<"Call logs saved!\n";
            }
};
int Log::log=0;

int main()
{
    cout<<"\n---------------------------------------------\n";
    cout<<"|                 CONTACTS                  |\n";
    cout<<"|             MINI PROJECT WORK             |\n";
    cout<<"---------------------------------------------\n";
    Log a;
    a.LogChoice();
}
