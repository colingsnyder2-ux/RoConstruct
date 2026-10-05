# RoConstruct

Standalone local reconstruction console for 2008 Roblox client behavior.

## Reconstruction Console

Colored Windows terminal lives at `scripts\re\roconstruct.py`. It shows local pipeline status, explains each stage, runs actions, and streams command output. First launch option `setup tools` can install Python, Ollama, and Visual Studio Build Tools through `winget` after confirmation. Ghidra and client samples remain local setup.

```powershell
py scripts\re\roconstruct.py
```

Build one portable Windows executable for a capable machine:

```powershell
powershell -ExecutionPolicy Bypass -File scripts\re\build.ps1
```

Output: `dist\RoConstruct.exe`. Keep EXE in checkout's `dist` folder so it finds pipeline scripts. Reverse-engineering data and client binaries stay local. Nothing uploads.

No-menu/headless status check:

```powershell
dist\RoConstruct.exe --headless
```

GUI uses compact dark neon controls: `Setup` → `Start server` → `Add jobs` → `Start worker`. `Refresh` shows queue, completed work, worker count, current job, speed, and errors.

## Distributed workers

Build GUI controller:

```powershell
powershell -ExecutionPolicy Bypass -File scripts\build_gui.ps1
```

Run `dist\RoConstruct-GUI.exe`, start coordinator, seed jobs, then start one worker per fast PC. Each worker needs the matching local client/database; coordinator receives only stable IDs, generated source, compiler logs, and evidence. Leases expire and retry. `scripts\roconstruct\coordinator.py` uses SQLite first; protocol is HTTP JSON, so Redis/PostgreSQL can replace storage later.

Workers may submit type/field proposals through coordinator. Every lease gets unique attempt ID, so stale workers cannot overwrite newer results. Heartbeats renew leases and expose current job/hardware metadata. Set `ROCONSTRUCT_TOKEN` and `ROCONSTRUCT_PROJECT` on coordinator and workers for token + project isolation.

Runtime/differential checks can report evidence through result payloads:

```json
{"kind":"runtime","value":"trace matched","score":3}
```

Compiler score is `1`; cross-function/field-offset/runtime evidence can raise ranking before promotion.

Compare reconstructed runtime traces:

```powershell
py scripts\roconstruct\differential.py expected.json actual.json
```

Promotion accepts compiler-clean jobs by default; use `--require-runtime` to require matching differential evidence.

Promote compiler-clean results into a reviewable branch:

```powershell
py scripts\roconstruct\promote.py --db coordinator.db --repo .
```

Client slots: `clients\README.md`. Do not publish proprietary Roblox client binaries in this repo.

Pipeline details: `scripts\re\README.md`. Working findings: `work\re\findings.md` (local, ignored).
