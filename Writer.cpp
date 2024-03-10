#include <iostream>


struct MyShared{
	...;
};

class WriterThread {
public:
    // Constructor for WriterThread
    WriterThread(int waitTime) : flag(false), waitTime(waitTime) {}

    // Member variables
    bool flag;
    int waitTime;
};

int main(void)
{
	std::cout << "I am a Writer" << std::endl;
	
	////////////////////////////////////////////////////////////////////////
	// This is a possible starting point for using threads and shared memory. 
	// You do not have to start with this
	////////////////////////////////////////////////////////////////////////
	Shared<MyShared> shared("sharedMemory", true); //This is the owner of sharedMamory
	WriterThread* thread1 = nullptr;
    std::string userInput;
	while(true){
		
		//create thread using user input
		std::cout << "Would you like to create a new thread? (yes/no): ";
        std::cin >> userInput;
        if (userInput != "yes")
            break;

        int waitTime;
        std::cout << "Enter the wait time for the new thread in seconds: ";
        std::cin >> waitTime;

        thread1 = new WriterThread(waitTime); // Create new WriterThread object
        // Launch thread with given wait time
        std::thread([&]() {
            std::this_thread::sleep_for(std::chrono::seconds(waitTime));
            thread1->flag = true;
            delete thread1;
        }).detach();

	}
	//example for one thread thread1
	thread1->flag= true;
	delete thread1;
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
