#ifndef UTIL_HPP
#define UTIL_HPP

#define DEBUG false

#define FOR(cont,max)			for(int (cont)=0;		(cont)<(int)(max);	 (cont)++)
#define FOR2(cont,start,max)	for(int (cont)=(start);	(cont)<(int)(max);	 (cont)++)
#define FORI(cont,max)			for(int (cont)=(max)-1;	(cont)>=0;			 (cont)++)
#define FOR2I(cont,start,max)	for(int (cont)=(max)-1;	(cont)>=(int)(start);(cont)++)
#define BETWEEN(x,a,b)			(((x)>=(a)) && ((x)<(b)))
#define SWAP(a,b)				int _temp_=(a);(a)=(b);(b)=_temp_;
#define RAND(max)				(rand()%(max))
#define RAND2(min,max)			((min)+(rand()%((max)-(min))))


extern bool 	strStartsWith	(const string&,const string&);
extern bool 	strEndsWith		(const string&,const string&);
extern ii 		get1stWordPos	(const string&,string ignore=" 	\n,.();\"\'=");
extern string 	get1stWord		(const string&,string ignore=" 	\n,.();\"\'=");
extern string 	lower_case		(const string&);
extern string 	upper_case		(const string&);
extern string 	noSpaces		(const string&);
extern bool 	parse			(string,string,vector<string>&);
extern bool 	isReserved		(const string&);
extern bool 	letter			(const string&);
extern bool 	letter			(char);
extern bool 	number			(const string&);
extern bool 	number			(char);
extern bool 	alphaNumeric	(const string&);
extern bool 	alphaNumeric	(char);

const string reservedWords[] = {
	"clear","exit",
	"int","bool","listInt","listBool","true","false",
	"let","in","if","then","else","define","function",
	"sum","sub","mult","div",
	"and","or","not",
	"eq",
	"gt","lt","ge","le",
};

#endif