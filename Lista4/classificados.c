#include <stdio.h>
#include <stdlib.h>
#define exch(a, b) \
  {                \
    Semente t = b; \
    b = a;         \
    a = t;         \
  }

typedef struct Semente
{
  int cod;
  int nota;
  int index;
} Semente;

Semente maior2(Semente a, Semente b)
{
  if (a.nota > b.nota)
  {
    return a;
  }
  if (a.nota == b.nota)
  {
    if (a.cod > b.cod)
    {
      return a;
    }
    return b;
  }
  if(b.nota > a.nota)
  {
    return b;
  }
}

Semente mediana(Semente a, Semente b, Semente c)
{
  Semente m = maior2(a,maior2(b,c));
  if (m.nota == a.nota)
  {
    return maior2(b, c);
  }
  if (m.nota == b.nota)
  {
    return maior2(a, c);
  }
  if (m.nota == c.nota)
  {
    return maior2(a, b);
  }
}

static int separa(Semente *v, int l, int r)
{
  Semente c;
  exch(v[(l + r )/2], v[r]);
  c = v[r];
  int j = l;

  for (int i = l; i < r; i++)
  {
    if (v[i].nota < c.nota)
    {
      exch(v[i], v[j]);
      j++;
    }
    if (v[i].nota == c.nota)
    {
      if (v[i].cod < c.cod)
      {
        exch(v[i], v[j]);
        j++;
      }
    }
  }
  exch(v[j], v[r]);
  return j;
}

void eec(int i, Semente *v, int l, int r)
{

  int j = separa(v, l, r);
  if (j == i)
  {
    return;
  }
  if (j > i)
  {
    eec(i, v, l, j - 1);
  }
  else
  {
    eec(i, v, j + 1, r);
  }
  return;
}

void mergeAB(Semente *c, Semente *a, int m, Semente *b, int n)
{
  int i = 0, j = 0, k = 0;
  while (i < m && j < n)
  {
    if (a[i].cod < b[j].cod)
    {
      c[k] = a[i];
      i++;
      k++;
    }
    else
    {
      c[k] = b[j];
      k++;
      j++;
    }
  }
  while (i < m)
  {
    c[k] = a[i];
    k++;
    i++;
  }
  while (j < n)
  {
    c[k] = b[j];
    k++;
    j++;
  }
}

void merge(Semente *v, int l, int r, int q)
{
  int i = l, k = 0;
  Semente *c = malloc(sizeof(Semente) * (r - l + 1));
  mergeAB(c, &v[l], (q - l + 1), &v[q + 1], (r - q));
  while (i <= r)
  {
    v[i] = c[k];
    i++, k++;
  }
  free(c);
}

void mergeSort(Semente *v, int l, int r)
{
  if (l == r)
  {
    return;
  }
  int q = (r + l) / 2;
  mergeSort(v, l, q);
  mergeSort(v, q + 1, r);
  merge(v, l, r, q);
}

int main()
{
  int k, cod, nota, i = 0;
  Semente semente;
  Semente *sementes;
  sementes = malloc(sizeof(Semente) * 10000001);
  scanf("%d", &k);
  while ((scanf("%d", &cod) == 1) && (scanf("%d", &nota) == 1))
  {
    semente.cod = cod;
    semente.nota = nota;
    sementes[i] = semente;
    i++;
  }
  eec(k - 1, sementes, 0, i - 1);
  mergeSort(sementes, 0, k - 1);
  for (int c = 0; c < k; c++)
  {
    printf("%d %d\n",sementes[c].cod, sementes[c].nota);
  }
  return 0;
}