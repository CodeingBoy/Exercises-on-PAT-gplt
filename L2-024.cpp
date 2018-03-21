// L2-024 部落
// Language: C++

#include <iostream>

using namespace std;

#define SIZE (10000+5)

int ancestor[SIZE];

void print_ancestor(int len){
    for(int i = 1;i <= len;i++){
        cout << i << ": " << ancestor[i] << "\t";
    }
    cout << endl;
}

int get_ancestor(int id){
    if(ancestor[id] == id){
        return ancestor[id];
    }
    int inner_ancestor = get_ancestor(ancestor[id]);
    ancestor[id] = inner_ancestor;
    return inner_ancestor;
}

void merge(int id_a, int id_b){
    int ancestor_a = get_ancestor(id_a),
        ancestor_b = get_ancestor(id_b);

    ancestor[ancestor_b] = ancestor_a;
}

int main(){
    for(int i = 0;i < SIZE;i++){
        ancestor[i] = i;
    }

    int circle_count;
    cin >> circle_count;

    int max_id = 0;
    while(circle_count--){
        int member_count;
        cin >> member_count;

        int first_member = -1;

        while(member_count--){
            int id;
            cin >> id;
            if(first_member == -1){
                if(ancestor[id] != id){
                    first_member = ancestor[id];
                }else{
                    first_member = id;
                }
            }
            if(ancestor[id] != id){
#ifdef DEBUG
                cout << "Merge: " << first_member << " -> " << ancestor[id] << endl;
#endif
                merge(ancestor[id], first_member);
            }else{
                ancestor[id] = first_member;
            }

            if(id > max_id){
                max_id = id;
            }
        }
    }

#ifdef DEBUG
    cout << "Array: " << endl;
    print_ancestor(max_id);
#endif

    int unique_clrcle_count = 0;
    for(int i = 1;i <= max_id;i++){
        if(ancestor[i] == i){
            unique_clrcle_count++;
        }
    }
    cout << max_id << " " << unique_clrcle_count << endl;

    int query_count;
    cin >> query_count;
    while(query_count--){
        int id_a, id_b;
        cin >> id_a >> id_b;
        int ancestor_a = get_ancestor(id_a);
        int ancestor_b = get_ancestor(id_b);

        if(ancestor_a == ancestor_b){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
    }

    return 0;
}
