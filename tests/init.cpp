
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
SCENARIO("BST delete non inserted element", "[delete]")
{ 
	Tree<int> tree = {8}; 
	REQUIRE( !tree.del(4) ); 
	REQUIRE( !tree.isEmpty() ); 
} 
SCENARIO("BST delete root without children", "[delete]") 
{ 
	Tree<int> tree = {8}; 
	REQUIRE( tree.del(8) ); 
	REQUIRE( tree.isEmpty() ); 
} 
SCENARIO("BST delete root with one child", "[delete]") 
{ 
	Tree<int> tree = {8, 4, 3}; 
	REQUIRE( tree.del(8) ); 
	REQUIRE( tree == Tree<int>({4, 3}) ); 
} 
SCENARIO("BST delete root with children", "[delete]") 
{ 
	Tree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12}; 
	REQUIRE( tree.del(8) ); 
	REQUIRE( tree == Tree<int>({9, 4, 3, 10, 13, 11, 12}) ); 
}
SCENARIO("BST delete non root without children", "[delete]") 
{ 
	Tree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12}; 
	REQUIRE( tree.del(3) ); 
	REQUIRE( tree == Tree<int>({8, 4, 10, 9, 13, 11, 12}) ); 
}
SCENARIO("BST delete non root with one child", "[delete]") 
{ 
	Tree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12}; 
	REQUIRE( tree.del(11) ); 
	REQUIRE( tree == Tree<int>({8, 4, 3, 10, 9, 13, 12}) ); 
}
SCENARIO("BST delete non root with children", "[delete]")
{ 
	Tree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12}; 
	REQUIRE( tree.del(10) ); 
	REQUIRE( tree == Tree<int>({8, 4, 3, 11, 9, 13, 12}) ); 
} 
