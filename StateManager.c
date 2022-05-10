#include <StateManager.h>
/*
State Manager Constructor
Sets min. capacity, allocate memory, and sets the index to the
top of the stack
*/
int STATEMANAGER_init(StateManager *statemanager) 
{
    statemanager-> capacity = 3;
    statemanager-> stack = malloc(sizeof(State *) * statemanager->capacity);
    statemanager-> top = -1;
    return 0;
}

/*
State Manager Destructor
Frees the memory allocated to the stack
Until the stack is empty/at the top, it pops the top of the stack
*/
int STATEMANAGER_free(StateManager *statemanager) {
    do {
        STATEMANAGER_pop(statemanager);
    } while (statemanager->top > -1);
    //match the malloc in init
    free(statemanager-> stack); 
    return 0; 
}

