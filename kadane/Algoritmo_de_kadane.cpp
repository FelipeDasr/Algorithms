#include <iostream>
#define TAM 5

using namespace std;

int kadane(int vet[TAM])
{
  int max_atual = 0;
  int max_total = -1;

  for(int i = 0; i < TAM; i++)
  {
    max_atual = max_atual + vet[i];

    if(max_atual < 0)
      max_atual = 0;
    if(max_atual > max_total)
      max_total = max_atual;
  }
  return max_total;
}

int main()
{
  int v[TAM] = {-2, 5, -1, 2, -3};

  cout << kadane(v);

  return 0;
}
