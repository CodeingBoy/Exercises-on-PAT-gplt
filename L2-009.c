// L2-009 抢红包
// Language: C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tagPlayer{
    int id;
    int balance_cent;
    int receive_count;
};
typedef struct tagPlayer Player;

int comp(const void *a, const void *b){
    Player *pa = (Player*)a, *pb = (Player*)b;
    if(pa->balance_cent == pb->balance_cent){
        if(pa->receive_count == pb->receive_count){
            return pa->id - pb->id;
        }
        return pb->receive_count - pa->receive_count;
    }
    return pb->balance_cent - pa->balance_cent;
}

int main(){
    int total_count;
    scanf("%d", &total_count);
    total_count++;
    Player players[total_count];

    memset(players, 0, sizeof(players));
    /* for(int i = 0;i < total_count;i++){ */
    /*     players[i].id = i; */
    /* } */

    for(int i = 1;i < total_count;i++){
        int sent_count;
        scanf("%d", &sent_count);

        int sent_amount = 0;
        while(sent_count--){
            int receiver_id, received_amount_cent;
            scanf("%d %d", &receiver_id, &received_amount_cent);

            players[receiver_id].id = receiver_id;
            players[receiver_id].balance_cent += received_amount_cent;
            players[receiver_id].receive_count++;

            sent_amount += received_amount_cent;
        }

        players[i].id = i;
        players[i].balance_cent -= sent_amount;
    }

    qsort(players, total_count, sizeof(Player), comp);

    for(int i = 0;i < total_count;i++){
        Player p = players[i];
        if(p.id == 0){
            continue;
        }
        printf("%d %.2lf\n", p.id, p.balance_cent / (double)100);
    }

    return 0;
}


