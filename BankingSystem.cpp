#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
class Bank
{
    public:
    string name;
    int pin ;
    long int bal ;
    void create();    
    void login(int x);
    vector<string> row;
    vector<string> acc_no;
 };
void Bank::create()
    {
        cout << "Enter you name: " << endl;
        cin.ignore();
        cin >> name ;
        cout << "Enter your pin: " << endl;
        cin >> pin ;
        cout << "Enter starting balance: " << endl;
        cin >> bal ;
        fstream fin ;
        fin.open("AccountNo.csv", ios::in);
        string no , num ;
        getline(fin , no );
        stringstream ss(no);
        while(getline(ss,num,','))
        {acc_no.push_back(num);}
        int acc;        
        acc = stoi(acc_no.back());                 
        acc_no.clear();
        fstream fout ;
        fout.open("Record.csv", ios::out| ios::app);
        fout << acc << "," << name << "," << pin << "," << bal << "," << endl;
        cout << "Your account has been created .... \t Account No is : " << acc << "\n\n";
        acc++;
        fstream foute ;
        foute.open("AccountNo.csv", ios::out|ios::app);
        foute << acc << ',';

    }
    void Bank::login(int x)
    {
        int bal , pi , acc;
        fstream fin;
        fstream fine;
        fin.open("Record.csv",ios::in);
        fine.open("AccountNo.csv", ios::in);
        string word , line , acc_n , no;
        while(!fine.eof())
        {
            //row.clear();
            getline(fine,acc_n);
            stringstream s(acc_n);
            while(getline(s,no,','))
            {
                acc_no.push_back(no);
            }             
            acc = stoi(acc_no.back()); 
            acc_no.clear();
        }
        while(!fin.eof())    
        {
            row.clear();
            getline(fin , line) ;
            stringstream sb(line);
            while(getline(sb,word , ','))
            {
                row.push_back(word);
            }
            bal = stoi(row[3]);
            pi = stoi(row[2]);
        }   
        if(x == acc)
            {
                int p;
                cout << "Enter the pin : " << endl ;
                cin >> p;
            if ( pi == p)
            {
            int ch , e=0;
            cout << "You have successfully logged in to the account....\n\n ";
            cout << "MENU: \n\n" ;
            do{
            cout << "1 - Display details \n2-Deposit money \n3-Withdraw money \n4-Check predicted amount \n5-EXIT \n Enter your choice: ";
            cin >>  ch;
            switch(ch)
            {
                case 1 :{
                cout << "Account No: " << x << endl;
                cout << "Balance: "<< bal << endl;
                cout << "Name: " << row[1] << endl;
                cout << "Pin: " << p << "\n\n";
                break;}
                
                case 2:{
                int d;
                cout << "How much do you want to deposit: ";
                cin>> d;
                bal += d;
                cout << "New Balance: " << bal << "\n\n";
                break ;}
                
                case 3:{
                int w , b ;
                cout << "How much do you want to withdraw: ";
                cin>> w;
                if(bal >= w){
                bal -= w;
                cout << "New Balance: " << bal << endl;}
                else{
                    cout << "Amount larger than " << bal << " cannot be withdrawn...\n\n" ;
                }
                break ;}
                
                case 4:{ 
                int t;
                cout << "The interest rate is 10% (compounded annually) \n" ;
                cout << "Enter the number of years you wish to store money: ";
                cin >> t ;
                int b = bal ;
                for(int i =1 ; i<=t; i++)
                b*= (1.1);
                cout << "Final amount will be : " << b << "\n\n";
                break; }

                case 5 :
                cout << "Do you want exit the current account?? IF YES THEN ENTER 1 \n" ;
                cin >> e;
                break;
                default :
                cout << "Wrong choice entered ....\n" << endl;
            }
            }while(e!=1);
        }
        else
        cout << "Wrong pin entered....\n\n";
            }
    }
    
int main()
{
    Bank v;
    int che , e =0;
    cout << "Welcome to Varad's Bank: \n\n";
    do{
    cout << "What do you want to do: \n1-Create account \n2-Login into existing account \n3- Exit\n";
    cin >> che ;
    switch(che)
    {
        case 1: {
        v.create();
        break;}
        
        case 2:{
        int x;
        cout << "Enter the account number: " ;
        cin >> x;
        v.login(x) ;
        break;}
        
        case 3 :{
        cout << "DO U SURE U WISH TO DO THIS??? \nEnter 1\n" ;
        cin >> e;
        break ;}

        default :{
        cout << "Wrong choice entered ...." << endl;
        break;}
        }
    }while(e!=1);
    return 0;
}
