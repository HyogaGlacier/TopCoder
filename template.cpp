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

${<if Problem.Description.Modulo}
  static const ll MOD = ${Problem.Description.Modulo};
${<end}

struct ${ClassName} {
${<foreach Method.Params p}
  ${p.Type} ${p.Name};
${<end}
  ${Method.ReturnType} ${Method.Name}(${foreach Method.Params p , }${p.Type} _${p.Name}${end}) {
    ${foreach Method.Params p , }${p.Name} = _${p.Name}${end};
    return ${Method.ReturnType;zeroval};
  }
};

${CutBegin}
${<TestCode}
${CutEnd}
