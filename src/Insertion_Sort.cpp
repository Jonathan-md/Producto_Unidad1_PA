#include<iostream>
using namespace std;

int InsercionDir(int A[],int n){
	int aux,k;
	for(int i=2;i<=n;i++){
		aux=A[i];
		k=i-1;
		while(k>0 && aux<A[k]){
			A[k+1]=A[k];
			k=k-1;
		}
		A[k+1]=aux;
	}
	return 0;
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
	InsercionDir(A,n);
	
	cout<<"\nNumeros ordenadas: ";
	for(int i=1;i<=n;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}
