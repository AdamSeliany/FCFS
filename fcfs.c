#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

// Structure pour représenter un processus
typedef struct {
    int pid;      // Identifiant du processus
    int arrival;  // Temps d'arrivée du processus
    int burst;    // Durée d'exécution du processus
} Process;

// Fonction pour trier les processus par temps d'arrivée croissant
void sortProcessesByArrival(Process *processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival > processes[j + 1].arrival) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Fonction pour calculer le temps d'attente moyen
float calculateAverageWaitingTime(Process *processes, int n) {
    int totalWaitingTime = 0;
    int currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        int waitingTime = currentTime - processes[i].arrival;
        totalWaitingTime += waitingTime;
        currentTime += processes[i].burst;
    }
    
    return (float) totalWaitingTime / n;
}

int main() {
    int n; // Nombre de processus
    Process processes[MAX_PROCESS]; // Tableau des processus
    
    printf("Entrez le nombre de processus : ");
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_PROCESS) {
        printf("Nombre de processus invalide.\n");
        return 1;
    }
    
    printf("Entrez les temps d'arrivée et durées d'exécution des processus :\n");
    for (int i = 0; i < n; i++) {
        printf("Processus %d :\n", i + 1);
        printf("Temps d'arrivée : ");
        scanf("%d", &processes[i].arrival);
        printf("Durée d'exécution : ");
        scanf("%d", &processes[i].burst);
        processes[i].pid = i + 1;
    }
    
    sortProcessesByArrival(processes, n); // Trier les processus par temps d'arrivée
    
    printf("Ordre d'exécution des processus : ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].pid);
    }
    printf("\n");
    
    printf("Temps d'attente moyen : %.2f unités de temps\n", calculateAverageWaitingTime(processes, n));
    
    return 0;
}
