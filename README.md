## HW 6: Julian Prince

### Building the program
* This program can be compiled with the following commands:
    * g++ -g -Wall -Wextra -pedantic -Werror  -std=c++17 -fsanitize=address tree.cc test_tree.cc  -o tree

### Design Choices
**path_to**
This function takes advantage of the helper function is_in_tree to return a string representing the path to a given node in a tree. is_in_tree returns a boolean value for whether or not a given key exists within a given tree. This function recursivley traverses the left and right branches of a tree, and stores in a vector array the keys for each leaf on the way to the desired node/key. The array is essential for the path_to function. I iterate over the array and compare each index to the keys on the left and right of the root node. If there is a match then I store the corresponding direction character in a string, and move a tree_ptr_t to that node, repeat the process until the end of the array is reached. 

**node_at**
This function, given a valid input string of L's or R's, navigates to the node in the tree indicated by those directions. After verifying the input is valid, the function simply iterates over the string and moves a tree_ptr_t in the indicated direction.

**test cases**
I ended up writing many more tester tree creation functions than was actually necessary for the code, but I don't think it hurts to have more kinds of trees to run tests on. It could theoretically benefit a user trying to run tests specific to shallow, deep, or unbalanced trees.
