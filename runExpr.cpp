#include "header.hpp"

var let(string& in){//(x=10)in(...)
	var temp;
	string name=get1stWord(in);//name="x"
	in = in.substr(get1stWordPos(in).ss);//in="10)in(...)"
	int i=0,deep=1;
	while(1){
		if(in[i]=='(')deep++;
		if(in[i]==')')deep--;
		if(!deep)break;
		i++;
	}
	string t=in.substr(1,i-1);
	if(vars[name].t!=error)temp=vars[name];
	vars[name]=runExpr(t);
	cout << "var(" << name << ") = " << (vars[name].t==(char)tInt?"int":"bool") << "(" << vars[name].val << ")" << endl;
	//cout << "in0 = " << in << endl;
	in=in.substr(i+1);//in=")in(...)"
	cout << "in1 = " << in << endl;
	in=in.substr(in.find_first_of("("));//in="(...)"
	in=in.substr(1,in.size()-2);//in="..."
	cout << "in2 = " << in << endl;

	var result = runExpr(in);

	if(temp.t!=error)vars[name]=temp;
	else vars.erase(name);

	return result;
}

var defineFunc(string& expr){
	miniHfunc f(expr);
	funcs[f.name]=f;
	return var(sucess);//var with type=sucess
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

var sumOp(string& expr){
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
	var val1=runExpr(s);
	s=expr.substr(middle+1);
	var val2=runExpr(s);
	if(val1.t!=tInt || val2.t!=tInt)return var();
	cout << "left = " << val1.val << " right = " << val2.val << endl;
	return var(val1.val+val2.val);
}

var multOp(string& expr){
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
	var val1=runExpr(s);
	s=expr.substr(middle+1);
	var val2=runExpr(s);
	if(val1.t!=tInt || val2.t!=tInt)return var();
	return var(val1.val*val2.val);
}

var andOp(string& expr){
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
	var val1=runExpr(s);
	s=expr.substr(middle+1);
	var val2=runExpr(s);
	if(val1.t!=tBool || val2.t!=tBool)return var();
	return var(val1.val && val2.val);
}

var orOp(string& expr){
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
	var val1=runExpr(s);
	s=expr.substr(middle+1);
	var val2=runExpr(s);
	if(val1.t!=tBool || val2.t!=tBool)return var();
	return var(val1.val || val2.val);
}

var notOp(string& expr){
	var val=runExpr(expr);
	if(val.t!=tBool)return var();
	return var(!val.val);
}

using funcT=var(string&);
using funcP=funcT*;
using psf=pair<string,funcP>;
psf operators[]={
	psf("sum", (funcP)sumOp),
	psf("mult",(funcP)multOp),
	psf("and", (funcP)andOp),
	psf("or", (funcP)orOp),
	psf("not", (funcP)notOp),
};


var runExpr(string& expr){
	cout << "running " << expr << endl;
	string start=get1stWord(expr);
	cout << "start = " << start << endl;	
	if(start=="let"){//definir um valor para uma variavel nesse escopo//let(x=10)in(expr)
		cout << "detected 'let' expression" << endl;
		expr = expr.substr(get1stWordPos(expr).ss+1);
		return let(expr);
	}
	else if(start=="def" || start=="define"){//declara uma função//define foo(int x,int y)=(x+y)
		cout << "detected 'define' expression" << endl;
		expr = expr.substr(get1stWordPos(expr).ss+2);
		expr = expr.substr(0,expr.size()-1);
		return defineFunc(expr);
	}
	else if(funcs[start].name!=""){//função com esse nome esta declarada//foo(x,y)
		cout << "detected function call " << start << endl;
		expr = expr.substr(get1stWordPos(expr).ss+2);
		expr = expr.substr(0,expr.size()-1);
		return callFunc(start,expr);
	}
	else if(vars[start].t!=error){//variavel com esse nome esta definida//x
		cout << "detected variable " << start	 << endl;
		return getVar(start);
	}
	else if(lower_case(start)=="true" || lower_case(start)=="false"){//expressão é uma constante booleana true/false
		cout << "detected boolean constant " << endl;
		return getBool(start);
	}
	else{
		for(auto i:operators){//expressão é um dos operadores basicos("sum(x,y)","mult(x,y)","and(p,q)")
			if(start==i.ff){
				cout << "detected operator expression " << start << endl;
				expr = expr.substr(get1stWordPos(expr).ss+1);
				expr = expr.substr(0,expr.size()-1);
				return i.ss(expr);
			}
		}
		//expressão vai ser lida como um valor inteiro
		cout << "expression is being interpreted as an integer" << endl;
		return getInt(start);
	}
}
