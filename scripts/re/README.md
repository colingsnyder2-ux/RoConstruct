# Local RE pipeline — 2008 Roblox client

Goal: decompile/understand `RobloxApp_client.exe` (2008M) fully on local hardware,
$0 API spend, frontier-model escalation only when local models get stuck.

```
work/re/bin/RobloxApp_client.exe (+ rgmain.dll)
        |  analyzeHeadless (scripts/re/start-re.ps1 -Headless)
        v
Ghidra 12.1.4  project: work/re/projects/Rbx2008M
  + GhidrAssist 12.1.4   (interactive LLM chat in GUI)
  + GhidraMCP   11.3.2   (HTTP :8080 -> OpenCode "ghidra" MCP tools, 27 fns)
  + pyghidra lib          (CPython3 drives export; Ghidra 12 blocks plain .py headless)
        |  python scripts/re/export_pyghidra.py   (pyghidra lib, CPython3)
        v
work/re/export/*.jsonl  (functions + call edges + full decompile)
        |  python scripts/re/summarize.py ingest
        v
work/re/rbx2008m.db  (SQLite: functions, edges, tier, summary)
        |  python scripts/re/summarize.py run
        v
tiered Ollama summaries:
  skip  -> thunk/lib/tiny          : never sent
  fast  -> qwen2.5-coder:7b        : small functions
  main  -> qwen2.5-coder:14b       : big / complex / net-relevant
  pending -> escalation queue      : opt-in cloud (--cloud + RE_CLOUD_URL/KEY)
```

## Quick start

```powershell
# 1. boot Ollama + Ghidra GUI (project preloaded)
powershell -File scripts\re\start-re.ps1

# 2. headless full pass: export JSONL, ingest, summarize (GUI must be closed)
powershell -File scripts\re\start-re.ps1 -Headless

# 3. inspect
python scripts\re\summarize.py stats
sqlite3 work\re\rbx2008m.db "SELECT name, addr, tier, substr(summary,1,100) FROM functions WHERE done=1 LIMIT 20"
```

Bounded batches: `python scripts\re\summarize.py run --limit 100`
Single tier only: `--only-tier main`

## Layout

| Path | What |
|---|---|
| `work/re/ghidra` | Ghidra 12.1.4 install (moved out of OneDrive) |
| `work/re/projects` | Ghidra project `Rbx2008M` |
| `work/re/bin` | extracted 2008M binaries |
| `work/re/export` | JSONL decompile dump |
| `work/re/rbx2008m.db` | functions/edges/tiers/summaries |
| `work/re/dl` | plugin zips (GhidrAssist/GhidraMCP sources) |
| `scripts/re/` | this pipeline (tracked in git) |

`work/*` is gitignored — binaries, project, DB stay local.

## OpenCode MCP

`~/.config/opencode/opencode.json` wires server `ghidra` ->
`bridge_mcp_ghidra.py --ghidra-server http://127.0.0.1:8080/`.
Requires Ghidra GUI running with GhidraMCP plugin enabled
(`File > Configure > Developer > GhidraMCPPlugin`). Port set in
`Edit > Tool Options > GhidraMCP HTTP Server` (default 8080).

## GhidrAssist one-time config (GUI)

`Edit > Tool Options > GhidrAssist`:

| Field | Value |
|---|---|
| Provider | OpenAI-compatible / Ollama |
| Base URL | `http://localhost:11434/v1` |
| API key  | `ollama` (any non-empty) |
| Chat model | `qwen2.5-coder:14b` |
| Embedding  | `nomic-embed-text` |

Models already pulled: `qwen2.5-coder:14b` (9G, partial GPU offload — RAM holds
the rest on the 8G 3070Ti), `qwen2.5-coder:7b-instruct` (4.4G, full GPU),
`nomic-embed-text`.

## Cloud escalation (optional, still pennies)

```powershell
$env:RE_CLOUD_URL = "https://api.openai.com/v1/chat/completions"
$env:RE_CLOUD_KEY  = "sk-..."
$env:RE_CLOUD_MODEL = "gpt-5.6-luna"    # $0.20/M in, $1.20/M out
python scripts\re\summarize.py cloud --limit 20
```

Only `tier='pending'` rows go there (local 14b returned empty twice).
At ~500 tokens in / 200 out per function: 1,000 hard functions ≈ $0.35 on Luna.

## Reconstruction track (`rebuild.py`) — building runnable source

The summarize track explains the client; this one *rebuilds* it. Technique is
compiler-in-the-loop (HELIOS / DecLLM, 2026): model writes C++, MSVC compiles
it, the compiler's errors go back to the model, repeat.

```
Ghidra decompile --(typelib.py)--> type names + field offsets
                          |
             (opaque.py)  v  shared type universe (4,664 typedefs)
  work/re/types/opaque.h          every class = `typedef void X`
                          |
Ghidra decompile --(rebuild.py)--> qwen2.5-coder:7b writes C++
                          |
                   cl /c /TP (VS 18, x86) --errors--> model (repair loop)
                          |
                     compiles=1  in rbx2008m.db `rebuild` table
```

### What the client actually is (this is why it's tractable)

`typelib.py` recovered **13,151 type names**. Composition:

| component | types | rebuild? |
|---|---|---|
| **Ogre 1.2 "Dagon"** 3D engine | 5,294 | no — open source |
| **RBX::** Roblox engine | 805 | **yes — the target** |
| **MFC** UI | 224 | no — ships with MSVC |
| ATL / G3D | 43 | no — open source / SDK |

`scope.py` tags all 53,002 functions by owning library: **2,678 RBX functions
(5.1%)** are ours; the rest is Ogre/MFC/ATL or unattributed. So the job is
"rebuild the RBX engine on top of real Ogre 1.2", not "rewrite a 3D engine".

### Commands

```powershell
# mine type names + field offsets from the corpus
python scripts\re\typelib.py universe      # 13,151 type names
python scripts\re\opaque.py build          # -> work/re/types/opaque.h

# tag function ownership, see the RBX queue
python scripts\re\scope.py queue
python scripts\re\scope.py stats

# reconstruct: seed the queue, then run the compiler loop
python scripts\re\seed.py                   # most-central RBX functions
python scripts\re\rebuild.py run --limit 20 --max-attempts 3 --model qwen2.5-coder:7b-instruct
python scripts\re\rebuild.py fixup         # re-verify stored code, no LLM
python scripts\re\rebuild.py stats

# honest measurement on the real queue
python scripts\re\bench.py --n 20 --max-attempts 2

# regression tests for the mechanical repairs (7 passes, ~1s)
python scripts\re\tests\test_repairs.py
```

### Mechanical repairs and the MSVC error each kills

| pass | error |
|---|---|
| `cxx_fix` | `this` is a C++ keyword (Ghidra emits it as a parameter) |
| `fix_thiscall` | C3865 `__thiscall` on a free function |
| `declare_namespaces` | C2653 `'RBX' is not a class or namespace name` |
| `add_base_types` | C4430 / C2065 missing `byte`/`dword`/`undefined4` |
| `add_windows_header` + `strip_win32_decls` | C2377 / C2556 Win32 duplicates |
| `add_opaque_universe` | C2440 class-pointer mismatch (the big one) |
| `add_seh_globals` + `fix_voidp_assignments` | C2440 in the MSVC exception dance |
| `add_allocator_ops` | C2440 / C2092 on operator new/delete |
| `normalize_symbols` | C2065 / C2040 one declaration per Ghidra symbol |
| `fix_missing_semis` | C2146 / C2143 missing `;` |
| `fix_typedefs` / `strip_bad_typedefs` | C2628 / C2632 `uint32_t bool` |
| `_trim_to_balance` | C1075 truncated function bodies |

`prepare()` recomputes all of these from the PRISTINE model output every pass,
so injected declarations can never accumulate.

## Analysis priorities (from project brief)

1. **Networking** — filter summaries `TAGS` containing `net`, start from
   `SELECT * FROM functions WHERE tier='main' AND summary LIKE '%net%'`.
   2008 client: RakNet-era packet code, `WSA*` imports, HTTP ticket login.
2. **Conflicting hypotheses** — record both in function comments via MCP
   `set_decompiler_comment`, keep `summary` as latest verified reading;
   resolve by xrefs (`get_function_xrefs`) + runtime logging in the emulator.
3. **Crashes** — reproductions from `work/emu-*.log`; locate faulting addr with
   `get_function_by_address`, read decompile, diff against reconstruction.
