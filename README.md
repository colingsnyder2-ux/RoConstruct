<p align="center">
  <img src="docs/logo.png" alt="RoConstruct" width="560">
</p>

<p align="center">
  <b>Rebuilding classic Roblox clients (2007–2012) as real C++ source, together.</b><br>
  <a href="https://colingsnyder2-ux.github.io/RoConstruct/">Progress site</a> ·
  <a href="https://discord.gg/Tayg763nrG">Discord</a> ·
  <a href="#get-started">Get started</a>
</p>

---

## What is this?

The old Roblox clients only survive as compiled `.exe` files. Compiling throws away names, types and structure, so normal decompilers only give approximate code that can't be rebuilt into the same program.

RoConstruct uses **matching decompilation**, the method behind the Super Mario 64 and Ocarina of Time projects:

| Step | What happens |
|---|---|
| 1. Split | The exe is cut into functions (20k–40k per client). Compiler-generated stubs are skipped. |
| 2. Guess | Someone writes C++ for one function: a person, an AI worker, or the pattern matcher. |
| 3. Compile | The guess is built with the **exact** compiler Roblox used (detected from the exe). |
| 4. Compare | The result is checked byte for byte. Identical means **matched**: the source provably equals what shipped. Otherwise the diff shows what to fix. |

When every function matches, the result is a source tree that rebuilds the original client. That opens the door to:

- **Security fixes** for known exploits
- **Ports:** a browser version via WebAssembly, plus Linux and macOS
- **Bug fixes, modding and preservation**

## Get started

1. **Download** this repo (Code → Download ZIP) and unzip it.
2. Double-click **`install.cmd`**. It installs Python and the old compilers (each one verified) and enables one-click links. No admin rights needed.
3. On the [progress site](https://colingsnyder2-ux.github.io/RoConstruct/), click **Start helping** on a client.

You don't need to download any clients yourself. Whatever you pick — a one-click link, `roc analyze`, `roc next`, or the worker — fetches that client from Google Drive first, then checks its SHA-256 against the registered build before using it. If a file goes missing you get the same treatment: it re-downloads on the next command. To fetch up front instead, run `roc client-fetch all`.

The first click asks for a username. After that it runs on its own: leave the window open overnight, and your matches show up on the leaderboard.

> **Heads up:** a worker runs an AI model and the compiler nonstop. Expect high GPU/CPU use, fan noise and power draw (laptops: plug in). Close the window to stop.

To undo the install later, double-click **`uninstall.cmd`**. It lists everything first with sizes, then asks before each step. RoConstruct's own files default to yes (about 3.2 GB of compilers and caches); shared software defaults to no. Your other Ollama models are never touched — only the coder models this project uses are offered.

### Ways to help

| You have | Do this |
|---|---|
| A GPU with 8 GB+ | Run an **AI worker**: install [Ollama](https://ollama.com), then `ollama pull qwen2.5-coder:7b`, then click Start helping. `roc model` shows installed models; `roc model <name>` picks yours; `roc model default` restores automatic choice. Optional: [Docker](https://www.docker.com/products/docker-desktop/) + `docker pull revng/revng` for extra decompiler hints. |
| C++ knowledge | **Match by hand**: see below. |
| A PC that's always on | **Host the server**: see below. |

Double-click **`roc.cmd`** for a menu with everything.

### Getting matches without writing any C++

Most functions are not worth hand-writing, because the code is either public or machine-generated. Three commands cover those, and they compose:

| Command | What it does |
|---|---|
| **Library matching** | Compiles zlib, libjpeg, Lua, RakNet 3.0 and the rest from their real source with the client's own compiler, then matches by fingerprint. RakNet 3.0 targets the early RBXGS clients; later clients use their newer fork. Matched code carries `// roc-lang` / `// roc-flags` / `// roc-cl` lines so anyone re-checks it with the settings that matched. |
| **`roc xcopy <client\|all>`** | The clients share code: a function that is byte-identical in two exes is the same function. This takes every stored match and tries it against every other client's open functions. It only runs where the compiler can reproduce the same bytes, so it works within a compiler group (2008-06↔2011-06, or 2009/2010/2012-06). Re-run it whenever new matches land — every new match is a candidate everywhere else. |
| **`roc shapes <client\|all>`** | Counts the assembly shapes of what's still unmatched, with addresses and immediates generalised away, so the next pattern template is chosen from counts instead of guesses. |

Nothing above can record a wrong match: a result counts only when it is byte-identical, so a bad guess costs compile time and nothing else.

### Recovered findings

The recovered per-client function outputs are published separately, so normal
RoConstruct clones stay small. Browse [RoConstruct-findings](https://github.com/colingsnyder2-ux/RoConstruct-findings), or download only the recovered `src/` as the [latest ZIP](https://github.com/colingsnyder2-ux/RoConstruct-findings/releases/download/findings-latest/roconstruct-findings-src.zip).

## Reference

**[SOURCES.md](SOURCES.md)** — every source we compile to match functions, what we still need and cannot find, and leads we ruled out. ([live page](https://colingsnyder2-ux.github.io/RoConstruct/sources.html))

<details>
<summary><b>Matching by hand</b></summary>

`roc claim 2008-06 006e5040` writes a file with the target assembly as comments. Write C++ under it:

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

`roc check 2008-06 006e5040` prints `100%  MATCH`, or a diff showing what's different. When done, `roc submit 2008-06`.

Tips:
- `ecx` used before it's set means `this`, so write a member function.
- `ret N` means the function takes N bytes of arguments.
- `call dword ptr [...]` is an imported function: declare it `__declspec(dllimport)`.
- Addresses are ignored, so names don't matter.
- Inline asm is rejected.
- Strings and constants your source defines are checked too. Wrong data scores 99%.

Find easy targets with `roc next 2008-06`, and get everyone else's work with `roc pull 2008-06`.
</details>

<details>
<summary><b>All commands</b></summary>

```
roc install                     download compilers, check tools, enable links
roc client list | verify        your clients, and whether they're the right builds
roc client add <name> <exe>     register a new client
roc client remove <name>        unregister a client (--purge deletes its local copies)
roc client-fetch <name|all>     download a client and verify it (happens automatically)
roc client-sources <folder>     index a Drive folder as a fetch fallback
roc analyze <client|all>        split an exe into functions
roc auto <client|all>           auto-match trivial functions
roc shapes <client|all>         count unmatched assembly shapes (picks the next templates)
roc xcopy <client|all>          copy every match to the other clients that share the function
roc next <client>               easiest open functions
roc claim <client> <addr>       start a function: src/<client>/<addr>.cpp
roc check <client> [addr]       compile, score, show the diff
roc submit <client> [addr...]   send your sources to the server
roc pull <client|all> [--force] download everyone's sources
roc flags <client>              work out compiler flags from matched code
roc config --user U --server S  save your settings
roc model [name|default]         show or choose AI model
roc worker [--jobs N]           run an AI worker (`--workers N` for bounded parallel loops)
roc worker --dry-run             check worker setup without taking a job
roc worker --workers 2           run bounded parallel lease loops (1-8, or auto)
roc worker --preset fast|deep    choose speed or source-heavy mode
roc worker --source-only         run deterministic candidates only
roc doctor                       check compilers, Ollama, Docker, clients
roc model-stats                  compare models from worker telemetry
roc benchmark-models             create fixed targets + compare telemetry
roc benchmark-models --local-run --full --resume
                                 resumable full local model comparison
roc benchmark-models --progress  show saved benchmark records only
roc failures                     show recurring worker failures
roc source-status                show 2016 source-name coverage
roc server [--publish] [--startup] [--tunnel]   host the group server
roc status                      progress, active workers, leaderboard
roc progress                    rebuild the website data in docs/
roc link install | remove       one-click links on/off
```
</details>

<details>
<summary><b>Compilers</b></summary>

`roc install` downloads these into `tools/`. Each download is checked against a Microsoft signature or a known hash, and deleted if the check fails.

| Clients | Compiler | Source |
|---|---|---|
| 2008, 2011 | VS2008 RTM 15.00.21022 | [VS2008 Express DVD (2007)](https://archive.org/details/VisualStudioExpressEditionsDVD2007) |
| 2009, 2010, 2012 | VS2008 SP1 15.00.30729 | [VCForPython27.msi](https://web.archive.org/web/20210106040224/https://download.microsoft.com/download/7/9/6/796EF2E4-801B-4FC4-AB28-B59FBF6D907B/VCForPython27.msi) |
| 2007 | VS2005 14.00.50727 | [Visual C++ 2005 Express](https://archive.org/details/MS_VisualCPPExpress-2005) |

An existing Visual Studio 2005/2008 install is found automatically. Otherwise, set `ROC_CL` to the `cl.exe` path.
</details>

<details>
<summary><b>Hosting the server</b></summary>

Double-click **`host.cmd`** on a PC that stays on.
- It runs the server and updates and pushes the website every hour.
- `roc server --startup` makes it start at login.

To give it a public address:
1. Install [Tailscale](https://tailscale.com).
2. Run `tailscale funnel --bg 8765` and approve the link it prints.
3. Save the address: `roc config --public-server https://<pc>.<tailnet>.ts.net`.

Without a saved address, `--tunnel` uses a temporary Cloudflare address instead. The site and workers follow it automatically when it changes.

The server re-checks every submission with the real compiler and exe, so scores can't be faked. Back up `work/server.db`.

Workers try deterministic candidates and matching 2016 library source first, then retrieve related
source names/snippets and nearby matched examples before asking Ollama. Per-job telemetry is appended to
`work/worker-metrics.jsonl`; session summaries show matches, improvements, source guidance, and
average job time.

`roc benchmark-models --generate` creates repeatable tiny/medium/large targets. Add `--run` with
saved server/user settings to run installed code models against those targets.
`roc benchmark-models --hidden` creates a source/score-hidden regression corpus.
`roc benchmark-models --local-run --limit 1` compares two installed coder models locally without server submission.
The saved hidden-corpus baseline is in `work/benchmark-baseline.json`; use `--baseline` after a
sample or full run to compare score gain and match rate before changing worker speed settings.

One-click worker links ask each time for model, preset, worker count, and Rev.ng. Press Enter to
keep the shown defaults.

Speed checklist: `docs/worker-speed-checklist.md`.

Full implementation checklist: `docs/worker-checklist.md`.
Line-by-line source-plan audit: `docs/worker-full-plan-checklist.md`.
</details>

<details>
<summary><b>Adding a new client</b></summary>

`roc client add 2013-01 <path to RobloxApp.exe>` records the exe's hash, build date and compiler, then analyzes it. Patched or modded exes are refused: their PE checksum doesn't match. Commit `clients/clients.json` and restart the server.
</details>

<details>
<summary><b>After 100%</b></summary>

The remaining steps:
1. Match the data sections.
2. Relink a byte-identical exe.
3. Name the types and functions.
4. Swap third-party code for its real source. The open-source parts are Ogre, G3D, Lua, RakNet and boost. MFC, Codejock and FMOD get open alternatives.
5. Build ports: WebAssembly/WebGL, Linux and macOS.
</details>

<details>
<summary><b>Troubleshooting</b></summary>

| Message | Fix |
|---|---|
| `exe missing` | It should download itself. If it didn't, run `roc client-fetch <name>`. |
| `hash mismatch` | Wrong build on disk. `roc client remove <name> --purge`, then run the command again to re-download. |
| `looks modified` | That exe was patched; get an unmodified copy. |
| `Missing compiler` | Run `roc install` (re-running resumes downloads). |
| `cannot reach server` | The server may be offline; workers retry automatically. |
| `AI workers need Ollama` | Install Ollama, then `ollama pull qwen2.5-coder:7b`; check with `roc doctor`. |
</details>

## Rules

- **Never commit or share Roblox client files.** Everyone brings their own copy.
- `src/` (matched sources) stays out of git: publishing Roblox code risks a takedown. The server keeps the sources.
- Be friendly. Join us on [Discord](https://discord.gg/Tayg763nrG).
