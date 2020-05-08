#include "Dijkstra.h"

Dijkstra::Dijkstra(size_t n, size_t e) : N(n), E(e), startPoint(0), endPoint(1)
{
	dist.resize(N + 1);
	for (auto& i : dist)
		i = INT_MAX;

	graph = new vector<edge>[N + 1];
}
void Dijkstra::AddPath(unsigned u, unsigned v, unsigned w);
{
	graph[u].push_back({ v, w });
}
void Dijkstra::SetStartEndPoints(unsigned S, unsigned T)
{
	startPoint = S;
	endPoint = T;
	dist[startPoint] = 0;
	q.push({ S, 0 });
}
void Dijkstra::GetPath()
{
	PathCalculation();
	if (dist[endPoint] != INT_MAX)
		cout << dist[endPoint] << endl;
	else
		cout << "NIE\n";
}

void Dijkstra::PathCalculation()
{
	while (!q.empty())
	{
		edge p = q.top();
		q.pop();
		for (unsigned i = 0; i < graph[p.u].size(); i++)
		{
			unsigned u = p.u;
			unsigned v = graph[p.u][i].u;
			if (dist[u] + graph[p.u][i].w < dist[v])
			{
				dist[v] = dist[u] + graph[p.u][i].w;
				q.push(graph[p.u][i]);
			}
		}
	}
}