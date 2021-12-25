#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Course.h"
using namespace std;

const int HW = 0;
const int QUIZ = 1;
const int TEST = 2;
const int PROJECT = 3;
const int MISC = 4;

const string COURSE_SELECT = "Please select a course\n";

int main() {
    ifstream inFS;
    ifstream cFile("Courses.txt");
    stringstream SS;
    string input, fileName;
    
    vector<string> courseNames;
    string cName;
    vector<Course> courses;
    cout << COURSE_SELECT;
    while(!cFile.eof()) {
        SS.clear();
        getline(cFile, cName);
        courseNames.push_back(cName);
        Course *newCourse = new Course(cName);
        courses.push_back(*newCourse);
        cout << cName << "\t";
    }
    cout << endl;
    
    int courseID;
    getline(cin, input);
    fileName = input;
    fileName.append(".txt");
    inFS.open(fileName);
    for(int i = 0; i < courses.size(); i++) {
        if(courses.at(i).name == input) {
            courseID = i;
            break;
        }
    }
    
    string category;
    float weight;
    float grade;
    while(!inFS.eof()) {
        SS.clear();
        getline(inFS, input);
        SS.str(input);
        SS >> category >> weight >> grade;
        courses.at(courseID).addAss(category, weight, grade);
    }
    courses.at(courseID).display();

    return 0;
}
