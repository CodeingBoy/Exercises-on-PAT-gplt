// L1-034 点赞
// Language: C++ 11

#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, int> tag_freq;

    int row_count;
    cin >> row_count;

    int max_tag_id = 0, max_tag_freq = 0;
    while(row_count--){
        int tag_count;
        cin >> tag_count;

        while(tag_count--){
            int tag_id;
            cin >> tag_id;

            if(!tag_freq.count(tag_id)){
                tag_freq[tag_id] = 0;
            }
            tag_freq[tag_id]++;

            if(tag_freq[tag_id] > max_tag_freq
                    || (tag_freq[tag_id] == max_tag_freq
                        && tag_id > max_tag_id)){
                max_tag_id = tag_id;
                max_tag_freq = tag_freq[tag_id];
            }
        }
    }
    cout << max_tag_id << " " << max_tag_freq;

    return 0;
}
