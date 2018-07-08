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

class Resistance
{
  public:
	vector<double> spyProbability(int P, int S, vector<string> missions)
	{
		int validcnt = 0;
		vector<double> ret(P);
		for (int bit = 0; bit < (1 << P); bit++)
		{
			if (bicnt(bit) != S)
				continue;
			int fmission = 0;
			for (int i = 0; i < missions.size(); i++)
			{
				if (missions[i][0] == 'F')
				{
					int ok = 0;
					for (int j = 1; j <= P; j++)
					{
						if (bit & (1 << (j - 1)) && missions[i][j] == '1')
						{
							ok++;
						}
					}
					if (ok > 0)
					{
						fmission++;
					}
					else
					{
						fmission = 0;
						break;
					}
				}
			}
			if (fmission > 0)
			{
				validcnt++;
				for (int i = 0; i < P; i++)
				{
					if (bit & (1 << i))
						ret[i] += 1.0;
				}
			}
		}
		double sum = 0;
		for (int i = 0; i < P; i++)
		{
			ret[i] /= validcnt;
			sum += ret[i];
		}
		cout << sum - S << endl;
		if (sum - S < eps && sum - S > -eps)
			return vector<double>();
		else
			return ret;
	}
};