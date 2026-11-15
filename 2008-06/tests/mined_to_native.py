#!/usr/bin/env python
"""Turn mined exact sources (src/2008-06/<addr>.cpp with `// roc-lib: RECIPE FILE`) into verbatim native files.

For each (recipe, upstream file) group of still-uncovered addresses (a missing.json of
[addr, size, ...] rows per library, or --addrs), write native-classes/Mined<Recipe><File>.cpp
with the mined roc-flags plus the recipe's defines, includes and preincludes, compile all of them
through native_check_runner (range checks), and keep only files whose ranges hit.
Range hits are masked-byte analogs, not identity proof.

  python rebuild/2008-06/tests/mined_to_native.py missing.json [--keep-all]
"""
import json, re, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))
from roc import libs  # noqa: E402

NC = ROOT / "rebuild/2008-06/native-classes"
H = "{headers}/../../../tools/libs/"


def group(rows):
    g = {}
    for a, size in rows:
        try:
            head = (ROOT / f"src/2008-06/{a}.cpp").read_text(encoding="utf-8-sig", errors="replace")[:900]
        except OSError:
            continue
        lib = re.search(r"// roc-lib: (\S+) (\S+)", head)
        cl = re.search(r"// roc-cl: (\d+)", head)
        fl = re.search(r"// roc-flags: (.*)", head)
        if not lib or not fl or (cl and cl[1] not in ("21022", "50727")):
            continue
        g.setdefault((lib[1], lib[2].replace("\\", "/"), fl[1].strip(), cl[1] if cl else "21022"), []).append((a, size))
    return g


def native_flags(recipe, flags):
    r = libs.RECIPES.get(recipe, {})
    out = [flags]
    out += ["/D" + d for d in r.get("defines", "").split()]
    for inc in r.get("include", []):
        if inc != "WINSDK":
            out.append("/I" + H + inc)
    out += ["/FI" + p for p in r.get("preinclude", [])]
    return " ".join(out)


def main():
    rows = json.load(open(sys.argv[1]))
    allrows = [(a, s) for v in rows.values() for a, s, *_ in v] if isinstance(rows, dict) else rows
    jobs, made = [], []
    for (recipe, file, flags, cl), items in group(allrows).items():
        r = libs.RECIPES.get(recipe)
        if not r or "src" not in r:
            continue
        src = ROOT / "tools/libs" / r["src"] / file
        if not src.is_file():
            continue
        name = "Mined" + re.sub(r"[^A-Za-z0-9]", "", recipe + Path(file).stem)
        dest = NC / (name + ".cpp")
        if not dest.exists():
            dest.write_text(f"// native-flags: {native_flags(recipe, flags)}\n// 2008-06 native {name} (inactive): mined exact source "
                            f"{recipe} {file}, verbatim.\n" + src.read_text(encoding="utf-8-sig", errors="replace"), encoding="utf-8")
        if dest not in made:
            made.append(dest)
        jobs.append({"source": f"native-classes/{dest.name}", "ranges": [f"{a}-{int(a, 16) + s:08x}" for a, s in items]})
        if cl == "50727":
            jobs[-1]["compiler_build"] = 50727
    manifest = ROOT / "work/2008-06/mined-to-native.json"
    manifest.write_text(json.dumps({"jobs": jobs}))
    print(len(jobs), "files written; compiling...", flush=True)
    subprocess.run([sys.executable, str(ROOT / "rebuild/2008-06/tests/native_check_runner.py"), "run", str(manifest)],
                   cwd=ROOT, capture_output=True, text=True)
    run = max((ROOT / "work/2008-06/native-check-runs").iterdir(), key=lambda p: p.stat().st_mtime)
    results = json.load(open(run / "results.json"))
    hits = {}
    for res in results:
        cov = res.get("coverage") or []
        hits[Path(res["source"]).name] = sum(1 for c in cov if c.get("hits"))
    kept = 0
    for dest in made:
        n = hits.get(dest.name, 0)
        print(f"{n:3d} hits  {dest.name}")
        if n == 0 and "--keep-all" not in sys.argv:
            dest.unlink(missing_ok=True)
        else:
            kept += n
    print("total range hits kept:", kept)


if __name__ == "__main__":
    main()
