# P5 anchor transition trace

Original target executable, address-based evidence:

- `005e8050`, `005e80d0`, `005e8140` update the respective Primitive bytes
  at `+a8`, `+a9`, `+aa`, calling the world only when their aggregate OR changes.
- Original `005e94a0` / `005e94e0` find pipeline stage type 2, then call
  `0064cc40` / `0064ccf0`. Those replace the previous joint with an allocated
  0x88-byte joint. RTTI at vtables `0084b0cc` and `0084b10c` identifies
  `RBX::AnchorJoint` and `RBX::FreeJoint`, respectively.
- The server source lookup for both stage addresses points to existing
  `tools/openrbx/Client/App/v8world/ClumpStage2.cpp`; its corresponding methods
  select the old opposite-type joint, create the new one, insert it downstream,
  then remove the old edge. This donor path has a different stage/joint ABI from
  the currently linked older rbxgs `ClumpStage` and is not yet integrated.
- Current rebuild still uses `glue_anchor_registry.cpp` and the old Anchor path.
  Runtime success is evidence for the shim only, not native AnchorJoint parity.
  Before replacing it, recover the target joint constructors, pipeline/edge
  layouts and dependent stages; do not mix the two object models or fabricate
  padding/vtables.
