#include "header.hpp"

miniHfunc::miniHfunc():name{""}{}
miniHfunc::miniHfunc(string s){
	auto open=s.find_first_of("(");
	auto close=s.find_first_of(")");
	name=s.substr(0,open);
	string argStr=s.substr(open+1,close-open-1);
	while(1){
		if(argStr.size()==0)break;
		string t=get1stWord(argStr);
		argStr = argStr.substr(get1stWordPos(argStr).ss);
		if(t=="int"){
			args.push_back(ts(tInt,get1stWord(argStr)));
			argStr = argStr.substr(get1stWordPos(argStr).ss);
		}
		else if(t=="bool"){
			args.push_back(ts(tBool,get1stWord(argStr)));
			argStr = argStr.substr(get1stWordPos(argStr).ss);
		}
		argStr=argStr.substr(argStr.find_first_of(" ")+1);
	}
	s=s.substr(s.find_first_of("(",close));
	body=s.substr(1,s.size()-2);
}

var miniHfunc::call(string s,bool print){
	if(DEBUG)cout << "CALL function not implemented" << endl;
	return var(success);//todo
}
