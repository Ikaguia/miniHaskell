#include "header.hpp"

var operat::call(string s){
	vector<string> v;
	if(parse(s,code,v)){
		var result=func(v);
		if(DEBUG){
			cout << "called operator " << name << " with args (";
			for(auto i:v)cout << i << " ";
			cout << ") with vars(";
			for(auto i:vars)cout << "'" << i.ff << "'='"<< i.ss.str() << "' ";
			cout << ") returned " << result.str() << endl;
		}
		return result;
	}
	if(DEBUG)cout << "parse failed" << endl;
	return var(error,parsingError);
}

var let(vector<string> &in){

	if(isReserved(in[0]))return var(error,reservedError);
	if(!letter(in[0][0]) || !alphaNumeric(in[0]))return var(error,invalidNameError);

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
	/* essa versão foi removida pois fica impossivel declarar funções do tipo
	foo(listInt l)=(if(listEmpty)then(0)else(sum(listHeader(l),foo(listTail(l)))))//função que retorna a soma de todos os elementos de uma lista de inteiros
	pois o tipo retornado por listHeader de uma lista vazia é error
	if(then.t==error)return then;
	if(els.t==error)return els;
	if(cond.t!=tBool || then.t!=els.t)return var(error,typeError);
	if(cond.val)return then;
	return els;*/
	if(cond.val)return then;
	return els;
}

var define(vector<string> &in){
	string a=in[1]+",end";
	vector<string> v;
	vector<ts> args;
	while(parse(a,"%s.%s,%s",v)){
		//cout << v[0] << " " << v[1] << " " << v[2] << endl;
		if(isReserved(v[2]))return var(error,reservedError);
		if(!letter(v[2][0]) || !alphaNumeric(v[2]))return var(error,invalidNameError);
		if(v[0]=="int")args.push_back(ts(tInt,v[1]));
		if(v[0]=="bool")args.push_back(ts(tBool,v[1]));
		if(v[0]=="listInt")args.push_back(ts(listInt,v[1]));
		if(v[0]=="listBool")args.push_back(ts(listBool,v[1]));
		a=v[2];
	}
	miniHfunc f(in[0],args,in[2]);
	funcs[f.name]=f;
	//cout << "'" << f.name << "'" << endl;
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
