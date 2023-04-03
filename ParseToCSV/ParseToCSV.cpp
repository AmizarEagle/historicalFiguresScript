// ParseToCSV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
int index = 0;
struct RulerRecord {
public:
    RulerRecord(
        string rulerName,
        string rulerDynasty,
        string rulerBirthday,
        string rulerAdm,
        string rulerDip,
        string rulerMil,
        string rulerDate
    ) {
        RulerName = rulerName;
        RulerDynasty = rulerDynasty;
        RulerBirthday = rulerBirthday;
        RulerAdm = rulerAdm;
        RulerDip = rulerDip;
        RulerMil = rulerMil;
        RulerDate = rulerDate;
    }
    void display() {
        cout << "Ruler Name: " << RulerName << endl;
        cout << "Ruler Dynasty: " << RulerDynasty << endl;
        cout << "Ruler Birthday: " << RulerBirthday << endl;
        cout << "Ruler Admin: " << RulerAdm << endl;
        cout << "Ruler Diplo: " << RulerDip << endl;
        cout << "Ruler Military: " << RulerMil << endl;
        cout << "Ruler Date: " << RulerDate << endl;
        cout << endl;
    }
    string Tag = "PAP";
    bool writeRecordToFile() {
        ofstream file;
        file.open("tutorial.txt", std::ios_base::app);
        //file << "country_decisions = {" << endl;
        //file << endl;
        file << "\tmonarch_" << Tag << "_No."<< index << "a = {" << endl;
        file << "\t\tmajor = yes" << endl;
        file << "\t\tpotential = {" << endl;
        file << "\t\t\ttag = " << Tag << endl;
        file << "\t\t\tis_year = " << RulerDate << endl;
        file << "\t\t\tNOT = { has_global_flag = monarch_"<< Tag << "_No."<<index << "a }" << endl;
        file << "\t\t}" << endl;
        file << "\t\tallow = {" << endl;
        file << "\t\t\tis_year = " << RulerDate << endl;
        file << "\t\t\tis_lesser_in_union = no" << endl;
        file << "\t\t\thas_regency = no" << endl;
        file << "\t\t}" << endl;
        file << "\t\teffect = {" << endl;
        file << "\t\t\tset_global_flag = monarch_"<<Tag<<"_No."<<index<<"a" << endl;
        file << "\t\t\tadd_stability = -1" << endl;
        file << "\t\t\tdefine_ruler = {" << endl;
        file << "\t\t\t\tname = \"" << RulerName << "\"" << endl;
        file << "\t\t\t\tdynasty = \"" << RulerDynasty << "\"" << endl;
        //file << "\t\t\t\tculture = ligurian" << endl;
        file << "\t\t\t\tbirth_date = " << RulerBirthday << endl;
        file << "\t\t\t\tadm = " << RulerAdm << endl;
        file << "\t\t\t\tdip = " << RulerDip << endl;
        file << "\t\t\t\tmil = " << RulerMil << endl;
        file << "\t\t\t}" << endl;
        file << "\t\t}" << endl;
        file << "\t\tai_will_do = {" << endl;
        file << "\t\t\tfactor = 1" << endl;
        file << "\t\t}" << endl;
        file << "\t}" << endl;
        file.close();
        index++;
        return true;
    }
    string RulerName;
    string RulerDynasty;
    string RulerBirthday;
    string RulerAdm;
    string RulerDip;
    string RulerMil;
    string RulerDate;
};


int main(int argc, char* argv)
{
    ifstream inputFile;
    inputFile.open("test.csv");
    vector<RulerRecord> rulers;
    string line = "";
    getline(inputFile, line);
    line = "";
    while (getline(inputFile, line)) {
        string rulerName;
        string rulerDynasty;
        string rulerBirthday;
        string rulerAdm;
        string rulerDip;
        string rulerMil;
        string rulerDate;

        string tempString = "";

        stringstream inputString(line);

        getline(inputString, rulerName, ',');
        getline(inputString, rulerDynasty, ',');
        getline(inputString, rulerBirthday, ',');
        getline(inputString, rulerAdm, ',');
        getline(inputString, rulerDip, ',');
        getline(inputString, rulerMil, ',');
        getline(inputString, rulerDate, ',');

        RulerRecord ruler(rulerName, rulerDynasty, rulerBirthday, rulerAdm, rulerDip, rulerMil, rulerDate);
        rulers.push_back(ruler);

        line = "";
    }
    ofstream file;
    file.open("tutorial.txt", std::ios_base::app);

    file << "country_decisions = {" << endl;
    file << endl;
    int index = 0;
    for (auto ruler : rulers) {
        ruler.display();
        ruler.writeRecordToFile();
    }

    return 0;
}
