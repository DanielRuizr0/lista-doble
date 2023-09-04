#include <iostream>

using namespace std;

struct nodo{
	int nro;
	struct nodo *sgte;
	struct nodo *tras;
} *pri, *ult;
typedef struct nodo * Tlista;

void insertar(){
	Tlista q;
	q=new (struct nodo);
	cout << "Ingresar dato";
	cin>>q->nro;
	
	if(pri == NULL){
		pri=q;
		pri->sgte = NULL;
		pri->tras = NULL;
		ult = pri;
	}else{
		ult->sgte = q;
		q->sgte = NULL;
		q->tras =ult;
		ult = q;
    }
}
void mosListaDow(){
	Tlista q;
	q=new(struct nodo);
	q= ult;
	
	while(q != NULL){
		cout<<q->nro<<"-";
		q = q->tras;
	}
}
void mosListaUp(){
	Tlista q;
	q=new(struct nodo);
	q= pri;
	
	while(q != NULL){
		cout<<q->nro<<"-";
		q = q->sgte;
	}
}

int main(){
	int op;
	do{
		cout<<"Menu\n";
		cout<<"1. Ingresar datos\n";
		cout<<"2. Mostrar lista primero\n";
		cout<<"3. Mostrar lista ultimo\n";
		cout<<"4. Salir";
		switch(op)
			case 1:
				insertar();
			break;
			case 2:	
				mosListaUp();
			break;
			case 3:
				mosListaDow();
			break;
	}while(op!=4);
	return 0;
}
