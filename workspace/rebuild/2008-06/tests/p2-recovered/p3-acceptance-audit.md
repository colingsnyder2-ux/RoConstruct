# P3 acceptance audit

**PASSED** on canonical player source `0dcbf70f18`. This closes the roadmap's
many-Part/lifetime/one-non-box gate, not the complete original renderer/client.

| Requirement | Evidence |
|---|---|
| Two differently sized/colored Parts; load enumeration | `lifetime-shapes.rbxl`: green2x1.2x2 block and red2x2x2 ball. Normal `--p3test` starts with2 scene models/draw entries, both visibly rendered. |
| Property changes, rotation and resize | Actual Lua engine changes Brick size3x1.2x1, position(-2,.5,0), rotation0.6rad aboutZ. Model values asserted and captured silhouette changes. |
| Reparent, detach/reattach, insertion/removal | Two cycles each record `2→2→2→1→2→3→2→1` models. New Part contributes1314 foreground pixels; removal restores the preceding exact frame. |
| Other Part stationary and visible | Retains its node, geometry, size, position and orientation. Independent image audit verifies exact right-half foreground-mask identity across all16 stages. Color counts stay recorded separately. |
| Second place, reopening, repeated cycle | Each cycle loads an empty place in the same process, then reopens the two-Part fixture. Empty captures contain neither Part. |
| Stale chunks/resources released | Draw entries, levels, vertex-bank refs, backend meshes, sphere bounds-cache entries reach0. Mesh/material/texture/root-node baselines return to3/3/0/0. This does not claim all heap allocations freed. |
| Native non-box production/ownership | Sphere unit checks294 vertices/864 retained quad indices/1296 GPU indices, unit normals, component radius scaling, native flat UV,32 lifetimes, shared cache reuse and100-creation purge. Hardware trace proves same rebuilt sphere Mesh→Level→SubMesh→SubEntity actual render operation→entity destruction. |
| Original-client silhouette | Unmodified target SHA2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764 opens versioned `sphere-reference.rbxl`. Camera is serialized at(0,0,10), identity rotation, focus(0,0,0). Normalized silhouette IoU0.98403556 passes fixed0.98 gate. Box control0.79270935 fails0.9 maximum. |
| Existing block rendering preserved | Same-source normal selftest/cachetest pass; original P2 hardware identity/removal trace passes. Standalone block-factory regression also passes with the unchanged shared mesh source. |

Authoritative receipts under `work/2008-06/`:

- `p3-mixed-lifetime-0dcbf70f18/receipt.json`
- `p3-sphere-final-0dcbf70f18/receipt.json`
- `p3-aligned-player-0dcbf70f18/receipt.json` and `comparison.json`
- `p3-reference-proof-0dcbf70f18/`: original captures, executable/DLL/fixture hashes,
  original process command and unaligned-control failure.
- `p2-flat-producer/p3-sphere-block-final-trace-0dcbf70f18/receipt.json`

The first mixed test used a color threshold as stationary oracle and failed when
one specular pixel crossed it after scene bounds changed. The corrected test
checks the exact geometric foreground mask; color counts remain visible in CSV.
The first original capture used Zoom Extents and a different camera orientation;
IoU0.97932256 failed the same0.98 threshold. A versioned Camera reference aligned
the view; the threshold was retained. Original screenshot is helper JPEG, player
capture is actual D3D9 backbuffer PNG. Crop/scale normalization compensates
viewport/FOV differences; RGB/lighting/UI parity is not claimed.

Tracked limits: null native texture context uses explicit harness mipmaps/AA0
settings; full context remains P6/native-integration work. Non-box decal/texture
factory paths, other shapes, modifiers/aggregation, full native scene and unused
shadow/animation branches remain separately open. Original period assets are
external; exact June distribution identity remains unproven. Original reference
UI close did not complete through the helper; owned test process was terminated,
so clean original shutdown is not credited. Rebuilt processes exit cleanly.

P0/P2 earlier scoped gates remain preserved. Next roadmap milestone is P4:
ordinary disk places, parent/child references, local texture/mesh and supported
sound, observed missing-asset behavior, and reference object/material checks.
