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
	operat("empty",		"listEmpty(%s)",				(funcP)listEmptyOp),//list is empty
	operat("head",		"listHead(%s)",					(funcP)listHeadOp),//retrieve list head
	operat("tail",		"listTail(%s)",					(funcP)listTailOp),//retrieve list tail
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
	if(parse(s,"list%s[%s]",args)){
		type t=error,t2;
		if(args[0]=="Int"){
			t=tInt;
			t2=listInt;
		}
		else if(args[0]=="Bool"){
			t=tBool;
			t2=listBool;
		}
		if(t!=error){
			var temp;
			vector<int> v;
			vector<string> ss;
			string in=args[1]+",end";
			while(parse(in,"%s,%s",ss)){
				temp = runExpr(ss[0]);
				if(temp.t==error)return temp;
				if(temp.t!=t)return var(error,typeError);
				v.push_back(temp.val);
				in=ss[1];
			}
			if(DEBUG)cout << "called list" << endl;
			return var(t2,v);
		}
	}
	if(parse(s,"list%s[]",args)){
		vector<int> v;
		if     (args[0]=="Int" )return var(listInt, v);
		else if(args[0]=="Bool")return var(listBool,v);
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