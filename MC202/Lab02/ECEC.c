#include <stdio.h>
#include <stdlib.h>

int n;

struct queue
{
	int* vet;
	int front = 0;
	int rear = 0;
};

struct node
{
	int* visinhos;
	int cnt = 0;
};

struct graph
{
	node* vertices;
};

typedef struct queue queue;
typedef struct graph graph;

graph* buildgraph()
{
	graph* gr = (graph*)malloc(sizeof(graph));
	gr->vertices = (node*)malloc(sizeof(node) * (n + 1));

	for (int i = 0; i <= n; i++) gr->vertices[i].cnt = 0;
	for (int i = 0; i <= n; i++) gr->vertices[i].visinhos = (int*)malloc(sizeof(int) * n);

	return gr;
}

queue* buildqueue()
{
	queue* q = (queue*)malloc(sizeof(queue));

	q->front = 0;
	q->rear = 0;
	q->vet = (int*)malloc(sizeof(int) * 100 * n);

	return q;
}

void enqueue(queue* q, int x)
{
	q->vet[q->rear++] = x;
	q->rear = q->rear % (100 * n);
}

int dequeue(queue* q)
{
	return q->vet[q->front++];
	q->front = q->front % (100 * n);
}

int isempty(queue* q)
{
	return q->front == q->rear;
}

void addedge(graph* gr, int a, int b)
{
	gr->vertices[a].visinhos[gr->vertices[a].cnt++] = b;
	gr->vertices[b].visinhos[gr->vertices[b].cnt++] = a;
}

void bfs(graph* gr, int m)
{
	printf("Origem da busca: %d\n", m);
	printf("Vertices alcancados e distancias:\n");

	int* dist = (int*)malloc(n * sizeof(int));
	for (int i = 0; i <= n; i++) dist[i] = -1;

	queue* q = buildqueue();

	enqueue(q, m);
	dist[m] = 0;

	printf("%d %d\n", m, 0);
	while (!isempty(q))
	{
		int u = dequeue(q);

		for (int i = 0; i < gr->vertices[u].cnt; i++)
		{
			int v = gr->vertices[u].visinhos[i];
			if (dist[v] == -1)
			{
				dist[v] = dist[u] + 1;
				enqueue(q, v);

				printf("%d %d\n", v, dist[v]);
			}
		}
	}

	free(q->vet);
	free(q);
}

void finish(graph* gr)
{
	for (int i = 0; i <= n; i++)
	{
		free(gr->vertices[i].visinhos);
	}

	free(gr->vertices);
	free(gr);
}

int main()
{
	scanf("%d", &n);

	graph* gr = buildgraph();

	int x, y;
	while(scanf("%d,%d", &x, &y) && (x || y))
		addedge(gr, x, y);

	int m; scanf("%d", &m);

	bfs(gr, m);
	finish(gr);
}