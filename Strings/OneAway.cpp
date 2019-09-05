#include<bits/stdc++.h>
using namespace std;
bool OneAway(string s1, string s2)
{
	int l1 = s1.length(), l2 = s2.length();
	if(l1==l2)
	{
		bool flag = true;
		for(int i = 0; i < l1; i++)
		{
			if(s1[i]!=s2[i])
			{
				if(!flag) return false;
				flag = false;
			}
		}
		return true;
	}
	else if(l1>l2)
	{
		if(l1-l2>1) return false;
		int offset = 0;
		for(int i = 0; i < l2; i++)
		{
			if(s1[i+offset]!=s2[i])
			{
				if(offset==1) return false;
				else offset++;
			}
		}
		return true;
	}
	else
	{
		if(l2-l1>1) return false;
		int offset = 0;
		for(int i = 0; i < l1; i++)
		{
			if(s1[i]!=s2[i+offset])
			{
				if(offset==1) return false;
				else offset++;
			}
		}
		return true;
	}
}

int main()
{
	cout<<OneAway("pale", "ple");
	cout<<OneAway("pales", "palsel");
	cout<<OneAway("pale", "bale");
	cout<<OneAway("pale", "bake");
	cout<<OneAway("pale", "bales");
}