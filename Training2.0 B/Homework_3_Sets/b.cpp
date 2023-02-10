#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<int> set;
    int num;
    while(std::cin >> num) {    
        if(set.find(num) != set.end()){
            std::cout << "YES\n";
        }else{
            set.insert(num);
            std::cout << "NO\n";
        }
    }
    return 0;
}