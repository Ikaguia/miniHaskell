#ifndef exprHeader
#define epxrHeader

class expression{
public:
	virtual type retType()=0;
	virtual bool typeCheck()=0;
	virtual var  runExpr()=0;
};

class integer : public expression{
public:
	int val;
	integer(int v):val{v}{};

	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr(){return var(val);}
};

class boolean : public expression{
public:
	bool val;
	boolean(bool v):val{v}{};

	virtual type retType(){return tBool;};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr(){return var(val);}
};

class ifThenElse : public expression{
public:
	expression *cond,*then,*els;
	ifThenElse(expression* c,expression* t,expression* e):cond{c},then{t},els{e}{};
	virtual type retType(){return then->retType();};
	virtual bool typeCheck(){return cond->retType()==tBool && then->retType()==els->retType();}
	virtual var  runExpr();
};

class let : public expression{
public:
	string name;
	expression *newExp,*in;
	var oldVar;
	let(string n,expression* e,expression* i):name{n},newExp{e},in{i}{};
	virtual type retType(){return in->retType();};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr();
};

class define : public expression{
public:
	string name,args,body;
	define(string n,string a,string b):name{n},args{a},body{b}{};
	virtual type retType(){return success;};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr();
};

class sum : public expression{
public:
	expression *esq,*dir;
	sum(expression* e,expression* d):esq{e},dir{d}{};
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class sub : public expression{
public:
	expression *esq,*dir;
	sub(expression* e,expression* d):esq{e},dir{d}{};
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class mult : public expression{
public:
	expression *esq,*dir;
	mult(expression* e,expression* d):esq{e},dir{d}{};
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class div : public expression{
public:
	expression *esq,*dir;
	div(expression* e,expression* d):esq{e},dir{d}{};
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

#endif //exprHeader
