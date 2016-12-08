#include "header.hpp"

ifThenElse::ifThenElse(expression* cond,expression* then,expression* els){
	filhos.push_back(cond);
	filhos.push_back(then);
	filhos.push_back(els);
}
virtual var ifThenElse::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esq=filhos[0].runExpr();//if
	if(esq.t==error)return esq;
	if(esq.val)
		return filhos[1].runExpr();//then
	else
		return filhos[2].runExpr();//else
}


let::let(string n,expression* val,expression* in):name{n}{
	filhos.push_back(val);
	filhos.push_back(in);
}
virtual var let::runExpr(){
	var newVar=filhos[1].runExpr();  //get new value
	if(newVar.t==error)return newVar;//return error

	oldVar=vars[filhos[0]];//save old variable
	vars[filhos[0]]=newVar;//replace old variable with new

	var ret=filhos[2].runExpr();//run the expression

	if(oldVar.t!=error)vars[filhos[0]]=oldVar;//restore previous variable
	else vars.remove(filhos[0]);              //or just remove it if there was none before

	return ret;
}


sum::sum(expression* esq,expression* dir){
	filhos.push_back(esq);
	filhos.push_back(dir);
}
virtual var sum::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esq=filhos[0].runExpr();
	var dir=filhos[1].runExpr();
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	return var(esq.val + dir.val);
}


sub::sub(expression* esq,expression* dir){
	filhos.push_back(esq);
	filhos.push_back(dir);
}
virtual var sub::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esq=filhos[0].runExpr();
	var dir=filhos[1].runExpr();
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	return var(esq.val - dir.val);
}


mult::mult(expression* esq,expression* dir){
	filhos.push_back(esq);
	filhos.push_back(dir);
}
virtual var mult::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esq=filhos[0].runExpr();
	var dir=filhos[1].runExpr();
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	return var(esq.val * dir.val);
}


div::div(expression* esq,expression* dir){
	filhos.push_back(esq);
	filhos.push_back(dir);
}
virtual var div::runExpr(){
	if(!typeCheck())return var(error,typeError);
	var esq=filhos[0].runExpr();
	var dir=filhos[1].runExpr();
	if(esq.t==error)return esq;
	if(dir.t==error)return dir;
	if(esq.val==0)return var(error,div0Error);
	return var(esq.val * dir.val);
}
