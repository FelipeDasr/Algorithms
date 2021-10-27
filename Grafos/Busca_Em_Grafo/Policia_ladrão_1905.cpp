#include <iostream>
#include <vector>

using namespace std;

class Coordenada
{
public:
  bool visitada;
};

int winner;

void busca(vector<vector <int> > mat, vector<vector <Coordenada> > coordenadas, int i, int j)
{
	if(i >= 0 && i < 5 && j >= 0 && j < 5 && !winner)
	{
    coordenadas[i][j].visitada = true;
    if(j == 4 && i == 4)
      winner = 1;
    else
    {
      if(i + 1 < 5 && mat[i + 1][j] == 0 && !coordenadas[i + 1][j].visitada)
        busca(mat, coordenadas, i + 1, j);
      if(i - 1 >= 0 && mat[i - 1][j] == 0 && !coordenadas[i - 1][j].visitada)
        busca(mat, coordenadas, i - 1, j);
      if(j + 1 < 5 && mat[i][j + 1] == 0 && !coordenadas[i][j + 1].visitada)
        busca(mat, coordenadas, i, j + 1);
      if(j - 1 >= 0 && mat[i][j - 1] == 0 && !coordenadas[i][j - 1].visitada)
        busca(mat, coordenadas, i, j - 1);
    }
  }
}

int main()
{
  int t;

  cin >> t;

  for(int i = 0; i < t; i++)
  {
    vector<vector <int> > mat(5);
    vector<vector <Coordenada> > coordenadas(5);

    for(int j = 0; j < 5; j ++)
    {
      mat[j].resize(5);
      coordenadas[j].resize(5);
    }

    for(int j = 0; j < 5; j++)
    {
      for(int k = 0; k < 5; k++)
      {
        int e;
        cin >> e;
        mat[j][k] = e;

        coordenadas[j][k].visitada = false;
      }
    }
    winner = 0;
    busca(mat, coordenadas, 0, 0);

    if(winner)
      cout << "COPS\n";
    else
      cout << "ROBBERS\n";
  }

  return 0;
}
