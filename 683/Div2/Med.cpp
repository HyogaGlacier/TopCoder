#include <bits/stdc++.h>
using namespace std;
class MoveStonesEasy{
	public:
	int get(vector<int> a,vector<int> b){
		int sum=0;
		for(int i:a)	sum+=i;
		for(int i:b)	sum-=i;
		if(sum!=0)	return -1;
		int tmp=0,ret=0;
		int n=a.size();
		for(int i=0;i<n;i++){
			int dif=a[i]-b[i];
			tmp+=dif;
			ret+=abs(tmp);
		}
		return ret;
	}
};
