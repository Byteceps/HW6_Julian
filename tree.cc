// Tree.cc Implementation of binary tree structure
//Author: Julian Prince
//HW6
//

#include <iostream>
#include <vector>
#include "tree.hh"
#include <string>
#include <cassert>

//create_tree:
//create_tree allocates space for a new tree node and fills it with the given data parameters
//
tree_ptr_t create_tree(const key_t& key, const value_t& value, tree_ptr_t left, tree_ptr_t right){
    Tree* newTree = new Tree;
    newTree->key_ = key;
    newTree->value_ = value;
    newTree->left_ = left;
    newTree->right_ = right;
    return newTree;
}
// is_in_tree returns boolean for if a path to key exists in tree
//
//adds keys from nodes on the path to key into vector array
bool is_in_tree(tree_ptr_t tree, key_t key, std::vector<int>& arr){
    //Check if root is nullptr
    if(!tree) return false;
    //Add key to array
    arr.push_back(tree->key_);
    //Return true if key is in root of tree
    if(tree->key_ == key){
        return true;
    }
    //Check if key is in left or right subtree of tree node
    if(is_in_tree(tree->left_,key, arr)|| is_in_tree(tree->right_, key, arr)){
        return true;
        }
    //Delete key from array if not on path to the node we want
    arr.pop_back();
    return false;
}

// path_to
// return a string representing the path taken from a given tree root
// to a given key in the tree. For each left child taken along the path, the
// string contains an 'L' character, and 'R' for a right child, in order.
//
std::string path_to(tree_ptr_t tree, key_t key){
    //Check if root is nullptr
    if(!tree){
        return "-";
    }
    std::vector<int> arr;
    std::string path = "";
    //Check if tree has no leaves and the root matches the key
    if(!tree->left_ && !tree->right_ && tree->key_ == key){
        return path;
    }
    //If path exists
    if(is_in_tree(tree, key, arr)){
        tree_ptr_t current = tree;

        //Iterate through array of keys on path to desired key, and compare it to the next left and right leaves of the current node
        for(unsigned i = 0; i <= arr.size() - 1; i++){
            if(current->left_ != nullptr && current->left_->key_ == arr[i]){
                path += "L";
                current = current->left_;
            }
            if(current->right_ != nullptr && current->right_->key_ == arr[i]){
                path+= "R";
                current = current->right_;
            }
         }
         return path;
     }
     //Path doesn't exist,
    return "-";
 }
 //DESTROY_TREE
 //
//Deallocate all space consumed by this tree and its children.
 void destroy_tree(tree_ptr_t root){
     if(root){
        destroy_tree(root->left_);
        destroy_tree(root->right_);
        delete(root);
     }
     return;
 }

 //NODE_AT
 //
 //Follow a path given by a string of L's and R's from a given root node and return the node that is
 // at the end of the path
 tree_ptr_t node_at(tree_ptr_t tree, std::string path){
     int length = path.length();
     //Check that path string is valid input
     for(int i = 0; i <= length - 1; i++){
        if(path[i] != 'L' && path[i] != 'R'){
            return nullptr;
         }
    }
    tree_ptr_t current = tree;
    //Case of empty path to root of tree
    if (path == ""){
       return tree;
    }
    for(int i = 0; i <= length - 1; i++){
        //Detect path instruction
        if(path[i] == 'L'){
            if(current->left_){
                current = current->left_;
                continue;
            }
            else{
                return nullptr;
            }
        }
        if(path[i] == 'R'){
            if(current->right_){
                current = current->right_;
                continue;
            }
            else{
                return nullptr;
            }
        }
     }
     return current;
 }


