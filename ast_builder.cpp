#include "header.hpp"

expression* builder(string s){
	integerExpression  *int1=new integerExpression(1);
	variableExpression *var1=new variableExpression("x");
	expression         *test=new sumExpression(int1,var1);

	integerExpression  *int2=new integerExpression(2);
	test                    =new letExpression("x",int2,test);
	return test;
	//VAI JOSÉ
}
