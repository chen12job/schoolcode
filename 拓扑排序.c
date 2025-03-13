#include <stdio.h>
#include <stdlib.h>

#define MAX 11

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* indegree;
} Graph;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->indegree = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->indegree[i] = 0;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    graph->indegree[dest]++;
}

void topologicalSort(Graph* graph) {
    int queue[MAX];
    int front = -1, rear = -1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    int count = 0;
    int topoOrder[MAX];

    while (front != rear) {
        int current = queue[++front];
        topoOrder[count++] = current;

        Node* temp = graph->adjLists[current];
        while (temp) {
            int adjVertex = temp->vertex;
            graph->indegree[adjVertex]--;
            if (graph->indegree[adjVertex] == 0) {
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }

    if (count != graph->numVertices) {
        printf("图中有回路，无法进行拓扑排序。\n");
    } else {
        printf("拓扑排序结果: ");
        for (int i = 0; i < count; i++) {
            printf("A%d ", topoOrder[i] + 1);
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(MAX);

    // 根据题目中的依赖关系添加边
    addEdge(graph, 0, 1); // A1 -> A2
    addEdge(graph, 1, 2); // A2 -> A3
    addEdge(graph, 3, 4); // A4 -> A5
    addEdge(graph, 2, 4); // A3 -> A5
    addEdge(graph, 2, 5); // A3 -> A6
    addEdge(graph, 4, 6); // A5 -> A7
    addEdge(graph, 5, 6); // A6 -> A7
    addEdge(graph, 6, 7); // A7 -> A8
    addEdge(graph, 7, 8); // A8 -> A9
    addEdge(graph, 6, 9); // A7 -> A10
    addEdge(graph, 9, 10); // A10 -> A11

    topologicalSort(graph);

    return 0;
}