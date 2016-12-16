#include "header.hpp"
#include "parser.tab.h"

extern int yy_scan_string(const char *);
extern int yylex_destroy();

expression* builder(string s){
	expression *ast = NULL;
	yy_scan_string(s.c_str());
	yyparse(&ast);
	yylex_destroy();
	return ast;
}

int main(int argc, char const *argv[]){
	string s;
	getline(cin, s);

	builder(s);

	return 0;
}