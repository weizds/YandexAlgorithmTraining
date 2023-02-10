#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <functional>

struct Message{
    std::string text;
    int topic_id;
};

struct Topic{
    std::string text;
    int message_count;
};

int main() {
    std::vector<Topic> topics;
    std::vector<Message> messages;
    std::string line;
    int n;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    iss >> n;
    for(int i = 1; i <= n; ++i){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        unsigned int parent_id;
        iss >> parent_id;
        if(parent_id == 0){
            std::getline(std::cin, line);
            topics.push_back({line, 1});
            std::getline(std::cin, line);
            messages.push_back({line, (int)((topics).size() - 1)});
        }else{
            std::getline(std::cin, line);
            int topic_id = messages[parent_id - 1].topic_id;
            messages.push_back({line, topic_id});
            ++topics[topic_id].message_count;
        }
    }
    int max_messages = 0;
    for(const auto &topic : topics){
        max_messages = std::max(max_messages, topic.message_count);
    }
    
    for(const auto &topic : topics){
        if(topic.message_count == max_messages){
            std::cout << topic.text;
            break;
        }
    }
    return 0;
}