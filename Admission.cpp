#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Branch
{
    private:
        bool openChemical[50];
        bool openComputer[50];
        bool openElectronics[50];
        bool openProduction[50];
        bool openInstrumentation[50];
        bool openIT[50];
        bool openMechanical[50];
    
        bool categoryChemical[30];
        bool categoryComputer[30];
        bool categoryElectronics[30];
        bool categoryProduction[30];
        bool categoryInstrumentation[30];
        bool categoryIT[30];
        bool categoryMechanical[30];

        bool managementChemical[20];
        bool managementComputer[20];
        bool managementElectronics[20];
        bool managementProduction[20];
        bool managementMechanical[20];
        bool managementInstrumentation[20];
        bool managementIT[20];
    
    public:
        bool isAvailable(bool seatArray[], int size);
        int openChemicalSeatsFilled();
        int openComputerSeatsFilled();
        int openElectronicsSeatsFilled();
        int openProductionSeatsFilled();
        int openInstrumentationSeatsFilled();
        int openITSeatsFilled();
        int openMechanicalSeatsFilled();

    friend class Student;           //Student should be able to access these seats
}branch;

bool Branch::isAvailable(bool seatArray[], int size){
    int filledSeats = count(seatArray, seatArray+size, true);
    if (filledSeats == size)
        return false;
    else
        return true;
}

int Branch::openChemicalSeatsFilled(){
    return count(openChemical, openChemical+50, true);
}

int Branch::openComputerSeatsFilled(){
    return count(openComputer, openComputer+50, true);
}

int Branch::openElectronicsSeatsFilled(){
    return count(openElectronics, openElectronics+50, true);
}

int Branch::openProductionSeatsFilled(){
    return count(openProduction, openProduction+50, true);
}

int Branch::openInstrumentationSeatsFilled(){
    return count(openInstrumentation, openInstrumentation+50, true);
}

int Branch::openITSeatsFilled(){
    return count(openIT, openIT+50, true);
}

int Branch::openMechanicalSeatsFilled(){
    return count(openMechanical, openMechanical+50, true);
}

class Student
{
    private:
        string studentName;
        int studentRank;
        int categoryRank;
        int programChoice[3];
        int quota;
    public:
        Student(vector<string> &line);
        void printData();
        int getCategory();
        void assignBranch(int quota);

    friend class Branbh;
};

Student::Student(vector<string> &line)
{
    studentName = line[0];
    studentRank = stoi(line.at(2));
    if(line.at(3) == "NA")
        categoryRank = 0;                //for those without category, Crank is 0
    else
        categoryRank = stoi(line.at(3));
    programChoice[0] = stoi(line.at(4));
    programChoice[1] = stoi(line.at(5));
    programChoice[2] = stoi(line.at(6));
    quota = stoi(line.at(7));
}

void Student::printData(){
    cout << "Name: " << studentName << endl;
    cout << "Rank: " << studentRank << endl;
    cout << "CRank: " << categoryRank << endl;
    cout << "Choice1: " << programChoice[0] << endl;
    cout << "Choice2: " << programChoice[1] << endl;
    cout << "Choice3: " << programChoice[2] << endl;
    switch (quota)
    {
    case 1:
        cout << "Quota: Open" << endl;
        break;
    
    case 2:
        cout << "Quota: Category" << endl;
        break;
    
    case 3:
        cout << "Quota: Management" << endl;
        break;
    
    default:
        break;
    }
}

int Student::getCategory(){
    return quota;
}

void Student::assignBranch(int quota){
    /* Quota 
    1 = Open
    2 = Category
    3 = Mangement */

   /* Branch
    1 = Chemical
    2 = Computer
    3 = Electronics
    4 = Production
    5 = Instrumentation
    6 = IT
    7 = Mechanical*/

    switch (quota){
        case 1:
            for(int i = 0; i < 3; ++i){
                switch (programChoice[i]){
                    case 1:
                        if(branch.isAvailable(branch.openChemical, 50)){
                            int filledSeats = count(branch.openChemical, branch.openChemical+50, true);
                            branch.openChemical[filledSeats] = true;       //next seat is filled
                        }
                        break;

                    case 2:
                        if(branch.isAvailable(branch.openComputer, 50)){
                            int filledSeats = count(branch.openComputer, branch.openComputer+50, true);
                            branch.openComputer[filledSeats] = true;       //next seat is filled
                        }
                        break;
                    
                    case 3:
                        if(branch.isAvailable(branch.openElectronics, 50)){
                            int filledSeats = count(branch.openElectronics, branch.openElectronics+50, true);
                            branch.openElectronics[filledSeats] = true;       //next seat is filled
                        }
                        break;
                    
                    case 4:
                        if(branch.isAvailable(branch.openProduction, 50)){
                            int filledSeats = count(branch.openProduction, branch.openChemical+50, true);
                            branch.openProduction[filledSeats] = true;       //next seat openProduction filled
                        }
                        break;
                    
                    case 5:
                        if(branch.isAvailable(branch.openInstrumentation, 50)){
                            int filledSeats = count(branch.openInstrumentation, branch.openInstrumentation+50, true);
                            branch.openInstrumentation[filledSeats] = true;       //next seat is filled
                        }
                        break;
                    
                    case 6:
                        if(branch.isAvailable(branch.openIT, 50)){
                            int filledSeats = count(branch.openIT, branch.openIT+50, true);
                            branch.openIT[filledSeats] = true;       //next seat is filled
                        }
                        break;

                    case 7:
                        if(branch.isAvailable(branch.openMechanical, 50)){
                            int filledSeats = count(branch.openMechanical, branch.openMechanical+50, true);
                            branch.openMechanical[filledSeats] = true;       //next seat is filled
                        }
                        break;
                }
            }

            break;
        
        case 2:
            for(int i = 0; i < 3; ++i){
                switch (programChoice[i]){
                    case 1:
                        if(branch.isAvailable(branch.categoryChemical, 50)){
                            int filledSeats = count(branch.categoryChemical, branch.categoryChemical+50, true);
                            branch.categoryChemical[filledSeats] = true;       //next seat is filled
                        }
                        break;

                    case 2:
                        if(branch.isAvailable(branch.categoryComputer, 50)){
                            int filledSeats = count(branch.categoryComputer, branch.categoryComputer+50, true);
                            branch.categoryComputer[filledSeats] = true;       //next seat is filled
                        }
                        break;
                    
                    case 3:
                        if(branch.isAvailable(branch.categoryElectronics, 50)){
                            int filledSeats = count(branch.categoryElectronics, branch.categoryElectronics+50, true);
                            branch.categoryElectronics[filledSeats] = true;       //next seat is filled
                        }
                        break;
                    
                    case 4:
                        if(branch.isAvailable(branch.categoryProduction, 50)){
                            int filledSeats = count(branch.categoryProduction, branch.categoryProduction+50, true);
                            branch.categoryProduction[filledSeats] = true;       //next seat is filled
                        }
                        break;
                    
                    case 5:
                        if(branch.isAvailable(branch.categoryInstrumentation, 50)){
                            int filledSeats = count(branch.categoryInstrumentation, branch.categoryInstrumentation+50, true);
                            branch.categoryInstrumentation[filledSeats] = true;       //next seat is filled
                        }
                        break;
                    
                    case 6:
                        if(branch.isAvailable(branch.categoryIT, 50)){
                            int filledSeats = count(branch.categoryIT, branch.categoryIT+50, true);
                            branch.categoryIT[filledSeats] = true;       //next seat is filled
                        }
                        break;

                    case 7:
                        if(branch.isAvailable(branch.categoryMechanical, 50)){
                            int filledSeats = count(branch.categoryMechanical, branch.categoryMechanical+50, true);
                            branch.categoryMechanical[filledSeats] = true;       //next seat is filled
                        }
                        break;
                }
            }
            break;
        
    }
    
}

int main(){
    ifstream admissionFile;

    string studApplication;         //to store one line from the file
    string word;                    //to store contents of each cell from one line of the file
    vector <string> line;           //to store each cell separately from one line of the file
    
    admissionFile.open("AdmissionDatabase2.csv");
    if (admissionFile.is_open()) {
        cout << "File has been opened" << endl;
    }
    else {
        cout << "File couldn't be opened" << endl;
    }


    while (!admissionFile.eof()) {

        line.clear();
        admissionFile >> studApplication;

        std::stringstream temp(studApplication);

        while (std::getline(temp, word, ',')) {
            line.push_back(word);
        }

        //store the data from the file into Student class object now
        Student s1(line);
        s1.printData();

        //TODO: call assign on s1 using quota

        switch (s1.getCategory()){
            case 1:
                s1.assignBranch(1);
                break;
            
            case 2:
                s1.assignBranch(2);
                break;
            
            default:
                s1.assignBranch(3);         //since if not open or category, its management.
                break;
        }

        cout << "Filled seats in open chemical = " << branch.openChemicalSeatsFilled() << endl;
        cout << "Filled seats in open computer = " << branch.openComputerSeatsFilled() << endl;
        cout << "Filled seats in open electronics = " << branch.openElectronicsSeatsFilled() << endl;
        cout << "Filled seats in open instrumentation = " << branch.openInstrumentationSeatsFilled() << endl;
        cout << "Filled seats in open Production = " << branch.openProductionSeatsFilled() << endl;
        cout << "Filled seats in open IT = " << branch.openITSeatsFilled() << endl;
        cout << "Filled seats in open mechanical = " << branch.openMechanicalSeatsFilled() << endl;

    }
    admissionFile.close();

    return 0;
}