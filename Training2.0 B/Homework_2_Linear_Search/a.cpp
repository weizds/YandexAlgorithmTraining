#include <iostream>
#include <algorithm>

int main()
{
    int max_count = 1;
    int max = 0;
    int current_num;
    while(std::cin >> current_num){
        if(current_num == 0)
            break;
        if(current_num > max){
            max = current_num;
            max_count = 1;
        }else if(current_num == max){
            max_count++;
        }
    }
    std::cout << max_count;
    return 0;
}