//

// Created by dolly on 2022/1/2.
//
#include "graph.h"

typedef struct _graph{
    int vertice;
    int edge;
    list_t *adj;
} graph_t;

typedef struct _graph_node{
    node_t* node;
    int no;
} graph_node_t;

graph_node_t* graph_node_init( int no)
{
    graph_node_t* gp_node = (graph_node_t*)malloc(sizeof(graph_node_t));
    gp_node->no = no;
    return gp_node;
}

void graph_init(graph_t* graph, int vertice)
{
    graph->vertice = vertice;
//    graph->edge = edge;
    graph->adj = malloc(sizeof(list_t*) * vertice);
    for(int i=0;i<vertice;i++){
        list_init(&graph->adj[i]);
    }
}


void graph_add_edge(graph_t* graph, int v, int w){
    graph_node_t* node1 = graph_node_init(v);
    graph_node_t* node2 = graph_node_init(w);
    list_add_tail(&graph->adj[v], node2->node);
    list_add_tail(&graph->adj[w], node1->node);
    graph->edge++;
}

int main(){
    int vertice = 5; // 0 1 2 3 4
    int edges[4][2] = {
            {0,1},
            {1,2},
            {2,3},
            {3,0},
    };
    graph_t graph;
    graph_init(&graph, vertice);
    for(int i=0;i<5;i++){
        int v = edges[i][0];
        int w = edges[i][1];
        graph_add_edge(&graph, v, w);
    }


    for(int i=0;i<vertice;i++){
        printf("%d : ",i);
        int cnt = graph.adj->count;
        node_t* cur = graph.adj[i].head;
        for(int j=0;j<cnt;i++){
            graph_node_t* tmp = (graph_node_t*)cur;
            printf("%d ", tmp->no);
            cur = cur->next;
        }

    }
}