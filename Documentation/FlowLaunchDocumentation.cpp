// Flow Launch Documentation for Control Box 
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//

// comments
//----------------------------------------------------------------------------//
// code can be commented by using double forward slashes // the text after 
// the slash will be commented and will not be run by Flow Launch, if the commented 
// text is after a valid command the text will be outputted to the log

// time selectors
//----------------------------------------------------------------------------//
// time should always be defined in the format mm:ss.zzz
// where mm = min, ss = seconds, zzz = milliseconds
// for example a line starting with "09:33:087" will run at 9 min, 33 s, 87 ms


// gas flow %
//----------------------------------------------------------------------------//
mm:ss.zzz pressure -m -v 0 // close gas, set flow to 0
mm:ss.zzz pressure -m -v 41 // open gas, set flow to 1%
mm:ss.zzz pressure -m -v 410 // open gas, set flow to 10%
mm:ss.zzz pressure -m -v 2048 // open gas, set flow to 50%
mm:ss.zzz pressure -m -v 4095 // open gas, set flow to 100%


// heater & temp controls
//----------------------------------------------------------------------------//
mm:ss.zzz peltier -t 0 // turn off heater, temp 0C
mm:ss.zzz peltier -t 50 // turn on heater, temp 50C
mm:ss.zzz peltier -t 105 // turn on heater, temp 105C
// it takes some time to heat / cool so factor that in with the timings


// pump control
//----------------------------------------------------------------------------//
mm:ss.zzz pumps -i 0 -t 0 // stop pump 1, "-i 0" =  pump 1
mm:ss.zzz pumps -i 1 -t 0 // stop pump 2, "-i 1" = pump 2

// pump controls for pump 1
mm:ss.zzz pumps -i 0 -s 50 -t 1500 -e 0 -a 750 -f 4025 -d 225 
// pump 1, 3mL/min, -t top speed 1500, acceleration 50, deceleration 0, run time 5000ms (750+4025+225)
mm:ss.zzz pumps -i 0 -s 50 -t 1500 -e 0 -a 750 -f 9025 -d 225 
// pump 1, 3mL/min, -t top speed 1500, acceleration 50, deceleration 0, run time 1000ms (750+9025+225)
mm:ss.zzz pumps -i 0 -s 50 -t 1000 -e 0 -a 500 -f 4350 -d 150 
// pump 1, 2mL/min, -t top speed 1000, acceleration 50, deceleration 0, run time 5000ms

// pump controls for pump 2 are the same, but the "-i 0" should be changed to "-i 1"
// "-f" flag controls pump running time, "-f 4025" plus "-a 750" plus "-d 225" equals 5000ms,
// so -f XXXX should be set after removing 750+225 from the required running time


// valve control
//----------------------------------------------------------------------------//
// valve 1 = sample valve (eg generator eluent)
// valve 2 = gas supply
// valve 3 = EtOH valve
// valve 4 = elution valve
// valve 5 = waste valve from pump 1
// valve 6 = waste valve (fed via gas, valve 2 ???)
// valve 7 = collection valve to heater

mm:ss.zzz valves -s 0x0 // open all valves
mm:ss.zzz valves -s 0xFF // close all valves
mm:ss.zzz valves -s 0xEE // open valve 1 and 5
mm:ss.zzz valves -s 0xEB // open valve 3 and 5
mm:ss.zzz valves -s 0xDD // open valve 2 and 6
mm:ss.zzz valves -s 0x7B // open valve 3 and 7
mm:ss.zzz valves -s 0x27 // open valve 4 and 7


// light & alarm control
//----------------------------------------------------------------------------//
mm:ss.zzz user -l 16 // white lights
mm:ss.zzz user -l 66 // red lights, alarm on
mm:ss.zzz user -l 136 // red lights off, alarm off


// dialog controls
//----------------------------------------------------------------------------//
mm:ss.zzz dialog "Run finished, replace tubing when cold" // text in " " will be 
// displayed in a dialog control, the text in this comment will be outputted to the log


// Emergency Stop
//----------------------------------------------------------------------------//
mm:ss.zzz user -s

