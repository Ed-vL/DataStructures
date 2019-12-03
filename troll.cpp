#include <bits/stdc++.h>

using namespace std;



int main(){
  int c,r,cnt = 0;
  string criatura,c2;
  int maior = 0;
  vector <map<string,int>> natureza;
  cin >> c;
  cin >> r;
  while(c != 0 && r != 0){
    map <string, int> fon;
    for(int i = 0; i < c; i ++){
      cin >> criatura;
    }
    for(int j = 0; j < r; j++){
      cin >> criatura;
      cin >> c2;
      fon.insert(pair<string,int>(criatura,cnt++));

      fon.insert(pair<string,int>(c2,cnt++));
    }
    if (fon.size() > maior){
      maior = fon.size();
    }
    cout << maior << '\n';
    cin >> c;
    cin >> r;
  }
}