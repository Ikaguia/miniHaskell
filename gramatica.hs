-- 0. Warning:
-- This is not an haskell file, but an caricature of an actual haskell description file such as prelude. Hence the contents below will make any haskell interpreter crashes


-- 1. Grammar notations:
-- @ is an annotation to help compiler or interpreter building an context of the following code
-- @(bnf) means we have a bnf notation below
-- ~ means the maintype extends the following structure
-- table is a regular table where collumns are spearated by tab and lines, by \n.


-- 2. BNF notation for leaf expressions such as a boolean value
@(bnf):
bool_exp 	::=	true|false --bool
digit 		::=	0|1|2|3|4|5|6|7|8|9 
integer  	::=	(digit)+ --int


-- 3. Prelude expressions
-- Prelude expressions are basically functions that can be executed by @ikaguia's implemented parser
-- An more complex parser is being implemented by @joseleite19 using bision
-- Those prelude expressions can be used in user prompt "> "
-- %s is an arbitrary sequence of caracters (string)

@(prelude-expression ~ table where c[exp-str,type_identifier]):
if(%s)then(%s)else(%s)        		bool type_a type_a -> type_a
define.%s(%s.%s,%s.%s...)=(%s)		func_name type_name_a type_a type_name_b type_b ... expr -> sucess/fail
let(%s=%s)in(%s)                  	var_name expr expr -> expr
%s(%s,%s...)                      	type_a type_b ... -> ?
%s                                	var_name -> type_a

listInt[%s,%s...]                 	int_a,int_b... -> listInt
listBool[%s,%s...]                	bool_a,bool_b... -> listBool

sum(%s,%s)                        	int int -> int
sub(%s,%s)                        	int int -> int
mult(%s,%s)                       	int int -> int
div(%s,%s)                        	int int -> int
and(%s,%s)                        	bool bool -> bool
or(%s,%s)                         	bool bool -> bool
not(%s)                           	bool -> bool
equals(%s,%s)                     	bool bool -> bool / int int -> bool
eq(%s,%s)                         	bool bool -> bool
greater(%s,%s)                    	int int -> bool
gt(%s,%s)                         	int int -> bool
lessThen(%s,%s)                   	int int -> bool
lt(%s,%s)                         	int int -> bool
greaterEq(%s,%s)                  	int int -> bool
ge(%s,%s)                         	int int -> bool
lessEq(%s,%s)                     	int int -> bool
le(%s,%s)                         	int int -> bool
