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
		//Read Shared memory
		std::cout << "Thread ID: " <<sharedMemory->threadId << ", Report ID: " 
				  << sharedMemory->reportId << ", Elapsed Time: " 
                  << sharedMemory->elapsedTime << " seconds" << std::endl;
			//Time delay before reading again
			std::this_thread::sleep_for(std::chrono::Seconds(1));

	}
}


int main(void)
{
	std::cout << "I am a reader" << std::endl;

	MyShared sharedMemory;

	//Start Reader thread
	std::thread readerThread(readerFunction, &sharedMemory)

	//Keep reader running for 10 seconds
	std::this_thread::sleep_for(std::chrono::seconds(10));

    // Join reader thread
    readerThread.join();

    return 0;
}
