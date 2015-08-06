//  Agenda Stage 01 : Date.cpp
//  definitions of class Date and its methods

#include "Date.h"
#include <sstream>
#include <iomanip>
#include <iostream>

using std::string;
using std::setw;
using std::setfill;
using std::cout;
using std::endl;

//  default constructor
Date::Date(void) {}

//  constructor with parameters
Date::Date(int y, int m, int d, int h, int mi)
  : year_(y), month_(m), day_(d), hour_(h), minute_(mi) {}

//  return year_
int Date::getYear(void) const {
  return year_;
}  //  end class Date getYear function

//  set year_
void Date::setYear(int year) {
  year_ = year;
}  //  end class Date setYear function

//  return month_
int Date::getMonth(void) const {
  return month_;
}  //  end class Date getMonth function

//  set month_
void Date::setMonth(int month) {
  month_ = month;
}  //  end class Date setMonth function

//  return day_
int Date::getDay(void) const {
  return day_;
}  //  end class Date getDay function

//  set day_
void Date::setDay(int day) {
  day_ = day;
}  //  end class Date setDay function

//  return hour_
int Date::getHour(void) const {
  return hour_;
}  //  end class Date getHour function

//  set hour_
void Date::setHour(int hour) {
  hour_ = hour;
}  // end class Date setHout function

//  return minute_
int Date::getMinute(void) const {
  return minute_;
}  //  end class Date getMinute function

//  set minute_
void Date::setMinute(int minute) {
  minute_ = minute;
}  // end class Date setMinute function

//  return true if object date is valid else return false
bool Date::isValid(Date date) {
  if (date.getYear() < 1000 || date.getYear() > 9999 ||
      date.getMonth() < 1 || date.getMonth() > 12 ||
      date.getDay() < 1 || date.getDay() > 31 ||
      date.getHour() > 23 || date.getHour() < 0 ||
      date.getMinute() > 59 || date.getMinute() < 0) {
    return false;
  } else {
    if (date.getMonth() != 2) {
        //  the following if isn't necessary because the previous one
        //  has already checked it, but I am not sure so I don't delete it
      if (date.getMonth() == 1 || date.getMonth() == 3
	  || date.getMonth() == 5 || date.getMonth() == 7 ||
          date.getMonth() == 8 || date.getMonth() == 10
          || date.getMonth() == 12) {
          if (date.getDay() > 31)
              return false;
      }
      else if (date.getMonth() == 4 || date.getMonth() == 6
               || date.getMonth() == 9 || date.getMonth() == 11) {
          if (date.getDay() > 30)
              return false;
      }
    }
    else if (date.getMonth() == 2) {
        if ((date.getYear() % 4 == 0 &&
             date.getYear() % 100 != 0) || date.getYear() % 400 == 0) {
            if (date.getDay() > 29)
                return false;
        } else {
            if (date.getDay() > 28)
                return false;
        }
    }
  }
    return true;
}  // end class Date isValid function

//  string turn into the Date object
Date Date::stringToDate(std::string dateString) {
    Date date;
    int year = 0;
    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
    char tmp;
    std::stringstream ss;
    ss.str(dateString);
    ss >> year >> tmp >> month >> tmp >> day >> tmp >> hour >> tmp >>minute;  //  set year_
    date.setYear(year);
    date.setMonth(month);
    date.setDay(day);
    date.setHour(hour);
    date.setMinute(minute);
    return date;
}  //  end class Date stringToDate function

//  the Date object turn into string
std::string Date::dateToString(Date date) {
    if (Date::isValid(date)) {
        std::stringstream ss;
        ss << date.year_ << "-" << setfill('0') << setw(2) << date.month_ <<
            "-" << setfill('0') << setw(2) << date.day_ << "/" << setfill('0')
           << setw(2) << date.hour_ << ":" << setfill('0') << setw(2) << date.minute_;
        string str = ss.str();
        return str;
    }
    return 0;
}  //  end class Date dateToString function

//  assignment operator
Date & Date::operator=(const Date& date) {
    this -> year_ = date.getYear();
    this -> month_ = date.getMonth();
    this -> day_ = date.getDay();
    this -> hour_ = date.getHour();
    this -> minute_ = date.getMinute();
    return *this;
}  //  end class Date assignment operator

//  return true if date is equal else return false
bool Date::operator==(const Date& date) const {
    if (this -> year_ != date.getYear()) {
        return false;
    } else {
        if (this -> month_ != date.getMonth()) {
            return false;
        } else {
            if (this -> day_ != date.getDay()) {
                return false;
            } else {
                if (this -> hour_ != date.getHour()) {
                    return false;
                } else {
                    if (this -> minute_ != date.getMinute()) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}  //  end class Date == operator

//  return true if date is smaller
bool Date::operator>(const Date& date) const {
    if (this -> year_ > date.getYear())
        return true;
    else if (this -> year_ < date.getYear())
        return false;
    else if (this -> year_ == date.getYear()) {
        if (this -> month_ > date.getMonth())
            return true;
        else if (this -> month_ < date.getMonth())
            return false;
        else if (this -> month_ == date.getMonth()) {
            if (this -> day_ > date.getDay())
                return true;
            else if (this -> day_ < date.getDay())
                return false;
            else if (this -> day_ == date.getDay()) {
                if (this -> hour_ > date.getHour())
                    return true;
                else if (this -> hour_ < date.getHour())
                    return false;
                else if (this -> hour_ == date.getHour()) {
                    if (this -> minute_ > date.getMinute())
                        return true;
                    else if (this -> minute_ <= date.getMinute())
                        return false;
                }
            }
        }
    }
    return 0;
}  //  end class Date > operator

//  return true if date is bigger
bool Date::operator<(const Date& date) const {
    if (this -> year_ < date.getYear())
        return true;
    else if (this -> year_ > date.getYear())
        return false;
    else if (this -> year_ == date.getYear()) {
        if (this -> month_ < date.getMonth())
            return true;
        else if (this -> month_ > date.getMonth())
            return false;
        else if (this -> month_ == date.getMonth()) {
            if (this -> day_ < date.getDay())
                return true;
            else if (this -> day_ > date.getDay())
                return false;
            else if (this -> day_ == date.getDay()) {
                if (this -> hour_ < date.getHour())
                    return true;
                else if (this -> hour_ > date.getHour())
                    return false;
                else if (this -> hour_ == date.getHour()) {
                    if (this -> minute_ < date.getMinute())
                        return true;
                    else if (this -> minute_>= date.getMinute())
                        return false;
                }
            }
        }
    }
    return 0;
}  //  end class Date < operator

//  return true if date is smaller or just equal
bool Date::operator>=(const Date& date) const {
    if (*this > date || *this == date)
        return true;
    else
        return false;
}  //  end class Date >= operator

//  return true if date is bigger or just equal else return false
bool Date::operator<=(const Date& date) const {
    if (*this < date || *this == date)
        return true;
    else
        return false;
}  //  end class Date <= operator

