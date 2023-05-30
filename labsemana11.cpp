#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
private:
	vector<vector<int>> vertices;
	
public:
	Graph()
	{
	}
	Graph(vector<vector<int>> v)
	{
		vertices = v;
	}
	~Graph()
	{
	}
	void AddEdge(int x, int y)
	{
		vertices[x][y] = 1;
		vertices[y][x] = 1;
	}
	
	void PrintGraph()
	{
		cout << "Adjacency Matrix: " << endl;
		for (const auto& row : vertices)
		{
			for (int val : row)
				cout << val << " ";
				
			cout << endl;
		}
	}
	
	void VerticeAdyacente(int x, int y)
	{
		if (vertices[x][y] >= 1)
		{
			cout << "Los vertices " << x << " y " << y << " son adyacentes" << endl;
		}
		else
		{
			cout << "Los vertices " << x << " y " << y << " no son adyacentes" << endl;
		}
	}
	
	void CaminoVertices(int x, int y, queue<int> cam)
	{
		if (x == y)
			return;
		
		queue<int> c = cam;
		for (int i=x; i<y; i++)
		{
			if (vertices[i][x] == 1)
			{
				c.push(i);
				CaminoVertices(i, y, c);
			}
		}
	}
	
};

int main() {
	
	vector<vector<int>> vertices(8, vector<int>(8, 0));
	Graph grafo(vertices);
	
	// ejercicio 1
	grafo.AddEdge(0,1);
	grafo.AddEdge(0,2);
	grafo.AddEdge(1,3);
	grafo.AddEdge(1,4);
	grafo.AddEdge(1,5);
	grafo.AddEdge(2,3);
	grafo.AddEdge(2,5);
	grafo.AddEdge(2,6);
	grafo.AddEdge(3,4);
	grafo.AddEdge(4,5);
	grafo.AddEdge(4,7);
	grafo.AddEdge(5,6);
	grafo.AddEdge(5,7);
	grafo.AddEdge(6,7);
	
	// ejercicio 2
	grafo.PrintGraph();
	
	// ejercicio 3
	grafo.VerticeAdyacente(0,1);
	grafo.VerticeAdyacente(0,3);
	
	// ejercicio 4
	queue<int> camino;
	
	grafo.CaminoVertices(0,8, camino);
	
	while (!camino.empty())
	{
		cout << camino.front() << " ";
		camino.pop();
	}
	
	return 0;
}

