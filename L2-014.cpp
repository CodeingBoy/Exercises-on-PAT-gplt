// L2-014 列车调度
// Language: C++

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print_queues(vector<queue<int>> queues){
    for(queue<int> q : queues){
        queue<int> copy = q;
        while(!copy.empty()){
            cout << copy.front() << " ";
            copy.pop();
        }
        cout << endl;
    }
}

int pop_queue(vector<queue<int>> &queues, int start, int end){
    int last_success = -1;
    for(int i = start;i >= end;i--){
        bool found = false;
        for(queue<int> &q : queues){
            if(q.front() == i){
#ifdef DEBUG
                cout << "Poped " << i << endl;
#endif
                last_success = i;
                found = true;
                q.pop();
                break;
            }
        }
        if(!found){
            break;
        }
    }
    return last_success;
}

int main(){
    vector<queue<int>> queues;

    int train_count;
    cin >> train_count;
    int end = train_count;

    queue<int> in;
    while(train_count--){
        int num;
        cin >> num;
        in.push(num);
    }

    int next_out_train = end;
    while(!in.empty()){
        /* int result = pop_queue(queues, next_out_train, 1); */
/* #ifdef DEBUG */
        /* cout << "Param: "<< next_out_train << " result: " << result << endl; */
/* #endif */
        /* if(result != -1){ */
        /*     next_out_train = result - 1; */
/* #ifdef DEBUG */
        /*     print_queues(queues); */
        /*     cout << "---" << endl; */
/* #endif */
        /* } */

        bool inserted = false;
        int train_in = in.front();
        in.pop();

#ifdef DEBUG
        cout << "Inserting train " << train_in << endl;
#endif
        /* for(queue<int> &q : queues){ */
        /*     if(!q.empty()){ */
        /*         if(q.back() - train_in == 1){ */
        /*             q.push(train_in); */
        /*             inserted = true; */
        /*             break; */
        /*         } */
        /*     } */
        /* } */

        if(!inserted){
        for(queue<int> &q : queues){
            if(!q.empty()){
                if(train_in < q.back()){
                    q.push(train_in);
                    inserted = true;
                    break;
                }
            }
        }
        }


        if(!inserted){
            for(queue<int> &q : queues){
                if(q.empty()){
                    q.push(train_in);
                    inserted = true;
                    break;
                }
            }
        }

        if(!inserted){
            queue<int> new_queue;
            new_queue.push(train_in);
            queues.push_back(new_queue);
        }

#ifdef DEBUG
        print_queues(queues);
        cout << "---" << endl;
#endif

    }
    cout << queues.size() << endl;

    return 0;
}
