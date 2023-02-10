#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    std::vector<int> vec;
    int num;
    while(std::cin >> num)   
        vec.push_back(num);
    std::unordered_map<int, int> hash_map;
    for(int a : vec)
        ++hash_map[a];
    for(int a : vec)
        if(hash_map[a] == 1)
            std::cout << a << " ";
    return 0;
}