/*
StateManager.h
*/
#pragma once

/*
Both stdio.h and stdlib.h are needed for the following errors:
- identifier "NULL" is undefined
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/* State Strucutre defined as Init, Update, Draw, Destroy */
// Function pointer to the state's functions
typedef unsigned int (*fnPtr)();
typedef unsigned int (*fnPtrFl)(float);

/* Define State: Init, Update, Draw, Destroy */
typedef struct
{
    fnPtr init;
    fnPtrFl update;
    fnPtrFl draw;
    fnPtr destroy;
} State;

/*Define State Manager:
a stack,
 a capacity of states,
 and a current state as the index of the top of the stack*/

typedef struct
{
    State **stack;
    int capacity;
    int top;
} StateManager;

// State Manager Constructor
int STATEMANAGER_init(StateManager *statemanager);
// State Manager Destructor
int STATEMANAGER_free(StateManager *statemanager);
// State Manager Push State
int STATEMANAGER_push(StateManager *statemanager, State *state);
// State Manager Pop State
int STATEMANAGER_pop(StateManager *statemanager);
// State Manager Update State
int STATEMANAGER_update(StateManager *statemanager, float deltaTime);
// State Manager Draw State
int STATEMANAGER_draw(StateManager *statemanager, float deltaTime);
// Dynamically Scale State Manager
int STATEMANAGER_scale(StateManager *statemanager);

State *STATEMANAGER_getTop(StateManager *statemanager);





