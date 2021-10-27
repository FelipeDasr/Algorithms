#include <iostream>

using namespace std;

int grafo[5][5] =
{
    {0,0,1,0,0,},
    {0,0,1,0,0,},
    {1,1,0,1,1,},
    {0,0,1,0,1,},
    {0,0,1,1,0}
};

bool ligacao(int v1, int v2)
{
  if(grafo[v1][v2])
    return true;
  return false;
}

int main()
{
  cout << ligacao(2, 0) << endl;
  return 0;
}
