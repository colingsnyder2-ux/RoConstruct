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

GUI main window stays simple: `Client setup`, `Server`, `Worker`, `Run demo`. Each opens its own focused window. Server window queues/refreshes jobs; worker window starts/stops processing; client window selects local DB/EXE. Progress bar shows completed/total work.

### Load 2008 data

Public repo intentionally contains no Roblox binary or private DB. Use authorized local files. Existing local 2008 data can be selected without copying:

```powershell
$env:ROCONSTRUCT_DATA_ROOT = 'C:\Users\colin\RBXBanland\work\re'
dist\RoConstruct-GUI.exe
```

Expected files:

```text
<DATA_ROOT>\rbx2008m.db
<DATA_ROOT>\bin\RobloxApp_client.exe
```

`rbx2008m.db` is created by Ghidra export + ingest. To create one from scratch, place authorized client/project under this checkout's `work\re` layout, then run `powershell -File scripts\re\start-re.ps1 -Headless`; this exports functions, ingests SQLite, and runs summaries. `ROCONSTRUCT_DATA_ROOT` is for reusing an already-built data folder. GUI `Check data` reports exact missing file and next action. Each worker needs matching local DB + client; coordinator never receives them.

### Public server list

Use separate, opt-in metadata directory. It stores server name, URL, description, project, and client label only—not binaries, DBs, pseudocode, or tokens:

```powershell
$env:ROCONSTRUCT_DIRECTORY_TOKEN = 'change-me'
py scripts\roconstruct\directory.py --host 0.0.0.0 --token $env:ROCONSTRUCT_DIRECTORY_TOKEN
$env:ROCONSTRUCT_DIRECTORY_URL = 'https://directory.example'
$env:ROCONSTRUCT_PUBLIC_URL = 'https://my-server.example:8765'
dist\RoConstruct-GUI.exe
```

GUI `Select DB...` and `Select client...` buttons set local paths and save them in ignored `roconstruct-settings.json`; they do not upload files. Click `Public list` to view live entries. Keep directory HTTPS/authenticated/rate-limited. Public discovery must never carry client files or DB uploads.

## Distributed workers

`Add jobs` may report `added 0`: stable function IDs already exist in coordinator DB. Not stall. `WORKING` means active processing, `WAITING` means queue exists but worker unavailable, `IDLE` means no queued work.

### Try without Roblox data

Run safe tiny C demo:

```powershell
py scripts\roconstruct\demo.py
```

It uses `examples\tiny_demo` and writes reconstructed files to `work\demo\reconstructed`. This tests queue/lease/result/evidence flow without Ghidra, Ollama, MSVC, or client binaries.

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

Playable-build roadmap: `docs\PLAYABLE.md`.

Automatic offline package assembly:

```powershell
py scripts\roconstruct\package.py
```

This copies reconstructed/demo source, checks open-source dependency folders,
writes `work\playable\build-report.json`, and never copies client binaries.

### Source-first mode

If authorized C/C++ source exists, use it directly—no Ghidra required:

```powershell
$env:ROCONSTRUCT_SOURCE_ROOT = 'C:\path\to\authorized\source'
py scripts\roconstruct\package.py
```

Ghidra is only needed for binary → decompiler export. Python GUI/worker EXE
users do not need Ghidra or a compiler after a package is already built; the
compiler/toolchain is needed only on build machines creating the executable.
