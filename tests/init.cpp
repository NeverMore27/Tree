
#include <tree.hpp>
#include <catch.hpp>


SCENARIO("null")
{
	Tree<int> a;
	REQURE(a.tree_one()=NULL);
}
SCENARIO("add") 
{
	Tree<int> a;
	bool b=a.add(5);
	REQURE(b == 1);
}
SCENARIO("find")
{
	Tree<int> a;
	a.add(5);
	bool b = a.find(5);
	REQURE(b == 1);
}
