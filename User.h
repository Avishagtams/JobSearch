//
// Created by Student on 26/02/2024.
//

#ifndef PART1_USER_H
#define PART1_USER_H
using namespace std;
#include "string"
class User {
private:
    string user_name;
    string password;
    string user_id;
public:
    explicit User(const string &userName, const string &password, const string &user_id):user_name(userName),password(password),user_id(user_id){};
    ~User()=default;
};


#endif //PART1_USER_H
