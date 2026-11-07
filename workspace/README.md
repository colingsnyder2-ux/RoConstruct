> Maintained native source/tools: [RoConstruct work/workspace](https://github.com/colingsnyder2-ux/RoConstruct/tree/work/workspace). For an agent, use the [native prompt](https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct/work/data/NATIVE_AGENT.md). A branch ZIP contains a `workspace` folder; enter it before running tools.

<p align="center">
  <img src="docs/logo.png" alt="RoConstruct" width="560">
</p>

<p align="center">
  <b>Rebuilding classic Roblox clients (2007â€“2012) as real C++ source, together.</b><br>
  <a href="https://colingsnyder2-ux.github.io/RoConstruct/">Progress site</a> Â·
  <a href="https://discord.gg/Tayg763nrG">Discord</a> Â·
  <a href="https://github.com/colingsnyder2-ux/RoConstruct/tree/work">Findings</a>
</p>

---

The old Roblox clients survive only as compiled executables. RoConstruct uses
**matching decompilation**, the method behind the Super Mario 64 and Ocarina of Time
projects: each function gets C++ that the client's original MSVC compiler turns into
the exact same bytes.

| Step | What happens |
|---|---|
| Split | The exe is cut into functions (20kâ€“40k per client). |
| Guess | A person, an AI worker or a pattern matcher writes C++ for one function. |
| Compile | The guess is built with the exact compiler Roblox used. |
| Compare | Byte-identical code and data means **matched**; otherwise a diff shows what to fix. |

A fully matched client rebuilds the original program, which opens the way to security
fixes, ports (WebAssembly, Linux, macOS), bug fixes, modding and preservation.

## Get started

1. Download the [verified Worker ZIP](https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct/work/data/native-worker.zip), check its [SHA-256 manifest](https://raw.githubusercontent.com/colingsnyder2-ux/RoConstruct/work/data/native-worker.json), and unzip it.
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
| OpenCode, Claude Code or Codex | `roc gui` â†’ **Workers â†’ Worker / Integrator**, or use [Matching agent](docs/MATCHING_AGENT.md) / [Native agent](docs/NATIVE_AGENT.md) |
| C++ knowledge | `roc next`, `roc claim`, `roc check`, `roc submit` |
| An always-on PC | `roc host` (maintainers) |

## Documentation

| Document | For |
|---|---|
| [docs/SETUP.md](docs/SETUP.md) | install, Linux, models and ChatGPT plan, dashboard, matching by hand, troubleshooting |
| [docs/AGENT_GUIDE.md](docs/AGENT_GUIDE.md) | matching workflow, tool routing, experiment memory, automatic agent workers |
| [docs/SERVER.md](docs/SERVER.md) | hosting, publishing, Discord, private cluster, clients, packages |
| [docs/SOURCES.md](docs/recovery/SOURCES.md) | every source we compile, what is still missing ([live page](https://colingsnyder2-ux.github.io/RoConstruct/sources.html)) |

Recovered sources, portable agent evidence and historical research reports are published
in [RoConstruct work branch](https://github.com/colingsnyder2-ux/RoConstruct/tree/work)
([latest source ZIP](https://github.com/colingsnyder2-ux/RoConstruct/archive/refs/heads/work.zip)).

## Native rebuild

Work locally in `rebuild/2008-06/`. Recovered declarations and implementations live in `native-headers/` and `native-classes/`; reviewed sources are gradually moving into project folders such as `App/src/`. Some setups provide local `Source/` views of donor inputs, but those views are not part of the published Git tree. See `rebuild/2008-06/SOURCE_LAYOUT.txt` for build inputs and audit locations.

The [public source package](https://github.com/colingsnyder2-ux/RoConstruct/tree/work/2008-06) exports assembled C++, configs, patches, runtime harnesses and verification metadata. Native runtime integration remains partial. Run its `compile_test.bat` with `ROC_ROOT` pointing to this configured tooling checkout.

Keep current native work under `rebuild/2008-06/`; the work branch publishes a reviewed public view under `2008-06/`. `integration-status.json` distinguishes source-only recovery, inactive compiler probes, linked code, and scoped runtime evidence. `roc rebuild 2008-06 install` restores missing build inputs from the work-branch package while preserving existing files; generated build artifacts remain local.

## Rules

- Keep original client downloads out of this tooling repository. Native rebuild sources and required assets belong in RoConstruct work branch; generated output stays local.
- Only server-verified byte matches count. No inline assembly or patched bytes.
- Be friendly. Join us on [Discord](https://discord.gg/Tayg763nrG).
