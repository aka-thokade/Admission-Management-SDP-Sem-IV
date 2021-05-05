#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Student
{
public:
    string studentName;
    int studentRank;
    int categoryRank;
    int programChoice[3];
//public:
    Student(/* args */);
    ~Student();
    void getData();

};

Student::Student(/* args */)
{
    
}

Student::~Student()
{
}

/* Student::getData(ifstream inFile){
    inFile >> studentName;
    inFile >> studentRank;
    inFile >> categoryRank;
    inFile >> programChoice[0];
    inFile >> programChoice[1];
    inFile >> programChoice[2];
} */

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
    bool managementInstrumentation[20];
    bool managementIT[20];
    bool managementMechanical[20];
    
public:
    Branch(/* args */);
    ~Branch();
};

Branch::Branch(/* args */)
{
}

Branch::~Branch()
{
}

int main(){
    ifstream admissionFile;

    string studApplication;         //to store one line from the file
    string word;                    //to store contents of each cell from one line of the file
    vector <string> line;           //to store each cell separately from one line of the file
    Student s1;

    admissionFile.open("AdmissionDatabase2.csv");
    if (admissionFile.is_open()) {
        cout << "File has been opened" << endl;
    }
    else {
        cout << "NO FILE HAS BEEN OPENED" << endl;
    }


    while (!admissionFile.eof()) {

        line.clear();
        admissionFile >> studApplication;

        std::stringstream temp(studApplication);

        while (std::getline(temp, word, ',')) {
            line.push_back(word);
        }

        /* s1.studentName = line[0];
        s1.studentRank = stoi(line[1]);
        s1.categoryRank = stoi(line[2]);
        s1.programChoice[0] = stoi(line[3]);
        s1.programChoice[1] = stoi(line[4]);
        s1.programChoice[2] = stoi(line[5]); */

        //stringstream temp(studApplication);
        
        /* std::getline(studApplication, s1.studentRank, ',');
        std::getline(admissionFile, s1.categoryRank, ',');
        getline(admissionFile, s1.programChoice[0], ',');
        getline(admissionFile, s1.programChoice[1], ',');
        admissionFile >> s1.programChoice[2]; */
        
        /* cout << "Name: " << s1.studentName << endl;
        cout << "Rank: " << s1.studentRank << endl;
        cout << "CRank: " << s1.categoryRank << endl;
        cout << "Choice1: " << s1.programChoice[0] << endl;
        cout << "Choice2: " << s1.programChoice[1] << endl;
        cout << "Choice3: " << s1.programChoice[2] << endl; */

        cout << "Name: " << line[0] << endl;
        cout << "Rank: " << line[2] << endl;
        cout << "CRank: " << line[3] << endl;
        cout << "Choice1: " << line[4] << endl;
        cout << "Choice2: " << line[5] << endl;
        cout << "Choice3: " << line[6] << endl;
    }
    admissionFile.close();
}