#include <iostream>
#include "UserManager.h"
#include "PostManager.h"
#include "Display.h"

using namespace std;

int main() {
    UserManager userManager;
    PostManager postManager;
    Display display;

    // Load data from files
    userManager.loadUsersFromFile("data/users.txt");
    postManager.loadPostsFromFile("data/posts.txt");

    UserManager::User* loggedInUser = nullptr;

    string command;
    while (true) {
        display.col_yellow("Welcome to SocioPat!\n");
        display.col_yellow("SocioPat is a CLI-Based social media Application.\n");
        if (loggedInUser) {
            display.col_green("Hello " + loggedInUser->username + "!\n");
        }
        cout << "Enter command (register, login, post, view, logout, exit): ";
        getline(cin, command);

        if (command == "register" && (loggedInUser == nullptr)) {
            string username, password;
            cout << "Username: ";
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);
            if (userManager.loginUser(username, password) != nullptr) {
                display.col_red("Username already exists. Please login instead.\n");
            } else {
                userManager.registerUser(username, password);
                display.col_green("User registered successfully!\n");
            }
        } else if (command == "login") {
            string username, password;
            cout << "Username: ";
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);
            loggedInUser = userManager.loginUser(username, password);
            if (loggedInUser) {
                display.col_green("Login successful!\n");
            } else {
                display.col_red("Login failed! Check your username and/or password.\n");
            }
        } else if (command == "post" && loggedInUser) {
            string content;
            cout << "Enter your post: ";
            getline(cin, content);
            postManager.createPost(content, loggedInUser->username);
        } else if (command == "view") {
            postManager.viewPosts();
        } else if (command == "logout" && loggedInUser) {
            loggedInUser = nullptr;
            display.col_green("Logged out successfully!\n");
        } else if (command == "exit") {
            // Save data to files before exiting
            userManager.saveUsersToFile("data/users.txt");
            postManager.savePostsToFile("data/posts.txt");
            break;
        } else {
            display.col_red("Invalid command or not logged in!\n");
        }
    }

    return 0;
}
