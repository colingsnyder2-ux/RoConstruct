# FreeFalling signal trace

007f68d0 initializes Humanoid::event_FreeFalling, bool signature, at 0097a47c;
its name string is 0083d8e8. Original Freefall constructor 00667810 looks up
that descriptor at 0066788f and fires true; destructor 00667930 looks it up at
00667975 and fires false. The same native methods also save/restore Head and Torso friction, absent from the donor Freefall implementation. Recovered
source is in src/2008-06/00667810.cpp and 00667930.cpp. Donor headers already
declare event_FreeFalling, but current glue does not define it, and donor
Freefall ctor has no fire/dtor override. Integrate both transition notifications
and verify friction restoration; verify entry and exit
with scripts and original-client comparisons. Do not count registration alone
as functional signal support.

005d8a10 resolves Head; 005d8b10 resolves Torso. 00598d50 reads the
Part friction property; 0059e090 sets it, descriptor name at 008331c8.
