#include "header.hpp"

extern map<string,miniHfunc> funcs;
extern map<string,var> vars;

bool strStartsWith(const string& a,const string& b){
	if(a.size() <b.size())return false;
	if(a.size()==b.size())return a==b;
	return a.substr(0, b.size()) == b;
}

bool strEndsWith(const string& a,const string& b){
	if(a.size() <b.size())return false;
	if(a.size()==b.size())return a==b;
	return a.substr(a.size()-b.size()-1,a.size())==b;
}

ii get1stWordPos(const string& s,string ignore){
	if(s.size()==0)return ii(0,s.size());
	auto begin = s.find_first_not_of(ignore);
	if(begin==string::npos)return ii(0,s.size());
	auto end = s.find_first_of(ignore,begin);
	if(end==string::npos)return ii(begin,s.size());
	return ii(begin,end);
}

string get1stWord(const string& s,string ignore){
	ii pos = get1stWordPos(s,ignore);
	cout << s << " " << pos.ff << " " << pos.ss << endl;
	return s.substr(pos.ff,pos.ss-pos.ff);
}
