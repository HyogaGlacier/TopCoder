#include <bits/stdc++.h>
using namespace std;
class EqualSubstrings2{
	public:
	int get(string s){
		int ret=0;
		for(int i=0;i<s.size();i++){
			for(int j=i+1;j<s.size();j++){
				int cnt=0;
				while(j+cnt<s.size()&&i+cnt<j&&s[i+cnt]==s[j+cnt])	cnt++;
				ret+=cnt;
			}
		}
		return ret;
	}
};
