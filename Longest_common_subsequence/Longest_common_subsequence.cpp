#include <iostream>
#include <algorithm>

using namespace std;

int getLenLcs(string & s1, string & s2)
{
  int lenS1 = s1.size(), lenS2 = s2.size();

  int m[lenS1 + 1][lenS2 + 1];

  for(int i = 1; i <= lenS1; i++)
    m[i][0] = 0;
  for (int i = 0; i <= lenS2; i++)
    m[0][i] = 0;

  for(int i = 1; i <= lenS1; i++)
  {
    for(int j = 1; j <= lenS2; j++)
    {
        if(s1[i - 1] == s2[j - 1])
          m[i][j] = m[i - 1][j - 1] + 1;
        else
          m[i][j] = max(m[i][j - 1], m[i - 1][j]);
    }
  }

  cout << "Tabela\n";

  for(int  i = 0; i <= lenS1; i++)
  {
    for(int j = 0; j <= lenS2; j++)
    {
      cout << m[i][j];
    }
    cout << endl;
  }

  return m[lenS1][lenS2];
}

int main()
{
  string s1("ABCB"), s2 ("BDCAB");

  int lenLcs = getLenLcs(s1, s2);

  cout << "Length: " << lenLcs << endl;

  return 0;
}
