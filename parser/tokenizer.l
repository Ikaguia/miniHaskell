%{
#include <cstdio>
#include <iostream>
using namespace std;
#define YY_DECL extern int yylex()

#include <bits/stdc++.h>
using namespace std;

#include "../core/var.hpp"
#include "../core/expression.hpp"

using ii = pair<int,int>;
#include "../util.hpp"

#include "parser.tab.h"  // to get the token types that we return
%}
%option outfile="lex.cpp" header-file="lex.h"

LPAREN    "("
RPAREN    ")"
LCOLCH "["
RCOLCH "]"

sum       "+"
mult      "*"
minus     "-"
divi      "/"

or        "|"
and       "&"
not       "!"

false     "false"
true      "true"

let "let"
in "in"

if "if"
then "then"
else "else"

comma ","

eq  "="
lt  "<"
gt  ">"

listInt "listInt"
listBool "listBool"

%%
{false}                       { return tfalse; }
{true}                        { return ttrue; }

{let}                         { return tlet; }
{in}                          { return tin; }

{comma}                       { return tcomma; }

{if}                          { return tif; }
{then}                        { return tthen; }
{else}                        { return telse; }

{eq}                          { return teq; }
{lt}                          { return tlt; }
{gt}                          { return tgt; }
{listInt}					  { return tlistInt; }
{listBool}					  { return tlistBool; }

[ \t\n]                         ;
[0-9]+                        { yylval.ival = atoi(yytext); return INT; }
[a-zA-Z]+[a-zA-Z0-9]*         {
                                yylval.sval = strdup(yytext);
                                return STRING;
					          }
{LPAREN}                      { return TLPAREN; }
{RPAREN}                      { return TRPAREN; }
{LCOLCH}                      { return TLCOLCH; }
{RCOLCH}                      { return TRCOLCH; }

{mult}                        { return tmult; }
{sum}                         { return tsum; }
{minus}                       { return tminus; }
{divi}                        { return tdivi; }
{or}                          { return tor; }
{and}                         { return tand; }
{not}                         { return tnot; }

.                             ;
%%