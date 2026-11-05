"""Recipe-driven native discovery. Local proofs are proposals, never native credit."""
import json
import hashlib
import os
import re
import subprocess
import sys
import time
import uuid
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from types import SimpleNamespace

from roc import fingerprint, integration, libs, match, rebuild, worker

ROOT = Path(__file__).resolve().parent.parent
FLAGS = "/O2 /Ob2 /Oy /GF /GS- /EHsc /MD"
MODES = tuple(os.environ.get("ROC_NATIVE_MODES", "assertions,fp-fast,assertions-fp-fast").split(","))
# TU-wide pragma families, prepended like fp-fast (each mode name lists its parts, joined by '-').
PRAGMAS = {"fp": "#pragma float_control(precise, off)\n", "osize": '#pragma optimize("s", on)\n',
           "noautoinline": "#pragma auto_inline(off)\n"}
OUTPUT_MARKER = 'out.write_text(json.dumps(patches, indent=1) + "\\n", encoding="utf-8")'


def require_private_workspace():
    if (ROOT / "work/server.db").exists():
        raise ValueError("Native finding must use a private contributor checkout; server workspace detected")


def masked_cpp(text):
    """Hide comments and literals without moving any source offsets."""
    pattern = r'//[^\n]*|/\*[\s\S]*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\''
    return re.sub(pattern, lambda m: re.sub(r"[^\n\r]", " ", m[0]), text)


def closing(text, start, left, right):
    depth = 0
    for i in range(start, len(text)):
        if text[i] == left:
            depth += 1
        elif text[i] == right:
            depth -= 1
            if not depth:
                return i
    raise ValueError("Unbalanced C++ source")


def methods(text):
    """Unambiguous out-of-line methods only; constructors/templates/operators defer."""
    clean = masked_cpp(text)
    result = defaultdict(list)
    for found in re.finditer(r"\b(\w+)::(~?\w+)\s*\(", clean):
        end = closing(clean, clean.index("(", found.start()), "(", ")") + 1
        brace = clean.find("{", end)
        if brace < 0 or not re.fullmatch(r"\s*(?:(?:const|volatile|override|final)\s*)*", clean[end:brace]):
            continue
        finish = closing(clean, brace, "{", "}") + 1
        if re.search(r"(?m)^\s*#\s*(?:if|elif|else|endif)\b", clean[brace:finish]):
            continue
        token = found[1] + "::" + found[2]
        result[token].append((found.start(), finish))
    return {token: spans[0] for token, spans in result.items() if len(spans) == 1}


def without_assertions(text):
    """Erase only complete RBXASSERT calls; keep their semicolon/control-flow slot."""
    clean = masked_cpp(text)
    edits = []
    for found in re.finditer(r"\bRBXASSERT\s*\(", clean):
        end = closing(clean, clean.index("(", found.start()), "(", ")") + 1
        if clean[end:].lstrip().startswith(";"):
            edits.append((found.start(), end))
    for start, end in reversed(edits):
        text = text[:start] + re.sub(r"[^\r\n]", " ", text[start:end]) + text[end:]
    return text


def symbol_method(symbol):
    found = re.match(r"^\?([A-Za-z_]\w*)@([A-Za-z_]\w*)@", symbol)
    if found:
        return found[2] + "::" + found[1]
    found = re.match(r"^\?\?1([A-Za-z_]\w*)@", symbol)
    return found[1] + "::~" + found[1] if found else None


def variant(text, mode, selected=None):
    edits = []
    spans = methods(text)
    parts = mode.split("-")
    if "scoped" in parts and "osize" in parts:
        raise ValueError("Scoped size optimization needs an explicit restore profile")
    if "assertions" in parts or "scoped" in parts:
        for token, (start, end) in spans.items():
            if selected is not None and token not in selected:
                continue
            old = text[start:end]
            new = without_assertions(old) if "assertions" in parts else old
            if "scoped" in parts:
                before, after = "", ""
                if "fp" in parts:
                    before += "#pragma float_control(push)\n#pragma float_control(precise, %s)\n" % ("on" if "precise" in parts else "off")
                    after = "#pragma float_control(pop)\n" + after
                if "noautoinline" in parts:
                    previous = re.findall(r"#pragma\s+auto_inline\s*\(\s*(on|off)\s*\)", text[:start])
                    before += PRAGMAS["noautoinline"]
                    after = "#pragma auto_inline(%s)\n" % (previous[-1] if previous else "on") + after
                if "depth0" in parts:
                    previous = re.findall(r"#pragma\s+inline_depth\s*\(\s*([^)]*)\)", text[:start])
                    before += "#pragma inline_depth(0)\n"
                    after = "#pragma inline_depth(%s)\n" % (previous[-1].strip() if previous else "") + after
                if before:
                    new = "\n" + before + new + "\n" + after
            if old != new:
                edits.append([old, new])
    for old, new in edits:
        if text.count(old) != 1:
            raise ValueError("Ambiguous method anchor")
        text = text.replace(old, new, 1)
    if "scoped" in parts:
        return text, edits
    pragmas = "".join(PRAGMAS[p] for p in ("fp", "osize", "noautoinline")
                      if p in parts and not re.match(r"\s*" + re.escape(PRAGMAS[p].strip()), text))
    if pragmas:
        prefix = re.match(r"(?:\s*\n)*[^\n]+\n", text)
        if prefix is None or text.count(prefix[0]) != 1:
            raise ValueError("Ambiguous TU prelude")
        old = prefix[0]
        new = pragmas + old
        text = text.replace(old, new, 1)
        edits.insert(0, [old, new])
    return text, edits


def proven_proposal(text, mode, hits, baseline):
    """A diagnostic can suggest many edits; promote only newly exact native methods."""
    spans = methods(text)
    counts = Counter(h["symbol"] for h in hits if h["addr"] not in baseline)
    witnesses = [h for h in hits if h["addr"] not in baseline and counts[h["symbol"]] == 1
                 and symbol_method(h["symbol"]) in spans]
    if not witnesses:
        return None
    selected = {symbol_method(h["symbol"]) for h in witnesses}
    final, edits = variant(text, mode, selected)
    return {"source": final, "edits": edits, "witnesses": witnesses, "mode": mode} if edits else None


def claim_unit(hit, row):
    unit = row["unit"]
    # Mined factory/RTTI tags can wrap a class name. The compiled native method
    # supplies a real existing class; the scheduling label is not ownership proof.
    method = symbol_method(hit["symbol"])
    return unit if re.fullmatch(r"RBX::(?:\w+::)*\w+", unit) or not method else "RBX::" + method.split("::")[0]


def project_headers(tree):
    return sorted({p.relative_to(tree).as_posix()
                   for folder in ("App", "Network", "Rendering/AppDraw", "Rendering/RenderLib", "RbxView", "RbxViewBase", "RbxGraphics")
                   for p in (tree / folder).rglob("*") if p.suffix.lower() in {".h", ".hpp", ".inl", ".inc"}})


def compilation_contexts(files, tree, overlay):
    contexts = {}
    for prefix, name in (("Network/", "rbxgs-net"), ("Rendering/AppDraw/", "rbxgs-appdraw"),
                         ("Rendering/RenderLib/", "rbxgs-render"), ("RbxView/", "rbxgs-view")):
        if not any(rel.startswith(prefix) for rel in files):
            continue
        recipe = libs.RECIPES[name]
        roots = [libs._case_path(libs.LIBS / p).resolve() for p in recipe["include"] if p != "WINSDK"]
        contexts[prefix] = (rebuild._overlaid(roots, [], (tree, overlay))[0], recipe["defines"] + " BOOST_ALL_NO_LIB")
    return contexts


def header_families(tree, overlay, files, extra=()):
    """Conservative project-include graph: duplicate basenames add work, never hide dependents."""
    paths = set(project_headers(tree)) | set(files)
    texts = {rel: (overlay / rel if (overlay / rel).exists() else tree / rel).read_text(errors="replace")
             for rel in paths}
    reverse = defaultdict(set)
    for rel, text in texts.items():
        for name in re.findall(r'^\s*#\s*include\s*[<"]([^>"\n]+)[>"]', text, re.M):
            reverse[Path(name).name].add(rel)
    ranked = []
    for rel, text in texts.items():
        changed = without_assertions(text)
        if rel in files or changed == text and rel not in extra:
            continue
        todo, reached = [Path(rel).name], set()
        while todo:
            for parent in reverse[todo.pop()]:
                if parent not in reached:
                    reached.add(parent)
                    todo.append(Path(parent).name)
        dependent = sorted(reached & set(files))
        if dependent:
            ranked.append({"file": rel, "dependent_tus": len(dependent), "files": dependent,
                           "assertions": len(re.findall(r'\bRBXASSERT\s*\(', text))})
    return sorted(ranked, key=lambda r: (-r["dependent_tus"], -r["assertions"], r["file"]))


def discover_families(config, files, tree, overlay, includes, defines, flags, matcher, targets, owned,
                      by_addr, output, jobs, log, contexts=None):
    """Test shared inline/template assertion bodies through every dependent native TU."""
    custom = config.get("family_edits", {})
    if any(not value.get("evidence") for value in custom.values()):
        raise ValueError("Custom native family edits require recorded evidence")
    ranking = header_families(tree, overlay, files, custom)
    integration.atomic_json(output / "family-ranking.json", ranking)
    selected = config["header_families"]
    families = ranking[:selected] if isinstance(selected, int) else [r for r in ranking if r["file"] in selected]
    affected = sorted({rel for f in families for rel in f["files"]})
    texts = {rel: (overlay / rel if (overlay / rel).exists() else tree / rel).read_text(errors="replace")
             for rel in affected}
    records, baseline, checks, proposals = [], {}, [], []
    cache_output = Path(config.get("family_cache", output))
    def compile_file(item):
        rel, label, shadow, _ = item
        roots, unit_defines = next((v for prefix, v in (contexts or {}).items() if rel.startswith(prefix)), (includes, defines))
        if shadow != overlay:
            original_roots, roots = roots, []
            for inc in original_roots:
                for base in (overlay, tree):
                    if Path(inc).is_relative_to(base):
                        roots.append(shadow / Path(inc).relative_to(base))
                        break
            roots += original_roots
        try:
            result = compile_unit(texts[rel], rel, label, cache_output, tree, shadow, roots, unit_defines, flags)
        except ValueError as error:
            result = {"file": rel, "mode": label, "ok": False, "error": str(error)}
        result["hits"] = matcher.scan(Path(result["object"]).read_bytes()) if result["ok"] else []
        return result
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for result in pool.map(compile_file, [(rel, "family-baseline", overlay, includes) for rel in affected]):
            baseline[result["file"]] = result
            records.append(result)
            log("native family baseline %s: %d exact code+data" % (result["file"], len(result["hits"])))
            integration.atomic_json(output / "trials.json", records)
            integration.atomic_json(output / "progress.json", {"phase": "family-baseline", "tried": len(records),
                "total": len(affected), "translation_unit": result["file"]})
        for number, family in enumerate(families, 1):
            header = family["file"]
            old = (overlay / header if (overlay / header).exists() else tree / header).read_text(errors="replace")
            new = old
            if header in custom:
                for anchor, replacement in custom[header]["edits"]:
                    if not anchor or new.count(anchor) != 1:
                        raise ValueError("Stale or ambiguous family anchor: " + header)
                    new = new.replace(anchor, replacement, 1)
            else:
                new = without_assertions(old)
            shadow = cache_output / "families" / integration.digest(header)[:16] / "overlay"
            # Copy project headers so nested relative includes also see the changed header.
            for rel in project_headers(tree):
                if rel == header:
                    continue
                src = overlay / rel if (overlay / rel).exists() else tree / rel
                target = shadow / rel
                data = src.read_bytes()
                target.parent.mkdir(parents=True, exist_ok=True)
                if not target.exists() or target.read_bytes() != data:
                    target.write_bytes(data)
            path = shadow / header
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(new, encoding="utf-8")
            roots = []
            for inc in includes:
                inc = Path(inc)
                for base in (overlay, tree):
                    if inc.is_relative_to(base):
                        roots.append(shadow / inc.relative_to(base))
                        break
            roots += includes
            witnesses, failed, losses, proof = {}, [], set(), []
            trial = [(rel, "header-" + integration.digest(header)[:16], shadow, roots) for rel in family["files"]]
            for result in pool.map(compile_file, trial):
                records.append(result)
                before = baseline[result["file"]]
                if not before["ok"] or not result["ok"]:
                    failed.append(result["file"])
                    continue
                previous = {h["addr"] for h in before["hits"]}
                current = {h["addr"] for h in result["hits"]}
                losses.update(previous & owned - current)
                candidates = [h for h in result["hits"] if h["addr"] in targets - owned - previous]
                if candidates:
                    kept, deferred = ownership_witnesses(Path(result["object"]).read_bytes(), candidates)
                    checks.extend(dict(h, file=header, translation_unit=result["file"]) for h in deferred)
                    for hit in kept:
                        hit = dict(hit, claim_unit=claim_unit(hit, by_addr[hit["addr"]]), object=result["object"])
                        witnesses[hit["addr"]] = hit
                proof.append(result["object"])
                integration.atomic_json(output / "progress.json", {"phase": "header-families", "family": number,
                    "total_families": len(families), "header": header, "translation_unit": result["file"],
                    "local_unique_candidates": len(witnesses)})
            safe = not failed and not losses
            row = dict(family, gains=len(witnesses), lost_owned=sorted(losses), failed=failed, safe=safe)
            integration.atomic_json(shadow.parent / "result.json", row)
            log("native family %s: %d unique candidates, %d losses, %d compile failures" %
                (header, len(witnesses), len(losses), len(failed)))
            if safe and witnesses:
                proposals.append({"file": header, "edits": [[old, new]],
                                  "mode": "shared-header-source" if header in custom else "shared-header-assertions",
                                  "evidence": custom.get(header, {}).get("evidence", "Shared inline/template assertion profile"),
                                  "witnesses": list(witnesses.values()),
                                  "proof": {"object": proof[0], "objects": proof, "losses": [],
                                            "dependent_tus": family["dependent_tus"]}})
            integration.atomic_json(output / "trials.json", records)
            integration.atomic_json(output / "proposals.json", proposals)
    integration.atomic_json(output / "ownership-checks.json", checks)
    return records, proposals, checks


def split_families(spec, selected, name, server, jobs, output, log):
    """Retry disjoint halves against the latest accepted baseline, retaining server gates."""
    middle = len(selected) // 2
    results = []
    for index, group in enumerate((selected[:middle], selected[middle:])):
        config = dict(spec["native_sweep"], header_families=[p["file"] for p in group], settle_jobs=[],
                      family_cache=str(spec["native_sweep"].get("family_cache", output)))
        config.pop("after_job", None)
        integration.command(SimpleNamespace(action="sync", server=server, user=None, token=integration.native_token()))
        results.append(run(dict(spec, native_sweep=config), name + "-split-%d" % index, server, jobs,
                           output=output / ("split-%d" % index), log=log))
    return results


def ownership_witnesses(obj, witnesses):
    """Match the server's global unique-body ownership rule, beyond the discovery pool."""
    symbols = {h["symbol"] for h in witnesses}
    pairs = rebuild.pair("2008-06", [f for f in match.coff_functions(obj) if f[0] in symbols])
    unique = {(symbol, addrs[0]) for symbol, _, addrs in pairs if len(addrs) == 1}
    kept = [h for h in witnesses if (h["symbol"], h["addr"]) in unique]
    deferred = [dict(h, reason="Not uniquely owned across the whole client") for h in witnesses
                if (h["symbol"], h["addr"]) not in unique]
    return kept, deferred


def experiments(text, modes=MODES):
    seen, result = set(), []
    for mode in ("baseline", *modes):
        try:
            source = text if mode == "baseline" else variant(text, mode)[0]
            key = hashlib.sha256(source.encode()).hexdigest()
            if key not in seen:
                seen.add(key)
                result.append((mode, source, None))
        except ValueError as error:
            result.append((mode, None, str(error)))
    return result


class Matcher:
    def __init__(self, addresses):
        self.target = fingerprint.Target("2008-06")
        self.index = defaultdict(list)
        functions = match._functions("2008-06")
        for addr in sorted(addresses):
            if addr in functions and functions[addr].get("kind", "code") == "code":
                self.index[functions[addr]["size"]].append(addr)

    def scan(self, obj):
        found = {}
        for symbol, code, relocs in match.coff_functions(obj):
            if len(code) < 6:
                continue
            refs = None
            for addr in self.index.get(len(code), []):
                if addr in found:
                    continue
                exe = self.target.same(addr, code, relocs)
                if exe is None:
                    continue
                # Shared tiny bodies can hit many addresses. Parse this symbol's
                # COFF data once, while checking each target's referenced bytes.
                if refs is None:
                    refs = match.coff_data_refs(obj, symbol)
                _, bad = match.data_check("2008-06", addr, exe, refs)
                if not bad:
                    found[addr] = symbol
        return [{"addr": addr, "symbol": found[addr]} for addr in sorted(found)]


def compile_unit(source, rel, label, output, tree, overlay, includes, defines, flags):
    folder = output / "objects" / integration.digest([rel, label])[:20]
    folder.mkdir(parents=True, exist_ok=True)
    unit = folder / Path(rel).name
    if not unit.exists() or unit.read_text(encoding="utf-8") != source:
        unit.write_text(source, encoding="utf-8")
    siblings = [overlay / Path(rel).parent, tree / Path(rel).parent]
    started = time.monotonic()
    result = rebuild.compile_direct("2008-06", [unit], folder, siblings + includes, defines, flags)
    ok, message = result[str(unit)]
    logs = output / "logs"
    logs.mkdir(exist_ok=True)
    (logs / (folder.name + ".log")).write_text(message, encoding="utf-8")
    obj = unit.with_suffix(".obj")
    return {"file": rel, "mode": label, "ok": ok, "seconds": round(time.monotonic() - started, 3),
            "object": str(obj), "source_sha256": hashlib.sha256(source.encode()).hexdigest(),
            "object_sha256": hashlib.sha256(obj.read_bytes()).hexdigest() if ok else None,
            "error": message if not ok else None}


def foreign_claims(user, identity):
    """Classes with a live claim (claimed/submitted/parked) by any other worker, from the host server DB."""
    import sqlite3
    path = Path(os.environ.get("ROC_NATIVE_EVIDENCE_ROOT", ROOT)) / "work/server.db"
    if not path.exists():
        return set()  # contributor PC without the server DB: the server's claim checks still apply
    db = sqlite3.connect("file:%s?mode=ro" % path.as_posix(), uri=True, timeout=30)
    try:
        return {unit for unit, worker in db.execute("SELECT unit,worker FROM integration_claims WHERE expires>?",
                                                    (time.time(),)) if not worker.endswith(identity)}
    finally:
        db.close()


def stage_generator(generator, original, additions):
    require_private_workspace()
    if generator.read_bytes() != original:
        raise ValueError("Generator changed during discovery; proposals saved, edits not applied")
    text = original.decode("utf-8")
    if text.count(OUTPUT_MARKER) != 1:
        raise ValueError("Generator output anchor is ambiguous")
    integration.validate_patches(additions)
    block = ("# Native sweep: method-scoped corrections passed exact code/data preflight.\n"
             "for native_file, native_edits in json.loads(%r).items():\n"
             "    patches.setdefault(native_file, []).extend(native_edits)\n\n") % json.dumps(additions, sort_keys=True)
    generator.write_bytes(text.replace(OUTPUT_MARKER, block + OUTPUT_MARKER).encode("utf-8"))


def wait_for_job(api, identifier, timeout, log):
    deadline, previous = time.monotonic() + timeout, None
    while time.monotonic() < deadline:
        try:
            jobs = api.call("/v1/integration?id=" + identifier)["jobs"]
        except worker.ApiFailure as error:
            if error.category not in ("offline", "server_fail"):
                raise
            if previous != ("offline", error.category):
                log("Native server unavailable; retaining job %s and retrying: %s" % (identifier, error))
            previous = ("offline", error.category)
            time.sleep(5)
            continue
        if not jobs:
            raise ValueError("Native job missing: " + identifier)
        job = jobs[0]
        phase = (job["state"], job["phase"])
        if phase != previous:
            log("native job %s: %s / %s" % (identifier, *phase))
            previous = phase
        if job["state"] in ("accepted", "rejected"):
            return job
        time.sleep(5)
    raise TimeoutError("Native verification still pending: " + identifier)


def wait_for_campaign(prerequisite, timeout, log):
    path = Path(prerequisite["summary"])
    expected = prerequisite["run_id"]
    started, last = time.monotonic(), None
    while time.monotonic() - started < timeout:
        saved = path.parent / "runs" / (expected + ".json")
        current = saved if saved.exists() else path
        if current.exists():
            result = json.loads(current.read_text(encoding="utf-8"))
            if result.get("run_id") == expected:
                state = result.get("state")
                if state != last:
                    log("native prerequisite campaign %s: %s" % (expected, state))
                    last = state
                if state in {"accepted", "rejected", "split-complete", "no-proposals", "proposals", "staged"}:
                    return result
        time.sleep(5)
    raise TimeoutError("Native prerequisite campaign did not finish: " + expected)


def run(spec, name, server=None, jobs=4, limit=None, output=None, log=print):
    """Discover, minimize, recompile, claim, stage, and optionally submit real native fixes."""
    require_private_workspace()
    config = spec["native_sweep"]
    if spec.get("client", "2008-06") != "2008-06":
        raise ValueError("Native sweep supports the coherent 2008-06 module only")
    output = Path(output or ROOT / "work/research" / name)
    output.mkdir(parents=True, exist_ok=True)
    run_id = uuid.uuid4().hex
    integration.atomic_json(output / "summary.json", {"recipe": name, "state": "running", "run_id": run_id, "new_verified": 0})
    def finish(summary):
        summary.update(run_id=run_id, state=summary.get("state") or ("queued" if summary.get("job") else "staged" if summary.get("applied_files") else "proposals" if summary.get("proposed_files") else "no-proposals"))
        integration.atomic_json(output / "summary.json", summary)
        integration.atomic_json(output / "runs" / (run_id + ".json"), summary)
        return summary
    settings = worker.load_settings()
    api = worker.Api(server or settings["server"], integration.native_token() or settings.get("native_token") or settings.get("token"))
    claimed, used = [], set()
    keep_claims = False
    generator = ROOT / "rebuild/2008-06/patches/make_rbxgs_client.py"
    try:
        if config.get("submit") and not config.get("model"):
            raise ValueError("Submission requires actual model identity")
        if config.get("after_campaign"):
            wait_for_campaign(config["after_campaign"], config.get("verify_timeout", 4 * 3600), log)
        for identifier in config.get("settle_jobs", []):
            wait_for_job(api, identifier, config.get("verify_timeout", 4 * 3600), log)
        if config.get("after_job"):
            prior = wait_for_job(api, config["after_job"], config.get("verify_timeout", 4 * 3600), log)
            if prior["state"] != "accepted" or not prior["receipt"].get("accepted"):
                raise ValueError("Prerequisite native batch was rejected; discovery not started")
        if config.get("after_campaign") or config.get("after_job") or config.get("settle_jobs"):
            integration.command(SimpleNamespace(action="sync", server=server, user=None, token=integration.native_token()))
        original = generator.read_bytes()
        base = api.call("/v1/integration/base")
        if hashlib.sha256(original).hexdigest() != base["generator"]:
            raise ValueError("Sync accepted work and preserve unsent generator edits before sweeping")
        overlay_file = generator.with_name("rbxgs-client.json")
        if json.loads(overlay_file.read_text()) != base["overlay"]:
            raise ValueError("Local overlay differs from server baseline; sync first")
        module = rebuild.load_module("2008-06", "rbxgs-app")
        tree, overlay = rebuild.build_overlay("2008-06", "RbxgsApp", module["overlay"])
        recipe = libs.RECIPES["rbxgs"]
        includes = [libs._case_path(libs.LIBS / path).resolve() for path in recipe["include"] if path != "WINSDK"]
        includes = rebuild._overlaid(includes, [], (tree, overlay))[0]
        defines = recipe["defines"] + " BOOST_ALL_NO_LIB"
        flags = config.get("flags", FLAGS)
        # Discovery reads installed manifests only. Mutable source/output trees stay private.
        evidence_root = Path(os.environ.get("ROC_NATIVE_EVIDENCE_ROOT", ROOT))
        manifest = Path(config.get("manifest", evidence_root / "rebuild/2008-06/manifests/functions.json"))
        rows = json.loads(manifest.read_text(encoding="utf-8"))
        by_addr = {row["addr"]: row for row in rows}
        owned_path = Path(config.get("owned_report", evidence_root / "rebuild/2008-06/out/RbxgsApp/report.json"))
        owned = set(json.loads(owned_path.read_text()).get("owned_addrs", [])) if owned_path.exists() else set()
        for job in api.call("/v1/integration")["jobs"]:
            if job["state"] == "accepted":
                owned.update(job["receipt"].get("gains", []))
        targets = {row["addr"] for row in rows if row.get("score") == 100
                   and row.get("source_kind") in config.get("source_kinds", ["snippet"])
                   and row.get("unit", "").startswith("RBX::")}
        if config.get("new_coverage_only"):
            covered = evidence_root / "work/integration/progress-native.json"
            targets -= set(json.loads(covered.read_text())["addresses"])
        if spec.get("targets", {}).get("addresses"):
            targets &= set(spec["targets"]["addresses"])
        matcher = Matcher(targets | owned)
        files = sorted({p.relative_to(tree).as_posix() for pattern in config.get("files", ["App/*/*.cpp"])
                        for p in tree.glob(pattern) if not p.name.startswith("roc_")})
        if limit:
            files = files[:limit]
        contexts = compilation_contexts(files, tree, overlay)
        rebuild.toolchain()  # Resolve discovery once before compile workers start.
        texts = {rel: (overlay / rel if (overlay / rel).exists() else tree / rel).read_text(errors="replace") for rel in files}
        if config.get("header_families"):
            records, proposals, ownership_checks = discover_families(config, files, tree, overlay, includes,
                defines, flags, matcher, targets, owned, by_addr, output, jobs, log, contexts)
        else:
            trials = [(rel, *trial) for rel in files for trial in experiments(texts[rel], config.get("modes", MODES))]
            records, proofs, baseline_hits, baseline_ready = [], defaultdict(list), {}, set()
            ownership_checks = []
            def compile_trial(item):
                rel, mode, source, error = item
                if error:
                    return {"file": rel, "mode": mode, "ok": False, "error": error, "seconds": 0}
                try:
                    roots, unit_defines = next((v for prefix, v in contexts.items() if rel.startswith(prefix)), (includes, defines))
                    return compile_unit(source, rel, mode, output, tree, overlay, roots, unit_defines, flags)
                except ValueError as error:
                    return {"file": rel, "mode": mode, "ok": False, "error": str(error), "seconds": 0}
            with ThreadPoolExecutor(max_workers=jobs) as pool:
                for result in pool.map(compile_trial, trials):
                    result["hits"] = matcher.scan(Path(result["object"]).read_bytes()) if result["ok"] else []
                    records.append(result)
                    rel, mode = result["file"], result["mode"]
                    if mode == "baseline":
                        baseline_hits[rel] = {h["addr"] for h in result["hits"]}
                        if result["ok"]:
                            baseline_ready.add(rel)
                    elif result["ok"] and rel in baseline_ready:
                        exclude = baseline_hits.get(rel, set())
                        if config.get("retain_existing_objects"):
                            exclude = exclude & owned
                        proposal = proven_proposal(texts[rel], mode, [h for h in result["hits"] if h["addr"] in targets - owned],
                                                   exclude)
                        if proposal:
                            witnesses, deferred = ownership_witnesses(Path(result["object"]).read_bytes(), proposal["witnesses"])
                            ownership_checks.extend(dict(h, file=rel, mode=mode) for h in deferred)
                            proposal = proven_proposal(texts[rel], mode, witnesses, exclude)
                        if proposal:
                            proposal["file"] = rel
                            for hit in proposal["witnesses"]:
                                hit["claim_unit"] = claim_unit(hit, by_addr[hit["addr"]])
                            proofs[rel].append(proposal)
                    log("native %s %s: %d exact code+data" % (rel, mode, len(result["hits"])))
                    integration.atomic_json(output / "trials.json", records)
                    integration.atomic_json(output / "progress.json", {"phase": "discovery", "tried": len(records), "total": len(trials), "file": rel, "mode": mode})
            proposals, final_checks = [], []
            for rel, choices in proofs.items():
                for proposal in sorted(choices, key=lambda p: (-len(p["witnesses"]), len(p["edits"]))):
                    roots, unit_defines = next((v for prefix, v in contexts.items() if rel.startswith(prefix)), (includes, defines))
                    final = compile_unit(proposal["source"], rel, "final-" + proposal["mode"], output, tree, overlay, roots, unit_defines, flags)
                    hits = matcher.scan(Path(final["object"]).read_bytes()) if final["ok"] else []
                    if final["ok"]:
                        proposal["witnesses"], deferred = ownership_witnesses(Path(final["object"]).read_bytes(), proposal["witnesses"])
                        ownership_checks.extend(dict(h, file=rel, mode=proposal["mode"]) for h in deferred)
                    addresses = {h["addr"] for h in hits}
                    wanted = {h["addr"] for h in proposal["witnesses"]}
                    lost = (baseline_hits[rel] & owned) - addresses
                    proposal["proof"] = dict(final, hits=hits, losses=sorted(lost))
                    final_checks.append(proposal["proof"])
                    proposal.pop("source")
                    if wanted and not lost and wanted <= addresses:
                        proposals.append(proposal)
                        break
            integration.atomic_json(output / "proposals.json", proposals)
            integration.atomic_json(output / "final-checks.json", final_checks)
            integration.atomic_json(output / "ownership-checks.json", ownership_checks)
        summary = {"recipe": name, "client": "2008-06", "op": "native-grid", "tried": len(records),
                   "proposed_files": len(proposals), "local_exact": len({h["addr"] for p in proposals for h in p["witnesses"]}),
                   "eligible_targets": len(targets - owned), "starting_revision": base["revision"],
                   "deferred_ownership": len(ownership_checks),
                   "new_verified": 0}
        if not proposals or not config.get("apply"):
            return finish(summary)
        if api.call("/v1/integration/base")["revision"] != base["revision"]:
            raise ValueError("Accepted baseline changed; rerun discovery before applying")
        identity_file = ROOT / "work/integration-client/identity.json"
        if not identity_file.exists():
            integration.atomic_json(identity_file, {"id": uuid.uuid4().hex})
        identity = json.loads(identity_file.read_text())["id"][:12]
        units, selected = {}, []
        max_claims = base.get("limits", {}).get("claims", 16)
        for proposal in proposals:
            needed = {h["claim_unit"] for h in proposal["witnesses"]}
            if len(set(units) | needed) > max_claims:
                continue
            for unit in sorted(needed - set(units)):
                result = api.call("/v1/integration/claim", {"user": settings["user"], "worker": settings["user"] + "@native-sweep:" + identity,
                                                          "unit": unit, "count": 1})
                if result["claims"]:
                    claim = result["claims"][0]
                    claimed.append(claim)
                    if claim["base_revision"] != base["revision"]:
                        raise ValueError("Claim baseline changed; rerun discovery")
                    units[unit] = claim
            # Gains are credited from the linked rebuild, not per claim: take a proposal when it holds at least one
            # claim and no other worker holds a live claim on any class it touches (catalog-less classes and
            # sub-24-byte targets cannot be claimed at all).
            if not needed & foreign_claims(settings["user"], identity):
                selected.append(proposal)  # rides on any claim this batch holds; at least one is required below
        if selected and not units:
            result = api.call("/v1/integration/claim", {"user": settings["user"], "worker": settings["user"] + "@native-sweep:" + identity,
                                                      "count": 1})
            for claim in result["claims"]:
                claimed.append(claim)
                units[claim["unit"]] = claim
        used = {h["claim_unit"] for p in selected for h in p["witnesses"]} & units.keys()
        if selected and not used and units:
            used = {sorted(units)[0]}  # carrier claim for catalog-less classes
        additions = {p["file"]: p["edits"] for p in selected}
        if not additions or not used:
            return finish(summary)
        for unit in used:
            claim = units[unit]
            folder = ROOT / "work/integration-client/claims" / claim["id"]
            integration.atomic_json(folder / "packet.json", claim)
            (folder / "generator-base.py").write_bytes(original)
        notes = output / "batch-notes.txt"
        notes.write_text("Native source experiment: real methods and shared header/template bodies under recorded profiles.\n"
                         "Every listed method passed exact instruction and referenced-data checks in the recorded native objects.\n"
                         "Existing exact object bodies may be retained by inline settings; only independent linked gains earn credit.\n"
                         "Per-TU previously owned matches preserved; independent linked/runtime/ABI gates still required.\n\n" +
                         "\n".join("Claim %s scheduling addresses: %s. Factory/RTTI tags may differ; exact native proof follows." %
                                   (unit, " ".join(units[unit]["addresses"][:3])) for unit in sorted(used)) + "\n\n" +
                         "\n".join("%s: %s %s; %s; object %s" % (h["claim_unit"], h["addr"], h["symbol"], p["mode"], p["proof"]["object"])
                                   for p in selected for h in p["witnesses"]) + "\n\n" +
                         "\n".join(p.get("evidence", "") for p in selected), encoding="utf-8")
        batch = output / "batch.json"
        integration.atomic_json(batch, {"claims": [units[u]["id"] for u in sorted(used)]})
        (output / "generator-base.py").write_bytes(original)
        stage_generator(generator, original, additions)
        staged_generator = generator.read_bytes()
        try:
            subprocess.run([sys.executable, str(generator)], cwd=ROOT, check=True, capture_output=True)
            integration.overlay_delta(base["overlay"], json.loads(overlay_file.read_text()))
        except BaseException:
            generator.write_bytes(original)
            subprocess.run([sys.executable, str(generator)], cwd=ROOT, check=True, capture_output=True)
            raise
        summary.update(applied_files=len(selected), batch=str(batch), evidence=str(notes))
        keep_claims = True
        if config.get("submit"):
            args = SimpleNamespace(action="submit", server=server, user=None, token=integration.native_token(),
                                   claim=None, all=False, batch=str(batch), model=config["model"], evidence_file=str(notes), retry=False, wait=False)
            integration.command(args)
            marker = ROOT / "work/integration-client/claims" / units[sorted(used)[0]]["id"] / "job.json"
            summary["job"] = json.loads(marker.read_text())["id"]
            finish(summary)
            if config.get("wait"):
                job = wait_for_job(api, summary["job"], config.get("verify_timeout", 4 * 3600), log)
                summary.update(state=job["state"], receipt=job["receipt"])
                if job["state"] == "accepted" and job["receipt"].get("accepted"):
                    summary["new_verified"] = job["receipt"].get("credits", 0)
                    integration.command(SimpleNamespace(action="sync", server=server, user=None, token=integration.native_token()))
                elif job["state"] == "rejected" and config.get("header_families") and config.get("split_rejected") and len(selected) > 1:
                    if generator.read_bytes() != staged_generator:
                        raise ValueError("Private generator changed; preserve edits before splitting rejected families")
                    generator.write_bytes(original)
                    subprocess.run([sys.executable, str(generator)], cwd=ROOT, check=True, capture_output=True)
                    for claim in claimed:
                        api.call("/v1/integration/release", {"user": settings["user"], "claim": claim["id"]})
                    claimed.clear()
                    summary["split_results"] = split_families(spec, selected, name, server, jobs, output, log)
                    summary["new_verified"] = sum(r.get("new_verified", 0) for r in summary["split_results"])
                    summary["state"] = "split-complete"
        return finish(summary)
    finally:
        for claim in claimed:
            if not keep_claims or claim["unit"] not in used:
                try:
                    api.call("/v1/integration/release", {"user": settings["user"], "claim": claim["id"]})
                except worker.ApiFailure as error:
                    log("Claim release failed (%s): %s" % (claim["id"], error))
        api.close()
