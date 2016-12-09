#include "header.hpp"

var integerList::runExpr(){
	if(!typeCheck())return var(error,typeError);

	var h=head->runExpr();
	if(h.t==error)return h;

	if(!tail)return var(listInt,vector<int>(1,h.val);)

	var t=tail->runExpr();
	if(t.t==error)return t;

	t.li.insert(t.li.begin(),h.val);
	return var(listInt,t.li);
}


var booleanList::runExpr(){
	if(!typeCheck())return var(error,typeError);

	var h=head->runExpr();
	if(h.t==error)return h;

	if(!tail)return var(listBool,vector<int>(1,h.val);)

	var t=tail->runExpr();
	if(t.t==error)return t;

	t.li.insert(t.li.begin(),h.val);
	return var(listBool,t.li);
}


var ifThenElse::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esq=cond->runExpr();//if
	if(esq.t==error)return esq;
	if(esq.val)
		return then->runExpr();//then
	else
		return els->runExpr();//else
}


var let::runExpr(){
	if(isReserved(name))return var(error,reservedError);
	if(!letter(name[0]) || !alphaNumeric(name))return var(error,invalidNameError);
	//for(auto i:vars)if(name==i.ff)return var(error,invalidNameError);
	for(auto i:funcs)if(name==i.ff)return var(error,invalidNameError);

	var newVar=newExp->runExpr();  //get new value
	if(newVar.t==error)return newVar;//return error

	oldVar=vars[name];//save old variable
	vars[name]=newVar;//replace old variable with new

	var ret=in->runExpr();//run the expression

	if(oldVar.t!=error)vars[name]=oldVar;//restore previous variable
	else vars.erase(name);               //or just erase it if there was none before

	return ret;
}


var define::runExpr(){
	if(isReserved(name))return var(error,reservedError);
	if(!letter(name[0]) || !alphaNumeric(name))return var(error,invalidNameError);
	for(auto i:vars)if(name==i.ff)return var(error,invalidNameError);
	for(auto i:funcs)if(name==i.ff)return var(error,invalidNameError);

	string s=args+",end";
	vector<string> v;
	vector<ts> argV;
	while(parse(a,"%s.%s,%s",v)){

		if(isReserved(v[1]))return var(error,reservedError);
		if(!letter(v[1][0]) || !alphaNumeric(v[1]))return var(error,invalidNameError);
		for(auto i:vars)if(v[1]==i.ff)return var(error,invalidNameError);
		for(auto i:funcs)if(v[1]==i.ff)return var(error,invalidNameError);

		if(v[0]=="int")argV.push_back(ts(tInt,v[1]));
		if(v[0]=="bool")argV.push_back(ts(tBool,v[1]));
		if(v[0]=="listInt")argV.push_back(ts(listInt,v[1]));
		if(v[0]=="listBool")argV.push_back(ts(listBool,v[1]));
		a=v[2];
	}
	miniHfunc f(name,argV,body);
	funcs[f.name]=f;
	//cout << "'" << f.name << "'" << endl;
	return var(success);
}


bool function::typeCheck(){
	FOR(i,args.size()){
		if(args[i]->retType()!=func->args[i].ff)return false;
	}
	return true;
}

var function::runExpr(){
	if(args.size()!=func->args.size())return var(error,argCountError);
	if(!typeCheck())return var(error,typeError);
	expression* temp=body;
	FOR(i,args.size()){
		temp=new let(func->args[i].ss,args[i],temp);//let(varName=varExpression)in(body)
	}
	var ret=temp->runExpr();
	delete temp;
	return ret;
}


var sum::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esq;
	if(dirVar.t==error)return dir;
	return var(esqVar.val + dirVar.val);
}


var sub::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esq;
	if(dirVar.t==error)return dir;
	return var(esqVar.val - dirVar.val);
}


var mult::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esq;
	if(dirVar.t==error)return dir;
	return var(esqVar.val * dirVar.val);
}


var div::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esq;
	if(dirVar.t==error)return dir;
	if(esqVar.val==0)return var(error,div0Error);
	return var(esqVar.val / dirVar.val);
}

var and::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esq;
	if(dirVar.t==error)return dir;
	return var(esqVar.val && dirVar.val);
}

var or::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esq;
	if(dirVar.t==error)return dir;
	return var(esqVar.val || dirVar.val);
}

var not::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	if(esqVar.t==error)return esq;
	return var(!esqVar.val);
}

