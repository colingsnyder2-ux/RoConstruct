# Match functions with your own Claude Code or Codex plan

`roc agent` lets a coding agent you already pay for do the matching work. It
leases a function from the group server, puts it in `src/<client>/<addr>.cpp`
(starting from the server's best source), and runs the agent CLI on it. The
agent edits that one file and re-runs `roc check` until it matches or stops
improving. RoConstruct then re-scores the file itself: a gain is submitted
under the lease (the server verifies it again), and a regression is rolled back.

Usage is billed to whatever the CLI is signed in with on your PC: your Claude
Pro/Max plan for `claude`, your ChatGPT plan for `codex`, or an API key if you
set one (`ANTHROPIC_API_KEY` / `OPENAI_API_KEY` take precedence in those CLIs).

## Set up

1. Finish the normal setup (`install.cmd` or `./install.sh`) and `roc config`
   with your username and the server.
2. Install and sign in to one CLI:
   - Claude Code: `npm install -g @anthropic-ai/claude-code`, then run `claude` once and log in.
   - Codex: `npm install -g @openai/codex`, then run `codex` once and sign in with ChatGPT.

## Run

```text
roc agent claude --jobs 5
roc agent codex --client 2008-06 --jobs 10 --max-size 128
roc agent claude --model sonnet --minutes 30
```

`--minutes` caps each function (default 20); `--jobs` is how many functions to
do one after another.

### Goal mode

Give the agent a task in plain words instead of one leased function:

```text
roc agent claude --goal "match as many 2008-06 RakNet functions as you can"
roc agent codex --goal "finish the zlib functions in 2008-06" --minutes 60
```

The agent picks its own functions with `roc next`/`claim`/`check`, may run any
`roc.py` command, searches the web for the original library source, and submits
gains with `roc submit`. A session runs up to `--minutes` (default 120). The
menu (`roc.cmd` with no arguments) offers this as "Match functions with my
Claude Code / Codex plan".

What the agent may do: Claude runs with `acceptEdits`; per function it may only
run `roc.py check`, in goal mode any `roc.py` command plus web search/fetch.
Codex runs with `--full-auto` (writes limited to this folder). Submissions are
always re-verified by the server before they count.

## Claude Code cloud sessions (claude.ai/code)

A cloud session is Claude Code running in an Anthropic Linux VM, paid from your
Claude plan or cloud session credits. There, Claude itself is the agent, so it
uses the manual loop instead of `roc agent` (see `CLAUDE.md`). It needs:

- **Network access: Full** (or a custom allowlist) in the environment settings.
  The VM must reach the compiler downloads, the client download source and the
  group server. A Tailscale-only server address is not reachable from the cloud;
  it needs a public address (for example Tailscale Funnel).
- **Setup script** for the environment (not yet proven end to end; Wine runs the
  old 32-bit `cl.exe`):

  ```sh
  sudo dpkg --add-architecture i386 && sudo apt-get update
  sudo apt-get install -y wine wine32 msitools cabextract p7zip-full
  ./install.sh
  ```

Then ask the session, for example: "Set up with `./roc.sh doctor`, then match
open 2008-06 functions following CLAUDE.md and submit any gains."
