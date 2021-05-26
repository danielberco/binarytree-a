#include "BinaryTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;
using namespace ariel;


TEST_CASE ("Left-pos order") {
    BinaryTree<int> tree;
    tree.add_root(0);
    for (int i = 0; i < 5; i++) {
        tree.add_left(i, i + 1);
    }
    int j = 0;
    for (auto t = tree.begin_preorder(); t != tree.end_preorder(); t++,j++) {
                CHECK((*t) == j);
       
    }
}


TEST_CASE (" Right -  pos order") {
    BinaryTree<int> tree;
    tree.add_root(0);
    for (int i = 0; i < 5; i++) {
        tree.add_right(i, i + 1);
    }
    int j = 0;
    for (auto t = tree.begin_preorder(); t != tree.end_preorder(); t++,j++) {
                CHECK((*t) == j);
    }
}

TEST_CASE("Integer Part A ")
{
    BinaryTree<int> tree_of_ints;
    CHECK_NOTHROW(tree_of_ints.add_root(7));
    CHECK_NOTHROW(tree_of_ints.add_left(7, 6));
    CHECK_NOTHROW(tree_of_ints.add_left(8, 7));
    CHECK_NOTHROW(tree_of_ints.add_right(2, 35));
    CHECK_NOTHROW(tree_of_ints.add_right(3, 53));
    CHECK_NOTHROW(tree_of_ints.add_left(1, 2));
}



TEST_CASE("Integer Part B Sorting")
{
  BinaryTree<int> tree_of_ints;

  CHECK_NOTHROW(tree_of_ints.add_root(1));
  CHECK_NOTHROW(tree_of_ints.add_root(2)); 
  CHECK_NOTHROW(tree_of_ints.add_root(3)); 
  CHECK_NOTHROW(tree_of_ints.add_left(2, 5));
  CHECK_NOTHROW(tree_of_ints.add_left(5, 4));
  CHECK_NOTHROW(tree_of_ints.add_right(5, 9));
  CHECK_NOTHROW(tree_of_ints.add_right(1, 3));
  CHECK_NOTHROW(tree_of_ints.add_left(1, 2)); 
  CHECK_NOTHROW(cout << tree_of_ints << endl);

  int preOrder[] = {2, 4, 3, 5, 3};
  int inOrder[] = {4, 2, 5, 1, 3};
  int postOrder[] = {4, 5, 2, 3, 1};

  int i = 0;
  for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it)
  {
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }

  i = 0;
  for (auto it = tree_of_ints.begin_inorder(); it != tree_of_ints.end_inorder(); ++it)
  {
    CHECK_EQ((*it), inOrder[i]);
    i++;
  }

  i = 0;
  for (auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it)
  {
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }
}

TEST_CASE("Sorting String")
{
  BinaryTree<string> tree_of_strings;

  CHECK_NOTHROW(tree_of_strings.add_root("3"));
  CHECK_NOTHROW(tree_of_strings.add_root("2"));
  CHECK_NOTHROW(tree_of_strings.add_root("1")); 
  CHECK_NOTHROW(tree_of_strings.add_left("1", "9"));
  CHECK_NOTHROW(tree_of_strings.add_left("9", "4"));
  CHECK_NOTHROW(tree_of_strings.add_right("9", "5"));
  CHECK_NOTHROW(tree_of_strings.add_right("1", "3"));
  CHECK_NOTHROW(tree_of_strings.add_left("1", "2")); 
  CHECK_NOTHROW(cout << tree_of_strings << endl;);

  string pre[] = {"1", "2", "4", "5", "3"};
  string in[] = {"4", "2", "5", "1", "3"};
  string post[] = {"4", "5", "2", "3", "1"};

  int i = 0;
  for (auto it = tree_of_strings.begin_preorder(); it != tree_of_strings.end_preorder(); ++it)
  {
    CHECK_EQ((*it), pre[i]);
    i++;
  }

  i = 0;
  for (auto it = tree_of_strings.begin_inorder(); it != tree_of_strings.end_inorder(); ++it)
  {
    CHECK_EQ((*it), in[i]);
    i++;
  }

  i = 0;
  for (auto it = tree_of_strings.begin_postorder(); it != tree_of_strings.end_postorder(); ++it)
  {
    CHECK_EQ((*it), pre[i]);
    i++;
  }
}


TEST_CASE("Sorting Char")
{
  BinaryTree<char> tree_of_chars;

  CHECK_NOTHROW(tree_of_chars.add_root('3'));
  CHECK_NOTHROW(tree_of_chars.add_root('2'));
  CHECK_NOTHROW(tree_of_chars.add_root('1'));
  CHECK_NOTHROW(tree_of_chars.add_left('1', '9'));
  CHECK_NOTHROW(tree_of_chars.add_left('9', '4'));
  CHECK_NOTHROW(tree_of_chars.add_right('9', '5'));
  CHECK_NOTHROW(tree_of_chars.add_right('1', '3'));
  CHECK_NOTHROW(tree_of_chars.add_left('1', '2')); 
  CHECK_NOTHROW(cout << tree_of_chars << endl;);

  char preOrder[] = {'1', '2', '4', '5', '3'};
  char inOrder[] = {'4', '2', '5', '1', '3'};
  char postOrder[] = {'4', '5', '2', '3', '1'};

  int i = 0;
  for (auto it = tree_of_chars.begin_preorder(); it != tree_of_chars.end_preorder(); ++it)
  {
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }

  i = 0;
  for (auto it = tree_of_chars.begin_inorder(); it != tree_of_chars.end_inorder(); ++it)
  {
    CHECK_EQ((*it), inOrder[i]);
    i++;
  }

  i = 0;
  for (auto it = tree_of_chars.begin_postorder(); it != tree_of_chars.end_postorder(); ++it)
  {
    CHECK_EQ((*it), preOrder[i]);
    i++;
  }
}
