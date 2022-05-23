//The type 'string' is defined as 'char*' in Esterel, hence passing a string by referenc  is 'char**'
//Avoid naming a function 'recv'
#include<stdbool.h>

#define _states(x,y) (*(x)=y)

typedef enum states {OFF, ON, DISABLE, STDBY} states;

char* _states_to_text(states state);
void _text_to_states(states* state, char* text);
void setState(states* state, int value);
float saturateThrottle(float throttleIn, bool* saturate);
float regulateThrottle(int isGoingOn, float cruiseSpeed, float vehicleSpeed);
