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
