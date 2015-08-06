//  Agenda Stage 02 : AgendaUI.cpp
//  the definitions of the class AgendaUI and its methods

#include <iostream>
#include <string>
#include "AgendaUI.h"
#include "AgendaService.h"
#include "Storage.h"

using std::string;
using std::cout;
using std::endl;
using std::list;
using std::cin;

static int flag = 0;

AgendaUI::AgendaUI() {}

void AgendaUI::OperationLoop(void) {
    startAgenda();
}

//  start Agenda
void AgendaUI::startAgenda(void) {
    while (true) {
        if (!flag) {
            cout << "----------------------- Agenda -----------------------" << endl;
            cout << "Action : " << endl;
            cout << "l   - log in Agenda by user name and password" << endl;
            cout << "r   - register an Agenda accout" << endl;
            cout << "quit   - quit Agenda" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << endl;
            cout << "Agenda : ~$" << endl;
            string qRl;
            cin >> qRl;
            executeOperation(qRl);
            if (qRl == "q")
                break;
        }
        if (flag) {
            cout << "----------------------- Agenda -----------------------" << endl;
            cout << "Action : " << endl;
            cout << "a    - log out Agenda" << endl;
            cout << "dc   - delete Agenda account" << endl;
            cout << "lu   - list all meetings" << endl;
            cout << "cm   - create a meeting" << endl;
            cout << "la   - list all meetings" << endl;
            cout << "las  - list all sponsor meetings" << endl;
            cout << "lap  - list all participate meetings" << endl;
            cout << "qm   - query meeting by title" << endl;
            cout << "qt   - query meeting by time interval" << endl;
            cout << "dm   - delete meeting by title" << endl;
            cout << "da   - delete all meetings"  << endl;
            cout << "-------------------------------------------------------" << endl;
            string tt;
            cin >> tt;
            executeOperation(tt);
            cout << "Agenda@" << userName_ << " : # " << endl;
            if (tt == "q")
                break;
        }
    }
}  //  end AgendaUI startAgenda function

//  get operation
//std::string AgendaUI::getOperation() {
//}  //  end AgendaUI getOperation function

//  execute operation
bool AgendaUI::executeOperation(std::string op) {
    if (op == "l")
        userLogIn();
    if (op == "cm")
        createMeeting();
    else if (op == "o")
        userLogOut();
    else if (op == "dc")
        deleteUser();
    else if (op == "lu")
        listAllUsers();
    else if (op == "la")
        listAllMeetings();
    else if (op == "las")
        listAllSponsorMeetings();
    else if (op == "lap")
        listAllParticipateMeetings();
    else if (op == "qm")
        queryMeetingByTitle();
    else if (op == "qt")
        queryMeetingByTimeInterval();
    else if (op == "dm")
        deleteMeetingByTitle();
    else if (op == "da")
        deleteAllMeetings();
    else if (op == "r")
        userRegister();
    else if (op == "q") {
        quitAgenda();
    }
    return 0;
}  //  end AgendaUI executeOperation function

//  user login
void AgendaUI::userLogIn(void) {
    string action;
    cout <<"[Log in] [userName] [password]" << endl;
    cout << "[log in] ";
    cin >> userName_;
    cin >> userPassword_;
    if (agendaService_.userLogIn(userName_, userPassword_)) {
    cout << "----------------------- Agenda -----------------------" << endl;
            cout << "Action : " << endl;
            cout << "a    - log out Agenda" << endl;
            cout << "dc   - delete Agenda account" << endl;
            cout << "lu   - list all meetings" << endl;
            cout << "cm   - create a meeting" << endl;
            cout << "la   - list all meetings" << endl;
            cout << "las  - list all sponsor meetings" << endl;
            cout << "lap  - list all participate meetings" << endl;
            cout << "qm   - query meeting by title" << endl;
            cout << "qt   - query meeting by time interval" << endl;
            cout << "dm   - delete meeting by title" << endl;
            cout << "da   - delete all meetings"  << endl;
            cout << "-------------------------------------------------------" << endl;
    cout << "Agenda@" << userName_ << " : # " << endl;
    flag = 1;
    cin >> action;
    executeOperation(action);
    } else {
        cout << "[error] log in fail!" << endl;
    }
}  //  end AgendaUI userLogIn function

//  user register
void AgendaUI::userRegister(void) {
    cout << "[register] [userName] [password] [email] [phone]" << endl;
    cout << "[register] ";
    string name, pass, email, phone;
    cin >> name >> pass >> email >> phone;
    if (agendaService_.userRegister(name, pass, email, phone)) {
        cout << "[register] succeed!" << endl;
    } else {
        cout << "[error] register fail!" << endl;
    }
}  //  end AgendaUI userRegister function

//  quit Agenda
void AgendaUI::quitAgenda(void) {
    agendaService_.quitAgenda();
    cout << "byebye" << endl;
}  //  end AgendaUI quitAgenda function

//  user logout
void AgendaUI::userLogOut(void) {
    userName_ = "";
    userPassword_ = "";
    cout << "Ok, see you" << endl;
}  //  end AgendaUI userLogOut function

//  delete user
void AgendaUI::deleteUser(void) {
    if (agendaService_.deleteUser(userName_, userPassword_)) {
        cout << "[delete user account] : succeed!" << endl;
    } else {
        cout << "[delete user accout] : fail!" << endl;
    }
}  //  end AgendaUI deleteUser function

//  list all users
void AgendaUI::listAllUsers(void) {
    cout << "[list all users]" << endl << endl;
    cout << "name email phone" << endl;
    std::list<User> re = agendaService_.listAllUsers();
    std::list<User>::iterator it;
    for (it = re.begin(); it != re.end(); ++it)
        cout << it->getName() << "\t" << it->getEmail() << "\t" << it->getPhone() << "\t" << endl;
}  //  end AgendaUI listAllUsers function

//  create meeting
void AgendaUI::createMeeting(void) {
    cout << "[create meeting] [title] [participator] [start time<yyyy-mm-dd/hh:mm>] [end time<yyyy-mm-dd/hh:mm>]" << endl;
    cout << "[create meeting]";
    string title, participator, startd, endd;
    cin >> title >> participator >> startd >> endd;
    if (agendaService_.createMeeting(userName_, title, participator, startd, endd)) {
        cout << "[create meeting] : succeed!" << endl;
    } else {
        cout << "[create meeting] : fail!" << endl;
    }
}  //  end AgendaUI createMeeting function

//  list all meetings
void AgendaUI::listAllMeetings(void) {
    cout << "[list all sponsor meetings]" << endl << endl;
    cout <<"title\tsponsor\tparticipator\tstart time\tend time\t" << endl;
    std::list<Meeting> re = agendaService_.listAllMeetings(userName_);
    std::list<Meeting>::iterator it;
    for (it = re.begin(); it != re.end(); ++it) {
        cout << it->getTitle() << "\t" << it->getSponsor() << "\t" << it->getParticipator() << "\t" << Date::dateToString(it->getStartDate()) << Date::dateToString(it->getStartDate()) << endl;
    }
}  //  end AgendaUI listAllMeetings

//  list all sponsor meetings
void AgendaUI::listAllSponsorMeetings(void) {
    cout << "[list all sponsor meeting]" << endl << endl;
    cout <<"title\tsponsor\tparticipator\tstart time\tend time\t" << endl;
    std::list<Meeting> re = agendaService_.listAllSponsorMeetings(userName_);
    std::list<Meeting>::iterator it;
    for (it = re.begin(); it != re.end(); ++it) {
        cout << it->getTitle() << "\t" << it->getSponsor() << "\t" << it->getParticipator() << "\t" << Date::dateToString(it->getStartDate()) << endl;
    }
}  //  end AgendaUI listAllSponsorMeetings function

//  list all participate meetings
void AgendaUI::listAllParticipateMeetings(void) {
    cout << "[list all participate meeting]" << endl << endl;
    cout <<"title\tsponsor\tparticipator\tstart time\tend time\t" << endl;
    std::list<Meeting> re = agendaService_.listAllParticipateMeetings(userName_);
    std::list<Meeting>::iterator it;
    for (it = re.begin(); it != re.end(); ++it) {
        cout << it->getTitle() << "\t" << it->getSponsor() << "\t" << it->getParticipator() << "\t" << Date::dateToString(it->getStartDate()) << endl;
    }
}  //  end AgendaUI listAllParticipateMeetings function

//  query meeting by title
void AgendaUI::queryMeetingByTitle(void) {
    string title;
    cout << "[query meeting] [title]:" << endl;
    cout << "[query meeting] " << endl;
    cin >> title;
    cout << endl;
    cout << "sponsor\tparticipator\tstart time\tend time\t" << endl;
    std::list<Meeting>::iterator it;
    std::list<Meeting> re = agendaService_.meetingQuery(userName_, title);
    for (it = re.begin(); it != re.end(); ++it)
        cout << it->getSponsor() << '\t' << it->getParticipator() << '\t' <<
            Date::dateToString(it->getStartDate()) << '\t' << Date::dateToString(it->getEndDate()) << '\t' << endl;
}//  end AgendaUI queryMeetingTitle function

//  query meeting by time interval
void AgendaUI::queryMeetingByTimeInterval(void) {
    cout << "[query meetings] [start time] [end time]:" << endl;
    cout << "[query meetings] " << endl;
    string startDate,endDate;
    cin >> startDate >> endDate;
    cout << endl;
    cout << "title\tsponsor\tparticipator\tstart time\t" << endl;
    std::list<Meeting>::iterator it;
    std::list<Meeting> re = agendaService_.meetingQuery(userName_, startDate, endDate);
    for (it = re.begin(); it != re.end(); ++it)
        cout << it->getTitle() << '\t' << it->getSponsor() << '\t' << it->getParticipator() << '\t' <<
            Date::dateToString(it->getStartDate()) << '\t' << endl;
}  //  end AgendaUI queryMeetingByTimeInterval function


//  delete meeting by title
void AgendaUI::deleteMeetingByTitle(void) {
    cout << "[delete meeting] [title]" << endl;
    cout << "[delete meeting] ";
    string title;
    cin >> title;
    cout << "[delete meeting by title] " << endl;
    if (agendaService_.deleteMeeting(userName_, title)) {
        cout << "[delete meeting by title] succeed!" << endl;
    } else {
        cout << "[error] delete meeting fail!" << endl;
    }
}  //  end AgendaUI deleteMeetingByTitle function

//  delete all meetings
void AgendaUI::deleteAllMeetings(void) {
    cout << "[delete all meetings] succeed!" << endl;
    agendaService_.deleteAllMeetings(userName_);
}  //  end AgendaUI deleteAllMeetings function

//  print meetings
void AgendaUI::printMeetings(std::list<Meeting> meetings) {
    std::list<Meeting>::iterator it;
    for (it = meetings.begin(); it != meetings.end(); ++it) {
        cout << it->getTitle() << "\t" << it->getSponsor() << "\t" << it->getParticipator();
        cout << "\t" << Date::dateToString(it->getStartDate()) << "\t" << Date::dateToString(it->getEndDate()) << endl;
    }
}  //  end AgendaUI printMeetings function
