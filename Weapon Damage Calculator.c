#include <stdio.h>
#include <stdlib.h> // For srand and rand functions
#include <time.h>   // For time function

// Program: Weapon Damage Calculator
// Description: Simulates weapon attack and calculates total damage

// Function to generate random hits (2-5) based on probabilities
int generateNumHits() {
    int randNum = rand() % 100;
    if (randNum < 37) return 2; else if (randNum < 75) return 3; else if (randNum < 87) return 4; else return 5;
}

// Function to calculate total damage
int calculateDamage(int baseDamage, int numHits) {
    if (numHits <= 0) return 0;
    else {
        int damage = baseDamage;
        printf("Swing: Damage = %d\n", damage);
        return damage + calculateDamage(baseDamage, numHits - 1);
    }
}

int main() {
    int baseDamage = 20; srand(time(NULL));
    int numHits = generateNumHits();
    printf("Number of hits: %d\n", numHits);
    int totalDamage = calculateDamage(baseDamage, numHits);
    printf("Total damage dealt: %d\n", totalDamage);
    return 0;
}
