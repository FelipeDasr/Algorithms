#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Grafo
{
  int V; //numero de vertices
  list<int> *adj; //ponteiro para um array contendo as listas de adjacência

public:
  Grafo(int V);

  void adicionarAresta(int v1, int v2); //adiciona uma aresta ao grafo

  //faz um busca em largura (BFS)
  void bfs(int v);
};

void Grafo::bfs(int v)
{
  queue<int> fila;
  bool visitados[V];

  for(int i = 0; i < V; i++)
    visitados[i] = false;

  cout << "Visitando vertice " << v << "...\n";

  while(true)
  {
    //cout << "\n\n" << v << "\n\n";
    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); it++)
    {
      if(!visitados[*it])
      {
        cout << "Visitando vertice " << *it << " ...\n";
        visitados[*it] = true;
        fila.push(*it);
      }
    }

    if(!fila.empty())
    {
      v = fila.front();
      fila.pop();
    }
    else
      break;
  }
}

Grafo::Grafo(int V)
{
  this->V = V; //atribui o numero de vertices
  adj = new list<int>[V]; //cria listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
  //adciona v2 a lista de vertices adjacêntes de v1
  adj[v1].push_back(v2);
}

int main()
{
  cout << "BFS\n";
  //criando um grafo de 4 vertices
  Grafo grafo(8);

  grafo.adicionarAresta(0, 1);
  grafo.adicionarAresta(0, 2);
  grafo.adicionarAresta(1, 3);
  grafo.adicionarAresta(1, 4);
  grafo.adicionarAresta(2, 5);
  grafo.adicionarAresta(2, 6);
  grafo.adicionarAresta(6, 7);

  grafo.bfs(0);
  return 0;
}
