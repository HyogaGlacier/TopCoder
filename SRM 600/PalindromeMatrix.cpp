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
const int inf = 1e9;

struct PalindromeMatrix
{
    vector<string> A;
    int rowCount;
    int columnCount;
    int minChange(vector<string> _A, int _rowCount, int _columnCount)
    {
        A = _A, rowCount = _rowCount, columnCount = _columnCount;
        int n = A.size(), m = A[0].size();
        int end = 1 << n;
        int ret = inf;
        // 行についてbit全探索で固定
        rep(i, end)
        {
            if (bicnt(i) != rowCount)
                continue;
            // cout << "state:" << i << endl;
            vint dp(columnCount + 1, inf);
            dp[0] = 0;
            vector<tuple<int, int, int>> cost;
            for (int j = 0; j < m - j; j++)
            {
                int k = m - 1 - j;
                // j,k列目をともに回文にしない
                int None = 0;
                rep(l, n)
                {
                    if (i & (1 << l) && A[l][j] != A[l][k])
                    {
                        None++;
                    }
                }
                // jだけ回分にする
                int onlyLeft = 0;
                for (int l = 0; 2 * l < n; l++)
                {
                    int il = n - 1 - l;
                    int bk = 0, wh = 0;
                    if (A[l][j] == '0')
                        bk++;
                    else
                        wh++;
                    if (A[il][j] == '0')
                        bk++;
                    else
                        wh++;
                    if (i & (1 << l))
                    {
                        if (A[l][k] == '0')
                            bk++;
                        else
                            wh++;
                    }
                    if (i & (1 << il))
                    {
                        if (A[il][k] == '0')
                            bk++;
                        else
                            wh++;
                    }
                    // cout << j << " " << k << " " << l << " " << il << ":" << bk << " " << wh << endl;
                    onlyLeft += min(bk, wh);
                }
                // kだけ回分に
                int onlyRight = 0;
                for (int l = 0; 2 * l < n; l++)
                {
                    int il = n - 1 - l;
                    int bk = 0, wh = 0;
                    if (A[l][k] == '0')
                        bk++;
                    else
                        wh++;
                    if (A[il][k] == '0')
                        bk++;
                    else
                        wh++;
                    if (i & (1 << l))
                    {
                        if (A[l][j] == '0')
                            bk++;
                        else
                            wh++;
                    }
                    if (i & (1 << il))
                    {
                        if (A[il][j] == '0')
                            bk++;
                        else
                            wh++;
                    }
                    onlyRight += min(bk, wh);
                }
                // j,k両方回分に
                int Both = 0;
                for (int l = 0; 2 * l < n; l++)
                {
                    int il = n - 1 - l;
                    if (i & (1 << l) || i & (1 << il))
                    {
                        // 4マス全部同じに
                        int bk = 0, wh = 0;
                        if (A[l][j] == '0')
                            bk++;
                        else
                            wh++;
                        if (A[l][k] == '0')
                            bk++;
                        else
                            wh++;
                        if (A[il][j] == '0')
                            bk++;
                        else
                            wh++;
                        if (A[il][k] == '0')
                            bk++;
                        else
                            wh++;
                        Both += min(bk, wh);
                    }
                    else
                    {
                        if (A[l][k] != A[il][k])
                            Both++;
                        if (A[l][j] != A[il][j])
                            Both++;
                    }
                }
                cost.push_back(mt(None, min(onlyLeft, onlyRight), Both));
            }
            rep(i, cost.size())
            {
                int zero, one, two;
                tie(zero, one, two) = cost[i];
                // cout << "use:" << zero << "," << one << "," << two << endl;
                vint dp2(columnCount + 1, inf);
                rep(j, dp.size())
                {
                    dp2[j] = min(dp2[j], dp[j] + zero);
                    if (j + 1 < dp.size())
                        dp2[j + 1] = min(dp2[j + 1], dp[j] + one);
                    if (j + 2 < dp.size())
                        dp2[j + 2] = min(dp2[j + 2], dp[j] + two);
                }
                /*
                rep(j, dp.size())
                {
                    cout << dp2[j] << " ";
                }
                cout << endl;
                */
                dp = dp2;
            }
            // cout << dp[columnCount] << endl;
            ret = min(ret, dp[columnCount]);
        }
        return ret;
    }
};

// CUT begin
ifstream data("PalindromeMatrix.sample");

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

bool do_test(vector<string> A, int rowCount, int columnCount, int __expected)
{
    time_t startClock = clock();
    PalindromeMatrix *instance = new PalindromeMatrix();
    int __result = instance->minChange(A, rowCount, columnCount);
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
        vector<string> A;
        from_stream(A);
        int rowCount;
        from_stream(rowCount);
        int columnCount;
        from_stream(columnCount);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(A, rowCount, columnCount, __answer))
        {
            passed++;
        }
    }
    if (mainProcess)
    {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1531155190;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "PalindromeMatrix (600 Points)" << endl
             << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
