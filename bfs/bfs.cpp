#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;



    map<int , vector<int> > adjListINT;



    void addEdgeINT(int u, int v) {
        adjListINT[u].push_back(v);
    }




    void bfs(int src, int target[], int visited) {

        queue<int> q;
        map<int, int> dist;


        for (auto i: adjListINT) {
            dist[i.first] = -1;
        }

        q.push(src);
        dist[src] = 0;
        int countMAX = 0;


        while (!q.empty()) {

            int node = q.front();

            q.pop();

            // For the neigbours of the current node, find out the nodes which are not visited
            for (int neigbour: adjListINT[node]) {


                if (dist[neigbour] == -1) {
                    q.push(neigbour);
                    dist[neigbour] = dist[node] + 1;

                    for(int j = 0; j < visited; j++) {


                            if (neigbour == target[j]) {
                                if(countMAX < dist[neigbour]){
                                    countMAX = dist[neigbour];
                                }
                            }


                    }



                }


            }


        }


        cout << countMAX;


    }





int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    string startString;
    int start;

    int NUMvillages;
    cin >> NUMvillages;
    int visited;
    cin >> visited;

    string target;
    int targetInt[visited];



    string villages;
    string neighbours;

    map <string ,int> villagesINT;

    for (int i = 0; i < NUMvillages; i++) {
        cin >> villages;
        villagesINT[villages] = i;

    }


    int Xcounter = 0;
    int j = 0;


    while (cin >> neighbours) {
        if (neighbours == "X") {
            Xcounter++;
            j++;


            if (Xcounter == NUMvillages) {
                break;
            }
        }

        if (neighbours != "X") {
            addEdgeINT(j, villagesINT[neighbours]);

        }
    }

    cin >> startString;

    start = villagesINT[startString];



    for(int i = 0; i < visited; i++){
        cin >> target;
        targetInt[i] = villagesINT[target];
    }

    bfs(start,targetInt,visited);




    return 0;
}