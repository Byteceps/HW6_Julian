//Tester File for Tree.cc
#include <iostream>
#include "tree.hh"
#include <cassert>

//Creates a depth 1 tree with two leaves: one left and one right
tree_ptr_t create_shallow_balanced_tree(){
    tree_ptr_t tree = create_tree(20,1);
    tree->left_ = create_tree(40,2);
    tree->right_ = create_tree(60, 3);
    return tree;
}
//Creates a depth 2 tree with equal left and right leaves
tree_ptr_t create_deep_balanced_tree(){
    tree_ptr_t tree = create_tree(20,1);
    tree->left_ = create_tree(40,2);
    tree->right_ = create_tree(60, 3);
    tree->left_->left_ = create_tree(80, 4);
    tree->left_->right_ = create_tree(100, 5);
    tree->right_->left_ = create_tree(120, 6);
    tree->right_->right_ = create_tree(140,8);
    return tree;
}
//Creates an unbalanced tree with 3 layers of left leaves nad one layer of right leaves
tree_ptr_t create_left_unbalanced_tree(){
    tree_ptr_t tree = create_tree(20,1);
    tree->left_ = create_tree(40,2);
    tree->right_ = create_tree(60, 3);
    tree->left_->left_ = create_tree(80, 4);
    tree->left_->right_ = create_tree(100, 5);
    tree->left_->left_->left_ = create_tree(120, 6);
    tree->left_->left_->right_ = create_tree(140, 7);
    return tree;
}
//Creates an unbalanced tree with 3 layers of right leaves and one layer of left leaves
tree_ptr_t create_right_unbalanced_tree(){
    tree_ptr_t tree = create_tree(20,1);
    tree->left_ = create_tree(40,2);
    tree->right_ = create_tree(60, 3);
    tree->right_->left_ = create_tree(80, 4);
    tree->right_->right_ = create_tree(100, 5);
    tree->right_->left_->left_ =create_tree(120, 6);
    tree->right_->left_->right_ = create_tree(140, 7);
    return tree;
}
//Create a tree with duplicate keys (duplicate is 12)
tree_ptr_t create_tree_duplicate_keys(){
    tree_ptr_t tree = create_tree(126 , 1);
    tree->left_ = create_tree(-5 ,2);
    tree->right_ = create_tree(12, 3);
    tree->left_->left_ = create_tree(12, 4);
    tree->left_->right_ = create_tree(6, 5);
    tree->left_->right_->left_ = create_tree(9, 6);
    tree->right_->left_ = create_tree(3, 7);
    return tree;
}
//Creates a tree where the root is a nullptr;
tree_ptr_t create_nullptr_root(){
    tree_ptr_t tree = nullptr;
    return tree;
}

int main(){
    // path_to test Cases

    //Want path to root of tree
    tree_ptr_t tree = create_deep_balanced_tree();
    assert(path_to(tree, 20) == "" && "path_to root returns empty string");

    //Want Path to shallow left node
    assert(path_to(tree, 40) == "L" && "path_to first left node == 40");

    //Want path to shallow right node
    assert(path_to(tree, 60) == "R" && "path_to first right now == 60");
    
    //Want path to deep left node
    assert(path_to(tree, 100) == "LR" && "path_to deeper left node == 100");

    //Want path to deep right node
    assert(path_to(tree, 120) == "RL" && "path_to deeper right node == 140");

    //When key is not in the tree
    assert(path_to(tree, 54) == "-" && "path_to returns - when key is not in tree");

    //When tree has duplicate keys
    tree_ptr_t tree_duplicates = create_tree_duplicate_keys();
    assert(path_to(tree_duplicates, 12) == "LL" && "Tree with duplicate keys returns leftmost one");


    ////////////////////////////////////////////////////////////////////////////////
    // node_at test cases

    //Empty string input
    assert(node_at(tree, "") == tree && "Empty string input returns tree root");

    // "L" input
    assert(node_at(tree, "L") == tree->left_ && "Single L input returns left node");

    // "R" input
    assert(node_at(tree, "R") == tree->right_ && "Single R input returns right node");

    // "LR" Input
    assert(node_at(tree, "LR") == tree->left_->right_ && "LR input returns left->right node");

    // "LL" Input
    assert(node_at(tree, "LL") == tree->left_->left_ && "LL input returns left->left node");

    // "RR" Input
    assert(node_at(tree, "RR") == tree->right_->right_ && "RR input returns right->right node");

    // "RL" Input
    assert(node_at(tree, "RL") == tree->right_->left_ && "RL input returns right->left node");

    // "Invlaid String input"
    assert(node_at(tree, "abcd") == nullptr && "Invalid path returns nullptr");

    // Path leads to nullptr
    assert(node_at(tree, "LRRL") == nullptr && "Path leading to invalid node returns nullptr");

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // destroy_tree test case
   
    return 0;
}
/* I wish this worked
TEST_CASE( "PATH_TO TEST CASES", "[path_to]" ){
    SECTION( "Want path to root of tree" ){
        tree_ptr_t tree = create_shallow_balanced_tree();
        REQUIRE ( path_to(tree, 20) == "" );
}
    }
    SECTION( "Want path to shallow left node" ){
        tree_ptr_t tree = create_shallow_balanced_tree();
        REQUIRE ( path_to(tree, 40) == "L" );
    }
    SECTION( "Want path to shallow right node" ){
        tree_ptr_t tree = create_shallow_balanced_tree();
        REQUIRE( path_to(tree, 60) == "R");
    }
}
*/

  

















