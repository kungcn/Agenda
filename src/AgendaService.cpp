//  Agenda Stage 02 : AgendaService.cpp
//  the definitions of the class AgendaService and its functions

#include "Storage.h"
#include "AgendaService.h"
#include <iterator>
#include <iostream>

using std::list;
using std::string;
using std::endl;
using std::cout;

//  default constructor
AgendaService::AgendaService() {
    storage_ = Storage::getInstance();
}

//  destructor
AgendaService::~AgendaService() {
    storage_ = NULL;
}

//  if login successfully, return true, else return false
bool AgendaService::userLogIn(std::string userName, std::string password) {
    std::list<User>::iterator it;
    std::list<User> temp = listAllUsers();
    if (temp.empty())
        return false;
    for (it = temp.begin(); it != temp.end(); ++it) {
        if (userName == it->getName()) {
            if (password == it->getPassword())
            return true;
        }
    }
    return false;
}  //  end AgendaService userLogIn function

//  if register sucessfully, return true else return false
bool AgendaService::userRegister(std::string userName, std::string password,
                                 std::string email, std::string phone) {
    std::list<User>::iterator it;
    std::list<User> temp = listAllUsers();
    for (it = temp.begin(); it != temp.end(); ++it)
        if (userName == it->getName())
            return false;
    User tmp(userName, password, email, phone);
    storage_->createUser(tmp);
    return true;
}  //  end AgendaService userRegister function

//  if delete user successfully, return true else return false
bool AgendaService::deleteUser(std::string userName, std::string password) {
    int delSuc = 0;
    string name = userName;
    string pass = password;
    delSuc = storage_->deleteUser([&name, &pass](const User& other)->bool {
            if (other.getName() == name && other.getPassword() == pass) {
                return true;
            } else {
                 return false;
            }
        });
    if (delSuc) {
        deleteAllMeetings(name);
        return true;
    } else {
        return false;
    }
}  //  end AgendaService deleteUser function
	// a user can only delete itself

//  return all users
std::list<User> AgendaService::listAllUsers(void) {
    std::list<User> result = storage_->queryUser([](const User& other)->bool {
                return true;
        });
    return result;
}  //  end AgendaService listAllUsers function

//  creat meetings
bool AgendaService::createMeeting(std::string userName, std::string title,
                     std::string participator,
                   std::string startDate, std::string endDate) {
	Meeting meeting(userName, participator, Date::stringToDate(startDate), Date::stringToDate(endDate), title);
        std::list<Meeting>::iterator it;
        std::list<Meeting> tmp = listAllMeetings(userName);
        for (it = tmp.begin(); it != tmp.begin(); ++it) {
            if (it->getTitle() == title)
                return false;
        }
        if (!Date::isValid(Date::stringToDate(startDate)))
            return false;
        else if (!Date::isValid(Date::stringToDate(endDate)))
            return false;
        else if (userName == participator)
            return false;
        else if (Date::stringToDate(startDate) >= Date::stringToDate(endDate))
            return false;
        for (it = tmp.begin(); it != tmp.end(); ++it) {
            if (Date::stringToDate(startDate) < it->getEndDate())
                return false;
            else if (Date::stringToDate(endDate) > it->getStartDate())
                return false;
        }
	storage_->createMeeting(meeting);
    return true;
}  //  end AgendaService createMeeting function

//  return query meeting
std::list<Meeting> AgendaService::meetingQuery(std::string userName, std::string title) {
    std::list<Meeting> result;
    result = storage_->queryMeeting([&userName, &title](const Meeting& other)->bool {
            if (userName == other.getSponsor() || userName == other.getParticipator()) {
                if (title == other.getTitle())
                    return true;
                else
                    return false;
            } else {
                return false;
            }
        });
    return result;
}  //  end AgendaService meetingQuery function

//  return query meeting but with another parameter
std::list<Meeting> AgendaService::meetingQuery(std::string userName, std::string startDate,
                                               std::string endDate) {
    std::list<Meeting> result;
    result = storage_->queryMeeting([&userName, &startDate, &endDate](const Meeting& other)->bool {
            if (other.getSponsor() == userName || other.getParticipator() == userName) {
                if (other.getStartDate() == Date::stringToDate(startDate) || other.getEndDate() == Date::stringToDate(endDate))
                    return true;
                else
                    return false;
            } else {
                return false;
            }
        });
    return result;
}  //  end AgendaService meetingQuery function

//  return all meetings
std::list<Meeting> AgendaService::listAllMeetings(std::string userName) {
    list<Meeting> result;
    string user = userName;
    result = storage_->queryMeeting([&user](const Meeting& meeting)->bool {
            if (user == meeting.getSponsor() || user == meeting.getParticipator())
                return true;
            else
                return false;
        });
    return result;
}  //  end AgendaService listAllMeetings function

//  return all sponsor meetings
std::list<Meeting> AgendaService::listAllSponsorMeetings(std::string userName) {
    list<Meeting> result;
    string user = userName;
    result = storage_->queryMeeting([user](const Meeting& meeting)->bool {
            if (user == meeting.getSponsor())
                return true;
            else
                return false;
        });
    return result;
}  //  end AgendaService listAllSponsorMeetins function

//  return all participator meetings
std::list<Meeting> AgendaService::listAllParticipateMeetings(std::string userName) {
    list<Meeting> result;
    result = storage_->queryMeeting([&userName](const Meeting& meeting)->bool {
            if (userName == meeting.getParticipator())
                return true;
            else
                return false;
        });
    return result;
}  //  end AgendaService listAllParticipateMeetings function

//  return true if delete successfully, else return false
bool AgendaService::deleteMeeting(std::string userName, std::string title) {
    int delSuc = 0;
    delSuc = storage_->deleteMeeting([&userName, &title](const Meeting& other)->bool {
            if (other.getSponsor() == userName && other.getTitle() == title)
                return true;
            else
                return false;
        });
    if (delSuc)
        return true;
    else
        return false;
}  //  end AgendaService deleteMeetings function

//  return truw if delete sucessfully, else return false but with less parameters
bool AgendaService::deleteAllMeetings(std::string userName) {
    int delSuc = 0;
    delSuc = storage_->deleteMeeting([&userName](const Meeting& meeting)->bool {
            if (meeting.getSponsor() == userName)
                return true;
            else
                return false;
        });
    if (delSuc)
        return true;
    else
        return false;
}  //  end AgendaService deleteMeetings

//  start to use the stystem
void AgendaService::startAgenda(void) {
    storage_->getInstance();
}  //  end AgendaService startAgenda function

//  quit the stystem and then print out all the result
void AgendaService::quitAgenda(void) {
    storage_->sync();
}  //  end AgendaService quitAgenda function

