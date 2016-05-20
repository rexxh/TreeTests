#include <BST.cpp>
#include <catch.hpp>
#include <fstream>
#include <iostream> 
using namespace std;
                  

SCENARIO("BST init", "[init]") {
BST<int> tree(2, 1);
Node<int>*Root = tree.get_root();
REQUIRE(Root!=0);
}

SCENARIO("Insert element", "[Insert]") {
  BST<double> tree(6,100);
  Node<double>*Root = tree.get_root();
  REQUIRE(tree.Insert(Root, 4, -20.8)!=0);
}

SCENARIO("Search element", "[Search]") {
  BST<char> tree(1,10);
  REQUIRE(tree.Search(1)!=0);
}

