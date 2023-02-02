#include <iostream>
#include <vector>

int meda(int day, int month, int year){
    if(day <= 12 && month <= 12)
        return 0;
    return 1;
}

int main()
{
    int n;
    std::vector<int> houses;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        std::cin >> tmp;
        houses.push_back(tmp);
    }
    std::cout << houses[n/2];
    return 0;
}