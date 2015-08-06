#include "Storage.h"
#include "Date.h"
#include "User.h"
#include "Meeting.h"
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#define MAX 10000

using std::string;
using std::list;
using std::vector;
using std::cout;
using std::endl;

//  default constructor
Storage::Storage() {
    readFromFile("./");
}

// File IO
bool Storage::readFromFile(const char *fpath) {
    string path1(fpath);
    string path2(fpath);
    path1 += "User.csv";
    path2 += "Meeting.csv";
    /*char *p1 = new char[path1.length() + 2];
    char *p2 = new char[path2.length() + 2];
    for (unsigned int i = 0; i < path1.length(); i++)
        p1[i] = path1[i];
    for (unsigned int i = 0; i < path2.length(); i++)
        p2[i] = path2[i];*/
    std::ifstream ifs1;
    std::ifstream ifs2;
    ifs1.open(path1);
	ifs2.open(path2);
    if (!ifs1)
        return false;
    if (!ifs2)
        return false;
    // char kkk[MAX];
    std::string temp;
    int flag = 0;
    std::getline(ifs1, temp);
    while (std::getline(ifs1, temp)) {
        std::string others = temp;
        vector<string> res;
        for (unsigned int i = 0; i < others.length(); i++) {
            if (others[i] == ',' && others[i + 1] == '"' && others[i - 1] == '"') {
                res.push_back(others.substr(flag + 1, i - flag - 2));
                flag = i + 1;
            }
            else if (others[i] == '"' && i == others.length() - 1)
                res.push_back(others.substr(flag + 1, i - flag - 1));
        }
        std::vector<string>::iterator it = res.begin();
        string name = *it;
        string password = *(it + 1);
        string email = *(it + 2);
        string phone = *(it + 3);
        User result(name, password, email, phone);
        userList_.push_back(result);
    }
    int flag1 = 0;
    std::getline(ifs2, temp);
    while (std::getline(ifs2, temp)) {
        string other(temp);
        vector<string> res1;
        for (unsigned int i = 0; i < other.length(); i++) {
            if (other[i] == ',' && other[i - 1] == '"' && other[i + 1] == '"') {
                res1.push_back(other.substr(flag1 + 1, i - flag1 - 2));
                flag1 = i + 1;
            }
            else if (i == other.length() - 1 && other[i] == '"') {
                res1.push_back(other.substr(flag1 + 1, i - flag1 - 1));
			}
        }
        std::vector<string>::iterator it = res1.begin();
        string sponsor = *it;
        string participator = *(it + 1);
        string startDate = *(it + 2);
        string endDate = *(it + 3);
        string title = *(it + 4);
        Meeting m(sponsor, participator, Date::stringToDate(startDate), Date::stringToDate(endDate), title);
        meetingList_.push_back(m);
    }
	ifs1.close();
	ifs2.close();
    return true;
}  //  end Storage readFromFile function

//  File IO
bool Storage::writeToFile(const char *fpath) {
    std::ofstream ofs1;
    std::ofstream ofs2;
    string path1(fpath);
    string path2(fpath);
    path1 += "User.csv";
    path2 += "Meeting.csv";
    /*char *p1 = new char[path1.length() + 2];
    char *p2 = new char[path2.length() + 2];
    //for (unsigned int i = 0; i < path1.length(); i++)
        p1[i] = path1[i];
    for (unsigned int i = 0; i < path2.length(); i++)
        p2[i] = path2[i];*/
    std::list<User>::iterator it;
    std::list<Meeting>::iterator kt;
    ofs1.open(path1);
    if (!ofs1)
        return false;
    ofs1 << "\"name\",\"password\",\"email\",\"phone\"" << endl;
    for (it = userList_.begin(); it != userList_.end(); ++it) {
        string name = (*it).getName();
        /*for (int i = 0; i < name.length(); i++)
            if (name[i] == '"')
            name.insert(i - 1, "\"");*/
        string password = it->getPassword();
        /*for (int i = 0; i < password.length(); i++)
            if (password[i] == '"')
            password.insert(i - 1, "\"");*/
        string email = it->getEmail();
        /*for (int i = 0; i < email.length(); i++)
            if (email[i] == '"')
            email.insert(i - 1, "\"");*/
        string phone = it->getPhone();
        /*for (int i = 0; i < phone.length(); i++)
            if (phone[i] == '"')
            phone.insert(i - 1, "\"");*/
        string al = "\"" + name + "\"," + "\"" + password + "\"," + "\"" +
            email + "\"," + "\"" + phone + "\"";
        ofs1 << al << endl;
    }
    //bool check1 = ofs1.good();
    ofs1.close();
    ofs2.open(path2);
    if (!ofs2)
        return false;
    ofs2 << "\"sponsor\",\"participator\",\"start time\",\"end time\",\"title\""
         << endl;
    for (kt = meetingList_.begin(); kt != meetingList_.end(); ++kt) {
        string sponsor = kt->getSponsor();
        /*for (int i = 0; i < sponsor.length(); i++)
            if (sponsor[i] == '"')
            sponsor.insert(i - 1, "\"");*/
        string participator = kt->getParticipator();
        /*for (int i = 0; i < participator.length(); i++)
            if (participator[i] == '"')
            participator.insert(i - 1, "\"");*/
        string startDate = Date::dateToString(kt->getStartDate());
        /*for (int i = 0; i < startDate.length(); i++)
            if (startDate[i] == '"')
            startDate.insert(i - 1, "\"");*/
        string endDate = Date::dateToString(kt->getEndDate());
        /*for (int i = 0; i < endDate.length(); i++)
            if (endDate[i] == '"')
            endDate.insert(i - 1, "\"");*/
        string title = kt->getTitle();
        /*for (int i = 0; i < title.length(); i++)
            if (title[i] == '"')
            title.insert(i - 1, "\"");*/
        ofs2 << "\"" << sponsor << "\"," << "\"" <<
            participator << "\"," << "\"" << startDate << "\"," << "\"" <<
            endDate << "\"," << "\"" << title << "\"" << endl;
    }
    ofs2.close();
    //delete []p1;
    //delete []p2;
    return true;
}  //  end Storage writeToFile function

// singleton
Storage * Storage::getInstance(void) {
    if (instance_ == NULL)
        instance_ = new Storage();
    return instance_;
}  //  end getInstance function

//  destructor
Storage::~Storage() {
    sync();
    instance_ = NULL;
}

// CRUD for User & Meeting
// using C++11 Function Template and Lambda Expressions
void Storage::createUser(const User& others) {
    userList_.push_back(others);
}  //  end Storage creatUser function

//  return found users
std::list<User> Storage::queryUser(std::function<bool(const User&)> filter) {
    std::list<User> tempUser;
    std::list<User>::iterator it;
    for (it = userList_.begin(); it != userList_.end(); ++it)
        if (filter(*it))
            tempUser.push_back(*it);
    return tempUser;
}  //  end Storage queryUser function

// return the number of updated uesrs
int Storage::updateUser(std::function<bool(const User&)> filter,
                        std::function<void(User&)> switcher) {
    int count = 0;
    std::list<User>::iterator it;
    for (it = userList_.begin(); it != userList_.end(); ++it) {
        if (filter(*it)) {
            switcher(*it);
            count++;
        }
    }
    return count;
}  //  end Storage updateUser function

// return the number of deleted users
int Storage::deleteUser(std::function<bool(const User&)> filter) {
    std::list<User>::iterator it;
    int count = 0;
    for (it = userList_.begin(); it != userList_.end();)
        if (filter(*it)) {
            userList_.erase(it++);
            count++;
        } else {
            ++it;
        }
    return count;
}  //  end Storage deleteUser function

// push back the Meeting object
void Storage::createMeeting(const Meeting& others) {
    meetingList_.push_back(others);
}  //  end Storage createMeetion function

//  return the found meetings
std::list<Meeting> Storage::queryMeeting(std::function<bool
                                         (const Meeting&)> filter) {
    std::list<Meeting> tempMeeting;
    std::list<Meeting>::iterator it;
    for (it = meetingList_.begin(); it != meetingList_.end(); ++it)
        if (filter(*it))
            tempMeeting.push_back(*it);
    return tempMeeting;
}  //  end Storage queryMeeting function

// return the number of the updated meetings
int Storage::updateMeeting(std::function<bool(const Meeting&)>
                           filter, std::function<void(Meeting&)> switcher) {
    int count = 0;
    std::list<Meeting>::iterator it;
    for (it = meetingList_.begin(); it != meetingList_.end(); ++it) {
        if (filter(*it)) {
            switcher(*it);
            count++;
        }
    }
    return count;
}  //  end Storage updateMeetion function

// return the number of deleted meetings
int Storage::deleteMeeting(std::function<bool(const Meeting&)>
                           filter) {
    int count = 0;
    std::list<Meeting>::iterator it;
    for (it = meetingList_.begin(); it != meetingList_.end(); ++it) {
        if (filter(*it)) {
            meetingList_.erase(it);
            count++;
        }
    }
    return 0;
}  //  end Storage deleteMeeting function

// File IO
bool Storage::sync(void) {
    if (writeToFile("./"))
        return true;
    else
        return false;
}  //  end Storage sync function


Storage* Storage::instance_ = NULL;
