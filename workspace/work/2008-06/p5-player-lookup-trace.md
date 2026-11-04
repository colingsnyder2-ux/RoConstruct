# P5 animation player lookup probe

The supplied original Animate script fails at line 113 while calling
`Players:GetPlayerFromCharacter(script.Parent)`. An authored probe
`tests/fixtures/p5-player-lookup-probe.rbxl` calls the same method for the
attached local Actor inside `pcall`. On source revision 9484069c6b, with
`--p5-control --p5-play --frames 60`, it logs `LOOKUP false function: ...`.
The thrown Lua error object is a function, so the existing message `(error
object)` conceals its cause. An experimental fix for metatable stack
imbalance in Bridge::getValue did not change either result; it was reverted.
Next trace the member-call boundary, argument conversion and Lua error stack.
This result is not evidence of animation, sound or complete player parity.

Controls: `pcall` succeeds for reading Players, Actor, and the lookup method;
only calling the method fails. An instrumented controller check also invokes
`Players::getPlayerFromCharacter(actor)` directly and obtains the local Player,
so the observed failure lies in the Lua/member-call boundary or argument/result
conversion, not the native player lookup itself. Further trace is required.

Instrumented call boundary reported `Unable to cast Object to Instance`.
Generic Value::convert had displaced the recovered 0056f8c0 specialization;
its existing source now compiles in glue with an explicit declaration, and
Lua lookup returns the local Player. Bridge metatable checks also left eight
extra Lua stack entries on this path; the overlay now balances the stack.
`--p5-lua-object-check` exercises conversion, object identity and stack depth.
The original Animate script advances to the missing Climbing signal, so its
full functionality remains open.
