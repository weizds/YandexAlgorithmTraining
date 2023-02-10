#include <iostream>

int main() {
    int folder_count = 0;
    std::cin >> folder_count;
    int max = 0;
    int sum = 0;
    for(int i = 0; i < folder_count; ++i){
        int current_folder;
        std::cin >> current_folder;
        sum += current_folder;
        if(current_folder > max){
            sum += max;
            max = current_folder;
            sum -= max;
        }
    }

    std::cout << sum;
    return 0;
}