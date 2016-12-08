#include "header.hpp"

expression* builder(string s){
	integer *int1=new integer(1);
	integer *int2=new integer(2);
	sum     *test=new sum(int1,int2);
	cout << test->runExpr().str() << endl;
	return NULL;
	//VAI JOSÉ
}
