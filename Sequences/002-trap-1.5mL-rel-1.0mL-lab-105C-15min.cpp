// Monolith - Trap, Wash, Release and Radiolabelling
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//

// trap volume - 1-15 mL
// wash volume - 2 mL
// release volume - 1 mL
// label at 105C for 15min


// initial setup
//----------------------------------------------------------------------------//
00:00.100 valves -s 0x0 // open all valves
00:00.200 pressure -m -v 0 // close gas, set flow to 0
00:00.300 peltier -t 0 // turn off heater, temp 0C
00:00.400 pumps -i 0 -t 0 // stop pump 1, "-i 0" =  pump 1
00:00.600 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
00:00.700 valves -s 0xFF // close all valves
00:00.800 user -l 16 // white lights


// turn on peltier to start preheating
//----------------------------------------------------------------------------//
00:00.900 peltier -t 105 // heat at 105C


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
06:15.000 pumps -i 0 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 1, 1 mL/min, 1 min (3/3)
07:16.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
07:16.500 valves -s 0xFF // close all valves


// release from monolith to collection vial
//----------------------------------------------------------------------------//
07:17.000 valves -s 0x27 // open valve 4 and 7
07:17.500 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 27000 -d 10 // pump 2, 1 mL/min, 30s (1/1)
07:48.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (1/10)
08:49.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (2/10)
09:50.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (3/10)
10:51.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (4/10)
11:52.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (5/10)
12:53.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (6/10)
13:54.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (7/10)
14:55.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (8/10)
15:56.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (9/10)
16:57.000 pumps -i 1 -s 50 -t 150 -e 0 -a 200 -f 59350 -d 10 // pump 2, 0.1 mL/min, 1 min (10/10)
17:58.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 2, 1 mL/min, 1 min (1/2)
18:59.000 pumps -i 1 -s 50 -t 1000 -e 0 -a 200 -f 59350 -d 10 // pump 2, 1 mL/min, 1 min (2/2)
20:00.000 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
20:01.000 valves -s 0xFF // close all valves

// prompt to move vial
//----------------------------------------------------------------------------//
20:02.000 dialog "Sequence Paused. Release complete. Move vial to hot plate and press ok to heat for 15min @105C"
20:03.000 peltier -t 105 // turn of heating
35:02.000 peltier -t 0 // turn of heating
35:03.000 dialog "15min heating time complete. Move vial to cool. Press ok to complete run."

// final steps
//----------------------------------------------------------------------------//
35:05.000 user -s // open all valves
