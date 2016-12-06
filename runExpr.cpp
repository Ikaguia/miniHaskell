#include "header.hpp"

vector<operat> operators={
	operat("let",		"let(%s=%s)in(%s)",			(funcP)let),
	operat("if",		"if(%s)then(%s)else(%s)",	(funcP)ifThenElse),
	operat("define",	"define(%s(%s)=(%s))",		(funcP)define),
	operat("sum",		"sum(%s,%s)",				(funcP)sumOp),
	operat("sub",		"sub(%s,%s)",				(funcP)subOp),
	operat("mult",		"mult(%s,%s)",				(funcP)multOp),
	operat("div",		"div(%s,%s)",				(funcP)divOp),
	operat("and",		"and(%s,%s)",				(funcP)andOp),
	operat("or",		"or(%s,%s)",				(funcP)orOp),
	operat("not",		"not(%s)",					(funcP)notOp),
	operat("equals",	"equals(%s,%s)",			(funcP)eqOp),//equals
	operat("eq",		"eq(%s,%s)",				(funcP)eqOp),//equals
	operat("greater",	"greater(%s,%s)",			(funcP)gtOp),//greater then
	operat("gt",		"gt(%s,%s)",				(funcP)gtOp),//greater then
	operat("lessThen",	"lessThen(%s,%s)",			(funcP)ltOp),//less then
	operat("lt",		"lt(%s,%s)",				(funcP)ltOp),//less then
	operat("greaterEq",	"greaterEq(%s,%s)",			(funcP)geOp),//greater then or equals
	operat("ge",		"ge(%s,%s)",				(funcP)geOp),//greater then or equals
	operat("lessEq",	"lessEq(%s,%s)",			(funcP)leOp),//less then or equals
	operat("le",		"le(%s,%s)",				(funcP)leOp),//less then or equals
};

var runExpr(const string &s){
	var result;
	vector<string> args;
	for(auto i:operators){
		result = i.call(s);
		if(result.t!=error || result.val!=parsingError){
			if(DEBUG)cout << "called operator " << i.name << endl;
			return result;
		}
	}
	for(auto i:funcs){
		if(parse(s,i.ff+"(%s)",args)){
			if(DEBUG)cout << "called function " << i.ff << endl;
			return i.ss.call(args[0]);
		}
	}
	for(auto i:vars){
		if(parse(s,i.ff,args)){
			if(DEBUG)cout << "called variable " << i.ff << endl;
			return i.ss;
		}
	}
	if(lower_case(noSpaces(s))=="true"){
		if(DEBUG)cout << "called true" << endl;
		return var(true);
	}
	if(lower_case(noSpaces(s))=="false"){
		if(DEBUG)cout << "called false" << endl;
		return var(false);
	}
	if(s.find_first_not_of("0123456789 ")<=s.size())return var(error,parsingError);
	if(DEBUG)cout << "called integer" << endl;
	return var(atoi(s.c_str()));
}