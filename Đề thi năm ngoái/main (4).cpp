#include <iostream>
#include <string>
using namespace std;
string Reverse(string s, int N)
{
	string temp(1, s[N-1]);
	if(N==1)
	{
		return temp;
	}
	else
	{
		return temp+ Reverse(s,N-1);
	}
}
int main() {
  string a;
	a="pots&pans";
	cout<<a<<endl;
	cout<<"Chuoi dao nguoc: ";
	cout<<Reverse(a,a.length());
}