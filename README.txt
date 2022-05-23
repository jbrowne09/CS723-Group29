Group 29 ReadMe

- A Cruise Controller developed in esterel with some support functions in C
- All work was done in: 'group29_esterel.strl' and 'group29_esterel_data.c',
  all other files were provided or auto-generated
- Design report with implementation/design information is included: 'report_group_29.pdf'
- Running the project requires esterel installed in linux, additionally you would need 
  gcc-multilib installed to support the 32-bit build method (esterel only supports 32-bit OS 
  as far as I'm aware). 
- I have been unable to locate a reliable download/installation source for esterel to match 
  the setup originally provided for running the project and so have only listed the original 
  instructions as they would be with all the required libraries installed.

The original running steps were: 

1) Open a terminal window in the src folder (or navigate to using cd)
2) Enter command make group29_esterel.xes
3) Enter command ./group29_esterel.xes
4) Simulator Windows should open, click to provide an input signal (enter value
   for valued signals as well).
