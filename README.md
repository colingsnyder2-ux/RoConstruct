# RoConstruct

Matching decompilation of old Roblox clients (2007–2010), done as a group.

**Progress:** https://colingsnyder2-ux.github.io/RoConstruct/

## Overview

The clients only exist as compiled x86 executables. Compilation throws away names, types and structure. Ordinary decompilers (Ghidra, Rev.ng) produce approximate C that can't be proven correct or rebuilt into the same program.

RoConstruct uses **matching decompilation**, the method behind the Super Mario 64 and Ocarina of Time reconstructions:

1. **Partition** the exe into functions (25k–37k per client) using control flow, base relocations and MSVC RTTI. Compiler-generated stubs are excluded.
2. **Hypothesize** C++ source for one function, written by a person, an LLM, or a pattern matcher for trivial cases.
3. **Compile** it with the *exact* original compiler, identified from the exe's Rich header.
4. **Verify** it byte for byte against the original, with linker-patched fields masked. Identical output is a **match**: the source is equivalent to what shipped. Otherwise the instruction diff shows what to fix.

When every function matches, the result is a source tree that rebuilds the original client.

**Why:** proper security patches for known exploits, WebAssembly and native ports (Linux, macOS), bug fixes, modding, and preservation.

**After 100%:** match the data sections, relink a byte-identical exe, name types and functions, replace third-party code (open-source Ogre, G3D, Lua, RakNet and boost with their real source; proprietary MFC, Codejock and FMOD with open alternatives), then build non-matching ports (Emscripten/WebGL, Linux, macOS).

## Quick start

1. Download this repo (Code → Download ZIP) and unzip it.
2. Double-click **`install.cmd`**. It installs Python 3.12, downloads and verifies the compilers, and enables one-click links. No admin rights needed.
3. Put your copy of the client in its folder, for example `clients\2008M\RobloxApp_client.exe`.
4. Click **"Help on 2008M"** on the progress site, or double-click **`roc.cmd`** for a menu.

The one-click link asks for a username once, sets up anything missing, keeps the PC awake, and runs a worker until you close the window. Leave it running overnight. Your matches show up on the leaderboard.

| You have | Do this |
|---|---|
| GPU with 8 GB+ | AI worker: install [Ollama](https://ollama.com), then `ollama pull qwen2.5-coder:7b`. Optional: [Docker](https://www.docker.com/products/docker-desktop/) + `docker pull revng/revng` for decompiler hints. |
| C++ knowledge | Match functions by hand (below). |
| An always-on PC | Host the server. |

## Commands

```
roc install                     download compilers, check tools, enable links
roc client list | add <n> <exe> clients you have / register a new one
roc analyze <client|all>        split an exe into functions
roc auto <client|all>           auto-match trivial functions (getters, setters, empty bodies)
roc next <client>               easiest open functions
roc claim <client> <addr>       start one: src/<client>/<addr>.cpp
roc check <client> [addr]       compile, score, show the asm diff
roc submit <client> [addr...]   send your sources to the server
roc flags <client>              infer compiler flags from matched code
roc config --user U --server S [--token T] [--public-server HOST:PORT]
roc worker [--jobs N] [--rounds N]
roc server [--port 8765] [--token T]
roc status                      progress, active workers, leaderboard
roc progress                    write the website data to docs/
roc link install | remove       roconstruct:// one-click links
```

## Matching by hand

`roc claim 2008M 006e5040` writes a file with the target assembly as comments:

```cpp
// 006e5040  8b81d0000000   mov eax, dword ptr [ecx + 0xd0]
// 006e5046  85c0           test eax, eax
// 006e5048  7404           je 0x6e504e
// 006e504a  8b4024         mov eax, dword ptr [eax + 0x24]
// 006e504d  c3             ret
// 006e504e  33c0           xor eax, eax
// 006e5050  c3             ret

struct Item { char pad[0x24]; int m_id; };
struct CXTPControls { char pad[0xd0]; Item* m_item; int GetId(); };

int CXTPControls::GetId()
{
    return m_item ? m_item->m_id : 0;
}
```

`roc check 2008M 006e5040` then prints `100%  MATCH`.

- `ecx` used before it's set means `this`.
- `ret N` means N bytes of arguments.
- `call dword ptr [...]` is an import: declare it `__declspec(dllimport)`.
- Addresses are masked, so names don't matter.
- Inline asm is rejected.

## Compilers

`roc install` fetches these into `tools/`. A download that fails its check is deleted.

| Client | Compiler | Source |
|---|---|---|
| 2008M, 2010L | VS2008 RTM 15.00.21022 | [VS2008 Express DVD (2007)](https://archive.org/details/VisualStudioExpressEditionsDVD2007), SHA-1 + Microsoft signature |
| 2009E | VS2008 SP1 15.00.30729 | [VCForPython27.msi](https://web.archive.org/web/20210106040224/https://download.microsoft.com/download/7/9/6/796EF2E4-801B-4FC4-AB28-B59FBF6D907B/VCForPython27.msi), Microsoft signature |
| 2007M | VS2005 14.00.50727 | [Visual C++ 2005 Express](https://archive.org/details/MS_VisualCPPExpress-2005), SHA-1 + Microsoft signature |

An existing Visual Studio 2005/2008 install is detected automatically; otherwise set `ROC_CL` to its `cl.exe` path.

## New client

`roc client add 2011E <path to RobloxApp_client.exe>` records the exe's hash and compiler and analyzes it. Commit `clients/clients.json` and restart the server.

## Hosting

```
roc server --token <password>
roc config --public-server your.host:8765
roc progress
```

After `roc progress`, commit and push `docs/`.

- Forward TCP 8765, or use Tailscale or ngrok.
- Back up `work/server.db`.
- Abandoned jobs free themselves after 15 minutes.
- If the server has the compilers and exes, it re-checks every submission.
- The site is served by GitHub Pages from `/docs`.

## Rules

- Never commit client exes, DLLs or game content. `.gitignore` blocks them.
- `src/` is git-ignored: matched source reproduces Roblox code and risks a takedown if published. The server keeps the sources.
- Only use client files you're allowed to have.

## Troubleshooting

| Message | Fix |
|---|---|
| `exe missing` / `hash mismatch` | Use the exact client build in `clients/<name>/`. |
| `Missing compiler` | `roc install` |
| `cannot reach server` | Check the address, port forwarding, and that the server is running. |
| `wrong or missing server password` | `roc config --token <password>` |
| `AI workers need Ollama` | Install Ollama, then `ollama pull qwen2.5-coder:7b`. |
| `needs Python 3.12 or older` | Run `install.cmd`, which installs 3.12. |
