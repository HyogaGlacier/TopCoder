#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

class TreeDistanceConstruction {
	public:
	vector<int> construct(vector<int> d) {
		map<int,vi> dist;
		int n=d.size();
		int maxdist=0,mindist=1e9;
		rep(i,n){
			dist[d[i]].push_back(i);
			maxdist=max(maxdist,d[i]);
			mindist=min(mindist,d[i]);
		}
		int curdist=dist.begin()->first;
		vi ret(2*(n-1));
		int fill=0;
		int next[2]={0,0};
		vi ls=dist[curdist];
		if(ls.size()==1){
			if(dist.size()!=mindist+1)	return {};
			next[0]=next[1]=ls[0];
		}
		else if(ls.size()==2){
			if(dist.size()!=mindist)	return {};
			next[0]=ls[0];	next[1]=ls[1];
			ret[0]=ls[0];	ret[1]=ls[1];
			fill=1;
		}
		else 	return {};
		for(auto it:dist){
			if(mindist==it.first)	continue;
			curdist++;
			if(it.first!=curdist)	return {};
			if(it.second.size()<2)	return {};
			int base=next[0];
			ret[2*fill]=it.second[0];
			ret[2*fill+1]=next[0];
			next[0]=it.second[0];
			fill++;
			ret[2*fill]=it.second[1];
			ret[2*fill+1]=next[1];
			next[1]=it.second[1];
			fill++;
			for(int i=2;i<it.second.size();i++){
				ret[2*fill]=it.second[i];
				ret[2*fill+1]=base;
				fill++;
			}
		}
		return ret;
	}
};

// CUT begin
ifstream data("TreeDistanceConstruction.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> d, vector<int> __expected) {
    time_t startClock = clock();
    TreeDistanceConstruction *instance = new TreeDistanceConstruction();
    vector<int> __result = instance->construct(d);
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
        vector<int> d;
        from_stream(d);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(d, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1483019017;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TreeDistanceConstruction (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
