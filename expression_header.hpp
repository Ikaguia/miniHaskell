#ifndef exprHeader
#define epxrHeader

class expression{
public:
	virtual ~expression(){};
	virtual type retType()=0;
	virtual bool typeCheck()=0;
	virtual var  runExpr()=0;
};

class integerExpression : public expression{
public:
	int val;
	integerExpression(int v):val{v}{};

	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr(){return var(val);}
};

class booleanExpression : public expression{
public:
	bool val;
	booleanExpression(bool v):val{v}{};

	virtual type retType(){return tBool;};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr(){return var(val);}
};

class integerListExpression : public expression{
public:
	expression *head;
	expression *tail;
	integerListExpression(expression *h,expression *t):head{h},tail{t}{};

	virtual type retType(){return listInt;};
	virtual bool typeCheck(){return head->retType()==tInt && tail->retType()==listInt;}
	virtual var  runExpr();
};

class booleanListExpression : public expression{
public:
	expression *head;
	expression *tail;
	booleanListExpression(expression *h,expression *t):head{h},tail{t}{};

	virtual type retType(){return listBool;};
	virtual bool typeCheck(){return head->retType()==tBool && tail->retType()==listBool;}
	virtual var  runExpr();
};

class ifThenElseExpression : public expression{
public:
	expression *cond,*then,*els;
	ifThenElseExpression(expression* c,expression* t,expression* e):cond{c},then{t},els{e}{};
	virtual ~ifThenElseExpression(){
		delete cond;
		delete then;
		delete els;
	};
	virtual type retType(){return then->retType();};
	virtual bool typeCheck(){return cond->retType()==tBool && then->retType()==els->retType();}
	virtual var  runExpr();
};

class letExpression : public expression{
public:
	string name;
	expression *newExp,*in;
	var oldVar;
	letExpression(string n,expression* e,expression* i):name{n},newExp{e},in{i}{};
	virtual ~letExpression(){
		delete newExp;
		delete in;
	}
	virtual type retType(){return in->retType();};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr();
};

class defineExpression : public expression{
public:
	string name,args,body;
	defineExpression(string n,string a,string b):name{n},args{a},body{b}{};
	virtual type retType(){return success;};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr();
};

class functionExpression : public expression{
public:
	miniHfunc &func;
	vector<expression*> args;
	expression* body;
	functionExpression(string s,vector<expression*> a):func{funcs[s]},args{a},body{builder(func.body)}{};
	virtual ~functionExpression(){
		for(auto i:args)delete i;
		delete body;
	}
	virtual type retType(){return body->retType();};
	virtual bool typeCheck();
	virtual var  runExpr();
};

class sumExpression : public expression{
public:
	expression *esq,*dir;
	sumExpression(expression* e,expression* d):esq{e},dir{d}{};
	virtual ~sumExpression(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class subExpression : public expression{
public:
	expression *esq,*dir;
	subExpression(expression* e,expression* d):esq{e},dir{d}{};
	virtual ~subExpression(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class multExpression : public expression{
public:
	expression *esq,*dir;
	multExpression(expression* e,expression* d):esq{e},dir{d}{};
	virtual ~multExpression(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class divExpression : public expression{
public:
	expression *esq,*dir;
	divExpression(expression* e,expression* d):esq{e},dir{d}{};
	virtual ~divExpression(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return esq->retType()==tInt && esq->retType()==tInt;}
	virtual var  runExpr();
};

class andExpression : public expression{
public:
	expression *esq,*dir;
	andExpression(expression* e,expression* d):esq{e},dir{d}{};
	virtual ~andExpression(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tBool;};
	virtual bool typeCheck(){return esq->retType()==tBool && esq->retType()==tBool;}
	virtual var  runExpr();
};

class orExpression : public expression{
public:
	expression *esq,*dir;
	orExpression(expression* e,expression* d):esq{e},dir{d}{};
	virtual ~orExpression(){
		delete esq;
		delete dir;
	}
	virtual type retType(){return tBool;};
	virtual bool typeCheck(){return esq->retType()==tBool && esq->retType()==tBool;}
	virtual var  runExpr();
};

class notExpression : public expression{
public:
	expression *esq;
	notExpression(expression* e):esq{e}{};
	virtual ~notExpression(){
		delete esq;
	}
	virtual type retType(){return tBool;};
	virtual bool typeCheck(){return esq->retType()==tBool;}
	virtual var  runExpr();
};

#endif //exprHeader
