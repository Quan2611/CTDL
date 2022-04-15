#include <iostream>
using namespace std;
template <class T>
class BSTree{
	private:
		struct Node
		{
			T data;
			Node* pLeft;
			Node* pRight;
		};
		Node *root;
		void Add(Node* &t, T x)
		{
			if(t==NULL)
			{
				Node *p= new Node;
				p->data =x;
				p->pLeft =NULL;
				p->pRight=NULL;
				t=p;
			}
			else
			{
				if(t->data > x)
				{
					Add(t->pLeft,x);
				}
				else if(t->data<x)
				{
					Add(t->pRight,x);
				}
			}
		}
		bool Search(T a, Node *p)
		{
			if (p!= NULL)
			{
				if (a == p->data)
					return true;
				if (a<p->data)
					return Search(a, p->pLeft);
				else
					return Search(a, p->pRight);
			}
			else 
				return false;
		}
		void TimNodeTheMang(Node* &X, Node* &Y)
		{
			if(Y->pLeft != NULL)
			{
				TimNodeTheMang(X, Y->pLeft);
			}
			else
			{
				X->data= Y->data;
				X=Y;
				Y=Y->pRight;
			}
		}
		void Delete(Node* &p, T x)
		{
			if(p==NULL)
			{
				return;
			}
			else
			{
				if(x < p->data)
				{
					Delete(p->pLeft,x);
				}
				else if(x > p->data)
				{
					Delete(p->pRight,x);
				}
				else 
				{
					Node* X=p;
					if(p->pLeft==NULL)
					{
						p=p->pRight;
					}
					else if(p->pRight==NULL)
					{
						p=p->pLeft;
					}
					else
					{
						TimNodeTheMang(X,p->pRight);
					}
					delete X;
				}
			}
		}
		void printPost(Node* p)
		{
			if (p == NULL)
				return;
			printPost(p->pLeft);
			printPost(p->pRight);
			cout << p->data << " ";
		}
		T HeightTree(Node* p)
		{
			if(p == NULL){
				return 0;
			}
			T a = HeightTree(p->pLeft);
			T b = HeightTree(p->pRight);
			if (a>b)
				return a+1;
			return b+1;
		}
		void DeleteTree(Node* p)
		{
			if(p != NULL)
			{
				DeleteTree(p->pLeft);
				DeleteTree(p->pRight);
				delete p;
			}
		}
	public:
		BSTree() 
		{ 
			root = NULL; 
		}
		~BSTree()
		{
			DeleteTree(root);
		}
		void Add(T a)
		{
			Add(root,a);
		}
		bool Search(T a)
		{
			return Search(a, root);
		}
		void Delete(T x)
		{
			Delete(root,x);
		}
		void printPost()
		{
			printPost(root);
		}
		int HeightTree()
		{
			return HeightTree(root);
		} 
};


int main() {
  BSTree<int> a;
	a.Add(2);
	a.Add(5);
	a.Add(6);
	a.Add(-3);
	a.Add(0);
	a.Add(1);
	a.Add(8);
	a.Add(-5);

	int x;
	cout<<"Nhap node can tim: ";
	cin>>x;
	if(a.Search(x)==0)
	{
		cout<<"Khong Tim Thay\n";
	}
	else
	{
		cout<<"Co Ton Tai\n";	
	}

	int b;
	cout<<"Nhap gia tri node can xoa: ";
	cin>>b;
	a.Delete(x);

	cout<<"In hau to: ";
	a.printPost();
	cout<<endl;

	cout<<"Chiều cao cây: "<<a.HeightTree()<<endl;

	return 0;


} 