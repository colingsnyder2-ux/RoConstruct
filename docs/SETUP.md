# Setup and use

Everything runs from one launcher: `roc.cmd` on Windows, `./roc.sh` on Linux. With no
arguments it opens a menu; `roc --help` lists every command, grouped.

## Install

**Windows.** Download the repo (Code → Download ZIP), unzip it, double-click
`install.cmd`. It checks Python 3.12 (installs it with winget if missing), installs
`pefile`, `capstone` and `tzdata`, downloads the exact MSVC compiler bundles, registers
`roconstruct://` links and runs `roc doctor`. It prints download sizes first, needs no
admin rights, and installs no Ollama, Docker or model. Running it again is safe:
downloads resume and `work/`, `src/` and settings are never touched. `roc.cmd` runs it
automatically the first time if setup is missing. The VS2005 and VS2008 RTM bundles
need 7-Zip (`winget install --id 7zip.7zip -e`).

**Linux.** Install Python 3.12+, Wine (`wine wine32` on Debian/Ubuntu) and `cabextract`
or `7z`, then run `./install.sh`. Packages go into a private venv at `tools/venv`;
`./roc.sh` uses it automatically. The old `cl.exe` runs under Wine with a private prefix
in `tools/wineprefix` (your `~/.wine` is untouched). For an emulated Wine loader, set
`ROC_WINE` to its path. `roconstruct://` links and the winget Ollama install are
Windows-only. Linux support adapted from
[brambora69123's fork](https://github.com/brambora69123/RoConstruct).

**Compilers** (`roc install`, checked against a Microsoft signature or known hash):

| Clients | Compiler | Source |
|---|---|---|
| 2008, 2011 | VS2008 RTM 15.00.21022 | [VS2008 Express DVD](https://archive.org/details/VisualStudioExpressEditionsDVD2007) |
| 2009, 2010, 2012 | VS2008 SP1 15.00.30729 | [VCForPython27.msi](https://web.archive.org/web/20210106040224/https://download.microsoft.com/download/7/9/6/796EF2E4-801B-4FC4-AB28-B59FBF6D907B/VCForPython27.msi) |
| 2007 | VS2005 14.00.50727 | [Visual C++ 2005 Express](https://archive.org/details/MS_VisualCPPExpress-2005) |

An existing VS2005/2008 install is found automatically; `ROC_CL` can point at a `cl.exe`.

**Update and uninstall.** `roc update` fast-forwards a git checkout (a ZIP download is
linked to the repository first) and never touches local edits, clients, work, models or
settings. `roc uninstall` lists everything with sizes and asks before each step.

## Start a worker

For a coding-agent-driven session, use [Matching agent](MATCHING_AGENT.md) for
source mining or [Native agent](NATIVE_AGENT.md) for native integration. Both guides
bootstrap a verified Worker download and install missing dependencies when authorized.

Click **Help out** on a client at the
[website](https://colingsnyder2-ux.github.io/RoConstruct/), or run `roc launch`. It asks:
cloud or local model, which model, worker mode (Recommended / Fast / Deep / Advanced /
Optimize), how many workers, and whether to edit advanced options. It then downloads the
client and its compiler if needed, analyzes the binary and runs. Close the window to stop.

Clients download themselves from Google Drive (fallback: `clients.zip`) and are used only
after their SHA-256 matches `clients/clients.json`. `roc client-fetch all` fetches all up
front; `roc client verify` checks a copy you supply at `clients/<name>/<exe>`. Patched exes
are refused (PE checksum). Never commit or share client files.

## Models

| Option | How |
|---|---|
| Cloud API key | `roc provider setup` saves a key (DeepSeek, OpenAI, Anthropic, Gemini, NVIDIA) in a user-local secrets file outside the repo; `roc provider secrets --open` edits it; `roc provider test NAME --model M` sends a two-word probe. Custom providers: `docs/providers.example.json`. |
| ChatGPT plan | `roc chatgpt login` (installs its sign-in packages on first use), pick a model, then `roc launch`. Plus/Pro limits are shared with your other ChatGPT apps; set the app limit at [ChatGPT Settings → Usage](https://chatgpt.com/settings/usage). Tokens are encrypted, the key is held by the OS keyring (Linux: Secret Service or KWallet). `roc chatgpt status`, `models`, `use ID`, `logout`. RoConstruct never falls back to an API key, and a USD cap is rejected for this provider. |
| OpenCode CLI | No key: Match and Agent modes run through the signed-in OpenCode CLI. `npm i -g opencode-ai`, then `opencode auth login`; the dashboard's Install / sign in button does the same. Pick `opencode:…` models from the Match dropdown (or the OpenCode agent CLI) and, if the model supports it, a reasoning variant (`#high`, `#low`, `none`…`max`). `opencode-go/…` models (Go subscription — $80/mo DeepSeek V4.1 Flash allowance) draw on the plan automatically; a USD cap is rejected for them. Model list: `opencode models`. |
| Local model | `roc local-ai` installs Ollama (asks first); `roc local-ai --docker` adds Docker/Rev.ng hints (~5 GB). `roc model` lists and picks models. Local models load the GPU/CPU hard. |
| Claude Code / Codex | Install and sign in to the CLI, then select it under **Workers → Worker / Integrator → Model connection**. Both modes accept CLI models, APIs and local models. See [INTEGRATION.md](INTEGRATION.md). |

Cloud dollar caps need your exact model rates:
`roc provider pricing PROVIDER --model M --input-per-million X --output-per-million Y`.
`roc optimize --model M` calibrates a per-model worker profile on local verified matches
(never submits).

## Dashboard

`roc gui` opens the local dashboard (loopback only; keep its session link private).

- **Workers:** mining workers and native integrators in one chat view with session tabs, loop filters,
  live generated C++, and a configuration drawer. Function workers can pause, resume,
  retune and finish; integration controls apply at file/AI-round boundaries. Worker count controls parallel AI jobs; integration also has a separate compiler cap and batch size.
- **Commands:** run any `roc` command with a preview; jobs queue to protect shared files.
- **Functions / History:** local attempt history (`work/function-history.sqlite`) and saved runs.
- **Servers:** hosting guide, CPU contribution and cluster status (see [SERVER.md](SERVER.md)).
- **Workers → Agent:** choose Claude Code or Codex; install/sign in inside the card.
- **History:** searchable local attempts and server-stored functions; Runs and Experiments expand below.

Closing the tab leaves jobs running; **Exit ROC dashboard** stops them.

## Match by hand

```text
roc next 2008-06              easiest open functions
roc claim 2008-06 006e5040    writes src/2008-06/006e5040.cpp with the target asm as comments
roc check 2008-06 006e5040    compile with the client's compiler: 100% MATCH or a diff
roc classify 2008-06 ADDR F   explain a mismatch
roc submit 2008-06            send sources; the server re-verifies them
roc pull 2008-06              everyone's current sources
```

`ecx` used before it is set means `this`; `ret N` means N bytes of arguments;
`call dword ptr [...]` is an import (`__declspec(dllimport)`); inline asm is rejected;
data your source defines is checked too (wrong data scores 99%).

Automatic passes that need no C++: `roc mass` (all matchers), `roc auto`, `roc libs`
(library recipes), `roc xcopy` (copy matches between clients sharing a compiler),
`roc donor` (RBXGS WebService.dll PDB names), `roc shapes`, `roc research`.

## Where things live

| Path | Contents |
|---|---|
| `roc.py`, `roc/` | the CLI and library |
| `research/` | `recipes.json` experiments, `lessons.json` (ranked lessons), `reports.json` (old report index), `retired.json` (old runners), `repair-patterns.json`, `scout_sources.py` + `artifact-search-log.json` |
| `docs/` | guides and the website |
| `src/` | recovered sources (RoConstruct-findings checkout; ignored here) |
| `work/`, `tools/` | analysis, journals, server DB, compilers, libraries (ignored) |
| `local/` | this PC only: `config/` (settings, providers, worker config), `findings/`, `packages/`, `archive/` |

`packaging/organize-local.ps1` previews (or with `-Apply` performs) moving local state
into `local/`. It never deletes evidence, never deletes the publisher's lock, and skips
anything in use.

## Troubleshooting

`roc doctor` prints every check and the exact fixing command (`--json` for scripts).

| Message | Fix |
|---|---|
| `exe missing` | `roc client-fetch NAME` |
| `hash mismatch` | `roc client remove NAME --purge`, then rerun |
| `looks modified` | get an unmodified exe |
| `missing VS2005 / VS2008` | `roc install` again (resumes) |
| `cannot reach server` | server offline; workers retry |
| `no cloud model key is set` | `roc provider setup`, or `roc local-ai` |
| NVIDIA 404 for Nemotron Ultra | Keep namespace: `nvidia:nvidia/nemotron-3-ultra-550b-a55b`. For OpenCode sign-in: `opencode:nvidia/nvidia/nemotron-3-ultra-550b-a55b#none`. |
| Cloud HTTP 401/403 | Check key/model access; environment keys override ROC's saved key. OpenCode credentials require an `opencode:` model. |
| DeepSeek HTTP 402 | API balance exhausted; fix billing. Retrying or switching reasoning cannot repair billing. |
| `worker config was edited` | delete `local/config/roconstruct-worker.json`, run `roc setup` |
