#include<bits/stdc++.h>
using namespace std;
string compress(string s)
{
	string final;
	char prev = '@';
	int count =0;
	for(char a: s)
	{
		if(a==prev) count++;
		else 
		{
			if(count > 0)
			{
				final+=prev;
				final+=to_string(count);
			}
			prev = a;
			count = 1;
		}
	}
	if(count > 0)
	{
		final+=prev;
		final+=to_string(count);
	}
	if(s.length()<=final.length()) return s;
	return final;
}
int main()
{
	cout<<compress("aa");
	cout<<compress("aaaa");
	cout<<compress("abc");
}