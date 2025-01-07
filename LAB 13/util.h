#ifndef _UTIL_H_
#define _UTIL_H_


struct Node* make_node(double value);
struct BST* generateBST(const char* filename);
struct Node* find_min(struct Node* node);
struct Node* removeNode(struct Node* root, double value);
struct Node* searchNode(struct Node* currentNode, double value);
struct Node* searchValue(struct BST* bst, double value);
int countNodesRecursive(struct Node* node);
int max_depth_need_recursive(struct Node* node);
int find_depth_max(struct BST* bst);
int count_nodes(struct Node* node);
int countNodes(struct BST* bst);
int countLeafNodes(struct BST* bst);
void in_Order(struct Node* node);
void pre_Order(struct Node* node);
void post_Order(struct Node* node); 
void level_Order(struct Node* node);
void printTree(struct BST* bst);
void remove_node(struct BST* bst, double value);
void addNode(struct BST* bst, double value);
void insertNode(struct Node* node, double value);


#endif /* _UTIL_H_ */

