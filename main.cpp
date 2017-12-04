#include <ctime>
#include "DiningPhilisophers.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

int main(int argc, char* argv[]) {
	srand(time(0)); //раскрутка генератора случайных чисел
	int ponder = argc > 1 & atoi(argv[1]) : 5;
	cout << "Press <ENTER>to quit" << endl;
	enum{SZ=5};

	try {
		CountedPtr<Display>d(new Display);
		ThreadedExecutor executor;
		Chopstick c[SZ];

		for (int i = 0; i < SZ; i++) {
			executor.execute(new Philosopher(c[i], c[(i + 1) % SZ], d, i, ponder));
		}
		cin.get();
		executor.interrupt();
		executor.wait();

	}
	catch (Synchronization_Exception& e) {
		cerr << e.what() << endl;
	}

}