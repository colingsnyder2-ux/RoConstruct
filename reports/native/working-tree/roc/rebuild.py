"""2008-06 client rebuild: toolchain, audit, whole-file builds, TU diffs and links.

Separate from mining: nothing here edits src/, clients/, tools/ or bounds.json.
Outputs go to rebuild/<client>/ (manifests/ and out/ stay untracked until
rebuild/<client>/POLICY.md allows publishing them).
"""
import json
import hashlib
import functools
import os
import re
import subprocess
from pathlib import Path

from roc import match, setup

ROOT = Path(__file__).resolve().parent.parent
TOOLS = ROOT / "tools"
DOCS = ROOT / "docs"
BUILD = 21022  # the 2008-06 client's compiler (VS2008 RTM)


def workspace(client):
    path = ROOT / "rebuild" / client
    (path / "out").mkdir(parents=True, exist_ok=True)
    return path



def _ml():
    """The VS2008-era MASM used for small assembly stubs."""
    candidates = [
        ROOT / "tools" / "vc2008sp1" / "Microsoft" / "Visual C++ for Python" / "9.0" / "VC" / "bin" / "ml.exe",
        ROOT / "tools" / "vc2008rtm" / "Program Files" / "Microsoft Visual Studio 9.0" / "VC" / "bin" / "ml.exe",
    ]
    for candidate in candidates:
        if candidate.exists():
            return candidate
    found = next((p for p in (ROOT / "tools").rglob("ml.exe")), None)
    if found is None:
        raise RuntimeError("ml.exe not found")
    return found


def _first(*candidates):
    for c in candidates:
        if c and Path(c).exists():
            return Path(c)
    return None


def _ci(folder, name):
    """Case-insensitive child lookup (the SDK ships Kernel32.Lib)."""
    if not folder or not folder.is_dir():
        return None
    low = name.lower()
    return next((p for p in folder.iterdir() if p.name.lower() == low), None)


@functools.lru_cache(maxsize=8)
def sdk_roots(tools):
    """Discover installed SDKs once per tools tree, not once per compile batch."""
    return tuple(sorted(tools.glob("*/**/WinSDK")))


def toolchain(build=BUILD):
    """Paths for one period toolchain; None where a piece is missing. Never substitutes a newer build."""
    cl = setup.compilers().get(build)
    cl = Path(cl) if cl else None
    vc = cl.parents[1] if cl else None
    ide = cl.parents[2] / "Common7" / "IDE" if cl else None
    candidates = [Path(p) for p in os.environ.get("ROC_WINSDK", "").split(os.pathsep) if p]
    sdk = next((r for r in candidates if _ci(r / "Lib", "kernel32.lib")), None)
    if sdk is None:
        sdk = next((r for r in sdk_roots(TOOLS) if _ci(r / "Lib", "kernel32.lib")), None)
    atlmfc = _first(os.environ.get("ROC_ATLMFC"), TOOLS / "libs" / "mfc-9.0-rtm" / "atlmfc")
    return {
        "build": build,
        "cl": cl,
        "link": _first(vc / "bin" / "link.exe") if vc else None,
        "lib": _first(vc / "bin" / "lib.exe") if vc else None,
        "mspdb": _first(ide / "mspdb80.dll") if ide else None,
        "vc_include": _first(vc / "include") if vc else None,
        "vc_lib": _first(vc / "lib") if vc else None,
        "crt": _first(vc / "lib" / "msvcrt.lib") if vc else None,
        "sdk_include": _first(sdk / "Include") if sdk else None,
        "sdk_lib": _first(sdk / "Lib") if sdk else None,
        "rc": _ci(sdk / "Bin", "rc.exe") if sdk else None,
        "atlmfc_include": _first(atlmfc / "include") if atlmfc else None,
        "atlmfc_lib": _first(atlmfc / "lib") if atlmfc else None,
        "atls": _first(atlmfc / "lib" / "atls.lib") if atlmfc else None,
        "mfcs90": _first(atlmfc / "lib" / "mfcs90.lib") if atlmfc else None,
    }


def env(tc):
    """Process environment for cl/link/lib with the VC, SDK and ATL/MFC include and lib paths."""
    e = setup.cl_env(tc["cl"])
    e["INCLUDE"] = ";".join(str(p) for p in (tc["vc_include"], tc["atlmfc_include"], tc["sdk_include"]) if p)
    e["LIB"] = ";".join(str(p) for p in (tc["vc_lib"], tc["atlmfc_lib"], tc["sdk_lib"]) if p)
    return e


def run(tc, tool, args, cwd, timeout=600):
    """Run cl/link/lib (or a tool path such as ml.exe); returns (returncode, combined output)."""
    exe = tc[tool] if isinstance(tool, str) and tool in tc else Path(tool)
    cmd = setup.cl_command(exe) + [str(a) for a in args]  # Wine on Linux
    done = subprocess.run(cmd, cwd=cwd, env=env(tc), capture_output=True, text=True, errors="replace", timeout=timeout)
    return done.returncode, (done.stdout + done.stderr).strip()


REQUIRED = ("cl", "link", "lib", "mspdb", "vc_include", "crt", "sdk_include", "sdk_lib")


def doctor(client="2008-06", log=print):
    tc = toolchain()
    for key, value in tc.items():
        if key == "build":
            continue
        log("[%s] %-15s %s" % ("ok  " if value else ("MISS" if key in REQUIRED else "opt "), key, value or "-"))
    missing = [k for k in REQUIRED if not tc[k]]
    if missing:
        log("Missing required pieces: " + ", ".join(missing))
        return False
    ok, text = smoke(client, tc)
    log(("[ok  ] smoke exe runs: %s" if ok else "[FAIL] smoke: %s") % text)
    return ok


SMOKE = r"""#include <windows.h>
#include <stdio.h>
int main()
{
    OSVERSIONINFOA info = { sizeof(info) };
    GetVersionExA(&info);
    printf("rebuild-smoke %d\n", _MSC_FULL_VER);
    return info.dwMajorVersion > 0 ? 0 : 1;
}
"""


def smoke(client, tc=None):
    """Compile and link a tiny PE32 console exe with the period toolchain, then run it."""
    tc = tc or toolchain()
    out = workspace(client) / "out" / "smoke"
    out.mkdir(parents=True, exist_ok=True)
    (out / "smoke.cpp").write_text(SMOKE)
    code, text = run(tc, "cl", ["/nologo", "/O2", "/MD", "/EHsc", "/c", "smoke.cpp"], out)
    if code:
        return False, "compile failed: " + text[-400:]
    code, text = run(tc, "link", ["/nologo", "/SUBSYSTEM:CONSOLE", "/MACHINE:X86", "smoke.obj", "kernel32.lib",
                                  "/OUT:smoke.exe", "/MAP:smoke.map"], out)
    if code:
        return False, "link failed: " + text[-400:]
    try:
        done = subprocess.run([str(out / "smoke.exe")] if setup.WINDOWS else [setup.wine_exe(), str(out / "smoke.exe")],
                              capture_output=True, text=True, timeout=60)
    except OSError as error:
        return False, "run failed: %s (the VC90 CRT msvcr90.dll must be loadable)" % error
    return done.returncode == 0 and "rebuild-smoke 1500" in done.stdout, done.stdout.strip() or done.stderr.strip()


# ---------- Phase 2: read-only audit ----------

def _source_kind(source):
    lib = match.directives(source or "").get("lib", "")
    recipe, _, rel = lib.partition(" ")
    rel = rel.strip().replace("\\", "/")
    if not recipe:
        return ("snippet" if source else "none"), None, None
    return ("generated-unit" if rel.rsplit("/", 1)[-1].startswith("roc_") else "vendor-file"), recipe, rel


def _dump(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(data, indent=1, sort_keys=True) + "\n", encoding="utf-8")


def audit(client="2008-06", rows=None, log=print):
    """Write manifests/{original-pe,functions,tu-coverage}.json. rows: [{addr, score, source}] (server sources)."""
    import hashlib
    import pefile
    from roc import clients, worker
    entry = clients.load()[client]
    exe = clients.exe_path(client, entry)
    pe = pefile.PE(str(exe))
    out = workspace(client) / "manifests"
    imports = {}
    for d in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
        imports[d.dll.decode()] = sorted((i.name.decode() if i.name else "#%d" % i.ordinal) for i in d.imports)
    _dump(out / "original-pe.json", {
        "sha256": hashlib.sha256(Path(exe).read_bytes()).hexdigest(),
        "image_base": "%08x" % pe.OPTIONAL_HEADER.ImageBase,
        "entry_point": "%08x" % (pe.OPTIONAL_HEADER.ImageBase + pe.OPTIONAL_HEADER.AddressOfEntryPoint),
        "sections": [{"name": s.Name.rstrip(b"\0").decode(), "va": "%08x" % (pe.OPTIONAL_HEADER.ImageBase + s.VirtualAddress),
                      "size": s.Misc_VirtualSize} for s in pe.sections],
        "imports": imports,
        "tls": hasattr(pe, "DIRECTORY_ENTRY_TLS"),
    })
    if rows is None:
        s = worker.load_settings()
        api = worker.Api(s["server"], s.get("token"))
        try:
            rows = api.call("/v1/sources?client=" + client, timeout=300)
        finally:
            api.close()
    by_addr = {r["addr"]: r for r in rows}
    functions, files = [], {}
    for addr, f in sorted(match._functions(client).items()):
        if f.get("kind", "code") != "code":
            continue
        row = by_addr.get(addr, {})
        source = row.get("source") or ""
        kind, recipe, rel = _source_kind(source)
        d = match.directives(source)
        functions.append({"addr": addr, "size": f["size"], "unit": f.get("unit"), "score": row.get("score", 0),
                          "source_kind": kind, "recipe": recipe, "file": rel, "cl": d.get("cl"), "flags": d.get("flags")})
        if recipe:
            tu = files.setdefault("%s|%s" % (recipe, rel), {"recipe": recipe, "file": rel, "kind": kind,
                                                              "exact": [], "open": [], "flags": set(), "cl": set()})
            tu["exact" if row.get("score") == 100 else "open"].append(addr)
            tu["flags"].add(d.get("flags") or "")
            tu["cl"].add(d.get("cl") or "")
    coverage = []
    for tu in files.values():
        tu.update(flags=sorted(tu["flags"]), cl=sorted(tu["cl"]), exact_count=len(tu["exact"]), open_count=len(tu["open"]))
        coverage.append(tu)
    coverage.sort(key=lambda t: (-t["exact_count"], t["open_count"], t["file"]))
    _dump(out / "functions.json", functions)
    _dump(out / "tu-coverage.json", coverage)
    kinds = {}
    for f in functions:
        key = (f["source_kind"], f["score"] == 100)
        kinds[key] = kinds.get(key, 0) + 1
    log("%s: %d code functions; %s" % (client, len(functions), ", ".join(
        "%s %s=%d" % (k, "exact" if e else "open", n) for (k, e), n in sorted(kinds.items()))))
    log("%d source files/units referenced; manifests in %s" % (len(coverage), out))
    abi_evidence(client, log=log)
    return coverage


def abi_evidence(client="2008-06", log=print):
    """Write manifests/abi-evidence.json from the original exe alone: per vtable class (work/<client>/vtables.json),
    the functions that store its vtables and at which `this` offsets (constructors/destructors: subobject layout),
    the vbtables those functions store, and the allocation sizes passed to malloc/operator new right before a call
    to one of those functions. Every entry is an observation of the binary (confidence "observed")."""
    import struct
    import pefile
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    from capstone.x86_const import X86_OP_IMM, X86_OP_MEM
    from roc import clients
    exe = clients.exe_path(client, clients.load()[client])
    pe = pefile.PE(str(exe))
    base = pe.OPTIONAL_HEADER.ImageBase
    image = pe.get_memory_mapped_image()
    vtables = json.loads((ROOT / "work" / client / "vtables.json").read_text())
    owner = {int(v["vtable"], 16): v["class"] for v in vtables}
    allocators = {i.address for d in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []) for i in d.imports
                  if i.name in (b"malloc", b"??2@YAPAXI@Z")}
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    stores, vbtables, calls = {}, {}, []  # fn -> [(off, vt)], vbtable addr -> entries, (caller, size, callee)
    for addr, f in sorted(match._functions(client).items()):
        if f.get("kind", "code") != "code":
            continue
        start = int(addr, 16)
        pending = None  # size pushed for an allocation, until the allocation's result is passed to a call
        last_push, allocated = None, None
        for ins in md.disasm(image[start - base:start - base + f["size"]], start):
            ops = ins.operands
            if ins.mnemonic == "mov" and len(ops) == 2 and ops[0].type == X86_OP_MEM and ops[1].type == X86_OP_IMM \
                    and ops[0].size == 4:
                imm = ops[1].imm & 0xffffffff
                if imm in owner:
                    stores.setdefault(start, []).append((ops[0].mem.disp, imm, ins.reg_name(ops[0].mem.base) if ops[0].mem.base else ""))
                elif base <= imm < base + len(image) - 16 and ops[0].mem.index == 0:
                    first = struct.unpack_from("<i", image, imm - base)[0]
                    if first == -ops[0].mem.disp and first <= 0:
                        entries = list(struct.unpack_from("<4i", image, imm - base))
                        n = 1
                        while n < len(entries) and 0 < entries[n] < 0x10000:
                            n += 1
                        vbtables.setdefault(imm, {"fn": set(), "at": ops[0].mem.disp, "entries": entries[:n]})["fn"].add(start)
            elif ins.mnemonic == "push" and ops and ops[0].type == X86_OP_IMM:
                last_push = ops[0].imm & 0xffffffff
            elif ins.mnemonic == "call" and ops:
                target = ops[0].imm if ops[0].type == X86_OP_IMM else (
                    ops[0].mem.disp & 0xffffffff if ops[0].type == X86_OP_MEM and not ops[0].mem.base else None)
                if target in allocators and last_push is not None:
                    allocated = last_push
                elif allocated is not None and ops[0].type == X86_OP_IMM:
                    calls.append((start, allocated, target))
                    allocated = None
                last_push = None
    classes = {}
    for fn, items in stores.items():
        for off, vt, reg in items:
            c = classes.setdefault(owner[vt], {"vtables": set(), "vptr_stores": {}, "alloc_sizes": {}, "vbtables": {}})
            c["vtables"].add("%08x" % vt)
            c["vptr_stores"].setdefault("%08x" % fn, set()).add((reg, off, "%08x" % vt))
    for vb, item in vbtables.items():
        for fn in item["fn"]:
            for vt in {vt for _, vt, _ in stores.get(fn, [])}:
                classes[owner[vt]]["vbtables"]["%08x" % vb] = {"at": item["at"], "entries": item["entries"]}
    for caller, size, callee in calls:
        # the allocated object is the callee's `this`: the base register most of its vptr stores go through
        # (an inlined `new` of another class inside the constructor stores through another register)
        regs = [reg for _, _, reg in stores.get(callee, [])]
        this = max(sorted(set(regs)), key=regs.count) if regs else None
        for vt in {vt for off, vt, reg in stores.get(callee, []) if off == 0 and reg == this}:
            classes[owner[vt]]["alloc_sizes"].setdefault("0x%x" % size, set()).add("%08x" % caller)
    out = {}
    for name, c in sorted(classes.items()):
        out[name] = {"confidence": "observed", "vtables": sorted(c["vtables"]),
                     "vptr_stores": {fn: [["[%s+0x%x]" % (reg, off), vt] for reg, off, vt in sorted(v)] for fn, v in sorted(c["vptr_stores"].items())},
                     "alloc_sizes": {s: sorted(v) for s, v in sorted(c["alloc_sizes"].items())},
                     "vbtables": dict(sorted(c["vbtables"].items()))}
    _dump(workspace(client) / "manifests" / "abi-evidence.json", out)
    log("%s: abi evidence for %d vtable classes (%d with allocation sizes, %d with vbtables)"
        % (client, len(out), sum(1 for c in out.values() if c["alloc_sizes"]), sum(1 for c in out.values() if c["vbtables"])))
    return out


# ---------- Phase 3: whole-file build + TU diff ----------

def tu_source(recipe, rel, cl=BUILD, flags="/O2 /Ob2 /Oy /GF /GS- /EHsc /MD"):
    """The mining wrapper that compiles one authentic file whole, exactly as its exacts were verified."""
    return "// roc-cl: %s\n// roc-flags: %s\n// roc-lib: %s %s\n" % (cl, flags, recipe, rel)


def tu_diff(client, tu, log=print):
    """Compile one coverage row's file whole; pair each object function with the 2008 address it matches.
    Returns {obj, functions: [{symbol, size, addr|None, status}], exact, total}."""
    flags = tu["flags"][0] if tu["flags"] and tu["flags"][0] else "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD"
    cl = int(tu["cl"][0]) if tu["cl"] and tu["cl"][0] else BUILD
    obj = match.compile_text(client, tu_source(tu["recipe"], tu["file"], cl, flags))
    funcs = match.coff_functions(obj)
    targets = {}
    for addr in tu["exact"] + tu["open"]:
        code, relocs, _ = match.target(client, addr)
        targets[addr] = (code, relocs)
    rows, owned, generic = [], set(), set()
    for name, body, relocs in funcs:
        hits = [a for a, (code, trel) in targets.items()
                if len(code) == len(body) and match.exact_match(code, trel, body, relocs)]
        status = "owned" if len(hits) == 1 else ("generic-shape" if hits else "not-in-2008-or-differs")
        (owned if len(hits) == 1 else generic).update(hits)
        rows.append({"symbol": name, "size": len(body), "addrs": hits, "status": status})
    generic -= owned
    missing = sorted(set(targets) - owned - generic)
    report = {"recipe": tu["recipe"], "file": tu["file"], "cl": cl, "flags": flags, "functions": rows,
              "owned": sorted(owned), "generic_shape_addrs": sorted(generic), "unpaired_targets": missing,
              "object_functions": len(funcs)}
    log("%s %s: %d object functions; %d 2008 addresses owned 1:1, %d only via a generic shape, %d unpaired"
        % (tu["recipe"], tu["file"], len(funcs), len(owned), len(generic), len(missing)))
    return obj, report


_INDEX = {}


def size_index(client):
    """{size: [(addr, code, relocs)]} over every code function of the client (built once per process)."""
    if client not in _INDEX:
        _paired_addresses.cache_clear()
        idx = {}
        for addr, f in match._functions(client).items():
            if f.get("kind", "code") == "code":
                code, relocs, _ = match.target(client, addr)
                idx.setdefault(len(code), []).append((addr, code, relocs))
        _INDEX[client] = idx
    return _INDEX[client]


@functools.lru_cache(maxsize=16384)
def _paired_addresses(client, body, relocs):
    """Template bodies recur across TUs; cache immutable matches, including twins."""
    return tuple(a for a, code, trel in _INDEX[client].get(len(body), ())
                 if match.exact_match(code, trel, body, relocs))


def pair(client, funcs):
    """[(symbol, size, [2008 addrs whose masked bytes equal it])] against the whole binary."""
    size_index(client)
    return [(name, len(body), list(_paired_addresses(client, body, tuple(relocs))))
            for name, body, relocs in funcs]


def build_library(client, recipe, files, flags, name, cl=BUILD, jobs=6, log=print):
    """Compile each authentic file whole into out/<name>/, archive <name>.lib, and write <name>.tudiff.json."""
    import concurrent.futures as cf
    out = workspace(client) / "out" / name
    out.mkdir(parents=True, exist_ok=True)

    from roc import libs

    def one(rel):
        try:
            obj = match.compile_text(client, libs.source_for(recipe, rel, None, cl, flags))
        except match.CompileError as error:
            return rel, None, str(error)[:300]
        path = out / (Path(rel).stem + ".obj")
        path.write_bytes(obj)
        return rel, path, None

    with cf.ThreadPoolExecutor(jobs) as pool:
        built = list(pool.map(one, files))
    objs = [p for _, p, e in built if p]
    errors = {rel: e for rel, _, e in built if e}
    tc = toolchain(cl)
    lib_name = Path(name).name + ".lib"
    code, text = run(tc, "lib", ["/nologo", "/OUT:" + lib_name] + [p.name for p in objs], out)
    report = {"recipe": recipe, "flags": flags, "cl": cl, "files": {}, "compile_errors": errors,
              "lib": str(out / lib_name) if code == 0 else None, "lib_output": text[-500:]}
    owned_total = generic_total = 0
    for rel, path, err in built:
        if not path:
            continue
        rows = pair(client, match.coff_functions(path.read_bytes()))
        owned = sorted({a for _, _, hits in rows if len(hits) == 1 for a in hits})
        generic = sorted({a for _, _, hits in rows if len(hits) > 1 for a in hits} - set(owned))
        owned_total += len(owned)
        generic_total += len(generic)
        report["files"][rel] = {"object_functions": len(rows), "owned": owned, "generic_shape": generic,
                                "symbols": [{"symbol": s, "size": n, "addrs": h} for s, n, h in rows]}
    report.update(owned=owned_total, generic=generic_total)
    _dump(out / (Path(name).name + ".tudiff.json"), report)
    log("%s: %d/%d files compiled, lib %s; %d 2008 functions owned 1:1, %d via generic shapes"
        % (name, len(objs), len(files), "ok" if report["lib"] else "FAILED", owned_total, generic_total))
    return report


def unresolved_symbols(text):
    """Decorated names from LNK2001/LNK2019 lines (C++: the parenthesised name after the quoted one; C: bare)."""
    return [a or b for a, b in re.findall(r'unresolved external symbol (?:"[^"]*" \((\?[^)]+)\)|(_\w+))', text)]


# #pragma comment(lib) names vendor headers ask for; rebuilt modules supply that code instead
VENDOR_AUTOLINK = ("zlib.lib", "G3D.lib", "GLG3D.lib", "sdl.lib", "sdlmain.lib", "glut32.lib", "ToolkitPro1122vc90DS.lib",
                   "ToolkitPro1122vc90S.lib", "ToolkitPro1122vc90LDS.lib")


def link_test(client, test, libs, includes=(), defines="WIN32 NDEBUG _MBCS _CRT_SECURE_NO_WARNINGS", flags="/O2 /GS- /EHsc /MD",
              system_libs=("kernel32.lib", "user32.lib", "gdi32.lib", "advapi32.lib", "shell32.lib", "ole32.lib",
                           "oleaut32.lib", "comdlg32.lib", "ws2_32.lib", "winmm.lib", "opengl32.lib", "glu32.lib"), cl=BUILD, run_args=()):
    """Compile tests/<test>.cpp, link it against rebuilt libs with the period linker, run it.
    Returns dict(compiled, linked, ran, exit, output, unresolved, map)."""
    tc = toolchain(cl)
    ws = workspace(client)
    out = ws / "out" / "tests" / test
    out.mkdir(parents=True, exist_ok=True)
    src = ws / "tests" / (test + ".cpp")
    args = ["/nologo", "/c"] + flags.split() + ["/D" + d for d in defines.split()] + ["/I" + str(i) for i in includes]
    code, text = run(tc, "cl", args + ["/Fo" + test + ".obj", str(src)], out)
    result = {"compiled": code == 0, "linked": False, "ran": False, "exit": None, "output": text[-1500:], "unresolved": []}
    if code:
        return result
    code, text = run(tc, "link", ["/nologo", "/SUBSYSTEM:CONSOLE", "/MACHINE:X86", "/MAP:%s.map" % test,
                                  "/OUT:%s.exe" % test, test + ".obj"] + [str(l) for l in libs] + list(system_libs)
                       + ["imagehlp.lib", "version.lib", "wininet.lib", "dbghelp.lib", "psapi.lib"] + ["/NODEFAULTLIB:" + l for l in VENDOR_AUTOLINK], out)
    result["unresolved"] = sorted(set(unresolved_symbols(text)))
    result["duplicates"] = sorted(set(re.findall(r"\((\?[^)]+)\) already defined in", text)))
    result["referencers"] = sorted(set(a or b for a, b in re.findall(r'referenced in function (?:"[^"]*" \((\?[^)]+)\)|(_\w+))', text)))
    result.update(linked=code == 0, output=text[-1500:], map=str(out / (test + ".map")))
    if code:
        return result
    done = subprocess.run([str(out / (test + ".exe"))] + list(run_args), capture_output=True, text=True, timeout=300)
    result.update(ran=True, exit=done.returncode, output=(done.stdout + done.stderr).strip()[-1500:])
    return result


def defined_symbols(obj_path):
    return {name for name, _, _ in match.coff_functions(Path(obj_path).read_bytes())}


def coff_externals(data):
    """{name: defined} for the external (class 2) symbols of a COFF object."""
    import struct
    _, _, _, symptr, nsym, _, _ = struct.unpack_from("<HHIIIHH", data, 0)
    strtab, out, i = symptr + nsym * 18, {}, 0
    while i < nsym:
        raw, _, secnum, _, cls, naux = struct.unpack_from("<8sIhHBB", data, symptr + 18 * i)
        if cls == 2:
            name = data[strtab + struct.unpack_from("<I", raw, 4)[0]:].split(b"\0", 1)[0] if raw[:4] == b"\0\0\0\0" \
                else raw.rstrip(b"\0")
            name = name.decode("latin-1")
            out[name] = out.get(name, False) or secnum > 0
        i += 1 + naux
    return out


def strip_symbols(data, keep=None, drop=()):
    """COFF rewrite for per-function swaps. Each external definition that is dropped (named in drop, or, with
    keep given, not named in keep) becomes an undefined external, so references resolve to the definition
    another object supplies; a COMDAT section keyed by it, and its associative sections, are removed. With
    keep given, static-initializer sections (.CRT$X*) are removed too: the kept object must not construct
    globals another object owns."""
    import struct
    data = bytearray(data)
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from("<HHIIIHH", data, 0)
    strtab = symptr + nsym * 18
    sec_at = lambda i: 20 + optsz + 40 * i  # noqa: E731
    remove, comdat_key, assoc, shared, twins, i = set(), {}, [], set(), {}, 0
    while i < nsym:
        at = symptr + 18 * i
        raw, value, secnum, typ, cls, naux = struct.unpack_from("<8sIhHBB", data, at)
        if cls == 3 and naux and secnum > 0 and value == 0:  # section symbol: aux holds COMDAT selection
            number, selection = struct.unpack_from("<HB", data, at + 18 + 12)
            if selection == 5:
                assoc.append((secnum, number))
            elif struct.unpack_from("<I", data, sec_at(secnum - 1) + 36)[0] & 0x1000:
                comdat_key.setdefault(secnum, None)
                if selection != 1:
                    shared.add(secnum)  # any/same-size/largest: duplicates link fine, keep (e.g. string literals)
        elif cls == 2 and secnum > 0:
            name = bytes(data[strtab + struct.unpack_from("<I", raw, 4)[0]:].split(b"\0", 1)[0]) \
                if raw[:4] == b"\0\0\0\0" else raw.rstrip(b"\0")
            name = name.decode("latin-1")
            if secnum in comdat_key and comdat_key[secnum] is None:
                comdat_key[secnum] = name
            if (keep is not None and name not in keep and secnum not in shared) or name in drop:
                if comdat_key.get(secnum) == name:
                    # a COMDAT section needs its key symbol: keep it, local, on the removed section, and
                    # point references at an appended undefined external of the same name
                    remove.add(secnum)
                    data[at + 16] = 3
                    twins[i] = bytes(raw) + struct.pack("<IhHBB", 0, 0, typ, 2, 0)
                else:
                    struct.pack_into("<Ih", data, at + 8, 0, 0)
        i += 1 + naux
    if keep is not None:
        for s in range(1, nsec + 1):
            if bytes(data[sec_at(s - 1):sec_at(s - 1) + 8]).startswith(b".CRT$X"):
                remove.add(s)
    for child, parent in assoc:
        if parent in remove:
            remove.add(child)
    for s in remove:
        flags = struct.unpack_from("<I", data, sec_at(s - 1) + 36)[0]
        struct.pack_into("<I", data, sec_at(s - 1) + 36, flags | 0x800)  # IMAGE_SCN_LNK_REMOVE
    if twins:
        index = {old: nsym + n for n, old in enumerate(sorted(twins))}
        for s in range(nsec):
            relptr, nrel = struct.unpack_from("<I", data, sec_at(s) + 24)[0], struct.unpack_from("<H", data, sec_at(s) + 32)[0]
            for k in range(nrel):
                old = struct.unpack_from("<I", data, relptr + 10 * k + 4)[0]
                if old in index:
                    struct.pack_into("<I", data, relptr + 10 * k + 4, index[old])
        struct.pack_into("<I", data, 12, nsym + len(twins))
        data[strtab:strtab] = b"".join(twins[old] for old in sorted(twins))  # symbols precede the string table
    return bytes(data)


def verified_layer(client, spec, log=print, exclude=frozenset(), vdrop=frozenset(), helpers=None, sinks=()):
    """out/<Module>/verified (rebuild/2008-06/swap_build.py) as a preferred layer of kept symbols only, and the
    set of those symbols, to drop from every other object. A symbol kept by several groups is taken once.
    helpers: {symbol: obj} non-exact helpers a swapped function calls that no other object defines, kept in that one
    object (not counted, not dropped elsewhere).
    sinks: symbols only dead bodies left in verified .text sections still name (their own symbols were stripped, so
    nothing calls them); a small MASM object defines each as an int 3 trap so those objects can link."""
    folder = workspace(client) / "out" / spec["name"] / "verified"
    if not spec.get("verified") or not (folder / "swaps.json").exists():
        return None, set()
    layer = workspace(client) / "out" / spec["name"] / "layer-verified"
    layer.mkdir(parents=True, exist_ok=True)
    for old in layer.glob("*.obj"):
        old.unlink()
    taken = set()
    for item in json.loads((folder / "swaps.json").read_text())["swaps"]:
        keep = {k for k in item["keep"] if not k.startswith(("??__E", "??__F"))} - taken - exclude - vdrop  # initializers never run here
        if keep:
            taken |= keep
            extra = {h for h, o in (helpers or {}).items() if o == item["obj"]} - vdrop
            (layer / ("verified_" + item["obj"])).write_bytes(strip_symbols((folder / item["obj"]).read_bytes(), keep=keep | extra, drop=vdrop))
    sinks = sorted(s for s in sinks if len(s) < 240)
    if sinks:
        src = layer / "verified_sinks.asm"
        src.write_text(".386\n.model flat\noption casemap:none\n.code\n"
                       + "".join("PUBLIC %s\n%s:\n" % (s, s) for s in sinks) + "\tint 3\nEND\n")
        code, text = run(toolchain(), _ml(), ["/nologo", "/c", "/Fo" + str(layer / "verified_sinks.obj"), str(src)], layer)
        if code:
            log("verified: sink object failed: " + text[-300:])
    log("verified layer: %d exact symbols swapped in" % len(taken))
    return layer, taken


def resolve_objects(client, test, layers, name, includes=(), max_rounds=20, log=print, extra_libs=(), defines=None,
                    drop=frozenset()):
    """layers: [dir, ...] most-preferred first (e.g. 2008-verified partial files, then complete upstream).
    Start from each file's most-preferred object; when the link reports an unresolved symbol, switch the
    file that defines it in a later layer to that layer. Returns the final link_test result plus choices."""
    out = workspace(client) / "out" / name
    files = {}
    for rank, layer in enumerate(layers):
        for obj in sorted(Path(layer).glob("*.obj")):
            if not obj.name.startswith("roc_"):
                files.setdefault(obj.name, []).append((rank, obj))
    choice = {f: opts[0] for f, opts in files.items()}
    symbols = {(f, rank): defined_symbols(o) for f, opts in files.items() for rank, o in opts}
    tc = toolchain()
    for round_ in range(max_rounds):
        if out.exists():
            for old in out.glob("*.obj"):
                old.unlink()
        out.mkdir(parents=True, exist_ok=True)
        for f, (rank, obj) in choice.items():
            data = obj.read_bytes()
            (out / f).write_bytes(strip_symbols(data, drop=drop) if drop and not f.startswith("verified_") else data)
        lib_name = Path(name).name + ".lib"
        code, text = run(tc, "lib", ["/nologo", "/OUT:" + lib_name] + sorted(choice), out)
        kwargs = {"defines": defines} if defines else {}
        result = link_test(client, test, [out / lib_name] + list(extra_libs), includes=includes, **kwargs)
        result["choices"] = {f: layers[rank] and str(Path(layers[rank]).name) for f, (rank, _) in choice.items()}
        missing = result["unresolved"]  # full list, not the truncated output
        if result["linked"] or not missing:
            return result
        switched = False
        for sym in missing:
            for f, opts in files.items():
                current = choice[f][0]
                later = next(((r, o) for r, o in opts if r > current and sym in symbols[(f, r)]), None)
                if later:
                    log("round %d: %s needs %s -> use %s from layer %d" % (round_ + 1, f, sym[:60], f, later[0]))
                    choice[f] = later
                    switched = True
                    break
        if not switched:
            log("unresolved with no later definition: " + ", ".join(m[:70] for m in missing))
            return result
    return result


def _twin(path, overlay):
    """The overlay copy a file under the overlay root would have (a non-existent path when it is outside)."""
    root, ov = overlay
    try:
        return Path(ov) / Path(path).resolve().relative_to(Path(root).resolve())
    except ValueError:
        return Path(ov) / "-outside-"


def compile_direct(client, sources, out_dir, includes, defines, flags="/O2 /GS- /EHsc /MD", cl=BUILD, append=None,
                   overlay=None):
    """Plain whole-file cl /c build (no mining wrapper): header search order is the ABI choice.
    append: a header included after each source, e.g. template bodies a tree declares but never defines."""
    tc = toolchain(cl)
    out = Path(out_dir)
    out.mkdir(parents=True, exist_ok=True)
    includes, compiled = _overlaid(includes, sources, overlay)
    @functools.lru_cache(maxsize=None)
    def cache_path(path):
        path = Path(os.path.abspath(path))
        return path.relative_to(ROOT).as_posix() if path.is_relative_to(ROOT) else str(path)

    @functools.lru_cache(maxsize=None)
    def content(path):
        with Path(path).open("rb") as stream:
            return hashlib.file_digest(stream, "sha256").hexdigest()

    @functools.lru_cache(maxsize=None)
    def inventory(folder):
        # New files can shadow previously resolved includes without changing them.
        names = []
        for root, dirs, files in os.walk(folder):
            dirs[:] = [d for d in dirs if d != "_wrap"]
            prefix = os.path.relpath(root, folder)
            names.extend(os.path.join(prefix, name) for name in files
                         if not name.endswith((".obj", ".deps", ".compile.json")))
        return hashlib.sha256("\0".join(sorted(names)).encode()).hexdigest()

    compiler_files = []
    if tc.get("cl"):
        compiler_files = sorted(p for p in Path(tc["cl"]).parent.iterdir()
                                if p.suffix.lower() in (".exe", ".dll"))
    if tc.get("mspdb"):
        compiler_files.append(Path(tc["mspdb"]))
    config = [client, cl, flags, defines, cache_path(append) if append else None,
              {k: cache_path(v) if isinstance(v, Path) else v for k, v in tc.items()},
              [(cache_path(p), content(p)) for p in compiler_files],
              [os.environ.get(k, "") for k in ("CL", "_CL_")]]

    def signature(orig, src, deps):
        files = sorted(set([Path(orig), src] + ([Path(append)] if append else []) + list(map(Path, deps))))
        dirs = [src.parent, Path(orig).parent] + list(includes) + [
            tc[k] for k in ("vc_include", "atlmfc_include", "sdk_include") if tc.get(k)]
        dirs += sorted({p.parent for p in files} - set(map(Path, dirs)))
        payload = [config, [(cache_path(p), content(p)) for p in files],
                   [(cache_path(p), inventory(p)) for p in dirs]]
        return hashlib.sha256(json.dumps(payload, sort_keys=True).encode()).hexdigest()

    def compile_one(pair):
        orig, src = pair
        src = Path(src)
        obj = out / (src.stem + ".obj")
        deps_file = obj.with_suffix(".deps")
        cache_file = obj.with_suffix(".compile.json")
        if obj.exists() and deps_file.exists() and cache_file.exists() and src.suffix.lower() != ".asm":
            deps = json.loads(deps_file.read_text())
            # a header that gained an overlay twin since this object was built is shadowed now: rebuild
            shadowed = overlay and any(_twin(d, overlay).exists() for d in deps)
            if not shadowed and all(Path(d).exists() for d in deps):
                saved = json.loads(cache_file.read_text())
                if saved == {"inputs": signature(orig, src, deps), "object": content(obj)}:
                    return str(orig), (True, "content cache hit")
        obj.unlink(missing_ok=True)  # a failed compile must not leave a stale object
        cache_file.unlink(missing_ok=True)
        if src.suffix.lower() == ".asm":
            code, text = run(tc, _ml(), ["/nologo", "/c", "/Fo" + str(obj), str(src)], out)
            return str(orig), (code == 0, text[-400:])
        unit = src
        if append:
            unit = out / "_wrap" / (src.stem + ".cpp")
            unit.parent.mkdir(exist_ok=True)
            unit.write_text('#include "%s"\n#include "%s"\n' % (src.as_posix(), Path(append).as_posix()), encoding="utf-8")
        # a patched copy compiles from the overlay, so its original folder must stay on the path
        # for sibling "quoted" includes (overlay twin first, as everywhere else)
        siblings = [src.parent, Path(orig).parent] if src != Path(orig) else []
        args = ["/nologo", "/c"] + flags.split() + ["/D" + d for d in defines.split()] + \
               ["/I" + str(i) for i in siblings + list(includes)] + ["/showIncludes", "/Fo" + src.stem + ".obj", str(unit)]
        code, text = run(tc, "cl", args, out)
        included = re.findall(r"^Note: including file:\s*(.+?)\s*$", text, re.M)
        text = "\n".join(l for l in text.splitlines() if not l.startswith("Note: including file:"))
        if code == 0:
            deps_file.write_text(json.dumps(sorted(set(included))))
            if obj.exists():
                cache_file.write_text(json.dumps({"inputs": signature(orig, src, included),
                                                  "object": hashlib.sha256(obj.read_bytes()).hexdigest()}))
        return str(orig), (code == 0, "\n".join(l for l in text.splitlines() if " error " in l)[:2000] or text[-400:])

    import concurrent.futures
    # Objects/dependency files use source stems; colliding stems must stay serial.
    jobs = 4 if len({Path(s).stem.casefold() for s in compiled}) == len(compiled) else 1
    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as pool:
        return dict(pool.map(compile_one, zip(sources, compiled)))


# ---------- modules: reproducible layered builds ----------

def _in_tree(path, src, tree):
    """An include dir inside the recipe tree maps to the patched copy (header patches apply too)."""
    path, src = Path(path).resolve(), Path(src).resolve()
    return tree / path.relative_to(src) if path.is_relative_to(src) else path


def patched_tree(client, recipe):
    """The recipe's source tree, with its binary-derived `patches` applied, as a cached copy under out/.
    Without patches the pristine tree is used in place."""
    import hashlib
    import shutil
    from roc import libs
    r = libs.RECIPES[recipe]
    src = libs._case_path(libs.LIBS / r["src"]).resolve()
    if not r.get("patches"):
        return src
    key = hashlib.sha256(json.dumps(r["patches"], sort_keys=True).encode()).hexdigest()[:12]
    tree = workspace(client) / "out" / "trees" / ("%s-%s" % (recipe, key))
    if not tree.exists():
        tmp = tree.with_name(tree.name + ".tmp")
        if tmp.exists():
            shutil.rmtree(tmp)
        shutil.copytree(src, tmp)
        for rel, edits in r["patches"].items():
            text = (tmp / rel).read_text(errors="replace")
            for old, new in edits:
                if old not in text:
                    raise ValueError("patch for %s no longer applies: %r" % (rel, old[:60]))
                text = text.replace(old, new)
            (tmp / rel).write_text(text)
        tmp.rename(tree)
    return tree

def build_overlay(client, module, spec):
    """Module-level source fixes without touching tools/: the files named in spec["patches"] (a JSON file of
    {rel: [[old, new], ...]}, rel under spec["root"]) are copied, edited and placed in out/<module>/overlay.
    Returns (root, overlay) for compile_direct, or None."""
    if not spec:
        return None
    import hashlib
    root = (ROOT / spec["root"]).resolve()
    patches = json.loads((ROOT / spec["patches"]).read_text(encoding="utf-8"))
    # one stable folder: a file is rewritten only when its patched text changes, so objects that do not
    # include it stay current (compile_direct tracks each object's includes)
    overlay = workspace(client) / "out" / module / "overlay"
    wanted = {}
    for rel, edits in patches.items():
        text = (root / rel).read_text(errors="replace") if (root / rel).exists() else ""
        for old, new in edits:
            if old == "@replace":  # adopt a whole header from a local unit; no vendor text in the patch file
                text = (root / new).read_text(errors="replace")
                continue
            if old.startswith("@all:"):  # every occurrence, e.g. a member that became a weak_ptr
                if old[5:] not in text:
                    raise ValueError("overlay patch for %s no longer applies: %r" % (rel, old[:60]))
                text = text.replace(old[5:], new)
                continue
            if old and old not in text:
                raise ValueError("overlay patch for %s no longer applies: %r" % (rel, old[:60]))
            text = text.replace(old, new, 1) if old else text + new
        wanted[Path(rel).as_posix()] = text
    for path in [p for p in overlay.rglob("*") if p.is_file()] if overlay.exists() else []:
        if path.relative_to(overlay).as_posix() not in wanted:
            path.unlink()  # no longer patched: dependents see it gone and rebuild
    for rel, text in wanted.items():
        target = overlay / rel
        if not target.exists() or target.read_text(errors="replace") != text:
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_text(text)
    return root, overlay


def _overlaid(includes, sources, overlay):
    """Each include dir under the overlay root gets its overlay twin first; patched sources compile from the overlay."""
    if not overlay:
        return list(includes), list(sources)
    root, ov = overlay
    inc = []
    for i in includes:
        i = Path(i).resolve()
        if i.is_relative_to(root):
            inc.append(ov / i.relative_to(root))
        inc.append(i)
    src = [ov / Path(x).resolve().relative_to(root) if Path(x).resolve().is_relative_to(root)
           and (ov / Path(x).resolve().relative_to(root)).exists() else x for x in sources]
    return inc, src


def _spec_path(client, value):
    """`tree:RECIPE/sub/dir` names a folder inside a recipe's (patched) tree; anything else is repo-relative."""
    if value.startswith("tree:"):
        recipe, _, rest = value[5:].partition("/")
        return patched_tree(client, recipe) / rest
    return (ROOT / value).resolve()


def load_module(client, name):
    return json.loads((ROOT / "rebuild" / client / "modules" / (name + ".json")).read_text(encoding="utf-8"))


def mfc_import_lib(client):
    """out/mfclib/mfc90.lib: the mfc90.dll import library (the 2008 exe imports mfc90.dll), made by the period lib.exe
    from the RTM MFC source's mfc90.def. Tests reference it as ../../mfclib/mfc90.lib from out/tests/<test>."""
    out = workspace(client) / "out" / "mfclib"
    if not (out / "mfc90.lib").exists():
        from roc import libs
        out.mkdir(parents=True, exist_ok=True)
        definition = libs.LIBS / "mfc-9.0-rtm" / "atlmfc" / "src" / "mfc" / "intel" / "mfc90.def"
        code, text = run(toolchain(), "lib", ["/nologo", "/MACHINE:X86", "/DEF:" + str(definition), "/NAME:mfc90.dll",
                                              "/OUT:mfc90.lib"], out)
        if code:
            raise RuntimeError("mfc90.lib: " + text[-300:])
    return out / "mfc90.lib"


def build_module(client, name, log=print):
    """Build every layer of modules/<name>.json, resolve the link, run its test, write a report."""
    from roc import libs
    spec = load_module(client, name)
    out = workspace(client) / "out" / spec["name"]
    if spec.get("mfc_import"):  # MFC headers auto-link mfc90.lib by name: the linker finds it in the test's folder
        import shutil
        tests = workspace(client) / "out" / "tests" / spec["test"]
        tests.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(mfc_import_lib(client), tests / "mfc90.lib")
    ov = build_overlay(client, spec["name"], spec.get("overlay"))
    layer_dirs = []
    for layer in spec["layers"]:
        folder = out / ("layer-" + layer["name"])
        if layer["mode"] == "recipe":
            src = libs._case_path(libs.LIBS / libs.RECIPES[layer["recipe"]]["src"])
            listed = libs.RECIPES[layer["recipe"]].get("files")
            if layer["files"] == "recipe" and isinstance(listed, list):
                files = list(listed)
            else:
                globs = (listed if layer["files"] == "recipe" else layer["files"]).split()
                files = sorted(p.relative_to(src).as_posix() for g in globs for p in src.glob(g)
                               if not p.name.startswith("roc_"))
            files = [f for f in files if f not in layer.get("exclude", [])]
            if layer.get("direct"):  # plain cl: /MD defines _DLL, so CRT data is imported as the linker expects
                rep = {"compile_errors": {f: "direct" for f in files}}
            else:
                rep = build_library(client, layer["recipe"], files, layer["flags"], "%s/layer-%s" % (spec["name"], layer["name"]),
                                    cl=layer.get("cl", BUILD), log=log)
            errors = rep["compile_errors"]
            if errors:  # e.g. windows.h: the mining environment has no SDK include path; the rebuild toolchain does
                recipe = libs.RECIPES[layer["recipe"]]
                tree = patched_tree(client, layer["recipe"])
                includes = [tree] + [_in_tree(libs._case_path(libs.LIBS / i), src, tree)
                                     for i in recipe.get("include", []) if i != "WINSDK"]
                defines = (recipe.get("defines", "") + " " + layer.get("extra_defines", "")).strip()
                append = (ROOT / layer["append_include"]).resolve() if layer.get("append_include") else None
                flags = " ".join([layer["flags"]] + ["/FI" + h for h in recipe.get("preinclude", [])])  # recipe preludes
                res = compile_direct(client, [tree / rel for rel in errors], folder, includes, defines,
                                     flags, cl=layer.get("cl", BUILD), append=append, overlay=ov)
                if layer.get("fallback_cl"):  # e.g. VS2005 accepts access checks VS2008 rejects
                    res.update(compile_direct(client, [Path(k) for k, (ok, _) in res.items() if not ok], folder, includes,
                                              defines, layer["flags"], cl=layer["fallback_cl"], append=append, overlay=ov))
                errors = {Path(k).name: v for k, (ok, v) in res.items() if not ok}
        else:
            recipe = libs.RECIPES[layer["includes_from_recipe"]] if layer.get("includes_from_recipe") else {"include": []}
            includes = [(libs.LIBS / i).resolve() for i in recipe["include"] if i != "WINSDK"]
            includes += [(ROOT / i).resolve() for i in layer.get("extra_includes", [])]
            defines = libs.RECIPES[layer["defines_from_recipe"]]["defines"] if layer.get("defines_from_recipe") else layer.get("defines", "")
            defines = (defines + " " + layer.get("extra_defines", "")).strip()
            sources = [p for g in layer["files"].split() for p in sorted((ROOT / layer["dir"]).glob(g))
                       if not p.name.startswith("roc_") and p.name not in layer.get("exclude", [])]
            append = (ROOT / layer["append_include"]).resolve() if layer.get("append_include") else None
            res = compile_direct(client, sources, folder, includes, defines, layer["flags"], cl=layer.get("cl", BUILD), append=append, overlay=ov)
            if layer.get("fallback_cl"):
                res.update(compile_direct(client, [Path(k) for k, (ok, _) in res.items() if not ok], folder, includes,
                                          defines, layer["flags"], cl=layer["fallback_cl"], append=append, overlay=ov))
            errors = {Path(k).name: v for k, (ok, v) in res.items() if not ok}
        _dump(folder / "errors.json", errors)
        log("layer %s: %d compile errors%s" % (layer["name"], len(errors), (" (" + ", ".join(sorted(errors)) + ")") if errors else ""))
        layer_dirs.append(folder)
    deps, pending = [], list(spec.get("depends", []))
    while pending:  # transitive: G3D needs zlib-winapi wherever G3D goes
        dep = pending.pop(0)
        dep_spec = load_module(client, dep)
        dep_lib = workspace(client) / "out" / dep_spec["name"] / "linked" / "linked.lib"
        if dep_lib in deps:
            continue
        if not dep_lib.exists():
            build_module(client, dep, log=log)
        deps.append(dep_lib)
        pending += dep_spec.get("depends", [])
    excluded_path = out / "verified" / "excluded.json"
    excluded = set(json.loads(excluded_path.read_text())) if excluded_path.exists() else set()
    vdrop_path = out / "verified" / "vdrop.json"
    vdrop = set(json.loads(vdrop_path.read_text())) if vdrop_path.exists() else set()
    helpers_path = out / "verified" / "helpers.json"
    helpers = json.loads(helpers_path.read_text()) if helpers_path.exists() else {}
    sinks_path = out / "verified" / "sinks.json"
    sinks = set(json.loads(sinks_path.read_text())) if sinks_path.exists() else set()
    # an inline or template body that several of the module's own objects define is shared code: swapping the 2008 copy
    # in replaces it for every caller, including ones compiled in other contexts (seen crashing M4a/M5), so only
    # file-owned functions swap in
    counts = {}
    for layer_dir in layer_dirs:
        for obj in Path(layer_dir).glob("*.obj"):
            for sym, defined in coff_externals(obj.read_bytes()).items():
                if defined:
                    counts[sym] = counts.get(sym, 0) + 1
    shared = {sym for sym, n in counts.items() if n > 1}
    for _ in range(12):  # a swapped-in function may call a helper nothing else emits: keep it, or swap the caller back out
        verified, drop = verified_layer(client, spec, log=log, exclude=excluded | shared, vdrop=vdrop, helpers=helpers, sinks=sinks)
        result = resolve_objects(client, spec["test"], ([verified] if verified else []) + layer_dirs, spec["name"] + "/linked",
                                 includes=_overlaid([_spec_path(client, i) for i in spec.get("test_includes", [])], [], ov)[0], log=log,
                                 extra_libs=deps, defines=spec.get("test_defines"), drop=drop)
        if verified and not result["linked"] and result["unresolved"]:
            # a missing helper defined by one of the verified objects themselves: keep it there
            missing, added = set(result["unresolved"]) - set(helpers) - vdrop, 0
            for obj in sorted((out / "verified").glob("*.obj")):
                for name, defined in coff_externals(obj.read_bytes()).items():
                    if defined and name in missing and name not in helpers:
                        helpers[name] = obj.name
                        added += 1
            if added:
                _dump(helpers_path, helpers)
                log("verified: keeping %d helpers the swapped functions call" % added)
                continue
        back = set(result.get("referencers", [])) & drop
        if verified and not result["linked"] and result["unresolved"] and not back:
            fresh = set(result["unresolved"]) - sinks
            if fresh:  # only dead bodies name them: give them a trap to bind to instead of evicting whole objects
                sinks |= fresh
                _dump(sinks_path, sorted(sinks))
                log("verified: %d symbols only dead bodies reference; bound to a trap" % len(fresh))
                continue
        if not back and verified and result["unresolved"]:
            # dead bodies left in a verified .text still name the helper: take that whole object out
            missing = set(result["unresolved"])
            for obj in verified.glob("*.obj"):
                ext = coff_externals(obj.read_bytes())
                if any(not ext[m] for m in missing if m in ext):
                    back |= {k for k, d in ext.items() if d} & drop
        dupes = set(result.get("duplicates", [])) - vdrop
        if verified and dupes and not result["linked"]:
            # a verified inline copy against a regular definition elsewhere, or CRT members MSVCP90 exports
            vdrop |= dupes
            _dump(vdrop_path, sorted(vdrop))
            log("verified: %d duplicate definitions; undefined in verified objects" % len(dupes))
            continue
        if result["linked"] or not back:
            break
        excluded |= back
        _dump(excluded_path, sorted(excluded))
        log("verified: %d swapped functions need helpers nothing else defines; swapping them back out" % len(back))
    linked = out / "linked"
    funcs, owned_addrs, owned16_addrs = 0, set(), set()
    for obj in sorted(linked.glob("*.obj")):
        rows = pair(client, match.coff_functions(obj.read_bytes()))
        funcs += len(rows)
        owned_addrs.update(h[0] for _, _, h in rows if len(h) == 1)  # COMDAT copies repeat across objects
        owned16_addrs.update(h[0] for _, s, h in rows if len(h) == 1 and s >= 16)
    owned, owned16 = len(owned_addrs), len(owned16_addrs)
    report = {"module": spec["name"], "linked": result["linked"], "test_exit": result["exit"], "test_output": result["output"][-500:],
              "unresolved": result["unresolved"], "object_functions": funcs, "owned_2008": owned, "owned_2008_16b": owned16,
              "choices": result.get("choices"), "owned_addrs": sorted(owned_addrs)}
    _dump(out / "report.json", report)
    log("%s: linked=%s test_exit=%s; %d object functions, %d byte-identical to unique 2008 functions (%d of >=16 bytes)"
        % (spec["name"], result["linked"], result["exit"], funcs, owned, owned16))
    try:
        progress(client, notify=True, log=log)
    except Exception as error:  # progress is reporting only; never fail a build
        log("rebuild progress update failed: %s" % error)
    return report


# Phase 8 runtime milestones: each is a real test exe linked with a rebuilt module (and its deps)
MILESTONES = {"M2": ("m2_window", "rbxgs-app"), "M4a": ("m4_datamodel", "rbxgs-app"), "M5": ("m5_place", "rbxgs-app"), "M4b": ("m4_render", "rbxgs-app")}


def milestones(client, log=print):
    """Build and run each milestone test; writes out/milestones.json ({id: {passed, exit, output}})."""
    results = {}
    for mid, (test, module) in sorted(MILESTONES.items()):
        spec = load_module(client, module)
        libs, pending = [workspace(client) / "out" / spec["name"] / "linked" / "linked.lib"], list(spec.get("depends", []))
        while pending:
            dep_spec = load_module(client, pending.pop(0))
            lib = workspace(client) / "out" / dep_spec["name"] / "linked" / "linked.lib"
            if lib not in libs:
                libs.append(lib)
                pending += dep_spec.get("depends", [])
        ov = build_overlay(client, spec["name"], spec.get("overlay"))
        kwargs = {"defines": spec["test_defines"]} if spec.get("test_defines") else {}
        result = link_test(client, test, libs,
                           includes=_overlaid([_spec_path(client, i) for i in spec.get("test_includes", [])], [], ov)[0], **kwargs)
        results[mid] = {"test": test, "module": module, "passed": bool(result["linked"] and result["exit"] == 0),
                        "linked": result["linked"], "exit": result["exit"], "output": result["output"][-300:], "unresolved": result["unresolved"]}
        log("%s %s: linked=%s exit=%s" % (mid, test, result["linked"], result["exit"]))
    _dump(workspace(client) / "out" / "milestones.json", results)
    return results


def closure(client, name, log=print):
    """Link every object the module chose (not just what its test pulls in) plus its deps: the full list of
    symbols the module still lacks. Writes out/<module>/closure.json."""
    spec = load_module(client, name)
    out = workspace(client) / "out" / spec["name"]
    objs = sorted((out / "linked").glob("*.obj"))
    deps, pending = [], list(spec.get("depends", []))
    while pending:
        dep_spec = load_module(client, pending.pop(0))
        lib = workspace(client) / "out" / dep_spec["name"] / "linked" / "linked.lib"
        if lib not in deps:
            deps.append(lib)
            pending += dep_spec.get("depends", [])
    kwargs = {"defines": spec["test_defines"]} if spec.get("test_defines") else {}
    ov = build_overlay(client, spec["name"], spec.get("overlay"))
    result = link_test(client, spec["test"], objs + deps,
                       includes=_overlaid([_spec_path(client, i) for i in spec.get("test_includes", [])], [], ov)[0], **kwargs)
    _dump(out / "closure.json", {"module": spec["name"], "objects": len(objs), "linked": result["linked"],
                                 "unresolved": result["unresolved"]})
    log("%s closure: %d objects, linked=%s, %d unresolved symbols" % (spec["name"], len(objs), result["linked"], len(result["unresolved"])))
    missing = set(result["unresolved"])
    blamed = [o for o in objs if o.name.startswith("verified_") and missing & {k for k, d in coff_externals(o.read_bytes()).items() if not d}]
    if blamed:  # dead code in a verified object names it: swap that object out on the next module build
        excluded_path = out / "verified" / "excluded.json"
        excluded = set(json.loads(excluded_path.read_text())) if excluded_path.exists() else set()
        swaps = {"verified_" + item["obj"]: item["keep"] for item in json.loads((out / "verified" / "swaps.json").read_text())["swaps"]}
        for o in blamed:
            excluded |= set(swaps.get(o.name, ()))
        _dump(excluded_path, sorted(excluded))
        log("closure: %d verified objects need these; excluded, rebuild the module" % len(blamed))
    if result.get("duplicates") and (out / "verified" / "swaps.json").exists():
        vdrop_path = out / "verified" / "vdrop.json"
        vdrop = set(json.loads(vdrop_path.read_text())) if vdrop_path.exists() else set()
        _dump(vdrop_path, sorted(vdrop | set(result["duplicates"])))
        log("closure: %d duplicate definitions; undefined in verified objects, rebuild the module" % len(result["duplicates"]))
    try:
        progress(client, notify=True, log=log)
    except Exception as error:
        log("rebuild progress update failed: %s" % error)
    return result


def placed(client="2008-06", log=print):
    """2008 addresses an address-ambiguous body (byte-identical, relocations masked, to several 2008 functions;
    >= 16 bytes, at most 64 candidates) reproduces at exactly one place: the one candidate whose referenced data
    (string literals, constants the body points to) also matches the exe. Cached per object hash in
    out/<Module>/placed.json; writes out/placed.json {address: module}. Slow the first time (minutes per module)."""
    import hashlib
    base, image = match._image(client)
    found = {}
    for spec_path in sorted((ROOT / "rebuild" / client / "modules").glob("*.json")):
        spec = json.loads(spec_path.read_text(encoding="utf-8"))
        out = workspace(client) / "out" / spec["name"]
        report = out / "report.json"
        if not report.exists() or not json.loads(report.read_text()).get("linked"):
            continue
        cache_path = out / "placed.json"
        cache = json.loads(cache_path.read_text()) if cache_path.exists() else {}
        fresh = {}
        for obj in sorted((out / "linked").glob("*.obj")):
            data = obj.read_bytes()
            key = hashlib.sha256(data).hexdigest()
            if key not in cache:
                hits = []
                for name, size, h in pair(client, match.coff_functions(data)):
                    if len(h) < 2 or size < 16 or len(h) > 64:
                        continue
                    refs = match.coff_data_refs(data, name)
                    fits = []
                    for a in h if refs else ():
                        at = int(a, 16) - base
                        ok, bad = match.data_check(client, a, bytes(image[at:at + size]), refs)
                        if ok and not bad:
                            fits.append(a)
                    if len(fits) == 1:
                        hits.append(fits[0])
                cache[key] = hits
            fresh[key] = cache[key]
            for a in cache[key]:
                found.setdefault(a, spec["name"])
        _dump(cache_path, fresh)
        log("%s: %d placed by referenced data" % (spec["name"], len({a for v in fresh.values() for a in v})))
    _dump(workspace(client) / "out" / "placed.json", found)
    log("placed by referenced data: %d addresses" % len(found))
    return found


def status(client="2008-06", log=print):
    """One line per built module from out/<module>/report.json, plus totals (no double counting of addresses)."""
    owned_all, shared_all = set(), set()
    rows = []
    for spec_path in sorted((ROOT / "rebuild" / client / "modules").glob("*.json")):
        spec = json.loads(spec_path.read_text(encoding="utf-8"))
        report_path = workspace(client) / "out" / spec["name"] / "report.json"
        if not report_path.exists():
            rows.append((spec_path.stem, "not built", "", "", ""))
            continue
        r = json.loads(report_path.read_text(encoding="utf-8"))
        linked = workspace(client) / "out" / spec["name"] / "linked"
        for obj in linked.glob("*.obj") if r["linked"] else ():
            for _, size, h in pair(client, match.coff_functions(obj.read_bytes())):
                if len(h) == 1:
                    owned_all.update(h)
                elif size >= 16:  # identical 2008 functions (e.g. template copies): reproduced, address ambiguous
                    shared_all.update(h)
        rows.append((spec_path.stem, "linked" if r["linked"] else "LINK FAIL",
                     "test ok" if r.get("test_exit") == 0 else "test %s" % r.get("test_exit"),
                     r["object_functions"], r["owned_2008"]))
    for name, state, test, funcs, owned in rows:
        log("%-12s %-9s %-8s %6s object functions  %5s owned 2008" % (name, state, test, funcs, owned))
    log("distinct 2008 functions reproduced by linked rebuilt code: %d" % len(owned_all))
    placed_path = workspace(client) / "out" / "placed.json"
    if placed_path.exists():  # `roc rebuild <client> placed` (slow; cached)
        extra = set(json.loads(placed_path.read_text())) - owned_all
        log("plus %d placed at one 2008 address by their referenced data (as of the last `placed` run)" % len(extra))
    log("plus %d (>= 16 bytes) whose bytes the rebuild reproduces but that have byte-identical twins in 2008 (address ambiguous)"
        % len(shared_all - owned_all))
    try:
        progress(client, notify=True, log=log)
    except Exception as error:
        log("rebuild progress update failed: %s" % error)
    return rows, owned_all

import json
import hashlib
import time
import urllib.request
import urllib.error

DEFAULT_REBUILD_WEBHOOK = "DISCORD_WEBHOOK_REDACTED"


def _rebuild_webhook_url():
    return (os.environ.get("ROCONSTRUCT_REBUILD_WEBHOOK") or
            os.environ.get("ROCONSTRUCT_REBUILD_WEBHOOK_URL") or
            DEFAULT_REBUILD_WEBHOOK)


def _rebuild_emoji_bar(value, total, width=10, fill="🟦", empty="⬜"):
    if total <= 0:
        return empty * width
    filled = max(0, min(width, int(round(width * value / total))))
    return fill * filled + empty * (width - filled)



def _send_rebuild_phases_webhook(url, client, data):
    bars = data["bars"]
    current = int(data["phase"])
    phases = [
        (0, "Decisions", "Licensing policy and where the rebuilt tree lives"),
        (1, "Toolchain", "Windows SDK and ATL/MFC libraries plus a running smoke exe"),
        (2, "Audit", "Read-only manifests and per-file coverage"),
        (3, "First linked file", "One whole file compiled, linked and tested"),
        (4, "Modules", "Shared headers and one library per module"),
        (5, "Reconciliation", "Patch files from exact snippets and mine missing functions"),
        (6, "Full link", "Link everything and group unresolved symbols"),
        (7, "Multi-agent", "Claims, worktrees and a trusted merge gate"),
        (8, "Runtime", "Window, startup, rendering, places, Lua and physics"),
    ]
    lines = []
    for number, name, flavor in phases:
        if number < current:
            status = ":white_check_mark:"
        elif number == current:
            status = ":arrows_counterclockwise:"
        else:
            status = ":hourglass:"
        lines.append("%s **Phase %d - %s**\n*%s*" % (status, number, name, flavor))
    description = (
        "**Rebuild phases: %s**\n\n" % client +
        "\n\n".join(lines) +
        "\n\n**Current metrics**\n" +
        "Modules: %d reporting, %d linked\n" % (bars["compiled"]["value"], bars["linked"]["value"]) +
        "Byte-exact functions: %s / %s\n" % (format(bars["exact"]["value"], ","), format(bars["exact"]["total"], ",")) +
        "Unresolved symbols: %d\n" % bars["unresolved"]["value"] +
        "Temporary stubs: %d\n" % bars["stubs"]["value"] +
        "Runtime milestones: %d / %d" % (bars["runtime"]["value"], bars["runtime"]["total"]))
    payload = {"embeds": [{
        "title": ":clipboard: Rebuild phases: %s" % client,
        "description": description,
        "footer": {"text": "RoConstruct rebuild"},
        "timestamp": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
    }]}
    body = json.dumps(payload).encode("utf-8")
    req = urllib.request.Request(url, data=body, headers={"Content-Type": "application/json", "User-Agent": "RoConstruct/1.0"}, method="POST")
    with urllib.request.urlopen(req, timeout=15):
        pass


def _send_rebuild_webhook(url, client, data):
    bars = data["bars"]
    phase_flavor = {
        "0": "Decisions and policy are being recorded before any code is published.",
        "1": "Closing the original VS2008 toolchain and smoke-testing a linked executable.",
        "2": "Auditing the original PE and mapping every function to a source kind.",
        "3": "Compiling and linking the first complete translation unit.",
        "4": "Expanding modules against one corrected shared header set.",
        "5": "Reconciling differing functions against exact 2008 snippets.",
        "6": "Linking all modules and turning unresolved symbols into tracked tasks.",
        "7": "Coordinating parallel agents and merge gates.",
        "8": "Bringing up the runtime, one tested milestone at a time.",
    }.get(str(data["phase"]), "Rebuild work is in progress.")
    description = (
        "**Phase %s - %s**\n" % (data["phase"], data["phaseLabel"]) +
        "*%s*\n\n" % phase_flavor +
        "**Overall byte-exact progress**\n" +
        "%s / %s (%.2f%%)\n\n" % (format(bars["exact"]["value"], ","), format(bars["exact"]["total"], ","), 100.0 * bars["exact"]["value"] / bars["exact"]["total"] if bars["exact"]["total"] else 0.0) +
        "%s\n\n" % _rebuild_emoji_bar(bars["exact"]["value"], bars["exact"]["total"], width=23, fill="\U0001f7e9") +
        "**Modules:** %d reporting, %d linked\n" % (bars["compiled"]["value"], bars["linked"]["value"]) +
        "**Blockers:** %d unresolved, %d temporary stubs\n" % (bars["unresolved"]["value"], bars["stubs"]["value"]) +
        "**Runtime:** %d / %d milestones" % (bars["runtime"]["value"], bars["runtime"]["total"]))
    payload = {
        "embeds": [{
            "title": ":wrench: Rebuild progress: %s" % client,
            "description": description,
            "fields": [
                {"name": ":package: Modules", "value": "**%d** reporting / **%d** linked\n\n%s" % (bars["compiled"]["value"], bars["linked"]["value"], _rebuild_emoji_bar(bars["linked"]["value"], bars["linked"]["total"], width=8, fill="\U0001f7e9")), "inline": True},
                {"name": ":dart: Byte-exact", "value": "**%s** / %s\n\n%s" % (format(bars["exact"]["value"], ","), format(bars["exact"]["total"], ","), _rebuild_emoji_bar(bars["exact"]["value"], bars["exact"]["total"], width=8, fill="\U0001f7e9")), "inline": True},
                {"name": ":warning: Blockers", "value": "**%d** unresolved\n**%d** stubs" % (bars["unresolved"]["value"], bars["stubs"]["value"]), "inline": True},
                {"name": ":rocket: Runtime", "value": "**%d** / %d\n\n%s" % (bars["runtime"]["value"], bars["runtime"]["total"], _rebuild_emoji_bar(bars["runtime"]["value"], bars["runtime"]["total"], width=8, fill="\U0001f7ea")), "inline": True},
            ],
            "footer": {"text": "RoConstruct rebuild"},
            "timestamp": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        }]
    }

    body = json.dumps(payload).encode("utf-8")
    req = urllib.request.Request(url, data=body, headers={"Content-Type": "application/json", "User-Agent": "RoConstruct/1.0"}, method="POST")
    with urllib.request.urlopen(req, timeout=15) as response:
        status = response.status
    try:
        _send_rebuild_phases_webhook(url, client, data)
    except Exception:
        pass
    return status


def progress(client="2008-06", log=print, notify=True):
    """Summarize rebuild module reports into docs/rebuild-progress.json."""
    module_dir = ROOT / "rebuild" / client / "modules"
    out_dir = workspace(client) / "out"
    specs = sorted(module_dir.glob("*.json"))
    modules = []
    distinct = set()
    linked_count = 0
    unresolved_count = 0
    for spec_path in specs:
        spec = json.loads(spec_path.read_text(encoding="utf-8"))
        report_path = out_dir / spec["name"] / "report.json"
        if not report_path.exists():
            continue
        report = json.loads(report_path.read_text(encoding="utf-8"))
        linked = bool(report.get("linked"))
        if linked:
            linked_count += 1
            linked_dir = out_dir / spec["name"] / "linked"
            for obj in linked_dir.glob("*.obj"):
                rows = pair(client, match.coff_functions(obj.read_bytes()))
                distinct.update(h[0] for _, _, h in rows if len(h) == 1)
        unresolved = report.get("unresolved") or []
        unresolved_count += len(unresolved)
        modules.append({
            "name": spec["name"],
            "linked": linked,
            "test": report.get("test_exit"),
            "exact": report.get("owned_2008", 0),
            "objectFunctions": report.get("object_functions", 0),
            "unresolved": len(unresolved),
        })

    total_specs = len(specs)
    reporting = len(modules)
    total_functions = 0
    functions_file = ROOT / "work" / client / "functions.jsonl"
    if functions_file.exists():
        total_functions = sum(1 for _ in functions_file.read_text(encoding="utf-8").splitlines() if _.strip())
    if not total_functions:
        total_functions = 22291

    if not modules:
        phase = "0"
        phase_label = "Not started"
    elif linked_count == 0:
        phase = "3"
        phase_label = "First linked unit"
    elif unresolved_count > 0:
        phase = "6"
        phase_label = "Link closure"
    elif any(m["test"] not in (0, None) for m in modules):
        phase = "4"
        phase_label = "Module tests"
    else:
        phase = "8"
        phase_label = "Runtime"
    # stubs: glue bodies tagged // STUB (empty or placeholder behaviour); M1 = every module linked with tests passing
    stub_count = sum(p.read_text(errors="replace").count("// STUB") for p in (workspace(client) / "glue").rglob("*.cpp"))
    milestones = 1 if modules and all(m["linked"] and m["test"] == 0 for m in modules) else 0
    ran = workspace(client) / "out" / "milestones.json"
    if milestones and ran.exists():
        milestones += sum(1 for k, r in json.loads(ran.read_text()).items() if r.get("passed") and k[1:].isdigit())  # M4a is half of M4

    data = {
        "phase": phase,
        "phaseLabel": phase_label,
        "overall": round(len(distinct) / total_functions, 4) if total_functions else 0.0,
        "bars": {
            "compiled": {"value": reporting, "total": total_specs or 1, "label": "Modules reporting"},
            "linked": {"value": linked_count, "total": reporting or 1, "label": "Modules linked"},
            "exact": {"value": len(distinct), "total": total_functions, "label": "Byte-exact functions"},
            "unresolved": {"value": unresolved_count, "total": max(unresolved_count, 1), "label": "Unresolved symbols", "invert": True},
            "stubs": {"value": stub_count, "total": max(stub_count, 1), "label": "Temporary stubs", "invert": True},
            "runtime": {"value": milestones, "total": 7, "label": "Runtime milestones"},
        },
        "modules": modules,
        "next": "Run roc rebuild %s status for details" % client,
    }

    path = DOCS / "rebuild-progress.json"
    existing = {}
    if path.exists():
        try:
            existing = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            existing = {}
    existing.setdefault("updated", "")
    existing.setdefault("clients", {})
    existing["clients"][client] = data
    existing["updated"] = time.strftime("%Y-%m-%d %H:%M UTC", time.gmtime())
    path.write_text(json.dumps(existing, indent=2) + "\n", encoding="utf-8")
    log("rebuild progress written: %s" % path)

    if notify:
        url = _rebuild_webhook_url()
        if url:
            state_path = ROOT / "work" / "rebuild-webhook-state.json"
            state = {}
            if state_path.exists():
                try:
                    state = json.loads(state_path.read_text(encoding="utf-8"))
                except (OSError, json.JSONDecodeError):
                    state = {}
            states = state.setdefault("clients", {})
            digest = hashlib.sha256(json.dumps(data, sort_keys=True).encode("utf-8")).hexdigest()
            now = time.time()
            last_sent = state.get("last_sent", 0.0)
            hour_start = state.get("hour_start", now)
            sent_this_hour = state.get("sent_this_hour", 0)
            if now - hour_start >= 3600:
                hour_start = now
                sent_this_hour = 0
            if states.get(client) != digest and now - last_sent >= 300 and sent_this_hour < 10:
                try:
                    _send_rebuild_webhook(url, client, data)
                    states[client] = digest
                    state["last_sent"] = now
                    state["hour_start"] = hour_start
                    state["sent_this_hour"] = sent_this_hour + 1
                    state_path.parent.mkdir(parents=True, exist_ok=True)
                    state_path.write_text(json.dumps(state, indent=2) + "\n", encoding="utf-8")
                    log("rebuild webhook sent")
                except (OSError, urllib.error.URLError, ValueError) as error:
                    log("rebuild webhook failed: %s" % error)
            else:
                log("rebuild webhook skipped (no change or rate limited)")
    return data
