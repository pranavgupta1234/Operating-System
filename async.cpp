#include <iostream>
#include <future>						//std::async  std::future

using namespace std;

bool isPrime(int x){

	cout<<"Ongoing computation..."<<endl;
	for(int i=2 ; i<x ; i++){
		if(x%i == 0){
			return false;
		}
	}

	return true;
}

int sum(int a,int b){
	return a+b;
}

int main(){

	//template to store async call result
	std::future<bool> asyncallres = async(isPrime,313222313);

	cout<<"Checking primeness of the given number 313222313"<<endl;

	int sum = 0;

	for(int i=0 ; i<100000000; i++){
		sum += i;
	}
	cout<<sum<<endl;

	bool p = asyncallres.get();

	cout<<(p ? "Prime" : "Not Prime")<<endl;


	return 0;
}