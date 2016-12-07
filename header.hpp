#ifndef miniHheader
#define miniHheader

#include <bits/stdc++.h>
//#include <math.h>
//#include <unistd.h>
using namespace std;

#define DEBUG true

#define FOR(cont,max)			for(int (cont)=0;		(cont)<(int)(max);	 (cont)++)
#define FOR2(cont,start,max)	for(int (cont)=(start);	(cont)<(int)(max);	 (cont)++)
#define FORI(cont,max)			for(int (cont)=(max)-1;	(cont)>=0;			 (cont)++)
#define FOR2I(cont,start,max)	for(int (cont)=(max)-1;	(cont)>=(int)(start);(cont)++)
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
	parsingError,
	invalidNameError,
	emptyListtError,
} errorID;
const string errorMsgs[] = {
	"ERROR",
	"ERROR CALL function not implemented",
	"ERROR invalid type",
	"ERROR reserved words",
	"ERROR division by 0",
	"ERROR no matching expression found",
	"ERROR invalid variable name",
	"ERROR list is empty",
};
const string reservedWords[] = {"int","bool","true","false","let","def","define","listInt","listBool"};

//var
typedef enum{tInt,tBool,listInt,listBool,error,success} type;
using ts = pair<type,string>;

class var{
public:
	type t;
	int val;
	vector<int> li;
	var():t{error},val{0}{};
	var(type x):t{x},val{0}{};
	var(type x,int y):t{x},val{y}{};
	var(bool v):t{tBool},val{v}{};
	var(int v):t{tInt},val{v}{};
	var(type ty,vector<int> v):t{ty},val{0},li{v}{};
	string str(){
		if(t==success)return "SUCCESS";
		if(t==error)return errorMsgs[val];
		if(t==tBool)return val?"TRUE":"FALSE";
		if(t==tInt)return to_string(val);
		if(t==listBool){
			string s;
			FOR(i,li.size()){
				if(i)s+=", ";
				s+=li[i]?"TRUE":"FALSE";
			}
			return "listBool[" + s + "]";
		}
		if(t==listInt){
			string s;
			FOR(i,li.size()){
				if(i)s+=", ";
				s+=to_string(li[i]);
			}
			return "listInt[" + s + "]";
		}
		return "???";
	}
};

//miniHfunc
class miniHfunc{
public:
	string name;
	vector<ts> args;
	string body;
	miniHfunc(const string&,const vector<ts>&,const string&);
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
extern string noSpaces(const string&);
extern bool parse(string,string,vector<string>&);
extern bool isReserved(const string&);
extern bool letter(const string&);
extern bool letter(char);
extern bool number(const string&);
extern bool number(char);
extern bool alphaNumeric(const string&);
extern bool alphaNumeric(char);

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
extern var let(vector<string>&);
extern var ifThenElse(vector<string>&);
extern var define(vector<string>&);
extern var sumOp(vector<string>&);
extern var subOp(vector<string>&);
extern var multOp(vector<string>&);
extern var divOp(vector<string>&);
extern var andOp(vector<string>&);
extern var orOp(vector<string>&);
extern var notOp(vector<string>&);
extern var eqOp(vector<string>&);
extern var gtOp(vector<string>&);
extern var ltOp(vector<string>&);
extern var geOp(vector<string>&);
extern var leOp(vector<string>&);
extern var listEmptyOp(vector<string>&);
extern var listHeadOp(vector<string>&);
extern var listTailOp(vector<string>&);

//runExpr
extern var runExpr(const string& expr);

//main
extern map<string,miniHfunc> funcs;
extern map<string,var> vars;

#endif // miniHheader