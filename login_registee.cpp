#include "login.h"
#include <fstream>
#include <iostream>

void registerUser(const UserInfo& user)
{
    std::ofstream outFile("user_info.txt", std::ios::app);

    if (outFile.is_open())
    {
        outFile << user.username << " "
                << user.password << std::endl;

        outFile.close();
    }
}

bool authenticateUser(const std::string& enteredUsername,
                      const std::string& enteredPassword)
{
    std::ifstream inFile("user_info.txt");

    UserInfo user;

    while (inFile >> user.username >> user.password)
    {
        if (enteredUsername == user.username &&
            enteredPassword == user.password)
        {
            return true;
        }
    }

    return false;
}