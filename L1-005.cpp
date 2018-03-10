// L1-005 考试座位号
// Language: C++ 11

#include <iostream>
#include <map>

using namespace std;

int main(){
    int row_count;
    cin >> row_count;

    map<string, string> dict;

    while(row_count--){
        string exam_id, test_pos, exam_pos;
        cin >> exam_id >> test_pos >> exam_pos;
        string value = exam_id + " " + exam_pos;
        dict[test_pos] = value;
    }

    int query_count;
    cin >> query_count;
    while(query_count--){
        string query_test_pos;
        cin >> query_test_pos;
        if(dict.count(query_test_pos)){
            cout << dict[query_test_pos] << endl;
        }
    }

    return 0;
}
