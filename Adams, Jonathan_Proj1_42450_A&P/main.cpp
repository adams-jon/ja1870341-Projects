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
    unsigned short choose;
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
    //Catch invalid input choose
    while (!(choose>=1 && choose<=4)) {
        cin.clear();
    	cin.ignore();
        cout<<"Not an option! Please re-enter: "<<endl;
        cin>>choose;
    }
    //End catch invalid input choose
    //Utilize switch to implement the menu
    switch(choose) {                                      //Begin switch choose
        
        case 1:{ 
///////////////////////////////Component Calculator/////////////////////////////
            cout<<"Program 1:New Component Longitudinal CG Calculator";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
            //Prompt
            cout<<setfill('-')<<setw(40)<<"-"<<endl;
            cout<<" Welcome to Longitudinal CG Calculator!"<<endl;
            cout<<setfill('-')<<setw(40)<<"-"<<endl;
            cout<<"This CG calculator is meant to aid you in recalculating \n";
            cout<<"aircraft empty weight CG when you remove, add or replace \n";
            cout<<"a permanent piece of equipment, as defined in the \n";
            cout<<"Aircraft Equipment List."<<endl<<endl;  
            //Prompt for user to select ACFT to modify, or make their own
            cout<<"Select which option you would prefer:"<<endl;
            cout<<"1. Enter my own aircraft data"<<endl;
            cout<<"2. Cessna 150L Profile"<<endl;
            cout<<"3. Cessna 172R Profile"<<endl;
            cout<<"4. McDonald Douglas DC-3 Profile"<<endl;
            //Menu 1 Input Variable
            unsigned short menu1;
            //User input for menu1
            cin>>menu1;
            //Catch invalid input menu1
                while (!(menu1>=1&&menu1<=4)) {
                cin.clear();
                cin.ignore();
                cout<<"Not an option! Please re-enter: "<<endl;
                cin>>menu1;
                }
            //Catch invalid input menu1
                switch (menu1) {                        /////Menu1 Switch start
                    //Variables declared for CG calculations
                    float acftW, acftMom, acftCG, itemOld, oldArm, itemNew;
                    float newArm;
                    case 1:{
                        //Retrieve Aircraft Weight
                        cout<<"Please enter aircraft empty weight, in lbs\n";
                        cout<<"to 1/10 of a lb accuracy. (xxxx.x)\n";
                        cout<<"NOTE: Info on acft Type Certificate Data Sheet\n";
                        cin>>acftW;
                        //Retrieve Aircraft Moment
                        cout<<"Please enter aircraft empty moment,\n";
                        cout<<"to 1/10 accuracy. (xxxx.x)\n";
                        cout<<"NOTE: Info on acft Type Certificate Data Sheet\n";
                        cin>>acftMom;
                        //Calculate CG
                        acftCG=(acftMom/acftW);
                        cout<<endl;
                        cout<<"Current CG is "<<acftCG<<"."<<endl;
                        cout<<"Are you adding, removing or replacing an item?\n";
                        cout<<"Type in option above in lowercase letters"<<endl;
                        string opt1;
                        cin>>opt1;
                        //Error catching loop opt1
                        while (opt1!="removing"&&opt1!="adding"&&opt1!="replacing"){
                            cin.clear();
                            cin.ignore();
                            cout<<"Invalid input, re-enter:"<<endl<<endl;
                            cout<<"Please type one of the following options: \n";
                            cout<<"removing \nadding \nreplacing\n";
                            cout<<"Type in option above in lowercase letters"<<endl;
                            cin>>opt1;
                            cout<<endl<<endl;
                        }
                        //End error catching loop opt1
                        if (opt1=="removing") {
                            cout<<"You're removing"<<endl;break;
                        }
                        if (opt1=="adding") {
                            cout<<"You're adding an item"<<endl;break;
                        }
                        if (opt1=="replacing") {
                            cout<<"You're replacing an item"<<endl;break;
                        }
                    }
                    case 2:{
                        
                    }
                    case 3:{
                        
                    }
                    case 4:{
                        
                    }
                
                
                }                                     ////////Menu 1 Switch End
            //FINISH CODE///////////////////////////// 
            cout<<"\n\n";
            cout<<"Would you like to run again? N for No."<<endl;
            cout<<"Press any other key to run again."<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));      /////////do while loop 
            cout<<endl;
            cout<<endl;
            cout<<"End Program 1"<<endl;break;
        } //End option 1
        
        case 2:{
////////////////////////////////PROBLEM 2///////////////////////////////////////
            cout<<"Welcome to Option 2.";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
           
            //FINISH CODE/////////////////////////////  
            cout<<"\n\n";
            cout<<"Would you like to run again? N for No."<<endl;
            cout<<"Press any other key to run again."<<endl;
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
            cout<<"\n\n";
            cout<<"Would you like to run again? N for No."<<endl;
            cout<<"Press any other key to run again."<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));
            cout<<endl;
            cout<<endl;
            cout<<"End problem"<<endl;break;
        } //End option 3
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////       
        case 4: {
            cout<<"Happy Landings!"<<endl;break;
        }
////////////////////////////////////////////////////////////////////////////////  
    } // switch statement end bracket
////////////////////////////////////////////////////////////////////////////////
    } while (choose!=4);
////////////////////////////////////////////////////////////////////////////////        
//Exit Stage Right
    return 0;
}

