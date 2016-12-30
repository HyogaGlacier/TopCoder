#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

class Sunnygraphs {
    public:
    int n;
    vector<int> d;
    vector<int> edge[50];
    int color[50];
    void dfs(int cur,int setColor){
		color[cur]=setColor;
		for(int i=0;i<edge[cur].size();i++){
			if(!color[edge[cur][i]])	dfs(edge[cur][i],setColor);
		}
	}
	bool visited[50];
	long long calc(int a){
		long long ret=1;
		while(a--)	ret*=2;
		return ret;
	}
	int cntFind(int cur){
		for(int i=0;i<edge[cur].size();i++){
			if(edge[cur][i]==1)	return 1;
			else if(!visited[edge[cur][i]]){
				int check=cntFind(edge[cur][i]);
				if(check){
					if(d[cur]==edge[cur][i] && d[edge[cur][i]]==cur)	return check;
					else return check+1;
				}
			}
		}
		return 0;
	}
	int a=0,b=0;
	void SqOrCir(){
		for(int i=0;i<n;i++)	visited[i]=false;
		bool first=true;
		visited[0]=true;
		for(int i=0;i<edge[0].size();i++){
			int tmp=cntFind(edge[0][i]);
			if(tmp){
				if(first)	a=tmp;
				else 	b=tmp;
			}
		}
	}
	
    long long count(vector<int> _d) {
		d=_d;
		n=d.size();
		for(int i=0;i<n;i++){
			edge[d[i]].push_back(i);
			edge[i].push_back(d[i]);
		}
		memset(color,0,sizeof(color));
		int setColor=1;
		for(int i=0;i<n;i++){
			if(!color[i])	dfs(i,setColor++);
		}
		//colorが違う:それぞれのcolorを含んでいればOK
		if(color[0]!=color[1]){
			int c=0;//0のグループ、1のグループ、その他の個数
			for(int i=0;i<n;i++){
				if(color[i]==color[0])	a++;
				else if(color[i]==color[1])	b++;
				else 	c++;
			}
			//2^c * (2^a-1) * (2^b-1)
			long long ret=(calc(a)-1)*(calc(b)-1)*calc(c);
			return ret;
		}
		long long others=0;
		for(int i=0;i<n;i++){
			if(color[i]!=color[0])	others++;
		}
		//colorが同じ:0->1への道が途中で途切れなければOK
		// -言い方を変えると、単結合のものを片方だけnに繋がなければOK
		for(int i=0;i<n;i++)	sort(edge[i].begin(),edge[i].end());
		long long ret=calc(n);
		//イカ足型と巨大円型に分けられる
		//巨大円型は切れない。
		//イカ足型は間の要素数a(ただし2重結合なら除く)とすると、
		// -(2^a-1)
		for(int i=0;i<n;i++)	visited[i]=false;
		SqOrCir();
		if(b==0){//イカ型
			long long dec=calc(others)*(calc(a)-1);
			ret-=dec;
		}
        return ret;
    }
};

// CUT begin
ifstream data("Sunnygraphs.sample");

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

bool do_test(vector<int> a, long long __expected) {
    time_t startClock = clock();
    Sunnygraphs *instance = new Sunnygraphs();
    long long __result = instance->count(a);
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
        vector<int> a;
        from_stream(a);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1464620403;
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
        cout << "Sunnygraphs (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
