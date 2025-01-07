#include "util.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    double Value;
    struct Node* left;
    struct Node* right;
}node;

struct BST {
    struct Node* root;
};






struct Node* make_node(double value) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->Value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}


void insertNode(struct Node* node, double value) {
    if (value < node->Value) {
        if (node->left == NULL) {
            node->left = make_node(value);
        }
        else {
            insertNode(node->left, value);
        }
    }
    else if (value > node->Value) {
        if (node->right == NULL) {
            node->right = make_node(value);
        }
        else {
            insertNode(node->right, value);
        }
    }
}

struct BST* generateBST(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }

    struct BST* bst = (struct BST*)malloc(sizeof(struct BST));
    bst->root = NULL;

    double value;
    fscanf(file, "%lf", &value);
    bst->root = make_node(value);

    while (fscanf(file, "%lf", &value) != EOF) {
        insertNode(bst->root, value);
    }

    fclose(file);
    return bst;
}

void addNode(struct BST* bst, double value) {
    if (bst == NULL) {
        printf("BST is not initialized!\n");
        return;
    }

    if (bst->root == NULL) {
        bst->root = make_node(value);
    }
    else {
        insertNode(bst->root, value);
    }
}

struct Node* find_min(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* removeNode(struct Node* root, double value) {
    if (root == NULL) {

        return root;
    }

    if (value < root->Value) {
        root->left = removeNode(root->left, value);
    }
    else if (value > root->Value) {
        root->right = removeNode(root->right, value);
    }
    else {
        if (root->left == NULL) {
         

            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
        

            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = find_min(root->right);
        root->Value = temp->Value;
        root->right = removeNode(root->right, temp->Value);
    }

    return root;
}

struct Node* searchNode(struct Node* currentNode, double value) {
    if (currentNode == NULL || currentNode->Value == value) {
        return currentNode;
    }

    while(currentNode != NULL) {
        if (value < currentNode->Value) {
            currentNode = currentNode->left;
        }
        else if (value > currentNode->Value) {
            currentNode = currentNode->right;
        }
        else {
            return currentNode;
        }
    }
    return currentNode;
}

struct Node* searchValue(struct BST* bst, double value) {
    if (bst == NULL) {
        printf("BST is not initialized!\n");
        return NULL;
    }

    return searchNode(bst->root, value);
}

int countNodesRecursive(struct Node* node) {
    if (node == NULL) {
        return 0;
    }

    return 1 + countNodesRecursive(node->left) + countNodesRecursive(node->right);
}

int countNodes(struct BST* bst) {
    if (bst == NULL) {
        printf("BST is not initialized!\n");
        return 0;
    }

    return countNodesRecursive(bst->root);
}


void remove_node(struct BST* bst, double value) {
    if (bst == NULL) {
        printf("BST is not initialized!\n");
        return;
    }

    bst->root = removeNode(bst->root, value);
}



int max_depth_need_recursive(struct Node* node) {
    if (node == NULL) {
        return 0;
    }

    int left = max_depth_need_recursive(node->left);
    int right = max_depth_need_recursive(node->right);

    if(left > right) {
        return left + 1;
    }
    else {
        return right + 1;
    }
}

int find_depth_max(struct BST* bst) {
    if (bst == NULL) {
        printf("BST is not initialized!\n");
        return 0;
    }

    return max_depth_need_recursive(bst->root);
}

int count_nodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        return 1;
    }

    return count_nodes(node->left) + count_nodes(node->right);
}

int countLeafNodes(struct BST* bst) {
    if (bst == NULL) {
        printf("BST is not initialized!\n");
        return 0;
    }

    return count_nodes(bst->root);
}

void in_Order(struct Node* node) {
    if (node != NULL) {
        in_Order(node->left);
        printf("%.2lf ", node->Value);
        in_Order(node->right);
    }
}

void pre_Order(struct Node* node) {
    if (node != NULL) {
        printf("%.2lf ", node->Value);
        pre_Order(node->left);
        pre_Order(node->right);
    }
}

void post_Order(struct Node* node) {
    if (node != NULL) {
        post_Order(node->left);
        post_Order(node->right);
        printf("%.2lf ", node->Value);
    }
}

void level_Order(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* node = queue[front++];
        printf("%.2lf ", node->Value);

        if (node->left != NULL) {
            queue[rear++] = node->left;
        }

        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}

void printTree(struct BST* bst) {
    if (bst == NULL) {
        printf("BST is not initialized!\n");
        return;
    }
    int choice;
    printf("Choose traversal type:\n");
    printf("1. In-order\n");
    printf("2. Pre-order\n");
    printf("3. Post-order\n");
    printf("4. Level-order\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            in_Order(bst->root);
            printf("\n");
            break;
        case 2:
            pre_Order(bst->root);
            printf("\n");
            break;
        case 3:
            post_Order(bst->root);
            printf("\n");
            break;
        case 4:    
            level_Order(bst->root);
            printf("\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}
