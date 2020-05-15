#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a=__builtin_popcount(7);//counts 1's in bin represent
	//__builtin_popcountll(x) for long long
	cout << bitset<8>(12) << endl;
	//bitset<8>(num) convert to binary
	//bitset<4>(n) for 4 bits representation
	
	//a << b -> a.2^b  so 2^x=1 << x     a >> b -> a/2^b
	//__builtin_clz(x) -> leading zeros in x
	//__builtin_ctz(x) -> trailing zeros in x
	string s;
	cin >> s;
	bitset<8> x(s);
	cout << x << endl;
	
	cout << (x>>(1)) << endl;
	//flip() flips bits flip(pos) for pos
	//for any bitwise operation 
	// << construtive(only print)  <<= destructive(changes object)
	// &= |= ^= ~ for and or xor not
	/*for(int i=1;i<100;i++)
	{if(ceil(log(i)/log(3))==floor(log(i)/log(3)))
		{cout << i << endl;
		}
	}*/
	int r=(x&1==1)?printf("odd"):printf("even");
	 return 0;
}

