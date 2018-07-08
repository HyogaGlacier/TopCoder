#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
typedef vector<ll> vll;
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

struct ProductThreshold
{
    int N;
    int limit;
    vector<int> Aprefix;
    int spread;
    int offset;
    ll subarrayCount(int _N, int _limit, vector<int> _Aprefix, int _spread, int _offset)
    {
        N = _N, limit = _limit, Aprefix = _Aprefix, spread = _spread, offset = _offset;
        vll a(N);
        rep(i, Aprefix.size()) a[i] = Aprefix[i];
        ll seed = labs(Aprefix[Aprefix.size() - 1]);
        srep(i, Aprefix.size(), N)
        {
            seed = (seed * 1103515245LL + 12345LL) % (1LL << 31);
            a[i] = (seed % spread) + offset;
        }
        ll overp = 0, overm = 0;
        map<ll, ll> cntmp;
        cntmp[0] = 1;
        ll ret = 0;
        rep(i, N)
        {
            map<ll, ll> nxtmp;
            ll addOverp = 0, addOverm = 0;
            for (auto it : cntmp)
            {
                ll nxt = it.first * a[i];
                if (limit < labs(nxt))
                {
                    if (nxt < 0)
                    {

                        addOverm++;
                    }
                    else
                        addOverp++;
                }
                else
                {
                    nxtmp[nxt] += it.second;
                }
            }
        }
        return 0;
    }
};

// CUT begin
ifstream data("ProductThreshold.sample");

string next_line()
{
    string s;
    getline(data, s);
    return s;
}

template <typename T>
void from_stream(T &t)
{
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s)
{
    s = next_line();
}

template <typename T>
void from_stream(vector<T> &ts)
{
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i)
    {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t)
{
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t)
{
    return "\"" + t + "\"";
}

bool do_test(int N, int limit, vector<int> Aprefix, int spread, int offset, ll __expected)
{
    time_t startClock = clock();
    ProductThreshold *instance = new ProductThreshold();
    ll __result = instance->subarrayCount(N, limit, Aprefix, spread, offset);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected)
    {
        cout << "PASSED!"
             << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else
    {
        cout << "FAILED!"
             << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command)
{
    int cases = 0, passed = 0;
    while (true)
    {
        if (next_line().find("--") != 0)
            break;
        int N;
        from_stream(N);
        int limit;
        from_stream(limit);
        vector<int> Aprefix;
        from_stream(Aprefix);
        int spread;
        from_stream(spread);
        int offset;
        from_stream(offset);
        next_line();
        ll __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(N, limit, Aprefix, spread, offset, __answer))
        {
            passed++;
        }
    }
    if (mainProcess)
    {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1530981856;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i)
    {
        if (string(argv[i]) == "-")
        {
            mainProcess = false;
        }
        else
        {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess)
    {
        cout << "ProductThreshold (500 Points)" << endl
             << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
