#!/usr/bin/env python
"""Compiler-flag bruteforcer for one native source file against original addresses.

Compiles the source once per flag set (NATIVE_FLAGS override of native_check_runner.py),
scores the target addresses, and stops at the first byte-exact set.

Phase 0: mined (server-verified exact) source flags from src/2008-06/<addr>.cpp, its nearest
mined neighbours, then whole flag lines of the nearest native sources by address, then the most
common lines in native-classes, tried as-is first.
Phase 1: full grid over the main axes (optimizer, inline level, frame pointer, hotpatch).
Phase 2: greedy single-toggle flips from the best phase-1 set (secondary flags, CRT, EH).
Base tokens not on an axis (/I, /D, /FI ...) are kept as-is.

  python rebuild/2008-06/tests/flag_bruteforce.py native-classes/Mfcappmodul.cpp \
      007bca0b:?AfxInitialize@@YGHHK@Z
  options: --base "FLAGS" (default: the file's // native-flags line), --workers N,
           --build 21022|50727, --top N, --all (do not stop at first exact)

Local byte check only: no data, call-binding, ABI, link or P5/P6 proof. Source-shape
problems (statement order, wrong type) are not fixable by flags.
"""
import argparse, itertools, json, os, re, subprocess, sys, tempfile
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
RUNNER = ROOT / "rebuild/2008-06/tests/native_check_runner.py"
SRC_ROOT = ROOT / "rebuild/2008-06"
DEFAULT = "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS"

# Phase 1 axes: each is a list of alternatives (empty string = flag absent).
GRID = [
    ["/O1", "/O2", "/Ox", "/Os", "/Ot", "/Od"],
    ["", "/Ob0", "/Ob1", "/Ob2"],
    ["/Oy", "/Oy-"],
    ["", "/hotpatch"],
]
# Phase 2 axes: flipped one at a time against the best set.
FLIPS = [
    ["", "/Oi"], ["", "/GF"], ["", "/Gy"], ["", "/GS-"], ["", "/GS"],
    ["/EHsc", "/EHs", "/EHa", ""], ["/MD", "/MT", "/MDd"],
    ["", "/fp:fast", "/fp:precise", "/fp:strict"], ["", "/Gr", "/Gz"],
    ["", "/arch:SSE", "/arch:SSE2"], ["", "/Zp1", "/Zp4", "/Zp8"],
    ["", "/Zc:wchar_t", "/Zc:wchar_t-"], ["", "/GR", "/GR-"], ["", "/J"],
    ["", "/D_MBCS", "/D_UNICODE"], ["", "/D_AFXDLL"], ["", "/DNDEBUG"],
]
AXIS_TOKENS = {t for ax in GRID + FLIPS for t in ax if t}
SCORE = re.compile(r"^SCORE (\w+) status=(\w+) score=([\d.]+) .*?bytes=(\d+)/(\d+)", re.M)


def base_flags(source, override):
    if override:
        return override
    m = re.search(r"^// native-flags: (.*)$", source.read_text(encoding="utf-8-sig"), re.M)
    return m[1] if m else DEFAULT


GRID_TOKENS = {t for ax in GRID for t in ax if t} | {"/Ob0", "/Ob1", "/Ob2"}


def split_fixed(flags):
    return [t for t in flags.split() if t not in GRID_TOKENS]


def mined_seeds(addr, fixed, limit):
    """Flags of the mined (server-verified) exact source for this address, then its nearest mined neighbours.
    Mined flags are merged with the file's own non-grid tokens (includes/defines) and also tried alone."""
    out, hdr = [], re.compile(r"^// roc-(flags|cl): ?(.*)$", re.M)
    def read(path):
        try:
            h = dict(hdr.findall(path.read_text(encoding="utf-8-sig", errors="replace")[:600]))
            return h.get("flags", "").strip(), int(h["cl"]) if h.get("cl", "").isdigit() else None
        except OSError:
            return None
    d = ROOT / "src/2008-06"
    target = int(addr, 16)
    files = sorted((p for p in d.glob("*.cpp") if re.fullmatch(r"[0-9a-f]{8}(_.*)?", p.stem)) if d.is_dir() else [],
                   key=lambda p: (abs(int(p.stem[:8], 16) - target), p.stem))
    seen = set()
    for p in files[:60]:
        r = read(p)
        if not r or not r[0] or (r[0], r[1]) in seen:
            continue
        seen.add((r[0], r[1]))
        mined = [t for t in r[0].split() if t not in fixed]
        out.append((" ".join(fixed + [t for t in mined if t not in fixed]), r[1], "mined"))
        out.append((r[0], r[1], "mined-alone"))
        if len(seen) >= limit:
            break
    return out


def seed_flags(addrs, limit):
    """Phase 0: mined (server-verified exact) source flags from src/2008-06/<addr>.cpp, its nearest
mined neighbours, then whole flag lines used by the nearest native sources (by address), then the most common."""
    from collections import Counter
    line = re.compile(r"^// native-flags: (.*)$", re.M)
    def flags_of(rel):
        try:
            m = line.search((ROOT / rel.split("workspace/", 1)[-1]).read_text(encoding="utf-8-sig", errors="replace"))
            return m[1].strip() if m else None
        except OSError:
            return None
    seeds, nearest = [], []
    try:
        data = json.load(open(ROOT / "docs/integration.json"))
        src = {int(a, 16): v["path"] for a, v in data.get("inactive_sources", {}).items() if "native-classes/" in v["path"]}
        order = sorted(src, key=lambda a: abs(a - int(addrs[0], 16)))
        for a in order[:200]:
            f = flags_of(src[a])
            if f and f not in nearest:
                nearest.append(f)
            if len(nearest) >= limit:
                break
    except (OSError, ValueError, KeyError):
        pass
    common = Counter(f for f in (flags_of(str(p.relative_to(ROOT))) for p in (SRC_ROOT / "native-classes").glob("*.cpp")) if f)
    for f in nearest + [f for f, _ in common.most_common(limit)]:
        if f not in seeds:
            seeds.append(f)
    return seeds


def run(fixed, axes_choice, source, targets, build, scratch):
    flags = fixed if isinstance(fixed, str) else " ".join(fixed + [t for t in axes_choice if t])
    checks = [{"addr": a, "symbol": s} for a, s in targets]
    job = {"jobs": [{"source": source, "checks": checks}]}
    if build:
        job["compiler_build"] = build
    with tempfile.NamedTemporaryFile("w", suffix=".json", dir=scratch, delete=False) as f:
        json.dump(job, f)
    env = dict(os.environ, NATIVE_FLAGS=flags)
    try:
        out = subprocess.run([sys.executable, str(RUNNER), "run", f.name], cwd=ROOT, env=env,
                             capture_output=True, text=True, timeout=300).stdout
    except subprocess.TimeoutExpired:
        out = ""
    finally:
        os.unlink(f.name)
    rows = SCORE.findall(out)
    if not rows:                         # compile failure
        return flags, -1.0, False, 0
    score = sum(float(r[2]) for r in rows) / len(targets)
    exact = len(rows) == len(targets) and all(r[1] == "exact" for r in rows)
    size_delta = sum(int(r[3]) - int(r[4]) for r in rows)
    return flags, score, exact, size_delta


def sweep(candidates, fixed, source, targets, build, workers, scratch, stop_on_exact):
    results = []
    with ThreadPoolExecutor(workers) as pool:
        futs = {pool.submit(run, c[0] if fixed is None else fixed, c[1] if fixed is None else c,
                            source, targets, (c[2] if len(c) > 2 and c[2] else build) if fixed is None else build, scratch): c
                for c in candidates}
        for fut in as_completed(futs):
            r = fut.result()
            results.append(r)
            print(f"{r[1]:9.4f} {'EXACT' if r[2] else 'dsize=%+d' % r[3]:>9}  {r[0]}", flush=True)
            if r[2] and stop_on_exact:
                for other in futs:
                    other.cancel()
                break
    return sorted(results, key=lambda r: (-r[2], -r[1]))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", help="path relative to rebuild/2008-06, e.g. native-classes/Foo.cpp")
    ap.add_argument("targets", nargs="+", help="ADDR:SYMBOL (mangled symbol in the object)")
    ap.add_argument("--base")
    ap.add_argument("--workers", type=int, default=3)
    ap.add_argument("--build", type=int, choices=(21022, 50727))
    ap.add_argument("--top", type=int, default=5)
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--seeds", type=int, default=12, help="phase 0: nearest-address and most common flag lines to try first")
    a = ap.parse_args()
    targets = [tuple(t.split(":", 1)) for t in a.targets]
    base = base_flags(SRC_ROOT / a.source, a.base)
    fixed = split_fixed(base)
    scratch = tempfile.mkdtemp(prefix="flagbf-", dir=ROOT / "work/2008-06")
    seeds = [(base, (), a.build)]
    seeds += [(f, (), b) for f, b, _ in mined_seeds(targets[0][0], fixed, a.seeds)]
    seeds += [(f, (), a.build) for f in seed_flags([t[0] for t in targets], a.seeds)]
    seeds = list(dict.fromkeys(seeds))
    print(f"phase 0: {len(seeds)} seeds (file's own, mined source of this address and nearest mined, nearest native, most common)", flush=True)
    phase0 = sweep(seeds, None, a.source, targets, a.build, a.workers, scratch, not a.all)
    if phase0 and phase0[0][2] and not a.all:
        print(f"\nBEST\n{phase0[0][1]:9.4f}     EXACT  {phase0[0][0]}")
        print(f"\nTo pin: change line 1 of the source to '// native-flags: {phase0[0][0]}'.")
        sys.exit(0)
    print(f"fixed: {' '.join(fixed)}\nphase 1: {len(list(itertools.product(*GRID)))} sets", flush=True)

    phase1 = sweep(list(itertools.product(*GRID)), fixed, a.source, targets, a.build, a.workers,
                   scratch, not a.all)
    phase1 = sorted(phase1 + phase0, key=lambda r: (-r[2], -r[1]))
    best = phase1[0]
    # Phase 2: hill-climb. Flip one axis (grid or secondary) at a time from the current best,
    # move to any improvement, repeat until nothing improves (a pair like /O1 + /D_MBCS needs two rounds).
    seen_flags = {r[0] for r in phase1}
    for rnd in range(1, 7):
        if best[2] or best[1] < 0:
            break
        tokens = [t for t in best[0].split() if t not in fixed]
        flips = []
        for ax in GRID + FLIPS:
            axset = set(ax) | ({"/Ob0", "/Ob1", "/Ob2"} if ax is GRID[1] else set())
            cur = [t for t in tokens if t in axset]
            for alt in ax:
                if alt not in cur:
                    flips.append(tuple(t for t in tokens if t not in axset) + ((alt,) if alt else ()))
        flips = [f for f in dict.fromkeys(flips) if " ".join(fixed + [t for t in f if t]) not in seen_flags]
        if not flips:
            break
        print(f"phase 2 round {rnd}: {len(flips)} single-flag flips from best {best[0]}", flush=True)
        res = sweep(flips, fixed, a.source, targets, a.build, a.workers, scratch, not a.all)
        seen_flags |= {r[0] for r in res}
        phase1 += res
        phase1.sort(key=lambda r: (-r[2], -r[1]))
        if (phase1[0][2], phase1[0][1]) <= (best[2], best[1]):
            break
        best = phase1[0]
    print("\nBEST")
    for flags, score, exact, d in phase1[:a.top]:
        print(f"{score:9.4f} {'EXACT' if exact else 'dsize=%+d' % d:>9}  {flags}")
    print("\nTo pin: change line 1 of the source to '// native-flags: <flags>'.")
    sys.exit(0 if phase1 and phase1[0][2] else 1)


if __name__ == "__main__":
    main()
