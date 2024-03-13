#include <iostream>
#include <thread>
#include <chrono>


struct MyShared{
	std::atomic<int> threadId;
	std::atomic<int> reportId;
	std::atomic<double> elapsedTime;
};


//Function to read from shared memory and report
void readerFunction (MyShared* sharedMemory){
	while (true){
		
	}
}


int main(void)
{
	std::cout << "I am a reader" << std::endl;
}
