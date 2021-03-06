#include "StateManager.h"
/*
State Manager Constructor
Sets min. capacity, allocate memory, and sets the index to the
top of the stack
*/
int STATEMANAGER_init(StateManager *statemanager)
{
    statemanager->capacity = 3;
    statemanager->stack = malloc(sizeof(State *) * statemanager->capacity);
    statemanager->top = -1;
    return 0;
}
/*
State Manager Destructor
Frees the memory allocated to the stack
Until the stack is empty/at the top, it pops from the top of the stack.
Then the stack is freed.
*/
int STATEMANAGER_free(StateManager *statemanager)
{
    do
    {
        STATEMANAGER_pop(statemanager);
    } while (statemanager->top > -1);
    // match the malloc with a free in init!
    free(statemanager->stack);
    return 0;
}
/*
In case we reach the top of the stack and because games can have more than 3
states, we can push more states onto the stack
*/
int STATEMANAGER_scale(StateManager *statemanager)
{
    statemanager->capacity *= 2;
    statemanager->stack = realloc(statemanager->stack, sizeof(State *) * statemanager->capacity);
}
/*
Get the top of the stack
*/
State *STATEMANAGER_getTop(StateManager *statemanager)
{
    return statemanager->stack[statemanager->top];
}
/*
Before pushing a state onto the stack, we check if the stack is full.
If it is, we scale the stack
Otherwise we push the state onto the stack
*/
int STATEMANAGER_push(StateManager *statemanager, State *state)
{
    if (statemanager->top == statemanager->capacity - 1)
    {
        STATEMANAGER_scale(statemanager);
    }
    if (state->init != NULL)
    {
        state->init();
    }
    // increment the top of the stack
    statemanager->top++;
    // sets the state to the top of the stack
    statemanager->stack[statemanager->top] = state;
    return statemanager->top;
}
/*
Check to see if the stack is empty based on the value of top,
then pop by pointing the top of the stack to nothing/null,
and decrement the top of the stack
*/
int STATEMANAGER_pop(StateManager *statemanager)
{
    State *top = STATEMANAGER_getTop(statemanager);
    if (statemanager->top == -1)
    {
        return 0;
    }
    if (top->destroy != NULL)
    {
        top->destroy();
    }
    statemanager->stack[statemanager->top] = NULL;
    statemanager->top--;
    return statemanager->top;
}
/*
The update function is called every frame.
It checks to see if the stack is empty,
then checks to see if the top of the stack has an update function.
*/
int STATEMANAGER_update(StateManager *statemanager, float deltatime)
{
    State *state = STATEMANAGER_getTop(statemanager);
    if (state->update == NULL)
    {
        return 1;
    }
    return state->update(deltatime);
}
/*
The draw function is called every frame.
It checks to see if the stack is empty,
then checks to see if the top of the stack has a draw function.
*/

int STATEMANAGER_draw(StateManager *statemanager, float deltatime)
{
    State *state = STATEMANAGER_getTop(statemanager);
    if (state->draw == NULL)
    {
        return 1;
    }
    return state->draw(deltatime);
}
