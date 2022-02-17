#include <iostream>
#include <map>

using namespace std;

int main ()
{
	map<char,int> first;

	//initializing
	first['a']=10;
	first['b']=20;
	first['c']=30;
	first['d']=40;

	map<char, int>::iterator it;
	for(it=first.begin(); it!=first.end(); ++it){
		cout << it->first << " => " << it->second << '\n';
	}
	cout << first.at('a') << endl;
	return 0;
}
