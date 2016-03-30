#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, a, N) for (int i = a; i < (int)N; i++)
#define rrep(i, a, N) for (int i = a; i >= (int)N; i--)
static const int mod = 1000000007;

struct BracketSequenceDiv2 {
  string s;
  ll dp[120][120];
  int count(string _s) {
    s = _s;
    int n=s.size();
    memset(dp,0,sizeof(dp));
    rep(i,0,n){
		if(s[i]=='('){
			dp[i][1]=1;
			break;
		}
	}
    rep(i,0,n){
		rep(j,0,105){
			if(dp[i][j]==0)	continue;
			int start=i+1,end=i+1;
			while(start<n){
				if(s[start]=='(')	break;
				start++;
			}
			while(end<n){
				if(s[end]==')')	break;
				end++;
			}
			dp[start][j+1]=(dp[start][j+1]+dp[i][j])%mod;
			if(j>0)	dp[end][j-1]=(dp[end][j-1]+dp[i][j])%mod;
		}
	}
	ll ret=0;
	rep(i,0,n){
		ret=(ret+dp[i][0])%mod;
	}
	return (int)ret;
  }
};

// CUT begin
ifstream data("BracketSequenceDiv2.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string s, int __expected) {
    time_t startClock = clock();
    BracketSequenceDiv2 *instance = new BracketSequenceDiv2();
    int __result = instance->count(s);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string s;
        from_stream(s);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1459239326;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "BracketSequenceDiv2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
