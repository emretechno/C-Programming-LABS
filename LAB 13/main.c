#include <stdio.h>
#include <stdlib.h>
#include "util.h"

struct Node {
    double Value;
    struct Node* left;
    struct Node* right;
}node;

struct BST {
    struct Node* root;
};


int main() {
    struct BST* bst = generateBST("input.txt");
    if (bst == NULL) {
        return 1;
    }
    int choice;
    double value;
   int flag =1;
   printf("Welcome to my BST program!\n");
    do {
        printf("1. Add node\n");
        printf("2. Remove node\n");
        printf("3. Search  node\n");
        printf("4. Count nodes\n");
        printf("5. Get max depth\n");
        printf("6. Count leaf nodes\n");
        printf("7. Print tree\n");
        printf("8. Exit\n>>>");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%lf", &value);
                addNode(bst, value);
                break;
            case 2:
                printf("Enter value to remove: ");
                scanf("%lf", &value);
                remove_node(bst, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%lf", &value);
                struct Node* foundNode = searchValue(bst, value);
                if (foundNode != NULL) {
                    printf("Node with value %.2lf found!\n", value);
                }
                else {
                    printf("Node with value %.2lf not found!\n", value);
                }
                break;
            case 4:
                printf("Total number of nodes: %d\n", countNodes(bst));
                break;
            case 5:
                printf("Maximum depth of the tree: %d\n", find_depth_max(bst));
                break;
            case 6:
                printf("Number of leaf nodes: %d\n", countLeafNodes(bst));
                break;
            case 7:
                printTree(bst);
                break;
            case 8:
                 flag = 0;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (flag);

    return 0;
}

