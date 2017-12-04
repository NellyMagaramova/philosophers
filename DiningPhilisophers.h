#pragma once
#include "Header.h"
#include "Runnable.h"

using namespace std;

class Chopstick {
	mutex lock;
	condition_variable  notTaken;
	bool taken;

public:
	Chopstick(): notTaken(lock),taken(false){}

	void take() {
		std::lock_guard<std::mutex> g(lock);

		while (taken) { 
			notTaken.wait; 
		}
		taken = true;
				}

	void drop() {
		lock_guard<std::mutex>g(lock);
		taken = false;
		notTaken.notify_one; //notify_one активируется, 
		//когда один из потоков, которые в ожидании переменной условия
		//используется вместо signal()
	
	}
};



