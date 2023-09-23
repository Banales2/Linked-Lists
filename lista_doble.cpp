#include <iostream>
using namespace std;
void agregar(int);

struct Node
{
    int id;
    Node *ant;
    Node *sig;
};

class ListaDoble{
private:
Node *I,*F,*T,*N;

public:
    ListaDoble(): I(NULL){}
    void create(int);
    Node* read(int);
    void update(int, int);
    void del(int);
    void presentar_I();
    void presentar_F();
};

void ListaDoble::create(int x){
    T=new Node();
    T->id=x;
    T->sig=NULL;
    T->ant=NULL;

    if(I==NULL){
        I=T;
        F=T;
    } else if(I->id>T->id){
        I->ant = T;
        T->sig = I;
        I = T;
    } else if(T->id>F->id){
        F->sig = T;
        T->ant = F;
        F = T;
    } else if(T->id>I->id && T->id<F->id){
        N=I;
        while (N->id < T->id){
            N = N->sig;
        }
        T->ant = N->ant;
        T->sig = N;
        N->ant = T;
        N = T->ant;
        N->sig = T;
    }
}

Node* ListaDoble::read(int x){
    T=I;

    if(I==NULL){
        cout<<"Lista vacia"<<endl;
    }
    while (T != NULL && T->id != x){
        T = T->sig;
    }
    
    if(T == NULL){
        cout<<"Dato no encontrado"<<endl;
    }
    return T;
}

void ListaDoble::del(int busq){
    T=read(busq);

    if (T == NULL){
        cout<<"No se pudo completar la operacion"<<endl;
        return;
    }
    N = T->ant;
    N->sig = T->sig;
    N = T->sig;
    N->ant = T->ant;
    delete T;
}

void ListaDoble::update(int x, int mod){
    del(x);
    create(mod);
}

void ListaDoble::presentar_I(){
    T=I;
    while (T!=NULL){
        cout<<"ID: "<<T->id<<endl;
        T=T->sig;
    }
}

void ListaDoble::presentar_F(){
    T=F;
    while (T!=NULL){
        cout<<"ID: "<<T->id<<endl;
        T=T->ant;
    }
}


int main(){
    ListaDoble Lista;
    Node *A;
    for (int i = 1; i < 10; i++){
        Lista.create(i*10);
    }
    Lista.create(1);
    Lista.create(100);
    Lista.create(55);
    cout<<"Presentar por el Inicio"<<endl;
    Lista.presentar_I();
    cout<<"Presentar por el Final"<<endl;
    Lista.presentar_F();
    A = Lista.read(50);
    cout<<A->id<<endl;
    Lista.del(50);
    cout<<"Presentar Lista con el dato 50 eliminado"<<endl;
    Lista.presentar_F();
    Lista.update(30,35);
    cout<<"Presentar Lista con el valor 30 cambiado a 30"<<endl;
    Lista.presentar_F();
    return 0;
}
