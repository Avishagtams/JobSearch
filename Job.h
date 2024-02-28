//
// Created by Student on 26/02/2024.
//

#ifndef PART1_JOB_H
#define PART1_JOB_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Job {
private:

public:
    void addJob(const string &nameJ, const string &areaJ, const string &dateJ) {
        ofstream file("job.txt", ios::app);
        if (file.is_open()) {
            file << "Date: " << dateJ << " Name: " << nameJ << " area: " << areaJ << "." << endl;
            file << endl; // הוספת שורה ריקה
            file.close();
            cout << "add job successful.\n";
        } else {
            cerr << "Unable to add job.\n";
        }
    }

    void deleteJob(const string &nameToDelete) {
        ifstream inputFile("job.txt");
        ofstream outputFile("temp.txt");
        string line;

        if (!inputFile.is_open()) {
            cerr << "Unable to open input file.\n";
            return;
        }

        bool found = false;
        while (getline(inputFile, line)) {
            // Check if the line contains the job name to delete
            if (line.find("Name: " + nameToDelete) != string::npos) {
                found = true;
                continue; // Skip this line, effectively deleting it
            }
            outputFile << line << endl;
        }

        inputFile.close();
        outputFile.close();

        if (found) {
            remove("job.txt");         // Remove the old file
            rename("temp.txt", "job.txt");  // Rename temp file to original name
            cout << "Job '" << nameToDelete << "' deleted successfully.\n";
        } else {
            cout << "Job '" << nameToDelete << "' not found.\n";
            remove("temp.txt"); // Remove the temp file if the job wasn't found
        }
    }

    void editJob(const string &nameToEdit, const string &newName, const string &newArea, const string &newDate) {
        ifstream inputFile("job.txt");
        ofstream outputFile("temp.txt");
        string line;

        if (!inputFile.is_open()) {
            cerr << "Unable to open input file.\n";
            return;
        }

        bool found = false;
        while (getline(inputFile, line)) {
            // Check if the line contains the job name to edit
            if (line.find("Name: " + nameToEdit) != string::npos) {
                found = true;
                // Modify the line with new details
                outputFile << "Date: " << newDate << " Name: " << newName << " area: " << newArea << "." << endl;
            } else {
                outputFile << line << endl;
            }
        }

        inputFile.close();
        outputFile.close();

        if (found) {
            remove("job.txt");         // Remove the old file
            rename("temp.txt", "job.txt");  // Rename temp file to original name
            cout << "Job '" << nameToEdit << "' edited successfully.\n";
        } else {
            cout << "Job '" << nameToEdit << "' not found.\n";
            remove("temp.txt"); // Remove the temp file if the job wasn't found
        }
    }

    void viewPublishedJobs() {
        ifstream file("job.txt");
        string line;

        if (file.is_open()) {
            cout << "List of Published Jobs:\n";
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cerr << "Unable to open file.\n";
        }
    }
};



#endif //PART1_JOB_H
