#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <atomic>

struct MyShared{
	std::atomic<int> threadId;
	std::atomic<int> reportId;
	std::atomic<double> elapsedTime;
};

void WriterThread(MyShared* sharedMemory, int threadId, int sleepTime) {
	int reportId=0
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(sleepTime));

		//Update shared memory
		sharedMemory->threadId = threadId;
		sharedMemory->reportId = ++reportId;

		//Calculate time difference
		double timePast = sleepTime * reportId;
		sharedMemory->elapsedTime = timePast;
	}
	
};

int main()
{
	std::cout << "I am a Writer" << std::endl;
	
	////////////////////////////////////////////////////////////////////////
	// This is a possible starting point for using threads and shared memory. 
	// You do not have to start with this
	////////////////////////////////////////////////////////////////////////
	char userInput;
	MyShared sharedMemory;
	std::vector<std::thread> threads
	while(true){
		
		//create thread using user input
		std::cout << "Would you like to create a new thread? (yes/no): ";
        std::cin >> userInput;
        if (userInput == "yes"){
			int waitTime;
        	std::cout << "Enter the wait time for the new thread in seconds: ";
        	std::cin >> waitTime;
			threads.emplace_back(threadFunction, &sharedMemory, threads.size() + 1, sleepTime);

		}
	}while (userInput=='yes');

	//Join all threads
	for(auto& thread : threads){
		thread.join();
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////
// This is a possible starting point for using threads and shared memory. 
// You do not have to start with this
////////////////////////////////////////////////////////////////////////
/*class WriterThread : public Thread{
	public:
		int 	threadNum;
		bool	flag;
		
		WriterThread(int in):Thread(8*1000){
			this->threadNum = in; //or whatever you want/need here
		}

		virtual long ThreadMain(void) override{
			...
			//declare shared memory var so this thread can access it
			Shared<MyShared> sharedMemory ("sharedMemory");
			while(true)
			{
				//write to shared memory
				...  
				if(flag){//Exit loop to end the thread
					break;
				}
			}
		}
};
*/
