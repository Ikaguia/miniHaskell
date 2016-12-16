#ifndef VAR_HPP
#define VAR_HPP

typedef enum{tInt,tBool,listInt,listBool,error,success} type;

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

#endif