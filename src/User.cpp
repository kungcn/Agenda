//  Agenda Stage 01 : User.cpp
//  definitions of class User and its methods

#include "User.h"

using std::string;

//  defalut constructor
User::User() {}

//  constructor with parameters
User::User(std::string userName, std::string userPassword,
       std::string userEmail, std::string userPhone)
    : name_(userName), password_(userPassword), email_(userEmail),
      phone_(userPhone) {}

//  return name_
std::string User::getName() const {
    return name_;
}  //  end User getName function

//  set name_
void User::setName(std::string name) {
    name_ = name;
}  //  end User setName function

//  return password_
std::string User::getPassword() const {
    return password_;
}  //  end User getPassword function

//  set password_
void User::setPassword(std::string password) {
    password_ = password;
}  //  end User setPassword function

//  return email_
std::string User::getEmail() const {
    return email_;
}  //  end User getEmail function

//  set email_
void User::setEmail(std::string email) {
    email_ = email;
}  //  end User setEmail function

//  return phone_
std::string User::getPhone() const {
    return phone_;
}  //  end User getPhone function

//  set phone_
void User::setPhone(std::string phone) {
    phone_ = phone;
}  //  end User setPhone function

