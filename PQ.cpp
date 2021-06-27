
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <ctime>

using namespace std;

//make the structure
class PRecord {

	//holds priority and data item
public:
	int priority;
	int item;
	PRecord* next;

};

//make the queue
class queue
{
	PRecord* temp;
	PRecord* front;
	int count;
	

public:
	//intialize to Null
	queue();

	void dequeue();
	void enqueue(int x, int prio);
	bool isEmpty();

};

//makes a queue of the specified size
queue::queue()
{
	
	front = NULL; //initialize the front to be null

}

//removes element from the queue in a FIFO fashion
void queue::dequeue()
{

	if (!isEmpty()) {
		//front of the queue is removed
		temp = front;
		front = front->next;
		cout << temp->item;
		cout << " ";
		delete temp;
	}
	else {
		cout << "Queue is empty\n";
	}
	
}

bool queue::isEmpty() {

	//if the queue is not empty or not
	
		return front == NULL;
	
}

//adds specified item to the queue
void queue::enqueue(int x, int prio)
{
	PRecord *q;
	temp = new PRecord;
	temp->item = x;
	temp->priority = prio;

	bool flag = -1;


	/*if the priority is greater (smaller number) than the front element
	place it there*/
	if (isEmpty() || prio < front->priority) {

		flag = true;

	}
	/*Otherwise, check the next element. if the priority is higher than the new element
	keep moving down the queue.*/
	else {
		flag = false;
	}

	if (flag) {
		temp->next = front;
		front = temp;
	}
	if (!flag) {
		q = front;

		while (q->next != NULL && q->next->priority <= prio) {

			q = q->next;

		}

		temp->next = q->next;
		q->next = temp;
	}

	if (flag == -1) {
		cerr << "problem with code or input or something";
	}
}

int main()
{
	int val; //user specified value in the queue
	int prio; //user specified priority of the element

	queue q;
	//ran out of time to implement time
	/*
	time_t current_time;
	current_time = time(NULL);*/

	//loop 3 times 
	for (int i = 0; i < 3; i++) {

		cout << "please enter an integer value:\n";
		cin >> val;

		cout << "please enter an integer priority for the value:\n";
		cin >> prio;

		q.enqueue(val, prio);
	}

	//demo that it prints in the proper order
	cout << "Now see the elements leave the queue: \n";

	for (int i = 0; i < 3; i++) {

		 q.dequeue(); 

	}

	return 0;
}