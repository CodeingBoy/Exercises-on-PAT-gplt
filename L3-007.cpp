// L3-007 天梯地图
// Language: C++

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int least_time = INT_MAX, shortest = INT_MAX;
int least_time_length = INT_MAX;
vector<int> least_time_solution, shortest_solution;

void dfs(int **roads, int **times, int location_count,
        int src, int dest,
        int current_time, int current_len, 
        vector<int> current_locations){
    if(current_len > shortest && current_time > least_time){
        return;
    }

    for(int i : current_locations){
        if(i == src){
            return;
        }
    }

    current_locations.push_back(src);

#ifdef DEBUG
    cout << src << " => " << dest << endl;
#endif


    if(src == dest){
        if(current_time < least_time
                || (current_time == least_time 
                    && current_len < least_time_length)){
            least_time = current_time;
            least_time_length = current_len;
            least_time_solution = current_locations;
        }

        if(current_len < shortest
                || (current_len == shortest
                    && current_locations.size() < shortest_solution.size())){
            shortest = current_len;
            shortest_solution = current_locations;
        }
        return;
    }


    int *current_src_roads = roads[src];
    int *current_src_times = times[src];
    for(int i = 0;i < location_count;i++){
        int road_len = current_src_roads[i];
        int road_time = current_src_times[i];
        if(road_len == 0){
            continue;
        }
        int road_dest = i;
#ifdef DEBUG
        cout << "Found road: " << src << " -> " << road_dest << endl;
#endif
        dfs(roads, times, location_count, road_dest, dest,
                current_time + road_time, current_len + road_len,
                current_locations);
    }

}

int main(){
    int location_count, road_count;
    cin >> location_count >> road_count;

    /* int roads[location_count][location_count] = {0}; */
    /* int times[location_count][location_count] = {0}; */
    int **roads = new int*[location_count];
    int **times = new int*[location_count];
    for(int i = 0;i < location_count;i++){
        roads[i] = new int[location_count];
        times[i] = new int[location_count];
        memset(roads[i], 0, sizeof(int) * location_count);
        memset(times[i], 0, sizeof(int) * location_count);
    }

    for(int i = 0;i < road_count;i++){
        int location_a, location_b, one_way, road_length, time;
        cin >> location_a >> location_b >> one_way >> road_length >> time;

        // one_way == 1: v1 -> v2
#ifdef DEBUG
        cout << location_a << " -> " << location_b << endl;
#endif

        roads[location_a][location_b] = road_length;
        times[location_a][location_b] = time;
        if(one_way == 0){
            roads[location_b][location_a] = road_length;
            times[location_b][location_a] = time;
        }

    }

    int src, dest;
    cin >> src >> dest;

    vector<int> empty;
    dfs(roads, times, location_count, src, dest, 0, 0, empty);

    if(least_time_solution == shortest_solution){
        bool first = true;
        cout << "Time = " << least_time << "; Distance = " << shortest << ": ";
        for(int i : shortest_solution){
            if(!first){
                cout << " => ";
            }
            cout << i;
            first = false;
        }
        cout << endl;
    }else{
        bool first = true;
        cout << "Time = " << least_time << ": ";
        for(int i : least_time_solution){
            if(!first){
                cout << " => ";
            }
            cout << i;
            first = false;
        }
        cout << endl;

        first = true;
        cout << "Distance = " << shortest << ": ";
        for(int i : shortest_solution){
            if(!first){
                cout << " => ";
            }
            cout << i;
            first = false;
        }
        cout << endl;
    }


    return 0;
}

