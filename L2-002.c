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
    bool duplicate;
};
typedef struct tagNode Node;

bool duplicated[NUM_RANGE] = {false};
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

    for(int i = 0;i < ARR_SIZE;i++){
        list[i].address = -1;
        list[i].next = -1;
    }

    while(node_count--){
        int address, key, next;
        scanf("%d %d %d", &address, &key, &next);
        int key_abs = abs(key);

        Node n;
        n.address = address;
        n.key = key;
        n.next = next;
        n.duplicate = duplicated[key_abs];
        duplicated[key_abs] = true;
        list[address] = n;
    }

#ifdef DEBUG
    printf("Output:\n");
#endif

    int cur_address = head_address;
    bool first = true;
    while(cur_address != -1){
        Node n = list[cur_address];
        if(n.address == -1){
            break;
        }
        if(!n.duplicate){
            if(!first){
                printf("%05d\n", n.address);
            }
            printf("%05d %d ", n.address, n.key);
            first = false;
        }
        if(n.address == n.next){
            break;
        }
        cur_address = n.next;
    }
    if(!first){
        printf("-1\n");
    }

    cur_address = head_address;
    first = true;
    while(cur_address != -1){
        Node n = list[cur_address];
        if(n.duplicate){
            if(!first){
                printf("%05d\n", n.address);
            }
            printf("%05d %d ", n.address, n.key);
            first = false;
        }
        if(n.address == n.next){
            break;
        }
        cur_address = n.next;
    }
    if(!first){
        printf("-1\n");
    }

    return 0;
}
