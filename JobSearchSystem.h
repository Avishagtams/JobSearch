//
// Created by Student on 26/02/2024.
//

#ifndef PART1_JOBSEARCHSYSTEM_H
#define PART1_JOBSEARCHSYSTEM_H
using namespace std;
#include <vector>
#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include <string>


class JobSearchSystem {
private:
    //std::vector<User*> users;  // Use polymorphism with pointers to handle both candidates and employers
    // Other members and methods

public:
    // Other methods

    // Method to register a new employer
    void registerEmployer(const string& id, const string& password,const string& name) {
        ofstream file("employers.txt", ios::app);
        if (file.is_open()) {
            file <<"id: " << id << " password: " << password  <<" Name: "<<name<< "\n";
            file.close();
            cout << "Registration employer successful.\n";
        } else {
            cerr << "Unable to open file for registration.\n";
        }
    }
    // Method to register a new candidate
    void registerCandidate(const string& id, const string& password) {
        // TO DO: תוסיפי פה את כל השדות לפי דרישה מס 2 ותדאגי לקליטה שלהם בשורה 41
        ofstream file("candidate.txt", ios::app);
        if (file.is_open()) {
            file <<"id: " << id << "password: " << password  << "\n";
            file.close();
            cout << "Registration candidate successful.\n";
        } else {
            cerr << "Unable to open file for registration.\n";
        }
    }
    //if employer in text
    bool loginEmployer(const string& id, const string& password) {
        vector<string> employers;
        readFile("employers.txt", employers);
        for (const auto& emp : employers) {
            size_t pos = emp.find(" ");
            if (pos != string::npos) {
                string empId = emp.substr(4, id.size());
                string empPass = emp.substr(24,password.size());
                if (empId == id && empPass == password) {
                    cout << "Login employer successful.\n";
                    return true;
                }
            }
        }
        cout << "Invalid credentials. Please try again.\n";
        return false;
    }
    //if candidate in text
    bool loginCandidate(const string& id, const string& password) {
        vector<string> candidate;
        readFile("candidate.txt", candidate);
        for (const auto& emp : candidate) {
            size_t pos = emp.find(" ");
            if (pos != string::npos) {
                string empId = emp.substr(4, id.size());
                string empPass = emp.substr(24,password.size());
                if (empId == id && empPass == password) {
                    cout << "Login candidate successful.\n";
                    return true;
                }
            }
        }
        cout << "Invalid credentials. Please try again.\n";
        return false;
    }

    void readFile(const string& filename, vector<string>& data) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                data.push_back(line);
            }
            file.close();
        }
    }

};

#endif //PART1_JOBSEARCHSYSTEM_H
