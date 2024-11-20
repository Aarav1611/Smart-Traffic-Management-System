#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a vehicle
typedef struct Vehicle {
    int id;
    char type[10]; // "Normal" or "Emergency"
    struct Vehicle* next;
} Vehicle;

// Structure for an intersection
typedef struct Intersection {
    int id;
    Vehicle* queue; // Queue of vehicles
    int signalTimer; // Signal timer in seconds
    struct Intersection* next;
} Intersection;

// Function to create a new vehicle
Vehicle* createVehicle(int id, char* type) {
    Vehicle* newVehicle = (Vehicle*)malloc(sizeof(Vehicle));
    newVehicle->id = id;
    strcpy(newVehicle->type, type);
    newVehicle->next = NULL;
    return newVehicle;
}

// Function to create a new intersection
Intersection* createIntersection(int id) {
    Intersection* newIntersection = (Intersection*)malloc(sizeof(Intersection));
    newIntersection->id = id;
    newIntersection->queue = NULL;
    newIntersection->signalTimer = 10; // Default timer
    newIntersection->next = NULL;
    return newIntersection;
}

// Add a new intersection to the linked list
Intersection* addIntersection(Intersection* head, int id) {
    Intersection* newIntersection = createIntersection(id);
    if (!head) {
        return newIntersection;
    }
    Intersection* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newIntersection;
    return head;
}

// Add a vehicle to the queue of a specific intersection
void addVehicle(Intersection* head, int intersectionID, int vehicleID, char* type) {
    Intersection* temp = head;
    while (temp && temp->id != intersectionID) {
        temp = temp->next;
    }
    if (!temp) {
        printf("Intersection %d not found!\n", intersectionID);
        return;
    }

    Vehicle* newVehicle = createVehicle(vehicleID, type);
    if (!temp->queue) {
        temp->queue = newVehicle;
    } else {
        Vehicle* vTemp = temp->queue;
        while (vTemp->next) {
            vTemp = vTemp->next;
        }
        vTemp->next = newVehicle;
    }
    printf("Vehicle %d (%s) added to Intersection %d.\n", vehicleID, type, intersectionID);
}

// Process vehicles at an intersection
void processVehicles(Intersection* head) {
    Intersection* temp = head;
    while (temp) {
        printf("\nProcessing Intersection %d:\n", temp->id);
        int timer = temp->signalTimer;
        while (timer > 0 && temp->queue) {
            Vehicle* vehicle = temp->queue;
            printf("Processing Vehicle %d (%s)\n", vehicle->id, vehicle->type);
            temp->queue = temp->queue->next;
            free(vehicle);
            timer -= 2; // Assume each vehicle takes 2 seconds to pass
        }
        if (!temp->queue) {
            printf("All vehicles cleared at Intersection %d.\n", temp->id);
        } else {
            printf("Vehicles remaining at Intersection %d.\n", temp->id);
        }
        temp = temp->next;
    }
}

// Adjust signal timer based on the number of vehicles in the queue
void adjustSignalTimer(Intersection* head) {
    Intersection* temp = head;
    while (temp) {
        int count = 0;
        Vehicle* vTemp = temp->queue;
        while (vTemp) {
            count++;
            vTemp = vTemp->next;
        }
        if (count > 5) {
            temp->signalTimer = 20; // Increase timer if queue is long
        } else {
            temp->signalTimer = 10; // Default timer
        }
        printf("Intersection %d: Queue size = %d, Signal Timer = %d seconds\n", temp->id, count, temp->signalTimer);
        temp = temp->next;
    }
}

// Display all intersections and their queues
void displayIntersections(Intersection* head) {
    Intersection* temp = head;
    while (temp) {
        printf("\nIntersection %d: Signal Timer = %d seconds\n", temp->id, temp->signalTimer);
        Vehicle* vTemp = temp->queue;
        if (!vTemp) {
            printf("No vehicles in queue.\n");
        } else {
            printf("Vehicles in queue: ");
            while (vTemp) {
                printf("%d(%s) -> ", vTemp->id, vTemp->type);
                vTemp = vTemp->next;
            }
            printf("NULL\n");
        }
        temp = temp->next;
    }
}

// Main function
int main() {
    Intersection* head = NULL;
    int choice, intersectionID, vehicleID;
    char type[10];

    while (1) {
        printf("\nSmart City Traffic Management System\n");
        printf("1. Add Intersection\n");
        printf("2. Add Vehicle\n");
        printf("3. Process Vehicles\n");
        printf("4. Adjust Signal Timers\n");
        printf("5. Display Intersections\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Intersection ID: ");
                scanf("%d", &intersectionID);
                head = addIntersection(head, intersectionID);
                break;
            case 2:
                printf("Enter Intersection ID: ");
                scanf("%d", &intersectionID);
                printf("Enter Vehicle ID: ");
                scanf("%d", &vehicleID);
                printf("Enter Vehicle Type (Normal/Emergency): ");
                scanf("%s", type);
                addVehicle(head, intersectionID, vehicleID, type);
                break;
            case 3:
                processVehicles(head);
                break;
            case 4:
                adjustSignalTimer(head);
                break;
            case 5:
                displayIntersections(head);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
