#include <stdio.h>
#include <stdlib.h>

#define NV 5
#define BLACK -1
#define GREY 0
#define WHITE 1



typedef struct edge {
    int dest; 
    int cost ; 
    struct edge *next ;
} *EList;

typedef EList Graph [NV] ;
    
int addEdg (Graph g,int or, int f, int cost){
    EList temp = g[or] ;
    EList temp1=NULL; 
    while (temp !=NULL){
        temp1 = temp;
        temp = temp->next;

    }
    temp = malloc (sizeof(struct edge));
    temp->dest = f;
    temp->cost = cost;
    temp->next=NULL;
    if (temp1) temp1->next = temp;
    else g[or] = temp;
    return 1;
}

int printG (Graph g){
    int i =0, aux=0,aux2;
    EList temp;

    for (;i<NV;i++){
        printf("Vertice : %d\n", i);
        for (temp=g[i],aux=0;temp;temp=temp->next,aux++){
            for(aux2=aux;aux2>0;aux2--) printf("\t");
            printf("\tDestino: %d\n",temp->dest);
            for(aux2=aux;aux2>0;aux2--) printf("\t");
            printf("\tCusto: %d\n",temp->cost);
        }    
    }
    printf("\n");
    return 1;
    
}

int createG (Graph g){
    /*
    addEdg(g,0,1,12);
    addEdg(g,1,2,10);
    addEdg(g,2,3,5);
    //addEdg(g,3,1,8);
    addEdg(g,3,4,15);*/
/*
    addEdg(g,0,1,12);
    addEdg(g,1,2,12);
    addEdg(g,1,3,12);
    addEdg(g,2,4,12);
    addEdg(g,4,5,12);
    addEdg(g,4,6,12);*/

  /*  addEdg(g,0,1,12);
    addEdg(g,1,2,12);
    addEdg(g,1,4,12);
    addEdg(g,1,5,12);
    addEdg(g,1,6,12);
    addEdg(g,2,3,12);
    addEdg(g,4,6,12);*/
    
    addEdg(g,1,2,7);
    addEdg(g,1,3,10);
    addEdg(g,1,4,15);
    addEdg(g,2,0,4);
    addEdg(g,2,4,20);
    addEdg(g,3,4,5);
    addEdg(g,4,0,6);
    addEdg(g,4,2,2);

/*
    addEdg(g,0,1,0);
    addEdg(g,0,2,0);
    addEdg(g,1,0,0);
    addEdg(g,1,3,0);
    addEdg(g,1,6,0);
    addEdg(g,2,0,0);
    addEdg(g,2,4,0);
    addEdg(g,2,5,0);
    addEdg(g,3,1,0);
    addEdg(g,3,5,0);
    addEdg(g,4,2,0);
    addEdg(g,4,6,0);
    addEdg(g,5,2,0);
    addEdg(g,5,3,0);
    addEdg(g,5,7,0);
    addEdg(g,6,1,0);
    addEdg(g,6,4,0);
    addEdg(g,6,7,0);
    addEdg(g,7,5,0);
    addEdg(g,7,6,0);

    addEdg(g,3,0,12);
    addEdg(g,3,1,12);
    addEdg(g,3,4,12);
    addEdg(g,4,2,12);
    addEdg(g,1,6,12);
    addEdg(g,6,5,12);
*/
    return 1;
}



int capacidade (Graph g, int v){
    int dest =0, or=0,i;
    EList temp;
    for (i=0; i<NV;i++){
        for(temp=g[i]; temp; temp=temp->next){
            if (i == v) or +=temp->cost;
            else{
                if (temp->dest == v) dest +=temp->cost;
            }

        }
    }
    return dest-or;
}

int maxCap (Graph g){
    int ind=0,i;
    EList temp;
    int *arr = calloc(NV, sizeof(int));
    for (i=0; i<NV; i++){
        for(temp=g[i]; temp;temp=temp->next){
            arr[i]-=temp->cost;

            arr[temp->dest]+= temp->cost;

            if(arr[i]>arr[ind]) ind =i;
            if(arr[temp->dest] > arr[ind]) ind = temp->dest;
        }
    }
    free(arr);
    return ind;
}

int addist (Graph g, int o, int k){

    EList temp;
    int dist=-1;
    if (o == k) return 0;
    for (temp=g[o]; temp && dist==-1; temp = temp->next){
        dist = addist(g,temp->dest,k);
        if (dist != -1) dist++;
    }
    return dist;
    
}

int depthF (Graph g, int init, int *arr,int size){
    EList temp;
    int flag=1, i=0;
    for (i=0;i<size;i++)
        if (arr[i] == init) flag =0;
    
    if (flag==1) {arr[i] = init;size++;}

    for (temp=g[init];temp && flag; temp = temp->next){
        size=depthF(g, temp->dest, arr,size);
        
    }
    return size;
}

int breadthF (Graph g, int init, int *arr){
    EList temp;
    int i=0, fim=0,i2=0,flag=1;
    arr[i] = init; fim++;

    while (i < fim){
        for (temp = g[arr[i]]; temp; temp=temp->next){
            for (i2=0; i2<fim && flag != 0; i2++) if (arr[i2] == temp->dest) flag=0; 
            if (flag!=0) {arr[fim] = temp->dest; fim++;}
            flag=1;
        }
        i++;
    }
}

//mais eficiente
int breadthF2 (Graph g, int init, int *arr){
    int pais[NV];
    int i=0, vertice=init, vistos=0, flag=1;
    EList tmp;
    for (i=0; i<NV; pais[i]=-2, i++);
    
    pais[vertice] =-1;
    arr[vistos] = vertice;
    vistos++;
    i=0;

    while (i < vistos){
        for (tmp = g[vertice]; tmp ;tmp=tmp->next){
            if (pais[tmp->dest] == -2){
                pais[tmp->dest] = vertice;
                arr[vistos] = tmp->dest;
                vistos++;}
        }
        i++;
        vertice = arr[i];
        if (vistos == NV) i=vistos;
    } 


}


int dijkstra(Graph g,int cost[], int ori, int pais[]){
    EList temp;
    int color[NV];
    int i=0, res=0, inicio=0, fim=0, min, ind=ori, flag =0,now;
    for (i=0;i<NV; i++) {color[i] = BLACK; cost[i]=-1;pais[i]=-1;}
    color[ind] = WHITE;
    cost[ind]=0;
    do  {
        for (temp = g[ind]; temp; temp=temp->next){
            if (color[temp->dest] == BLACK || color[temp->dest] ==GREY ) {
                color[temp->dest] = GREY;
                if (cost[temp->dest]== -1) {cost[temp->dest] = cost[ind] + temp->cost; pais[temp->dest] = ind;}
                else if (cost[temp->dest] > cost[ind] + temp->cost ) {cost[temp->dest] = cost[ind] + temp->cost; pais[temp->dest] = ind;}
            }
            fim++;}
    
        for (i=0, min = 300000; i<NV; i++){
            if (color[i]==GREY) {
                if (min > cost[i]){
                    min = cost[i];
                    ind = i;}
                flag=1;
            }
        }
        if (flag==1) color[ind] = WHITE;

        inicio++;

    }while(inicio<fim);

    return 1;
    

}


int dijkstra2(Graph g,int cost[], int ori, int pais[]){
    int vertice = ori, i, flag=1;
    EList temp;
    for (i=0; i<NV; cost[i]= 0, pais[i]=-2, i++);
    pais[ori] = -1;

    for (i=0; i<NV;i++){
        
        for (temp = g[vertice]; temp; temp=temp->next){
           if (pais[temp->dest] == -2){
               pais[temp->dest] = vertice;
               cost[temp->dest] = cost[vertice] + temp->cost;
           }
           else if (pais[temp->dest] != -1){
               if (cost[temp->dest] > cost[vertice] + temp->cost){
                    cost[temp->dest] = cost[vertice] + temp->cost;
                    pais[temp->dest] = vertice;
               }
           }
        }
        //not complete...

    }

    

}



    // 1º temos de encontrar a raíz
    // 2º temos de chegar a todos os nodos do grafo atraves da raiz sem que haja ligaçao entre os nodos
    // se for arvore: podemos chegar ao ramo final dado q este n tem saidas

int indegree(Graph g, int o)
{
    int i=0, count=0;
    EList temp= g[i];
    for (i=0; i<NV;i++){
        if (i != o){
            temp = g[i];
            while (temp){
                if (temp->dest == o) count++;
                temp=temp->next;
            }
        }
    }
    return count;
}

int isTree (Graph g){
    int flag=1,flag1=0;
    int i=0, d,raiz;
    for (i=0; i<NV && flag; i++){
        d = indegree(g,i);
        if (d==0 && flag1 == 0) {flag1 =1; raiz=i;}
        else if (d==1);
        else if (d>1) flag = 0;
        else flag=0;
    }
    return (flag==1)? raiz:-1;
}



int pesoC(Graph g, int v[], int k){
    int i = 0, flag=1, som=0;
    EList temp;
    while (flag && i+1<k){
        temp = g[v[i]];
        while (temp &&temp->dest != v[i+1]) temp=temp->next;
        if (!temp) {flag = 0; som =-1;}
        else {
            som +=temp->cost;
            i++;
        }   
    }    
    return som;
}

int maisArestas (Graph g, int o){
    int pais[NV], pesos[NV];
    dijkstra(g,pesos,o,pais);
    int maxPath,i,vertice=0, count=0;
    for (i=1,maxPath =pesos[0]; i <NV; i++){
        if (pesos[i]> maxPath){
            vertice=i;
            maxPath = pesos[i];
        }
    }
    
    for (; vertice != -1 && vertice!= o;){
        vertice = pais[vertice];
        count++;
    }
    if (vertice == -1) return -1;
    else return count;

}

// 1º percorrer todos os elementos alcançaveis a partir de um dado vertice -done
// 1.1 a medida que percorremos o grafo, criar grafo inverso
// 2º percorrer grafo inverso e verificar se vistos == n
int stronglyConnected(Graph g, int n){
    Graph inv;
    EList temp;
    int vistos=0, flag=1, vertice = 0, i=0;
    int arrV[n];
    int pais[n];
    for (i=0;i<n; pais[i]=-1, i++);
    i=0;


    while (flag!=-1 && flag!=0 ){
        temp = g[vertice];
        for (;temp; temp=temp->next){
            if (pais[temp->dest] == -1){
                arrV[vistos]= temp->dest;
                pais[temp->dest] = vertice;
                addEdg(inv,temp->dest,vertice,0); // adiciona nodo invertido ao grafo inv
                vistos++;
            }
        }
        if (vistos < n && i<n) {i++; vertice = arrV[i];}
        else if (i<n) flag=0;
        else flag=-1;
    }
    if (flag == -1) return 0;
    else {
        flag=1;
        vistos=0; 
        vertice=0;
        for (i = 0; i < n; pais[i] = -1, i++);
        i=0;
        while (flag != -1 && flag != 0){
            temp = inv[vertice];
            for (; temp; temp = temp->next){
                if (pais[temp->dest] == -1){
                    arrV[vistos] = temp->dest;
                    pais[temp->dest] = vertice;
                    vistos++;
                }
            }
            if (vistos < n && i < n){
                i++;
                vertice = arrV[i];
                }
            else if (i < n) flag = 0;
            else flag = -1;
        }
        return (flag==-1)?0:1;
     }
}

int colorOK(Graph g, int color[]){
    int flag=1, i=0;
    EList temp;
    for (i=0; i<NV && flag; i++){
        temp = g[i];
        for (;temp && flag; temp=temp->next){
            if (color[i]== color[temp->dest])
                flag=0;
        }
    return flag;
    }
}

int minPeso(Graph g){
    int i=0, min=0;
    min = g[i]->cost;
    EList temp;
    while (i<NV){
        temp=g[i];
        while (temp){
            if (temp->cost < min) min = temp->cost;
            temp=temp->next;
        }
        i++;
    }
    return min;
}

int haCaminho(Graph g, int o, int d){
    int i=0, flag=0, nvi=0;
    EList temp;
    int pais[NV];
    int vistos[NV];
    for (i=0; i<NV; pais[i]=-2,vistos[i]=-1,i++);
    
    vistos[0] = o;
    nvi++;
    pais[o]=-1;
    i=0;
    
    while (i<nvi && flag==0){
        for (temp=g[o]; temp && flag==0; temp=temp->next){
            if (temp->dest == o) flag=1;
            else if (pais[temp->dest] != -2){
                pais[temp->dest] = o;
                vistos[nvi] = temp->dest;
                nvi++;
            }
        }
        if (flag==0) {
            i++;
            o = vistos[i];
        }
    }
    return flag;
}





    int main()
{
    Graph g;
    int i=0,j=0,q;
    int arr[NV];
    int pais[NV];
    int cost[NV];
    for (i=0;i< NV ;i++){
        g[i]=NULL;
        arr[i]=-1;
    }
    printf("\n//////////////////////////////create////////////////////////////\n");
    createG(g);
    
    printG(g);

   printf("\n//////////////////////////////Paths////////////////////////////\n");

   depthF(g,0,arr,0);
   printf("Depth-First: ");
   for (i=0;i<NV;i++){
       printf("%d ->",arr[i]);
   }
   printf("\b\b    \n");

    printf("Breadth-First: ");
    breadthF(g,1,arr);
    for (i=0;i<NV;i++){
       printf("%d ->",arr[i]);
   }
    printf("\b\b    \n");
    printf("\n//////////////////////////Dijkstra//////////////////////////////\n");
    dijkstra(g,cost,0,pais);
    printf("Custo desde o vertice 0:\n");
    for (i=0;i<NV;i++){
       printf("%d -> %d\t\t",i,cost[i]);
   }
   printf("\n\nPais :\n");
       for (i=0;i<NV;i++){
       printf("%d -> %d\t\t",i,pais[i]);
   }
   printf("\n//////////////////////////IsTree//////////////////////////////\n");
   q = isTree(g);
   if (q==-1) printf("Not a tree!!\n");
   else printf("Root of tree : %d\n", q);
   printf("\n//////////////////////////PesoCaminho//////////////////////////////\n");
      
   int caminho [4] = {0,2,4,5};
   printf("O caminho 0 2 4 5 tem um peso de %d\n",pesoC(g,caminho,4));

   printf("\n//////////////////////////maisArestas//////////////////////////////\n");
   printf("O caminho com mais arestas partindo de 0 tem: %d arestas\n", maisArestas(g,0));

   printf("\n//////////////////////////////END////////////////////////////\n");
}
   