/* 
 * File:   main.cpp
 * Author: Adams, Jonathan
 *
 * Created on April 19th, 2014 @ 09:30 AM
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
//Global Constants
//Function Prototypes
//Execution
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int short choose;
    char exit;
    //Welcome statement to not be looped
    cout<<"Welcome to the Aerospace and Powerplant Maintenance Helper."<<endl;
    //Prompt user for number of problem to execute
    cout<<endl;
    cout<<endl;
    do {                                                //MENU DO LOOP BEGIN
    cout<<"Choose from the following list"<<endl;
    cout<<"1. Re-Calculate Longitudinal CG for new component"<<endl;
    cout<<"2. Longitudinal CG Practice"<<endl;
    cout<<"3. Forward & Aft CG limit generator w/ Cargo Load Calculator"<<endl;
    cout<<"4. Exit Program - All"<<endl;
    cin>>choose;
    //Catch invalid input
    if (!(choose<=4)) {
        cout<<"Not an option!"<<endl;
    }
    //Utilize switch to implement the menu
    switch(choose) {
        
        case 1:{ 
///////////////////////////////Component Calculator/////////////////////////////
            cout<<"New Component Longitudinal CG Calculator.";
            cout<<endl;
            //START CODE//////////////////////////////
            do {
    
            //FINISH CODE/////////////////////////////  
            cout<<"Would you like to run again? Y for Yes, N for No"<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));
            cout<<endl;
            cout<<endl;
            cout<<"End problem 1"<<endl;break;
        } //End option 1
        
        case 2:{
////////////////////////////////PROBLEM 2///////////////////////////////////////
            cout<<"Welcome to Option 2.";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
           
            //FINISH CODE/////////////////////////////  
            cout<<"Would you like to run again? Y for Yes, N for No"<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));
            cout<<endl;
            cout<<endl;
            cout<<"End problem 2"<<endl;break;
        } //End option 2
////////////////////////////////////////////////////////////////////////////////        
       
        case 3:{
////////////////////////////////PROBLEM 3///////////////////////////////////////
            cout<<"Welcome to Option 3.";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
                      
            //FINISH CODE/////////////////////////////
            cout<<"Would you like to run again? Y for Yes, N for No"<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));
            cout<<endl;
            cout<<endl;
            cout<<"End problem"<<endl;break;
        } //End option 3
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////       
        case 4: {
            cout<<"Good Bye!"<<endl;break;
        }
////////////////////////////////////////////////////////////////////////////////  
    } // switch statement end bracket
////////////////////////////////////////////////////////////////////////////////
    } while (choose!=4);
////////////////////////////////////////////////////////////////////////////////        
//Exit Stage Right
    return 0;
}

