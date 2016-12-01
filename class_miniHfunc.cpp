#include "header.hpp"

miniHfunc::miniHfunc():name{""}{}
miniHfunc::miniHfunc(string s){
cout << "s " << s << endl;

	auto open=s.find_first_of("(");
	auto close=s.find_first_of(")");
	name=s.substr(0,open);
	string argStr=s.substr(open+1,close-open-1);
	s=s.substr(s.find_first_of("(",close));
cout << "name " << name << endl;
cout << "argStr " << argStr << endl;
	while(1){
		if(argStr.size()==0)break;
		string t=get1stWord(argStr);
cout << "t " << t << endl;
		argStr = argStr.substr(get1stWordPos(argStr).ss);
cout << "argStr2 '" << argStr << "'" << endl;
		if(t=="int"){
			args.push_back(ts(tInt,get1stWord(argStr)));
			argStr = argStr.substr(get1stWordPos(argStr).ss);
		}
		else if(t=="bool"){
			args.push_back(ts(tBool,get1stWord(argStr)));
			argStr = argStr.substr(get1stWordPos(argStr).ss);
		}
	}
	body=s.substr(1,s.size()-2);
}

var miniHfunc::call(string s,bool print){
	assert(false);
	return var(error,funcError);//todo
}
