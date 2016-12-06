#include "header.hpp"

map<string,miniHfunc> funcs;
map<string,var> vars;

int main(){
	vector<string> v;
	cout << parse("let(x=10)in(x)","let(%s=%s)in(%s)",v) << endl;
	for(auto i:v)cout << i << endl;

	string in;

	system("clear");
	cout << "yay" << endl;
	while(1){
		vars.clear();
		getline(cin,in);
		if(in=="exit")break;
		else if(in=="clear")system("clear");
		else if(in=="" || strStartsWith(in,"//"))continue;
		else{
			cout << endl << "in = " << in << endl;
			cout << runExpr(in).str() << endl;
		}
	}
	return 0;
}