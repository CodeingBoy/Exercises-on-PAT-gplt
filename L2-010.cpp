// L2-010 排座位
// Language: C++

#include <iostream>

using namespace std;

int get_ancestor(int arr[], int id){
    if(arr[id] == id){
        return id;
    }
    int inner_ancestor = get_ancestor(arr, arr[id]);
    arr[id] = inner_ancestor;
    return inner_ancestor;
}

void merge(int arr[], int id_a, int id_b){
    int ancestor_a = get_ancestor(arr, id_a),
        ancestor_b = get_ancestor(arr, id_b);

    arr[ancestor_b] = ancestor_a;
}

bool have_relationship(int arr[], int id_a, int id_b){
    return get_ancestor(arr, id_a) == get_ancestor(arr, id_b);
}

int main(){
    int people_count, relationship_count, query_count;
    cin >> people_count >> relationship_count >> query_count;

    int friendship[people_count+1];
    /* int enemy[people_count+1]; */
    bool enemy_bool[people_count+1][people_count+1] = {false};
    for(int i = 1;i <= people_count;i++){
        friendship[i] = i;
        /* enemy[i] = i; */
    }

    while(relationship_count--){
        int id_a, id_b, relationship;
        cin >> id_a >> id_b >> relationship;
        if(relationship == 1){
            merge(friendship, id_a, id_b);
        }else{
            /* merge(enemy, id_a, id_b); */
            enemy_bool[id_a][id_b] = true;
            enemy_bool[id_b][id_a] = true;
        }
    }

    while(query_count--){
        int id_a, id_b;
        cin >> id_a >> id_b;
        bool is_friend = have_relationship(friendship, id_a, id_b),
             /* is_enemy = have_relationship(enemy, id_a, id_b); */
             is_enemy = enemy_bool[id_a][id_b];

        if(is_friend && !is_enemy){
            cout << "No problem" << endl;
        }else if(!is_friend && !is_enemy){
            cout << "OK" << endl;
        }else if(is_friend && is_enemy){
            cout << "OK but..." << endl;
        }else{
            cout << "No way" << endl;
        }
    }

    return 0;
}
