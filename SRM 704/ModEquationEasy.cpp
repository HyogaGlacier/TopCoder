#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pii;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

static const ll mod = 1e9+7;

class ModEquationEasy {
	public:
		int n;
		int k;
		int v;
		int count(int _n, int _K, int _v) {
		n = _n, k = _K, v = _v;
		vi ret(k,1);
		vector<vi> array(k,vi(k,0));
		rep(i,k){
			rep(j,k){
				array[i][(i*j)%k]++;
			}
		}
		n--;
		while(n){
			if(n&1){
				vi next(k,0);
				rep(i,k)	rep(j,k){
					next[j]+=array[i][j]*ret[i];
					next[j]%=mod;
				}
				ret=next;
			}
			n/=2;
			vector<vi> tmp(k,vi(k,0));
			rep(i,k)	rep(j,k)	rep(l,k){
				tmp[i][l]+=array[i][j]*array[j][l];
				tmp[i][l]%=mod;
			}
			array=tmp;
		}
		return ret[v];
	}
};

// CUT begin
ifstream data("ModEquationEasy.sample");

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

bool do_test(int n, int K, int v, int __expected) {
    time_t startClock = clock();
    ModEquationEasy *instance = new ModEquationEasy();
    int __result = instance->count(n, K, v);
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
        int n;
        from_stream(n);
        int K;
        from_stream(K);
        int v;
        from_stream(v);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, K, v, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1483021863;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ModEquationEasy (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
