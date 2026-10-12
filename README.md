<p align="center">
  <img src="docs/logo.png" alt="RoConstruct" width="560">
</p>

<p align="center">
  <b>Rebuilding classic Roblox clients (2007–2012) as real C++ source, together.</b><br>
  <a href="https://colingsnyder2-ux.github.io/RoConstruct/">Progress site</a> ·
  <a href="https://discord.gg/Tayg763nrG">Discord</a> ·
  <a href="https://github.com/colingsnyder2-ux/RoConstruct-findings">Findings</a>
</p>

---

The old Roblox clients survive only as compiled executables. RoConstruct uses
**matching decompilation**, the method behind the Super Mario 64 and Ocarina of Time
projects: each function gets C++ that the client's original MSVC compiler turns into
the exact same bytes.

| Step | What happens |
|---|---|
| Split | The exe is cut into functions (20k–40k per client). |
| Guess | A person, an AI worker or a pattern matcher writes C++ for one function. |
| Compile | The guess is built with the exact compiler Roblox used. |
| Compare | Byte-identical code and data means **matched**; otherwise a diff shows what to fix. |

A fully matched client rebuilds the original program, which opens the way to security
fixes, ports (WebAssembly, Linux, macOS), bug fixes, modding and preservation.

## Get started

1. Download this repository (Code → Download ZIP) and unzip it.
2. Double-click **`install.cmd`** (Linux: `./install.sh`). It installs Python packages and
   the exact compilers only: no GPU, Ollama or Docker.
3. Click **Help out** on a client at the [website](https://colingsnyder2-ux.github.io/RoConstruct/),
   or run **`roc.cmd`** for a menu.

`roc.cmd` is the only launcher you need. `roc --help` lists every command, grouped;
`roc doctor` explains anything that is broken and how to fix it.

| You have | Do this |
|---|---|
| A PC | `roc launch`: a cloud worker (API key or ChatGPT plan) keeps your PC mostly idle |
| A GPU | `roc local-ai`, then `roc launch` with a local model |
| Claude Code or Codex | `roc gui` → **Workers → Agent worker** |
| C++ knowledge | `roc next`, `roc claim`, `roc check`, `roc submit` |
| An always-on PC | `roc host` (maintainers) |

## Documentation

| Document | For |
|---|---|
| [docs/SETUP.md](docs/SETUP.md) | install, Linux, models and ChatGPT plan, dashboard, matching by hand, troubleshooting |
| [docs/AGENT_GUIDE.md](docs/AGENT_GUIDE.md) | matching workflow, tool routing, experiment memory, automatic agent workers |
| [docs/SERVER.md](docs/SERVER.md) | hosting, publishing, Discord, private cluster, clients, packages |
| [docs/SOURCES.md](docs/SOURCES.md) | every source we compile, what is still missing ([live page](https://colingsnyder2-ux.github.io/RoConstruct/sources.html)) |

Recovered sources, portable agent evidence and historical research reports are published
in [RoConstruct-findings](https://github.com/colingsnyder2-ux/RoConstruct-findings)
([latest source ZIP](https://github.com/colingsnyder2-ux/RoConstruct-findings/releases/download/findings-latest/roconstruct-findings-src.zip)).

## Rules

- Never commit or share Roblox client files; everyone brings their own verified copy.
- Only server-verified byte matches count. No inline assembly or patched bytes.
- Be friendly. Join us on [Discord](https://discord.gg/Tayg763nrG).
