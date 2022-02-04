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
00:02.000 pumps -i 0 -s 50 -t 900 -e 0 -a 500 -f 59350 -d 150 // pump 1, 1 mL/min, 1 min (1/5)
01:03.000 pumps -i 0 -s 50 -t 900 -e 0 -a 500 -f 59350 -d 150 // pump 1, 1 mL/min, 1 min (2/5)
02:04.000 pumps -i 0 -s 50 -t 900 -e 0 -a 500 -f 59350 -d 150 // pump 1, 1 mL/min, 1 min (3/5)
03:05.000 pumps -i 0 -s 50 -t 900 -e 0 -a 500 -f 59350 -d 150 // pump 1, 1 mL/min, 1 min (4/5)
04:06.000 pumps -i 0 -s 50 -t 900 -e 0 -a 500 -f 59350 -d 150 // pump 1, 1 mL/min, 1 min (5/5)
// pump 1, 1mL/min, -t top speed 900, acceleration 500, deceleration 0,,n time 60000 ms
05:10.000 pumps -i 0 -t 0 // stop pump 1, "-i 0" = pump 1
05:11.000 valves -s 0xFF // close all valves


// washing monolith to waste vial
//----------------------------------------------------------------------------//
05:12.000 valves -s 0xEB // open valve 3 and 5
05:13.000 pumps -i 0 -s 50 -t 900 -e 0 -a 500 -f 59350 -d 150 // pump 1, 1 mL/min, 1 min (1/2)
06:14.000 pumps -i 0 -s 50 -t 900 -e 0 -a 500 -f 59350 -d 150 // pump 1, 1 mL/min, 1 min (2/2)
10:15.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
10:16.000 valves -s 0xFF // close all valves


// release from monolith to collection vial
//----------------------------------------------------------------------------//
10:17.000 valves -s 0x27 // open valve 4 and 7
10:18.000 pumps -i 1 -s 50 -t 140 -e 0 -a 500 -f 59350 -d 150 // pump 2, 0.1 mL/min, 1 min (1/10)
11:19.000 pumps -i 1 -s 50 -t 140 -e 0 -a 500 -f 59350 -d 150 // pump 2, 0.1 mL/min, 1 min (2/10)
12:20.000 pumps -i 1 -s 50 -t 140 -e 0 -a 500 -f 59350 -d 150 // pump 2, 0.1 mL/min, 1 min (3/10)
13:21.000 pumps -i 1 -s 50 -t 140 -e 0 -a 500 -f 59350 -d 150 // pump 2, 0.1 mL/min, 1 min (4/10)
14:22.000 pumps -i 1 -s 50 -t 140 -e 0 -a 500 -f 59350 -d 150 // pump 2, 0.1 mL/min, 1 min (5/10)
15:23.000 pumps -i 1 -s 50 -t 140 -e 0 -a 500 -f 59350 -d 150 // pump 2, 0.1 mL/min, 1 min (6/10)
16:25.000 pumps -i 1 -s 50 -t 140 -e 0 -a 500 -f 59350 -d 150 // pump 2, 0.1 mL/min, 1 min (7/10)
16:25.500 peltier -t 95 // heater warm up, temp 95C
17:26.000 pumps -i 1 -s 50 -t 140 -e 0 -a 500 -f 59350 -d 150 // pump 2, 0.1 mL/min, 1 min (8/10)
18:27.000 pumps -i 1 -s 50 -t 140 -e 0 -a 500 -f 59350 -d 150 // pump 2, 0.1 mL/min, 1 min (9/10)
19:28.000 pumps -i 1 -s 50 -t 140 -e 0 -a 500 -f 59350 -d 150 // pump 2, 0.1 mL/min, 1 min (10/10)
20:30.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
20:31.000 valves -s 0xFF // close all valves


// labelling in the collection vial with heater, 95C, 5min
//----------------------------------------------------------------------------//
// heater already turned on on line 17 to allow time to warm up.
25:00.000 peltier -t 0 // turn off heater, temp 0C


// Cooling time & final steps
//----------------------------------------------------------------------------//
25:30.000 user -s // open all valves
26:00.000 dialog "Workflow complete, collect product, replace tubing when cold" // text in " " will be 
// displayed in a dialog control, the text in this comment will be outputted to the log