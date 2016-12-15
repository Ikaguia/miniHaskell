#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
#include "../util.hpp"

#include "var.hpp"

const string errorMsgs[] = {
	"ERROR",
	"ERROR CALL function not implemented",
	"ERROR invalid type",
	"ERROR reserved words",
	"ERROR division by 0",
	"ERROR no matching expression found",
	"ERROR invalid variable name",
	"ERROR list is empty",
	"ERROR wrong number of arguments to function",
};

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
