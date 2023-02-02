#include <iostream>

int is_unambiguous(int day, int month, int year){
    if(day <= 12 && month <= 12 && day != month)
        return 0;
    return 1;
}

int main()
{
    int day, month, year;
    std::cin >> day >> month >> year;
    std::cout << is_unambiguous(day, month, year);
    return 0;
}