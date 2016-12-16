#include "header.hpp"

// map<string,miniHfunc> funcs;
// map<string,var> vars;

int main(){
	string in;

	system("clear");
	while(1){
		vars.clear();
		cout << "> ";
		if(!getline(cin, in)){cout << endl; break;}
		if(in=="exit")break;
		else if(in=="clear")system("clear");
		else if(in=="" || strStartsWith(in,"//"))continue;
		else{
			expression* exp = builder(in);
			//cout << endl << "in = " << in << endl;
			if(exp) cout << exp->runExpr().str() << endl;
			//cout << runExpr(in).str() << endl;
		}
	}

	return 0;
}
