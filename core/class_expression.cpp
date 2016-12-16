#include <bits/stdc++.h>
using namespace std;

#include "var.hpp"
#include "expression.hpp"

using ii = pair<int,int>;
#include "../util.hpp"

#define ff first
#define ss second

map<string,miniHfunc> funcs;
map<string,var> vars;

map<string,miniHfunc> funcs;
map<string,var> vars;
var integerListExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);

	var h=head->runExpr();
	if(h.t==error)return h;

	if(!tail){
		vector<int> v(1,h.val);
		return var(listInt,v);
	}

	var t=tail->runExpr();
	if(t.t==error)return t;

	t.li.insert(t.li.begin(),h.val);
	return var(listInt,t.li);
}


var booleanListExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);

	var h=head->runExpr();
	if(h.t==error)return h;

	if(!tail){
		vector<int> v(1,h.val);
		return var(listBool,v);
	}

	var t=tail->runExpr();
	if(t.t==error)return t;

	t.li.insert(t.li.begin(),h.val);
	return var(listBool,t.li);
}


var ifThenElseExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esq=cond->runExpr();//if
	if(esq.t==error)return esq;
	if(esq.val)
		return then->runExpr();//then
	else
		return els->runExpr();//else
}


var letExpression::runExpr(){
	printf("asd\n");
	if(isReserved(name)) return var(error,reservedError);
	printf("asd\n");
	if(!letter(name[0]) || !alphaNumeric(name))return var(error,invalidNameError);
	//for(auto i:vars)if(name==i.ff)return var(error,invalidNameError);
	printf("asd\n");
	for(auto i:funcs)if(name==i.ff)return var(error,invalidNameError);

	printf("asd\n");
	var newVar=newExp->runExpr();  //get new value
	if(newVar.t==error)return newVar;//return error

	oldVar=vars[name];//save old variable
	vars[name]=newVar;//replace old variable with new

	printf("asd\n");

	var ret=in->runExpr();//run the expression

	if(oldVar.t!=error)vars[name]=oldVar;//restore previous variable
	else vars.erase(name);               //or just erase it if there was none before

	return ret;
}


var variableExpression::runExpr(){
	return vars[name];
}


var defineExpression::runExpr(){
	if(isReserved(name))return var(error,reservedError);
	if(!letter(name[0]) || !alphaNumeric(name))return var(error,invalidNameError);
	for(auto i:vars)if(name==i.ff)return var(error,invalidNameError);
	for(auto i:funcs)if(name==i.ff)return var(error,invalidNameError);

	string s=args+",end";
	vector<string> v;
	vector<ts> argV;
	while(parse(s,"%s.%s,%s",v)){

		if(isReserved(v[1]))return var(error,reservedError);
		if(!letter(v[1][0]) || !alphaNumeric(v[1]))return var(error,invalidNameError);
		for(auto i:vars)if(v[1]==i.ff)return var(error,invalidNameError);
		for(auto i:funcs)if(v[1]==i.ff)return var(error,invalidNameError);

		if(v[0]=="int")argV.push_back(ts(tInt,v[1]));
		if(v[0]=="bool")argV.push_back(ts(tBool,v[1]));
		if(v[0]=="listInt")argV.push_back(ts(listInt,v[1]));
		if(v[0]=="listBool")argV.push_back(ts(listBool,v[1]));
		s=v[2];
	}
	miniHfunc f(name,argV,body);
	funcs[f.name]=f;
	//cout << "'" << f.name << "'" << endl;
	return var(success);
}


bool functionExpression::typeCheck(){
	FOR(i,args.size()){
		if(args[i]->retType()!=func.args[i].ff)return false;
	}
	return true;
}
var functionExpression::runExpr(){
	if(args.size()!=func.args.size())return var(error,argCountError);
	if(!typeCheck())return var(error,typeError);
	expression* temp=body;
	FOR(i,args.size()){
		temp=new letExpression(func.args[i].ss,args[i],temp);//let(varName=varExpression)in(body)
	}
	var ret=temp->runExpr();
	delete temp;
	return ret;
}


var sumExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	return var(esqVar.val + dirVar.val);
}


var subExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	return var(esqVar.val - dirVar.val);
}


var multExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	return var(esqVar.val * dirVar.val);
}


var divExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	if(esqVar.val==0)return var(error,div0Error);
	return var(esqVar.val / dirVar.val);
}


var andExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	return var(esqVar.val && dirVar.val);
}


var orExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	return var(esqVar.val || dirVar.val);
}


var notExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	if(esqVar.t==error)return esqVar;
	return var(!esqVar.val);
}


var eqExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	if(esqVar.t==listInt || esqVar.t==listBool)return (esqVar.li==dirVar.li);
	return var(esqVar.val == dirVar.val);
}


var gtExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	return var(esqVar.val > dirVar.val);
}


var ltExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	return var(esqVar.val < dirVar.val);
}


var geExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	return var(esqVar.val >= dirVar.val);
}


var leExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esqVar;
	if(dirVar.t==error)return dirVar;
	return var(esqVar.val <= dirVar.val);
}


var listHeadExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var liVar=li->runExpr();
	if(liVar.t==error)return liVar;
	return var(liVar.li[0]);
}


var listTailExpression::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var liVar=li->runExpr();
	if(liVar.t==error)return liVar;
	vector<int> v(liVar.li.begin()+1,liVar.li.end());
	return var(liVar.t,v);
}

