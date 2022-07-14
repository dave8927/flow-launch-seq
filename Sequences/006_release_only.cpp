// Monolith - Trap, Wash, Release and Radiolabelling
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

// release from monolith to collection vial
//----------------------------------------------------------------------------//
00:02.000 valves -s 0x27 // open valve 4 and 7
00:03.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 27000 -d 10 // pump 2, 1 mL/min, 1 min (1/1)
00:35.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (2/7)
01:36.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (3/7)
02:37.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (4/7)
03:38.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (5/7)
04:39.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (6/7)
05:40.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (7/7)
06:41.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 2, 1 mL/min, 1 min (1/2)
07:42.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 2, 1 mL/min, 1 min (2/2)

08:43.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
08:44.000 valves -s 0xFF // close all valves


// final steps
//----------------------------------------------------------------------------//
08:45.000 user -s // open all valves
08:47.000 dialog "Workflow complete, collect product, replace tubing when cold" // text in " " will be 
// displayed in a dialog control, the text in this comment will be outputted to the log
