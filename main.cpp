#include "header.hpp"

map<string,miniHfunc> funcs;
map<string,var> vars;

int main(){
	string in;

	cout << "yay" << endl;
	while(1){
		vars.clear();
		getline(cin,in);
		if(in=="exit")break;
		if(strStartsWith(in,"define ")){
			miniHfunc f(in.substr(7));
			funcs[f.name]=f;
		}
		else if(strStartsWith(in,"def ")){
			miniHfunc f(in.substr(4));
			funcs[f.name]=f;
		}
		else cout << runExpr(in).val << endl;
	}
	return 0;
}