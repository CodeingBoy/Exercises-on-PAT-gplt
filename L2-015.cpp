// L2-015 互评成绩
// Language: C++

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double calculate_average(vector<int>::iterator begin, vector<int>::iterator end){
    auto p = begin;
    double sum = 0;
    while(p != end){
        sum += *p;
        p++;
    }
    int count = end - begin;
    return sum / count;
}

int main(){
    int student_count, assess_count, query_count;
    cin >> student_count >> assess_count >> query_count;

    vector<int> scores[student_count];
    vector<double> average_scores;
    for(int i = 0;i < student_count;i++){
        vector<int> &s = scores[i];
        for(int j = 0;j < assess_count;j++){
            int score;
            cin >> score;
            s.push_back(score);
        }
        sort(s.begin(), s.end());
        double average = calculate_average(s.begin() + 1, s.end() - 1);
        average_scores.push_back(average);
    }
    sort(average_scores.begin(), average_scores.end());
    int pos = average_scores.size() - query_count;
    bool first = true;
    while(pos < average_scores.size()){
        if(!first){
            putchar(' ');
        }
        printf("%.3lf", average_scores[pos]);
        first = false;
        pos++;
    }


    return 0;
}
