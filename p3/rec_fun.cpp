/* Xiaohong Zhu
 * CS211 Assignment 3
 * 11/9/2017 */
#include <string>
#include <iostream>
using namespace std;

void triangle (ostream& outs, unsigned int m, unsigned int n)
{
	if (m <= n) 
	{
		for (int i=0; i < m; i++)
			outs << "*";
		outs << endl;
		triangle(cout, m+1, n);
		for (int j=0; j < m; j++)
			outs << "*";
		outs << endl;
	}
}

void numbers (ostream& outs, const string& prefix, unsigned int levels)
{
	if (levels == 0) outs << prefix << endl;
	else {
		string s;
		char c;
	for (int i=1; i<10; i++)
		{
			c = i + '0';
			s = (prefix + c) + '.';
			numbers (cout, s, levels-1);
		}
	}
}

bool bears (int n)
{
	if (n == 42) return true;
	if (n < 42) return false;
	if (n%5 == 0)
		if (bears(n-42)) return true;
	if (n%2 == 0) 
		if (bears(n/2)) return true;
	if ((n%3 == 0 || n%4 == 0))
	{
		if ( ((n%100)/10)*(n%10) <= 0) return false;
		if (bears(n-(((n%100)/10)*(n%10)))) return true;
	}
	return false;
}

void pattern (ostream& outs, unsigned int n, unsigned int i)
{
	if(n==1) {
		for (int k = 0; k < i; k++) outs << ' ';
		outs << "*" <<endl;
	}
	else { 
		pattern (outs, n/2, i);
		for (int k = 0; k < i; k++) outs << ' ';
		for (int k = 0; k < n; k++) outs << "* ";
		outs << endl;
		pattern (outs, n/2, i+n);
	}
}

int main()
{
	//testing the functions
	triangle(cout, 3, 5);
	string str = "CHAU";
	numbers(cout, str, 2);
	cout<<bears(250)<<endl;
	cout<<bears(500)<<endl;
	cout<<bears(1000)<<endl;
	pattern(cout,8,4);
        cout<<endl;
        pattern(cout,16,4);
        return 0;
}

