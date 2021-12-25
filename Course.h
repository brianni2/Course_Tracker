#include <string>
#include <vector>
#include "Assignment.h"
using namespace std;

const string categories[] = {"HW", "QUIZ", "TEST", "PROJECT", "MISC"};

class Course {
    public: 
        Course();
        Course(string);
        vector<Assignment> assignments[5];
        int size[5] = {0, 0, 0, 0, 0};
        void addAss(string, float, float);
        void update(int, int, float);
        float getGrade(int);
        void display();
        
        string name;
        float grade;
};