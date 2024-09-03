#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Team {
    char name[30];
    int pts;    
} typedef Team;

struct Node {
    Team team;
    struct Node *next;
} typedef Node;

Node *createNode(Team team) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->team = team;
    node->next = NULL;
    return node; 
}

void insert(Node **head, Team team) {
    Node *newNode = createNode(team);
    if (!(*head)) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

Team createTeam() {
    Team team;
    printf("Write a team name: ");
    fgets(team.name, 30, stdin);
    printf("Write team points: ");
    scanf("%d", &team.pts);
    return team;
}

void print(Node *head) {
    if (head) {
        Node *temp = head;
        int pos = 1;
        while (temp) {
            printf("%d - Name: %s|Pts: %d\n", pos, temp->team.name, temp->team.pts);
            temp = temp->next;
            pos += 1;
        }
        printf("\n");
    }
}

void sort(Node **head) {
    for (Node *i = *head; i; i = i->next) {
        for (Node *j = i->next; j; j = j->next) {
            if (i->team.pts < j->team.pts) {                
                Team temp = i->team;
                i->team = j->team;
                j->team = temp;
            }
        }
    }
}

void insertSort(Node **head, Team team) {
    Node *newNode = createNode(team);
    if (!(*head)) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next && temp->next->team.pts > newNode->team.pts) temp = temp->next;
    if (!temp->next && temp->team.pts > newNode->team.pts) {
        temp->next = newNode;
        return;
    }

    newNode->next = temp->next;    
    temp->next = newNode;
}

void main() {
    Node *teams = NULL;
    Team team;
    int opt;
    for (;;) {
        printf("1 - Enter a new Team\n");
        printf("2 - Print Ranking\n");
        printf("3 - Sort Ranking\n");
        printf("4 - Enter a new Team in Order\n");
        printf("Enter a number for options: ");
        scanf("%d", &opt);
        getchar();
        switch (opt) {
            case 1:
                team = createTeam();
                insert(&teams, team);
                break;
            case 2:
                print(teams);
                break;
            case 3:
                sort(&teams);
                break;
            case 4:
                team = createTeam();
                insertSort(&teams, team);
                break;
            default:
                printf("end\n");
                exit(1);
                break;
        }
    }
}