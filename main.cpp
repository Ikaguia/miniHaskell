#include "header.hpp"

map<string,miniHfunc> funcs;
map<string,var> vars;

int main(){
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
			expression* exp = builder(in);
			cout << endl << "in = " << in << endl;
			cout << exp->runExpr().str() << endl;
			//cout << runExpr(in).str() << endl;
		}
	}
	return 0;
}