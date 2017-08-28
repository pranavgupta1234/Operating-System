#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;												//mutex for critical section

void print_block(int n,char c){

	mtx.lock();

	for(int i=0 ; i<n ; i++){
		cout<<c;
	}

	cout<<endl;
	mtx.unlock();
}

void print_block_uncertain(int n,char c){

	for(int i=0 ; i<n ; i++){
		cout<<c;
	}

	cout<<endl;

}

int main(){
	

	// gives jumbled output	
	//thread t1(print_block_uncertain,100,'*');
	//thread t2(print_block_uncertain,100,'#');

	//first occurence may be uncertain but all same char are together
	thread t1(print_block,100,'*');
	thread t2(print_block,100,'#');

	t1.join();
	t2.join();

	return 0;
}