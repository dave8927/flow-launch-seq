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


// trapping activity from vial on monolith @ 1mL/min, 5mL
//----------------------------------------------------------------------------//
00:01.000 valves -s 0xEE // open valve 1 and 5
00:02.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (1/3)
01:03.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (2/3)
02:04.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (3/3)
03:05.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (1/1)
// pump 1, 1mL/min, -t top speed 900, acceleration 500, deceleration 0,,n time 60000 ms
04:10.000 pumps -i 0 -t 0 // stop pump 1, "-i 0" = pump 1
04:11.000 valves -s 0xFF // close all valves


// washing monolith to waste vial
//----------------------------------------------------------------------------//
04:12.000 valves -s 0xEB // open valve 3 and 5
04:13.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (1/3)
05:14.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (2/3)
06:14.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (3/3)
07:15.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
07:16.000 valves -s 0xFF // close all valves


// release from monolith to collection vial
//----------------------------------------------------------------------------//
07:17.000 valves -s 0x27 // open valve 4 and 7
07:18.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 27000 -d 10 // pump 2, 1 mL/min, 1 min (1/1)
07:48.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (1/6)
08:49.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (2/6)
09:50.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (3/6)
10:51.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (4/6)
11:52.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (5/6)
12:53.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (6/6)
13:54.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 2, 1 mL/min, 1 min (1/2)
14:55.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 2, 1 mL/min, 1 min (2/2)

15:56.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
15:57.000 valves -s 0xFF // close all valves


// final steps
//----------------------------------------------------------------------------//
15:58.000 user -s // open all valves
15:59.000 dialog "Workflow complete, collect product, replace tubing when cold" // text in " " will be 
// displayed in a dialog control, the text in this comment will be outputted to the log
