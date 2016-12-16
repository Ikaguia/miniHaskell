#include <bits/stdc++.h>
using namespace std;

#include "../core/var.hpp"
#include "../core/expression.hpp"

#include "../parser/oldParser.hpp"

//each executable that uses the core library must define it's own functions and variables list so that the core can manipulate them

//example of covarage tests
extern void test_oldParser();

//usage of ../core/oldParser module
void testSimpleExpression(){
	oldParser *op;
	var returnValue;
	string s0;

	op = new oldParser();

	s0 = "sum(1,sub(sum(1,2),10))";
	returnValue = oldParser::runExpr(s0);

	cout << "test0 is: " << returnValue.str() << endl;
}

int main(){
	vars.clear();

	//example of sum
	integerExpression *lop, *rop;
	sumExpression *sum1;

	lop = new integerExpression(1);
	rop = new integerExpression(5);

	sum1 = new sumExpression(lop, rop);

	cout << "Sum of 1 and 5 is: " << sum1->runExpr().str() << endl;

	testSimpleExpression();

	cout << "1. Coverage Test" << endl;
	test_oldParser();

	return 0;
}