#include <iostream>
using namespace std;
#include "JobSearchSystem.h"
#include "User.h"
#include "Employer.h"
#include "Candidate.h"
void EntranceEmploy();// אם יש משתמש קיים מבקשים תז וסיסמה ומאמתים שאכן הוא רשום
void CreateEmploy();
void EntranceCandidate();
void Entrance();// פתיחה



int main() {
Entrance();// -----> Initial login to the system




    cout << "Hello, World!" << std::endl;
    return 0;
}
void Entrance(){
    int choose;
    cout<<"If you candidate please enter 1. \nIf you employer please enter 2." <<endl;
    cin>> choose;
    if (choose==1){
        //candidate.
        int us;
        cout<<"If you have an user of candidate, enter 1. \nIf you want to create a new user of candidate, enter 2." <<endl;
        cin>>us;
        if (us==1){
            //נשלח לפונקציה שנכנסת לאתר
            // נשלח לפונקציה שמאמתת שאכן יש אותו באתר
        } else  {
            // נשלח לפונקציה שיוצרת משתמש חדש
            }

    } else {
        //employer
        int us;
        cout<<"If you have an user of employer, enter 1 \nIf you want to create a new user of employer, enter 2" <<endl;
        cin>>us;
        if (us==1){
            EntranceEmploy();
            // נשלח לפונקציה שמאמתת שאכן יש אותו באתר
        } else  {
            CreateEmploy();
            Entrance();

        }
    }




}
void EntranceEmploy(){
    JobSearchSystem a;
    string id,password;
    cout<< "Enter your id: "<<endl;
    cin>>id;
    cout<< "Enter your password: "<<endl;
    cin>>password;
    a.loginEmployer(id,password);// בדיקה אם הוא באמת נמצא באתר

}
void CreateEmploy(){
    JobSearchSystem a;
    string id,password,name;
    cout<< "Enter your name: "<<endl;
    cin>>name;
    while (id.size()!=9) {
        cout << "Enter your id: " << endl;
        cin >> id;
    }

    cout<< "Enter your password: "<<endl;
    cin>>password;
    a.registerEmployer(id,password,name);
}
