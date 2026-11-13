# Archived 2008-06 rebuild paths (2026-11-09)

Moved here (git mv, history kept; uncommitted edits travelled with the files) because they are not part
of the native-only 2008 client:

- `p6/` — the P6 "fake shell": `RobloxShell.cpp`, `P6Engine.*`, `P6Data.cpp`, `build_client.py` and its
  probe/gate scripts. The `--native-doc` build still compiled `RobloxShell.cpp` and `P6Engine.cpp`.
- `modules/p2-*`, `p3-*`, `p4-*`, `player*.json` and `tests/P2*`, `P3*`, `P4*`, `Player*`, `p2-recovered/` —
  the P2 player harness (Player2008, bevelled block meshes) and its P3/P4 mesh/sound test modules.
  `roc rebuild 2008-06 player` no longer has a module to build.
- `tests/m4_render.cpp` and `glue/glue_render_m4b.cpp` — milestone M4b only checked that the centre pixel
  was not the magenta clear colour, while the glue left the renderer empty (no scene registration, empty
  BrickMesh, no-op prerender). A white frame passed it. Removed from `roc/rebuild.py` MILESTONES.
- `modules/rbx-app.json`, `glue/openrbx/` — the OpenRBX+rbxgs hybrid App build (mixed headers, missing
  lua/rbx-util/raknet deps, 325 unresolved). `rbxgs-app` builds the same engine and links.

Several `rebuild/2008-06/tests/compare_p4_*` / `compare_p5_*` analysis scripts still reference the player
and will fail if run.
