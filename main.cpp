//note: all the inclusion order does matter
#include <bits/stdc++.h> //note: otherwise all hpp will break at once, because it doesn't know what std::string is
using namespace std; //note: this declaration shouldn't be used at any .hpp

using ii = pair<int,int>; //note: otherwise util.hpp doen't know what ii return type means
#include "util.hpp"

#include "./core/var.hpp" //note: var include should be always included before expression.hpp because it depends on var definition
#include "./core/expression.hpp"

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
			if(exp) cout << exp->runExpr().str() << endl;
		}
	}

	return 0;
}
