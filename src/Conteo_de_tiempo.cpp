#include<chrono>
#include<iostream>
using namespace std;

int main(){
	chrono::steady_clock::time_point begin=chrono::steady_clock::now();
	for(int i=1;i<10000; i++){
		//Espera ocupada
	}
	chrono::steady_clock::time_point end=chrono::steady_clock::now();
	cout<<"Time difference = ";
	cout<<chrono::duration_cast<chrono::milliseconds>(end - begin).count()<<"[ms]"<<endl;
	cout<<"Time difference = ";
	cout<<chrono::duration_cast<chrono::microseconds>(end - begin).count()<<"[us]"<<endl;
	cout<<"Time difference = ";
	cout<<chrono::duration_cast< chrono::nanoseconds>(end - begin).count()<<"[ns]"<<endl;
}
