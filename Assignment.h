#pragma once 
#include <string>
using namespace std;

class Assignment {
    public: 
        Assignment();
        Assignment(string, float, float);
        ~Assignment();
        void update(float);
        
        string category;
        float weight;
        float grade;
};