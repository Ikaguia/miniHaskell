#include "header.hpp"

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

var listEmptyOp(vector<string> &in){//list -> bool
	var esq=runExpr(in[0]);
	if(esq.t==error)return esq;
	if(esq.t!=listBool && esq.t!=listInt)return var(error,typeError);
	return var(esq.li.size()==0);
}

var listHeadOp(vector<string> &in){//listInt -> int/listBool -> bool
	var esq=runExpr(in[0]);
	if(esq.t==error)return esq;
	if(esq.t!=listBool && esq.t!=listInt)return var(error,typeError);
	if(!esq.li.size())return var(error,emptyListtError);
	return var(esq.li[0]);
}

var listTailOp(vector<string> &in){//list -> list
	var esq=runExpr(in[0]);
	if(esq.t==error)return esq;
	if(esq.t!=listBool && esq.t!=listInt)return var(error,typeError);
	if(!esq.li.size())return var(error,emptyListtError);
	auto begin = esq.li.begin()+1;
	auto end = esq.li.end();
	esq.li=vector<int>(begin,end);
	return esq;
}

var listMergeOp(vector<string> &in){//int listInt -> listInt/bool listBool -> listBool
	var esq=runExpr(in[0]);
	var dir=runExpr(in[1]);
	//cout << "esq.t=" << esq.t << " dir.t=" << dir.t << endl;
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(!(esq.t==tBool && dir.t==listBool) && !(esq.t==tInt && dir.t==listInt))return var(error,typeError);
	dir.li.insert(dir.li.begin(),esq.val);
	return dir;
}
