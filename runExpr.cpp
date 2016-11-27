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
	cout << "running expr " << t << endl;
	if(vars[name].t!=error)temp=vars[name];
	vars[name]=runExpr(t);
	cout << "var(" << name << ") = " << (vars[name].t==(char)tInt?"int":"bool") << "(" << vars[name].val << ")" << endl;
	cout << "in1 = " << in << endl;
	in=in.substr(i+1);//in=")in(...)"
	cout << "in2 = " << in << endl;
	in=in.substr(in.find_first_of("("));//in="(...)"
	in=in.substr(1,in.size()-2);//in="..."
	cout << "in3 = " << in << endl;

	if(temp.t!=error)vars[name]=temp;
	else vars.erase(name);
	return runExpr(in);
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
	cout << "running " << expr << endl;
	string start=get1stWord(expr);
	if(start=="let"){//let(x=10)in(expr)
		expr=expr.substr(get1stWordPos(expr).ss+1);
		return let(expr);
	}
	else if(start=="sum"){//sum(x,y)
		expr=expr.substr(get1stWordPos(expr).ss+1);
		expr=expr.substr(0,expr.size()-1);
		return sum(expr);
	}
	else if(funcs[start].name!=""){//função com esse nome esta definida //foo(x,y)
		expr = expr.substr(get1stWordPos(expr).ss);
		funcs[start].call(expr);
	}
	else if(vars[start].t!=error){//variavel com esse nome esta definida //x
		return vars[start];
	}
	else if(start=="true")return var(true);
	else if(start=="false")return var(false);
	return var(atoi(start.c_str()));
}
