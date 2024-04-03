#include<iostream>

using namespace std;

int main()
{
    double num1, num2;
    char operation;
  
    cout << "Enter the First Number: ";
    cin >> num1;
    cout << "Enter the Second Number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /, %): ";
    cin >> operation;

    switch (operation)
    {
        case '+':
            cout << "Result: " << ( num1 + num2 ) << endl;
            break;
      
        case '-':
            cout << "Result: " << ( num1 - num2 ) << endl;
            break;
      
        case '*':
            cout << "Result: " << ( num1 * num2 ) << endl;
            break;
      
        case '/':
            if( num2 == 0 ) 
            {
                cout << "Error: Division by zero is undefined" << endl;
            } 
            
            else 
            {
                cout << "Result: " << (num1 / num2) << endl;
            }
            break;
      
        case '%':
            if( num2 == 0 )
            {
                cout << "Error: Division by zero is undefined" << endl;  
            }

            else
            {
                cout << "Result: " << (num1 % num2) << endl;
            }
            break;
      
        default:
            cout << "Please choose a valid operation!" << endl;
    }

    return 0;    
}
