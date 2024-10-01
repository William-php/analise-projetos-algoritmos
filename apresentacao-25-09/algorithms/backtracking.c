#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    struct Node *right;
    struct Node *left;
} typedef Node;

Node *create(char ch) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->ch = ch;
    node->right = NULL;
    node->left = NULL;
    return node;
}

Node *insert(Node *root, char ch) {
    if (!root) {
        return create(ch);
    }
    if (ch > root->ch) {
        root->right = insert(root->right, ch);
    } else {
        root->left = insert(root->left, ch);
    }
    return root;
}

//backTracking
Node print(Node *root) {
    if (root) {
        print(root->left);
        printf("|%c|->", root->ch);
        print(root->right);
    }
}

void main() {
    Node *tree = NULL;
    int opt;
    char ch;
    for (;;) {
        printf("1 - Insert a data;\n");
        printf("2 - Print tree;\n");
        printf("Enter a option: ");
        scanf("%d", &opt);
        getchar();
        switch (opt) {
            case 1:
                printf("Enter a char: ");
                scanf("%c", &ch);                
                tree = insert(tree, ch);
                break;
            case 2:
                print(tree);
                printf("\n");
                break;
            default:
                printf("end.\n");
                exit(1);
        }
    }
};