#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
#define prv for(int i:a)cout << i << " "
#define nl cout << endl
inline int myrand(int j){ return rand()%j;}
int main()
{
	srand(unsigned(time(0)));
	vector<int> a={1,2,3,4};
	pair<int,char> x;
	/*a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);*/
	x.first=1;//mak_pair(,)
	x.second='a';
	x=make_pair(2,'x');
	cout << x.first << "," << x.second;;
	//ITERATORS - begin(),end(),rbegin(),rend()
	//a.size() a.resize(n) bool x=a.empty()(returns true if empty(size 0) a.clear()-removes all elements and size will be zero
	//acess - a[2],a.at(2),a.front(),a.back()
	//a.assign(a.begin(),a.end()-3);a.assign(new size,value);a.(it1,it2)
	//push_back(n) pop_back() a.insert(it1,it2,it3)  
	nl;
	prv;
	cout << binary_search(a.begin(),a.end(),5);
	return 0;
}
