#include "header.hpp"

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
	//cout << s << " " << pos.ff << " " << pos.ss << endl;
	return s.substr(pos.ff,pos.ss-pos.ff);
}

string lower_case(const string& in){
	string out=in;
	for(auto &i:out){
		if(i>='A' && i <='Z')i=(i-'A')+'a';
	}
	return out;
}

string upper_case(const string& in){
	string out=in;
	for(auto &i:out){
		if(i>='a' && i <='z')i=(i-'a')+'A';
	}
	return out;
}

string noSpaces(string s){
	string o="";
	for(auto i:s){
		if(i!=' ')o+=i;
	}
	return o;
}

bool parser(string s,string code,vector<string> &ret){
	//cout << "parse " << s << " " << code << endl;
	if(code.size()==0 && s.size()==0)return true;
	if(code.size()==0 || s.size()==0)return false;
	if(code[0]=='%' && code[1]=='s'){
		FOR2(i,1,s.size()){
			vector<string> r=ret;
			r.push_back(s.substr(0,i));
			if(parser(s.substr(i),code.substr(2),r)){
				ret=r;
				return true;
			}
		}
	}
	else if(code[0]=='%' && code[1]=='%'){
		if(s[0]=='%')return parser(s.substr(2),code.substr(1),ret);
		return false;
	}
	else if(code[0]==s[0]){
		return parser(s.substr(1),code.substr(1),ret);
	}
	return false;



	int a=code.find_first_of('%');
	while((size_t)a+1<code.size()){
		if(code[a+1]!='%')break;
		code.find_first_of('%',a);
	}
	if((size_t)a+1>=code.size())return false;
	if(s.substr(0,a)!=code.substr(0,a))return false;
	return parser(s.substr(a),code.substr(a),ret);
}

bool parse(string s,string code,vector<string> &ret){
	//code = "let(%s=%s)in(%s)"
	s=noSpaces(s);
	code=noSpaces(code);
	if(DEBUG)cout << "parsing " << s << " with code " << code << endl;
	return parser(s,code,ret);
}