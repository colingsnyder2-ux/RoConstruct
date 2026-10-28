"""Serialized authoritative native verifier. Uploaded data never becomes Python."""
import concurrent.futures
import faulthandler
import functools
import hashlib
import json
import os
import shutil
import subprocess
import sys
import threading
import time
from pathlib import Path

from roc.integration import CLIENT, MODULE, ROOT, atomic_json, digest, merge_patches, canonical_patches

WRITABLE_OUT = {"RbxgsApp", "tests"}  # out/ folders a snapshot build or milestone link writes into

WATCHDOG_SECONDS = 20 * 60  # cold baselines take minutes; stacks only after this long without a verdict

# Compiler, matcher and gate implementation. Queue/UI/webhook code does not build native artifacts.
NATIVE_CODE = ("__init__", "analyze", "clients", "fingerprint", "integration", "integration_verify", "libs", "match",
               "rebuild", "repair", "rtti", "setup", "telemetry", "worker")


@functools.lru_cache(maxsize=1)
def tool_inventory():
    """Pin the configured period compiler/SDK for this verifier process."""
    from roc import libs, rebuild, setup
    key = digest({"environment": {name: os.environ.get(name, "") for name in
                                 ("ROC_CL", "ROC_WINSDK", "ROC_ATLMFC", "PATH", "WINEPREFIX", "ROC_WINE")},
                  "install": file_hash(setup.STATE).hex() if setup.STATE.exists() else None,
                  "code": [file_hash(Path(module.__file__)).hex() for module in (libs, rebuild, setup)]})
    cache = ROOT / "work/integration/toolchain.json"
    if cache.exists():
        try:
            saved = json.loads(cache.read_text())
            inventory = saved["inventory"]
            paths = [inventory["sdk"], inventory["ml"], inventory["toolchain"]["cl"]]
            paths += [value for name, value in inventory["toolchain"].items() if name != "build" and value]
            if saved["key"] == key and all(path and Path(path).exists() for path in paths):
                return inventory
        except (OSError, ValueError, KeyError, TypeError):
            pass  # An invalid discovery cache is rebuilt; it is never a verification receipt.
    sdk = libs.winsdk_include()
    tc = rebuild.toolchain()
    if not sdk or not tc.get("cl"):
        raise ValueError("Historical compiler/Windows SDK is not installed")
    inventory = {"sdk": sdk, "toolchain": {k: str(v) if isinstance(v, Path) else v for k, v in tc.items()},
                 "ml": str(rebuild._ml())}
    atomic_json(cache, {"key": key, "inventory": inventory})
    return inventory


def native_tools(root):
    """Resolve recipe/include/toolchain roots; unrelated installed tools are not inputs."""
    from roc import libs, rebuild
    if not (root / "rebuild/2008-06/modules/rbxgs-app.json").exists():
        return [root / "tools"]  # Small fixture/partial installation.
    roots, seen = set(), set()
    inventory = tool_inventory()
    sdk_include = inventory["sdk"]

    def recipe(name):
        r = libs.RECIPES[name]
        roots.add(libs._case_path(libs.LIBS / r["src"]).resolve())
        for path in r.get("include", []):
            roots.add(Path(sdk_include) if path == "WINSDK"
                      else libs._case_path(libs.LIBS / path).resolve())

    def module(name):
        if name in seen:
            return
        seen.add(name)
        spec = json.loads((root / "rebuild" / CLIENT / "modules" / (name + ".json")).read_text())
        for dep in spec.get("depends", []):
            module(dep)
        for layer in spec["layers"]:
            for key in ("recipe", "includes_from_recipe", "defines_from_recipe"):
                if layer.get(key):
                    recipe(layer[key])
            if layer.get("dir", "").startswith("tools/"):
                roots.add(root / layer["dir"])
            roots.update(root / path for path in layer.get("extra_includes", []) if path.startswith("tools/"))

    module(MODULE)
    for key, value in inventory["toolchain"].items():
        if value and key != "build":
            path = Path(value)
            roots.add(path if path.is_dir() else path.parent)
    roots.add(Path(inventory["ml"]).parent)
    roots = {p.resolve() for p in roots if p.exists()}
    return sorted((p for p in roots if not any(p != parent and p.is_relative_to(parent) for parent in roots)), key=str)


def file_hash(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").digest()


def input_files(parent, excluded=()):
    """Prune output/cache directories before descent, including their directory enumeration cost."""
    for directory, folders, files in os.walk(parent):
        folders[:] = [name for name in folders if name not in excluded]
        for name in files:
            yield Path(directory) / name


def input_paths(root, live_only=False):
    """Full and read-through input sets. Every selected file is checked by content."""
    paths = []
    # The unit registry is mining transport metadata. Pinned native builds read
    # installed files, including adopted/referenced generated units hashed below.
    for folder in ("clients/2008-06",):
        parent = root / folder
        if parent.exists():
            paths.extend(p for p in input_files(parent, ("__pycache__",))
                         if p.suffix not in (".pyc", ".pdb", ".ilk"))
    referenced = set()
    overlay = root / "rebuild/2008-06/patches/rbxgs-client.json"
    if overlay.exists():
        for edits in json.loads(overlay.read_text()).values():
            for old, new in edits:
                if old == "@replace":
                    referenced.add(root / "tools/rbxgs/Client" / new)
    for deps in (root / "rebuild/2008-06/out/RbxgsApp").glob("layer-*/*.deps"):
        referenced.update(Path(p) for p in json.loads(deps.read_text()) if Path(p).name.startswith("roc_"))
    for parent in native_tools(root):
        # Exclude vendor documentation/media/build logs, not code or binary
        # inputs. Extensionless MSVC/STL headers are included as well.
        suffixes = {"", ".h", ".hpp", ".hxx", ".c", ".cpp", ".cxx", ".inl", ".inc", ".ipp", ".tcc",
                    ".in", ".txt", ".ver", ".idl", ".tlh", ".tli", ".tlb", ".asm", ".def", ".rc", ".rc2",
                    ".res", ".obj", ".lib", ".dll", ".exe", ".config", ".dat", ".manifest"}
        paths.extend(p for p in input_files(parent, ("__pycache__",)) if p.suffix.lower() in suffixes
                     and not p.name.startswith("roc_"))
    paths.extend(p for p in {p.resolve() for p in referenced} if p.is_file())
    paths.extend(p for p in (root / "clients/clients.json", root / "clients/sources.json") if p.exists())
    live = set(paths)
    if live_only:
        return live, live
    paths.extend(p for name in NATIVE_CODE if (p := root / "roc" / (name + ".py")).exists())
    paths.extend(p for p in (root / "research/template-units.json", root / "research/libs-bundle.json") if p.exists())
    parent = root / "rebuild" / CLIENT
    paths.extend(input_files(parent, ("out", "__pycache__")))
    work = root / "work" / CLIENT
    paths.extend(p for p in (work / "functions.jsonl", work / "bounds.json") if p.is_file())
    out = root / "rebuild" / CLIENT / "out"
    paths.extend(p for p in out.glob("*/verified/*") if p.is_file())
    paths.extend(p for p in out.glob("*/*.json") if p.is_file()
                 and p.name != "report.json")
    paths.extend(p for p in out.glob("*/report.json") if p.parent.name != "RbxgsApp")
    for path in sorted((root / "rebuild" / CLIENT / "out").glob("*/linked/*")):
        if path.parent.parent.name != "RbxgsApp" and path.is_file() and path.suffix in (".obj", ".lib"):
            paths.append(path)
    return set(paths), live


def input_hash(root, live_only=False):
    return digest_paths(root, input_paths(root, live_only)[0])


def input_hashes(root):
    """Initial full/live checks share one walk and one read of each input."""
    paths, live = input_paths(root)
    paths = sorted(paths, key=str)
    with concurrent.futures.ThreadPoolExecutor(max_workers=8) as pool:
        contents = dict(zip(paths, pool.map(file_hash, paths)))
    return digest_paths(root, paths, contents), digest_paths(root, live, contents)


def digest_paths(root, paths, contents=None):
    result = hashlib.sha256(b"native-inputs-v2\0")
    paths = sorted(set(paths), key=str)
    # Independent file reads overlap Windows filesystem/antivirus latency.
    # map preserves path order; content hashes never rely on size or mtime.
    if contents is None:
        with concurrent.futures.ThreadPoolExecutor(max_workers=8) as pool:
            contents = dict(zip(paths, pool.map(file_hash, paths)))
    for path in paths:
        label = path.relative_to(root).as_posix() if path.is_relative_to(root) else str(path)
        result.update(label.encode() + b"\0" + contents[path])
    for name in ("INCLUDE", "LIB", "LIBPATH", "CL", "_CL_", "PATH", "WINEPREFIX", "ROC_CL", "ROC_WINSDK", "ROC_ATLMFC"):
        result.update(name.encode() + b"=" + os.environ.get(name, "").encode())
    return result.hexdigest()


def snapshot(root, destination, link=False):
    """Private mutable outputs; installed source/toolchain trees are read-through."""
    destination.mkdir(parents=True, exist_ok=False)
    for name in ("roc", "research"):
        shutil.copytree(root / name, destination / name, ignore=shutil.ignore_patterns("__pycache__", "*.pyc"))
    shutil.copy2(root / "roc.py", destination / "roc.py")
    shutil.copytree(root / "rebuild" / CLIENT, destination / "rebuild" / CLIENT,
                    ignore=shutil.ignore_patterns("out"))
    for name in ("tools", "clients", "src"):
        source, target = (root / name).resolve(), destination / name
        if os.name == "nt":
            subprocess.run(["cmd", "/c", "mklink", "/J", str(target), str(source)],
                           check=True, capture_output=True)
        else:
            target.symlink_to(source, target_is_directory=True)
    for name in ("work/2008-06", "local/units"):
        source = root / name
        if source.exists():
            target = destination / name
            target.mkdir(parents=True, exist_ok=True)
            for path in source.glob("*.json*"):
                shutil.copy2(path, target / path.name)
    # Copy what a build may write: linkers and compilers overwrite output files in place. A snapshot only
    # rebuilds rbxgs-app and links tests, so other modules' objects/libraries are read-only inputs: with link=True
    # (only from an immutable baseline cache, never the live checkout) hard-link those
    # (about half of a 1.3 GB copy that took minutes per job).
    # ponytail: relies on nothing rewriting other modules' .obj/.lib in a snapshot; copy them if that ever changes.
    source = root / "rebuild" / CLIENT / "out"

    def place(src, dst):
        parts = Path(src).relative_to(source).parts
        if link and parts[0] not in WRITABLE_OUT and Path(src).suffix.lower() in (".obj", ".lib"):
            try:
                return os.link(src, dst)
            except OSError:
                pass
        return shutil.copy2(src, dst)
    def ignore(folder, names):
        relative = Path(folder).relative_to(source).parts
        if not relative:
            # Native compilation needs its verified inputs. Other modules contribute linked artifacts/reports.
            modules = {p.name for p in source.iterdir() if p.is_dir()
                       and ((p / "report.json").exists() or (p / "linked").is_dir())}
            return [name for name in names if name not in modules | {"RbxgsApp", "mfclib", "placed.json"}]
        if len(relative) == 1:
            if relative[0] == "RbxgsApp":
                return [name for name in names if name != "verified" and not (link and name.startswith("layer-"))]
            if relative[0] != "mfclib":
                return [name for name in names if name not in {"linked", "report.json", "placed.json"}]
        return [name for name in names if name.endswith((".pdb", ".ilk"))]

    if source.exists():
        # Independent file copies overlap Windows filesystem/antivirus latency. Finish every copy before use.
        with concurrent.futures.ThreadPoolExecutor(max_workers=8) as pool:
            copies = []
            def enqueue(src, dst):
                copies.append(pool.submit(place, src, dst))
                return dst
            shutil.copytree(source, destination / "rebuild" / CLIENT / "out", copy_function=enqueue, ignore=ignore)
            for future in copies:
                future.result()
        # Incremental include tracking must point at this private overlay, never
        # the baseline's headers: only changed headers should force recompilation.
        for deps in (destination / "rebuild" / CLIENT / "out").rglob("*.deps"):
            values = json.loads(deps.read_text())
            remapped = []
            for value in values:
                path = Path(value)
                try:
                    relative = path.relative_to(root / "rebuild")
                except ValueError:
                    remapped.append(value)
                else:
                    remapped.append(str(destination / "rebuild" / relative))
            deps.write_text(json.dumps(remapped))


def run(root, args, log):
    env = {k: v for k, v in os.environ.items()
           if not any(s in k.upper() for s in ("WEBHOOK", "TOKEN", "API_KEY", "SECRET", "PASSWORD", "CREDENTIAL"))}
    env["PYTHONUNBUFFERED"] = "1"
    env["ROC_INTEGRATION_VERIFY"] = "1"
    env["ROC_NATIVE_TOOLCHAIN"] = json.dumps(tool_inventory())
    # Pin discovery for one isolated command. All header probes still execute;
    # they stop recursively searching every installed tool for each include.
    bootstrap = """import functools,json,os,runpy,sys
from pathlib import Path
from roc import libs,rebuild,setup
pinned=json.loads(os.environ['ROC_NATIVE_TOOLCHAIN'])
tc={k:Path(v) if v and k!='build' else v for k,v in pinned['toolchain'].items()}
libs.winsdk_include=lambda:pinned['sdk']
setup.compilers=lambda:{tc['build']:tc['cl']}
@functools.lru_cache(maxsize=None)
def installed_source(name):
 folder=libs._case_path(libs.LIBS/libs.RECIPES[name]['src']).resolve()
 if not folder.is_dir():raise ValueError('Install source recipe before verification: '+name)
 return folder
libs.fetch=installed_source
def toolchain(build=rebuild.BUILD):
 if build!=tc['build']:raise ValueError('Compiler outside pinned native profile')
 return tc
rebuild.toolchain=toolchain
rebuild._ml=lambda:Path(pinned['ml'])
args=json.loads(sys.argv[1])
if args[0]=='-c':
 exec(compile(args[1],'<native-verifier>','exec'),{'__name__':'__main__'})
else:
 sys.argv=args
 runpy.run_path(args[0],run_name='__main__')
"""
    with log.open("w", encoding="utf-8") as stream:
        try:
            subprocess.run([sys.executable, "-c", bootstrap, json.dumps(args)], cwd=root, env=env, stdout=stream,
                           stderr=subprocess.STDOUT, check=True, timeout=4 * 3600)
        except subprocess.SubprocessError:
            stream.flush()
            tail = log.read_text(encoding="utf-8", errors="replace")[-2500:]
            raise RuntimeError(log.name + " failed:\n" + tail) from None


def collect(root):
    out = root / "rebuild" / CLIENT / "out"
    report = json.loads((out / "RbxgsApp/report.json").read_text())
    status = (root / "integration-status.log").read_text(encoding="utf-8", errors="replace")
    import re
    distinct = re.search(r"distinct 2008 functions reproduced by linked rebuilt code: (\d+)", status)
    if not distinct:
        raise ValueError("No authoritative distinct result")
    return {"report": report, "distinct": int(distinct[1]),
            "size": json.loads((out / "size-check.json").read_text()),
            "base": json.loads((out / "base-check.json").read_text()),
            "milestones": json.loads((out / "milestones.json").read_text())}


def other_module_owned(root):
    """Addresses owned by linked modules other than RbxgsApp (their reports are fixed inputs of a native job)."""
    owned = set()
    for report in (root / "rebuild" / CLIENT / "out").glob("*/report.json"):
        if report.parent.name != "RbxgsApp":
            data = json.loads(report.read_text())
            if data.get("linked"):
                owned.update(data.get("owned_addrs", []))
    return owned


def ownership_diagnostics(before, after, elsewhere=()):
    old = set(before["report"]["owned_addrs"])
    new = set(after["report"]["owned_addrs"])
    return {"gains": sorted(new - old), "losses": sorted(old - new),
            "uncovered_losses": sorted(old - new - set(elsewhere))}


def linked_preflight(root, patches, output, log=print):
    """Contributor proof uses the independent verifier's snapshots, build and gates."""
    root, output = Path(root), Path(output)
    base = json.loads((root / "rebuild/2008-06/patches/rbxgs-client.json").read_text())
    combined, _, dropped = preflight(root, base, patches)
    if dropped:
        raise ValueError("Saved proposals stale; retained for repair: " + json.dumps(dropped))
    key, live = input_hashes(root)
    cache = root / "work/native-linked-preflight" / key[:20]
    cache.parent.mkdir(parents=True, exist_ok=True)
    result_file = cache / "integration-result.json"
    checkpoint = cache / "integration-prepared.json"
    if result_file.exists() and checkpoint.exists() and json.loads(checkpoint.read_text()) == {"format": 1, "inputs": key}:
        before = json.loads(result_file.read_text())
    else:
        cache, _ = prepare_baseline(root, cache, key)
        log("Linked preflight baseline artifacts: " + str(cache))
        before = verify_build(cache, lambda phase: log("Linked preflight baseline: " + phase))
        check_gates(before)
        before["linked_addresses"] = json.loads((cache / "integration-linked.json").read_text())
        atomic_json(cache / "integration-result.json", before)
    candidate = output / ("linked-preflight-" + str(time.time_ns()))
    snapshot(cache, candidate, link=True)
    atomic_json(candidate / "rebuild/2008-06/patches/rbxgs-client.json", combined)
    receipt = {"accepted": False, "baseline_artifacts": str(cache), "artifacts": str(candidate),
               "input_hash": key, "overlay_hash": digest(combined)}
    try:
        after = verify_build(candidate, lambda phase: log("Linked preflight candidate: " + phase))
        atomic_json(candidate / "integration-result.json", after)
        elsewhere = other_module_owned(candidate)
        receipt.update(ownership_diagnostics(before, after, elsewhere))
        check_gates(after, before, elsewhere)
        new_distinct = set(receipt["gains"]) - set(before["linked_addresses"])
        if after["distinct"] - before["distinct"] != len(new_distinct):
            raise ValueError("Linked coverage changed outside the submitted module")
        if input_hash(root, live_only=True) != live:
            raise ValueError("Inputs changed during linked preflight; proposals retained")
        receipt["accepted"] = True
    except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as error:
        receipt["reason"] = str(error)
        raise
    finally:
        atomic_json(candidate / "preflight-receipt.json", receipt)
        log("Linked preflight receipt: " + str(candidate / "preflight-receipt.json"))
    return receipt


def check_gates(result, baseline=None, elsewhere=frozenset()):
    """elsewhere: addresses another module still owns; RbxgsApp may stop claiming them (e.g. a coincidental
    match that a real layout fix moves away) because global coverage does not drop."""
    report = result["report"]
    if not report["linked"] or report.get("test_exit") != 0:
        raise ValueError("Module build/runtime gate failed")
    for milestone in ("M2", "M4a", "M5"):
        item = result["milestones"].get(milestone, {})
        if item.get("exit") != 0 or not item.get("passed"):
            code = item.get("exit")
            status = "not run" if code is None else "%s (0x%08X)" % (code, code & 0xffffffff)
            raise ValueError(milestone + " runtime gate failed: " + item.get("test", milestone)
                             + ", exit=" + status + ", linked=" + str(item.get("linked"))
                             + ("; " + item["output"] if item.get("output") else "; no stdout/stderr"))
    if result["base"].get("mismatch"):
        raise ValueError("Base offsets differ")
    if not baseline:
        return
    before, after = set(baseline["report"]["owned_addrs"]), set(report["owned_addrs"])
    if not after - before or before - after - set(elsewhere):
        raise ValueError("Need new module ownership without losing existing owned bodies")
    if result["distinct"] < baseline["distinct"]:
        raise ValueError("Global distinct coverage regressed")
    old_sizes = {r["class"]: r for r in baseline["size"]["rows"]}
    new_sizes = {r["class"]: r for r in result["size"]["rows"]}
    if set(old_sizes) - set(new_sizes):
        raise ValueError("Size probe coverage regressed")
    for name, row in new_sizes.items():
        if row["delta"] and old_sizes.get(name, {}).get("delta") != row["delta"]:
            raise ValueError("New size mismatch: " + name)
    for kind in ("size", "base"):
        if set(result[kind].get("probe_errors", {})) - set(baseline[kind].get("probe_errors", {})):
            raise ValueError(kind + " probe errors increased")
    if result["base"].get("checked", 0) < baseline["base"].get("checked", 0):
        raise ValueError("Base probe coverage regressed")


def preflight(root, base, patches):
    """Cheap anchor validation/rebase before hashing inputs or building anything.
    A file whose edits no longer apply is dropped from the batch, so one stale file does not cost the rest;
    returns (combined overlay, kept patches, {dropped file: reason}). Raises when nothing applies."""
    base = canonical_patches(base)
    patches = canonical_patches(patches, base)
    tree = root / "tools/rbxgs/Client"
    kept, dropped = {}, {}
    for name, change in patches.items():
        try:
            edits = merge_patches(base, {name: change})[name]
            path = tree / name
            text = path.read_text(errors="replace") if path.exists() else ""
            existing = len(base.get(name, []))
            for index, (old, new) in enumerate(edits):
                if old == "@replace":
                    text = (tree / new).read_text(errors="replace")
                elif old.startswith("@all:"):
                    anchor = old[5:]
                    if not anchor or anchor not in text:
                        raise ValueError("Stale overlay anchor: " + name)
                    text = text.replace(anchor, new)
                elif old:
                    if old not in text or index >= existing and text.count(old) != 1:
                        raise ValueError("Missing or ambiguous overlay anchor: " + name)
                    text = text.replace(old, new, 1)
                else:
                    text += new
        except ValueError as error:
            dropped[name] = str(error)
            continue
        kept[name] = change
    if not kept:
        raise ValueError("; ".join(dropped.values()) or "Empty batch")
    return merge_patches(base, kept), kept, dropped


def verify_build(root, progress):
    progress("building")
    # The size/base gates read only the header overlay: write it first (build_module rewrites nothing unchanged)
    # and run them beside the compile instead of after the link.
    overlay = ("from roc import rebuild; s=rebuild.load_module('2008-06','rbxgs-app'); "
               "rebuild.build_overlay('2008-06', s['name'], s.get('overlay'))")
    run(root, ["-c", overlay], root / "integration-overlay.log")
    # Reporting is separate: avoid another complete object scan/webhook per gate.
    build = ("from roc import rebuild; import sys; "
             "rebuild.progress=lambda *a,**kw: None; "
             "r=rebuild.build_module('2008-06','rbxgs-app'); "
             "sys.exit(0 if r['linked'] and r['test_exit']==0 else 1)")
    status = ("from roc import rebuild; import json; from pathlib import Path; "
              "rebuild.progress=lambda *a,**kw: None; "
              "rows,owned=rebuild.status('2008-06'); "
              "Path('integration-linked.json').write_text(json.dumps(sorted(owned)))")
    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        def submit(args, name):
            return pool.submit(run, root, args, root / ("integration-" + name + ".log"))
        early = [submit(["rebuild/2008-06/size_check.py"], "size"), submit(["rebuild/2008-06/base_check.py"], "base")]
        submit(["-c", build], "build").result()
        progress("checking")
        late = [submit(["-c", "from roc import rebuild; rebuild.milestones('2008-06')"], "milestones"),
                submit(["-c", status], "status")]
        for future in early + late:
            future.result()
    return collect(root)


def prepare_baseline(root, cache, input_key):
    """Resume only a snapshot prepared for these exact inputs; live objects never seed a cold proof."""
    checkpoint = cache / "integration-prepared.json"
    if checkpoint.exists() and json.loads(checkpoint.read_text()) == {"format": 1, "inputs": input_key}:
        return cache, True
    if cache.exists():
        cache = cache.with_name(cache.name + "-" + str(time.time_ns()))
    snapshot(root, cache)
    for folder in (cache / "rebuild/2008-06/out/RbxgsApp").glob("layer-*"):
        for obj in folder.glob("*.obj"):
            obj.unlink()
    run(cache, ["rebuild/2008-06/patches/make_rbxgs_client.py"], cache / "integration-generator.log")
    atomic_json(cache / "integration-prepared.json", {"format": 1, "inputs": input_key})
    return cache, False


def verify(promotions, job):
    from roc.integration_notify import notify
    root = promotions.root
    baseline = promotions.baseline()
    patches = json.loads(job["patches"])
    promotions.progress(job["id"], "preflight")
    combined, kept, dropped = preflight(root, baseline["overlay"], patches)
    if dropped:
        # finish() records job["patches"] as the accepted overlay: keep only what was verified.
        job["patches"] = json.dumps(kept)
    promotions.progress(job["id"], "fingerprinting inputs")
    before_hash, live_hash = input_hashes(root)
    # Builds run in a copied snapshot: only read-through trees can still change under them.
    cache = promotions.directory / "baselines" / before_hash
    index_file = promotions.directory / "baselines/index.json"
    index = json.loads(index_file.read_text()) if index_file.exists() else {}
    if before_hash in index:
        proposed = (promotions.root / index[before_hash]).resolve()
        if proposed.is_relative_to(promotions.directory.resolve()):
            cache = proposed
    def progress(phase):
        promotions.progress(job["id"], phase)
        notify(promotions, job)
    baseline_file = cache / "integration-result.json"
    if not baseline_file.exists():
        progress("baseline: preparing snapshot")
        cache, resumed = prepare_baseline(root, cache, before_hash)
        baseline_file = cache / "integration-result.json"
        # Persist the prepared location before compiling so a restart can reuse its content-checked objects.
        index[before_hash] = cache.relative_to(root).as_posix()
        atomic_json(index_file, index)
        if resumed:
            progress("baseline: resuming prepared snapshot")
        before = verify_build(cache, lambda phase: progress("baseline: " + phase))
        check_gates(before)
        before["linked_addresses"] = json.loads((cache / "integration-linked.json").read_text())
        if input_hash(root, live_only=True) != live_hash:
            raise ValueError("Server inputs changed during baseline verification; retry on a stable baseline")
        atomic_json(baseline_file, before)
        index[before_hash] = cache.relative_to(root).as_posix()
        atomic_json(index_file, index)
    else:
        before = json.loads(baseline_file.read_text())
    atomic_json(promotions.directory / "progress-native.json", {"addresses": before["linked_addresses"]})
    candidate = promotions.directory / "jobs" / job["id"]
    if candidate.exists():
        candidate = candidate.with_name(candidate.name + "-" + str(time.time_ns()))
    # Reuse independently verified outputs, while all writable files remain copies.
    progress("preparing candidate snapshot")
    snapshot(cache, candidate, link=True)  # the baseline cache is never rebuilt: share its read-only objects
    atomic_json(candidate / "rebuild" / CLIENT / "patches" / "rbxgs-client.json", combined)
    job["diagnostics"] = {"artifacts": candidate.relative_to(root).as_posix(),
                          "baseline_artifacts": cache.relative_to(root).as_posix(),
                          "baseline_revision": baseline["revision"], "submitted_revision": job["base"],
                          "input_hash": before_hash}
    after = verify_build(candidate, progress)
    atomic_json(candidate / "integration-result.json", after)
    elsewhere = other_module_owned(candidate)
    job["diagnostics"].update(ownership_diagnostics(before, after, elsewhere))
    atomic_json(candidate / "integration-diagnostics.json", job["diagnostics"])
    check_gates(after, before, elsewhere)
    if input_hash(root, live_only=True) != live_hash or promotions.baseline()["revision"] != baseline["revision"]:
        raise ValueError("Server inputs changed during candidate verification; retry on a stable baseline")
    old_owned = set(before["report"]["owned_addrs"])
    gains = set(after["report"]["owned_addrs"]) - old_owned
    new_distinct = gains - set(before["linked_addresses"])
    if after["distinct"] - before["distinct"] != len(new_distinct):
        raise ValueError("Linked coverage changed outside the submitted module")
    atomic_json(candidate / "integration-native.json", sorted(set(before["linked_addresses"]) | gains))
    return {"accepted": True, "gains": sorted(gains),
            "losses": sorted(old_owned - set(after["report"]["owned_addrs"])),  # each still owned by another module
            "new_distinct": sorted(new_distinct), "owned_before": len(old_owned),
            "owned_after": len(after["report"]["owned_addrs"]),
            "distinct_before": before["distinct"], "distinct_after": after["distinct"],
            "baseline_revision": baseline["revision"], "submitted_revision": job["base"],
            "rebased": baseline["revision"] != job["base"], "input_hash": before_hash,
            "overlay_hash": digest(combined), "gates": "M2/M4a/M5, size, base, linked ownership passed",
            "dropped_files": dropped,
            "artifacts": candidate.relative_to(root).as_posix(),
            "probe_errors": {k: after[k].get("probe_errors", {}) for k in ("size", "base")}}


def publish(promotions, patches=None):
    """Recoverable materialization of the DB's accepted declarative ledger."""
    path = promotions.overlay.with_name("native-promotions.json")
    old_ledger = path.read_bytes() if path.exists() else None
    old_overlay = promotions.overlay.read_bytes()
    try:
        atomic_json(path, promotions.accepted() if patches is None else patches)
        subprocess.run([sys.executable, str(promotions.generator)], cwd=promotions.root,
                       check=True, capture_output=True, timeout=60)
    except BaseException:
        if old_ledger is None:
            path.unlink(missing_ok=True)
        else:
            path.write_bytes(old_ledger)
        promotions.overlay.write_bytes(old_overlay)
        raise


def cache_accepted(promotions, receipt):
    candidate = promotions.root / receipt["artifacts"]
    shutil.copy2(promotions.overlay.with_name("native-promotions.json"),
                 candidate / "rebuild/2008-06/patches/native-promotions.json")
    run(candidate, ["rebuild/2008-06/patches/make_rbxgs_client.py"], candidate / "integration-generator.log")
    if digest(json.loads((candidate / "rebuild/2008-06/patches/rbxgs-client.json").read_text())) != receipt["overlay_hash"]:
        raise ValueError("Published overlay differs from verified candidate")
    result = collect(candidate)
    result["linked_addresses"] = json.loads((candidate / "integration-native.json").read_text())
    atomic_json(candidate / "integration-result.json", result)
    index_file = promotions.directory / "baselines/index.json"
    index = json.loads(index_file.read_text()) if index_file.exists() else {}
    index[input_hash(promotions.root)] = candidate.relative_to(promotions.root).as_posix()
    atomic_json(index_file, index)


def loop(promotions, log=print):
    # Only the server owns this worker. Clients cannot POST verification results.
    with promotions.store.lock, promotions.store.db:
        # Interrupted work resumes ahead of ordinary FIFO jobs; explicit force-queue requests still take precedence.
        promotions.store.db.execute("INSERT OR IGNORE INTO integration_queue_priority(job,requested) "
                                    "SELECT id,0 FROM integration_jobs WHERE state='verifying'")
        promotions.store.db.execute("UPDATE integration_jobs SET state='queued',phase='resuming' WHERE state='verifying'")
    while True:
        try:
            publish(promotions)
            promotions.worker_error = None
            break
        except (OSError, ValueError, subprocess.SubprocessError) as error:
            promotions.worker_error = str(error)[:500]
            log("Native verifier waiting for valid rebuild inputs")
            promotions.wake.wait(30)
            promotions.wake.clear()
    while True:
        job = promotions.take()
        if job is None:
            promotions.wake.wait(30)
            promotions.wake.clear()
            continue
        # A verification that stops moving leaves every thread's stack here (it once hung silently for 24 min).
        stacks = open(promotions.directory / "verifier-stacks.log", "a")
        faulthandler.dump_traceback_later(WATCHDOG_SECONDS, repeat=True, file=stacks)
        try:
            receipt = verify(promotions, job)
        except (OSError, ValueError, RuntimeError, subprocess.SubprocessError) as error:
            receipt = dict(job.get("diagnostics", {}), accepted=False, reason=str(error)[:1000])
            if receipt.get("artifacts"):
                atomic_json(promotions.root / receipt["artifacts"] / "rejection-receipt.json", receipt)
        finally:
            faulthandler.cancel_dump_traceback_later()
            stacks.close()
        try:
            finished = promotions.finish(job, receipt, lambda edits: publish(promotions, edits))
        except (OSError, ValueError, subprocess.SubprocessError) as error:
            receipt = {"accepted": False, "reason": "Could not publish accepted overlays: " + str(error)[:500]}
            finished = promotions.finish(job, receipt)
        if finished and not receipt.get("accepted"):
            from roc.integration_notify import notify
            notify(promotions, job, receipt)
        if finished and receipt.get("accepted"):
            from roc.integration_notify import notify
            candidate = promotions.root / receipt["artifacts"]
            atomic_json(promotions.directory / "progress-native.json",
                        {"addresses": json.loads((candidate / "integration-native.json").read_text())})
            notify(promotions, job, receipt)
            try:
                cache_accepted(promotions, receipt)
            except (OSError, ValueError, subprocess.SubprocessError):
                log("Native verification accepted; optional baseline cache could not be saved")
            log("Native integration accepted %s: %d credits" % (job["id"], receipt["credits"]))
