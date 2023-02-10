#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

bool compare(const std::pair<std::string, int> &p1, const std::pair<std::string, int> &p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second > p2.second;
}

int main() {
    std::map<std::string, int> word_count;
    std::string word;
    while(std::cin >> word){
        if(word == "end")
            break;
        ++word_count[word];
    }
    std::vector<std::pair<std::string, int>> sorted_words(word_count.begin(), word_count.end());
    std::sort(sorted_words.begin(), sorted_words.end(), compare);
    for(auto it = sorted_words.begin(); it != sorted_words.end(); ++it)
        std::cout << it->first << "\n";
    return 0;
}