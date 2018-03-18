// L2-001 紧急救援
// Language: C++

#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_CITIES_COUNT (500+1)
#define MAX_ROAD_COUNT (500 * (500 - 1)) + 1

using namespace std;

struct Road{
    int start;
    int end;
    int weight;
};

vector<Road> roads[MAX_CITIES_COUNT];
/* Road roads[MAX_ROAD_COUNT]; */
int profits[MAX_CITIES_COUNT];
bool accessed[MAX_CITIES_COUNT] = {false};

int min_solution_count = 0;
int solution_weight = INT_MAX;
int solution_profit = INT_MIN;
vector<int> solution;

void dfs(int src, int dest, int city_count, int road_count,
        int current_weight, int current_profit,
        vector<int> current_solution){
    if(current_weight > solution_weight){
        return;
    }

    current_solution.push_back(src);
    current_profit += profits[src];

    if(src == dest){
        if(current_weight < solution_weight){
            min_solution_count = 1;
        }else if(current_weight == solution_weight){
            min_solution_count++;
        }

        if(current_weight < solution_weight
                || (current_weight == solution_weight && current_profit > solution_profit)){
            solution_profit = current_profit;
            solution_weight = current_weight;
            solution = current_solution;
        }

        /* current_solution.erase(current_solution.end() - 1); */
        return;
    }

    accessed[src] = true;
    /* for(int i = 0;i < road_count;i++){ */
    for(Road r : roads[src]){
        /* Road &r = roads[i]; */
        if(r.start != src && r.end != src){
            continue;
        }

        int start = r.start == src ? src : r.end;
        int end = r.start == src ? r.end : r.start;
        int weight = r.weight;
        if(!accessed[end]){
#ifdef DEBUG
            cout << "Searching " << start << " -> " << end;
            cout <<", current profit: " << current_profit << endl;
#endif
            dfs(end, dest, city_count, road_count, 
                    current_weight + weight, 
                    current_profit,
                    current_solution);
        }
    }
    accessed[src] = false;
    /* current_solution.erase(current_solution.end() - 1); */
}

int main(){
    int city_count, road_count, src_id, dest_id;
    scanf("%d %d %d %d", &city_count, &road_count
            , &src_id, &dest_id);
    /* cin >> city_count >> road_count >> src_id >> dest_id; */

    for(int i = 0;i < city_count;i++){
        int profit;
        scanf("%d", &profit);
        /* cin >> profit; */
        profits[i] = profit;
    }

    for(int i = 0;i < road_count;i++){
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        /* cin >> start >> end >> weight; */
        Road r;
        r.start = start;
        r.end = end;
        r.weight = weight;

        roads[start].push_back(r);
        roads[end].push_back(r);
    }

    vector<int> empty;
    dfs(src_id, dest_id, city_count, road_count, 0, 0, empty);

    if(min_solution_count == 0){
        solution_profit = 0;
    }

    /* cout << min_solution_count << " " << solution_profit << endl; */
    printf("%d %d\n", min_solution_count, solution_profit);

    bool first = true;
    for(auto i : solution){
        if(!first){
            /* cout << " "; */
            printf(" ");
        }
        /* cout << i; */
        printf("%d", i);
        first = false;
    }

    return 0;
}
