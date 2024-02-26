#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"

// Function to create a new champion
Champion* createChampion() {
    Champion* newChampion = (Champion*)malloc(sizeof(Champion));
    if (!newChampion) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Assigning role randomly
    int roleProb = rand() % 4;
    switch (roleProb) {
        case 0:
            newChampion->role = MAGE;
            newChampion->level = rand() % 4 + 5; // MAGE level: 5 to 8
            break;
        case 1:
            newChampion->role = FIGHTER;
            newChampion->level = rand() % 4 + 1; // FIGHTER level: 1 to 4
            break;
        case 2:
            newChampion->role = SUPPORT;
            newChampion->level = rand() % 4 + 3; // SUPPORT level: 3 to 6
            break;
        case 3:
            newChampion->role = TANK;
            newChampion->level = rand() % 8 + 1; // TANK level: 1 to 8
            break;
    }

    newChampion->next = NULL;
    return newChampion;
}

// Function to add a champion to the linked list in descending order of level
Champion* addChampion(Champion* head, Champion* c) {
    if (!head || c->level > head->level) {
        c->next = head;
        return c;
    }

    Champion* current = head;
    while (current->next && current->next->level > c->level) {
        current = current->next;
    }

    c->next = current->next;
    current->next = c;

    return head;
}

// Function to build a list of champions
Champion* buildChampionList(int n) {
    Champion* head = NULL;
    for (int i = 0; i < n; ++i) {
        Champion* newChampion = createChampion();
        head = addChampion(head, newChampion);
    }
    return head;
}

// Function to print the list of champions
void printChampionList(Champion* head) {
    Champion* current = head;
    while (current) {
        printf("%c%d ", current->role, current->level);
        current = current->next;
    }
    printf("\n");
}

// Function to remove the first champion from the list
Champion* removeChampion(Champion* head) {
    if (!head) {
        return NULL;
    }

    Champion* temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Function to destroy the entire list of champions
Champion* destroyChampionList(Champion* head) {
    while (head) {
        head = removeChampion(head);
    }
    return NULL;
}
