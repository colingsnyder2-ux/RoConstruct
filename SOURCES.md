# Sources

This file explains every source RoConstruct compiles to match functions in the Roblox
clients, what we still need and cannot find, and leads we checked and ruled out. The live
version is on the site: **[Sources page](https://colingsnyder2-ux.github.io/RoConstruct/sources.html)**.

## What "a source" means here

RoConstruct does **matching decompilation**. A function counts as matched only when C++
source, compiled with the *exact* original Microsoft compiler and flags, produces
**byte-identical** machine code to the client exe (relocations masked). So a "source" is
not documentation — it is real, compilable code that reproduces the bytes. Every match on
the progress page traces back to one of the sources below.

The clients and their compilers:

| Client | Build | Compiler |
|--------|-------|----------|
| 2007-03 | 0.3.368.0 | VS2005 SP1 (cl 14.00.50727) |
| 2007-08 | 0.3.x | VS2005 SP1 (cl 14.00.50727) |
| 2008-06 | | VS2008 RTM (cl 15.00.21022) |
| 2009-06 | | VS2008 SP1 (cl 15.00.30729) |
| 2010-06 | | VS2008 SP1 (cl 15.00.30729) |
| 2011-06 | | VS2008 RTM (cl 15.00.21022) |
| 2012-06 | | VS2008 SP1 (cl 15.00.30729) |

All recipes live in [`roc/libs.py`](roc/libs.py). Running them: `roc libs <recipe|all>`,
or `roc mass` for the full automatic pass (runtime tagging + STL + every library + auto shapes).

---

## 1. Roblox's own source — the biggest win

Real Roblox code. No library ships it; it only exists in a leak or a community
decompilation. This is what moves the needle, because the bulk of every client is
Roblox's own `RBX::` code.

### RBXGSdecomp
[RBLXDecomp/RBXGSdecomp](https://github.com/RBLXDecomp/RBXGSdecomp) is a matching
decompilation of **RBXGS 0.3.634.0 (Nov 2007)**, built with VS2005 SP1 — the same
compiler as the 2007 clients, and a build very close to 2007-03/2007-08. Because the
code is unchanged across nearby builds, the same source byte-matches functions in the
later clients too.

Cloned with submodules into `tools/rbxgs`. Five recipes split it by project:

- `rbxgs` — the App project: v8kernel, v8world, humanoid, reflection, script (~160 TUs)
- `rbxgs-net` — networking: Replicator, Player, Players, Server, Client
- `rbxgs-view` — RbxView: Part and the mesh classes
- `rbxgs-render` — RenderLib: Clusterer, RenderScene
- `rbxgs-g3d` — its patched G3D fork (the exact G3D RBXGS linked)

It compiles with the project's `ReleaseAssert` defines (`_RELEASEASSERT`,
`_VC80_UPGRADE=0x0710`, …). This one source round added roughly 10,000 matches across
the clients.

### 2016 leak forks
Roblox's own forks of several libraries, taken from the 2016 source tree in
`tools/roblox2016`: G3D 8.00, Lua 5.1.4, libjpeg, libpng, and RakNet. Recipes
`rbx2016-g3d`, `rbx2016-lua`, `rbx2016-jpeg`, `rbx2016-png`, `rbx2016-raknet`. The
RakNet fork needed a stub for Roblox's 2016 `FastLog.h` (the pre-2016 clients predate
it, so its log calls compile to nothing).

---

## 2. Open-source libraries

Third-party code statically linked into the clients. Each recipe pins the exact release
by SHA-256, preprocesses one self-contained translation unit (`cl /EP`), and compiles it
across a small flag grid (`/O2`, `/Ox`, `/O1` × `/Oy±` × `/Ob1|2`, with/without `/GS`)
until the bytes line up.

| Library | Versions | Notes |
|---------|----------|-------|
| zlib | 1.1.4, 1.2.3 | deflate/inflate |
| libjpeg | 6b | |
| libpng | 1.2.5 – 1.2.44 (16 swept) | kept whichever version matched |
| Lua | 5.1.0 – 5.1.4 | tried as both C and C++ |
| G3D | 6.09 source + 6.10 prebuilt VC8 `.lib` | float math built with `/arch:SSE2 /fp:fast` |
| boost | 1.34.1, 1.35, 1.36, 1.38, 1.40, 1.44, 1.47 | plus explicit template instantiations |
| RakNet | public 4.081 (few) + Roblox's fork | most matches come from the fork |
| SDL | 1.2.11 headers | the rest is in SDL.dll |
| Ogre | 1.7.0 "Cthugha" VC8 SDK | see note below |

**On `/GS`:** VS2005 defaults to `/GS` on. 830 functions in the 2007-08 exe carry the
stack-cookie prologue, so that client is compiled with `/GS` and existing matches pin
`/GS-` on their own `roc-flags` line.

**On Ogre:** the engine lives in `OgreMain.dll`, so only inline/template Ogre code is in
the exe. Worse, most of the exe's Ogre classes are Roblox's own `Ogre::Rbx*` subclasses
(RbxSceneManager, RbxEntity, RbxCluster…), whose source is not public. So Ogre is only a
partial source.

---

## 3. Compiler runtime & UI toolkits

Code the toolchain and the UI library compiled into the exe.

- **MFC** 8.0 (VS2005) and 9.0 (VS2008) — the static MFC that ships with each compiler.
- **Codejock XTP** 11.2.2 / 13.2.1 / 15.2.1 — the `CXTP*` UI classes, built on MFC.
- **STL templates** — explicit instantiations of `std::vector/list/map/set/string`… from
  the VC headers. Explicit instantiation emits every member, so one TU fingerprints a
  whole container family.
- **`libcmt` / `libcpmt`** (`msvc-crt` recipe) — **0 matches.** The clients link the DLL
  runtime (`/MD` → `msvcr80/90.dll`, `msvcp80/90.dll`), so the static CRT/STL objects are
  simply not in the exe. The CRT/STL code that *is* in the exe comes from header template
  instantiation, covered by the STL recipes above. This was tested directly against all
  three compiler builds — do not re-chase it.

---

## 4. Techniques (no external source)

- **cross-client copy** (`roc xcopy`) — every matched source is recompiled against every
  other client; functions byte-identical between clients, or duplicated inside one client,
  match for free. Runs after each library pass because it multiplies everything.
- **auto shapes** (`roc auto`) — trivial compiler-stereotyped functions (import thunks,
  forwarders, small accessors) matched from their normalized assembly shape.
- **AI workers** (`roc worker`) — a local code model drafts C++ for one function, compiles
  it, diffs the assembly, and retries, using a Rev.ng decompile hint and the matching 2016
  source for the function's class.

---

## 5. Needed, but not found

If you can find any of these, drop them in the [Discord](https://discord.gg/Tayg763nrG).

- **G3D 8.00 / 8.01 source.** The 2010–2012 clients link G3D 8.x. The official source zips
  were deleted from SourceForge and were never captured by the Wayback Machine or mirrored
  to GitHub (only the redirect pages survive). The 2016 leak has a partial copy (used), but
  a clean 8.00/8.01 tree would match more rendering code.
- **A client PDB or MAP file.** Symbols for any client exe would give exact function
  boundaries and real names — the single biggest multiplier for the AI workers and for unit
  assignment. None are known to exist: the RBXGS installers carry only `WebService.pdb` (the
  grid-service binary, not the client), and the only leaked Roblox PDB is from 2022.
- **Roblox's Ogre subclass source.** ~950 `Ogre::Rbx*` functions per late client. Ogre was
  dropped before the 2016 leak, so this source exists nowhere public.
- **Exact per-translation-unit compiler flags.** Roblox built different files with different
  optimisation settings. We sweep a grid; the real per-file flags (from a build log or the
  original project files) would catch the functions the grid misses.
- **A later matching decompilation.** RBXGSdecomp covers Nov 2007. A matching decomp of a
  2009–2012 build would supply RBX source for the newer clients, where the 2007 source has
  drifted.

---

## 6. Checked, not useful

Recorded so they are not chased again.

| Lead | Why not |
|------|---------|
| VS2005/2008 CRT ISOs | only provide static `libcmt`/`libcpmt` — 0 matches against `/MD` clients |
| [rccservice-decompile](https://github.com/verify-stack/rccservice-decompile) | RCCService is the server binary; it uses gSOAP, which the desktop clients do not link |
| ODE (Open Dynamics Engine) | not linked — no ODE RTTI classes or version strings; Roblox used its own physics |
| RomkoSI/G3D, elfprince13/G3D10 | both are G3D 10 (2016+), far past the 6.x–8.x the clients use |
| 2022 RobloxStudio PDB leak | right artifact, wrong era by a decade |
| OgreSDK VC8 prebuilt libs | the Ogre clients are VC9, and stock Ogre is in the DLL, not the exe |

---

## Adding a source

1. Add a recipe to `RECIPES` in [`roc/libs.py`](roc/libs.py): a URL + SHA-256 (or a local
   tree), the files to compile, the include dirs, and a flag grid.
2. Run it: `roc libs <name>` (or against one client: `roc libs <name> --client <name>`).
3. Matches are written to `src/<client>/<addr>.cpp` as compact `// roc-lib:` pointers and
   re-verified by `roc check`.
4. Re-run `roc xcopy` to spread the new matches across clients, then `roc progress` to
   update the site.
