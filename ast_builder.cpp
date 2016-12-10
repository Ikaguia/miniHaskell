#include "header.hpp"

expression* builder(string s){
	expression *ast = NULL;
	yy_scan_string(s.c_str());
	yyparse(&ast);
	yylex_destroy();
	return ast;
}
// "let(x=2)in(sum(1,x))"