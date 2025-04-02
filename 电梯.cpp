#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> K(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> K[i];
    }
    vector<int> dist(N + 1, INT_MAX);
    queue<int> q;
    dist[A] = 0;
    q.push(A);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        if (current == B)
        {
            break;
        }
        int up = current + K[current];
        if (up <= N && dist[up] > dist[current] + 1)
        {
            dist[up] = dist[current] + 1;
            q.push(up);
        }
        int down = current - K[current];
        if (down >= 1 && dist[down] > dist[current] + 1)
        {
            dist[down] = dist[current] + 1;
            q.push(down);
        }
    }
    if (dist[B] != INT_MAX)
    {
        cout << dist[B] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}