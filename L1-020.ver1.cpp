// L1-020 帅到没朋友
// Language: C++ 11

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int friend_circle_count;
    cin >> friend_circle_count;

    vector<set<string>> circles;
    while(friend_circle_count--){
        int friend_count;
        cin >> friend_count;

        set<string> circle;
        while(friend_count--){
            string id;
            cin >> id;
            circle.insert(id);
        }
        circles.push_back(circle);
    }

    int query_count;
    cin >> query_count;

    vector<string> results;
    set<string> exists;
    while(query_count--){
        string query_id;
        cin >> query_id;

        bool has_friends = false;
        for(auto iter = circles.begin(); iter != circles.end(); ++iter){
            set<string> &circle = *iter;
#ifdef DEBUG
            cout << query_id << ": " <<circle.count(query_id) << endl;
#endif
            if(circle.count(query_id) && circle.size() > 1){
                has_friends = true;
                break;
            }
        }

        if(!has_friends && !exists.count(query_id)){
            exists.insert(query_id);
            results.push_back(query_id);
        }
    }

    if(results.empty()){
        cout << "No one is handsome";
    }else{
        for(int i = 0;i < results.size();i++){
            if(i != 0){
                cout << " ";
            }
            cout << results[i];
        }
    }

    return 0;
}
