#include "PostManager.h"
#include <fstream>
#include <iostream>

void PostManager::loadPostsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    Post post;
    while (std::getline(file, post.content) && std::getline(file, post.username)) {
        posts.push_back(post);
    }
    file.close();
}

void PostManager::createPost(const std::string& content, const std::string& username) {
    posts.push_back({content, username});
}

void PostManager::viewPosts() const {
    for (const auto& post : posts) {
        std::cout << post.username << ": " << post.content << '\n';
    }
}

void PostManager::savePostsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto& post : posts) {
        file << post.content << '\n' << post.username << '\n';
    }
    file.close();
}
