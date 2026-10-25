"""2008-06 client rebuild: toolchain, audit, whole-file builds, TU diffs and links.

Separate from mining: nothing here edits src/, clients/, tools/ or bounds.json.
Outputs go to rebuild/<client>/ (manifests/ and out/ stay untracked until
rebuild/<client>/POLICY.md allows publishing them).
"""
import json
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


def toolchain(build=BUILD):
    """Paths for one period toolchain; None where a piece is missing. Never substitutes a newer build."""
    cl = setup.compilers().get(build)
    cl = Path(cl) if cl else None
    vc = cl.parents[1] if cl else None
    ide = cl.parents[2] / "Common7" / "IDE" if cl else None
    sdk_roots = [Path(p) for p in os.environ.get("ROC_WINSDK", "").split(os.pathsep) if p]
    sdk_roots += sorted(TOOLS.glob("*/**/WinSDK"))
    sdk = next((r for r in sdk_roots if _ci(r / "Lib", "kernel32.lib")), None)
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
    return coverage


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
        idx = {}
        for addr, f in match._functions(client).items():
            if f.get("kind", "code") == "code":
                code, relocs, _ = match.target(client, addr)
                idx.setdefault(len(code), []).append((addr, code, relocs))
        _INDEX[client] = idx
    return _INDEX[client]


def pair(client, funcs):
    """[(symbol, size, [2008 addrs whose masked bytes equal it])] against the whole binary."""
    idx = size_index(client)
    return [(name, len(body), [a for a, code, trel in idx.get(len(body), ()) if match.exact_match(code, trel, body, relocs)])
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
VENDOR_AUTOLINK = ("zlib.lib", "G3D.lib", "GLG3D.lib", "sdl.lib", "sdlmain.lib", "glut32.lib")


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
    result.update(linked=code == 0, output=text[-1500:], map=str(out / (test + ".map")))
    if code:
        return result
    done = subprocess.run([str(out / (test + ".exe"))] + list(run_args), capture_output=True, text=True, timeout=300)
    result.update(ran=True, exit=done.returncode, output=(done.stdout + done.stderr).strip()[-1500:])
    return result


def defined_symbols(obj_path):
    return {name for name, _, _ in match.coff_functions(Path(obj_path).read_bytes())}


def resolve_objects(client, test, layers, name, includes=(), max_rounds=20, log=print, extra_libs=(), defines=None):
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
            (out / f).write_bytes(obj.read_bytes())
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


def compile_direct(client, sources, out_dir, includes, defines, flags="/O2 /GS- /EHsc /MD", cl=BUILD, append=None,
                   overlay=None):
    """Plain whole-file cl /c build (no mining wrapper): header search order is the ABI choice.
    append: a header included after each source, e.g. template bodies a tree declares but never defines."""
    tc = toolchain(cl)
    out = Path(out_dir)
    out.mkdir(parents=True, exist_ok=True)
    results = {}
    includes, compiled = _overlaid(includes, sources, overlay)
    # incremental: tools/ is read-only, so an object newer than its source, the overlay and the
    # appended header is current (a changed patch set makes a new overlay folder, hence newer)
    stamp = max([0] + ([Path(overlay[1]).stat().st_mtime] if overlay else []) + ([Path(append).stat().st_mtime] if append else []))
    for orig, src in zip(sources, compiled):
        src = Path(src)
        obj = out / (src.stem + ".obj")
        if obj.exists() and obj.stat().st_mtime > max(stamp, src.stat().st_mtime, Path(orig).stat().st_mtime):
            results[str(orig)] = (True, "up to date")
            continue
        obj.unlink(missing_ok=True)  # a failed compile must not leave a stale object
        if src.suffix.lower() == ".asm":
            code, text = run(tc, _ml(), ["/nologo", "/c", "/Fo" + str(obj), str(src)], out)
            results[str(orig)] = (code == 0, text[-400:])
            continue
        unit = src
        if append:
            unit = out / "_wrap" / (src.stem + ".cpp")
            unit.parent.mkdir(exist_ok=True)
            unit.write_text('#include "%s"\n#include "%s"\n' % (src.as_posix(), Path(append).as_posix()), encoding="utf-8")
        # a patched copy compiles from the overlay, so its original folder must stay on the path
        # for sibling "quoted" includes (overlay twin first, as everywhere else)
        siblings = [src.parent, Path(orig).parent] if src != Path(orig) else []
        args = ["/nologo", "/c"] + flags.split() + ["/D" + d for d in defines.split()] + \
               ["/I" + str(i) for i in siblings + list(includes)] + ["/Fo" + src.stem + ".obj", str(unit)]
        code, text = run(tc, "cl", args, out)
        results[str(orig)] = (code == 0, text[-400:])
    return results


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
    key = hashlib.sha256(json.dumps(patches, sort_keys=True).encode()).hexdigest()[:12]
    overlay = workspace(client) / "out" / module / ("overlay-" + key)
    if not overlay.exists():
        import shutil
        tmp = overlay.with_name(overlay.name + ".tmp")
        shutil.rmtree(tmp, ignore_errors=True)  # a half-written copy from an interrupted run
        for rel, edits in patches.items():
            text = (root / rel).read_text(errors="replace") if (root / rel).exists() else ""
            for old, new in edits:
                if old and old not in text:
                    raise ValueError("overlay patch for %s no longer applies: %r" % (rel, old[:60]))
                text = text.replace(old, new, 1) if old else text + new
            (tmp / rel).parent.mkdir(parents=True, exist_ok=True)
            (tmp / rel).write_text(text)
        try:
            tmp.rename(overlay)
        except PermissionError:  # Windows: a scanner can hold the fresh folder open briefly
            shutil.copytree(tmp, overlay)
            shutil.rmtree(tmp, ignore_errors=True)
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


def build_module(client, name, log=print):
    """Build every layer of modules/<name>.json, resolve the link, run its test, write a report."""
    from roc import libs
    spec = load_module(client, name)
    out = workspace(client) / "out" / spec["name"]
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
                res = compile_direct(client, [tree / rel for rel in errors], folder, includes, defines,
                                     layer["flags"], cl=layer.get("cl", BUILD), append=append, overlay=ov)
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
    result = resolve_objects(client, spec["test"], layer_dirs, spec["name"] + "/linked",
                             includes=_overlaid([_spec_path(client, i) for i in spec.get("test_includes", [])], [], ov)[0], log=log,
                             extra_libs=deps, defines=spec.get("test_defines"))
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
    try:
        progress(client, notify=True, log=log)
    except Exception as error:
        log("rebuild progress update failed: %s" % error)
    return result


def status(client="2008-06", log=print):
    """One line per built module from out/<module>/report.json, plus totals (no double counting of addresses)."""
    owned_all = set()
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
            owned_all.update(h[0] for _, _, h in pair(client, match.coff_functions(obj.read_bytes())) if len(h) == 1)
        rows.append((spec_path.stem, "linked" if r["linked"] else "LINK FAIL",
                     "test ok" if r.get("test_exit") == 0 else "test %s" % r.get("test_exit"),
                     r["object_functions"], r["owned_2008"]))
    for name, state, test, funcs, owned in rows:
        log("%-12s %-9s %-8s %6s object functions  %5s owned 2008" % (name, state, test, funcs, owned))
    log("distinct 2008 functions reproduced by linked rebuilt code: %d" % len(owned_all))
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

DEFAULT_REBUILD_WEBHOOK = "https://discord.com/api/webhooks/1563963572256768061/UlEfpuW48IqPmanJ2rr0gmawcff-DO19Crc4FMoZ24ufoe6Kp_qOhjIpF8oEzUm72IdW"


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

    data = {
        "phase": phase,
        "phaseLabel": phase_label,
        "overall": round(len(distinct) / total_functions, 4) if total_functions else 0.0,
        "bars": {
            "compiled": {"value": reporting, "total": total_specs or 1, "label": "Modules reporting"},
            "linked": {"value": linked_count, "total": reporting or 1, "label": "Modules linked"},
            "exact": {"value": len(distinct), "total": total_functions, "label": "Byte-exact functions"},
            "unresolved": {"value": unresolved_count, "total": max(unresolved_count, 1), "label": "Unresolved symbols", "invert": True},
            "stubs": {"value": unresolved_count, "total": max(unresolved_count, 1), "label": "Temporary stubs", "invert": True},
            "runtime": {"value": 0, "total": 7, "label": "Runtime milestones"},
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