#include "header.hpp"

virtual var ifThenElse::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esq=cond->runExpr();//if
	if(esq.t==error)return esq;
	if(esq.val)
		return then->runExpr();//then
	else
		return els->runExpr();//else
}


virtual var let::runExpr(){
	var newVar=newExp->runExpr();  //get new value
	if(newVar.t==error)return newVar;//return error

	oldVar=vars[name];//save old variable
	vars[name]=newVar;//replace old variable with new

	var ret=in->runExpr();//run the expression

	if(oldVar.t!=error)vars[name]=oldVar;//restore previous variable
	else vars.remove(name);              //or just remove it if there was none before

	return ret;
}


virtual var define::runExpr(){
	return var(error);//TODO
}


virtual var sum::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esq;
	if(dirVar.t==error)return dir;
	return var(esqVar.val + dirVar.val);
}


virtual var sub::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esq;
	if(dirVar.t==error)return dir;
	return var(esqVar.val - dirVar.val);
}


mult::mult(expression* esq,expression* dir){
	filhos.push_back(esq);
	filhos.push_back(dir);
}
virtual var mult::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esq;
	if(dirVar.t==error)return dir;
	return var(esqVar.val * dirVar.val);
}


virtual var div::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esqVar=esq->runExpr();
	var dirVar=dir->runExpr();
	if(esqVar.t==error)return esq;
	if(dirVar.t==error)return dir;
	if(esqVar.val==0)return var(error,div0Error);
	return var(esqVar.val / dirVar.val);
}
