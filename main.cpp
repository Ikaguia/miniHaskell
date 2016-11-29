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
		else cout << runExpr(in).str() << endl;
	}
	return 0;
}