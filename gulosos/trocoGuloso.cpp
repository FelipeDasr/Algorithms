#include <iostream>
#include <vector>

using namespace std;

int numMoedas(vector<int>& moedas, int n)
{
  int qMoedas = 0;
  int tamMoedas = moedas.size();

  for(int i = tamMoedas - 1; i >= 0; i--)
  {
    int auxMoedas = n / moedas[i];
    n -= auxMoedas * moedas[i];
    qMoedas += auxMoedas;
    if(n == 0)
      break;
  }

  return qMoedas;
}

int main(int argc, char const *argv[])
{
  vector<int> moedas;
  int n;

  n = 26;

  moedas.push_back(1);
  moedas.push_back(2);
  moedas.push_back(5);
  moedas.push_back(10);
  moedas.push_back(20);

  cout << "Numero de moedas: " << numMoedas(moedas, n);

  return 0;
}
