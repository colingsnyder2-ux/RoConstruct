# P5 climbing event trace

Original 007f6890 initializes Humanoid::event_Climbing, float speed signature,
at 0097a58c. Original Climbing::update 00666bc0 calls its base update and,
when active, fires this signal with the magnitude of the state's velocity.
The donor Humanoid header declares the descriptor, but donor humanoid states
have no Climbing implementation. The original Animate script now reaches
this missing event at line 561. Merely registering an inert descriptor would
hide the error without restoring behavior. Trace the original climbing state,
entry/exit and movement before integrating and testing it.

00643660 selects Climbing for humanoid state 9 (factory branch 0064387f calls 006435a0; its vtable 0084acd0 contains 00666bc0). State 10 constructs Seated. Recovered 00644a30 checks a
box ahead of the torso against nearby parts, excluding descendants of the
character; its relationship to actual state transition and force integration
still needs proof. The present Running::onStep is a reconstructed donor path
and has no Climbing transition. Recover transition predicates and force update
before adding an event-only shim.

The transition table at 0084a92c has 18 integers per state. From states 4–8,
entry 8 selects state 9; in 00644670 the original jump table 0064476c maps
entry 8 to the detected-climb byte at state+0x20, and entry 9 to its inverse.
The machine code table must be followed: the recovered draft switch order differs.
006451c0 updates that byte by calling 00644c80; its matched body first calls
00644a30 for nearby parts, then tests 17 rays at 1/7-stud height intervals.
00666410 uses this detected-climb byte to convert .7 of horizontal movement
magnitude to upward velocity. Force and complete state transitions remain open.

A diagnostic port of the broadphase and ray sweep is in PlayerEngine.cpp; it
uses the rebuilt contact manager and excludes the character. After one physics
step it detects a close rung and rejects distant, tall-wall, behind-character,
and character-descendant controls. Target-client parity, filtering equivalence,
state entry/exit, and climb forces remain unproven.

Original ray filter vtable 0084acc8 points to 006432e0: ignore dragged,
noncollidable, and same-assembly primitives; broadphase excludes character
descendants separately. The probe follows those existing filter semantics.
