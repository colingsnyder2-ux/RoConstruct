# Repository maintenance — 2026-10-10

Root investigation scripts and diagnostic output now live locally under
`work/investigation/`, which is ignored. Reusable benchmark runners, frozen
target manifests, and regression tests remain tracked. Pytest cache is ignored.
No investigation files were deleted from disk.

Worker fixes include consistent automatic concurrency, automatic rounds/output
budgets, saved launcher settings, a 128–32768 token range across CLI/launcher/GUI,
restored `--client all`, correct duplicate compile feedback, compact-log completion,
and stopping a lease loop when its cloud budget is exhausted. Existing fingerprint
scoping and source-candidate archive work is preserved.

Linux commits `4f39881d5`, `d12ee001b`, `81f0f178c`, and `d016a67e1` remain ancestors
of main. Wine compiler support, MSI extraction fixes, architecture handling, and
case-insensitive source lookup remain present. Tests cover the Linux branches;
GitHub Actions runs the suite on Ubuntu and Windows, now including frontend tests.

Local verification: `python -m pytest tests -q` — 241 passed, one existing
`msilib` deprecation warning. `node tests/test_gui_frontend.js` and
`git diff --check` passed. No paid generation or live submissions were run.
Native Linux/Wine compilation was not run locally; this host is Windows.
