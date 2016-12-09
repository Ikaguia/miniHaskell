#ifndef miniHheader
#define miniHheader

#include <bits/stdc++.h>
//#include <math.h>
//#include <unistd.h>
using namespace std;

#define DEBUG false

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
	argCountError,
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
	"ERROR wrong number of arguments to function",
};
const string reservedWords[] = {
	"int","bool","listInt","listBool","true","false",
	"let","in","if","then","else","define","function",
	"sum","sub","mult","div",
};

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
	string str();
};

//miniHfunc
class miniHfunc{
public:
	string name;
	vector<ts> args;
	string body;
	miniHfunc(){};
	miniHfunc(const string &n,const vector<ts> &ar,const string& b):name{n},args{ar},body{b}{};
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

//main
extern map<string,miniHfunc> funcs;
extern map<string,var> vars;

#include "expression_header.hpp"

//ast_builder
extern expression* builder(string);

#endif // miniHheader

