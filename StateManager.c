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
/*
In case we reach the top of the stack and because games can have more than 3
states, we can push more states onto the stack
*/
int STATEMANAGER_scale(StateManager *statemanager) {
    statemanager->capacity *= 2;
    statemanager->stack = realloc(statemanager->stack, sizeof (State *) * statemanager->capacity);   
}
/*
Before pushing a state onto the stack, we check if the stack is full.
If it is, we scale the stack
Otherwise we push the state onto the stack
*/
int STATEMANAGER_push(StateManager *statemanager, State *state) 
{
    //increment the top of the stack
    statemanager->top++;
    //sets the state to the top of the stack
    statemanager->stack[statemanager->top] = state;

    if (statemanager->top == statemanager->capacity - 1) {
        STATEMANAGER_scale(statemanager);
    }
    if (state->init != NULL) {
        state->init();
    }
}
int STATEMANAGER_pop(StateManager *statemanager) 
{}
int STATEMANAGER_gettop(StateManager *statemanager) 
{}