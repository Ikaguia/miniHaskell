#include "header.hpp"

void let(string& in){//(x=10)in(...)
	string name=get1stWord(in);//name="x"
	in = in.substr(get1stWordPos(in).ss);//in="=10)in(...)"
	string val = get1stWord(in);//val="10"
	in = in.substr(get1stWordPos(in).ss);//in=")in(...)"
	in = in.substr(get1stWordPos(in).ss);//in="(...)"
	in = in.substr(1,in.size()-2);//in="..."
	if(val=="true"){
		cout << name << " = bool(true)" << endl;
		vars[name]=var((bool)true);
	}
	else if(val=="false"){
		cout << name << " = bool(false)" << endl;
		vars[name]=var((bool)false);
	}
	else{
		int valI=atoi(val.c_str());
		cout << name << " = int(" << valI << ")" << endl;
		vars[name]=var(valI);
	}
	cout << vars[name].t << endl;
	cout << in << endl;	
}

var sum(string& expr){
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
	return var(val1.val+val2.val);
}

var runExpr(string& expr){
	string start=get1stWord(expr);
	if(start=="let"){//let(x=10)in(y)
		expr=expr.substr(3);
		let(expr);
		return runExpr(expr);
	}
	else if(start=="sum"){//sum(x,y)
		expr=expr.substr(4,expr.size()-5);
		return sum(expr);
	}
	else if(funcs[start].name!=""){//função com esse nome esta definida //foo(x,y)
		expr = expr.substr(get1stWordPos(expr).ss);
	}
	else if(vars[start].t!=error){//variavel com esse nome esta definida //x
		return vars[start];
	}
	else if(start=="true")return var(true);
	else if(start=="false")return var(false);
	return var(atoi(start.c_str()));
}
