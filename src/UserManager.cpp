#include "UserManager.h"
#include <fstream>
#include <iostream>

void UserManager::loadUsersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    User user;
    while (file >> user.username >> user.password) {
        users.push_back(user);
    }
    file.close();
}

void UserManager::registerUser(const std::string& username, const std::string& password) {
    users.push_back({username, password});
}

UserManager::User* UserManager::loginUser(const std::string& username, const std::string& password) {
    for (auto& user : users) {
        if (user.username == username && user.password == password) {
            return &user;
        }
    }
    return nullptr;
}

void UserManager::saveUsersToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto& user : users) {
        file << user.username << ' ' << user.password << '\n';
    }
    file.close();
}
