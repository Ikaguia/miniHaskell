#include <bits/stdc++.h>
using namespace std;


using ii = pair<int,int>;
#include "util.hpp"

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
	return s.substr(pos.first,pos.second-pos.first);
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

string noSpaces(const string &s){
	string o="";
	for(auto i:s){
		if(i!=' ')o+=i;
	}
	return o;
}

int findMatching(const string s,char open,char close){
	if(DEBUG)cout << "findMatching " << s << " " << open << " " << close << endl;
	int deepth=0;
	FOR(i,s.size()){
		if(s[i]==open)deepth++;
		if(s[i]==close)deepth--;
		if(deepth<=0)return i;
	}
	return s.size();
}

bool parser(string s,string code,vector<string> &ret){
	if(DEBUG){
		cout << "parse '" << s << "' '" << code << "'";
		for(auto i:ret)cout << " " << i;
		cout << endl;
	}
	if(code.size()==0 && s.size()==0)return true;
	if(code.size()==0 || s.size()==0)return false;
	if(code=="%s"){
		ret.push_back(s);
		return true;
	}
	//cout << "aaa " << (code[0]=='%') << " " << (code[1]=='s') << endl;
	if((code[0]=='%') && (code[1]=='s')){
		FOR2(i,1,s.size()){
			//define(foo(a)=(a)) define(%s(%s)=(%s))
			//foo(a)=(a)) %s(%s)=(%s))
	
			//cout << "batata" << endl;
			//(a)
			//aaa(bbb(ccc)),ddd
			//while(s[i]=='(' || s[i]=='['){
			//	if(s[i]=='(')i+=findMatching(s.substr(i),'(',')')+1;
			//	if(s[i]=='[')i+=findMatching(s.substr(i),'[',']')+1;
			//}
			//cout << "trying i=" << i << endl;
			if(s[i]=='(' && code[2]!='(')i+=findMatching(s.substr(i),'(',')')+1;
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
}

bool parse(string s,string code,vector<string> &ret){
	//code = "let(%s=%s)in(%s)"
	ret.clear();
	s=noSpaces(s);
	code=noSpaces(code);
	if(DEBUG)cout << "parsing " << s << " with code " << code << endl;
	return parser(s,code,ret);
}

bool isReserved(const string& s){
	for(auto i:reservedWords)if(i==s){
		return true;
	}
	/*for(auto i:operators)if(i.name==s){
		return true;
	}*/
	return false;
}

bool letter(const string &s){
	for(auto i:s)if(!letter(i))return false;
	return true;
}

bool letter(char c){
	return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

bool number(const string &s){
	for(auto i:s)if(!number(i))return false;
	return true;
}

bool number(char c){
	return (c>='0' && c<='9');
}

bool alphaNumeric(const string &s){
	for(auto i:s)if(!alphaNumeric(i))return false;
	return true;
}

bool alphaNumeric(char c){
	return (number(c) || letter(c));
}
