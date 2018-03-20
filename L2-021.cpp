// L2-021 点赞狂魔
// Language: C++

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct tagUser{
    int unique_tag_count = 0;
    string name;
    set<int> like_tags;
    int like_count = 0;

    double get_average_like_count(){
        if(unique_tag_count == 0){
            return 0;
        }
        return (double)like_count / unique_tag_count;
    }
};
typedef struct tagUser User;

struct Compator{
    bool operator() (User u1, User u2){
        if(u1.unique_tag_count == u2.unique_tag_count){
            return u1.get_average_like_count() < u2.get_average_like_count();
        }
        return u1.unique_tag_count > u2.unique_tag_count;
    }
} compator;

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    int user_count;
    cin >> user_count;

    User users[user_count];
    for(int i = 0;i < user_count;i++){
        User &u = users[i];
        string name;
        cin >> name;
        u.name = name;

        int tags_count;
        cin >> tags_count;
        while(tags_count--){
            int tag_id;
            cin >> tag_id;
            if(!u.like_tags.count(tag_id)){
                u.like_tags.insert(tag_id);
                u.unique_tag_count++;
            }
            u.like_count++;
        }
    }

    sort(users, users + user_count, compator);

    bool first = true;
    for(int i = 0;i < min(3, user_count);i++){
        if(!first){
            cout << " ";
        }
        cout << users[i].name;
        first = false;
    }
    for(int i = 0;i < 3 - user_count;i++){
        if(!first){
            cout << " ";
        }
        cout << "-";
        first = false;
    }

    return 0;
}
