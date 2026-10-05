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

Client slots: `clients\README.md`. Do not publish proprietary Roblox client binaries in this repo.

Pipeline details: `scripts\re\README.md`. Working findings: `work\re\findings.md` (local, ignored).
