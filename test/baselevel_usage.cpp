#include <bits/stdc++.h>
using namespace std;

#include "../core/var.hpp"
#include "../core/expression.hpp"

//each executable that uses the core library must define it's own functions and variables list so that the core can manipulate them

int main(){
	vars.clear();

	//example of sum
	integerExpression *lop, *rop;
	sumExpression *sum1;

	lop = new integerExpression(1);
	rop = new integerExpression(5);

	sum1 = new sumExpression(lop, rop);

	cout << "Sum of 1 and 5 is: " << sum1->runExpr().str() << endl;

	return 0;
}