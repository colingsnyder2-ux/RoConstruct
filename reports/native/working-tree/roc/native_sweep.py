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
    if "assertions" in mode:
        for token, (start, end) in spans.items():
            if selected is not None and token not in selected:
                continue
            old = text[start:end]
            new = without_assertions(old)
            if old != new:
                edits.append([old, new])
    for old, new in edits:
        if text.count(old) != 1:
            raise ValueError("Ambiguous method anchor")
        text = text.replace(old, new, 1)
    parts = mode.split("-")
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
    return unit if re.fullmatch(r"RBX::(?:\w+::)*\w+", unit) else "RBX::" + symbol_method(hit["symbol"]).split("::")[0]


def experiments(text):
    seen, result = set(), []
    for mode in ("baseline", *MODES):
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
        jobs = api.call("/v1/integration?id=" + identifier)["jobs"]
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


MODEL_RULES = """You repair real 2008 Roblox C++ so MSVC compiles it to the exact bytes of the 2008 exe.
Edit ONLY the file below. Reply with one or more blocks, nothing else:
<<<<<<< SEARCH
exact old text, copied verbatim from the file
=======
new text
>>>>>>> REPLACE
Each SEARCH text must occur exactly once in the file as shown. Blocks apply in order.
The mined sources are byte-exact proofs written with placeholder types: copy their control flow, call order,
constants and evaluation order, but use the real classes, members and methods. "standins" maps each placeholder
to the real symbol, RTTI type or import the exe uses at that spot. Never add padding structs, offset views,
invented fields, inline asm or casts to raw offsets. Keep every other method unchanged."""


def strip_asm(source):
    return "\n".join(line for line in source.splitlines() if not re.match(r"//\s*[0-9a-f]{8}\s", line))


def target_files(texts, wanted, names, by_addr):
    """{file: [addr]}: a target goes to the file defining its rebuilt method, else to the file named for its class."""
    spans = {rel: methods(text) for rel, text in texts.items()}
    stems = defaultdict(list)
    for rel in texts:
        stems[Path(rel).stem.lower()].append(rel)
    out = defaultdict(list)
    for addr in sorted(wanted):
        symbol = names.get(addr, {}).get("symbol")
        method = symbol_method(symbol) if symbol else None
        homes = [rel for rel in texts if method and method in spans[rel]]
        if not homes:
            homes = stems.get(by_addr.get(addr, {}).get("unit", "").rsplit("::", 1)[-1].lower(), [])
        if len(homes) == 1:
            out[homes[0]].append(addr)
    return out


def model_evidence(addr, names, by_addr):
    from roc import packet, standins
    source = packet._source("2008-06", addr)[0]
    code = match.target("2008-06", addr)[0]
    item = {"addr": addr, "size": by_addr.get(addr, {}).get("size"), "rebuilt": names.get(addr),
            "mined_source": strip_asm(source)[:4000], "target_asm": match.disasm(code, int(addr, 16))[:120]}
    try:
        item["standins"] = standins.mapping("2008-06", addr, source)
    except Exception as error:  # noqa: BLE001 - the map is optional evidence
        item["standins_error"] = str(error)[:200]
    return item


def body_diff(obj, symbol, addr, limit=40):
    """Unified diff of target vs rebuilt instructions for one method; long immediates (addresses) are masked."""
    import difflib
    code = {name: body for name, body, _ in match.coff_functions(obj)}.get(symbol)
    if code is None:
        return "rebuilt symbol %s is not in this object" % symbol
    va = int(addr, 16)

    def norm(lines):
        return [re.sub(r"0x[0-9a-f]{5,}", "X", line[31:]) for line in lines]
    lines = list(difflib.unified_diff(norm(match.disasm(match.target("2008-06", addr)[0], va)),
                                      norm(match.disasm(code, va)), "target", "rebuilt", n=1, lineterm=""))
    return "\n".join(lines[:limit]) + ("\n..." if len(lines) > limit else "") if lines else "identical after masking"


def excerpt(text, symbols, around=20):
    """The file's #include lines plus each target method with `around` lines of context, verbatim, so SEARCH
    blocks still anchor in the full file. Falls back to the whole file when no target method is found."""
    spans, lines = methods(text), text.split("\n")
    starts = [0]
    for line in lines:
        starts.append(starts[-1] + len(line) + 1)

    def line_of(offset):
        return max(0, next(i for i, start in enumerate(starts) if start > offset) - 1)
    keep = {i for i, line in enumerate(lines) if line.lstrip().startswith("#include")}
    found = False
    for symbol in symbols:
        span = spans.get(symbol_method(symbol))
        if span:
            found = True
            keep.update(range(max(0, line_of(span[0]) - around), min(len(lines), line_of(span[1]) + around + 1)))
    if not found:
        return text
    out, last = [], -1
    for i in sorted(keep):
        if i != last + 1:
            out.append("// ...")
        out.append(lines[i])
        last = i
    return "\n".join(out)


def apply_edits(text, edits):
    if not isinstance(edits, list) or not edits:
        raise ValueError("no edits")
    for pair in edits:
        if not (isinstance(pair, list) and len(pair) == 2 and all(isinstance(p, str) for p in pair)) or not pair[0]:
            raise ValueError("each edit must be [old, new] strings with non-empty old")
        if text.count(pair[0]) != 1:
            raise ValueError("old text occurs %d times, need exactly 1: %r" % (text.count(pair[0]), pair[0][:80]))
        text = text.replace(pair[0], pair[1], 1)
    return text


EDIT_BLOCK = re.compile(r"<{7} SEARCH\n(.*?)\n={7}\n(.*?)\n?>{7} REPLACE", re.S)


def parse_edits(reply):
    """SEARCH/REPLACE blocks: C++ needs no escaping, unlike JSON strings (most JSON replies failed to parse)."""
    edits = [[old, new] for old, new in EDIT_BLOCK.findall(providers_text(reply).replace("\r\n", "\n"))]
    if not edits:
        raise ValueError("reply has no SEARCH/REPLACE block")
    return edits


def providers_text(reply):
    from roc import providers
    return providers.strip_reasoning(reply.text if hasattr(reply, "text") else str(reply))


def model_proposal(rel, text, addrs, baseline, owned, model, rounds, compile_round, matcher, evidence, log, options=None,
                   diff=None, shown=None):
    """Ask the model for anchored edits to one native file; keep the first that makes a new target exact and
    loses no owned exact in that file. Every round compiles the real TU; failures go back as feedback."""
    from roc import providers
    prompt = "%s\n\nFILE %s\n```cpp\n%s\n```\n\nTARGETS (exact 2008 functions this file should produce)\n%s" % (
        MODEL_RULES, rel, (shown or text)[:60000], json.dumps([evidence(a) for a in addrs[:6]], indent=1))
    messages, trials = [{"role": "user", "content": prompt}], []
    for n in range(rounds):
        # Edit blocks are short: no thinking and a small reply cap keep each round to seconds, not a minute.
        # With thinking on, reasoning shares max_tokens: an 8192 cap left 27 of 29 replies without any edit.
        settings = dict({"allow_cloud": True, "timeout": 600, "thinking": "disabled"}, **(options or {}))
        settings.setdefault("max_tokens", 3072 if settings["thinking"] == "disabled" else 32768)
        reply = providers.generate(model, messages, settings)
        log("model %s round %d: %.1fs, %s reasoning tokens" % (rel, n, getattr(reply, "latency_s", 0) or 0,
                                                              getattr(reply, "reasoning_tokens", None)))
        messages.append({"role": "assistant", "content": providers_text(reply)})
        try:
            edits = parse_edits(reply)
            result = compile_round(apply_edits(text, edits), "model-%d" % n)
        except ValueError as error:
            trials.append({"file": rel, "mode": "model-%d" % n, "ok": False, "error": str(error)[:500],
                           "reply": providers_text(reply)[:3000]})
            messages.append({"role": "user", "content": "Rejected: %s\nReply with corrected SEARCH/REPLACE blocks." % error})
            continue
        hits = matcher.scan(Path(result["object"]).read_bytes()) if result["ok"] else []
        found = {h["addr"] for h in hits}
        new, lost = (found & set(addrs)) - baseline, (baseline & owned) - found
        result.update(hits=hits, losses=sorted(lost), reply=providers_text(reply)[:3000])
        trials.append(result)
        log("model %s round %d: %d new exact, %d lost" % (rel, n, len(new), len(lost)))
        if new and not lost:
            # Keep only edits the new exacts need: models rewrite neighbouring methods too, and an unproven
            # behaviour change in a method that was not exact would pass the loss check.
            edits = [pair for pair in edits if pair[0] != pair[1]]
            for pair in list(edits):
                rest = [other for other in edits if other is not pair]
                if not rest:
                    continue
                trial = compile_round(apply_edits(text, rest), "minimize-%d-%d" % (n, len(rest)))
                found = {h["addr"] for h in matcher.scan(Path(trial["object"]).read_bytes())} if trial["ok"] else set()
                if new <= found and not (baseline & owned) - found:
                    edits = rest
            result = compile_round(apply_edits(text, edits), "final-%d" % n)
            hits = matcher.scan(Path(result["object"]).read_bytes()) if result["ok"] else []
            found = {h["addr"] for h in hits}
            if not (new <= found and not (baseline & owned) - found):
                trials.append(dict(result, error="minimized edits lost the proof"))
                return None, trials
            result.update(hits=hits, losses=[])
            return {"file": rel, "edits": edits, "mode": "model",
                    "witnesses": [h for h in hits if h["addr"] in new], "proof": result}, trials
        feedback = result["error"][-1500:] if not result["ok"] else \
            "Compiled. Newly exact: %s. Still not exact: %s. Lost previously exact: %s." % (
                sorted(new) or "none", sorted(set(addrs) - found) or "none", sorted(lost) or "none")
        if result["ok"] and diff:
            data = Path(result["object"]).read_bytes()
            feedback += "".join("\n\n%s target vs your rebuilt code:\n%s" % (a, diff(data, a))
                                for a in sorted(set(addrs) - found)[:2])
        messages.append({"role": "user", "content": feedback + "\nReply with the complete corrected set of "
                         "SEARCH/REPLACE blocks against the ORIGINAL file."})
    return None, trials


def model_discovery(config, texts, wanted, owned, by_addr, matcher, output, jobs, log, compile_source):
    """Model-written proposals for every file that defines a waiting exact target, most targets first."""
    evidence_root = Path(os.environ.get("ROC_NATIVE_EVIDENCE_ROOT", ROOT))
    path = evidence_root / "rebuild/2008-06/out/native-names.json"
    names = json.loads(path.read_text()) if path.exists() else {}
    if config.get("only_rebuilt", True):
        # Near misses first: the rebuild already compiles a body for the address, so the fix is local to that method.
        # Targets with no rebuilt body need new methods and header declarations; .cpp-only edits rarely reach them.
        wanted = {addr for addr in wanted if names.get(addr, {}).get("symbol")}
    homes = target_files(texts, wanted, names, by_addr)
    skip = set(config.get("exclude_files", []))
    files = sorted((rel for rel in homes if rel not in skip), key=lambda rel: -len(homes[rel]))[:config.get("max_files")]
    model, rounds = config["llm"], config.get("rounds", 3)
    options = {key: config[key] for key in ("thinking", "max_tokens") if key in config}
    context = config.get("context", "file")

    def one(rel):
        base = compile_source(texts[rel], rel, "baseline")
        if not base["ok"]:
            return None, [base]
        data = Path(base["object"]).read_bytes()
        baseline = {h["addr"] for h in matcher.scan(data)}

        def diff(obj, addr):
            return body_diff(obj, names[addr]["symbol"], addr) if names.get(addr, {}).get("symbol") else "no rebuilt body"
        try:
            proposal, trials = model_proposal(rel, texts[rel], homes[rel], baseline, owned, model, rounds,
                                              lambda source, label: compile_source(source, rel, label), matcher,
                                              lambda addr: dict(model_evidence(addr, names, by_addr), current_diff=diff(data, addr)),
                                              log, options, diff,
                                              excerpt(texts[rel], [names[a]["symbol"] for a in homes[rel]
                                                                   if names.get(a, {}).get("symbol")])
                                              if context == "methods" else None)
        except Exception as error:  # noqa: BLE001 - one provider/compile failure must not stop the other files
            return None, [base, {"file": rel, "mode": "model", "ok": False, "error": str(error)[:500]}]
        return proposal, [base] + trials

    proposals, records = [], []
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for n, (proposal, trials) in enumerate(pool.map(one, files)):
            records.extend(trials)
            if proposal:
                for hit in proposal["witnesses"]:
                    hit["claim_unit"] = claim_unit(hit, by_addr[hit["addr"]])
                proposals.append(proposal)
            integration.atomic_json(output / "trials.json", records)
            integration.atomic_json(output / "progress.json", {"phase": "model", "files_done": n + 1, "total": len(files),
                                                               "proposals": len(proposals)})
    return proposals, records


def run(spec, name, server=None, jobs=4, limit=None, output=None, log=print):
    """Discover, minimize, recompile, claim, stage, and optionally submit real native fixes."""
    require_private_workspace()
    config = spec["native_sweep"]
    if config.get("llm"):
        config.setdefault("model", config["llm"])  # submissions name the model that wrote the edits
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
        if config.get("after_job"):
            prior = wait_for_job(api, config["after_job"], config.get("verify_timeout", 4 * 3600), log)
            if prior["state"] != "accepted" or not prior["receipt"].get("accepted"):
                raise ValueError("Prerequisite native batch was rejected; discovery not started")
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
        # Every byte-exact mined source kind (snippet, vendor-file, generated-unit) is a target: the linked
        # rebuild owns an address by exact bytes. Snippet-only targeting hid ~5k exact app functions.
        targets = {row["addr"] for row in rows if row.get("score") == 100 and row.get("unit", "").startswith("RBX::")}
        if spec.get("targets", {}).get("addresses"):
            targets &= set(spec["targets"]["addresses"])
        matcher = Matcher(targets | owned)
        files = sorted({p.relative_to(tree).as_posix() for pattern in config.get("files", ["App/*/*.cpp"])
                        for p in tree.glob(pattern) if not p.name.startswith("roc_")})
        if limit:
            files = files[:limit]
        rebuild.toolchain()  # Resolve discovery once before compile workers start.
        texts = {rel: (overlay / rel if (overlay / rel).exists() else tree / rel).read_text(errors="replace") for rel in files}
        if config.get("llm"):
            proposals, records = model_discovery(config, texts, targets - owned, owned, by_addr, matcher, output, jobs, log,
                                                 lambda source, rel, label: compile_unit(source, rel, label, output, tree,
                                                                                         overlay, includes, defines, flags))
            final_checks = [p["proof"] for p in proposals]
            trials = []
        else:
            trials = [(rel, *trial) for rel in files for trial in experiments(texts[rel])]
            records, proofs, baseline_hits, baseline_ready = [], defaultdict(list), {}, set()
            def compile_trial(item):
                rel, mode, source, error = item
                if error:
                    return {"file": rel, "mode": mode, "ok": False, "error": error, "seconds": 0}
                try:
                    return compile_unit(source, rel, mode, output, tree, overlay, includes, defines, flags)
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
                        proposal = proven_proposal(texts[rel], mode, [h for h in result["hits"] if h["addr"] in targets - owned],
                                                   baseline_hits.get(rel, set()))
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
                    final = compile_unit(proposal["source"], rel, "final-" + proposal["mode"], output, tree, overlay, includes, defines, flags)
                    hits = matcher.scan(Path(final["object"]).read_bytes()) if final["ok"] else []
                    addresses = {h["addr"] for h in hits}
                    wanted = {h["addr"] for h in proposal["witnesses"]}
                    lost = (baseline_hits[rel] & owned) - addresses
                    proposal["proof"] = dict(final, hits=hits, losses=sorted(lost))
                    final_checks.append(proposal["proof"])
                    proposal.pop("source")
                    if not lost and wanted <= addresses:
                        proposals.append(proposal)
                        break
        integration.atomic_json(output / "proposals.json", proposals)
        integration.atomic_json(output / "final-checks.json", final_checks)
        summary = {"recipe": name, "client": "2008-06", "op": "native-grid", "tried": len(records),
                   "proposed_files": len(proposals), "local_exact": sum(len(p["witnesses"]) for p in proposals),
                   "new_verified": 0, "files_tried": sorted({r["file"] for r in records})}
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
        notes.write_text("Native sweep: real out-of-line methods; scoped assertion omissions and/or x87 profile.\n"
                         "Every listed method passed exact instruction and referenced-data checks after minimizing edits.\n"
                         "Per-TU previously owned matches preserved; independent linked/runtime/ABI gates still required.\n\n" +
                         "\n".join("Claim %s scheduling addresses: %s. Factory/RTTI tags may differ; exact native proof follows." %
                                   (unit, " ".join(units[unit]["addresses"][:3])) for unit in sorted(used)) + "\n\n" +
                         "\n".join("%s: %s %s; %s; object %s" % (h["claim_unit"], h["addr"], h["symbol"], p["mode"], p["proof"]["object"])
                                   for p in selected for h in p["witnesses"]), encoding="utf-8")
        batch = output / "batch.json"
        integration.atomic_json(batch, {"claims": [units[u]["id"] for u in sorted(used)]})
        (output / "generator-base.py").write_bytes(original)
        stage_generator(generator, original, additions)
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
        return finish(summary)
    finally:
        for claim in claimed:
            if not keep_claims or claim["unit"] not in used:
                try:
                    api.call("/v1/integration/release", {"user": settings["user"], "claim": claim["id"]})
                except worker.ApiFailure as error:
                    log("Claim release failed (%s): %s" % (claim["id"], error))
        api.close()
