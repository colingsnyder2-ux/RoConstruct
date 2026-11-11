# Deterministic native recovery

This runner makes no model/provider requests. It automates work supported by existing
source and declarations; it cannot reconstruct arbitrary missing APIs or layouts.
Those targets retain a `needs_evidence` or `parked` record instead of receiving a stub.

Run from `C:\Users\colin\RoConstruct`. Use a completed census manifest, not one being
rewritten by a live proof process.

```powershell
# Plan only; native source stays untouched.
python work/native-client/ogre/deterministic_workflow.py --manifest work/native-client/census-mesh-round1-manifest.json

# Recover up to ten eligible functions; at most25 minutes per target.
python work/native-client/ogre/deterministic_workflow.py --manifest work/native-client/prove-out/OgreNativeFull/manifest.json --run --limit 10 --minutes 25

# Same batch, then commit/push clean proved survivors and run one final census.
python work/native-client/ogre/deterministic_workflow.py --manifest work/native-client/prove-out/OgreNativeFull/manifest.json --run --commit --census

# One target, mechanical repairs only.
python work/native-client/fix_loop.py 004ef930 --no-llm --minutes 25
```

## What runs automatically

1. Select unrecovered Ogre addresses, largest first, from the original987-function scope.
2. Find an existing native declaration/destination and an existing100% donor body.
3. Skip recorded PARKED evidence and unchanged rejected attempts. Source/header/recipe
   changes permit retrying scheduler failures; `--retry-parked` explicitly revisits manual parks.
4. Acquire source/header leases. Transplant typed C++; try existing-header includes,
   offset-to-member names, evidence-backed globals, and unambiguous friend access.
5. Prove exact bytes and original references. Reprove changed-header dependents and
   preserve every baseline accepted address. Candidate aliases do not receive recovery credit.
6. Keep accepted source; otherwise restore source/header bytes and save the rejected trial.
7. Persist state/events/handoff. Resume uses the same state file. OS locking prevents
   two scheduler instances; locks release automatically after process exit.
8. Optional `--commit` uses `native_commit.py` once per batch. The runner requires the
   authorized branch and an empty existing staging area before committing.
   Only receipt-listed, still-proved native paths qualify. Pre-existing user edits block
   automatic commit. Local proof/identity artifacts remain available for audit/reproof.
9. Optional `--census` runs `prove.py --all` and writes a scope audit with exact addresses,
   inferred-name counts, and added/deleted/changed native input checks. Concurrent
   modifications invalidate clean-census claims; they are never treated as runtime proof.

The scheduler defers mutations while any proof process is live. By default it does not launch a
wake loop, diagnostic executable, mining command, worktree, or PR. The broad Ogre goal
can stay paused while this tool is developed or inspected.

## Optional objdiff and C++ permuter

These tools are opt-in. Set them up on Windows with:

```powershell
python work/native-client/native_repair_tools.py setup
```

Setup uses a checksum-pinned objdiff release and a commit-pinned cpp_permuter checkout
under `work/native-client/external-eval/`. It needs Git, CMake, a modern C++ compiler,
and network access. It will not replace a different existing binary or modify a dirty
permuter checkout. Override executable locations with `ROCONSTRUCT_OBJDIFF` and
`ROCONSTRUCT_CPP_PERMUTER`. The actual recovery compiler remains MSVC 2008.

For an existing compilable source and its decorated symbol:

```powershell
python work/native-client/native_repair_tools.py diff $source $address $symbol
python work/native-client/prove.py $source --diff $address --objdiff-symbol $symbol
python work/native-client/native_repair_tools.py permute $source $address $symbol $method --iterations 12 --seconds 180
```

`$method` is a qualified name such as `Part::Part`. Diff writes a machine-readable
objdiff report under `work/native-client/repair-tool-runs/`. Its original-side COFF
contains original function bytes but omits PE relocation metadata: highlights and
similarity are diagnostic only. The permuter operates on a scratch copy and first
compares its compiled body with the real source context; a mismatch stops the run.
It uses one worker, a candidate limit, and a hard time limit of at most 25 minutes.
A zero score only means masked bytes match; references still require normal proof.

To enable these aids inside the deterministic worker, add `--repair-tools --run` to
the scheduler command, or add `--repair-tools --no-llm` to `fix_loop.py`. It tries
them at most once per target after compilation succeeds; it skips permutation when
the body already matches bytes, or is not within 5% of the original size. A zero-score
candidate can replace the leased trial only if its signature and all other source stay
unchanged, the target passes the existing byte/reference proof, and previous exacts
remain exact. Failure or interruption restores the original trial. The usual final
transaction and commit gates still apply. No model is called in deterministic mode.

Other candidates: [reccmp](https://github.com/isledecomp/reccmp) can compare old
MSVC x86 binaries and inspect stack layouts, but needs a recompiled binary and PDB;
it does not fit this inactive-only stage. [BinDiff](https://github.com/google/bindiff)
can compare Ghidra analyses and help find analogous functions in related builds;
similarity is triage, not byte/reference proof. The C-oriented decomp-permuter does
not list x86 as a supported architecture; cpp_permuter fits this C++/MSVC workflow.

## Artifacts and limits

Default output: `work/native-client/deterministic-workflow/`:
`plan.json`, `state.json`, `events.jsonl`, `summary.json`, and optional `census-audit.json`.
Rejected native trials also retain the existing `fix-loop-parked/` artifacts.

No useful deterministic rule means stop that target immediately, rather than repeat
the same attempt until the timer expires. Byte-generation, raw-offset receiver views,
invented layouts, and stubs remain disallowed. Importing existing discovery helpers
does not enable their model ladder: the worker explicitly sets `allow_models=False`.

The proof subprocess deadline stops compiler/binder descendants too. Interrupts restore
the native transaction. Formatting is omitted in mechanical mode to avoid an extra
unbounded proof subprocess. The final full census has its own potentially longer duration.

All successes are **inactive_exact** only. Field/layout inference still needs a separate
audit; the scope report leaves that count unset instead of inventing a number.
There is no linked, runnable, server, or P5/P6 claim.
