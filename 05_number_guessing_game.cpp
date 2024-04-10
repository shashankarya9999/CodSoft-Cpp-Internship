#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main() 
{
        int n,random_number;  
      
        srand(time(0));
      
        n=100;
        random_number = rand() % n;
      
        int guess;
        
        while(guess != random_number)
        {
          cout << "Enter your guess: ";
          cin >> user_guess;
      
          if( guess == random_number )
          {
              cout << "Congratulations! You guessed the right number!" << endl;
          }
      
          else if( guess < random_number )
          {
              cout << "Your guess is too low. Enter a larger number" << endl;
          }
      
          else
          {
              cout << "Your guess is too high. Enter a smaller number" << endl;
          }
        }
      
        return 0;
}
