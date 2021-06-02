#include <vector>
#include "iostream"
#include <ctime> 
using namespace std;

int Dijkstra(int n, int st, vector<vector<int>> w){

    vector<bool> visited;
    visited.resize(n);
    vector<int> D;
    int count = 0;
    D.resize(n);
    for(int i = 0;i < n;i++){
        D[i] = w[st][i];
        visited[i] = false;
        //count += 1;
    }

    D[st] = 0;
    int index = 0,u = 0;
    for (int i = 0;i < n;i++){
        int min = INT_MAX;
        for (int j = 0;j < n;j++){
            if (!visited[j] && D[j] < min){
                min = D[j];
                index = j;
                //count += 1;
            }
        }

        u = index;
        visited[u] = true;
        for(int j = 0;j < n;j++){
            if (!visited[j] && w[u][j] != INT_MAX && D[u] != INT_MAX && (D[u] + w[u][j] < D[j])){
                D[j] = D[u] + w[u][j];
                //count += 1;
            }
            //count += 1;
        }
    }
    return count;
}

vector<vector<int>> generate_w(vector<vector<int>> w, int n)
{

    int MAX_BLT = 228337;
    int per;
    for (int i = 0; i < n; i++)
    {
        for (int j =0; j< n; j++)
        {
            
            if (i == j)
            {
                w[i][j] = 0;
            }
            else 
            {
                per = rand() % 3 + 1;
                if (per == 1)
                {
                   w[i][j] = MAX_BLT;
                }
                else
                {
                    w[i][j] = rand() % 20 + 2;
                }
            }
            
        }
        //cout << " " << endl;
    }
    return w;
}

int main(){
    int n, start;
    start = 1;
    
    for (int i = 200; i < 20000; i+=200)
    {
        n = i;
        vector<vector<int>> w;
        w.resize(n);
        for (int i = 0;i < n;i++)
            w[i].resize(n);

        w = generate_w(w,n);
        float start_time =  clock();
        int D = Dijkstra(n , start, w);
        float end_time =  clock();
        cout << end_time - start_time << endl;
    }
    
    /**
    for (int i = 0; i < n; i++){
        if (D[i] != INT_MAX)
            cout << start << " -> " << i << " = " << D[i] << endl;
        else
            cout << start << " -> " << i << " = " << "маршрут недоступен" << endl;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            cout << w[i][j] << "  ";
        }
        cout << endl;
    }
    **/
    
    return 0;
}