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


//var
typedef enum{tInt,tBool,error,success} type;
using ts = pair<type,string>;

class var{
public:
	type t;
	int val;
	var():t{error},val{0}{};
	var(type x):t{x},val{0}{};
	var(bool v):t{tBool},val{v}{};
	var(int v):t{tInt},val{v}{};
	string str(){
		if(t==success)return "SUCCESS";
		if(t==error)return "ERROR";
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

//main
extern map<string,miniHfunc> funcs;
extern map<string,var> vars;

#endif // miniHheader