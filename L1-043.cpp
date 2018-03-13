// L1-043 阅览室
// Language: C++ 11

#include <iostream>
#include <map>
#include <sstream>
#include <cstdio>
#include <cmath>

using namespace std;

int calculate_time_difference(int h1, int m1, int h2, int m2){
    if(m2 < m1){
        h2--;
        m2 += 60;
    }
    return (h2 - h1) * 60 + (m2 - m1);
}

int calculate_lend_minutes(string start, string end){
    stringstream ss1;
    ss1 << start;
    int h1, m1;
    char whatever;
    ss1 >> h1 >> whatever >> m1;

    stringstream ss2;
    ss2 << end;
    int h2, m2;
    ss2 >> h2 >> whatever >> m2;

#ifdef DEBUG
    cout << h1 << ":" << m1 << " ~ " << h2 << ":" << m2 << endl;
#endif
    return calculate_time_difference(h1, m1, h2, m2);
}

void eatline(){
    while(getchar() != '\n')
        ;
}

int main(){
    int day_count;
    cin >> day_count;

    while(day_count--){
        int lend_count = 0, total_time = 0;
        map<int, string> lending_info;

        while(true){
            int book_id;
            char event;
            string time;

            cin >> book_id >> event >> time;
            if(book_id == 0){
                /* eatline(); */
                break;
            }
            if(event == 'S'){
                lending_info[book_id] = time;
            }else{
                if(!lending_info.count(book_id)){
                    continue;
                }
                lend_count++;
                total_time += calculate_lend_minutes(lending_info[book_id],
                        time);
#ifdef DEBUG
                cout << total_time << endl;
#endif
                lending_info.erase(book_id);
            }
        }

        int average_time = 0;
        if(total_time > 0){
            average_time = (int)round((double)total_time / lend_count);
        }
        cout << lend_count << " " << average_time << endl;

    }
    return 0;
}
