"""More mass-matching methods on top of roc/fingerprint.py:

  staticlibs  Runtime code the linker copied in from the compiler's own .lib files
              (CRT startup, security cookie, delay-load helpers...). Matched straight
              from the prebuilt objects; tagged 'gen' like other compiler stubs, so it
              leaves the to-do pile instead of counting as Roblox code.
  stl         Standard containers compiled from the compiler's own headers via explicit
              instantiation, for the element types Roblox most likely used.
"""
import json
import os
import re
import struct
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

from roc import fingerprint, match, setup

ROOT = Path(__file__).resolve().parent.parent


# ---------- static libraries ----------

def ar_members(data):
    """Object files inside a .lib (ar archive). Import stubs and linker members skipped."""
    if not data.startswith(b"!<arch>\n"):
        return
    pos = 8
    while pos + 60 <= len(data):
        name = data[pos:pos + 16].strip()
        size = int(data[pos + 48:pos + 58].strip() or 0)
        body = data[pos + 60:pos + 60 + size]
        pos += 60 + size + (size & 1)
        if name in (b"/", b"//") or len(body) < 20:
            continue
        if body[:4] == b"\0\0\xff\xff":  # short import object
            continue
        if struct.unpack_from("<H", body, 0)[0] == 0x14C:  # i386 COFF
            yield body


def lib_files(build):
    cl = Path(setup.compilers()[build])
    lib = cl.parents[1] / "lib"
    return sorted(lib.glob("*.lib")) + sorted(lib.glob("*.obj")) if lib.exists() else []


def staticlibs(targets, log=print):
    """Tag functions that come from the compiler's prebuilt libraries. Returns {client: count}."""
    out = {}
    for client in targets:
        t = fingerprint.Target(client)
        build = match.clients.load()[client]["compiler_build"]
        tagged = set()
        for path in lib_files(build):
            if path.name.endswith("d.lib"):  # debug variants never ship
                continue
            data = path.read_bytes()
            objs = list(ar_members(data)) if path.suffix == ".lib" else [data]
            for obj in objs:
                try:
                    found = t.match_obj(obj, None, data_check=False)
                except (struct.error, ValueError, IndexError):
                    continue
                tagged.update(found)
        path = ROOT / "work" / client / "libmatch.json"
        old = set(json.loads(path.read_text())) if path.exists() else set()
        path.write_text(json.dumps(sorted(old | tagged)))
        out[client] = len(tagged - old)
        log("%s: %d functions come from the compiler's static libraries" % (client, len(tagged)))
    return out


# ---------- STL ----------

ELEMENTS = {
    "ptr": "struct T; typedef T* E;",
    "int": "typedef int E;",
    "uint": "typedef unsigned int E;",
    "short": "typedef short E;",
    "char": "typedef char E;",
    "float": "typedef float E;",
    "double": "typedef double E;",
    "i64": "typedef __int64 E;",
    "string": "#include <string>\ntypedef std::string E;",
    "wstring": "#include <string>\ntypedef std::wstring E;",
}
ELEMENTS.update({"pod%d" % n: "struct E { int v[%d]; };" % (n // 4) for n in (8, 12, 16, 20, 24, 28, 32, 36, 40, 48, 64)})
ELEMENTS.update({"podc%d" % n: "struct E { char v[%d]; };" % n for n in (2, 3, 5, 6, 7)})
CONTAINERS = {
    "vector": "#include <vector>\ntemplate class std::vector<E>;",
    "list": "#include <list>\ntemplate class std::list<E>;",
    "deque": "#include <deque>\ntemplate class std::deque<E>;",
    "set": "#include <set>\nbool operator<(const E&, const E&);\ntemplate class std::set<E>;",
    "map_int": "#include <map>\ntemplate class std::map<int, E>;",
    "map_ptr": "#include <map>\nstruct K; template class std::map<K*, E>;",
    "map_str": "#include <map>\n#include <string>\ntemplate class std::map<std::string, E>;",
}


def stl_units():
    for cname, cont in CONTAINERS.items():
        for ename, elem in ELEMENTS.items():
            if cname == "set" and not ename.startswith(("pod", "podc")):
                cont_text = cont.replace("bool operator<(const E&, const E&);\n", "")
            else:
                cont_text = cont
            yield "%s<%s>" % (cname, ename), "// stl: %s<%s>\n%s\n%s\n" % (cname, ename, elem, cont_text)


def _compile_unit(client, text, build):
    return match.compile_text(client, text, build=build)


def stl(targets, log=print):
    tgts = {c: fingerprint.Target(c) for c in targets}
    builds = {c: match.clients.load()[c]["compiler_build"] for c in targets}
    new = {c: 0 for c in targets}
    jobs = int(os.environ.get("ROC_JOBS") or 0) or min(12, os.cpu_count() or 4)
    for build in sorted(set(builds.values())):
        group = [c for c in targets if builds[c] == build]
        units = list(stl_units())
        # Compiles are ~0.3s each and serial here; run them concurrently and keep
        # matching/saving serial (the fingerprint index is shared state).
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            futures = {pool.submit(_compile_unit, group[0], text, build): (label, text)
                       for label, text in units}
            for future in as_completed(futures):
                label, text = futures[future]
                try:
                    obj = future.result()
                except (match.CompileError, SystemExit):
                    continue
                for c in group:
                    found = tgts[c].match_obj(obj, text)
                    if found:
                        new[c] += fingerprint.save(c, found, "standard library %s" % label)
    log("stl: new matches %s" % new)
    return new
