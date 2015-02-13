//Programmer: Ryan Vasquez
//September 30, 2013
//Class: CS53 Section F
//Purpose: This program will will do fractions for Moe so he can learn to do
//math
#include <iostream>

using namespace std;

struct fraction
{
  long m_numer;
  long m_denom;
};

void Greetings();
//Desc: Greetings. This function is simply to output a welcome message.
//Input: none
//Output: Returns nothing, but outputs message to screen.
void Goodbyes();
//Desc: Goodbyes. This function is simply to output a parting message.
//Input: None
//Output: Returns nothing, but outputs message to screen.
int Display_menu();
//Desc: Display Menu function. This function is to display the menu and return
//valid character choice for that menu.
//Input: None
//Output: Returns character representing a valid menu choice.
void Enter_fractions(fraction& frac_1, fraction& frac_2);
//Desc: Enter fractions. This function will store keyboard input to memory for
//two fractions that are read in by user.
//Input: None.
//Output: Returns user input to calling function.
void Display_Fraction(const fraction frac_1);
//Desc: Display fraction. This function is to display to the screen a fraction
//(sent to it) in standard format: a/b
//Input: A fraction.
//Output: Returns nothing, but outputs the fraction to screen.
fraction Add_fractions(fraction frac_1, fraction frac_2);
//Desc: Add fraction. This function will compute the (unsimplified) sum of the
//two fractions passed to it and return that result.
//Input: Two fractions.
//Output: a fraction
fraction Divide_fractions(fraction frac_1, fraction frac_2);
//Desc: Divide fraction.This function will compute the (unsimplified) quotient
//of the two fractions passed to it and return that result.
//Input: Two fractions.
//Output: a fraction
void Simplify_fractions(fraction& frac_1, fraction& frac_2);
//Desc: The simplify function. This function will "simplify" a fraction that is
//passed to it.
//Input: A fraction.
//Output: The input fraction is simplified.



int main()
{
  fraction firstn, secondn, result_frac; //These three fraction objects are the
  //first, second, and result_frac. They represent the first 2 fractions the
  //inputs and result frac represents the output for the math operations that
  //the user executes.
  int menu_choice;
  bool has_entered_fraction = 0;// Initialized to false to show that the user
  //has not yet entered a fraction.
  Greetings();
  do
  {
    menu_choice = Display_menu();
    switch(menu_choice)
    {
      case 1:
      Enter_fractions(firstn, secondn); //calls the enter fractions function
      has_entered_fraction = 1;
      break;
      case 2:
      if (has_entered_fraction)
      {
        result_frac = Add_fractions(firstn, secondn);
        cout<<"Result:"<<endl;
        Display_Fraction(result_frac);
      }

      else
      {
        cout<<"Please select option 1 and enter fractions first"<<endl;
      }
      break;
      case 3:
      if(has_entered_fraction)
      {
        result_frac = Divide_fractions(firstn, secondn);
        cout<<"Result:"<<endl;
        Display_Fraction(result_frac);
      }
      else
      {
        cout<<"Please select option 1 and enter fractions first"<<endl;
      }
      break;
      case 4:
      if(has_entered_fraction)
      {
        Simplify_fractions(firstn, secondn);
        cout<<"Result fraction 1:"<<endl;
        Display_Fraction(firstn);
        cout<<"Result fraction 2:"<<endl;
        Display_Fraction(secondn);
      }

      else
      {
        cout<<"Please select option 1 and enter fractions first"<<endl;
      }
      break;
    }
  }while(menu_choice != 5);
  return 0;
}


void Greetings()
{
cout<<"Welcome to moes math program thingy!"<<endl;
cout<<" _____________________"<<endl;
cout<<"|  _________________  |"<<endl;
cout<<"| |    3.14159265359| |"<<endl;
cout<<"| |_________________| |"<<endl;
cout<<"|  ___ ___ ___   ___  |"<<endl;
cout<<"| | 7 | 8 | 9 | | + | |"<<endl;
cout<<"| |___|___|___| |___| |"<<endl;
cout<<"| | 4 | 5 | 6 | | - | |"<<endl;
cout<<"| |___|___|___| |___| |"<<endl;
cout<<"| | 1 | 2 | 3 | | x | |"<<endl;
cout<<"| |___|___|___| |___| |"<<endl;
cout<<"| | . | 0 | = | | / | |"<<endl;
cout<<"| |___|___|___| |___| |"<<endl;
cout<<"|_____________________|"<<endl;
cout<<"This program can add, divide and multiply fractions"<<endl;
}

void Goodbyes()
{
  cout<<"Thanks for learning math Moe!"<<endl;
}

int Display_menu()
{
  int menu_choice;
  cout<<" ________________________________"<<endl;
  cout<<"|                                |"<<endl;
  cout<<"|           Menu                 |"<<endl;
  cout<<"|________________________________|"<<endl;
  cout<<"|                                |"<<endl;
  cout<<"|1. Enter Fractions              |"<<endl;
  cout<<"|2. Add Fractions                |"<<endl;
  cout<<"|3. Divide Fractions             |"<<endl;
  cout<<"|4. Simplify Fractions           |"<<endl;
  cout<<"|5. Quit                         |"<<endl;
  cout<<"|________________________________|"<<endl;
  cout<<"|Please Enter your menu choice   |  ";
  cin>>menu_choice;
  while(menu_choice > 5 || menu_choice < 1)
  {
    cout<<"Please enter a valid menu choice option:  ";
    cin>>menu_choice;
  }
  return menu_choice;
}


void Enter_fractions(fraction& frac_1, fraction& frac_2)
{
  cout<<"Please enter the numerator of fraction 1:  ";
  cin>>frac_1.m_numer;
  cout<<"Please enter the denominator of fraction 1:   ";
  cin>>frac_1.m_denom;
  while(frac_1.m_denom == 0)//Makes sure that the user enters a valid
  //denominator for a fraction. If the user does not enter a valid
  //fraction it will prompt the user again.
  {
    cout<<"This is an invalid denominator for a fraction"<<endl;
    cout<<"A computer cannnot divide by zero"<<endl;
    cout<<"Please re-enter your denominator";
    cin>>frac_1.m_denom;
  }
  cout<<"Please enter the numerator of fraction 2:   ";
  cin>>frac_2.m_numer;
  cout<<"Please enter the denominator of fraction 2:   ";
  cin>>frac_2.m_denom;
  while(frac_2.m_denom == 0)//Makes sure that the user enters a valid
  //denominator for a fraction. If the user does not enter a valid
  //fraction it will prompt the user again.
  {
    cout<<"This is an invalid denominator for a fraction"<<endl;
    cout<<"A computer cannnot divide by zero"<<endl;
    cout<<"Please re-enter your denominator";
    cin>>frac_2.m_denom;
  }
  cout<<"The fractions you just entered are:"<<endl;
  cout<<"Fraction 1: "<<endl;
  Display_Fraction(frac_1);
  cout<<"Fraction 2: "<<endl;
  Display_Fraction(frac_2);
}

void Display_Fraction(const fraction frac_1)
{
  cout<<frac_1.m_numer<<endl;
  cout<<"-"<<endl;
  cout<<frac_1.m_denom<<endl;
}


fraction Add_fractions(const fraction frac_1,const fraction frac_2)
{
  fraction return_frac;
  if(frac_1.m_denom == frac_2.m_denom) //This if statement will help
  //the addition of fractions go faster.
  {
    return_frac.m_numer= frac_1.m_numer+frac_2.m_numer;
    return_frac.m_denom = frac_1.m_denom;
  }
  else
  {
    //This math operation will happen only if the denominators
    //of the two function is not the same.
    return_frac.m_numer = (frac_1.m_numer*frac_2.m_denom)+
      (frac_2.m_numer*frac_1.m_denom);
    return_frac.m_denom = frac_1.m_denom*frac_2.m_denom;
  }
  return return_frac;
}

fraction Divide_fractions(const fraction frac_1,const fraction frac_2)
{
  fraction return_frac;
  return_frac.m_numer = frac_1.m_numer*frac_2.m_denom;
  return_frac.m_denom = frac_1.m_denom*frac_2.m_numer;
  return return_frac;
}


void Simplify_fractions(fraction& frac_1, fraction& frac_2)
{
  //fraction frac_1, frac_2;
  //frac_1 = frac_3;
  //frac_2 = frac_4;
  for(int i = 2; i <= frac_1.m_numer || (frac_1.m_denom%i == 0 &&
    frac_1.m_numer%i == 0); i++)//The for loop starts at 2 because all numbers
    // are divisible by 1, but not by 2
    {
      while (frac_1.m_denom%i == 0 && frac_1.m_numer%i == 0)//This loop
      //will repeat until the fraction be reduced anymore by factor i
      {
        frac_1.m_denom = frac_1.m_denom/i;
        frac_1.m_numer = frac_1.m_numer/i;
      }
    }
  for(int i = 2; i <= frac_2.m_numer || (frac_2.m_denom%i == 0 &&
    frac_2.m_numer%i == 0) ; i++)
    {
      while (frac_2.m_denom%i == 0 && frac_2.m_numer%i == 0)
      {
        frac_2.m_denom = frac_2.m_denom/i;
        frac_2.m_numer = frac_2.m_numer/i;
      }
    }
}
