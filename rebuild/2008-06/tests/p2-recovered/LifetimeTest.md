# P3 block lifetime controls

Run the recovered player with `--p3test` and an absolute path to
`tests/fixtures/lifetime-blocks.rbxl`, in a fresh writable output directory.
Original staged Content remains required beside the EXE. Clear ROC_BUILD and
developer texture/sky overrides for the direct acceptance process.

The versioned fixture has two anchored Parts: green Brick at(-2,0,0), size
2x1.2x2; red Other at(2,0,0), size1x2.4x1. The test uses the actual rebuilt Lua
script engine to resize, move and rotate Brick; reparent it into a Workspace
Model; detach/reattach it; insert and remove another Part; then remove Brick.
Other must retain its node, geometry, position, orientation, dimensions and
visible red-pixel count throughout. Resize/rotation are checked against model
values, not merely accepted script calls.

Two cycles close the place, collect resources, load an empty place, and reopen
the fixture in the same process. Mesh/material/texture manager counts and root
scene-node children return to their initial baselines. Draw entries, retained
mesh refs/levels/backends and sphere-cache entries must reach zero. This measures
those resources, not all process allocations. CSV and real GPU captures retain
each stage. An independent image audit must also compare red-mask positions,
the transformed green silhouette and visibility of the inserted Part.

This closes only the block lifetime subgate. Native non-box production and
silhouette comparison against the original client remain required for P3.

The native Part constructor004ebcc0 installs vtable00826f94. Slot10 points to
004ef930, whose ordinary no-special-shape branch at004f0038 reads Part shape
at+1dc. Shape0 reaches004f00a4 ->004eea30; this factory allocates0x8c at004eeb89
and calls004fcfb0 at004eebab. The existing recovered constructor source resolves
to roc_espeon_spheresurfacenative72a4ae64b6ab9c3d.cpp. Its padding declarations
are mining analogs, not accepted integration ABI. Original ctor calls Mesh
00548570, writes geometryKind2 at+84, creates a QUADS Level through004dd2e0,
and calls builder helpers00500d80/00500d30. Next recover the genuine builder
members and subtype/cache ownership before integrating this ball path.
