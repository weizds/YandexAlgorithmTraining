#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;
    int count = 0;
    int n = input.size();
    for(int i = 0; i < n/2; ++i){
        if(input[i] != input[n - i - 1])
            count++;
    }
    std::cout << count;
    return 0;
}