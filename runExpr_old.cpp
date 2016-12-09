#include "header.hpp"

using funcT=var(string&);
using funcP=funcT*;
using psf=pair<string,funcP>;
psf operators[]={
	psf("sum",		(funcP)sumOp),
	psf("sub",		(funcP)subOp),
	psf("mult",		(funcP)multOp),
	psf("div",		(funcP)divOp),
	psf("and",		(funcP)andOp),
	psf("or",		(funcP)orOp),
	psf("not",		(funcP)notOp),
	psf("equals",	(funcP)eqOp),//equals
	psf("eq",		(funcP)eqOp),//equals
	psf("greater",	(funcP)gtOp),//greater then
	psf("gt",		(funcP)gtOp),//greater then
	psf("lessThen",	(funcP)ltOp),//less then
	psf("lt",		(funcP)ltOp),//less then
	psf("greaterEq",(funcP)geOp),//greater then or equals
	psf("ge",		(funcP)geOp),//greater then or equals
	psf("lessEq",	(funcP)leOp),//less then or equals
	psf("le",		(funcP)leOp),//less then or equals
};



var let(string& in){//(x=10,y=20)in(...)
	if(DEBUG)cout << "running let" << endl;
	if(DEBUG)cout << "in = " << in << endl;
	map<string,var> mapV;
	int i,deep;
	in=in.substr(in.find_first_of("(")+1);
	for(deep=1,i=0;(size_t)i<in.size();i++){
		if(in[i]=='(')deep++;
		if(in[i]==')')deep--;
		if(!deep)break;
	}
	string inside=in.substr(0,i)+")";//inside="x=10,y=20"
	in=in.substr(i+1);//in="in(...)"
	if(DEBUG)cout << "inside = " << inside << endl;
	while(1){
		string name=get1stWord(inside);//name="x"//name="y"
		if(DEBUG)cout << "name = " << name << endl;

		for(auto i:reservedWords)if(i==name){
			if(DEBUG)cout << i << " = " << name << endl;
			return var(error,reservedError);
		}
		for(auto i:operators)if(i.ff==name){
			if(DEBUG)cout << i.ff << " = " << name << endl;
			return var(error,reservedError);
		}

		inside = inside.substr(get1stWordPos(inside).ss);//inside="=10,y=20"
		inside = inside.substr(inside.find_first_of("=")+1);//inside="10,y=20"
		if(DEBUG)cout << "inside = " << inside << endl;
		for(deep=1,i=0;deep && (size_t)i<inside.size();i++){
			if(inside[i]=='(')deep++;
			if(inside[i]==')')deep--;
			if(inside[i]==',' && deep==1)break;
		}
		string val=inside.substr(0,i-1);
		if((size_t)i>=inside.size())i=inside.size()-1;
		inside=inside.substr(i);
		if(DEBUG)cout << "val = " << val << endl;
		if(mapV[name].t!=error);//if you do let(x=1,x=2)in(expr) x will be assigned as 2
		else if(vars[name].t!=error)mapV[name]=vars[name];//restore previous var value after this "let" ends
		else                        mapV[name]=var(error);//remove this var after this "let" ends
		var result=runExpr(val);
		if(result.t==error){
			//error, restore variables and return error
			for(auto i:mapV){
				if(i.ss.t!=error)vars[i.ff]=i.ss;
				else vars.erase(i.ff);
			}
			return result;
		}
		vars[name]=result;
		if(DEBUG)cout << "var(" << name << ") = " << (vars[name].t==(char)tInt?"int":"bool") << "(" << vars[name].val << ")" << endl;
		if(get1stWord(inside)==")")break;
	}
	if(DEBUG)cout << "in = " << in << endl;//in(...)
	in=in.substr(get1stWordPos(in).ss+1);
	in=in.substr(0,in.size()-1);
	if(DEBUG)cout << "in = " << in << endl;//in(...)

	var result = runExpr(in);

	for(auto i:mapV){
		if(i.ss.t!=error)vars[i.ff]=i.ss;
		else vars.erase(i.ff);
	}

	return result;
}

var ifThenElse(string& in){//(a)then(x)else(y)
	if(DEBUG)cout << "running ifThenElse" << endl;
	if(DEBUG)cout << "in = " << in << endl;
	int i,deep;
	in=in.substr(in.find_first_of("(")+1);
	for(deep=1,i=0;(size_t)i<in.size();i++){
		if(in[i]=='(')deep++;
		if(in[i]==')')deep--;
		if(!deep)break;
	}
	string cond=in.substr(0,i);//cond="x=10,y=20"
	if(DEBUG)cout << "cond = " << cond << endl;
	var result=runExpr(cond);
	if(result.t!=error)return result;
	if(result.t!=tBool)return var(error,typeError);

	in=in.substr(i+1);
	in=in.substr(in.find_first_of("("));
	cout << "true else false = " << in << endl;
	if(result.val==true){
		in=in.substr(0,in.find_first_of(")")+1);
		cout << "true = " << in << endl;
		return runExpr(in);
	}
	in=in.substr(in.find_first_of("(")+1);
	for(deep=1,i=0;(size_t)i<in.size();i++){
		if(in[i]=='(')deep++;
		if(in[i]==')')deep--;
		if(!deep)break;
	}
	in=in.substr(i+1);
	cout << "else false = " << in << endl;
	in=in.substr(in.find_first_of("("));
	cout << "false = " << in << endl;
	return runExpr(in);
}

var defineFunc(string& expr){
	miniHfunc f(expr);
	funcs[f.name]=f;
	return var(success);
}

var callFunc(string& func,string& args){
	return funcs[func].call(args);
}

var getVar(string& expr){
	return vars[expr];
}

var getBool(string& expr){
	if(expr=="true")return var(true);
	return var(false);
}

var getInt(string& expr){
	return var(atoi(expr.c_str()));
}

//binary operators start
void getBinOperatorVals(string& expr,var& val1,var& val2){
	int deep=0,middle=0;
	FOR(i,expr.size()){
		if(expr[i]=='(')deep++;
		if(expr[i]==')')deep--;
		if(expr[i]==',' && deep==0){
			middle=i;
			break;
		}
	}
	string s=expr.substr(0,middle);
	val1=runExpr(s);
	s=expr.substr(middle+1);
	val2=runExpr(s);
}

var sumOp(string& expr){//int,int -> int
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=tInt || val2.t!=tInt)return var();
	if(DEBUG)cout << "left = " << val1.val << " right = " << val2.val << endl;
	return var(val1.val+val2.val);
}

var subOp(string& expr){//int,int -> int
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=tInt || val2.t!=tInt)return var();
	if(DEBUG)cout << "left = " << val1.val << " right = " << val2.val << endl;
	return var(val1.val-val2.val);
}

var multOp(string& expr){//int,int -> int
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=tInt || val2.t!=tInt)return var();
	return var(val1.val*val2.val);
}

var divOp(string& expr){//int,int -> int
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=error)return val1;
	if(val2.t!=error)return val2;
	if(val1.t!=tInt || val2.t!=tInt)return var();
	if(val2.val==0)return var(error,div0Error);
	return var(val1.val/val2.val);
}

var andOp(string& expr){//bool,bool -> bool
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=error)return val1;
	if(val2.t!=error)return val2;
	if(val1.t!=tBool || val2.t!=tBool)return var();
	return var(val1.val && val2.val);
}

var orOp(string& expr){//bool,bool -> bool
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=error)return val1;
	if(val2.t!=error)return val2;
	if(val1.t!=tBool || val2.t!=tBool)return var();
	return var(val1.val || val2.val);
}

var eqOp(string& expr){//?,? -> bool
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=error)return val1;
	if(val2.t!=error)return val2;
	if(val1.t!=val2.t)return var();
	return var(val1.val == val2.val);
}

var gtOp(string& expr){//int,int -> bool
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=error)return val1;
	if(val2.t!=error)return val2;
	if(val1.t!=tInt || val2.t!=tInt)return var();
	return var(val1.val>val2.val);
}
	
var ltOp(string& expr){//int,int -> bool
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=error)return val1;
	if(val2.t!=error)return val2;
	if(val1.t!=tInt || val2.t!=tInt)return var();
	return var(val1.val<val2.val);
}

var geOp(string& expr){//int,int -> bool
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=error)return val1;
	if(val2.t!=error)return val2;
	if(val1.t!=tInt || val2.t!=tInt)return var();
	return var(val1.val>=val2.val);
}

var leOp(string& expr){//int,int -> bool
	var val1,val2;
	getBinOperatorVals(expr,val1,val2);
	if(val1.t!=error)return val1;
	if(val2.t!=error)return val2;
	if(val1.t!=tInt || val2.t!=tInt)return var();
	return var(val1.val<=val2.val);
}
//binary operators end

var notOp(string& expr){
	var val=runExpr(expr);
	if(val.t!=error)return val;
	if(val.t!=tBool)return var();
	return var(!val.val);
}

var runExpr(string& expr){
	if(DEBUG)cout << "running " << expr << endl;
	string start=get1stWord(expr);
	if(DEBUG)cout << "start = " << start << endl;
	if(start=="let"){//definir um valor para uma variavel nesse escopo//let(x=10)in(expr)
		if(DEBUG)cout << "detected 'let' expression" << endl;
		expr = expr.substr(get1stWordPos(expr).ss);
		return let(expr);
	}
	else if(start=="if"){//expressão condicional//if(bool)then(expr1)else(expr2)
		if(DEBUG)cout << "detected 'ifThenElse' expression" << endl;
		expr = expr.substr(get1stWordPos(expr).ss);
		return ifThenElse(expr);
	}
	else if(start=="def" || start=="define"){//declara uma função//define foo(int x,int y)=(x+y)
		if(DEBUG)cout << "detected 'define' expression" << endl;
		expr = expr.substr(get1stWordPos(expr).ss+1);
		//cout << expr << endl;
		return defineFunc(expr);
	}
	else if(funcs[start].name!=""){//função com esse nome esta declarada//foo(x,y)
		if(DEBUG)cout << "detected function call " << start << endl;
		expr = expr.substr(get1stWordPos(expr).ss+2);
		expr = expr.substr(0,expr.size()-1);
		return callFunc(start,expr);
	}
	else if(vars[start].t!=error){//variavel com esse nome esta definida//x
		if(DEBUG)cout << "detected variable " << start	 << endl;
		return getVar(start);
	}
	else if(lower_case(start)=="true" || lower_case(start)=="false"){//expressão é uma constante booleana true/false
		if(DEBUG)cout << "detected boolean constant " << endl;
		return getBool(start);
	}
	else{
		for(auto i:operators){//expressão é um dos operadores basicos("sum(x,y)","mult(x,y)","and(p,q)")
			if(start==i.ff){
				if(DEBUG)cout << "detected operator expression " << start << endl;
				expr = expr.substr(get1stWordPos(expr).ss+1);
				expr = expr.substr(0,expr.size()-1);
				return i.ss(expr);
			}
		}
		//expressão vai ser lida como um valor inteiro
		if(DEBUG)cout << "expression is being interpreted as an integer" << endl;
			return getInt(start);
	}
}
