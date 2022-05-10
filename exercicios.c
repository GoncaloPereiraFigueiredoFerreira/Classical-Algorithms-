//Exercicios sobre estruturas de dados Apontamentos JBB

/////   1)
int hash (char matricula[6]){
    int som=0,i;
    for (i=0; i<6;i++){
        som+=matricula[i];
    }
    return som;
}

int insert (Tabela T, char matricula[6]){
    int id =hash(matricula);
    Node temp;
    if (T[id] == NULL){
        T[id] = malloc(sizeof(struct no));
        T[id] ->matricula = matricula;
        T[id] ->next = NULL;
    }
    else {
    	temp=T[id];
    	while (temp->next && strcmp(...) != 0)
    		temp = temp->next;
    	if (strcmp(...)!=0){
    		temp->next = malloc(sizeof(struct no));
    		temp->next->matricula = matricula;
    		temp->next->next = NULL; 
    	}
    }
    return 0;
}

/////   2)

Arvore rr (Arvore arv){
	Arvore temp = arv->esq;
	if (temp == NULL) return arv;
	else{
		if (arv->bal == BAL && temp->bal == BAL){
			arv->bal == DIR;
			temp->bal == DIR;
		}
		else if (arv->bal == ESQ && temp->bal ==DIR){
			arv->bal == BAL;
			temp->bal == DIR;
		}
		else if (arv->bal == ESQ && temp->bal == ESQ){
			arv->bal == DIR;
			temp->bal == DIR;
		}
		else if (arv->bal == ESQ && temp->bal == BAL){
			arv->bal == BAL;
			temp->bal == DIR;
		}
		else if (arv->bal == DIR ){
			temp->BAL = DIR;
		}

		arv->esq = temp->dir;
		temp->dir = arv;
		arv= temp;
		return arv;

	}
}

/////   3)
// T(N)altura = N;
// T(N) = 2T((N-1)/2)altura + 2T((N-1)/2)
// T(1) = 1
//          
//      N resolvido    


/////   4)
void sinonimos(Dic d,char *pal){
	int key = hash(pal);
	Pal temp = d[id];
	Sin temp2;
	while (temp && strcmp (temp->pal,pal) != 0 )
		temp=temp->next;
	if (temp && strcmp (temp->pal,pal) == 0){
		temp2=temp->sins;
		for (; temp2; temp2=temp2->next)
			printf("%s\n",temp2->sin );
	}

}

/////   5)
Tree createHeapTree( Heap h, int raiz){
	if (raiz >= TAM) return NULL;
	Tree ret = malloc(sizeof(struct nodo));
	ret->valor = h[raiz];
	ret->esq = createHeapTree(h,2*raiz+1);
	ret->dir = createHeapTree(h,2*(raiz+1));
	return ret;
}

/////   7)
Node buildBST(int arr[], int n){
	int m = n/2;
	Node ret = malloc(sizeof(struct node));
	if(n==0) return NULL;
	if (n==1){
		ret->info = *arr;
		ret->esq=NULL;
		ret->dir=NULL;

	}
	else {
		ret->info = arr[m];
		ret->esq = buildBST(arr,n/2);
		ret->dir = buildBST(arr+n/2+1,n-n/2-1);

	}
	return ret;
}

/////   8)
// a melhor estrutura seria a implementação de arvores avl


/////   9)

void muda (MinHeap h, int pos, int valor){
	if (pos < MaxH){
		h->heap[pos] = h->heap[h->tamanho];
		bubbleDown(h,pos);
		h->heap[tamanho] = valor;
		bubbleUp(h,tamanho);
	}
}

#define FESQ (2*i)+1
#define FDIR 2*(i+1) 
#define PAI (i-1)/2

void bubbleUp (MinHeap h, int pos){
	int temp; 
	while (PAI(pos) >= 0 && h->heap[pos] < h->heap[PAI(pos)]){
		temp = h->heap[pos];
		h->heap[pos] = h->heap[PAI(pos)];
		h->heap[PAI(pos)]= temp;
		pos = PAI(pos);
	}
}	


void bubbleDown (MinHeap h, int pos){
	int temp,flag=1;
	while (flag){
		temp = h->heap[pos]
		if ( FESQ(pos) <= h->tamanho && temp > h->heap[FESQ(pos)]){
			h->heap[pos] = h->heap[FESQ(pos)];
			h->heap[FESQ(pos)]= temp;
			pos = FESQ(pos);
		}
		
		else if (FDIR(pos) <= h->tamanho && temp > h->heap[FDIR(pos)]){
			h->heap[pos] = h->heap[FDIR(pos)];
			h->heap[FDIR(pos)]= temp;
			pos = FDIR(pos);
		}
		
		else flag=0;

	}


}

/////   10)
int procura (ABPInt a, int l, int u){
	if (a== NULL) return 0;
	else{
		int ret;
		if (a->valor > l && a->valor < u)
			return 1;
		else {
			if (a->valor < l)
				ret = procura(a->dir, l,u);
			else if (a->valor > u)
				ret = procura(a->esq, l,u);
			return ret
		}
	}

}


/////   12)

int max (MinHeap h){
	return aux(h->heap,tamanho,0);
}

int aux (int *arr,int tamanho,int pos){
	if (FDIR(pos) <= tamanho){
		int esq = aux(arr,tamanho,FESQ(pos));
		int dir = aux(arr,tamanho,FDIR(pos));
		return (esq>dir)? esq:dir;
	}
	else if (FESQ(pos) <= tamanho)
		return aux(arr,tamanho,FESQ(pos));

	else return arr[pos];
}


/////   13)
int rdir(AVL *tptr){
	AVL temp;
	temp = (*tptr)->esq;
	if (temp == NULL) return -1;
	(*tptr)->esq = temp->dir;
	temp->dir = *tprtr;
	*tprtr= temp;
	return 0;


}


/////   15)
// a) 	Sendo K o nº de elementos permitidos em cada nodo de acordo com a carga maxima do nodo, T(N)= O(k) + O(1) sendo O(1) a pesquisa e O(K) o tempo que demora a percorrer todos os elementos que colidem naquele nodo

// b) Numa tabela de hash n podemos garantir a ordenação de elementos (esta será essencialmente aleatoria) . Assim para percorrer todos os elementos, no pior caso em que assumimos que o fator de carga de cada nodo está no maximo, teriamos um tempo de execução T(N) = O(N * K)

// c) A hash table permite uma inserção em tempo de execução constante bem como um tempo de procura constante (dado que os fatores de carga e o tamanho da tabela são suficientes para permitir o seu uso mais eficiente), sendo as suas maiores desvantagens, não permitir a pesquisa ordenada de elementos, e em alguns casos (dependendo da implementação) a remoção de elementos. Assim por exemplo a implementeação de dicionarios e estruturas semelhantes é aconselhavel usar esta estrutura de dados.


/////   18)
// a) Fc = chaves / cap; O Fc maximo deve ser 0.8;

// b) Numa pesquisa falhada numa tabela hash com closed addressing, será igual a T(N) = O(k), sendo K o nº maximo de elementos permitidos num nodo da tabela. Assim dado um Fc = 0.5 no melhor caso T(N) = O(1), e no pior caso T(N) = O(k), onde k é o numero maximo de keys permitidas para a mesma posiçao da tabela de hash.


/////   19)
void bubbleDown (MinHeap h);

int *ordenados (MinHeap h){
	int * ret = malloc(sizeof(int) * h->used);
	int i=0;
	while (h->used>0){
		ret[i] = h->heap[0];
		i++;
		h->heap[0] = h->heap[h->used-1];
		h->used--;
		bubbleDown(h);
	}
	return ret;

}


/////   20)
// a) Fc = chaves / cap; 

float loadFactorC (HashTableChain t){
	float chaves=0,result;
	float cap = (float) t->hashSize;
	int i =0;
	EntryChain tmp;

	while (i<t->hashSize){
		for (tmp = t[i]; tmp; tmp=tmp->ext, chaves++);
	}



	return chaves/cap;
}


/////   21)
int rank[26];

//simple awnser
int hash (int size, char c []){
	int som=0;
	int i=0;
	while (c[i]!='\0'){
		som+= rank[c[i]-'a'];
		i++;
	}
	return som%size;
}

/////   23) b) O(N)


/////   24)
void doubleTable (HashTableOAddr h){
	
	EntryOAdd *new = malloc(sizeof (struct entry) * h->size *2);
	int i,key;
	for (i=0; i<h->size*2; i++) h->table[i]->status =0;
	for (i=0; i<h->size; i++){
		
		if (h->table[i]->status == STATUS_USED){
			ofset=0;
			key = hash (h->table[i]->key, h->size);
			while (new[key+ofset]->status != 0) ofset++;
			new[ofset+key]->key = key;
			new[ofset+key]->status = 1;
			new[ofset+key]->info = h[i]->info;
		}

	}
	h->size*=2;
	h->table = new;
}

/////   25)

//Possibilidades : -> Uma arvore AVL com a struct 
			typedef struct nodo{
				int valor;
				int rep;
				int balFactor;
				struct nodo *esq, *dir;
			}*Avl;
	// T (Nº de ocorrencias) = omega(1),O(log(n))
	// T (Listagem) = N


/////   26)
int minHeapOK (MinHeap h){
	return auxMinH (h->values,h->used,0);
}

int auxMinH (int * arr, int size, int pos){
	if (FDIR(pos) < size){
		if (arr[FESQ (pos)] >  arr[pos] && arr[DIR (pos)] >  arr[pos])
			return auxMinH(arr,size,FESQ (pos)) && auxMinH(arr,size,FDIR(pos));
		
		else return 0;}
	else if (FESQ(pos) < size){
			if (arr[FESQ (pos)] >  arr[pos]) return auxMinH(arr,size,FESQ (pos));
			else return 0;}

	else return 1;

}

/////   27)
HashTable newTable(int hashsize){
	HashTable h = malloc(sizeof(struct hashT));
	h->hashsize = hashsize;
	h->table = malloc(sizeof(struct entry) * hashsize);
	int i=0;
	for (i=0; i<hashsize; h->table[i]=NULL,i++);
	return h;
}



/////   30)
AVL rotateLeft (AVL a){
	a = aux2(a);
	AVL temp= a->right;
	temp->altura --;
	aux(temp->dir);
	a->right = temp->left;
	temp->left = a;
	return temp;

}

AVL aux (AVL a){
	if (a){
		a->altura --;
		a->right= aux(a->right);
		a->left= aux(a->left);
		return a;
	}
	else return NULL;
}

AVL aux2 (AVL a){
	if (a){
		a->altura++;
		a->left = aux(a->left);
		a->right= aux(a->right);
		return a;
	}
	else return NULL;
	
}