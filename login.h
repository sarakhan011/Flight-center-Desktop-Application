#ifndef LOGIN_H
#define LOGIN_H

#include <string>

struct UserInfo
{
    std::string username;
    std::string password;
};

void registerUser(const UserInfo& user);

bool authenticateUser(const std::string& enteredUsername,
                      const std::string& enteredPassword);

#endif