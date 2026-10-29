#include<iostream>
using namespace std;

int ShellSort(int A[],int n){
	int k,aux,j;
	k=n+1;
	while(k>1){
		k=k/2;
		for(int i=k+1;i<=n;i++){
			aux=A[i];
			j=i;
			while(j-k>=1 && A[j-k]>aux){
				A[j]=A[j-k];
				j=j-k;
			}
			A[j]=aux;
		}
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
	ShellSort(A,n);
	
	cout<<"\nNumeros ordenadas: ";
	for(int i=1;i<=n;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}

