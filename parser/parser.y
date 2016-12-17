%{
#include <cstdio>
#include <iostream>

#include <bits/stdc++.h>
using namespace std;

#include "../core/var.hpp"
#include "../core/expression.hpp"

using ii = pair<int,int>;
#include "../util.hpp"

// #include "s.tab.h"
// #include "lex.h"
using namespace std;
// stuff from flex that bison needs to know about:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
 
void yyerror(expression **ast, const char *s);
%}
%parse-param {expression **ast}
// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
	expression *ret;
	vector<expression*> *vr;
	int ival;
	char *sval;
}

%left "+"
%left "-"
%left "/"
%left "*"

%left "="
%left "<"
%left ">"

%left "|"
%left "&"
%right "!"


%left "let"
%left "in"

%left "if"
%left "then"
%left "else"

%token <ival> INT
%token <sval> STRING
%token TLPAREN "("
%token TRPAREN ")"
%token TLCOLCH "["
%token TRCOLCH "]"

%token tfalse "false"
%token ttrue "true"

%token tsum "+"
%token tminus "-"
%token tdivi "/"
%token tmult "*"

%token teq "="
%token tlt "<"
%token tgt ">"

%token tor "|"
%token tand "&"
%token tnot "!"

%token tlet "let"
%token tin "in"

%token tif "if"
%token tthen "then"
%token telse "else"
%token tlistInt "listInt"
%token tlistBool "listBool"

%token tcomma ","

%type<ret> exp
%type<ret> funcao
%type<vr> args
%type<ret> argsInt
%type<ret> argsBool
%type<ret> listbool
%type<ret> listint

%%

comeco:
	{ ast = NULL; }
	| exp{
		*ast = $1;
	}
;

exp: {$$ = NULL;}
	| INT{
		$$ = new integerExpression($1);
	}
	| STRING{
		$$ = new variableExpression($1);
	}
	| ttrue{
		$$ = new booleanExpression(true);
	}
	| tfalse{
		$$ = new booleanExpression(false);
	}

	| listint{
		$$ = $1;
	}
	| listbool{
		$$ = $1;
	}
	| funcao{
		$$ = $1;
	}
	| TLPAREN exp TRPAREN{
		$$ = $2;
	}
	
	| exp tmult exp{
		$$ = new multExpression($1, $3);
	}
	| exp tsum exp{
		$$ = new sumExpression($1, $3);
	}
	| exp tdivi exp{
		$$ = new divExpression($1, $3);
	}
	| exp tminus exp{
		$$ = new subExpression($1, $3);
	}
	| exp teq teq exp{
		$$ = new eqExpression($1, $4);
	}
	| exp tgt exp{
		$$ = new gtExpression($1, $3);
	}
	| exp tlt exp{
		$$ = new ltExpression($1, $3);
	}

	| exp tand exp{
		$$ = new andExpression($1, $3);
	}
	| exp tor exp{
		$$ = new orExpression($1, $3);
	}
	| tnot exp{
		$$ = new notExpression($2);
	}

	| tif exp tthen exp telse exp{
		$$ = new ifThenElseExpression($2, $4, $6);
	}
	| tlet STRING teq exp tin exp{
		$$ = new letExpression($2, $4, $6);
	}
;

funcao:
	STRING TLPAREN args TRPAREN{
		$$ = new functionExpression($1, *$3);

	}
;

args:
	exp tcomma args{
		$3->push_back($1);
		$$ = $3;
	}
	| exp {
		vector<expression*> *v;
		v = new vector<expression*>();
		if($1) v->push_back($1);
		$$ = v;
	}
;

argsInt:
	exp tcomma argsInt{
		$$ = new integerListExpression($1, $3);
	}
	| exp {
		$$ = new integerListExpression($1, NULL);
	}
;

argsBool:
	exp tcomma argsBool{
		$$ = new booleanListExpression($1, $3);
	}
	| exp {
		$$ = new booleanListExpression($1, NULL);
	}
;

listint:
	tlistInt TLCOLCH argsInt TRCOLCH{
		$$ = $3;
	}
;

listbool:
	tlistBool TLCOLCH argsBool TRCOLCH{
		$$ = $3;
	}
;

%%

void yyerror(expression **ast, const char *s) {
	delete *ast;
	*ast = NULL;
	cout << s << endl;
}