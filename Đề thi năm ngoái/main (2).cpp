#include <iostream>
using namespace std;
template <class T>
class Stack
{
private:
	struct Node{
		T data;
		Node* next;
	};
	Node* top;
public:
	Stack()
  {
    top = NULL;
  };
	~Stack()
	{
  	Node *q = top;
    while(q!= 0 ) 
		{
			Node *next = q->next;
			delete q;
			q = next;
    }
    top = NULL;
	};
	void Push(T value)
  {
    Node* p = new Node;
    p->data = value;
    p->next = top;
    top = p;
  };
	T Pop()
  {    
    T value = top->data;
    Node* p = top;
    top = top->next;
    delete p;
    return value;
  };
	T getTop() const
  {
    return top->data;
  };
	bool isEmpty() const
  {
    return top == 0;
  };
};

int main() {
  Stack<float> a;
	float arr[5]={4.1,7.9,1.2,34.3,5.2};
	for(int i=0; i<5; i++)
	{
		a.Push(arr[i]);
	}
	cout<<"<ang sau khi dao nguoc la: \narr[5]= { ";
	for(int i=0; i<5; i++)
	{
		arr[i]=a.Pop();
		cout<<arr[i]<<", ";
	}
	cout<<"}";

} 