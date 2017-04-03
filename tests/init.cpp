
#include <tree.hpp>
#include <catch.hpp>


SCENARIO("null")
{
	Tree<int> a;
	REQUIRE(a.tree_one()==NULL);
}
SCENARIO("find")
{
	Tree<int> a;
	REQUIRE(a.find(0) == 0);
}

