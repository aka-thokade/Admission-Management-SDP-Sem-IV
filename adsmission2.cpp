#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//forward declaration
/* class Student;
class AdmittedStud;
class Branch; */

class Branch
{
    private:
        bool openChemical[70];
        bool openComputer[70];
        bool openElectronics[70];
        bool openProduction[70];
        bool openInstrumentation[70];
        bool openIT[70];
        bool openMechanical[70];
    
        bool categoryChemical[30];
        bool categoryComputer[30];
        bool categoryElectronics[30];
        bool categoryProduction[30];
        bool categoryInstrumentation[30];
        bool categoryIT[30];
        bool categoryMechanical[30];
    
    public:
        bool isAvailable(bool seatArray[], int size);
        
        int openChemicalSeatsFilled();
        int openComputerSeatsFilled();
        int openElectronicsSeatsFilled();
        int openProductionSeatsFilled();
        int openInstrumentationSeatsFilled();
        int openITSeatsFilled();
        int openMechanicalSeatsFilled();

        int categoryChemicalSeatsFilled();
        int categoryComputerSeatsFilled();
        int categoryElectronicsSeatsFilled();
        int categoryProductionSeatsFilled();
        int categoryInstrumentationSeatsFilled();
        int categoryITSeatsFilled();
        int categoryMechanicalSeatsFilled();

        void showFilledSeatData();

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
    return count(openChemical, openChemical+70, true);
}

int Branch::openComputerSeatsFilled(){
    return count(openComputer, openComputer+70, true);
}

int Branch::openElectronicsSeatsFilled(){
    return count(openElectronics, openElectronics+70, true);
}

int Branch::openProductionSeatsFilled(){
    return count(openProduction, openProduction+70, true);
}

int Branch::openInstrumentationSeatsFilled(){
    return count(openInstrumentation, openInstrumentation+70, true);
}

int Branch::openITSeatsFilled(){
    return count(openIT, openIT+70, true);
}

int Branch::openMechanicalSeatsFilled(){
    return count(openMechanical, openMechanical+70, true);
}

int Branch::categoryChemicalSeatsFilled(){
    return count(categoryChemical, categoryChemical+30, true);
}

int Branch::categoryComputerSeatsFilled(){
    return count(categoryComputer, categoryComputer+30, true);
}

int Branch::categoryElectronicsSeatsFilled(){
    return count(categoryElectronics, categoryElectronics+30, true);
}

int Branch::categoryProductionSeatsFilled(){
    return count(categoryProduction, categoryProduction+30, true);
}

int Branch::categoryInstrumentationSeatsFilled(){
    return count(categoryInstrumentation, categoryInstrumentation+30, true);
}

int Branch::categoryITSeatsFilled(){
    return count(categoryIT, categoryIT+30, true);
}

int Branch::categoryMechanicalSeatsFilled(){
    return count(categoryMechanical, categoryMechanical+30, true);
}

void Branch::showFilledSeatData(){
    cout << "\nOpen" << endl;
    cout << "Chemical\tComputer\tElectronics\tInstrumentaiton\t\tProduction\tIT\tMechanical" << endl;
    cout << branch.openChemicalSeatsFilled() << "\t\t" << branch.openComputerSeatsFilled() << "\t\t" << branch.openElectronicsSeatsFilled() << "\t\t" << branch.openInstrumentationSeatsFilled() << "\t\t\t" << branch.openProductionSeatsFilled() << "\t\t" << branch.openITSeatsFilled() << "\t" << branch.openMechanicalSeatsFilled() << endl;

    cout << "\n\nCategory" << endl;
    cout << "Chemical\tComputer\tElectronics\tInstrumentaiton\t\tProduction\tIT\tMechanical" << endl;
    cout << branch.categoryChemicalSeatsFilled() << "\t\t" << branch.categoryComputerSeatsFilled() << "\t\t" << branch.categoryElectronicsSeatsFilled() << "\t\t" << branch.categoryInstrumentationSeatsFilled() << "\t\t\t" << branch.categoryProductionSeatsFilled() << "\t\t" << branch.categoryITSeatsFilled() << "\t" << branch.categoryMechanicalSeatsFilled() << endl;
}

class AdmittedStud{
    private:
        string studentName;
        string studentLastName;
        string studentBranch;
        string GR;
        string quota;
        string fatherName;
        string motherName;
        string contactNo;
        string city;

    public:
        AdmittedStud();
        AdmittedStud(string, string, string, string, string, string, string, string, string);
        void storeInfo(int, int);
        void search(string, int);
        void displayInfo();
};

AdmittedStud::AdmittedStud(){
    //do nothign
}

AdmittedStud::AdmittedStud(string name, string lastname, string brnch, string grn, string quota, string fName, string mName, string contact, string city){
    this->studentName = name;
    this->studentLastName = lastname;
    this->studentBranch = brnch;
    this->GR = grn;
    this->quota = quota;
    this->fatherName = fName;
    this->motherName = mName;
    this->contactNo = contact;
    this->city = city;
}

void AdmittedStud::storeInfo(int qta, int brn){
    //qta: 1 = open; 2 = category
    //brn: 1 = CH; 2 = CS; 3 = EX; 4 = PD; 5 = IS; 6 = IT; 7 = ME

    ofstream outData;
    string grn = this->GR;
    
    if(qta == 1){
        switch (brn) {
            case 1:
                outData.open("openChemical.txt", ios::app);
                break;

            case 2:
                outData.open("openComputer.txt", ios::app);
                break;
            
            case 3: 
                outData.open("openElectronics.txt", ios::app);
                break;
            
            case 4:
                outData.open("openProduction.txt", ios::app);
                break;
            
            case 5: 
                outData.open("openInstrumentation.txt", ios::app);
                break;
            
            case 6:
                outData.open("openIT.txt", ios::app);
                break;
            
            case 7:
                outData.open("openMechanical.txt", ios::app);
                break;

        }
    }

    if(qta == 2){
        switch (brn) {
            case 1:
                outData.open("categoryChemical.txt", ios::app);
                break;

            case 2:
                outData.open("categoryComputer.txt", ios::app);
                break;
            
            case 3: 
                outData.open("categoryElectronics.txt", ios::app);
                break;
            
            case 4:
                outData.open("categoryProduction.txt", ios::app);
                break;
            
            case 5: 
                outData.open("categoryInstrumentation.txt", ios::app);
                break;
            
            case 6:
                outData.open("categoryIT.txt", ios::app);
                break;
            
            case 7:
                outData.open("categoryMechanical.txt", ios::app);
                break;

        }
    }

    if (outData.is_open()) {
        outData << grn << "|" << this->studentName << "|" << this->studentLastName << "|" << this->fatherName << "|" << this->motherName << "|" << this->contactNo << "|" << this->city << "|" << this->studentBranch << "|" << this->quota << endl;
    }
    else {
        std::cout << "Student with GR = " << grn << " couldn't be added to the file." << endl << endl;
    }
    
}

void AdmittedStud::search(string grn, int qta){
    //qta: 1 = open; 2 = category
    //brn: 1 = CH; 2 = CS; 3 = EC; 4 = PD; 5 = IS; 6 = IT; 7 = ME
    
    ifstream studDataFile;
    string studRecord, word;
    vector <string> line;
    int flag = 0;

    string brn = grn.substr(4, 2);

    if(brn == "CH"){
        if(qta == 1)
            studDataFile.open("openChemical.txt");
        else
            studDataFile.open("categoryChemical.txt");
    }

    if(brn == "CS"){
        if(qta == 1)
            studDataFile.open("openComputer.txt");
        else
            studDataFile.open("categoryComputer.txt");
    }

    if(brn == "EC"){
        if(qta == 1)
            studDataFile.open("openElectronics.txt");
        else
            studDataFile.open("categoryElectronics.txt");
    }

    if(brn == "PD"){
        if(qta == 1)
            studDataFile.open("openProduction.txt");
        else
            studDataFile.open("categoryProduction.txt");
    }

    if(brn == "IS"){
        if(qta == 1)
            studDataFile.open("openInstrumentation.txt");
        else
            studDataFile.open("categoryInstrumentation.txt");
    }

    if(brn == "IT"){
        if(qta == 1)
            studDataFile.open("openIT.txt");
        else
            studDataFile.open("categoryIT.txt");
    }

    if(brn == "ME"){
        if(qta == 1)
            studDataFile.open("openMechanical.txt");
        else
            studDataFile.open("categoryMechanical.txt");
    }

    if(studDataFile.is_open()){
        while(!studDataFile.eof()){
            studDataFile >> studRecord;
            

            if(studRecord.substr(0,12) == grn){
                cout << "\n\nRecord found!" << endl;
                flag++;
                	            
                std::stringstream temp(studRecord);

                while (std::getline(temp, word, '|')) {
                    line.push_back(word);
                }

                cout << "GR no.: " << line[0] << "\nFirst Name: " << line[1] << "\t\tLast Name: " << line[2] << "\t\tFather's Name: " << line[3] << "\t\tMother's Name: " << line[4] << "\nContact No.: " << line[5] << "\t\tCity: " << line[6] << "\nBranch: " << line[7] << "\t\tQuota: " << line[8] << endl << endl << endl;
                //cout << studRecord;
                break;
            }
            else {
                continue;
            }
        }

        if(flag == 0) 
            cout << "\n\nRecord not found for given details. Make sure you have entered correct details." << endl << endl << endl;
        
    }
    else {
        cout << "\n\nDatabase file not accessible." << endl << endl;
    }

}

void AdmittedStud::displayInfo(){
    cout << "GR No.: \t" << this->GR << endl;
    cout << "Name: \t\t" << this->studentName << endl;
    cout << "Branch: \t" << this->studentBranch << endl;
}

class Student
{
    private:
        string studentName;
        string studentLastName;
        float percentile;
        int programChoice[3];
        int quota;
        string fatherName;
        string motherName;
        string contactNo;
        string city;
        
    public:
        Student();
        Student(vector<string> &line);
        void takeData();
        void printData();
        int getCategory();
        string assignBranch(int quota);
        string generateGR(int, string);

    friend class Branch;
};

static int studCount = 0;

Student::Student(){
    studCount++;
}

Student::Student(vector<string> &line)
{
    studentName = line[0];
    studentLastName = line[1];
    fatherName = line.at(2);
    motherName = line.at(3);
    contactNo = line.at(4);
    city = line.at(5);
    percentile = stof(line[6]);
    quota = stoi(line.at(7));
    programChoice[0] = stoi(line.at(8));
    programChoice[1] = stoi(line.at(9));
    programChoice[2] = stoi(line.at(10));
    
    studCount++;
}

void Student::takeData(){
    cout << "\nEnter student first name: ";
    //fflush(stdin);
    //fgets(this->studentName,30,stdin);
    cin >> this->studentName;
    //std::getline(std::cin, this->studentName);
    //getline(cin, this->studentName);
    //gets(this->studentName);
    cout << "\nEnter student last name: ";
    cin>> this->studentLastName;
    cout << "\nEnter father's name: ";
    cin >> this->fatherName;
    cout << "\nEnter mother's name: ";
    cin >> this->motherName;
    cout << "\nEnter contact no.: ";
    cin >> this->contactNo;
    cout << "\nEnter city of residence: ";
    cin >> this->city;
    cout << "\nENter student percentile: ";
    cin >> this->percentile;
    cout << "\nEnter quota: ";
    cin >> this->quota;
    cout << "\n\nProgram choice menu: \n1 = Chemical\t2 = Computer\t3 = Electronics\t4 = Production\n5 = Instrumentation\t6 = IT\t7 = Mechanical";
    cout << "\nEnter first program choice: ";
    cin >> this->programChoice[0];
    cout << "\nEnter second program choice: ";
    cin >> this->programChoice[1];
    cout << "\nEnter third program choice: ";
    cin >> this->programChoice[2];
}

void Student::printData(){
    std::cout << "Name: " << studentName << endl;
    std::cout << "Choice1: " << programChoice[0] << endl;
    std::cout << "Choice2: " << programChoice[1] << endl;
    std::cout << "Choice3: " << programChoice[2] << endl;
    switch (quota)
    {
        case 1:
            std::cout << "Quota: Open" << endl;
            break;

        case 2:
            std::cout << "Quota: Category" << endl;
            break;

        default:
            break;
    }
}

int Student::getCategory(){
    return quota;
}

string Student::assignBranch(int quota){
    /* Quota 
    1 = Open
    2 = Category */

   /* Branch
    1 = Chemical
    2 = Computer
    3 = Electronics
    4 = Production
    5 = Instrumentation
    6 = IT
    7 = Mechanical*/
    
    int cutoff;
    string grn = "false";

    if (quota == 1){
        for (int i = 0; i < 3; ++i){

            switch(programChoice[i]){
                case 1:
                    if(branch.isAvailable(branch.openChemical, 70)){
                        cutoff = 80;
                        int filledSeats = count(branch.openChemical, branch.openChemical+70, true);
                        if (this->percentile >= cutoff){
                            branch.openChemical[filledSeats] = true;        //next seat is filled
                            grn = generateGR(studCount, "CH");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Chemical", grn, "Open", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(1, 1);
                            return grn;
                        }  
                    }
                    break;
                case 2:
                    if(branch.isAvailable(branch.openComputer, 70)){
                        cutoff = 90;
                        int filledSeats = count(branch.openComputer, branch.openComputer+70, true);
                        if (this->percentile >= cutoff){
                            branch.openComputer[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "CS");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Computer", grn, "Open", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(1, 2);
                            return grn;
                        } 
                    }
                    break;
                case 3:
                    if(branch.isAvailable(branch.openElectronics, 70)){
                        cutoff = 85;
                        int filledSeats = count(branch.openElectronics, branch.openElectronics+70, true);
                        if (this->percentile >= cutoff){
                            branch.openElectronics[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "EC");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Electronics", grn, "Open", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(1, 3);
                            return grn;
                        } 
                    }
                    break;
                case 4:
                    if(branch.isAvailable(branch.openProduction, 70)){
                        cutoff = 75;
                        int filledSeats = count(branch.openProduction, branch.openProduction+70, true);
                        if (this->percentile >= cutoff){
                            branch.openProduction[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "PD");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Production", grn, "Open", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(1, 4);
                            return grn;
                        }  
                    }
                    break;
                case 5:
                    if(branch.isAvailable(branch.openInstrumentation, 70)){
                        cutoff = 70;
                        int filledSeats = count(branch.openInstrumentation, branch.openInstrumentation+70, true);
                        if (this->percentile >= cutoff){
                            branch.openInstrumentation[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "IS");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Instrumentation", grn, "Open", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(1, 5);
                            return grn;
                        }
                    }
                    break;
                case 6:
                    if(branch.isAvailable(branch.openIT, 70)){
                        cutoff = 85;
                        int filledSeats = count(branch.openIT, branch.openIT+70, true);
                        if (this->percentile >= cutoff){
                            branch.openIT[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "IT");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "IT", grn, "Open", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(1, 6);
                            return grn;
                        }
                    }
                    break;
                case 7:
                    if(branch.isAvailable(branch.openMechanical, 70)){
                        cutoff = 85;
                        int filledSeats = count(branch.openMechanical, branch.openMechanical+70, true);
                        if (this->percentile >= cutoff){
                            branch.openMechanical[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "ME");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Mechanical", grn, "Open", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(1, 7);
                            return grn;
                        }
                    }
                    break;
                default:
                    break;
            }
            if(i == 2)
                return grn;
        }
    }

    if (quota == 2){
        for (int i = 0; i < 3; ++i){
            switch(programChoice[i]){
                case 1:
                    if(branch.isAvailable(branch.categoryChemical, 30)){
                        cutoff = 60;
                        int filledSeats = count(branch.categoryChemical, branch.categoryChemical+30, true);
                        if (this->percentile >= cutoff){
                            branch.categoryChemical[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "CH");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Chemical", grn, "Category", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(2, 1);
                            return grn;
                        }
                    }
                    break;
                case 2:
                    if(branch.isAvailable(branch.categoryComputer, 30)){
                        cutoff = 70;
                        int filledSeats = count(branch.categoryComputer, branch.categoryComputer+30, true);
                        if (this->percentile >= cutoff){
                            branch.categoryComputer[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "CS");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Computer", grn, "Category", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(2, 2);
                            return grn;
                        }  
                    }
                    break;
                case 3:
                    if(branch.isAvailable(branch.categoryElectronics, 30)){
                        cutoff = 65;
                        int filledSeats = count(branch.categoryElectronics, branch.categoryElectronics+30, true);
                        if (this->percentile >= cutoff){
                            branch.categoryElectronics[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "EC");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Electronics", grn, "Category", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(2, 3);
                            return grn;
                        }
                    }
                    break;
                case 4:
                    if(branch.isAvailable(branch.categoryProduction, 30)){
                        cutoff = 60;
                        int filledSeats = count(branch.categoryProduction, branch.categoryProduction+30, true);
                        if (this->percentile >= cutoff){
                            branch.categoryProduction[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "PD");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Production", grn, "Category", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(2, 4);
                            return grn;
                        }
                    }
                    break;
                case 5:
                    if(branch.isAvailable(branch.categoryInstrumentation, 30)){
                        cutoff = 55;
                        int filledSeats = count(branch.categoryInstrumentation, branch.categoryInstrumentation+30, true);
                        if (this->percentile >= cutoff){
                            branch.categoryInstrumentation[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "IS");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Instrumentation", grn, "Category", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(2, 5);
                            return grn;
                        }
                    }
                    break;
                case 6:
                    if(branch.isAvailable(branch.categoryIT, 30)){
                        cutoff = 65;
                        int filledSeats = count(branch.categoryIT, branch.categoryIT+30, true);
                        if (this->percentile >= cutoff){
                            branch.categoryIT[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "IT");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "IT", grn, "Category", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(2, 6);
                            return grn;
                        }
                    }
                    break;
                case 7:
                    if(branch.isAvailable(branch.categoryMechanical, 30)){
                        cutoff = 65;
                        int filledSeats = count(branch.categoryMechanical, branch.categoryMechanical+30, true);
                        if (this->percentile >= cutoff){
                            branch.categoryMechanical[filledSeats] = true;       //next seat is filled
                            grn = generateGR(studCount, "ME");
                            AdmittedStud admtStud(this->studentName, this->studentLastName, "Mechanical", grn, "Category", this->fatherName, this->motherName, this->contactNo, this->city);
                            //admtStud.displayInfo();
                            admtStud.storeInfo(2, 7);
                            return grn;
                        }
                    }
                    break;
                default:
                    break;
            }
            if(i == 2)
                return grn;
        }
    }
    return grn;
}

string Student::generateGR(int num, string code){
    string GR;
    string number = to_string(num);
    string newNumber;

    switch (number.size())
    {
    case 1:
        newNumber = "00000" + number;
        break;
    
    case 2:
        newNumber = "0000" + number;
        break;
    
    case 3:
        newNumber = "000" + number;
        break;
    
    case 4:
        newNumber = "00" + number;
        break;
    
    case 5:
        newNumber = "0" + number;
        break;
    
    case 6:
        newNumber = number;
        break;
    
    default:
        cout << "Problem generating GR No.";
        break;
    }

    GR = "2021" + code + newNumber;

    return GR;
}

int main(){
    ifstream admissionFile;

    string studApplication;         //to store one line from the file
    string word;                    //to store contents of each cell from one line of the file
    vector <string> line;           //to store each cell separately from one line of the file
    
    admissionFile.open("Database.csv");
    if (admissionFile.is_open()) {
        cout << "Database accessed." << endl << endl;
    }
    else {
        cerr << "Database not accessed." << endl << endl;
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
        //s1.printData();

        //assign branch now
        s1.assignBranch(s1.getCategory());

        /* switch (s1.getCategory()){
            case 1:
                s1.assignBranch(1);
                break;
            
            case 2:
                s1.assignBranch(2);
                break;
        }  */

    }

    while (true)
    {
        int choice, qta;
        string admissionStatus;
        string grn;
        Student s2;
        AdmittedStud s3;

        cout << "Menu:\n1. Admit new Student\t2. Find existing student\t3. Show total seats filled in each branch\t4. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s2.takeData();
            admissionStatus = s2.assignBranch(s2.getCategory());
            if(admissionStatus == "false")
                cout << "\n\nAdmission unsuccessful!" << endl << endl << endl;
            else{
                cout << "\n\nAdmission successful!\nGR no.: " << admissionStatus << endl << endl << endl;
            }
                
            break;

        case 2:
            cout << "\nEnter GR no.: ";
            cin >> grn;
            cout << "\nEnter quota (1 = Open, 2 = category): ";
            cin >> qta;
            s3.search(grn, qta);
            break;

        case 3:
            branch.showFilledSeatData();
            break;

        case 4:
            goto end;
            break;
        
        default:
            cout << "Invalid input!";
            break;
        }
    }

    end: admissionFile.close();

    return 0;
}