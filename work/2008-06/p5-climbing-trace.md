# P5 climbing event trace

Original 007f6890 initializes Humanoid::event_Climbing, float speed signature,
at 0097a58c. Original Climbing::update 00666bc0 calls its base update and,
when active, fires this signal with the magnitude of the state's velocity.
The donor Humanoid header declares the descriptor, but donor humanoid states
have no Climbing implementation. The original Animate script now reaches
this missing event at line 561. Merely registering an inert descriptor would
hide the error without restoring behavior. Trace the original climbing state,
entry/exit and movement before integrating and testing it.

00643660 selects Climbing for humanoid state 10. Recovered 00644a30 checks a
box ahead of the torso against nearby parts, excluding descendants of the
character; its relationship to actual state transition and force integration
still needs proof. The present Running::onStep is a reconstructed donor path
and has no Climbing transition. Recover transition predicates and force update
before adding an event-only shim.
