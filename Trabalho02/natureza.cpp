#include <bits/stdc++.h>

using namespace std;

static int cnt,cnt2;
int pre[5000];

typedef struct vertex * link;

typedef struct vertex{
  int i;
  vertex * next; 
} vertex;

typedef struct graph{
  int V;
  link * adj;
} graph;



graph * GRAPHinit( int V) { 
   graph * G = (graph *) malloc(sizeof(*G));
   G->V = V; 
   G->adj = (link *) malloc(sizeof(link)*V);
   for (int v = 0; v < V; ++v){
      G->adj[v] = NULL;
   }
   return G;
}

static link NEWnode( int w, link next) { 
   link a = (link) malloc( sizeof (link));
   a->i = w; 
   a->next = next;     
   return a;                         
}

void GRAPHinsertArc(graph * G, int v, int w) { 
   for (link a = G->adj[v]; a != NULL; a = a->next) 
      if (a->i == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
}

static void dfsR( graph * G, int v) 
{ 
   pre[v] = cnt++;
   cnt2++; 
   for (link a = G->adj[v]; a != NULL; a = a->next) {
      int w = a->i;
      //cout <<"elemento: "<< w << '\n';
      if (pre[w] == -1)
         dfsR( G, w); 
   }
}

void GRAPHdfs( graph * G) 
{ 
   cnt = 0;
   cnt2 = 0;
   for (int v = 0; v < G->V; ++v) 
      pre[v] = -1;
   for (int v = 0; v < G->V; ++v)
      if (pre[v] == -1) 
         dfsR( G, v);
}

int main(){
  int criaturas, edges,v,w,aux = 0;
  string criatura,c1,c2;
  graph * cadeia;
  map <string,int> natureza;
  map <string,int>::iterator it;
  cin >> criaturas;
  cin >> edges;
  while(criaturas != 0 && edges != 0){
    cnt2 = 0;
    cadeia = GRAPHinit(edges*2);
    for(int i = 0; i < criaturas; i ++){
      cin >> criatura;
      natureza.insert(pair<string,int>(criatura,i));
    }
    for(int c = 0; c < edges; c++){
      cin >> c1;
      cin >> c2;
      it = natureza.find(c1);
      v = it->second;
      it = natureza.find(c2);
      w = it->second;
      //cout << "v: " << v << " w: " << w << '\n';
      GRAPHinsertArc(cadeia,v,w);
    }
    GRAPHdfs(cadeia);
    for (int v = 0; v < cadeia->V; ++v)
    cout << pre[v] << '\n';
    cin >> criaturas;
    cin >> edges;
  }
  return 0;
}