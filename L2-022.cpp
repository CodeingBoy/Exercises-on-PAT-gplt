// L2-022 重排链表
// Language: C++

#include <iostream>
#include <map>

using namespace std;

struct tagNode{
    int address;
    int data;
    int next;
};
typedef struct tagNode Node;

int main(){
    int head_address, node_count;
    cin >> head_address >> node_count;

    map<int, Node> nodes;
    for(int i = 0; i < node_count;i++){
        int address, data, next;
        cin >> address >> data >> next;
        Node n;
        n.address = address;
        n.data = data;
        n.next = next;
        nodes[address] = n;
    }

    Node nodes_array[node_count];
    int pos = 0;
    int current_address = head_address;
    while(current_address != -1){
        nodes_array[pos] = nodes[current_address];
#ifdef DEBUG
        cout << pos << ": " << current_address << endl;
#endif
        current_address = nodes[current_address].next;
        pos++;
    }

    bool first = true;
    int left = 0, right = node_count - 1;
    while(left <= right){
        Node &l = nodes_array[left], &r = nodes_array[right];
        if(left <= right){
            char buffer[100];
            if(first){
                sprintf(buffer, "%05d %d", r.address, r.data);
            }else{
                sprintf(buffer, " %05d\n%05d %d", r.address, r.address, r.data);
            }
            cout << buffer;

            first = false;
            right--;
        }

        if(left <= right){
            char buffer[100];
            sprintf(buffer, " %05d\n%05d %d", l.address, l.address, l.data);
            cout << buffer;

            first = false;
            left++;
        }
    }
    cout << " " << -1 << endl;

    return 0;
}
