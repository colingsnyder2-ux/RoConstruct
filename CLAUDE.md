# RoConstruct

Matching decompilation of old Roblox clients: write C++ that the client's original
MSVC compiles to the exact target bytes. Read `docs/AI_WORKER_GUIDE.md` first.

Manual matching loop (`./roc.sh` on Linux, `roc.cmd` on Windows):

1. `roc doctor` - fix setup problems first.
2. `roc pull <client>` - get everyone's current sources so you don't redo matched work.
3. `roc next <client>` - easiest open functions; `roc claim <client> <addr>` writes `src/<client>/<addr>.cpp`.
4. Edit that file, then `roc check <client> <addr>` - score plus assembly diff; repeat.
5. `roc submit <client> <addr>` - the server re-verifies before storing.

Never use inline assembly or patch target bytes. `roc agent claude|codex` automates
this loop with a local agent CLI (`docs/agent-cli.md`).
