
#include <tree.hpp>
#include <catch.hpp>


SCENARIO("null")
{
	Tree<int> a;
	REQUIRE(a.tree_one()==NULL);
}
SCENARIO("add") 
{
	Tree <int> a;
	bool b=a.add(5);
	REQUIRE(b == 1);
}
SCENARIO("find")
{
	Tree<int> a;
	a.add(5);
	bool b = a.find(5);
	REQUIRE(b == 1);
}
SCENARIO("file")
{
	Tree<int> a, c;
	c.add(3);
	c.add(2);
	c.add(1);
	c.add(5);
	c.pr("Tr.txt");
	a.file_tree("Tr.txt");
	bool b = a.find(3);
	REQUIRE(b == 1);
	b = a.find(2);
	REQUIRE(b == 1);
	b = a.find(1);
	REQUIRE(b == 1);
	b = a.find(5);
	REQUIRE(b == 1);
}
