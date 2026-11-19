# Family task: common rules (read fully)

Project: RoConstruct, byte-exact matching decompilation of the 2008-06 Roblox client. Repo root
C:\Users\colin\RoConstruct (Windows; use the Bash tool with POSIX syntax; run Python as `python`, from the repo root).

Goal of a family task: many remaining functions are instantiations of ONE template (byte-identical "twins"). Make the
template's native definition compile to the original bytes for ONE address; then every other instantiation follows
mechanically. You fix the root cause once; you do not hand-write each function.

## Data
- Which address is which instantiation (from RTTI / typeid in the binary):
  `work/native-client/research-twins/identities.json` -> ["unique"][addr] = {rule, identity, size}; evidence in
  `research-twins/evidence.json`. Owner/declaration facts: `work/native-client/research-owners/owners.json`.
- Byte-exact reference for every function: `src/2008-06/<addr>.cpp` (a mined ANALOG with stand-in structs). Use it to
  see the statement order / shape that produces the right code. NEVER copy its structs into native code.
- Original assembly: `python roc.py native-asm 2008-06 ADDR`.
- Native headers: `rebuild/2008-06/native-headers/` (hyphenated top-level folders there are per-unit variant snapshots:
  leave them alone). Native units: `rebuild/2008-06/native-classes/*.cpp` (first line `// native-flags: ...`).

## Tools (use these, do not write your own manifest readers)
- Prove one file, one screen verdict per address (1-3 min, run in the FOREGROUND with a 10 minute timeout, never in the
  background, never sleep/poll):
  `python work/native-client/agent_prove.py PATH/FILE.cpp ADDR[=NameSubstring] [ADDR ...]`
  -> EXACT | REJECTED (bytes equal, identity/reference reason) | DIFF (asm diff of closest symbol) | COMPILE FAILED |
  RETRY LATER (someone edited inputs during the proof: just run it again).
- Identity rows for a byte-equal body: `python work/native-client/agent_bind.py "DECORATED_SYMBOL" ADDR "evidence"`.
- Generate + prove an instantiation for an address automatically (compiles, proves, binds, keeps only exact; writes
  `rebuild/2008-06/native-classes/TwinInst_<addr>.cpp`): `python work/native-client/twin_lane.py --only ADDR[,ADDR] --jobs 1`
  (read its docstring; it handles rule "rtti" identities; results also in `work/native-client/twin-lane-done.json`;
  delete an address's entry there to retry it). You may improve `twin_lane.py` for your family (e.g. add the member
  template instantiations your family needs in `member_templates()`), keep the changes small and general.
- Draft files go under `work/native-client/lane-drafts/<name>/` (own folder each), not into native-classes, until proven.

## Rules (owner's, strict)
- Native code uses the REAL classes from native headers. Never define a class/struct/union, pad field or `extern`
  in a native .cpp; no `(char*)this + offset`; no `__emit`/asm; no byte blobs.
- Header edits: the owner approved editing core headers for THIS task only. Before editing any header take its lease:
  `python roc.py lease take family:<yourname> <repo-relative paths...> --hours 4` (if refused, someone else holds
  it: stop and report). Release when done: `python roc.py lease release family:<yourname>`. Edit only the template
  definition(s) of your family; never change class layouts of unrelated classes. Mark inferred additions
  `// INFERRED: <evidence>`.
- NO REGRESSIONS: before your first header edit, pick 3 already-proved units that include that header and note their
  exact counts: `python work/native-client/prove.py PATH/unit.cpp --rounds 1 --no-register` prints a JSON line with
  "exact": N. After your final header state, rerun the same 3 and require the same N (or higher). If a unit drops,
  fix or revert. Report the before/after numbers.
- Never run a census (`prove.py --all`, lane_runner census). Never grep/find recursively inside
  `work/native-client/prove-out` (tens of GB). No LLM/agent calls. Do not push. The machine is busy: one proof at a time.
- Commit locally when a family (or a clear part) is proven: `python roc.py lease check PATHS` then
  `git add <only your files>` and `git commit -m "native: <what> (inactive exact)"` ending with the line
  `Co-Authored-By: Claude Fable 5.2 <noreply@anthropic.com>`. If `.git/index.lock` exists and no git process runs,
  report it instead of deleting.
- After three failed hypotheses on the root cause, stop and report exactly what differs (asm diff) and what you tried.

## Report (final message, under 350 words)
Numbers first: addresses EXACT (list), addresses still failing and why, header lines changed, regression check
before/after, commit hash, lease released yes/no.

## Lessons from 20+ family sessions (2026-11-18): do not repeat these
- Every proof is 1-3 minutes. Sessions that proved the SAME unit 10-13 times, or read manifest.json by hand with
  `python -c`, wasted most of their budget: use `agent_prove.py` (it already prints the verdict and the diff), change
  ONE thing between proofs, and read the diff before the next proof.
- Never search broad trees: `rg`/`grep`/`Select-String` over `work/native-client` or `rebuild/` as a whole is slow and
  dumps noise. Open the exact file you need (the lane units, `twin-lane-done.json`, the header of your template).
- Windows console: always run Python with `PYTHONIOENCODING=utf-8` (a session died on a `→` print) and avoid
  non-ASCII characters in anything you print.
- If your premise is wrong (the address is not an instantiation of your template, e.g. the Weld constructors are plain
  class members), say so in one line and switch: write the member natively in the class's unit instead of forcing the
  lane. That session succeeded in 95 calls; the ones that kept forcing the premise did not.
- Hard budget: 80 tool calls. At 60 calls with nothing proved, stop and report the exact diff.
- A family worth the session is measured in BYTES: take the largest functions of the family first.

## One-screen tools added 2026-11-18
- `python work/native-client/family_status.py ADDR...`: identity, owner facts, existing unit, bound rows, last lane verdict.
  It flags an address whose size differs from its family's usual size (a wrong premise). Run it BEFORE touching an address.
- Identity rows with `$` in the symbol: `python work/native-client/agent_bind.py --file rows.json` (list of
  {"symbol","address","evidence"}); never pass such a symbol unquoted on a shell line.
- `work/native-client/family-known-failures.json` lists families that failed twice for a header reason: do not start them.
- `python work/native-client/prefix_match.py FILE.cpp ADDR[=name]` (no model, ~10-40 s): compiles the unit, compares the emitted
  function to the original, prints matching prefix (insns/bytes of target), the first divergent instruction with 3 lines
  of context both sides, and score = prefix bytes / target bytes. A partial body is fine. Pass FILE as a repo-relative path.
- `python work/native-client/evolve.py ADDR --file FILE.cpp [--name SUBSTR] [--rounds 6] [--width N] [--no-permute]`: permuter first
  (roc.mutate), then model rounds that edit only the first divergent hunk, graded by prefix_match. Best draft goes to
  lane-drafts/evolve_<addr>/best.cpp; prove it with agent_prove.py. `--batch LIST` runs it over many near-miss drafts.
- Use prefix_match first on any big draft: fix the first divergence, rerun; the score tells whether a change helped.
