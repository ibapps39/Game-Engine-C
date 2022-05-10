#include <StateManager.h>
/* State Strucutre defined as Init, Update, Draw, Destroy */
//Function pointer to the state's functions
typedef unsigned int (*fnPtr)();
typedef unsigned int (*fnPtrFl)(float);

/* Define State: Init, Update, Draw, Destroy */
typedef struct {
    fnPtr init;
    fnPtr update;
    fnPtr draw;
    fnPtr destroy;
} State;

/*Define State Manager: 
a stack,
 a capacity of states, 
 and a current state as the index of the top of the stack*/

 typedef struct {
     State **stack;
     int capacity;
     int top;
 } StateManager;

