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

class integerList : public expression{
public:
	expression *head;
	expression *tail;
	integerList(expression *h,expression *t):head{h},tail{t}{};

	virtual type retType(){return listInt;};
	virtual bool typeCheck(){return head->retType()==tInt && tail->retType()==listInt;}
	virtual var  runExpr();
};

class booleanList : public expression{
public:
	expression *head;
	expression *tail;
	booleanList(expression *h,expression *t):head{h},tail{t}{};

	virtual type retType(){return listBool;};
	virtual bool typeCheck(){return head->retType()==tBool && tail->retType()==listBool;}
	virtual var  runExpr();
};

class ifThenElse : public expression{
public:
	expression *cond,*then,*els;
	ifThenElse(expression* c,expression* t,expression* e):cond{c},then{t},els{e}{};
	~ifThenElse(){
		delete cond;
		delete then;
		delete els;
	};
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
	~let(){
		delete newExp;
		delete in;
	}
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

class function : public expression{
public:
	miniHfunc* func;
	vector<expression*> args;
	expression* body;
	function(string s,vector<expression*> a):func{funcs[s].ss},args{a},body{build(func->body)}{};
	~function(){
		for(auto i:args)delete i;
		delete body;
	}
	virtual type retType(){return body->retType();};
	virtual bool typeCheck();
	virtual var  runExpr();
};

class sum : public expression{
public:
	expression *esq,*dir;
	sum(expression* e,expression* d):esq{e},dir{d}{};
	~sum(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class sub : public expression{
public:
	expression *esq,*dir;
	sub(expression* e,expression* d):esq{e},dir{d}{};
	~sub(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class mult : public expression{
public:
	expression *esq,*dir;
	mult(expression* e,expression* d):esq{e},dir{d}{};
	~mult(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class div : public expression{
public:
	expression *esq,*dir;
	div(expression* e,expression* d):esq{e},dir{d}{};
	~div(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class and : public expression{
public:
	expression *esq,*dir;
	and(expression* e,expression* d):esq{e},dir{d}{};
	~and(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tBool;};
	virtual bool typeCheck(){return esq->retType()==tBool && esq->retType()==tBool;}
	virtual var  runExpr();
};

class or : public expression{
public:
	expression *esq,*dir;
	or(expression* e,expression* d):esq{e},dir{d}{};
	~or(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tBool;};
	virtual bool typeCheck(){return esq->retType()==tBool && esq->retType()==tBool;}
	virtual var  runExpr();
};

class not : public expression{
public:
	expression *esq;
	not(expression* e):esq{e}{};
	~not(){
		delete esq;
	}
	virtual type retType(){return tBool;};
	virtual bool typeCheck(){return esq->retType()==tBool;}
	virtual var  runExpr();
};

#endif //exprHeader
