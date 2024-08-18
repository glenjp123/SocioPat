#ifndef POSTMANAGER_H
#define POSTMANAGER_H

#include <string>
#include <vector>

class PostManager {
public:
    void loadPostsFromFile(const std::string& filename);
    void createPost(const std::string& content, const std::string& username);
    void viewPosts() const;
    void savePostsToFile(const std::string& filename) const;

private:
    struct Post {
        std::string content;
        std::string username;
    };

    std::vector<Post> posts;
};

#endif // POSTMANAGER_H
