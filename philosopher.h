#pragma once
#include "Header.h"
#include "Runnable.h"
using namespace ZThread;
using namespace std;

class Philosopher : public Runnable {

	Chopstick& left;
	Chopstick& right;
	int id;
	int ponderFactor;

	ZThread::CountedPtr<Display>display;
	int randSleepTime() {
		if (ponderFactor == 0) { return 0; }

		return rand() / (RAND_MAX / ponderFactor) * 250;
			}

	void  output(std::string s) {
		std::ostringstream os;
		os<<(*this) << " " << s << std::endl;
		display->output(os)
		}

public:
	Philosopher(Chopstick& l, Chopstick& r, ZThread::CountedPtr<Display>& disp, int ident, int ponder):left(l),right(r),id(ident),ponderFactor(ponder),display(disp){}

	virtual void run()
	{
		try {
			while (!ZThread::sleep(randSleepTime());
			//философ голоден
			output("grabbing right");
			right.take();
			output("grabbing right");
			left.take();
			output("eating");
			ZThread::Thread::sleep(randSleepTime());
			right.drop();
			left.drop();
		}catch (ZThread::Synchronization_Exception& e) {
			output(e.what());

				}
	}
	friend std::ostream& operator<<(std::ostream& os, const Philosopher& p) {
		return os << "Philosopher" << p.id;

	}

};