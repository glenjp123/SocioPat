#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <vector>

class UserManager {
public:
    struct User {
        std::string username;
        std::string password;
    };

    void loadUsersFromFile(const std::string& filename);
    void registerUser(const std::string& username, const std::string& password);
    User* loginUser(const std::string& username, const std::string& password);
    void saveUsersToFile(const std::string& filename);

private:
    std::vector<User> users;
};

#endif // USERMANAGER_H
