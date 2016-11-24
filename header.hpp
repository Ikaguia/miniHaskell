#ifndef miniHheader
#define miniHheader

#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
using namespace std;

#define FOR(cont,max)			for(int (cont)=0;		(cont)<(int)(max);(cont)++)
#define FOR2(cont,start,max)	for(int (cont)=(start);	(cont)<(int)(max);(cont)++)
#define ABS(x)					(((x)> 0 ) ? (x) :-(x))
#define MAX(x,y)				(((x)>(y)) ? (x) : (y))
#define MIN(x,y)				(((x)<(y)) ? (x) : (y))
#define BETWEEN(x,a,b)			(((x)>=(a)) && ((x)<(b)))
#define SWAP(a,b)				int _temp_=(a);(a)=(b);(b)=_temp_;
#define RAND(max)				(rand()%(max))
#define RAND2(min,max)			((min)+(rand()%((max)-(min))))


using ii = pair<int,int>;
#define ff first
#define ss second


//var
typedef enum{tInt,tBool,error} type;
using ts = pair<type,string>;

class var{
public:
	type t;
	int val;
	bool inf;
	var():t{error},val{0},inf{false}{};
	var(bool v):t{tBool},val{v},inf{false}{};
	var(int v):t{tInt},val{v},inf{false}{};
};

//miniHfunc
class miniHfunc{
public:
	string name;
	vector<ts> args;
	string body;
	miniHfunc(string);
	miniHfunc();
	int call(string,bool);
};

//utilFuncs
extern bool strStartsWith(const string&,const string&);
extern bool strEndsWith(const string&,const string&);
extern ii get1stWordPos(const string&,string ignore=" 	\n,.();\"\'=");
extern string get1stWord(const string&,string ignore=" 	\n,.();\"\'=");

//runExpr
extern var runExpr(string& expr);

//main
extern map<string,miniHfunc> funcs;
extern map<string,var> vars;

#endif // miniHheader