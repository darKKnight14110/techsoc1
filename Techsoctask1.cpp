#include <iostream> 
using namespace std ; 
double expon ( double a , int b)
    {
        double pro=1 ;
        for ( int i =1 ; i <= b ; ++i)
        pro *= a ;
        return pro ;
    }
double fact(int x)
    {
        double fac =1;
        for ( int i =1 ; i <= x ; ++i)
        fac *= i;
        return fac ; 
    }
int main()
{
    int choice, restart , calc  ; 
    double num1 , num2 ;
    restart = 0 ;
    while( restart == 0)
    {
    cout << "Hello , Welcome to Varad's calculator." << endl ;
    cout << "Please enter your choice of operation to be performed: "<< endl << "1 - Addition" << endl << "2 - Subtraction" << endl << "3 - Multiplication" << endl <<"4 - Division" <<endl << "5 - Exponentation" << endl << "6 - Basic Trigonometric Funtions" << endl ;
    cin >> choice ;
        
        if ( choice == 1 )
    {
        cout << "Operation to be performed is addition." << endl; 
        cout << "Enter the two numbers : " << endl ; 
        cin >> num1 >> num2 ;
        cout << "The addition of " << num1 << " and " << num2 << " is : " << num1 + num2 << endl ;
    }
    else if(choice == 2)
    {
        cout << "Operation to be performed is subtraction." << endl; 
        cout << " Enter the number from which we have to subtract: " << endl ; 
        cin >> num1  ;
        cout << " Enter the number to be subtracted : " << endl ; 
        cin >> num2  ;
        cout << num1 << " - "<< num2 << " = " << num1 - num2 << endl ;       
    }
    else if(choice == 3)
    {
        cout << "Operation to be performed is multiplication." << endl; 
        cout << " Enter the two numbers : " << endl ; 
        cin >> num1 >> num2 ;
        cout << "The product of " << num1 << " and " << num2 << " is : " << num1 * num2 << endl ;    
    }
    else if(choice == 4)
    {
        double res;
        cout << "Operation to be performed is division." << endl; 
        cout << "Enter the numerator: " << endl ; 
        cin >> num1  ;
        cout << "Enter the denominator : " << endl ; 
        cin >> num2  ;
        res = num1 / num2 ;
        cout << num1 << " divided by "<< num2 << " = " << res << endl ; 
    }
    else if(choice == 5)
    {
        int expo=1 ;
        cout << "Operation to be performed is exponentation." << endl; 
        cout << "Enter the base: " << endl ; 
        cin >> num1  ;
        cout << "Enter the power: " << endl ; 
        cin >> num2  ;
        for ( int i =1 ; i <= num2 ; ++i)
        {  expo =  expo*num1 ;}        
        cout << num1 << " raised to "<< num2 << " = " << expo << endl; 
    }
    else if(choice == 6)
    {
        int deg ,deg2  , choice2 ; 
        
        cout << "Which trigonometric function do you want to perform: " << endl << "1- Sine function" << endl << "2- Cosine function" << endl << "3- Tangent function" << endl ;
        cin >> choice2 ;
        cout << "Enter the angle(in degrees):" << endl ;
        cin >> deg ;
        if(deg >180) {
        deg2= deg -  180 ;
        }
        double rad = (deg2*3.142)/180 ;
        double sum = 0;
        if( choice2 == 1)
             {   
                for(int i= 1; i < 100 ; i+=4)
                {
                    sum += expon(rad ,i ) / fact (i);
                }
                for(int i= 3; i < 100 ; i+=4)
                {
                    sum -= expon(rad ,i ) / fact (i);
                }
                cout << "The sine of " << deg<< " is  \n" << sum ;
            }
            else if( choice2 == 2)
            {
                sum = 1 ; 
                for(int i= 4; i < 100 ; i+=4)
                {
                    sum += expon(rad ,i ) / fact (i);
                }
                for(int i= 2; i < 100 ; i+=4)
                {
                    sum -= expon(rad ,i ) / fact (i);
                } 
                cout << "The cosine of" << deg << "is " << sum ;
            }
            else if( choice2 == 3)
            {
                double sine , cosine ;
                if(deg == 90)
                    cout << "The tangent of " << deg << " is not defined.";
                else 
                {
                    for(int i= 1; i < 1000 ; i+=4)
                    {
                    sine += expon(rad ,i ) / fact (i);
                    }
                    for(int i= 3; i < 1000 ; i+=4)
                    {
                    sine -= expon(rad ,i ) / fact (i);
                    }
                    cosine = 1 ; 
                    for(int i= 4; i < 1000 ; i+=4)
                    {
                    cosine += expon(rad ,i ) / fact (i);
                    }
                    for(int i= 2; i < 1000 ; i+=4)
                    {
                    cosine -= expon(rad ,i ) / fact (i);
                    }      
                    double tn = sine / cosine ;
                    cout << "The tangent of "<< deg << " is :" << tn << endl ;
                }
            }
            else 
            {
                cout << "Invalid choice entered...";
            }      
    }
    else
    {
        cout << "Invalid choice entered. Make sure to only enter the number..." << endl ;
    }
    cout << "Do you wish to restart the calculator : " << endl << "1 - YES" << endl << "2 -NO" << endl;
    cin >> calc ;
    if(calc == 1)
    restart = 0  ;
    else 
    {restart ++ ;
    cout << " Thank you !" << endl ;
    }
    }
} 
