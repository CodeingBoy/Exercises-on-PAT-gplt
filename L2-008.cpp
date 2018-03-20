// L2-008 最长对称子串
// Language: C++

#include <iostream>

using namespace std;

bool is_mirrored_string(string input, int start, int end){
#ifdef DEBUG
    cout << "Start: " << start << " End: " << end << endl;
    cout << input.substr(start, end) << endl;
#endif
    int count = end - start;
    for(int i = 0;i < count / 2;i++){
        char l = input[start + i];
        char r = input[end - 1 - i];
        if(l != r){
            return false;
        }
    }
    return true;
}

int main(){
    string input;
    getline(cin, input);

    int input_len = input.size();
    for(int len = input.size(); len > 0;len--){
        for(int start = 0;start <= input_len - len;start++){
            if(is_mirrored_string(input, start, start + len)){
                cout << len;
                return 0;
            }
        }
    }

    return 0;
}
