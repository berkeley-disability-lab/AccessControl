/* pseudocode for servo activation

state=0;
case (state)
   {
   case 0:        // reset state, waiting for input pin to be held low 
                  //long enough to move to state 1, ready state
       Cooloff = 0;
while( input pin is low)
       {
       Cooloff++;
       If cooloff > 100
               state = 1;
           wait (1msec);
           }

   case 1:        // ready state situation
       Cooloff = 0;
while( input pin is HIGH && state == 1)
       {
       Cooloff++;
       If cooloff > 100
           {
               state = 0;    // reset us to waiting state
               activate_servo()
               }
           Wait(1msec)
           }
       State = 0;        // if servo is activate or if pin is low then back to state zero*/
state = 0; //default state
switch (state) {
  case 0 :
    //reset state; wait for input pin to be LOW long enough to move to state 1 (ready state)
    timeOut = 0; //default state
    while ()
    break;
  default:
    //read state scenario
    break;
}
