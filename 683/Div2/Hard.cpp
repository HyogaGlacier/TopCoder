#include <bits/stdc++.h>
using namespace std;
class SubtreesCounting{
	public:
	const int mod=1000000007;
	vector<int> edge[100010];
	int cnt[100010],kind[100010];
	bool visited[100010];
	void dfs(int cur){
		visited[cur]=true;
		long long ret=1,sort=1;
		for(int i=0;i<(int)edge[cur].size();i++){
			int to=edge[cur][i];
			if(visited[to])	continue;
			dfs(to);
			ret=(ret*(kind[to]+1))%mod+(cnt[to]*sort)%mod;	ret%=mod;
			sort=(sort*(kind[to]+1))%mod;
		}
		cnt[cur]=ret%mod;	kind[cur]=sort%mod;
		return;
	}
	int sumOfSizes(int n,int a0,int b,int c,int m){
		vector<int> a(n);	a[0]=a0;
		for(int i=1;i<n;i++){
			a[i]=((long long)b*a[i-1]+c)%m;
		}
		for(int i=1;i<n;i++){
			int j=a[i-1]%i;
			edge[j].push_back(i);	edge[i].push_back(j);
		}
		for(int i=0;i<n;i++){
			cnt[i]=kind[i]=1;	visited[i]=false;
		}
		dfs(0);
		int ret=0;
		for(int i=0;i<n;i++)	ret=(ret+cnt[i])%mod;
		return ret;
	}
};
