// L2-019 悄悄关注
// Language: C++

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int follow_count;
    cin >> follow_count;

    set<string> following_users;
    while(follow_count--){
        string user_id;
        cin >> user_id;
        following_users.insert(user_id);
    }

    int like_count;
    cin >> like_count;

    map<string, int> like_users;
    int total_like_count = 0;
    while(like_count--){
        string user_id;
        int like_times;
        cin >> user_id >> like_times;
        like_users[user_id] = like_times;
        total_like_count += like_times;
    }
    double average_like_times = (double)total_like_count / like_users.size();

    vector<string> results;
    for(auto pair : like_users){
        string user_id = pair.first;
        int like_times = pair.second;
        if(like_times >= average_like_times
                && !following_users.count(user_id)){
            results.push_back(user_id);
        }
    }

    if(results.empty()){
        cout << "Bing Mei You" << endl;
    }else{
        sort(results.begin(), results.end());
        for(string id : results){
            cout << id << endl;
        }
    }

    return 0;
}
