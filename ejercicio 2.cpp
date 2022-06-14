#include<iostream>
#include<cstdlib>
using namespace std;

struct nodo{
    int nro;
    struct nodo *sgte;
};

typedef struct nodo *Puntero;

class Pila{
    public:
        Pila(void);
        void Apilar(int );
        int Desapilar(void );
        void Cima(void);
        void MostrarPila(void);
        bool PilaVacia(void);

    private:
        Puntero cima;

};
Pila::Pila(void){
    cima=NULL;
}

bool Pila::PilaVacia(void){
    if(cima==NULL)
        return true;
    else
        return false;
}


void Pila::Apilar(int x){

    Puntero p_aux;
    p_aux=new(struct nodo);
    p_aux->nro=x;
    p_aux->sgte=cima;
    cima=p_aux;

}


void Pila::MostrarPila(void){
    Puntero p_aux;
    p_aux=cima;

    while(p_aux!=NULL){
        cout<<"\t "<<p_aux->nro<<endl;
        p_aux=p_aux->sgte;
    }
}


int Pila::Desapilar(void){
    int x;
    Puntero p_aux;
    if(cima==NULL)
        cout<<"\n\n\tPila Vacia...!!";
    else{
        p_aux=cima;
        x=p_aux->nro;
        cima=cima->sgte;
        delete(p_aux);
    }
    return x;
}

int main(void ){


    Pila pila;
    int x;
    int opcion;

    do
    {
        cout<<" \t  1. APILAR "<<endl;
    	cout<<" \t  2. MOSTRAR PILA "<<endl;
    	cout<<" \t 3. DESAPILAR "<<endl;
   		cout<<"\t Ingrese opcion: ";
		cin>> opcion;

        switch(opcion)
        {
            case 1: cout<< "\n\t INGRESE EL NUMERO QUE QUIERE APILAR: "; cin>> x;
                    pila.Apilar(x);
                    cout<<"Numero " << x << " apilado";
                    break;


            case 2:
                    cout << "MOSTRAR PILA\n\n";
                    if(pila.PilaVacia()!=true)
                        pila.MostrarPila(  );
                    else
                        cout<<"Pila vacia"<<endl;
                    break;
                    
			case 3:
                    if(pila.PilaVacia()==true)
                        cout<<"\n\n\tPila Vacia....";
                    else{
                        x = pila.Desapilar( );
                        cout<<"\n\n\tNumero "<<x<<" Eliminado de la pila\n";
                        }
                    break;                    

         }

        cout<<endl<<endl;
        system("pause");

    }while(opcion!=4);

return 0;
}