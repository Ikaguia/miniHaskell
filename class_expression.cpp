#include "header.hpp"

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
	return var(error);//TODO
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
