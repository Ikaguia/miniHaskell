#ifndef miniHheader
#define miniHheader

#include <bits/stdc++.h>
//#include <math.h>
//#include <unistd.h>
using namespace std;

#define DEBUG true

#define FOR(cont,max)			for(int (cont)=0;		(cont)<(int)(max);(cont)++)
#define FOR2(cont,start,max)	for(int (cont)=(start);	(cont)<(int)(max);(cont)++)
#define BETWEEN(x,a,b)			(((x)>=(a)) && ((x)<(b)))
#define SWAP(a,b)				int _temp_=(a);(a)=(b);(b)=_temp_;
#define RAND(max)				(rand()%(max))
#define RAND2(min,max)			((min)+(rand()%((max)-(min))))


using ii = pair<int,int>;
#define ff first
#define ss second

typedef enum{
	defError,
	funcError,
	typeError,
	reservedError,
	div0Error,
	invalidExprError,
} errorID;
const string errorMsgs[] = {
	"ERROR",
	"ERROR CALL function not implemented",
	"ERROR invalid type",
	"ERROR reserved words",
	"ERROR division by 0",
	"ERROR invalid expression",
};
const string reservedWords[] = {"int","bool","true","false","let","def","define"};

//var
typedef enum{tInt,tBool,error,success} type;
using ts = pair<type,string>;

class var{
public:
	type t;
	int val;
	var():t{error},val{0}{};
	var(type x):t{x},val{0}{};
	var(type x,int y):t{x},val{y}{};
	var(bool v):t{tBool},val{v}{};
	var(int v):t{tInt},val{v}{};
	string str(){
		if(t==success)return "SUCCESS";
		if(t==error)return errorMsgs[val];
		if(t==tBool)return val?"TRUE":"FALSE";
		return to_string(val);
	}
};

//miniHfunc
class miniHfunc{
public:
	string name;
	vector<ts> args;
	string body;
	miniHfunc(vector<string>&);
	miniHfunc();
	var call(string);
};

//utilFuncs
extern bool strStartsWith(const string&,const string&);
extern bool strEndsWith(const string&,const string&);
extern ii get1stWordPos(const string&,string ignore=" 	\n,.();\"\'=");
extern string get1stWord(const string&,string ignore=" 	\n,.();\"\'=");
extern string lower_case(const string&);
extern string upper_case(const string&);
extern string noSpaces(string);
extern bool parse(string,string,vector<string>&);

//operators
using funcT=var(vector<string>&);
using funcP=funcT*;
class operat{
public:
	string name;
	string code;
	funcP func;
	operat(string n,string c,funcP f):name{n},code{c},func{f}{}
	var call(string s);
};

extern vector<operat> operators;
extern var let(vector<string>			&expr);
extern var ifThenElse(vector<string>	&expr);
extern var define(vector<string>		&expr);
extern var sumOp(vector<string>			&expr);
extern var subOp(vector<string>			&expr);
extern var multOp(vector<string>		&expr);
extern var divOp(vector<string>			&expr);
extern var andOp(vector<string>			&expr);
extern var orOp(vector<string>			&expr);
extern var notOp(vector<string>			&expr);
extern var eqOp(vector<string>			&expr);
extern var eqOp(vector<string>			&expr);
extern var gtOp(vector<string>			&expr);
extern var gtOp(vector<string>			&expr);
extern var ltOp(vector<string>			&expr);
extern var ltOp(vector<string>			&expr);
extern var geOp(vector<string>			&expr);
extern var geOp(vector<string>			&expr);
extern var leOp(vector<string>			&expr);
extern var leOp(vector<string>			&expr);

//runExpr
extern var runExpr(const string& expr);

//main
extern map<string,miniHfunc> funcs;
extern map<string,var> vars;

#endif // miniHheader