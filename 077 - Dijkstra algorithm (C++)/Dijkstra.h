# programming challenge
# Dijkstra algorithm
# C++ 17
# binariusO1



#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Dijkstra
{
private:
	struct edge
	{
		unsigned u, w;
	};
public:
	//
	// n - vertex numbers, e - edges numbers
	Dijkstra(size_t n, size_t e) : N(n), E(e), startPoint(0), endPoint(1);
	~Dijkstra()
	{
		delete[] graph;
	}
	//
	// a - start vertex point, u - end vertex point, val - value
	void AddPath(unsigned u, unsigned v, unsigned w);
	//
	// S - start path point, T - end path point
	void SetStartEndPoints(unsigned S, unsigned T);
	void GetPath();

	friend bool operator<(edge a, edge b) {
		return a.w < b.w;
	}

private:
	size_t N;
	size_t E;

	unsigned startPoint;
	unsigned endPoint;

	std::vector<unsigned> dist;		//paths value array
	std::vector<edge>* graph;
	priority_queue<edge> q;
	void PathCalculation();
};
