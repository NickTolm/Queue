#include <iostream>
#include <cstdlib>
using namespace std;

const int maxSize = 100; // max size of queue

template <class QType> class Queue{  

	QType q[maxSize]; //array for queue
	int size;
	int putlock, getlock; //indexes for function put() and get()

public:

	Queue(int len){    // constructor queue a certain length
		if (len>maxSize) len = maxSize;
		else if (len <= 0) len = 1;

		size = len;
		putlock = getlock = 0;
	}

	void put(QType data){  //put data in queue
		if (putlock == size){
			cout << "Queue is full\n";
			return;
		}
		putlock++;
		q[putlock] = data;
	}

	QType get(){  //geting data from queue
		if (getlock == putlock){
			cout << "Queue is empty\n";
			return 0;
		}
		getlock++;
		return q[getlock];
	}

};

int main(){


	Queue<int> Q1(10), Q2(10);

	Q1.put(1);
	Q1.put(2);
	Q1.put(3);

	Q2.put(10);
	Q2.put(20);
	Q2.put(300);


	for (int i = 0; i<3; i++){
		cout << Q1.get() << " ";
	}
	cout << endl;

	for (int i = 0; i<3; i++){
		cout << Q2.get() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}