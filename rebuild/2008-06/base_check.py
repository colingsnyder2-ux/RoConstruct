"""Phase 4 base-offset checks: for every RBX class the 2008 RTTI describes, the offset of each non-virtual
base in the 2008 object (its BaseClassDescriptor mdisp) against the same base's offset in the rbxgs class as
rbxgs-app compiles it (module overlay ahead of the rbxgs tree; run `roc rebuild 2008-06 module rbxgs-app`
first). Offsets come from a small probe exe built and run with the period toolchain (static_cast of a fake
pointer: nothing is constructed). A mismatch locates a layout difference to a base boundary.
Read-only; writes rebuild/2008-06/out/base-check.json.
usage: python rebuild/2008-06/base_check.py"""
import json
from concurrent.futures import ThreadPoolExecutor
import re
import struct
import subprocess
import sys
import uuid
from pathlib import Path

import pefile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import clients, libs, rebuild, setup  # noqa: E402

CLIENT = "2008-06"
TREE = ROOT / "tools" / "rbxgs" / "Client" / "App"
OUT = ROOT / "rebuild" / CLIENT / "out"
OVERLAY = OUT / "RbxgsApp" / "overlay"
SIMPLE = re.compile(r"^\.\?AV(\w+)@RBX@@$")


def rtti_bases():
    """{class: [(base, mdisp)]} for RBX classes whose RTTI names and bases are plain (non-template) names."""
    exe = clients.exe_path(CLIENT, clients.load()[CLIENT])
    pe = pefile.PE(str(exe), fast_load=True)
    base, image = pe.OPTIONAL_HEADER.ImageBase, pe.get_memory_mapped_image()
    u32 = lambda va: struct.unpack_from("<I", image, va - base)[0]
    i32 = lambda va: struct.unpack_from("<i", image, va - base)[0]
    name = lambda td: image[td + 8 - base:td + 8 - base + 200].split(b"\0")[0].decode(errors="replace")
    out = {}
    for item in json.loads((ROOT / "work" / CLIENT / "vtables.json").read_text()):
        col = u32(int(item["vtable"], 16) - 4)
        if u32(col + 4):  # secondary vtable: same class as its primary
            continue
        m = SIMPLE.match(name(u32(col + 12)))
        if not m or m.group(1) in out:
            continue
        chd = u32(col + 16)
        bases = []
        for i in range(1, u32(chd + 8)):
            bcd = u32(u32(chd + 12) + 4 * i)
            b = SIMPLE.match(name(u32(bcd)))
            if b and i32(bcd + 12) == -1 and b.group(1) != m.group(1):  # pdisp -1: not reached through a vbase
                bases.append((b.group(1), i32(bcd + 8)))
        if bases:
            out[m.group(1)] = sorted(set(bases), key=lambda x: (x[1], x[0]))
    return out


def header_of(cls, cache={}):
    if not cache:
        for path in sorted((TREE / "include").rglob("*.h")):
            for c in re.findall(r"^\s*class\s+(?:__declspec\(\w+\)\s+)?(\w+)\s*:", path.read_text(errors="replace"), re.M):
                cache.setdefault(c, path.relative_to(TREE / "include").as_posix())
        for path in sorted((OVERLAY / 'App/include').rglob('*.h')):
            for c in re.findall(r'^\s*class\s+(?:__declspec\(\w+\)\s+)?(\w+)\s*:', path.read_text(errors='replace'), re.M):
                cache[c] = path.relative_to(OVERLAY / 'App/include').as_posix()
    return cache.get(cls)


def probe(header, rows, tmp, tc):
    """Offsets of each (class, base) via a probe exe; None for a header that does not compile."""
    src = ["#define private public", "#define protected public", '#include "%s"' % header, "#include <stdio.h>",
           "int main() {"]
    for i, (cls, b, _) in enumerate(rows):
        src.append('  printf("%d %%d\\n", (int)(char*)static_cast<RBX::%s*>((RBX::%s*)0x10000) - 0x10000);' % (i, b, cls))
    src.append("  return 0; }")
    (tmp / "probe.cpp").write_text("\n".join(src) + "\n")
    r = libs.RECIPES["rbxgs"]
    folder = libs.fetch("rbxgs").resolve()
    incs = [OVERLAY / "App" / "include", OVERLAY / "App", folder] + [
        Path(libs.winsdk_include()) if i == "WINSDK" else libs._case_path(libs.LIBS / i) for i in r.get("include", [])]
    args = ["/nologo", "/c", "/EHsc", "/MD", "/O2", "/GS-", "/DBOOST_ALL_NO_LIB"] + ["/D" + d for d in r.get("defines", "").split()] + \
           ["/I" + str(p) for p in incs] + ["probe.cpp"]
    code, text = rebuild.run(tc, "cl", args, tmp)
    if code:
        return None, text[-400:]
    code, text = rebuild.run(tc, "link", ["/nologo", "/SUBSYSTEM:CONSOLE", "/MACHINE:X86", "/FORCE:UNRESOLVED",
                                          "probe.obj", "kernel32.lib", "/OUT:probe.exe"], tmp)
    if not (tmp / "probe.exe").exists():
        return None, text[-400:]
    run = [str(tmp / "probe.exe")] if setup.WINDOWS else [setup.wine_exe(), str(tmp / "probe.exe")]
    try:
        done = subprocess.run(run, capture_output=True, text=True, timeout=60)
    except subprocess.TimeoutExpired:
        return None, "Probe runtime timed out after 60 seconds"
    if done.returncode:
        return None, "Probe runtime exit=%s (0x%08X): %s" % (
            done.returncode, done.returncode & 0xffffffff, (done.stdout + done.stderr)[-400:])
    try:
        offsets = {int(a): int(b) for a, b in (line.split() for line in done.stdout.splitlines() if line.strip())}
    except ValueError:
        return None, "Invalid probe output: " + done.stdout[-400:]
    if set(offsets) != set(range(len(rows))):
        return None, "Incomplete probe output: " + done.stdout[-400:]
    return offsets, None


def main():
    if setup.WINDOWS:
        import ctypes
        # Children inherit this: report crash codes instead of blocking on Windows error dialogs.
        ctypes.windll.kernel32.SetErrorMode(0x0001 | 0x0002 | 0x8000)
    tc = rebuild.toolchain()
    by_header = {}
    for cls, bases in sorted(rtti_bases().items()):
        header = header_of(cls)
        if not header:
            continue
        for b, mdisp in bases:
            if header_of(b):
                by_header.setdefault(header, []).append((cls, b, mdisp))
    rows, errors = [], {}
    tmp = OUT / "base-check"
    tmp.mkdir(parents=True, exist_ok=True)
    def check(item):
        header, items = item
        folder = tmp / uuid.uuid4().hex
        folder.mkdir()
        return probe(header, items, folder, tc)
    headers = sorted(by_header.items())
    with ThreadPoolExecutor(max_workers=4) as pool:
        for (header, items), (got, error) in zip(headers, pool.map(check, headers)):
            if got is None:
                errors[header] = error
                continue
            for i, (cls, b, mdisp) in enumerate(items):
                if i in got:
                    rows.append({"class": cls, "base": b, "2008": mdisp, "rbxgs": got[i], "header": header})
    bad = [r for r in rows if r["2008"] != r["rbxgs"]]
    (OUT / "base-check.json").write_text(json.dumps({"mismatch": bad, "checked": len(rows), "probe_errors": errors}, indent=1))
    print("%d base offsets checked, %d differ, %d headers did not probe" % (len(rows), len(bad), len(errors)))
    for r in bad:
        print("  %-26s %-24s 2008 0x%-4x rbxgs 0x%-4x %s" % (r["class"], r["base"], r["2008"], r["rbxgs"], r["header"]))


if __name__ == "__main__":
    main()
