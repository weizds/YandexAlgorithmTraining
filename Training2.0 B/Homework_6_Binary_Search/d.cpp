#include <iostream>
#include <cstdint>
#include <fstream>

using namespace std;

uint64_t get_value(uint64_t days, uint64_t a, uint64_t k, uint64_t b, uint64_t m){
    return (days - days/k) * a + (days - days/m) * b;
}

bool check(uint64_t days, uint64_t a, uint64_t k, uint64_t b, uint64_t m, uint64_t x) {
    return get_value(days, a, k, b, m) < x;
}

uint64_t binary_search(uint64_t l, uint64_t r, uint64_t a, uint64_t k, uint64_t b, uint64_t m, uint64_t x) {
    while(l < r){
        uint64_t med = (r + l) / 2;
        if(check(med, a, k, b, m, x))
            l = med + 1;
        else
            r = med;
    }
    return l;
}

int main() {
    uint64_t a, k, b, m, x;
    ifstream fin("input.txt");
    fin >> a >> k >> b >> m >> x;
    fin.close();
    
	uint64_t right = x * 2 / a + 1;
    auto days = binary_search(0, right, a, k, b, m, x);
    cout << days;
    return 0;
}