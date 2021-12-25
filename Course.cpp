#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Course.h"
using namespace std;

Course::Course() {};
Course::Course(string nam) {
    name = nam;
};

void Course::addAss(string cat, float wei, float gra) {
    for(int i = 0; i < 5; i++) {
        if (cat == categories[i]) {
            Assignment *newAss = new Assignment(cat, wei, gra);
            assignments[i].push_back(*newAss);
            size[i]++;
            return;
        }
    }
};

void Course::update(int cat, int num, float gra) {
    assignments[cat].at(num).update(gra);
};

float Course::getGrade(int cat = 5) {
    if(cat < 2 or cat == 3) {
        if(size[cat] != 0) {
            float sum = 0;;
            for(int i = 0; i < size[cat]; i++) {
                sum += assignments[cat].at(i).grade;
            }
            sum = sum/size[cat];
            sum = sum * assignments[cat].at(0).weight;
            //cout << fixed << setprecision(2) << sum << "\t";
            return sum;
        }
        else {
            return 0;
        }
    }
    if(cat == 2 or cat == 4) {
        if(size[cat] != 0) {
            float sum = 0;
            for(int i = 0; i < size[cat]; i++) {
                sum += assignments[cat].at(i).grade * assignments[cat].at(i).weight;
            }
            //cout << fixed << setprecision(2) << sum << "\t";
            return sum;
        }
        else {
            return 0;
        }
    }
    else {
        for(int i = 0; i < 5; i++) {
            grade += getGrade(i);
        }
        return grade;
    }
};

void Course::display() {
    //display row by row as assignments[i].at(i)
    const int HEADER_WIDTH = 8;
    const int COLUMN_WIDTH = 8;
    const int NEW_LINE = 6;

    ostringstream hw, quiz, test, proj, misc, total; 
    
    if(size[0] > 0) {
        hw << setw(HEADER_WIDTH) << left << "HW";
        for(int i = 0; i < size[0]; i++) {
            hw << setw(COLUMN_WIDTH) << right << fixed << setprecision(2) << assignments[0].at(i).grade;
            if((i+1)%NEW_LINE == 0 and i != 0 and i+1 < size[0]) {
                hw << endl << setw(HEADER_WIDTH) << "";
            }
        }
        cout << hw.str() << endl;
    }
    
    if(size[1] > 0) {
        quiz << setw(HEADER_WIDTH) << left << "QUIZ";
        for(int i = 0; i < size[1]; i++) {
            quiz << setw(COLUMN_WIDTH) << right << fixed << setprecision(2) << assignments[1].at(i).grade;
            if((i+1)%NEW_LINE == 0 and i != 0 and i+1 < size[1]) {
                quiz << endl << setw(HEADER_WIDTH) << "";
            }
        }
        cout << quiz.str() << endl;
    }
    
    if(size[2] > 0) {
        test << setw(HEADER_WIDTH) << left << "TEST";
        for(int i = 0; i < size[2]; i++) {
            test << setw(COLUMN_WIDTH) << right << fixed << setprecision(2) << assignments[2].at(i).grade;
            if((i+1)%NEW_LINE == 0 and i != 0 and i+1 < size[2]) {
                test << endl << setw(HEADER_WIDTH) << "";
            }
        }
        cout << test.str() << endl;
    }
    
    if(size[3] > 0) {
        proj << setw(HEADER_WIDTH) << left << "PROJECT";
        for(int i = 0; i < size[3]; i++) {
            proj << setw(COLUMN_WIDTH) << right << fixed << setprecision(2) << assignments[3].at(i).grade;
            if((i+1)%NEW_LINE == 0 and i != 0 and i+1 < size[3]) {
                proj << endl << setw(HEADER_WIDTH) << "";
            }
        }
        cout << proj.str() << endl;
    }
    
    if(size[4] > 0) {
        misc << setw(HEADER_WIDTH) << left << "MISC";
        for(int i = 0; i < size[4]; i++) {
            misc << setw(COLUMN_WIDTH) << right << fixed << setprecision(2) << assignments[4].at(i).grade;
            if((i+1)%NEW_LINE == 0 and i != 0 and i+1 < size[4]) {
                misc << endl << setw(HEADER_WIDTH) << "";
            }
        }
        cout << misc.str() << endl;
    }
    total << setw(HEADER_WIDTH) << left << "TOTAL";
    total << setw(COLUMN_WIDTH) << right << fixed << setprecision(2) << getGrade();
    cout << total.str() << endl;
};