#include "header.hpp"

var operat::call(string s){
	vector<string> v;
	if(parse(s,code,v))return func(v);
	cout << "parse failed" << endl;
	return var(error);
}

var let(vector<string> &in){

	for(auto i:reservedWords)if(i==in[0]){
		return var(error,reservedError);
	}
	for(auto i:operators)if(i.name==in[0]){
		return var(error,reservedError);
	}

	var before=vars[in[0]];

	var temp=runExpr(in[1]);
	if(temp.t==error)return temp;
	vars[in[0]]=temp;

	var result=runExpr(in[2]);

	if(before.t==error)vars.erase(in[0]);
	else vars[in[0]]=before;

	return result;
}

var ifThenElse(vector<string> &in){
	var cond=runExpr(in[0]);
	var then=runExpr(in[1]);
	var els =runExpr(in[2]);
	if(cond.t==error)return cond;
	if(then.t==error)return then;
	if(els.t==error)return els;
	if(cond.t!=tBool || then.t!=els.t)return var(error,typeError);
	if(cond.val)return then;
	return els;
}

var define(vector<string> &in){
	miniHfunc f(in);
	funcs[f.name]=f;
	return var(success);
}

var sumOp(vector<string> &in){//int int -> int
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=tInt || dir.t!=tInt)return var(error,typeError);
	return esq.val+dir.val;
}

var subOp(vector<string> &in){//int int -> int
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=tInt || dir.t!=tInt)return var(error,typeError);
	return esq.val-dir.val;
}

var multOp(vector<string> &in){//int int -> int
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=tInt || dir.t!=tInt)return var(error,typeError);
	return esq.val*dir.val;
}

var divOp(vector<string> &in){//int int -> int
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=tInt || dir.t!=tInt)return var(error,typeError);
	if(dir.val==0)return var(error,div0Error);
	return esq.val/dir.val;
}

var andOp(vector<string> &in){//bool bool -> bool
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=tBool || dir.t!=tBool)return var(error,typeError);
	return esq.val && dir.val;
}

var orOp(vector<string> &in){//bool bool -> bool
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=tBool || dir.t!=tBool)return var(error,typeError);
	return esq.val || dir.val;
}

var eqOp(vector<string> &in){//? ? -> bool
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=dir.t)return var(error,typeError);
	return esq.val == dir.val;
}

var gtOp(vector<string> &in){//int int -> bool
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=tInt || dir.t!=tInt)return var(error,typeError);
	return esq.val > dir.val;
}

var ltOp(vector<string> &in){//int int -> bool
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=tInt || dir.t!=tInt)return var(error,typeError);
	return esq.val < dir.val;
}

var geOp(vector<string> &in){//int int -> bool
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=tInt || dir.t!=tInt)return var(error,typeError);
	return esq.val >= dir.val;
}

var leOp(vector<string> &in){//int int -> bool
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.t!=tInt || dir.t!=tInt)return var(error,typeError);
	return esq.val <= dir.val;
}

var notOp(vector<string> &in){//bool -> bool
	var esq=runExpr(in[0]);
	if(esq.t==error)return esq;
	if(esq.t!=tBool)return var(error,typeError);
	return !esq.val;
}
