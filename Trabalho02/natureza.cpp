#include <bits/stdc++.h>
#define vertex int

using namespace std;

static int cnt,cnt2;
int pre[5000];
typedef struct node *link;

struct graph {
   int V; 
   int A; 
   link *adj; 
};

struct node { 
   vertex w; 
   link next; 
};

typedef struct graph *Graph;

static link NEWnode( vertex w, link next) { 
   link a = (link) malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

Graph GRAPHinit( int V) { 
   Graph G = (Graph) malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = (link *) malloc( V * sizeof (link));
   for (vertex v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   for (link a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
   cnt2++;
}

static void dfsR( Graph G, vertex v) 
{ 
   pre[v] = cnt++;
   //cout << "pre: " << pre[v] << " pre+1: " << pre[v+1] << "\n";
   for (link a = G->adj[v]; a != NULL; a = a->next) {
      vertex w = a->w;
      //cout << "w: " << w << "\n";
      if (pre[w] == -1)
         dfsR( G, w); 
   }
}

void GRAPHdfs( Graph G) 
{ 
   cnt = 0;
   for (vertex v = 0; v < G->V; ++v) 
      pre[v] = -1;
   for (vertex v = 0; v < cnt2; ++v)
      if (pre[v] == -1) 
         dfsR( G, v); // começa nova etapa
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
    //for(int v = 0; v < 10;v++)
    cout << pre[cnt2] << '\n';
    cin >> criaturas;
    cin >> edges;
  }
  return 0;
}