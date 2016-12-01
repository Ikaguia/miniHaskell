#ifndef miniHheader
#define miniHheader

#include <bits/stdc++.h>
//#include <math.h>
//#include <unistd.h>
using namespace std;

#define DEBUG false

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
} errorID;
const string errorMsgs[] = {
	"ERROR",
	"ERROR CALL function not implemented",
	"ERROR invalid type",
	"ERROR reserved words",
	"ERROR division by 0",
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
	miniHfunc(string);
	miniHfunc();
	var call(string,bool=false);
};

//utilFuncs
extern bool strStartsWith(const string&,const string&);
extern bool strEndsWith(const string&,const string&);
extern ii get1stWordPos(const string&,string ignore=" 	\n,.();\"\'=");
extern string get1stWord(const string&,string ignore=" 	\n,.();\"\'=");
extern string lower_case(const string&);
extern string upper_case(const string&);

//runExpr
extern var runExpr(string& expr);
extern var sumOp(string& expr);
extern var subOp(string& expr);
extern var multOp(string& expr);
extern var divOp(string& expr);
extern var andOp(string& expr);
extern var orOp(string& expr);
extern var notOp(string& expr);
extern var eqOp(string& expr);
extern var eqOp(string& expr);
extern var gtOp(string& expr);
extern var gtOp(string& expr);
extern var ltOp(string& expr);
extern var ltOp(string& expr);
extern var geOp(string& expr);
extern var geOp(string& expr);
extern var leOp(string& expr);
extern var leOp(string& expr);

//main
extern map<string,miniHfunc> funcs;
extern map<string,var> vars;

// map<string,miniHfunc> funcs;
// map<string,var> vars;

#endif // miniHheader