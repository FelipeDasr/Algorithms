#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Brinquedo
{
public:
  int d, p, div;

  Brinquedo(int d, int p)
  {
    this->d = d;
    this->p = p;
    div = (double)p / d;
  }
};

bool comp(Brinquedo& x, Brinquedo & y)
{
  return x.div > y.div;
}

int main()
{
  int t, n, h = 1;

  while(true)
  {
    vector<Brinquedo> brinquedos;

    cin >> n >> t;

    if(n == 0)
      break;

    for(int i = 0; i < n; i++)
    {
      int p, d;

      cin >> d >> p;

      Brinquedo brinquedo(d, p);
      brinquedos.push_back(brinquedo);
    }
    sort(brinquedos.begin(), brinquedos.end(), comp);

    int pontuacao_total = 0, tempo_total = 0;

    int i = 0;
    while(i < n)
    {
      int aux_tempo_total = tempo_total + brinquedos[i].d;
      if(aux_tempo_total <= t)
      {
        pontuacao_total += brinquedos[i].p;
        tempo_total = aux_tempo_total;
      }
      else
        i++;
    }
    cout << "Instancia " << h++ << endl;
    cout << pontuacao_total << endl << endl;
  }

  return 0;
}
