#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



struct Student {

    string name;
    string indexNumber;

};


vector<Student> students;



// REGISTER
void registerStudent(){

    Student s;

    cin.ignore();

    cout<<"Enter name: ";
    getline(cin,s.name);

    cout<<"Enter index: ";
    getline(cin,s.indexNumber);

    students.push_back(s);

}



// VIEW
void viewStudents(){

    for(int i=0;i<students.size();i++){

        cout<<students[i].name
        <<" "
        <<students[i].indexNumber<<endl;

    }

}



// SAVE FILE
void save(){

    ofstream file("students.txt");

    for(int i=0;i<students.size();i++){

        file<<students[i].name
        <<","
        <<students[i].indexNumber<<endl;

    }

    file.close();

    cout<<"Saved successfully\n";

}



// LOAD FILE
void load(){

    ifstream file("students.txt");

    Student s;

    while(getline(file,s.name,',')){

        getline(file,s.indexNumber);

        students.push_back(s);

    }

}



// MAIN
int main(){

    load();

    int choice;

    do{

        cout<<"\n===== WEEK 4 SYSTEM =====\n";

        cout<<"1 Register\n";
        cout<<"2 View\n";
        cout<<"3 Save\n";
        cout<<"0 Exit\n";

        cin>>choice;

        switch(choice){

            case 1: registerStudent(); break;

            case 2: viewStudents(); break;

            case 3: save(); break;

        }

    }

    while(choice!=0);

}