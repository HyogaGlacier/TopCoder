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

struct LineColoring
{
    vector<int> x;
    int minCost(vector<int> _x)
    {
        x = _x;
        int n = x.size();
        vector<pii> xdat(n);
        rep(i, n) xdat[i] = mp(x[i], i);
        sort(all(xdat));
        vint color(n, -1);
        int cnt = 0;
        int ret = 0;
        bitset<1010> bs(0);
        while (bs.count() < n)
        {
            int idx = xdat.size() - 1;
            while (idx >= 0)
            {
                int p = xdat[idx].second;
                if (bs[p])
                    idx--;
                else
                    break;
            }
            int v = xdat[idx].first;
            int pos = xdat[idx].second;
            // cout << "(" << v << "," << pos << ") ";
            color[pos] = cnt;
            bs.set(pos);
            ret += v;
            rrep(i, xdat.size())
            {
                int p = xdat[i].second;
                if (bs[p])
                    continue;
                if (p + 1 < n && color[p + 1] == cnt)
                    continue;
                if (p - 1 >= 0 && color[p - 1] == cnt)
                    continue;
                color[p] = cnt;
                bs.set(p);
                // cout << "(" << xdat[i].first << "," << p << ") ";
            }
            cout << endl;
            cnt++;
        }
        int reta = 0, retb = 0;
        rep(i, n)
        {
            if (i & 1)
                reta = max(reta, x[i]);
            else
                retb = max(retb, x[i]);
        }
        return min(ret, reta + retb);
    }
};

// CUT begin
ifstream data("LineColoring.sample");

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

bool do_test(vector<int> x, int __expected)
{
    time_t startClock = clock();
    LineColoring *instance = new LineColoring();
    int __result = instance->minCost(x);
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
        vector<int> x;
        from_stream(x);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(x, __answer))
        {
            passed++;
        }
    }
    if (mainProcess)
    {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1528990724;
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
        cout << "LineColoring (500 Points)" << endl
             << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
