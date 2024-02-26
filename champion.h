#ifndef CHAMPION_H
#define CHAMPION_H

// Enum for champion roles
typedef enum {
    MAGE = 'M',
    FIGHTER = 'F',
    SUPPORT = 'S',
    TANK = 'T'
} ChampionRole;

// Struct to represent a champion
typedef struct Champion {
    ChampionRole role;
    int level;
    struct Champion* next;
} Champion;

// Function prototypes
Champion* createChampion();
Champion* addChampion(Champion* head, Champion* c);
Champion* buildChampionList(int n);
void printChampionList(Champion* head);
Champion* removeChampion(Champion* head);
Champion* destroyChampionList(Champion* head);

#endif // CHAMPION_H
