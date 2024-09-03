#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[30];
} typedef Product;

struct Node {
    Product product;
    struct Node *next;
    struct Node *prev;
} typedef Node;



Product createProduct(int id, char *name) {
    Product product;
    product.id = id;
    strcpy(product.name, name);
    return product;
}

Node *createNode(Product product) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->product = product;
    node->prev = node->next = NULL;
    return node;
}

void insertProduct(Node **head, int id, char *name) {
    Product newProduct = createProduct(id, name);
    Node *newNode = createNode(newProduct);

    if (!(*head)) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next) temp = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
}

void print(Node *head) {
    if (head) {
        Node *temp = head;
        while (temp) {
            printf("|id: %d\t|product: %s\n", temp->product.id, temp->product.name);
            temp = temp->next;
        }
        printf("\n");
    }
}

int binarySearch(Node *head, char *name) {
    int id = 0;
    if (head) {
        Node *temp = head;
        while (temp && strcmp(name, temp->product.name) != 0) temp = temp->next;
        if (temp) id = temp->product.id;
        return id;
    }
    return 0;
}

void selectionSort(Node **head) {
    Node *min; //min actually data, assign minimum element
    for (Node *i = *head; i && i->next; i = i->next) {
        min = i;
        /*Verify if the next value is most than actually (i)*/
        for (Node *j = i->next; j; j = j->next) 
            if (strcmp(j->product.name, min->product.name) < 0) min = j; //if j->products.name < min->product.name => min = j;
        
        /*Swap data*/
        if (min != i) { 
            Product temp = i->product;
            i->product = min->product;
            min->product = temp;
        }
    }
}

void main() {
    Node *products = NULL;
    int opt;
    int id = 0;
    char name[30];
    for (;;) {
        printf("1 - Add a product\n");
        printf("2 - Print products\n");
        printf("3 - Binary Search\n");
        printf("4 - Selection sort\n");
        printf("Enter a number for 'opt': ");
        scanf("%d", &opt);
        getchar();
        switch (opt) {
            case 1:
                printf("Enter a name for product: ");
                fgets(name, 30, stdin);
                getchar();
                id += 1;
                insertProduct(&products, id, name);
                break;
            case 2:
                print(products);
                break;
            case 3:
                printf("Enter a name for product: ");
                fgets(name, 30, stdin);
                getchar();

                int idProduct = binarySearch(products, name);
                if (idProduct) printf("id Product: %d\n", idProduct);
                    else printf("product not found\n");

                break;
            case 4:
                selectionSort(&products);
                break;
            default:
                printf("end\n");
                exit(1);
                break;
        }
    }
}