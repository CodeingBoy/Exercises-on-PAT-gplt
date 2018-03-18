// L2-002 链表去重
// Language: C

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARR_SIZE (100000+5)
#define NUM_RANGE (10000+5)

struct tagNode{
    int address;
    int key;
    int next;
};
typedef struct tagNode Node;

bool duplicated[NUM_RANGE];
Node list[ARR_SIZE];
Node duplicated_list[ARR_SIZE];

int abs(int num){
    return num < 0 ? -num : num;
}

int comp(const void *a, const void *b){
    Node *na = (Node*)a, *nb = (Node*)nb;
    if(na->address == nb->address)return 0;
    return na->address < nb->address;
}

int main(){
    int head_address, node_count;
    scanf("%d %d", &head_address, &node_count);

    int duplicate_pos = 0;
    int last_list_address = head_address, last_duplicate_address = 0;
    while(node_count--){
        int address, key, next;
        scanf("%d %d %d", &address, &key, &next);
        int key_abs = abs(key);

        Node n;
        n.address = address;
        n.key = key;
        n.next = next;
        if(!duplicated[key_abs]){
            duplicated[key_abs] = true;
            list[address] = n;
        }else{
            duplicated_list[duplicate_pos] = n;
            duplicate_pos++;
        }
    }

    int cur_address = head_address;
    while(cur_address != -1){
        Node n = list[cur_address];
        printf("%5d %d %5d\n", n.address, n.key, n.next);
        cur_address = n.next;
    }

    qsort(duplicated, duplicate_pos - 1, sizeof(Node), comp);
    for(int i = 0; i < duplicate_pos - 2;i++){
        Node n = duplicated_list[i];
        Node next = duplicated_list[i+1];
        printf("%5d %d %5d\n", n.address, n.key, next.address);
    }
    Node n = duplicated_list[duplicate_pos - 1];
    printf("%5d %d -1\n", n.address, n.key);

    return 0;
}
