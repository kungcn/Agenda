//  Agenda Stage 01 : Meeting.cpp
//  definitions of class Meeting and its methods

#include <string>
#include "Meeting.h"
#include "Date.h"
using std::string;

//  default constructor
Meeting::Meeting() {}

//  constructor with parameters
Meeting::Meeting(std::string sponsor, std::string participator,
          Date startTime, Date endTime, std::string title)
    : sponsor_(sponsor), participator_(participator),
      title_(title) {
    if (Date::isValid(startTime) && Date::isValid(endTime)) {
        if (startTime <= endTime) {
            startDate_ = startTime;
            endDate_ = endTime;
        }
    }
      }

//  return sponsor_
std::string Meeting::getSponsor(void) const {
    return sponsor_;
}  //  end Meeting getSponsor function

//  set sponsor_
void Meeting::setSponsor(std::string sponsor) {
    sponsor_ = sponsor;
}  //  end Meeting setSponsor function

//  return participator_
std::string Meeting::getParticipator(void) const {
    return participator_;
}  //  end Meeting getParticipator function

//  set participator_
void Meeting::setParticipator(std::string participator) {
    participator_ = participator;
}  //  end Meeting setParticipator function

//  return startDate_
Date Meeting::getStartDate(void) const {
    return startDate_;
}  //  end Meeting getStartDate function

//  set startDate_
void Meeting::setStartDate(Date startTime) {
    startDate_ = startTime;
}  //  end Meeting setStartDate function

//  return endDate_
Date Meeting::getEndDate(void) const {
    return endDate_;
}  //  end Meeting getEndDate function

//  set endDate_
void Meeting::setEndDate(Date endTime) {
    endDate_ = endTime;
}  //  end Meeting setEndDate function

//  return title_
std::string Meeting::getTitle(void) const {
    return title_;
}  //  end Meeting getTitle function

//  set title_
void Meeting::setTitle(std::string title) {
    title_ = title;
}  //  end Meeting setTitle function

