#include "header.hpp"

miniHfunc::miniHfunc():name{""}{}
miniHfunc::miniHfunc(vector<string> &in){
	name=in[0];
	string a=in[1]+",end";
	body=in[2];

	vector<string> v;
	while(parse(a,"%s.%s,%s",v)){
		if(v[0]=="int")args.push_back(ts(tInt,in[1]));
		if(v[0]=="bool")args.push_back(ts(tBool,in[1]));
		a=v[2];
	}
}

vector<string> readArgs(string s){
	vector<string> v;
	return v;
}

var miniHfunc::call(string s){
	/*vector<string> argsIn=readArgs(s);
	map<string,var> mapV;

	for(int i=0;(size_t)i<argsIn.size() && (size_t)i<args.size();i++){
		const string& name=args.ss;
		if(mapV[name].t!=error);
		else if(vars[name].t!=error)mapV[name]=vars[name];//restore previous var value after this function ends
		else                        mapV[name]=var(error);//remove this var after this function ends
		var result=runExpr(argsIn[i]);
		if(result.t!=args[i].ff)result=var(error,typeError);
		if(result.t==error){
			//error, restore variables and return error
			for(auto i:mapV){
				if(i.ss.t!=error)vars[i.ff]=i.ss;
				else vars.erase(i.ff);
			}
			return result;
		}
		vars[name]=result;
	}

	var result = runExpr(body);
	for(auto i:mapV){
		if(i.ss.t!=error)vars[i.ff]=i.ss;
		else vars.erase(i.ff);
	}
	return result;*/return var(error);
}
