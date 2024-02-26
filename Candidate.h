//
// Created by Student on 26/02/2024.
//

#ifndef PART1_CANDIDATE_H
#define PART1_CANDIDATE_H

# include <iostream>
using namespace std;
# include <string>
#include "User.h"
//#include "Resume.h"

class Candidate : public User {
private:
    string birth_date_candidate;
    string email_candidate;
    //Resume candidate_resume;
public:
    Candidate(const string &userName, const string &password, const string &user_id, const string &birth_date_candidate,
              const string &email_candidate/*,const Resume &candidate_resume*/) : User(userName, password, user_id),
                                                                                  birth_date_candidate(
                                                                                          birth_date_candidate),
                                                                                  email_candidate(
                                                                                          email_candidate) /*candidate_resume(candidate_resume)*/{};

    string &getBirthDate();

    string &getEmailCandidate();

    void setResumeFilePath(const string &path);

    //Resume& getCandidateResume();
    void setBirthDate(const string &birth_date);

    void setEmail(const string &email);

    ~Candidate();

};
#endif //PART1_CANDIDATE_H
