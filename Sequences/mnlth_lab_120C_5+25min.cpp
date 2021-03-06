// Monolith - Radiolabelling only
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//


// preheat to 95C
// cook for 10min at 95C


// initial setup
//----------------------------------------------------------------------------//
00:00.100 valves -s 0x0 // open all valves
00:00.200 pressure -m -v 0 // close gas, set flow to 0
00:00.300 peltier -t 0 // turn off heater, temp 0C
00:00.400 pumps -i 0 -t 0 // stop pump 1, "-i 0" =  pump 1
00:00.600 pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2
00:00.700 valves -s 0xFF // close all valves
00:00.800 user -l 16 // white lights


// labelling in the collection vial with heater, 95C, 2min preheat + 10min
//----------------------------------------------------------------------------//
00:01.000 peltier -t 120 // preheat to 120C for 2 min
05:01.000 peltier -t 120 // heat at 120 for 10 min
20:05.000 peltier -t 0 // turn off heater, temp 0C


// Completion steps
//----------------------------------------------------------------------------//
20:06.000 user -s // open all valves
20:07.000 dialog "Workflow complete, remove vial from heating area to cool"

