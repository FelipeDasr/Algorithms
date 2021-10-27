#include <iostream>
#include <list>
#include <algorithm>//função find

using namespace std;

class Grafo
{
  int V; //numero de vertices
  list<int> *adj; //ponteiro para um array contendo as listas de adjacência

public:
  Grafo(int V);

  void adicionarAresta(int v1, int v2); //adiciona uma aresta ao grafo

  int obterGrauDeSaida(int v); //obter o grau de saida do grafo

  bool existeVizinho(int v1, int v2); // verifica se v1 é vizinho de v2
};

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

int Grafo::obterGrauDeSaida(int v)
{
  //basta retornar o tamanho da lista que é a quantidade de vizinhos
  return adj[v].size();
}

bool Grafo::existeVizinho(int v1, int v2)
{
  if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
    return true;
  return false;
}

int main()
{
  //criando um grafo de 4 vertices
  Grafo grafo(4);

  grafo.adicionarAresta(0, 1);
  grafo.adicionarAresta(0, 3);
  grafo.adicionarAresta(1, 2);
  grafo.adicionarAresta(3, 1);
  grafo.adicionarAresta(3, 2);

  cout << "Grau de saida do vertice 1: " << grafo.obterGrauDeSaida(1) << endl;
  cout << "Grau de saida do vertice 2: " << grafo.obterGrauDeSaida(2) << endl;
  cout << "Grau de saida do vertice 3: " << grafo.obterGrauDeSaida(3) << endl;

  if(grafo.existeVizinho(0, 1))
    cout << "\n\n1 eh vizinha de 0\n";
  else
    cout << "\n\n1 nao eh vizinho de 0\n";

  if(grafo.existeVizinho(0, 2))
    cout << "\n\n2 eh vizinha de 0\n";
  else
    cout << "\n\n2 nao eh vizinho de 0\n";
  return 0;
}
