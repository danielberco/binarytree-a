#include "BinaryTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;
using namespace ariel;


TEST_CASE ("Left-pos order") {
    BinaryTree<int> bTree;
    bTree.add_root(0);
    for (int i = 0; i < 5; i++) {
        bTree.add_left(i, i + 1);
    }
    int j = 0;
    for (auto t = bTree.begin_preorder(); t != bTree.end_preorder(); t++,j++) {
                CHECK((*t) == j);
       
    }
}


TEST_CASE (" Right -  pos order") {
    BinaryTree<int> bTree;
    bTree.add_root(0);
    for (int i = 0; i < 5; i++) {
        bTree.add_right(i, i + 1);
    }
    int j = 0;
    for (auto t = bTree.begin_preorder(); t != bTree.end_preorder(); t++,j++) {
                CHECK((*t) == j);
    }
}

TEST_CASE("Integer Part A ")
{
    BinaryTree<int> treeInt;
    CHECK_NOTHROW(treeInt.add_root(7));
    CHECK_NOTHROW(treeInt.add_left(7, 6));
    CHECK_NOTHROW(treeInt.add_left(8, 7));
    CHECK_NOTHROW(treeInt.add_right(2, 35));
    CHECK_NOTHROW(treeInt.add_right(3, 53));
    CHECK_NOTHROW(treeInt.add_left(1, 2));
}


TEST_CASE("Integer Part B Sorting")
{
  BinaryTree<int> treeInt;

  CHECK_NOTHROW(treeInt.add_root(3));
  CHECK_NOTHROW(treeInt.add_root(2)); 
  CHECK_NOTHROW(treeInt.add_root(1)); 
  CHECK_NOTHROW(treeInt.add_left(1, 9));
  CHECK_NOTHROW(treeInt.add_left(9, 4));
  CHECK_NOTHROW(treeInt.add_right(9, 5));
  CHECK_NOTHROW(treeInt.add_right(1, 3));
  CHECK_NOTHROW(treeInt.add_left(1, 2)); 
  CHECK_NOTHROW(cout << treeInt << endl);

  int preOrder[] = {2, 4, 3, 5, 3};
  int inOrder[] = {4, 2, 5, 1, 3};
  int postOrder[] = {4, 5, 2, 3, 1};

  int i = 0;
  for (auto it = treeInt.begin_preorder(); it != treeInt.end_preorder(); ++it)
  {
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }

  i = 0;
  for (auto it = treeInt.begin_inorder(); it != treeInt.end_inorder(); ++it)
  {
    CHECK_EQ((*it), inOrder[i]);
    i++;
  }

  i = 0;
  for (auto it = treeInt.begin_postorder(); it != treeInt.end_postorder(); ++it)
  {
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }
}

TEST_CASE("Sorting String")
{
  BinaryTree<string> treeString;

  CHECK_NOTHROW(treeString.add_root("3"));
  CHECK_NOTHROW(treeString.add_root("2")); 
  CHECK_NOTHROW(treeString.add_root("1")); 
  CHECK_NOTHROW(treeString.add_left("1", "9"));
  CHECK_NOTHROW(treeString.add_left("9", "4"));
  CHECK_NOTHROW(treeString.add_right("9", "5"));
  CHECK_NOTHROW(treeString.add_right("1", "3"));
  CHECK_NOTHROW(treeString.add_left("1", "2")); 
  CHECK_NOTHROW(cout << treeString << endl;);

  string pre[] = {"1", "2", "4", "5", "3"};
  string in[] = {"4", "2", "5", "1", "3"};
  string post[] = {"4", "5", "2", "3", "1"};

  int i = 0;
  for (auto it = treeString.begin_preorder(); it != treeString.end_preorder(); ++it)
  {
    CHECK_EQ((*it), pre[i]);
    i++;
  }

  i = 0;
  for (auto it = treeString.begin_inorder(); it != treeString.end_inorder(); ++it)
  {
    CHECK_EQ((*it), in[i]);
    i++;
  }

  i = 0;
  for (auto it = treeString.begin_postorder(); it != treeString.end_postorder(); ++it)
  {
    CHECK_EQ((*it), pre[i]);
    i++;
  }
}


TEST_CASE("Sorting  Char")
{
  BinaryTree<char> treeChar;

  CHECK_NOTHROW(treeChar.add_root('3'));
  CHECK_NOTHROW(treeChar.add_root('2')); 
  CHECK_NOTHROW(treeChar.add_root('1')); 
  CHECK_NOTHROW(treeChar.add_left('1', '9'));
  CHECK_NOTHROW(treeChar.add_left('9', '4'));
  CHECK_NOTHROW(treeChar.add_right('9', '5'));
  CHECK_NOTHROW(treeChar.add_right('1', '3'));
  CHECK_NOTHROW(treeChar.add_left('1', '2')); 
  CHECK_NOTHROW(cout << treeChar << endl;);
  char pre[] = {'1', '2', '4', '5', '3'};
  char in[] = {'4', '2', '5', '1', '3'};
  char post[] = {'4', '5', '2', '3', '1'};

  int i = 0;
  for (auto it = treeChar.begin_preorder(); it != treeChar.end_preorder(); ++it)
  {
    CHECK_EQ((*it), pre[i]);
    i++;
  }

  i = 0;
  for (auto it = treeChar.begin_inorder(); it != treeChar.end_inorder(); ++it)
  {
    CHECK_EQ((*it), in[i]);
    i++;
  }

  i = 0;
  for (auto it = treeChar.begin_postorder(); it != treeChar.end_postorder(); ++it)
  {
    CHECK_EQ((*it), pre[i]);
    i++;
  }
}
