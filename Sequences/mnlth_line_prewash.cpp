// Monolith - prime / wash all reagent lines
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//


// initial setup
//----------------------------------------------------------------------------//
00:00.100 valves -s 0x0 // open all valves
00:00.200 pressure -m -v 0 // close gas, set flow to 0
00:00.300 peltier -t 0 // turn off heater, temp 0C
00:00.400 pumps -i 0 -t 0 // stop pump 1, "-i 0" =  pump 1
00:00.600 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
00:00.700 valves -s 0xFF // close all valves
00:00.800 user -l 16 // white lights


// prime wash Ga and monolith lines
//----------------------------------------------------------------------------//
00:01.000 valves -s 0xEE // open valve 1 and 5
01:02.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (1/1)
// pump 1, 1mL/min, -t top speed 900, acceleration 500, deceleration 0,,n time 60000 ms
01:03.000 pumps -i 0 -t 0 // stop pump 1, "-i 0" = pump 1
01:04.000 valves -s 0xFF // close all valves


// prime wash line
//----------------------------------------------------------------------------//
01:05.000 valves -s 0xEB // open valve 3 and 5
01:06.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (1/1)
02:07.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
02:08.000 valves -s 0xFF // close all valves


// prime & wash release line
//----------------------------------------------------------------------------//
02:09.000 valves -s 0x27 // open valve 4 and 7
02:10.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 2, 1 mL/min, 1 min (1/1)
03:12.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
03:13.000 valves -s 0xFF // close all valves


// final steps
//----------------------------------------------------------------------------//
03:02.000 user -s // open all valves
03:05.000 dialog "Wash-prime run complete" // text in " " will be 
// displayed in a dialog control, the text in this comment will be outputted to the log
