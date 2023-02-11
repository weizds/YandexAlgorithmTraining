#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <limits>

using namespace std;

struct Rectangle{
    double r_beg;
    double r_end;
    double angle_beg;
    double angle_end;
};

enum{
    BEGIN,
    END
};

std::ostream& operator<< (std::ostream& stream, const Rectangle& rectangle){
    stream << rectangle.r_beg << " " << rectangle.r_end << " "
    << rectangle.angle_beg << " " << rectangle.angle_end;
    return stream;
}

struct RectangleEvent {
    double angle;
    int state;
    int id;
};

bool compareRectanleEvents(const RectangleEvent &re1, const RectangleEvent &re2) {
    return re1.angle < re2.angle;
}

int main() {
    ifstream fin("input.txt");
    int n = 0;
    fin >> n;
    vector<pair<double, double>> rectangles_rad(n);
    vector<RectangleEvent> rectangles_angle(n*2);
    for(int i = 0; i < n; ++i){
        double r_beg, r_end, angle_beg, angle_end;
        fin >> r_beg >> r_end >> angle_beg >> angle_end;
        rectangles_rad[i] = {r_beg, r_end};
        rectangles_angle[i*2] = {angle_beg, BEGIN, i};
        rectangles_angle[i*2 + 1] = {angle_end, END, i};
    }
    fin.close();
    
    double r_start_max = rectangles_rad[0].first;
    double r_end_min = rectangles_rad[0].second;
    for(int i = 1; i < n; ++i){
        r_start_max = max(r_start_max, rectangles_rad[i].first);
        r_end_min = min(r_end_min, rectangles_rad[i].second);
    }
    if(r_end_min < r_start_max)
        cout << "0.0";
    
    set<int> started_rects;
    int count_started = 0;
    sort(rectangles_angle.begin(), rectangles_angle.end(), compareRectanleEvents);
    for(int i = 0; i < n*2; ++i){
        if(rectangles_angle[i].state == BEGIN){
            ++count_started;
            started_rects.insert(rectangles_angle[i].id);
        }else if(rectangles_angle[i].state == END && started_rects.find(rectangles_angle[i].id) != started_rects.end()){
            --count_started;
            started_rects.erase(rectangles_angle[i].id);
        }
    }
    double angle_sum_start = 0;
    double angle_sum = 0;
    for(int i = 0; i < n*2; ++i){
        if(rectangles_angle[i].state == BEGIN){
            ++count_started;
            if(count_started == n){
                angle_sum_start = rectangles_angle[i].angle;
            }
        }else if(rectangles_angle[i].state == END){
            if(count_started == n)
                angle_sum += rectangles_angle[i].angle - angle_sum_start;
            --count_started;
        }
    }
	if(count_started == n)
    	angle_sum += M_PI * 2 - angle_sum_start;
    cout.precision(10);
    cout << fixed << angle_sum / 2 * (r_end_min * r_end_min - r_start_max * r_start_max) << "\n";
    return 0;
}