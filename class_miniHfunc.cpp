#include "header.hpp"

miniHfunc::miniHfunc():name{""}{}
miniHfunc::miniHfunc(string s){
	auto open=s.find_first_of("(");
	auto close=s.find_first_of(")");
	name=s.substr(0,open);
	string argStr=s.substr(open+1,close-open);
	while(1){
		if(argStr.size()==0)break;
		if(strStartsWith(argStr,"int ")){
			argStr=argStr.substr(argStr.find_first_of(" ")+1);
			args.push_back(ts(tInt,argStr.substr(0,argStr.find_first_of(" "))));
		}
		else if(strStartsWith(argStr,"bool ")){
			argStr=argStr.substr(argStr.find_first_of(" ")+1);
			args.push_back(ts(tBool,argStr.substr(0,argStr.find_first_of(" "))));
		}
		argStr=argStr.substr(argStr.find_first_of(" ")+1);
	}
	body=s.substr(close+2);
}

int miniHfunc::call(string s,bool print=false){
	return 0;
}