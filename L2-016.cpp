// L2-016 愿天下有情人都是失散多年的兄妹
// Language: C++

#include <iostream>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

struct Person{
    int id;
    bool male;
    int father_id = -1, mother_id = -1;
    int mark = -1;
};
typedef struct Person Person;

map<int, Person> persons;

bool dfs(int id, int mark_id, int compare_id, int stage){
    if(stage >= 5){
        return true;
    }
    if(id == -1){
        return true;
    }
    if(!persons.count(id)){
        Person p;
        p.id = id;
        persons[id] = p;
    }

    Person &p = persons[id];
#ifdef DEBUG
    cout << "Accessing " << id << ", mark: " << p.mark << endl;
#endif
    if(p.mark == compare_id){
#ifdef DEBUG
        cout << "Found compare_id on " << id << endl;
#endif
        return false;
    }
    if(mark_id != -1){
        p.mark = mark_id;
    }
    bool result = true;
    result = dfs(p.father_id, mark_id, compare_id, stage + 1);
#ifdef DEBUG
    cout << "Father of " << p.id << ": " << result << endl;
#endif
    if(result){
        result = dfs(p.mother_id, mark_id, compare_id, stage + 1);
#ifdef DEBUG
    cout << "Mother of " << p.id << ": " << result << endl;
#endif
    }
    return result;
}

void can_pair(int id_a, int id_b){
    static int mark_id = 0;

    Person &a = persons[id_a], &b = persons[id_b];
    if(a.male == b.male){
        cout << "Never Mind" << endl;
        return;
    }

    mark_id++;
    bool result = dfs(id_a, mark_id, -3, 0);
    /* assert(result); */
    result = dfs(id_b, -1, mark_id, 0);
    if(result){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main(){
    int person_count;
    cin >> person_count;

    while(person_count--){
        int id, father_id, mother_id;
        string gender;
        cin >> id >> gender >> father_id >> mother_id;
        Person p;
        p.id = id;
        p.father_id = father_id;
        p.mother_id = mother_id;
        if(gender[0] == 'M'){
            p.male = true; 
        }else{
            p.male = false; 
        }
        persons[id] = p;
    }

    int query_count;
    cin >> query_count;
    while(query_count--){
        int id_a, id_b;
        cin >> id_a >> id_b;
        can_pair(id_a, id_b);
    }

    return 0;
}
