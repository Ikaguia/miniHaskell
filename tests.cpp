#include "header.hpp"
#include <cstdio>

class test{
private:
	int passou, falhou;

	void testSum(){
		string msg, s;

		s = "sum(3,4)"; 
		msg = "3 + 4 deveria dar -1";
		verifica(runExpr(s).str() == "7", msg);

		s = "sum(3, -4)";
		msg = "3 + (-4) deveria dar -1";
		verifica(runExpr(s).str() == "-1", msg);

		s = "sum(-2, -4)";
		msg = "(-2) + (-4) deveria dar -6";
		verifica(runExpr(s).str() == "-6", msg);
	}

	void testSub(){
		string msg, s;

		s = "sub(-2, -4)";
		msg = "(-2) - (-4) deveria dar 2";
		verifica(runExpr(s).str() == "2", msg);

		s = "sub(-2, 4)";
		msg = "(-2) - 4 deveria dar -6";
		verifica(runExpr(s).str() == "-6", msg);

		s = "sub(12, 4)";
		msg = "12 - 4 deveria dar 8";
		verifica(runExpr(s).str() == "8", msg);
	}

	void testMult(){
		string msg, s;

		s = "mult(12, 4)";
		msg = "12 * 4 deveria dar 48";
		verifica(runExpr(s).str() == "48", msg);

		s = "mult(12, 46)";
		msg = "12 * 46 deveria dar 552";
		verifica(runExpr(s).str() == "552", msg);

		s = "mult(5, -2)";
		msg = "5 * -2 deveria dar -10";
		verifica(runExpr(s).str() == "-10", msg);

		s = "mult(-5, -2)";
		msg = "-5 * -2 deveria dar 10";
		verifica(runExpr(s).str() == "10", msg);
	}

	void testDiv(){
		string msg, s;

		s = "div(5, 2)";
		msg = "5 / 2 deveria dar 2";
		verifica(runExpr(s).str() == "2", msg);

		s = "div(4, 2)";
		msg = "4 / 2 deveria dar 2";
		verifica(runExpr(s).str() == "2", msg);

		s = "div(2, 4)";
		msg = "2 / 4 deveria dar 0";
		verifica(runExpr(s).str() == "0", msg);
	}

	void testOr(){
		string msg, s;

		s = "or(false, true)";
		msg = "false | true deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "or(true, true)";
		msg = "true | true deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "or(true, false)";
		msg = "true | false deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "or(false, false)";
		msg = "false | false deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);
	}

	void testAnd(){
		string msg, s;

		s = "and(false, true)";
		msg = "false & true deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "and(true, true)";
		msg = "true & true deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "and(true, false)";
		msg = "true & false deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "and(false, false)";
		msg = "false & false deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);
	}

	void testNot(){
		string msg, s;

		s = "not(false)";
		msg = "!false deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "not(true)";
		msg = "!true deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);
	}

	void testEquals(){
		string msg, s;

		s = "eq(true, false)";
		msg = "true == false deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "eq(true, true)";
		msg = "true == true deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "eq(-5, 2)";
		msg = "-5 == 2 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "eq(-5, -5)";
		msg = "-5 == -5 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);
	}

	
	void testGreater(){
		string msg, s;

		s = "gt(2, 5)";
		msg = "2 > 5 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "gt(-2, -5)";
		msg = "-2 > -5 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "gt(101, -5)";
		msg = "101 > -5 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "gt(-101, 5)";
		msg = "-101 > 5 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "gt(7, 7)";
		msg = "7 > 7 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);
	}

	void testLower(){
		string msg, s;

		s = "lt(2, 5)";
		msg = "2 < 5 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "lt(-2, -5)";
		msg = "-2 < -5 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "lt(101, -5)";
		msg = "101 < -5 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "lt(-101, 5)";
		msg = "-101 < 5 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "lt(7, 7)";
		msg = "7 < 7 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);
	}
	
	void testGreaterOrEqual(){
		string msg, s;

		s = "ge(2, 5)";
		msg = "2 >= 5 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "ge(-2, -5)";
		msg = "-2 >= -5 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "ge(101, -5)";
		msg = "101 >= -5 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "ge(-101, 5)";
		msg = "-101 >= 5 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "ge(7, 7)";
		msg = "7 >= 7 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);
	}

	void testLowerOrEqual(){
		string msg, s;

		s = "le(2, 5)";
		msg = "2 <= 5 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "le(-2, -5)";
		msg = "-2 <= -5 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "le(101, -5)";
		msg = "101 <= -5 deveria dar false";
		verifica(runExpr(s).str() == "FALSE", msg);

		s = "le(-101, 5)";
		msg = "-101 <= 5 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);

		s = "le(7, 7)";
		msg = "7 <= 7 deveria dar true";
		verifica(runExpr(s).str() == "TRUE", msg);
	}

	void testLet(){
		string msg, s;

		s = "let(x = 10) in(sum(x, mult(3, x)))";
		msg = "let(x = 10) in(x + 3*x) deveria dar 40";
		verifica(runExpr(s).str() == "40", msg);

		s = "let(x = 10) in(sum(x, mult(3, let(x = 4) in(sub(x, -1)) )))";
		msg = "let(x = 10) in(x + 3*( let(x = 4) in(x - -1) )) deveria dar 25";
		verifica(runExpr(s).str() == "25", msg);
	}

public:
	void verifica(bool condicao, string & s){
		if(condicao == false){
			printf("Teste falhou: %s\n", s.c_str());
			falhou++;
		}
		else passou++;
	}

	void relatorio_final(){
		printf("%d testes feitos\n", passou+falhou);
		printf("Passou em %d testes\n", passou);
		printf("Falhou em %d testes\n", falhou);
	}

	test(){
		passou = falhou = 0;
	}

	void runTests(){
		testSum();
		testSub();
		testMult();
		testDiv();
		testOr();
		testAnd();
		testNot();
		testEquals();
		testGreater();
		testLower();
		testGreaterOrEqual();
		testLowerOrEqual();
		testLet();

		relatorio_final();
	}

};



int main(){

	test t;

	t.runTests();

	return 0;
}