#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>
#include <algorithm>

struct Party{
  std::string name;
  long long votes;
  double places_won;
  double fraction;
};

bool compare_by_fraction(Party *party1, Party *party2){
    if(std::fabs(party1->fraction - party2->fraction) <= std::numeric_limits<double>::epsilon())
        return party1->votes > party2->votes;
    else
        return party1->fraction > party2->fraction;
}

int main() {
    std::string line;
    std::vector<Party> parties;
    int votes_sum = 0;
    
    while(std::getline(std::cin, line)){
        if(line == "")
            break;
        std::istringstream iss(line);
        std::vector<std::string> line_split;
        std::string word;
        while(std::getline(iss, word, ' ')){
            line_split.push_back(word);
        }
        std::string name;
        int size =  line_split.size();
        for(int i = 0; i < size - 1; ++i){
            name.append(line_split[i]);
            if(i < size - 2)
                name.append(" ");
        }
        int votes = std::stoi(line_split[size - 1]);
        parties.push_back({name, votes, 0, 0});
        votes_sum += votes;
    }
    double one_place_votes = votes_sum / 450.;
    int places_sum = 0;
    for(auto &party : parties){
        party.places_won = std::floor(party.votes / one_place_votes);
        party.fraction = party.votes - party.places_won * one_place_votes;
        places_sum += party.places_won;
    }
    if(places_sum < 450){
        std::vector<Party *> parties_sorted;
        for(int i = 0; i < parties.size(); ++i)
            parties_sorted.push_back(&parties[i]);
        std::sort(parties_sorted.begin(), parties_sorted.end(), compare_by_fraction);
        for(int i = 0; places_sum < 450; ++i){
            parties_sorted[i]->places_won++;
            places_sum++;
        }
    }
    for(const auto &party : parties)
        std::cout << party.name << " " << party.places_won << "\n";
    return 0;
}