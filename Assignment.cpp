#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Assignment.h"
using namespace std;

Assignment::Assignment() {};            //default constructor

Assignment::Assignment(string cat, float wei, float gra) {
    category = cat;
    weight = wei/100;
    grade = gra;
};

Assignment::~Assignment() {};

void Assignment::update(float gra) {
    grade = gra;
};