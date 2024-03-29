#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int cnt = 0;

bool bfs(int adjmat[][10], int n, int e, int source, int destination)
{
    int visited[n];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    queue<int> q;
    q.push(source);
    int c = 0;
    // visited[source]=1;
    while (!q.empty())
    {
        int h = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (adjmat[h][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
        cout << h << " ";
        if (c != 0)
            if (h == destination)
                return true;
        c++;
    }
    return false;
}

int main()
{
    int adjmat[10][10], n, e;
    cnt = 0;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter the verticies from 1 " << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adjmat[i][j] = 0;

    int s, d;
    for (int i = 1; i <= e; i++)
    {
        cout << "Enter the source: ";
        cin >> s;
        cout << "Enter the destination: ";
        cin >> d;
        adjmat[s][d] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (bfs(adjmat, n, e, i, i))
            cout << "Yes, a cycle exists for: " << i << endl;
    }
}