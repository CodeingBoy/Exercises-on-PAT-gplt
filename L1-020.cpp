// L1-020 帅到没朋友
// Language: C++ 11

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    int friend_circle_count;
    cin >> friend_circle_count;

    map<string, int> max_circle_friends;
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

    for(auto iter = circles.begin(); iter != circles.end(); ++iter){
        set<string> &circle = *iter;
        for(auto inner_iter = circle.begin(); inner_iter != circle.end();
                ++inner_iter){
            string cur_id = *inner_iter;
            if(!max_circle_friends.count(cur_id)
                    || (max_circle_friends[cur_id] < circle.size())){
                max_circle_friends[cur_id] = circle.size();
            }
        }
    }

    int query_count;
    cin >> query_count;

    vector<string> results;
    set<string> exists;
    while(query_count--){
        string query_id;
        cin >> query_id;

        bool has_friends = true;
        if(!max_circle_friends.count(query_id)
                || max_circle_friends[query_id] == 1){
            has_friends = false;
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
