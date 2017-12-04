#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <process.h>
#include <mutex>

#include <condition_variable>

class Runnable {
public:
	virtual void run() = 0;
	virtual  ~Runnable(){}

};
