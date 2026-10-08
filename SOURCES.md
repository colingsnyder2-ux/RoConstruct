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
| 2009-12 | Releases/2009.12.14 | VS2008 SP1 (cl 15.00.30729) |
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
| Lua | 5.0–5.0.3, 5.1.0 – 5.1.4 | Lua 5.0 is named in the 2009 client `copyrights.txt`; all official 5.0 point releases are queued as C. 5.0 archive SHA-256 `4a23b3bcb812538c653033cd39fe9c9bd8030286b945c56eff280d452e4e244e`. |
| G3D | 6.09 source (rbxgs-g3d) + Roblox 2016 fork (rbx2016-g3d) | float math `/arch:SSE2 /fp:fast`. G3D version by client: 2007-08 = 6.x (VARArea only); 2009–2010 = 7.x (VARArea + VertexBuffer coexist); 2011–2012 = 8.x (VertexBuffer only, VARArea gone). All clients embed `G3Dcpp/`/`glg3dcpp/` source paths — Roblox's fork predates the 8.x reorganization to `G3D.lib/source/`. 6.10 prebuilt VC8 `.lib` no longer used (replaced by rbx2016-g3d). |
| boost | 1.34.1, 1.35–1.40, 1.44, 1.47 | plus explicit template instantiations; 1.37 and 1.39 pending ROC run |
| RakNet | public 4.081 (few) + Roblox's fork | most matches come from the fork |
| SDL | 1.2.11 headers | the rest is in SDL.dll |
| Ogre | 1.4.9, 1.6.4, 1.7.0 "Cthugha" VC8 SDK | 2009-06 plugin PDB paths name exact 1.4.9 (verified: all five Ogre DLLs embed `C:\Users\ncoder\roblox\Trunk\Client\Rendering\ogre-v1-4-9\lib\*.pdb`, age=1); 2009-06 imports the DLL as `rgmain.dll` (Roblox's renamed OgreMain). 2009-12 OgreMain.dll already uses 1.6.4 (`d:\Roblox\Releases\2009.12.14\Client\Rendering\ogre-v1-6-4\lib\OgreMain.pdb`); 2009-12+ imports standard `ogremain.dll`. 2010–2012 also 1.6.4. Transition 1.4.9→1.6.4 + rename rgmain→ogremain happened between June and December 2009. Recipes use their VC project flags. See note below. |
| LAME | 3.98.4, 3.99.5 | `lame-3.98.4` / `lame-3.99.5`; named in 2011-06 and 2012-06 `copyrights.txt` ("This program uses Lame"); no `lame.dll` import → statically linked. vc9_libmp3lame.vcproj Release: `/Ox /Ob2 /Ot /MD`. configMS.h provides the Windows `config.h`. New recipe added 2026-10-07; pending ROC run. |
| Scintilla MFC wrapper | PJ Naughter v1.20 | `scintilla-mfc-1.20` / `scintilla-mfc-1.20-vc8`; source synced to Scintilla 1.76, exact DLL version beside 2009 client. Local-only due source redistribution terms; provenance: TeXnicCenter commit `881e059d254b2cb921c0d239b5be16d97ad317ce`. Pending ROC run. |
| Wild Magic | Magic Software Wild Magic 2, 2003 | `wildmagic-2-core`; named in 2009 `copyrights.txt`. Local-only: its non-transferable license prohibits source redistribution. Source: `argapratama/kucgbowling` commit `65e40b6f33c5511bddf0fa350c1eefc647ace48a`, `Term/WildMagic2/Source`; VC7 project builds a static `/MT` library. License PDF SHA-256: `e9d9342ac59f43947aac782ac3b21dc8f0a533251c938cea15bb1146430e1192`. Pending ROC run. |

**On `/GS`:** VS2005 defaults to `/GS` on. 830 functions in the 2007-08 exe carry the
stack-cookie prologue, so that client is compiled with `/GS` and existing matches pin
`/GS-` on their own `roc-flags` line.

**On Ogre:** the engine lives in `OgreMain.dll`, so only inline/template Ogre code is in
the exe. Worse, most of the exe's Ogre classes are Roblox's own `Ogre::Rbx*` subclasses
(RbxSceneManager, RbxEntity, RbxCluster…), whose source is not public. So Ogre is only a
partial source.

**Ogre 1.4.9 PDB evidence (2009 client, verified 2026-10-07):** all five Ogre DLLs shipped
with the 2009 client embed CodeView RSDS records pointing to the same Roblox build machine:

| DLL | RSDS GUID | age | PDB path |
|-----|-----------|-----|---------|
| `Plugin_CgProgramManager.dll` | `28849752fcf19f44bb95c761ac217485` | 1 | `C:\Users\ncoder\roblox\Trunk\Client\Rendering\ogre-v1-4-9\lib\Plugin_CgProgramManager.pdb` |
| `rgpar.dll` | `e811acb2909acb45be3a8e93f98e3e36` | 1 | `C:\Users\ncoder\roblox\Trunk\Client\Rendering\ogre-v1-4-9\lib\rgpar.pdb` |
| `rgdx.dll` | `6431084fee279740b530e719be878b52` | 1 | `C:\Users\ncoder\roblox\Trunk\Client\Rendering\ogre-v1-4-9\lib\rgdx.pdb` |
| `rggl.dll` | `763812a8aa13dc4f8b193045ac00f15b` | 1 | `C:\Users\ncoder\roblox\Trunk\Client\Rendering\ogre-v1-4-9\lib\rggl.pdb` |
| `rgmain.dll` | `b1679eda89276b48ad26e62e078295c1` | 1 | `C:\Users\ncoder\roblox\Trunk\Client\Rendering\ogre-v1-4-9\lib\rgmain.pdb` |

The path `Rendering\ogre-v1-4-9` confirms the exact release as a directory-named drop
(matching the 1.6.4 pattern `Rendering\ogre-v1-6-4` in the 2010 client). The `ncoder`
username is the Roblox developer who built the 2009 client. No corresponding PDB was found
on the Microsoft symbol server (same GUID+age search returned 404 for all five).

---

## 3. Compiler runtime & UI toolkits

ATL source ships alongside the existing local MFC 8.0/9.0 source trees. The clients contain
named `ATL::CRegObject` functions, so `atl-8.0` and `atl-9.0` compile its four ATL translation
units with the matching VS2005/VS2008 headers. Pending ROC run.

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

- **G3D 7.x / 8.01 source.** The 2009-06/2009-12/2010-06 clients link G3D 7.x (both
  `VARArea` and `VertexBuffer` present — the transitional era where both names coexisted);
  the 2011-06/2012-06 clients link G3D 8.x (`VARArea` removed, `VertexBuffer` only). All
  clients embed source paths under `G3Dcpp/`/`glg3dcpp/` (the G3D 6.x/7.x layout), so
  Roblox's fork branched before the G3D 8.x reorganization into `G3D.lib/source/`. The
  official G3D 8.01-src.zip was deleted from SourceForge (only version 10.00 remains); G3D
  7.x source is also gone. The 2016 Roblox leak contains a partial fork (recipe
  `rbx2016-g3d`), but clean G3D 7.x or 8.01 source would match more rendering code.
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

## Hard limits

Functions that cannot be matched no matter what source we find.

- **VMProtect.** The later clients import `vmprotectsdk32.dll` and virtualize selected
  anti-tamper functions. Virtualized code is a VM bytecode blob, not real x86 — no C++
  source reproduces its bytes, so those functions are permanently unmatchable. It is a
  small set (license / integrity checks), not the bulk.

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
| Microsoft symbol server PDB probe (2026-10-07) | 2007-03, 2009-06, 2011-06 and 2012-06 embedded CodeView GUID+age paths all returned HTTP 404; no public Microsoft-symbol copy |

---

## Adding a source

1. Add a recipe to `RECIPES` in [`roc/libs.py`](roc/libs.py): a URL + SHA-256 (or a local
   tree), the files to compile, the include dirs, and a flag grid.
2. Run it: `roc libs <name>` (or against one client: `roc libs <name> --client <name>`).
3. Matches are written to `src/<client>/<addr>.cpp` as compact `// roc-lib:` pointers and
   re-verified by `roc check`.
4. Re-run `roc xcopy` to spread the new matches across clients, then `roc progress` to
   update the site.
