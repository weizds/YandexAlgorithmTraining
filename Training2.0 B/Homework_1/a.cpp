#include <iostream>

int total(int exit_code, int interactor, int checker){
    switch(interactor){
        case 0:
            return exit_code == 0 ? checker : 3;
        case 1:
            return checker;
        case 4:
            return exit_code == 0 ? 4 : 3;
        case 6:
            return 0;
        case 7:
            return 1;
    }
    return interactor;
}

int main()
{
    int exit_code, interactor, checker;
    std::cin >> exit_code >> interactor >> checker;
    std::cout << total(exit_code, interactor, checker);
    return 0;
}