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

int dp[1010][1010];

struct LeftToRightGame
{
    int length;
    int divisor;

    bool Bob(int i, int m)
    {
        if (i == length)
        {
            return m % divisor == 0;
        }
        else
        {
            if (dp[i][m])
                return dp[i][m] == 1;
            rep(k, 10)
            {
                if (k == 0 && i == 0)
                    continue;
                if (!Alice(i + 1, (m * 10 + k) % divisor))
                {
                    dp[i][m] = 1;
                    return true;
                }
            }
            dp[i][m] = 2;
            return false;
        }
    }
    bool Alice(int i, int m)
    {
        if (i == length)
        {
            return m % divisor != 0;
        }
        else
        {
            rep(k, 10)
            {
                if (k == 0 && i == 0)
                    continue;
                if (!Bob(i + 1, (m * 10 + k) % divisor))
                {
                    dp[i][m] = 1;
                    return true;
                }
            }
            dp[i][m] = 2;
            return false;
        }
    }

    string whoWins(int _length, int _divisor)
    {
        length = _length, divisor = _divisor;
        if (Alice(0, 0))
            return "Alice";
        else
            return "Bob";
    }
};

// CUT begin
ifstream data("LeftToRightGame.sample");

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

bool do_test(int length, int divisor, string __expected)
{
    time_t startClock = clock();
    LeftToRightGame *instance = new LeftToRightGame();
    string __result = instance->whoWins(length, divisor);
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
        int length;
        from_stream(length);
        int divisor;
        from_stream(divisor);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(length, divisor, __answer))
        {
            passed++;
        }
    }
    if (mainProcess)
    {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1530979205;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "LeftToRightGame (250 Points)" << endl
             << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end