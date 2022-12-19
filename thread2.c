#include <iostream>
#include <sstream>
#include <string>
#include<thread>

using namespace std;

int main()
{
		auto printMessage = [](const string& message){
				cout << message << endl;
		};

		thread thread(printMessage, "Meeeade from a child thread.");
		printMessage("waiting the cjiled thread..");
		thread.join();

		return 0;
}

