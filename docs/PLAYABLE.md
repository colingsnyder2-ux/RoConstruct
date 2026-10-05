# From reconstructed functions to playable build

Function reconstruction is only one layer. A playable preservation build needs
all layers below, tested with software and client files you are authorized to
use.

## Build layers

If complete authorized source exists, skip binary analysis entirely: place it
under `source/` or set `ROCONSTRUCT_SOURCE_ROOT`, then package/build it. No
Ghidra is needed in that source-first path.

1. **Source set** — promoted C/C++ functions, shared headers, type universe,
   globals, startup code, and third-party dependencies.
2. **Executable** — x86-compatible build, linker map, resource files, DLLs,
   runtime libraries, and deterministic packaging.
3. **Client shell** — window/input loop, renderer, audio, filesystem paths,
   Lua/script runtime, asset loading, and crash logging.
4. **Protocol** — documented local/server message schema, login/session flow,
   replication, physics authority, and version checks.
5. **Server** — a small compatible test server first; never point an unknown
   reconstructed client at real services.
6. **Validation** — offline replay traces, golden screenshots, input tests,
   packet fixtures, and differential checks against authorized reference runs.

## Safe first playable milestone

Build an **offline sandbox**:

- launch reconstructed executable;
- load one local map and a few local assets;
- spawn one controllable character;
- move/camera/jump locally;
- run scripted NPCs;
- save a replay trace;
- no internet or account login.

Then add a localhost-only test server. Add real networking only after protocol
fixtures and version checks pass.

## RoConstruct promotion loop

```text
queued functions -> compiler-clean source -> evidence review
-> Git branch/PR -> linked executable -> offline replay tests
-> localhost server tests -> packaged preservation build
```

`promote.py` creates reviewable source branches. It does not claim full client
playability; missing symbols, assets, protocols, and runtime behavior remain
explicit blockers in the build report.

Use `py scripts\roconstruct\package.py` or GUI `Build sandbox` to assemble a
local package. It checks Ogre3D/SDL2/zlib/OpenAL Soft folders and reports what
must be built. It never bundles unknown `rg*.dll`, client binaries, or private
assets automatically.
