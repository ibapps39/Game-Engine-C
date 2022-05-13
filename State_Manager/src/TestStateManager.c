#include "TestStateManager.h"

unsigned int initStateA(){
    printf("state A init\n");
    return 0;
}
unsigned int initStateB(){
    printf("state B init\n");
    return 0;
}
unsigned int destroyStateA(){
    printf("state A destroy\n");
    return 0;
}
unsigned int destroyStateB(){
    printf("state B destroy\n");
    return 0;
}
unsigned int updateStateB(float deltaTime){
    printf("state B update %f\n", deltaTime);
    return 0;
}

int main() {
    StateManager statemanager;
    STATEMANAGER_init(&statemanager);

    State stateA = {0};
    stateA.init = initStateA;
    stateA.destroy = destroyStateA;

    State stateB = {0};
    stateB.init = initStateB;
    stateB.update = updateStateB;
    stateB.destroy = destroyStateB;

    STATEMANAGER_push(&statemanager, &stateA);
    STATEMANAGER_update(&statemanager, 10.0f);
    STATEMANAGER_push(&statemanager, &stateB);
    STATEMANAGER_update(&statemanager, 10.0f);

    STATEMANAGER_pop(&statemanager);
    STATEMANAGER_update(&statemanager, 10.0f);

    STATEMANAGER_free(&statemanager);
}