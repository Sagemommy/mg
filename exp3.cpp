#include<iostream>

using namespace std;

class CircularQueue {
  	private:
  		int front;
  		int rear;
  		int arr[5];
  		int itemCount;

  	public:
  		CircularQueue() 
		{
      		itemCount = 0;
      		front = -1;
      		rear = -1;
      		for (int i = 0; i < 5; i++) 
        		arr[i] = 0;
      	}
    
  	bool isEmpty();
  	bool isFull(); 
  	void enqueue(int val); 
  	int  dequeue(); 
  	int  count();
  	void display(); 
};

int main() 
{
  	CircularQueue q1;
  	int value, option;

  	do{
    	cout<<"\n ***************************** Operations on Queue**************************************\n \n";
    	cout << "\t1. Enqueue()" << endl;
    	cout << "\t2. Dequeue()" << endl;
   	cout << "\t3. isEmpty()" << endl;
    	cout << "\t4. isFull()" << endl;
    	cout << "\t5. count()" << endl;
    	cout << "\t6. display()" << endl;
    	cout << "\n\nWhat operation do you want to perform?(Enter 0 for exit) :  " ;
    	cin >> option;

    	switch (option) 
		{
    		case 0:
      			break;
    		case 1:
      			cout <<"\n******************************ENQUEUE OERATION ******************************"; 
      			cout<<"\n\nEnter an item to Enqueue in the Queue :  ";
      			cin >> value;
      			q1.enqueue(value);
      			break;
    		case 2:
      			cout <<"\n\n******************************DEQUEUE OERATION ******************************" ; 
      			cout<<"\nDequeued Value : " << q1.dequeue() << endl;
      			break;
   		case 3:
      			if (q1.isEmpty())
        			cout << "Queue is Empty" << endl;
      			else
        			cout << "Queue is not Empty" << endl;
      			break;
    		case 4:
      			if (q1.isFull())
        			cout << "Queue is Full" << endl;
      			else
        			cout << "Queue is not Full" << endl;
      			break;
    		case 5:
      			cout << "\n******************************Count Operation ******************************";
      			cout<<"\n\nCount of items in Queue : " << q1.count() << endl;
      			break;
    		case 6:
      			cout << "****************************** Elements Present in Circular Queue****************************** \n\n";
      			q1.display();
      			break;
    		default:
      			cout << "Enter Proper Option number " << endl;
    	}

  	} while (option != 0);

  	return 0;
}

//check queue is empty or not
bool CircularQueue::isEmpty()
	{
    	if (front == -1 && rear == -1)
      		return true;
    	else
      		return false;
  	}

//check queue is full or not
bool CircularQueue::isFull()
	{
    	if ((rear + 1) % 5 == front)
      		return true;
   	else
      		return false;
  	}
  	
//fill queue from rear
void CircularQueue::enqueue(int val)
  	{
    	if (isFull()) 
		{
 	    	cout << "Queue full" << endl;
   		  	return;
    	} 
		else if (isEmpty()) 
		{
     		rear = 0;
      		front = 0;
     		arr[rear] = val;
    	} 
    	
		else 
		{
      		rear = (rear + 1) % 5;
      		arr[rear] = val;

   		}
    
    	itemCount++;

  	}

//pop element from front	
int CircularQueue::dequeue()
	{
    	int x = 0;
    	if (isEmpty()) 
		{
      		cout << "Queue is Empty" << endl;
      		return x;
   	 	} 
   	 	
		else if (rear == front) 
		{
      		x = arr[rear];
      		rear = -1;
      		front = -1;
      		itemCount--;
      		return x;
    	} 
		
		else 
		{
      		cout << "front value: " << front << endl;
      		x = arr[front];
      		arr[front] = 0;
      		front = (front + 1) % 5;
      		itemCount--;
      		return x;
    	}
  	}

//count total number of element in queue
int CircularQueue::count()
  	{
   		return (itemCount);
 	}

//display element in queue
void CircularQueue::display()
	{
    	cout << "All values in the Queue are - " << endl;
    	for (int i = 0; i < 5; i++) 
      		cout << arr[i] << "  ";
    
	}

