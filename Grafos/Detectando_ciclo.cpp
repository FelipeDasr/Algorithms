#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Grafo
{
  int V;
  list<int> *adj;
public:
  Grafo(int V);
  void adicionaAresta(int v1, int v2);

  bool dfs(int v);

  bool temCiclo();
};

Grafo::Grafo(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Grafo::adicionaAresta(int v1, int v2)
{
  adj[v1].push_back(v2);
}

bool Grafo::dfs(int v)
{
  stack<int> Pilha;
  bool visitados[V], pilha_rec[V];

  for(int i = 0; i < V; i++)
    visitados[i] = pilha_rec[i] = false;

  while(true)
  {
    bool achou_vizinho = false;
    list<int>::iterator it;

    if(!visitados[v])
    {
      Pilha.push(v);
      visitados[v] = pilha_rec[v] = true;
    }

    for(it = adj[v].begin(); it != adj[v].end(); it++)
    {
      if(pilha_rec[*it])
        return true;
      else if(!visitados[*it])
      {
        achou_vizinho = true;
        break;
      }
    }

    if(!achou_vizinho)
    {
      pilha_rec[Pilha.top()] = false;
      Pilha.pop();
      if(Pilha.empty())
        break;
      v = Pilha.top();
    }
    else
      v = *it;
  }

  return false;
}

bool Grafo::temCiclo()
{
  for(int i = 0; i < V; i++)
  {
    if(dfs(i))
      return true;
  }
  return false;
}

int main()
{
  Grafo g(4);

  g.adicionaAresta(0, 1);
  g.adicionaAresta(0, 2);
  g.adicionaAresta(1, 3);
  g.adicionaAresta(3, 0);

  if(g.temCiclo())
    cout << "CONTEM CICLO!";
  else
    cout << "NAO CONTEM CICLO!";
  return 0;
}
