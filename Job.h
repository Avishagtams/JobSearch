//
// Created by Student on 26/02/2024.
//

#ifndef PART1_JOB_H
#define PART1_JOB_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Job {
private:
    string title;
    string area;
    string type; // full time / half time etc.

public:
    Job(const string& title, const string& area, const string& type) : title(title), area(area), type(type) {}

    string getTitle() const { return title; }
    string getArea() const { return area; }
    string getType() const { return type; }
};


#endif //PART1_JOB_H
