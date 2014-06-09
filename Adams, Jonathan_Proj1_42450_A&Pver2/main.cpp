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
#include <fstream>
using namespace std;
//Global Constants
//Function Prototypes
void fillary (int[], int, int, int);
float convert (int, float);
void startNE (int, float &, float &);
void startIN (int, float &, float &);
void startFO (int, float &, float &);
void prinTbl (int[], int &, unsigned short &);
//Execution
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short choose;
    char exit;
    //-- 1 Decimal point is sufficient for all calculations
    //in this program
    cout<<fixed<<setprecision(1)<<showpoint;
    //Welcome statement to not be looped
    cout<<"Welcome to the Aerospace and Powerplant Maintenance Helper."<<endl;
    //Prompt user for number of problem to execute
    cout<<endl;
    cout<<endl;
    do {                                                //MENU DO LOOP BEGIN
    cout<<"Choose from the following list"<<endl;
    cout<<"1. Re-Calculate Longitudinal CG for new component"<<endl;
    cout<<"2. Longitudinal CG Practice"<<endl;
    cout<<"3. Load Cargo"<<endl;
    cout<<"4. Print Torque Table"<<endl;
    cout<<"5. Exit Program - All"<<endl;
    cin>>choose;
    //Catch invalid input choose
    while (!(choose>=1 && choose<=5)) {
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
            cout<<"Program 1: New Component Longitudinal CG Calculator";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
            //Prompt
            cout<<setfill('-')<<setw(40)<<"-"<<endl;
            cout<<" Welcome to Longitudinal CG Calculator!"<<endl;
            cout<<setfill('-')<<setw(40)<<"-"<<endl;
            cout<<setfill('-');
            cout<<"This CG calculator is meant to aid you in recalculating \n";
            cout<<"aircraft empty weight CG when you remove, add or replace \n";
            cout<<"a permanent piece of equipment, as defined in the \n";
            cout<<"Aircraft Equipment List."<<endl<<endl;  
            //Prompt for user to select ACFT to modify, or make their own
            cout<<"Select which option you would prefer:"<<endl;
            cout<<"1. Enter my own aircraft data"<<endl;
            cout<<"2. Cessna 172M Profile"<<endl;
            //Menu 1 Input Variable
            unsigned short menu1;
            //User input for menu1
            cin>>menu1;
            //Catch invalid input menu1
                while (!(menu1>=1&&menu1<=2)) {
                cin.clear();
                cin.ignore();
                cout<<"Not an option! Please re-enter: "<<endl;
                cin>>menu1;
                }
            //Catch invalid input menu1
                switch (menu1) {                        /////Menu1 Switch start
                    //Variables declared for CG calculations
                    //Planning to turn this into a function later
                    //Basic Aircraft Weight
                    float acftW;
                    //Aircraft moment comes from taking all aircraft longitudinal
                    //station numbers (in inches) and multiplying their weight by
                    //their ARM (distance from the DATUM)
                    float acftMom;
                    //CG is calculated by dividing aircraft moment by aircraft 
                    //weight. The purpose here is to determine Basic Empty CG.
                    //So fuel, cargo and passengers are considered to be at 0. 
                    float acftCG;
                    //Place holder for the weight of an item being removed
                    float itemOld;
                    //The location of the item being removed, in reference to
                    //manufacture specified DATUM point.
                    float armOld; 
                    //Weight of new item
                    float itemNew;
                    //Location of new item, if modified. (EX. longer starter)
                    float armNew;
                    //Menu character
                    char armChoi;
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
                        //Display CG
                        cout<<"Current CG is "<<acftCG<<"."<<endl;
                        //Ask what user wants to do to aircraft
                        cout<<"Are you adding, removing or replacing an item?\n";
                        cout<<"Type in option above in lowercase letters"<<endl;
                        cout<<"Type exit to leave or reset CG calculator."<<endl;
                        string opt1;
                        cin>>opt1;
                        do {
                        //Error catching loop opt1
                        while (opt1!="removing"&&opt1!="adding"&&opt1!=
                               "replacing"&&opt1!="exit"){
                            cin.clear();
                            cin.ignore();
                            cout<<"Invalid input, re-enter:"<<endl<<endl;
                            cout<<"Please type one of the following options: \n";
                            cout<<"removing \nadding \nreplacing\n";
                            cout<<"Type in option above in lowercase letters"<<endl;
                            cout<<"Or type exit to leave or reset CG calculator"<<endl;
                            cin>>opt1;
                            cout<<endl<<endl;
                        }
                        //End error catching loop opt1
                        //Removing option will only remove an item. 
                        //COUT statements self explanatory
                        if (opt1=="removing") {
                            cout<<"You're removing an item"<<endl;
                            cout<<"Enter weight, in lbs to 1/10 lb accuracy\n";
                            cout<<"of item being removed"<<endl;
                            cin>>itemNew;
                            cout<<"Determining ARM: Is the item located\n";
                            cout<<"FWD or AFT of Acft Datum?"<<endl;
                            cout<<"F for FWD, A for AFT: ";
                            cin>>armChoi;
                            //Error catch statement for FWD & AWF
                            //Important that the user has to input this
                            //because it sets the ARM to positive or negative
                                while (armChoi!='f'&&armChoi!='F'
                                        &&armChoi!='a'&&armChoi!='A') {
                                cout<<"Error! Invalid Input!"<<endl<<endl;
                                cout<<"Determining ARM: Is the item located\n";
                                cout<<"FWD or AFT of Acft Datum?"<<endl;
                                cout<<"F for FWD, A for AFT: ";  
                                cin>>armChoi;
                                } 
                            //end error statement
                            cout<<"Enter ARM (distance from Datum in inches)\n";
                            cout<<"of item being removed, to 1/10th of an inch"<<endl;
                            cin>>armOld;
                            //set ARM to negative if item was FWD of datum
                                if (armChoi=='f'||armChoi=='F') armOld=(armOld*-1);
                            //Calculations & Display
                            acftW=(acftW)-(itemNew)+.01;
                            cout<<setw(20)<<left<<"New Acft Weight: ";
                            cout<<setw(20)<<right<<acftW<<endl;
                            acftMom=acftMom-(itemNew*armOld)+.01;
                            cout<<setw(20)<<left<<"New Acft Mom: ";
                            cout<<setw(20)<<right<<acftMom<<endl;
                            acftCG=(acftMom/acftW)+.01;
                            cout<<setw(20)<<left<<"New Acft CG is: ";
                            cout<<setw(20)<<right<<acftCG<<endl<<endl;
                        }
                        //Adding an item
                        if (opt1=="adding") {
                            cout<<"You're adding an item"<<endl;
                            cout<<"Enter weight, in lbs to 1/10 lb accuracy\n";
                            cout<<"of item being added"<<endl;
                            cin>>itemNew;
                            cout<<"Determining ARM: Is the item located\n";
                            cout<<"FWD or AFT of Acft Datum?"<<endl;
                            cout<<"F for FWD, A for AFT: ";
                            cin>>armChoi;
                            //Error catch statement ARM location
                                while (armChoi!='f'&&armChoi!='F'
                                        &&armChoi!='a'&&armChoi!='A') {
                                cout<<"Error! Invalid Input!"<<endl<<endl;
                                cout<<"Determining ARM: Is the item located\n";
                                cout<<"FWD or AFT of Acft Datum?"<<endl;
                                cout<<"F for FWD, A for AFT: ";  
                                cin>>armChoi;
                                } 
                            //End error catch statement
                            cout<<"Enter ARM (distance from Datum in inches)\n";
                            cout<<"of item being removed, to 1/10th of an inch"<<endl;
                            cin>>armOld;
                            //Set ARM to negative if item FWD of datum
                                if (armChoi=='f'||armChoi=='F') armOld=(armOld*-1);
                            //Calculations & display
                            acftW=(acftW)+(itemNew)+.01;
                            cout<<setw(20)<<left<<"New Acft Weight: ";
                            cout<<setw(20)<<right<<acftW<<endl;
                            acftMom=acftMom+(itemNew*armOld)+.01;
                            cout<<setw(20)<<left<<"New Acft Mom: ";
                            cout<<setw(20)<<right<<acftMom<<endl;
                            acftCG=(acftMom/acftW)+.01;
                            cout<<setw(20)<<left<<"New Acft CG is: ";
                            cout<<setw(20)<<right<<acftCG<<endl<<endl; 
                        }
                        //Replacing an item
                        if (opt1=="replacing") {
                            cout<<"You're replacing an item"<<endl;
                            cout<<"Determining ARM: Is the item located\n";
                            cout<<"FWD or AFT of Acft Datum?"<<endl;
                            cout<<"F for FWD, A for AFT: ";
                            cin>>armChoi;
                            //Error catching statement
                                while (armChoi!='f'&&armChoi!='F'
                                        &&armChoi!='a'&&armChoi!='A') {
                                cout<<"Error! Invalid Input!"<<endl<<endl;
                                cout<<"Determining ARM: Is the item located\n";
                                cout<<"FWD or AFT of Acft Datum?"<<endl;
                                cout<<"F for FWD, A for AFT: ";  
                                cin>>armChoi;
                                   } 
                            //End error catching statement
                            cout<<"Enter ARM (distance from Datum in inches)\n";
                            cout<<"of item being removed, to 1/10th of an inch"<<endl;
                            cin>>armOld;
                            //Set ARM to negative if FWD of Datum
                                if (armChoi=='f'||armChoi=='F') armOld=(armOld*-1);
                            cout<<"Was the ARM moved forward or aft?\n";
                            cout<<"Y for Yes, any other key for No:"<<endl;
                            cin>>armChoi;
                            armNew=armOld;
                            if (armChoi=='y'||armChoi=='Y') {
                                do { 
                                cout<<"Forward, or Aft?"<<endl;
                                cout<<"F for FWD, A for AFT"<<endl;
                                cin>>armChoi;
                                        if (armChoi=='f'||armChoi=='F') {
                                        cout<<"Enter distance moved in inches\n";
                                        cin>>armNew;
                                        armOld=armOld-armNew;
                                        }
                                        else if (armChoi=='a'||armChoi=='A') {
                                        cout<<"Enter distance moved in inches\n";
                                        cin>>armNew;
                                        armOld=armOld+armNew;
                                        }
                                        else {
                                        cout<<"Error.";
                                        }
                                   } while (armChoi!='f'&&armChoi!='F'
                                   &&armChoi!='a'&&armChoi!='A');
                            }
                            armOld=armNew;
                            cout<<"Enter the item's original weight"<<endl;
                            cout<<"Enter weight, in lbs to 1/10 lb accuracy\n";
                            cin>>itemOld;
                            acftMom=(acftMom)+(-itemOld*armOld)+.01;
                            cout<<"Acft mom="<<acftMom<<endl;                            
                            cout<<"Enter weight of new item"<<endl;
                            cout<<"Enter weight, in lbs to 1/10 lb accuracy\n";
                            cin>>itemNew;
                            acftW=(acftW-itemOld)+(itemNew)+.01;
                            cout<<setw(20)<<left<<"New Acft Weight: ";
                            cout<<setw(20)<<right<<acftW<<endl;
                            acftMom=acftMom+(itemNew*armOld)+.01;
                            cout<<setw(20)<<left<<"New Acft Mom: ";
                            cout<<setw(20)<<right<<acftMom<<endl;
                            acftCG=(acftMom/acftW)+.01;
                            cout<<setw(20)<<left<<"New Acft CG is: ";
                            cout<<setw(20)<<right<<acftCG<<endl<<endl;              
                        }
                        if (opt1!="exit") {
                        cout<<"Are you adding, removing or replacing another item?"<<endl;
                        cout<<"Type in option above in lowercase letters"<<endl;
                        cout<<"Type exit to leave or reset CG calculator."<<endl;
                        cin>>opt1;
                        while (opt1!="removing"&&opt1!="adding"&&opt1!=
                               "replacing"&&opt1!="exit"){
                            cin.clear();
                            cin.ignore();
                            cout<<"Invalid input, re-enter:"<<endl<<endl;
                            cout<<"Please type one of the following options: \n";
                            cout<<"removing \nadding \nreplacing\n";
                            cout<<"Type in option above in lowercase letters"<<endl;
                            cout<<"Or type exit to leave or reset CG calculator"<<endl;
                            cin>>opt1;
                            cout<<endl<<endl; }
                        }
                    } while (opt1!="exit");
                    break;
                    } // end case 1
                    
                    case 2:{
                        
                        //Retrieve Aircraft Weight
                        cout<<"Cessna 172M Basic Empty Weight: "<<endl;
                        acftW=1588;
                        cout<<acftW<<" lbs"<<endl;
                        //Retrieve Aircraft Moment
                        cout<<"Cessna 172M Basic Empty Moment: "<<endl;
                        acftMom=61316.6;
                        cout<<acftMom<<endl;
                        //Calculate CG
                        cout<<"NOTE: Cessna 172M DATUM is located on the\n";
                        cout<<"Front Face of Cockpit Firewall"<<endl;
                        acftCG=(acftMom/acftW);
                        cout<<endl;
                        cout<<"Current CG is "<<acftCG<<"."<<endl;
                        cout<<"Are you adding, removing or replacing an item?\n";
                        cout<<"Type in option above in lowercase letters"<<endl;
                        cout<<"Type exit to leave or reset CG calculator."<<endl;
                        string opt1;
                        cin>>opt1;
                        do {
                        //Error catching loop opt1
                                while (opt1!="removing"&&opt1!="adding"&&opt1!=
                               "replacing"&&opt1!="exit"){
                                cin.clear();
                                cin.ignore();
                                cout<<"Invalid input, re-enter:"<<endl<<endl;
                                cout<<"Please type one of the following options: \n";
                                cout<<"removing \nadding \nreplacing\n";
                                cout<<"Type in option above in lowercase letters"<<endl;
                                cout<<"Or type exit to leave or reset CG calculator"<<endl;
                                cin>>opt1;
                                cout<<endl<<endl;
                                }
                        //End error catching loop opt1
                        if (opt1=="removing") {
                            cout<<"You're removing an item"<<endl;
                            cout<<"Enter weight, in lbs to 1/10 lb accuracy\n";
                            cout<<"of item being removed"<<endl;
                            cin>>itemNew;
                            cout<<"Determining ARM: Is the item located\n";
                            cout<<"FWD or AFT of Acft Datum?"<<endl;
                            cout<<"F for FWD, A for AFT: ";
                            cin>>armChoi;
                                while (armChoi!='f'&&armChoi!='F'
                                        &&armChoi!='a'&&armChoi!='A') {
                                cout<<"Error! Invalid Input!"<<endl<<endl;
                                cout<<"Determining ARM: Is the item located\n";
                                cout<<"FWD or AFT of Acft Datum?"<<endl;
                                cout<<"F for FWD, A for AFT: ";  
                                cin>>armChoi;
                                }
                            cout<<"Enter ARM (distance from Datum in inches)\n";
                            cout<<"of item being removed, to 1/10th of an inch"<<endl;
                            cin>>armOld;
                                if (armChoi=='f'||armChoi=='F') armOld=(armOld*-1);
                            acftW=(acftW)-(itemNew)+.01;
                            cout<<setw(20)<<left<<"New Acft Weight: ";
                            cout<<setw(20)<<right<<acftW<<endl;
                            acftMom=acftMom-(itemNew*armOld)+.01;
                            cout<<setw(20)<<left<<"New Acft Mom: ";
                            cout<<setw(20)<<right<<acftMom<<endl;
                            acftCG=(acftMom/acftW)+.01;
                            cout<<setw(20)<<left<<"New Acft CG is: ";
                            cout<<setw(20)<<right<<acftCG<<endl<<endl;
                        }
                        if (opt1=="adding") {
                            cout<<"You're adding an item"<<endl;
                            cout<<"Enter weight, in lbs to 1/10 lb accuracy\n";
                            cout<<"of item being added"<<endl;
                            cin>>itemNew;
                            cout<<"Determining ARM: Is the item located\n";
                            cout<<"FWD or AFT of Acft Datum?"<<endl;
                            cout<<"F for FWD, A for AFT: ";
                            cin>>armChoi;
                                while (armChoi!='f'&&armChoi!='F'
                                        &&armChoi!='a'&&armChoi!='A') {
                                cout<<"Error! Invalid Input!"<<endl<<endl;
                                cout<<"Determining ARM: Is the item located\n";
                                cout<<"FWD or AFT of Acft Datum?"<<endl;
                                cout<<"F for FWD, A for AFT: ";  
                                cin>>armChoi;
                                   } 
                            cout<<"Enter ARM (distance from Datum in inches)\n";
                            cout<<"of item being removed, to 1/10th of an inch"<<endl;
                            cin>>armOld;
                                if (armChoi=='f'||armChoi=='F') armOld=(armOld*-1);
                            acftW=(acftW)+(itemNew)+.01;
                            cout<<setw(20)<<left<<"New Acft Weight: ";
                            cout<<setw(20)<<right<<acftW<<endl;
                            acftMom=acftMom+(itemNew*armOld)+.01;
                            cout<<setw(20)<<left<<"New Acft Mom: ";
                            cout<<setw(20)<<right<<acftMom<<endl;
                            acftCG=(acftMom/acftW)+.01;
                            cout<<setw(20)<<left<<"New Acft CG is: ";
                            cout<<setw(20)<<right<<acftCG<<endl<<endl; 
                        }
                        if (opt1=="replacing") {
                            cout<<"You're replacing an item"<<endl;
                            cout<<"Determining ARM: Is the item located\n";
                            cout<<"FWD or AFT of Acft Datum?"<<endl;
                            cout<<"F for FWD, A for AFT: ";
                            cin>>armChoi;
                                while (armChoi!='f'&&armChoi!='F'
                                        &&armChoi!='a'&&armChoi!='A') {
                                cout<<"Error! Invalid Input!"<<endl<<endl;
                                cout<<"Determining ARM: Is the item located\n";
                                cout<<"FWD or AFT of Acft Datum?"<<endl;
                                cout<<"F for FWD, A for AFT: ";  
                                cin>>armChoi;
                                } 
                            cout<<"Enter ARM (distance from Datum in inches)\n";
                            cout<<"of item being removed, to 1/10th of an inch"<<endl;
                            cin>>armOld;
                                if (armChoi=='f'||armChoi=='F') armOld=(armOld*-1);
                            cout<<"Was the ARM moved forward or aft?\n";
                            cout<<"Y for Yes, any other key for No:"<<endl;
                            cin>>armChoi;
                            armNew=armOld;
                            if (armChoi=='y'||armChoi=='Y') {
                                do { 
                                cout<<"Forward, or Aft?"<<endl;
                                cout<<"F for FWD, A for AFT"<<endl;
                                cin>>armChoi;
                                        if (armChoi=='f'||armChoi=='F') {
                                        cout<<"Enter distance moved in inches\n";
                                        cin>>armNew;
                                        armOld=armOld-armNew;
                                        }
                                        else if (armChoi=='a'||armChoi=='A') {
                                        cout<<"Enter distance moved in inches\n";
                                        cin>>armNew;
                                        armOld=armOld+armNew;
                                        }
                                        else {
                                        cout<<"Error.";
                                        }
                                   } while (armChoi!='f'&&armChoi!='F'
                                   &&armChoi!='a'&&armChoi!='A');
                            }
                            armOld=armNew;
                            cout<<"Enter the item's original weight"<<endl;
                            cout<<"Enter weight, in lbs to 1/10 lb accuracy\n";
                            cin>>itemOld;
                            acftMom=(acftMom)+(-itemOld*armOld)+.01;
                            cout<<"Acft mom="<<acftMom<<endl;                            
                            cout<<"Enter weight of new item"<<endl;
                            cout<<"Enter weight, in lbs to 1/10 lb accuracy\n";
                            cin>>itemNew;
                            acftW=(acftW-itemOld)+(itemNew)+.01;
                            cout<<setw(20)<<left<<"New Acft Weight: ";
                            cout<<setw(20)<<right<<acftW<<endl;
                            acftMom=acftMom+(itemNew*armOld)+.01;
                            cout<<setw(20)<<left<<"New Acft Mom: ";
                            cout<<setw(20)<<right<<acftMom<<endl;
                            acftCG=(acftMom/acftW)+.01;
                            cout<<setw(20)<<left<<"New Acft CG is: ";
                            cout<<setw(20)<<right<<acftCG<<endl<<endl;              
                        }
                        if (opt1!="exit") {
                        cout<<"Are you adding, removing or replacing another item?"<<endl;
                        cout<<"Type in option above in lowercase letters"<<endl;
                        cout<<"Type exit to leave or reset CG calculator."<<endl;
                        cin>>opt1;
                        while (opt1!="removing"&&opt1!="adding"&&opt1!=
                               "replacing"&&opt1!="exit"){
                            cin.clear();
                            cin.ignore();
                            cout<<"Invalid input, re-enter:"<<endl<<endl;
                            cout<<"Please type one of the following options: \n";
                            cout<<"removing \nadding \nreplacing\n";
                            cout<<"Type in option above in lowercase letters"<<endl;
                            cout<<"Or type exit to leave or reset CG calculator"<<endl;
                            cin>>opt1;
                            cout<<endl<<endl; }
                        }
                    } while (opt1!="exit");
                        
                    }
                    
                
                
                }                                     ////////Menu 1 Switch End
            //FINISH CODE///////////////////////////// 
            cout<<"\n\n";
            cout<<"CG Calculator is reset."<<endl;
            cout<<"Would you like to run calculator again?"<<endl;
            cout<<"Type N for No and to return to main menu."<<endl;
            cout<<"Press any other key to run calculator again."<<endl;
            cin>>exit;
            } while ((exit!='n')&&(exit!='N'));      /////////do while loop 
            cout<<endl;
            cout<<endl;
            cout<<"End Program 1"<<endl;break;
        } //End option 1
        
        case 2:{
////////////////////////////////PROBLEM 2///////////////////////////////////////
            cout<<"Welcome to CG Practice.";
            cout<<endl;
            do {
            //START CODE//////////////////////////////
                //Randomly choose a sequence start
                float acftW=0; //weight
                float acftMom=0; //moment
                float acftCG=0; //mom/weight
                float testVal=0; //user input of new CG
                unsigned short itemW=0; //weight of new item
                unsigned short itemArm=0; //location of new item
                srand(static_cast<unsigned int>(time(0))); // time seed for rand
                cout<<"Aircraft Weight: "<<endl; //display weight of 1000 to 1049
                acftW=rand()%500+3000; 
                cout<<acftW<<" lbs"<<endl;
                cout<<"Aircraft Moment: "<<endl; //display mom of 30000 to 30999
                acftMom=rand()%1000+35000;
                cout<<acftMom<<endl;
                cout<<"Starting CG is: "<<endl;
                cout<<acftMom/acftW<<endl<<endl;
                itemW=rand()%9+50; //display starting CG and create itemW 20-29
                cout<<"Item added weighs:"<<endl;
                cout<<itemW<<" lbs"<<endl;
                itemArm=rand()%9+1; //display item location 2-11
                cout<<"Located "<<itemArm<<" inches aft of Datum"<<endl;
                cout<<"Enter new aircraft CG: (to 1 decimal point)"<<endl;
                //User inputs their calculation
                cin>>testVal;
                //Computer calculation for new CG
                acftMom=acftMom+(itemW*itemArm); //Add new items moment
                acftW=acftW+(itemW); // add new items weight
                acftCG=acftMom/acftW; //new cg
                cout<<"Correct new CG is: "<<endl; //output to user
                cout<<acftCG<<endl;
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
       
        
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////       
        case 3: {
            cout<<"Happy Landings!"<<endl;break;
        }
////////////////////////////////////////////////////////////////////////////////  
        //This is primarily just to practice with arrays
        case 4: {
            //Declare an array that can accommodate up to 1000 units of int
            //I know a vector would be better here, but I am more comfortable
            //with arrays for now. 
            int tableS[1000], increm=1, size=1000, startV;
            unsigned short dataC;
            cout<<"Print A Custom Shop Use Torque Value Conversion Table"<<endl<<endl;
            cout<<"User can print a table up to 1000 values"<<endl;
            cout<<"User chooses Troque Data needed (column 1)"<<endl;
            cout<<"---Either, Newton Meters, Foot Pounds, or Inch Pounds"<<endl<<endl;
            cout<<"Table will print out with corresponding values of the"<<endl;
            cout<<"other two data types, so the user can use any kind of"<<endl;
            cout<<"torque wrench!"<<endl<<endl;
            cout<<"User can choose how many values to print, and how to "<<endl;
            cout<<"increment those values!"<<endl<<endl;
            cout<<"What data type would you like column 1 to be?"<<endl;
            cout<<"(this should be the type you're commonly asked"<<endl;
            cout<<" for in tech data)"<<endl;
            cout<<"Press 1 for Newton Meters"<<endl;
            cout<<"Press 2 for Inch Pounds"<<endl;
            cout<<"Press 3 for Foot Pounds"<<endl;
            cin>>dataC;
            //Error catch
                while (dataC!=1&&dataC!=2&&dataC!=3) {
                        cout<<"Error! Not an option!"<<endl;
                        cout<<"Press 1 for Newton Meters"<<endl;
                        cout<<"Press 2 for Inch Pounds"<<endl;
                        cout<<"Press 3 for Foot Pounds"<<endl;
                        cin>>dataC;
                }
            cout<<"Enter how many values you would like the table to go up to: "<<endl;
            cout<<"Max is 1000; if printing it is suggested to keep under 75"<<endl;
            cin>>size;
                while (size>1000) {
                        cout<<"Too large, re-enter under 1000"<<endl;
                        cin>>size;
                }
                while (size<1) {
                        cout<<"Too small, value must be a whole #"<<endl;
                        cout<<"above zero and below 1000"<<endl;
                        cin>>size;
                }
            cout<<"Enter first value you want the table to start at: "<<endl;
            cin>>startV;
            cout<<"Enter how you would like the table to be incremented: "<<endl;
            cout<<"(Every 1, 2, 5, 10, etc)"<<endl;
            cin>>increm;
            fillary(tableS, size, increm, startV);
            prinTbl(tableS, size, dataC);
            
        }
////////////////////////////////////////////////////////////////////////////////  
        case 5: {
            cout<<"Happy Landings!"<<endl;break;
        }

    } // switch statement end bracket
////////////////////////////////////////////////////////////////////////////////
    } while (choose!=5);
////////////////////////////////////////////////////////////////////////////////        
//Exit Stage Right
    return 0;
}

void fillary(int array[], int size, int increm, int first) {
    int count=1;
    for (int index=0; index<size; index++){
        array[index]=first;
        //cout<<"Array Index "<<count<<" equals "<<first<<endl;
        first+=increm;
        count++;
    }
}
float convert (int origV, float conv1) {
    float newVal;
    newVal=(origV*conv1);
    return newVal;
}
//Function for user choosing to start with newtons
void startNE (int indexV, float &inchLb, float &footLb){
    //Multiplication factors to convert newton meters, to foot lbs and inch lbs
    float NEWTOIN=8.85074579, NEWTOLB=0.737562149;
    inchLb=convert(indexV, NEWTOIN);
    footLb=convert(indexV, NEWTOLB);    
}
//Function for user choosing inch pounds to start
void startIN (int indexV, float &footLb, float &newtMe){
    //Multiplication factors to convert inch lbs, to foot lbs and newton meters
    float INTONEW=0.112984829, INTOLB=0.0833;
    footLb=convert(indexV, INTOLB);
    newtMe=convert(indexV, INTONEW);
}
//Function for user choosing foot pounds to start
void startFO (int indexV, float &inchLb, float &newtMe){
    //Multiplication factors to convert inch lbs, to foot lbs and newton meters
    float LBTOIN=12, LBTONEW=1.35581795;
    inchLb=convert(indexV, LBTOIN);
    newtMe=convert(indexV, LBTONEW);
}


void prinTbl (int array[], int &size, unsigned short &choice){
    float col1=0, col2=0;
    int passVal=0;
    ofstream fout;
    fout.open("CurrentTable.dat");
    fout<<fixed<<setprecision(1)<<showpoint;
    //Begin printing table options
    //If user selected newtons: 
    if (choice==1) {
    cout<<setw(15)<<left<<"NewtMeters:";
    fout<<setw(15)<<left<<"NewtMeters:";
    cout<<setw(15)<<left<<"InchPounds:";
    fout<<setw(15)<<left<<"InchPounds:";
    cout<<setw(15)<<left<<"FootPounds:"<<endl;
    fout<<setw(15)<<left<<"FootPounds:"<<endl;
            for (int index=0; index<size; index++){
                passVal=array[index];
                startNE(passVal, col1, col2);
                cout<<setw(15)<<left<<array[index];
                fout<<setw(15)<<left<<array[index];
                cout<<setw(15)<<left<<col1;
                fout<<setw(15)<<left<<col1;
                cout<<setw(15)<<left<<col2;
                fout<<setw(15)<<left<<col2;
                cout<<endl;
                fout<<endl;
            }
    }
    if (choice==2) {
    cout<<setw(15)<<left<<"InchPounds:";
    fout<<setw(15)<<left<<"InchPounds:";
    cout<<setw(15)<<left<<"FootPounds:";
    fout<<setw(15)<<left<<"FootPounds:";
    cout<<setw(15)<<left<<"NewtMeters:"<<endl;
    fout<<setw(15)<<left<<"NewtMeters:"<<endl;
            for (int index=0; index<size; index++){
                passVal=array[index];
                startIN(passVal, col1, col2);
                cout<<setw(15)<<left<<array[index];
                fout<<setw(15)<<left<<array[index];
                cout<<setw(15)<<left<<col1;
                fout<<setw(15)<<left<<col1;
                cout<<setw(15)<<left<<col2;
                fout<<setw(15)<<left<<col2;
                cout<<endl;
                fout<<endl;
            }
    }
    if (choice==3) {
    cout<<setw(15)<<left<<"FootPounds:";
    fout<<setw(15)<<left<<"FootPounds:";
    cout<<setw(15)<<left<<"InchPounds:";
    fout<<setw(15)<<left<<"InchPounds:";
    cout<<setw(15)<<left<<"NewtMeters:"<<endl;
    fout<<setw(15)<<left<<"NewtMeters:"<<endl;
            for (int index=0; index<size; index++){
                passVal=array[index];
                startFO(passVal, col1, col2);
                cout<<setw(15)<<left<<array[index];
                fout<<setw(15)<<left<<array[index];
                cout<<setw(15)<<left<<col1;
                fout<<setw(15)<<left<<col1;
                cout<<setw(15)<<left<<col2;
                fout<<setw(15)<<left<<col2;
                cout<<endl;
                fout<<endl;
            }
    }
    else cout<<"Program screwed up if you get here!"<<endl;
    fout.close();
}