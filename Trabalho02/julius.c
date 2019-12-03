#include <stdio.h>
#include <stdlib.h>

typedef struct neigh
{
  int *b;
  int julius;
} neigh;

struct graph
{
  int V;
  int A;
  neigh *adj;
};

typedef struct graph *Graph;

static neigh *MATRIXint(int r, int c, int val)
{
  neigh *m = malloc(r * sizeof(neigh));
  for (int i = 0; i < r; ++i)
    m[i].b = malloc(c * sizeof(int));
  return m;
}

Graph GRAPHinit(int V)
{
  Graph G = malloc(sizeof(Graph));
  G->V = V;
  G->A = 0;
  G->adj = MATRIXint(V, V, 0);
  return G;
}

void GRAPHinsert(Graph G, int v, int w)
{
  if (G->adj[v].b[w] != 1)
  {
    G->adj[v].b[w] = 1;
    G->A++;
  }
} 

int main()
{
  int n, m, j, ni, bairro, aux;
  Graph hood;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &j);
  hood = GRAPHinit(n+1);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &ni);
    for (int k = 0; k < ni; k++)
    {
      scanf("%d", &bairro);
      GRAPHinsert(hood, i, bairro);
    }
  }
  for (int i = 0; i < m; i++)
  {
    scanf("%d", &bairro);
    hood->adj[bairro].julius = 1;
    for(int k = 0; k < n; k++){
      if(hood->adj[k].b[bairro] == 1){
        hood->adj[k].julius = 1;
      }
    }

  }
  for (int i = 0; i < j; i++)
  {
    scanf("%d", &bairro);
    if (hood->adj[bairro].julius == 1)
    {
      printf("Eu vou estar la\n");
    }
    else
    {
      printf("Nao vou estar la\n");
    }
  }
  return 0;
}