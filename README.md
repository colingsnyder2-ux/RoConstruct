# RoConstruct

A group project to turn old Roblox clients (2007–2010) back into readable C++ source code, one function at a time.

**Progress:** https://colingsnyder2-ux.github.io/RoConstruct/

---

## What is this? (the simple version)

A game like Roblox starts as **source code**: text that programmers write. A program called a **compiler** turns that text into the `.exe` file your computer runs. The exe is just numbers. People can't easily read it, and you can't easily change it.

The original source code for these old clients isn't available. We're **rebuilding it**.

Think of it like a cake. We have the cake (the exe) but not the recipe (the source). So we:

1. **Cut the cake into slices.** RoConstruct splits the exe into its ~40,000 pieces, called **functions**. Each one is a small job, like "get this part's color" or "play this sound".
2. **Guess the recipe for one slice.** Someone writes C++ code they think produced that function. That someone can be a person or an AI.
3. **Bake it with the original oven.** We compile the guess with the **exact same compiler Roblox used in 2008**.
4. **Compare.** If our slice is identical to the original, down to every byte, the recipe is proven correct. That's a **match**. If not, the tool shows exactly which instructions differ, and we try again.

Once every function matches, we have the complete recipe: real source code that rebuilds the same client.

This approach is called **matching decompilation**. Fan projects have used it to fully rebuild Super Mario 64, Zelda: Ocarina of Time and Super Smash Bros.

## Why bother? What this unlocks

- **Security fixes.** Old clients have known exploits, and running them today is risky. With the source, those holes can be patched properly instead of hacked around.
- **Run it in a web browser.** With source, the client can be compiled to **WebAssembly**, so a 2008 client could run in a browser tab with no download.
- **Run it anywhere.** Native builds for Linux, macOS, phones and new hardware, instead of relying on old Windows DLLs.
- **Bug fixes and quality of life.** Fix crashes, support modern screens and wide resolutions, remove dead online features cleanly.
- **Preservation.** The history of how Roblox worked is kept in a form people can read and learn from, not as a binary that slowly stops running.
- **Modding.** Changing behavior means editing readable code, not patching bytes in a hex editor.

## What happens after everything is 100%?

Matching every function is the biggest step, but not the last:

1. **Match the data.** Text, tables and constants (the "Data" bar on the site) need to match too.
2. **Rebuild the whole exe.** Link all the matched pieces in the original order and get an exe identical to the original. This proves nothing was missed.
3. **Name and organize.** Replace placeholder names (`func_00401000`, `pad[0x44]`) with real names, real types and real source files, so humans can work with the code.
4. **Swap out other people's code.** The client includes outside libraries: Ogre and G3D (graphics), Lua (scripting), RakNet (networking), boost, MFC and Codejock (Windows UI), FMOD (sound). Open-source ones get swapped for their real source. Proprietary ones (MFC, Codejock, FMOD) get replaced with open alternatives (for example SDL and OpenAL).
5. **Port it.** Build with a modern compiler (a "non-matching" build), then target WebAssembly (Emscripten + WebGL), Linux and macOS.

---

## Join in: 3 steps

1. **Download** this repo (green Code button, then Download ZIP, then unzip), or `git clone` it.
2. **Double-click `install.cmd`.** It installs Python if needed and downloads the old Microsoft compilers. Each download is checked against Microsoft's signature or a known fingerprint. Nothing is installed system-wide and no admin rights are needed.
3. **Put your own copy of the client** in its folder, for example `clients\2008M\RobloxApp_client.exe`. Then double-click `roc.cmd`.

`roc.cmd` opens a menu:

```
  1. First-time setup (downloads compilers, checks everything)
  2. Help automatically with AI (start a worker)
  3. Work on a function by hand
  4. Check my hand-written functions
  5. Send my hand-written functions to the server
  6. Host the group server
  7. Server status and leaderboard
  8. Update the progress website files
  9. Add a new Roblox client
 10. Auto-match easy functions
```

### Ways to help

| You have | Do this |
|---|---|
| A gaming PC (NVIDIA GPU, 8 GB+ VRAM) | **AI worker** (menu 2). Install [Ollama](https://ollama.com), run `ollama pull qwen2.5-coder:7b` (or `:14b`), and leave it running. It grabs functions, writes attempts, compiles and checks them, and sends the best result to the server under your username. |
| Some C++ knowledge | **By hand** (menu 3). Pick an easy function. RoConstruct writes a file with the target assembly as comments. Write C++ until `roc check` says `MATCH`, then send it (menu 5). |
| An always-on PC | **Host the server** (menu 6) and give people the address. |

Optional: install [Docker Desktop](https://www.docker.com/products/docker-desktop/) and run `docker pull revng/revng`. AI workers then also get a Rev.ng decompiler hint for every function.

The **leaderboard** on the website and in `roc status` shows who matched the most.

---

## How it works (more detail)

```
 RobloxApp_client.exe
        |  roc analyze      split into functions (follows the code, reads relocations,
        v                   finds class names from RTTI, skips compiler-made stubs)
 work/<client>/functions.jsonl
        |  roc server       hands out one function at a time ("lease")
        v
 worker / human  --->  draft C++  (Ollama AI, Rev.ng hint, or you)
        |  roc check        compile with the ORIGINAL cl.exe, compare bytes
        v                   (addresses that move between builds are ignored)
   score 0-100%  ---> not 100? show the assembly diff, try again
        |
        v  submit           server re-checks, keeps the best version, credits your username
 docs/  (roc progress)  --> website: treemap, per-client pages, history, leaderboard
```

- **Score:** 100% means byte-identical. Lower scores say how close it is. Partial work is kept so the next attempt starts from the best version, not from zero.
- **Units:** functions are grouped by the class they belong to, recovered from the exe's RTTI data (for example `RBX::DataModel`). Code with no class nearby goes into `seg_<address>` blocks.
- **Auto-matching:** about 1 in 7 small functions are trivial (`return this->x;`, `return 0;`, empty bodies). `roc auto` recognizes these by shape, compiles hundreds of guesses in one go, and keeps only exact matches. The server does this at startup, credited to the bot user `auto`. That cleared about 3,400 functions across the 4 clients in under a minute, so people and AI can focus on the real work.
- **Compiler stubs:** import thunks, `this`-adjust thunks and exception-unwind helpers are generated by the compiler, not written by people. They don't count toward progress.

### Commands

```
roc install                       download compilers, check tools  (--yes: no questions)
roc client list                   which clients you have
roc client add <name> <exe>       start a new client (then commit clients/clients.json)
roc analyze <name|all>            split an exe into functions
roc next <client>                 easiest open functions
roc claim <client> <addr>         start one: src/<client>/<addr>.cpp  (--open: Notepad)
roc check <client> [addr]         compile + score; one file shows the assembly diff
roc auto <client|all>             auto-match trivial functions (getters, setters, empty bodies)
roc submit <client> [addr...]     send hand-written sources to the server
roc flags <client>                work out the client's compiler flags from matched code
roc config --user NAME --server URL [--token PW] [--model M]   save your settings
roc worker [--jobs N] [--rounds N] [--max-size BYTES]          AI worker
roc server [--port 8765] [--token PW]                          host the group server
roc status                        server progress, active workers, leaderboard
roc progress                      write website data (pulls scores from your server)
```

### Writing a function by hand

`roc claim 2008M 006e5040` creates:

```cpp
// roc 2008M 006e5040  unit: CXTPControls  size: 17 bytes
// 006e5040  8b81d0000000   mov eax, dword ptr [ecx + 0xd0]
// 006e5046  85c0           test eax, eax
// 006e5048  7404           je 0x6e504e
// 006e504a  8b4024         mov eax, dword ptr [eax + 0x24]
// 006e504d  c3             ret
// 006e504e  33c0           xor eax, eax
// 006e5050  c3             ret
```

You write:

```cpp
struct Item { char pad[0x24]; int m_id; };
struct CXTPControls {
    char pad[0xd0];
    Item* m_item;
    int GetId();
};

int CXTPControls::GetId()
{
    return m_item ? m_item->m_id : 0;
}
```

`roc check 2008M 006e5040` then prints `100%  MATCH`. Tips:

- `ecx` used before it's set means `this`, so write a member function.
- `ret 4` means the function takes one 4-byte argument.
- `call dword ptr [...]` calls an imported function: declare it `extern "C" __declspec(dllimport)`.
- Global and function addresses are ignored, so any name works. Declare everything yourself (there are no Roblox headers).
- Inline assembly (`__asm`) is rejected. The point is real C++.

## Adding a new client

```
roc client add 2011E C:\path\to\RobloxApp_client.exe
```

This copies the exe into `clients/2011E/` (never committed), records its SHA-256 and the compiler that built it, and analyzes it. Commit `clients/clients.json` and restart the server. Everyone with the same exe can then work on it. The compiler is detected from the exe's Rich header. If it's not one of the three below, add a download to `roc/setup.py`.

## Compilers

`roc install` gets these automatically into `tools/`:

| Client | Compiler | Source (checked before use) |
|---|---|---|
| 2008M, 2010L | VS2008 RTM, cl 15.00.21022 | [VS2008 Express DVD (2007)](https://archive.org/details/VisualStudioExpressEditionsDVD2007), SHA-1 `65ebdd88…`, files signed by Microsoft |
| 2009E | VS2008 SP1, cl 15.00.30729 | [VCForPython27.msi](https://web.archive.org/web/20210106040224/https://download.microsoft.com/download/7/9/6/796EF2E4-801B-4FC4-AB28-B59FBF6D907B/VCForPython27.msi), signed by Microsoft |
| 2007M | VS2005, cl 14.00.50727 | [Visual C++ 2005 Express](https://archive.org/details/MS_VisualCPPExpress-2005), SHA-1 `1ae44e4e…`, files signed by Microsoft |

A download that fails its check is deleted and refused. Already have Visual Studio 2005/2008 installed? It's found automatically. For other locations, set `ROC_CL` to the `cl.exe` path. The `vcredist_*.exe` files some launchers ship are runtimes only; they don't contain a compiler.

## Hosting the server

```
roc server --token somepassword
```

- Workers connect with `roc worker --server http://<your-ip>:8765 --token somepassword`.
- For people outside your home network, forward TCP port 8765 on your router, or use a tunnel (Tailscale, ngrok).
- The server keeps everything in `work/server.db`, so back that file up.
- Abandoned jobs free themselves after 15 minutes (`--lease`).
- If the server PC has the compilers and client exes, it re-checks every submission, so a wrong score can't be faked.

## Progress website

`roc progress` writes `docs/`, then you commit and push. GitHub Pages serves it: Settings → Pages → branch `main`, folder `/docs`.

The site shows:
- overall progress and a card per client
- a treemap per client (click a box for its `roc claim` command, filter like `Instance <70% >1kb`)
- Code/Data bars
- Previous/Next through commit history
- the contributor leaderboard

## Rules

- **Never commit client exes, DLLs or game content.** `.gitignore` blocks everything in `clients/` except the registry.
- `src/` (matched sources) is git-ignored by default. Matched source reproduces Roblox's code, and publishing it in a public repo risks a takedown. The server keeps the sources; the group decides what gets published.
- Only use client files you are allowed to have.

## Troubleshooting

| Message | Fix |
|---|---|
| `exe missing` / `hash mismatch` | Put the exact client exe in `clients/<name>/`. A different build of the same year won't work. |
| `Missing compiler` | `roc install` |
| `cannot reach server` | Check the address, port forwarding, and that the server is running. |
| `wrong or missing server password` | `roc config --token <password>` |
| `AI workers need Ollama` | Install Ollama, then `ollama pull qwen2.5-coder:7b`. No GPU? Help by hand instead. |
| `This step needs Python 3.12 or older` | `install.cmd` installs 3.12. Python 3.13 removed a module the compiler unpacker uses. |
