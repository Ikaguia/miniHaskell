#include "header.hpp"

miniHfunc::miniHfunc():name{""}{}
miniHfunc::miniHfunc(const string &n,const vector<ts> &ar,const string& b):name{n},args{ar},body{b}{};

var miniHfunc::call(string s){
	/*string code="";
	string expr=body;
	FOR(i,args.size()){
		if(i)code+=",";
		code+="%s";
	}
	vector<string> vs;
	vector<var> vv;
	//cout << "code = " << code << endl;
	parse(s,code,vs);
	//cout << args.size() << endl;
	FOR(i,args.size()){
		vv.push_back(runExpr(vs[i]));
		if(DEBUG)cout << "passed arg[" << i << "] = " << vs[i] << " with type " << vv[i].t << endl;
		if(DEBUG)cout << "expected arg[" << i << "] with type " << args[i].ff << endl;
		if(vv[i].t!=args[i].ff)return var(error,typeError);
		expr="let("+args[i].ss+"="+vv[i].str()+")in("+expr+")";
	}

	return runExpr(expr);*/
	return var(error);
}
