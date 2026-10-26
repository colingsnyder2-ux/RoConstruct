"""Phase 4 size checks: sizeof each rbxgs class (headers as rbxgs-app builds them: its overlay of patched and adopted
2008 headers, out/RbxgsApp/overlay, ahead of the rbxgs tree; run `roc rebuild 2008-06 module rbxgs-app` first)
against the allocation size the 2008 exe passes to malloc/operator new before calling its constructor
(manifests/abi-evidence.json). A mismatch means the class layout (or a base/member layout) still differs from 2008.
Read-only; writes rebuild/2008-06/out/size-check.json.
usage: python rebuild/2008-06/size_check.py"""
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import libs, match  # noqa: E402

CLIENT = "2008-06"
TREE = ROOT / "tools" / "rbxgs" / "Client" / "App"
OUT = ROOT / "rebuild" / CLIENT / "out"
OVERLAY = OUT / "RbxgsApp" / "overlay"


def header_of(cls):
    pattern = re.compile(r"^\s*class\s+%s\b[^;]*$" % re.escape(cls), re.M)
    for path in sorted((TREE / "include").rglob("*.h")):
        if pattern.search(path.read_text(errors="replace")):
            return path.relative_to(TREE / "include").as_posix()
    return None


def probe(header, classes):
    """{class: sizeof} for classes declared in header, compiled with the recipe settings over the module overlay."""
    src = ("#define private public\n#define protected public\n" + '#include "%s"\n' % header
           + "template<int N> struct ROC_SHOW;\n"
           + "".join("ROC_SHOW<(int)sizeof(RBX::%s)> roc_v%d;\n" % (c, i) for i, c in enumerate(classes)))
    r, folder = libs.RECIPES["rbxgs"], libs.fetch("rbxgs").resolve()
    include = ";".join([str(OVERLAY / "App" / "include"), str(OVERLAY / "App"), str(folder)] + [libs.winsdk_include() if i == "WINSDK" else str(libs._case_path(libs.LIBS / i))
                                        for i in r.get("include", [])])
    with match.compile_directory() as tmp:
        path = Path(tmp) / "probe.cpp"
        path.write_text(src)
        try:
            body = libs.preprocess(21022, path, include, r.get("defines", ""))
        except Exception as error:  # noqa: BLE001
            return {}, str(error)[:300]
    try:
        match._compile_uncached(body, "/O2 /GS- /EHsc /MD", 21022, False)
        return {}, "no errors"
    except Exception as error:  # noqa: BLE001
        msg = str(error)
    sizes = {}
    for i, c in enumerate(classes):
        m = re.search(r"'roc_v%d' uses undefined struct[^\[]*\[\s*N=(\d+)" % i, msg)
        if m:
            sizes[c] = int(m.group(1))
    return sizes, None if sizes else msg[:300]


def main():
    evidence = json.loads((ROOT / "rebuild" / CLIENT / "manifests" / "abi-evidence.json").read_text())
    wanted = {}
    for name, item in evidence.items():
        m = re.fullmatch(r"RBX::(\w+)", name)
        if m and len(item["alloc_sizes"]) == 1:
            wanted[m.group(1)] = int(next(iter(item["alloc_sizes"])), 16)
    by_header, missing = {}, []
    for cls in sorted(wanted):
        header = header_of(cls)
        (by_header.setdefault(header, []) if header else missing).append(cls)
    rows, errors = [], {}
    for header, classes in sorted(by_header.items()):
        sizes, error = probe(header, classes)
        if error:
            errors[header] = error
        for cls in classes:
            if cls in sizes:
                rows.append({"class": cls, "header": header, "2008": wanted[cls], "rbxgs": sizes[cls],
                             "delta": wanted[cls] - sizes[cls]})
    rows.sort(key=lambda r: (r["delta"] == 0, -abs(r["delta"]), r["class"]))
    (OUT / "size-check.json").write_text(json.dumps({"rows": rows, "no_header": missing, "probe_errors": errors}, indent=1))
    ok = sum(1 for r in rows if not r["delta"])
    print("%d classes with a 2008 allocation size: %d checked, %d match, %d differ; %d without an rbxgs header, %d probe errors"
          % (len(wanted), len(rows), ok, len(rows) - ok, len(missing), len(errors)))
    for r in rows:
        if r["delta"]:
            print("  %-28s 2008 0x%-5x rbxgs 0x%-5x %+d  %s" % (r["class"], r["2008"], r["rbxgs"], r["delta"], r["header"]))


if __name__ == "__main__":
    main()
