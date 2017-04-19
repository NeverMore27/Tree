
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
SCENARIO("del1")
{
	Tree<int> a;
	a.add(5);
	a.add(4);
	a.add(7);
	a.add(8);
	a.add(2);
	a.add(6);
	a.del(7);
	bool b = a.find(7);
	REQUIRE(b == 0);
}
SCENARIO("del2") 
{
	Tree<int> a;
	a.add(5);
	a.add(4);
	a.add(7);
	a.add(8);
	a.add(2);
	a.add(6);
	a.del(2);
	bool b = a.find(2);
	REQUIRE(b == 0);
}
SCENARIO("del3")
{
	Tree<int> a;
	a.add(5);
	a.add(4);
	a.add(7);
	a.add(8);
	a.add(2);
	a.add(6);
	a.add(1);
	a.del(2);
	bool b = a.find(2);
	REQUIRE(b == 0);
}
SCENARIO("del4")
{
	Tree<int> a;
	a.add(5);
	a.add(4);
	a.add(7);
	a.add(8);
	a.add(2);
	a.add(6);
	a.add(3);
	a.del(2);
	bool b = a.find(2);
	REQUIRE(b == 0);
}
SCENARIO("del5")
{
	Tree<int> a;
	a.add(5);
	a.add(4);
	a.add(7);
	a.add(8);
	a.add(2);
	a.add(6);
	a.add(3);
	bool b = a.del(15);;
	REQUIRE(b == 0);
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

SCENARIO("BST delete non inserted element", "[delete]") {
	Tree<int> tree = {8};
	REQUIRE( !tree.remove(4) );
	REQUIRE( !tree.isEmpty() );
}

//		+----+
//		|-08-|							*
//		+----+
//
//
//					    08
//					   ---->
SCENARIO("BST delete root without children", "[delete]") {
	Tree<int> tree = {8};
	REQUIRE( tree.remove(8) );
	REQUIRE( tree.isEmpty() );
}

//                +----+                                              +----+
//                |-08-|                                              | 04 |
//                +----+                                              +----+
//                  /                                                   /
//                 /                                                   /
//           +----+                                              +----+
//           | 04 |                                              | 03 |
//           +----+                                              +----+
//             /
//            /
//      +----+                              08
//      | 03 |                             ---->
//      +----+
SCENARIO("BST delete root with one child", "[delete]") {
	Tree<int> tree = {8, 4, 3};
	REQUIRE( tree.remove(8) );
	REQUIRE( tree == BinarySearchTree<int>({4, 3}) );
}

//                +----+                                              +----+
//                |-08-|                                              | 09 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /          \
//            /         /  \                                      /            \
//      +----+    +----+    +----+          08              +----+              +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |              | 13 |
//      +----+    +----+    +----+                          +----+              +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 11 |
//                     +----+                                              +----+
//                        \                                                   \
//                         \                                                   \
//                          +----+                                              +----+
//                          | 12 |                                              | 12 |
//                          +----+                                              +----+
SCENARIO("BST delete root with children", "[delete]") {
	Tree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.remove(8) );
	REQUIRE( tree == BinarySearchTree<int>({9, 4, 3, 10, 13, 11, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                                  /\
//            /         /  \                                                /  \
//      +----+    +----+    +----+          03                        +----+    +----+
//      |-03-|    | 09 |    | 13 |         ---->                      | 09 |    | 13 |
//      +----+    +----+    +----+                                    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 11 |
//                     +----+                                              +----+
//                        \                                                   \
//                         \                                                   \
//                          +----+                                              +----+
//                          | 12 |                                              | 12 |
//                          +----+                                              +----+
SCENARIO("BST delete non root without children", "[delete]") {
	Tree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.remove(3) );
	REQUIRE( tree == BinarySearchTree<int>({8, 4, 10, 9, 13, 11, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /         /\
//            /         /  \                                      /         /  \
//      +----+    +----+    +----+          11              +----+    +----+    +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |    | 09 |    | 13 |
//      +----+    +----+    +----+                          +----+    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     |-11-|                                              | 12 |
//                     +----+                                              +----+
//                        \
//                         \
//                          +----+
//                          | 12 |
//                          +----+
SCENARIO("BST delete non root with one child", "[delete]") {
	Tree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.remove(11) );
	REQUIRE( tree == BinarySearchTree<int>({8, 4, 3, 10, 9, 13, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    |-10-|                                    | 04 |    | 11 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /         /\
//            /         /  \                                      /         /  \
//      +----+    +----+    +----+          10              +----+    +----+    +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |    | 09 |    | 13 |
//      +----+    +----+    +----+                          +----+    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 12 |
//                     +----+                                              +----+
//                        \
//                         \
//                          +----+
//                          | 12 |
//                          +----+
SCENARIO("BST delete non root with children", "[delete]") {
	Tree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.remove(10) );
	REQUIRE( tree == BinarySearchTree<int>({8, 4, 3, 11, 9, 13, 12}) );
}
