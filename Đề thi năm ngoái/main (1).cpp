#include <iostream>
using namespace std;
template <class T>
class List
{
private:
	struct Node 
	{
		T data;
		Node *next;
	};
	Node *head;
public:
	List()
	{
		head=NULL;
	}	
	void Insert (T value, int pos)
	{
		Node *n=new Node;
		n->data=value;
		if(pos==1)
		{
			n->next=head;
			head=n;
		}
		else
		{
			Node *p=head;
			for(int i=1; i<pos-1; i++)
			{
				p=p->next;
			}
			n->next=p->next;
			p->next=n;
		}
	}
	void Delete(int pos)
	{
		if(pos==1)
		{
			Node *p=head;
			head=head->next;
			delete p;
		}
		else
		{
			Node *n=head;
			for(int i=1; i<pos-1; i++)
			{
				n=n->next;
			}
			Node *q=n->next;
			n->next=n->next->next;
			delete q;
		}
	}
	T GetItem(int pos)
	{
		Node *p=head;
		for(int i=1;i<pos; i++)
		{
			p=p->next;
		}
		return p->data;
	}
	friend ostream& operator<<(ostream& out, List<T> v)
	{
		Node *p=v.head;
		while(p!=0)
		{
			out<<p->data<<" ";
			p=p->next;
		}
		out<<endl;
		return out;
	}
};
int main() {
  List<int> a;
	a.Insert(5,1);
	a.Insert(3,2);
	a.Insert(12,3);
	a.Insert(1,4);
	cout<<a;

	a.Delete(3);
	cout<<a;

	cout<<a.GetItem(2)<<endl;
} 