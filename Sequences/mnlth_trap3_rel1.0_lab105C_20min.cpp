// Monolith - Trap, Wash, Release and Radiolabelling
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//

// trap volume - 3mL
// wash volume - 
// release volume - 1mL


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
00:02.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (1/8)
01:03.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (2/8)
02:04.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (3/8)
03:05.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (4/8)
04:06.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (5/8)
05:07.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (6/8)
06:08.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (7/8)
07:09.000 pumps -i 0 -s 50 -t 600 -e 0 -a 200 -f 59350 -d 10 // pump 1, 0.5 mL/min, 1 min (8/8)
08:10.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (1/1)
// pump 1, 1mL/min, -t top speed 900, acceleration 500, deceleration 0,,n time 60000 ms
09:11.000 pumps -i 0 -t 0 // stop pump 1, "-i 0" = pump 1
09:12.000 valves -s 0xFF // close all valves


// washing monolith to waste vial
//----------------------------------------------------------------------------//
10:13.000 valves -s 0xEB // open valve 3 and 5
10:14.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (1/3)
11:15.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (2/3)
12:16.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (3/3)
13:17.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
13:18.000 valves -s 0xFF // close all valves


// turn on peltier to start preheating
//----------------------------------------------------------------------------//
13:18.500 peltier -t 105 // heat at 105C


// release from monolith to collection vial
//----------------------------------------------------------------------------//
13:19.000 valves -s 0x27 // open valve 4 and 7
13:20.500 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 27000 -d 10 // pump 2, 1 mL/min, 30s (1/1)
14:51.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (1/10)
15:52.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (2/10)
16:53.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (3/10)
17:54.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (4/10)
18:55.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (5/10)
19:56.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (6/10)
20:57.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (7/10)
21:58.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (8/10)
22:59.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (9/10)
23:00.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (10/10)
24:01.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 2, 1 mL/min, 1 min (1/2)
25:02.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 2, 1 mL/min, 1 min (2/2)
26:03.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
26:04.000 valves -s 0xFF // close all valves

// prompt to move vial
//----------------------------------------------------------------------------//
26:05.000 dialog "Sequence Paused. Release complete. Move vial to hot plate and press ok to heat for 25min @105C"
46:02.000 peltier -t 0 // turn of heating
46:03.000 dialog "25min heating time complete. Move vial to cool. Press ok to complete run."

// final steps
//----------------------------------------------------------------------------//
46:05.000 user -s // open all valves

