#include "header.hpp"

expression* builder(string s){
	integerExpression *int1=new integerExpression(1);
	integerExpression *int2=new integerExpression(2);
	sumExpression     *test=new sumExpression(int1,int2);
	cout << test->runExpr().str() << endl;
	return NULL;
	//VAI JOSÉ
}
