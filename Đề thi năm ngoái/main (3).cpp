#include <iostream>
using namespace std;
template <class T>
class Queue
{
private:
	T a[100];
	int N;
public:
	Queue()
  {
    N=0;
  }
  void EnQueue(T value)
  {
   a[N++]=value;
  };
  T DeQueue()
  {
		T value=a[0];
		for(int i=0; i<N; i++)
		{
			a[i]=a[i+1];
		}
		N--;
    return value;
  };
  T getFirst() const
  {
    return a[0];
  };
	T getTail() const
	{
		return a[N-1];
	}
  bool isEmpty() const
  {
    return N == 0;
  };
	bool isFull() const
	{
		return N==100;
	};


};

int main() {
  Queue<int> a;
	a.EnQueue(6);
	a.EnQueue(8);
	a.EnQueue(3);
	a.EnQueue(9);
	a.EnQueue(23);
	cout<<"Check Full: "<<a.isFull()<<endl;

	cout<<"Gia tri mơi lay ra khoi queue: "<<a.DeQueue()<<endl;
	cout<<"Phan tu dau: "<<a.getFirst()<<endl;
	cout<<"Phan tu cuoi: "<<a.getTail()<<endl;


	while(!a.isEmpty())
	{
		cout<<a.DeQueue()<<" ";
	}
} 