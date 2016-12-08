#ifndef exprHeader
#define epxrHeader

class expression{
public:
	vector<expression*> filhos;

	virtual type retType()=0;
	virtual bool runExpr()=0;
	virtual var  typeCheck(vector<var> v)=0;
};

class integer : public expression{
	int val;
	integer(int v):val{v}{};

	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr(){return var(val);}
};

class boolean : public expression{
	bool val;
	boolean(bool v):val{v}{};

	virtual type retType(){return tBool;};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr(){return var(val);}
};

class ifThenElse : public expression{
	ifThenElse(expression*,expression*,expression*);
	virtual type retType(){return filhos[1]->retType();};
	virtual bool typeCheck(){return filhos[0]->retType==bool && filhos[1]->retType==filhos[2]->retType;}
	virtual var  runExpr();
};

class let : public expression{
	string name;
	var oldVar;
	let(string,expression*,expression*);
	virtual type retType(){return filhos[2]->retType();};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr();
};

class define : public expression{
	string name,args,body;
	define(string n,string a,string b):name{n},args{a},body{b}{};
	virtual type retType(){return success;};
	virtual bool typeCheck(){return true;}
	virtual var  runExpr();
};

class sum : public expression{
	sum(expression* esq,expression* dir);
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return filhos[0]->retType==tInt && filhos[1]->retType==tInt;}
	virtual var  runExpr();
};

class sub : public expression{
	sub(expression* esq,expression* dir);
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return filhos[0]->retType==tInt && filhos[1]->retType==tInt;}
	virtual var  runExpr();
};

class mult : public expression{
	mult(expression* esq,expression* dir);
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return filhos[0]->retType==tInt && filhos[1]->retType==tInt;}
	virtual var  runExpr();
};

class div : public expression{
	div(expression* esq,expression* dir);
	virtual type retType(){return tInt;};
	virtual bool typeCheck(){return filhos[0]->retType==tInt && filhos[1]->retType==tInt;}
	virtual var  runExpr();
};

#endif exprHeader
