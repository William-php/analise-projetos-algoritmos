#include <stdio.h>
#include <stdlib.h>

struct NodeTree {
    int item;
    struct NodeTree *left;
    struct NodeTree *right;
} typedef NodeTree;

struct NodeList {
    int item;
    struct NodeList *next;
} typedef NodeList;

NodeList *createNodeList(int item) {
    NodeList *nodeList = (NodeList*)malloc(sizeof(NodeList));
    nodeList->next = NULL;
    nodeList->item = item;
    return nodeList;
}

void insertNodeList(NodeList **head, int item) {
    if (!(*head)) {
        *head = createNodeList(item);
        return;
    }

    NodeList *nodeTemp = *head;

    while (nodeTemp && nodeTemp->next) nodeTemp = nodeTemp->next;
    nodeTemp->next = createNodeList(item);
}

void printList(NodeList *head) {
    if (head) {
        for (NodeList *temp = head; temp; temp = temp->next) printf("|%d| => ", temp->item);
        printf("\n");
    }
}

void bubbleSort(NodeList *head) {
    for (NodeList *i = head; i; i = i->next) {
        for (NodeList *j = head; j; j = j->next) {
            if (j->item > i->item) {
                int temp = j->item;
                j->item = i->item;
                i->item = temp;
            }
        }
    }
}


NodeTree *createNodeTree(int item) {
    NodeTree *nodeTree = (NodeTree*)malloc(sizeof(NodeTree));
    nodeTree->item = item;
    nodeTree->left = NULL;
    nodeTree->right = NULL;
    return nodeTree;
}

NodeTree *insertNodeTree(NodeTree *root, int item) {
    if (!root) {
        root = createNodeTree(item);
        return root;
    }

    if (item < root->item) {
        root->left = insertNodeTree(root->left, item);
    } else {
        root->right = insertNodeTree(root->right, item);
    }
    return root;
}

void searchTreeItem(NodeTree *root, int key, int *item) {
    
    //Backtracking
    if (root) {

        if (root->item == key) {
            printf("key was found\n");
            *item = root->item;
            return;
        }

        searchTreeItem(root->left, key, item); 
        printf("Item: %d\n", root->item);
        searchTreeItem(root->right, key, item);
    }    
}





void printLinkedList(NodeList *head) {
    if (head) {
        NodeList *temp = head;
        while (temp) {
            printf("\t|%d|", temp->item);
            temp = temp->next;
        }
        printf("\n");
    }
}

void printTree(NodeTree *root) {
    if (root) {
        printTree(root->left);
        printf("|%d| => ", root->item);
        printTree(root->right);
    }
}

void main() {
    NodeList *linkedList = NULL;
    NodeTree *tree = NULL;
    int opt, item, key;
    for (;;) {
        printf("1 - Insert item\n");
        printf("2 - Get a number in tree\n");
        printf("3 - Print LinkedList\n");
        printf("4 - Print tree\n");
        printf("5 - BubbleSort\n");
        printf("Enter a value for opt: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("Enter a value for item: ");
                scanf("%d", &item);
                tree = insertNodeTree(tree, item);
                break;
            case 2:
                printf("Enter a value for key: ");
                scanf("%d", &key);
                getchar();
                searchTreeItem(tree, key, &item);
                if (item == key) insertNodeList(&linkedList, item);
                break;
            case 3:
                printLinkedList(linkedList);
                break;
            case 4:
                printTree(tree);
                printf("\n");
                break;
            case 5:
                bubbleSort(linkedList);
                break;
            default:
                exit(1);
                break;
        }
    }
}