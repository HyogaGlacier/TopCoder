#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef complex<ld> compd;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define srep(i, a, n) for (int i = (int)a; i < (int)n; i++)
#define REP(i, n) for (int i = 0; i <= (int)n; i++)
#define SREP(i, a, n) for (int i = (int)a; i <= n; i++)
#define rrep(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define RREP(i, n) for (int i = (int)n; i >= 0; i--)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define mt make_tuple
#define fst first
#define scn second
#define bicnt(x) __builtin_popcount(x)
#define gcd(a, b) __gcd(a, b)
const double eps = 1e-13;

class Deadfish
{
	const int lim = 10000000;
	int dp[10000000];
	int sorted(int x)
	{
		if (x == 0)
			return 0;
		vint l;
		while (x > 0)
		{
			l.push_back(x % 10);
			x /= 10;
		}
		sort(all(l));
		reverse(all(l));
		x = 0;
		for (int i = 0; i < l.size(); i++)
			x = x * 10 + l[i];
		return x;
	}

  public:
	int shortestCode(int N)
	{
		for (int i = 0; i < lim; i++)
			dp[i] = 1e9;
		dp[0] = 0;
		queue<pii> pq;
		pq.push(mp(0, 0));
		while (!pq.empty())
		{
			auto it = pq.front();
			pq.pop();
			int s = it.second;
			int t = it.first;
			if (s == N)
				return t;
			if (s * s < lim)
			{
				if (dp[s * s] > t + 1)
				{
					dp[s * s] = t + 1;
					pq.push(mp(t + 1, s * s));
				}
			}
			if (s + 1 < lim)
			{
				if (dp[s + 1] > t + 1)
				{
					dp[s + 1] = t + 1;
					pq.push(mp(t + 1, s + 1));
				}
			}
			if (s - 1 >= 0)
			{
				if (dp[s - 1] > t + 1)
				{
					dp[s - 1] = t + 1;
					pq.push(mp(t + 1, s - 1));
				}
			}
			int to = sorted(s);
			if (to < lim && dp[to] > t + 1)
			{
				dp[to] = t + 1;
				pq.push(mp(t + 1, to));
			}
		}
		return dp[N];
	}
};