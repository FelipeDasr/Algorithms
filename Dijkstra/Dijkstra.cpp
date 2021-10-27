#include <iostream>
#include <queue>
#include <list>

#define INFINITO 100000000

using namespace std;

class Grafo
{
private:
  int V; //numero de vertices

  list<pair<int, int> >* adj; //ponteiro para uma lista de adjacentes

public:
  Grafo(int V)
  {
    this->V = V;
    adj = new list<pair<int, int>>[V];
  }

  void addAresta(int v1, int v2, int c)
  {
    adj[v1].push_back(make_pair(v2, c));
  }

  int dijkstra(int orig, int dest)
  {
    /*vetor de visitados serve para o caso de o vertice ja tenha sido expandido
    , não expandir mais*/
    int visitados[V], dist[V];

    //fila de prioridade minima
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    for(int i = 0; i < V; i++)
    {
      dist[i] = INFINITO;
      visitados[i] = false;
    }
    //a distancia para a origem é 0

    dist[orig] = 0;

    pq.push(make_pair(orig, dist[orig]));

    //loop do algoritmo
    while(!pq.empty())
    {
      pair<int, int> p = pq.top(); //extrai o pair do topo
      int u = p.first; //obtem o vertice do pair
      pq.pop();

      //verifica se o vertice não foi expandido
      if(visitados[u] ==  false)
      {
        //marca como visitado
        visitados[u] == false;

        list<pair<int, int> >::iterator it;
        //percorre os adjacentes de u
        for(it = adj[u].begin(); it != adj[u].end(); it++)
        {
          //obtem o vertice adjacente e o custo da eresta
          int v = it->first;
          int custo_aresta = it->second;

          //relaxando (u, v)
          if(dist[v] > (dist[u] + custo_aresta))
          {
            //atualiza a distancia e insere na fila
            dist[v] = dist[u] + custo_aresta;
            pq.push(make_pair(v, dist[v]));
          }
        }
      }
    }

    return dist[dest];
  }

};

int main()
{
  Grafo g(5);

  g.addAresta(0, 1, 4);
  g.addAresta(0, 2, 2);
  g.addAresta(0, 3, 5);
  g.addAresta(0, 1, 4);
  g.addAresta(1, 4, 1);
  g.addAresta(2, 3, 2);
  g.addAresta(2, 3, 2);
  g.addAresta(2, 4, 1);
  g.addAresta(3, 4, 1);

  cout << g.dijkstra(0, 4);

  return 0;
}
