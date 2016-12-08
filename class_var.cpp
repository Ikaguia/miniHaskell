#include "header.hpp"

string var::str(){
	if(t==success)return "SUCCESS";
	if(t==error)return errorMsgs[val];
	if(t==tBool)return val?"TRUE":"FALSE";
	if(t==tInt)return to_string(val);
	if(t==listBool){
		string s;
		FOR(i,li.size()){
			if(i)s+=", ";
			s+=li[i]?"TRUE":"FALSE";
		}
		return "listBool[" + s + "]";
	}
	if(t==listInt){
		string s;
		FOR(i,li.size()){
			if(i)s+=", ";
			s+=to_string(li[i]);
		}
		return "listInt[" + s + "]";
	}
	return "???";
}
