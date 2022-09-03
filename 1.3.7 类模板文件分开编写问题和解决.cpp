#include"person.hpp"
#include<iostream>
void test()
{
	person<string, int> p("ssss", 18);
	p.info();
}
int main()
{
	test();
	return 0;
}