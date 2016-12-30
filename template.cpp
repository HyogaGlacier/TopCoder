#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

${<if Problem.Description.Modulo}
static const int MOD = ${Problem.Description.Modulo};
${<end}

class ${ClassName} {
	public:
	${<foreach Method.Params p}
	${p.Type} ${p.Name};
	${<end}
	${Method.ReturnType} ${Method.Name}(${foreach Method.Params p , }${p.Type} _${p.Name}${end}) {
		${foreach Method.Params p , }${p.Name} = _${p.Name}${end};
		
	}
};

${CutBegin}
${<TestCode}
${CutEnd}
