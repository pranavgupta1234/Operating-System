// example for thread::join
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

//compilation
//g++ -pthread  threadConcurrency.cpp 

std:: thread :: id main_thread_id = std :: this_thread :: get_id();

void pause_thread(int n){
	std::cout<<"Thread with id :: "<<std :: this_thread :: get_id() <<" generated"<<std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";
}

void doSomeTask(int n){
	std::cout<<"Thread with id :: "<<std :: this_thread :: get_id() <<" generated"<<std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";	
}

int main(){
	std::cout << "Spawning 6 threads...\n";
	std::thread t1 (pause_thread,1);
	std::thread t2 (pause_thread,2);
	std::thread t3 (pause_thread,3);
	std::thread t4 (pause_thread,4);
	std::thread t5 (pause_thread,5);
	std::thread t6 (pause_thread,6);

	std::cout << "Done spawning threads. Now waiting for them to join:\n";

	std::cout<<"Is thread joinable "<<(t1.joinable() ? "Yes" : "No")<<std::endl;
	std::cout<<"Is thread joinable "<<(t2.joinable() ? "Yes" : "No")<<std::endl;
	std::cout<<"Is thread joinable "<<(t3.joinable() ? "Yes" : "No")<<std::endl;		

	//Joining means that the thread who invoked the new thread will wait for the new thread to finish execution, before it will continue its own execution
	//hence All Threads joined is printed only after 3 sec
/*	t1.join();
	t2.join();
	t3.join();
	t4.detach();
	t5.detach();
	t6.detach();

*/

	pause_thread(40);
	std::cout << "All threads joined!\n";
	std::cout<<"Main thread ID :: "<<main_thread_id<<std::endl;


 	//threads t1,t2,t3 are already joined to main thread so they can't ne joined to any other threads
 	//A thread object is not joinable in any of these cases:
    //if it was default-constructed.
    //if it has been moved from (either constructing another thread object, or assigning to it).
    //if either of its members join or detach has been called.

	std::cout<<"Is thread joinable "<<(t1.joinable() ? "Yes" : "No")<<std::endl;
	std::cout<<"Is thread joinable "<<(t2.joinable() ? "Yes" : "No")<<std::endl;
	std::cout<<"Is thread joinable "<<(t3.joinable() ? "Yes" : "No")<<std::endl;	
	std::cout<<"Is thread joinable "<<(t4.joinable() ? "Yes" : "No")<<std::endl;
	std::cout<<"Is thread joinable "<<(t5.joinable() ? "Yes" : "No")<<std::endl;
	std::cout<<"Is thread joinable "<<(t6.joinable() ? "Yes" : "No")<<std::endl;	
	
	return 0;
}
