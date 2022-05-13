//header guard
#ifndef TEST_STATEMANAGER_H
#define TEST_STATEMANAGER_H
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "StateManager.h"
/*
A Unit Test for the State Manager
*/
unsigned int initStateA();
unsigned int initStateB();
unsigned int destroyStateA();
unsigned int destroyStateB();
unsigned int updateStateB(float deltaTime);
#endif

