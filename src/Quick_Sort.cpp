#include<iostream>
using namespace std;

int Reduce(int A[],int inicio,int final){
	int izq,der,pos,cen,aux;
	izq=inicio;
	der=final;
	pos=izq;
	cen=1;
	while(cen==1){
		cen=0;
		while(A[pos]<=A[der] && pos!=der){
			der--;
		}
		if(pos!=der){
			aux=A[pos];
			A[pos]=A[der];
			A[der]=aux;
			pos=der;
			while(A[pos]>=A[izq] && pos!=izq){
				izq++;
			}
			if(pos!=izq){
				aux=A[pos];
				A[pos]=A[izq];
				A[izq]=aux;
				pos=izq;
				cen=1;
			}
		}
		if(pos-1>inicio){
			Reduce(A,inicio,pos-1);
		}
		if(pos+1<final){
			Reduce(A,pos+1,final);
		}
	}
	return 0;
}

int QuickSort(int A[],int n){
	return Reduce(A,1,n);
}

int main(){
	int A[90],n;
	
	cout<<"Cuantos de numeros va ingresar?: ";
	cin>>n;
	cout<<"\nIngrese los numeros a ordenar: "<<endl;
	for(int i=1;i<=n;i++){
		cout<<" ";
		cin>>A[i];
	}
	QuickSort(A,n);
	
	cout<<"\nNumeros ordenadas: ";
	for(int i=1;i<=n;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}


