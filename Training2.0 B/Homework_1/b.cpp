#include <iostream>

using namespace std;

int count_stations(int max, int start, int end){
    int distance = abs(start - end);
    if(distance > max/2)
        return max - distance - 1;
    else
        return distance - 1;
}

int main()
{
    int start, end, max;
    cin >> max >> start >> end;
    cout << count_stations(max, start, end);
    return 0;
}