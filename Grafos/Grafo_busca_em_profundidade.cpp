#include <iostream>
#include <list>
#include <algorithm>//função find
#include <stack>

using namespace std;

class Grafo
{
  int V; //numero de vertices
  list<int> *adj; //ponteiro para um array contendo as listas de adjacência

public:
  Grafo(int V);

  void adicionarAresta(int v1, int v2); //adiciona uma aresta ao grafo

  //faz uma dfs apartir de um vertice
  void dfs(int v);
};

Grafo::Grafo(int V)
{
  this->V = V; //atribui o numero de vertices
  adj = new list<int>[V]; //cria listas
}

void Grafo::dfs(int v)
{
  stack<int>pilha;
  bool visitados[V];

  //marca todos nao visitados
  for(int i = 0; i < v; i++)
    visitados[i] = false;

  while(true)
  {
    if(!visitados[v])
    {
      cout << "Visitando vertice " << v << " ...\n";
      visitados[v] = true;
      pilha.push(v);
    }
    bool achou  = false;
    list<int>::iterator it;

    //busca por um vizinho nao visitado
    for(it = adj[v].begin(); it != adj[v].end(); it++)
    {
      if(!visitados[*it])
      {
        achou = true;
        break;
      }
    }

    if(achou)
      v = *it; // atualiza o "v"
    else
    {
      pilha.pop();
      if(pilha.empty())
        break;

      v = pilha.top();
    }
  }
}

void Grafo::adicionarAresta(int v1, int v2)
{
  //adciona v2 a lista de vertices adjacêntes de v1
  adj[v1].push_back(v2);
}

int main()
{
  //criando um grafo de 4 vertices
  Grafo grafo(4);

  grafo.adicionarAresta(0, 1);
  grafo.adicionarAresta(0, 2);
  grafo.adicionarAresta(1, 3);
  grafo.adicionarAresta(1, 4);
  grafo.adicionarAresta(2, 5);
  grafo.adicionarAresta(2, 6);
  grafo.adicionarAresta(6, 7);

  grafo.dfs(0);

  return 0;
}
