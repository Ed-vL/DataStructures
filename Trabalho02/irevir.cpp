#include <bits/stdc++.h>
#define vertex int
#define INF 99999
using namespace std;

struct graph
{
  int V;
  int A;
  int **adj;
};

typedef struct graph *Graph;

static int **MATRIXint(int r, int c, int val)
{
  int **m = (int **)malloc(r * sizeof(int *));
  for (vertex i = 0; i < r; ++i)
    m[i] = (int *)malloc(c * sizeof(int));
  for (vertex i = 0; i < r; ++i)
    for (vertex j = 0; j < c; ++j)
      m[i][j] = val;
  return m;
}

Graph GRAPHinit(int V)
{
  Graph G = (Graph)malloc(sizeof *G);
  G->V = V;
  G->A = 0;
  G->adj = MATRIXint(V, V, INF);
  return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w)
{
  if (G->adj[v][w] == INF)
  {
    G->adj[v][w] = 1;
    G->A++;
  }
}

void printSolution(Graph dist)  
{  
    for (int i = 1; i < dist->V; i++)  
    {  
        for (int j = 1; j < dist->V; j++)  
        {  
            if (dist->adj[i][j] == INF){ 
                cout<<0<<endl;
                return;
            }
        }    
    }
    cout<<1<<endl;
}  

void floydWarshall(Graph g)
{

  int i, j, k;
  Graph dist = GRAPHinit(g->V);

  for (i = 0; i < g->V; i++)
    for (j = 0; j < g->V; j++)
      dist->adj[i][j] = g->adj[i][j];
  for (k = 0; k < g->V; k++)
  {
    for (i = 0; i < g->V; i++)
    {

      for (j = 0; j < g->V; j++)
      {
        if (dist->adj[i][k] + dist->adj[k][j] < dist->adj[i][j])
          dist->adj[i][j] = dist->adj[i][k] + dist->adj[k][j];
      }
    }
  }
 printSolution(dist);
}

int main(){
  int S,v,w,c,n;
  scanf("%d",&S);
  scanf("%d",&c);
  while(S != 0){
  Graph grafo;
  grafo = GRAPHinit(S+1);
  for(int i = 0; i < c; i++){
    scanf("%d %d %d",&v,&w,&n);
    if(n == 2){
      GRAPHinsertArc(grafo,w,v);
    }
    GRAPHinsertArc(grafo,v,w);
  }
  floydWarshall(grafo);
  scanf("%d",&S);
  scanf("%d",&c);
  }
}