#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "group29_esterel.h"


char* _states_to_text(states state)
{
	if (state == OFF) 
	{
		return "OFF";
	}
	else if (state == ON)
	{
		return "ON";
	}
	else if (state == STDBY)
	{
		return "STDBY";
	}
	else
	{
		return "DISABLE";
	}
}
void _text_to_states(states* state, char* text)
{
	if (strcmp(text, "OFF") == 0)
	{
		*state = OFF;
	}
	else if (strcmp(text, "ON") == 0)
	{
		*state = ON;
	}
	else if (strcmp(text, "STDBY") == 0)
	{
		*state = STDBY;
	}
	else 
	{
		*state = DISABLE;
	}
}
void setState(states* state, int value)
{
	if (value == 1)
	{
		*state = OFF;
	}
	else if (value == 2)
	{
		*state = ON;
	}
	else if (value == 3)
	{
		*state = STDBY;
	}
	else 
	{
		*state = DISABLE;
	}
}
/*
DESCRIPTION: Saturate the throttle command to limit the acceleration.
PARAMETERS: throttleIn - throttle input
            saturate - true if saturated, false otherwise
RETURNS: throttle output (ThrottleCmd)
*/
float saturateThrottle(float throttleIn, bool* saturate)
{
	static const float THROTTLESATMAX = 45.0;
	if (throttleIn > THROTTLESATMAX) {
		*saturate = true;
		return THROTTLESATMAX;
	}
	else if (throttleIn < 0) {
		*saturate = true;
		return 0;
	}
	else {
		*saturate = false;
		return throttleIn;
	}
}

/*
DESCRIPTION: Saturate the throttle command to limit the acceleration.
PARAMETERS: isGoingOn - true if the cruise control has just gone into the ON state 
                        from another state; false otherwise
            saturate - true if saturated, false otherwise
RETURNS: throttle output (ThrottleCmd)
*/
float regulateThrottle(int isGoingOn, float cruiseSpeed, float vehicleSpeed)
{
	static const float KP = 8.113;
	static const float KI = 0.5;
	static _Bool saturate = true;
	static float iterm = 0;
	
	if (isGoingOn) {
		iterm = 0;	// reset the integral action
		saturate = true;	
	}
	float error = cruiseSpeed - vehicleSpeed;
	float proportionalAction = error * KP;
	if (saturate)
		error = 0;	// integral action is hold when command is saturated
	iterm = iterm + error;
	float integralAction = KI * iterm;
	return saturateThrottle(proportionalAction + integralAction, &saturate);
}
