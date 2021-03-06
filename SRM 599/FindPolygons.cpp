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
const double eps = 1e-9;

inline double getDist(double x, double y)
{
    return sqrt(x * x + y * y);
}

struct FindPolygons
{
    inline bool sameVector(pii a, pii b)
    {
        if (a.first == 0)
            return b.first == 0;
        return a.second * b.first == b.second * a.first;
    }
    double L;
    double minimumPolygon(int _L)
    {
        L = _L;
        if (_L & 1 || _L == 2)
            return -1;
        // can you make triangle?
        map<int, vector<pair<double, double>>> mp;
        for (int i = 0; 2 * i - L < eps; i++)
        {
            for (int j = 0; getDist(i, j) - L < eps; j++)
            {
                int d = getDist(i, j);
                if (d * d == i * i + j * j)
                {
                    mp[d].push_back(mp(i, j));
                }
            }
        }
        int ret = 1e9;
        for (int a = 1; 2 * a - L < eps; a++)
        {
            auto fst = mp[a];
            rep(i, fst.size())
            {
                for (int b = 1; b < min(a, (_L - a)); b++)
                {
                    auto scn = mp[b];
                    rep(j, scn.size())
                    {
                        if (sameVector(fst[i], scn[j]))
                            continue;
                        int x = fst[i].first - scn[j].first;
                        int y = fst[i].second - scn[j].second;
                        int d = getDist(x, y);
                        if (d * d == x * x + y * y && a + b + d == _L)
                        {
                            ret = min(ret, max(a, max(b, d)) - min(a, min(b, d)));
                        }
                    }
                }
            }
        }
        if (ret != 1e9)
        {
            return ret;
        }
        int halfL = L / 2;
        ret = ((int)(halfL + 1) / 2) - ((int)halfL / 2);
        return ret;
    }
};

// CUT begin
ifstream data("FindPolygons.sample");

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

bool double_equal(const double &a, const double &b) { return b == b && a == a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a)); }

bool do_test(int L, double __expected)
{
    time_t startClock = clock();
    FindPolygons *instance = new FindPolygons();
    double __result = instance->minimumPolygon(L);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result))
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
        int L;
        from_stream(L);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(L, __answer))
        {
            passed++;
        }
    }
    if (mainProcess)
    {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1531054170;
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
        cout << "FindPolygons (500 Points)" << endl
             << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
