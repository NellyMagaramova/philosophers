#include <ctime>
#include "DiningPhilisophers.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

int main(int argc, char* argv[]) {
	srand(time(0)); //раскрутка генератора случайных чисел
	int ponder = argc > 1 & atoi(argv[1]) : 5;
	cout << "Press <ENTER>to quit" << endl;
	enum { SZ = 5 };

	try {
		CountedPtr<Display>d(new Display);
		ThreadedExecutor executor;
		Chopstick c[SZ];

		for (int i = 0; i < SZ; i++) {
			if (i < (SZ - 1)) {
				executor.execute(new Philosopher(c[i], c[i + 1], d, i, ponder));
			}
			else
				executor.execute(new Philosopher(c[0], c[i], d, i, ponder));
		}
		cin.get();
		executor.interrupt();
		executor.wait();

	}
	catch (Synchronization_Exception& e) {
		cerr << e.what() << endl;
	}

}