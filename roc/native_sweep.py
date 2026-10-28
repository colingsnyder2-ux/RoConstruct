"""Recipe-driven native discovery. Local proofs are proposals, never native credit."""
import json
import hashlib
import functools
import os
import re
import subprocess
import sys
import time
import threading
import uuid
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor, as_completed
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
    return dict(_method_spans(text))


@functools.lru_cache(maxsize=32)
def _method_spans(text):
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
    return tuple((token, spans[0]) for token, spans in result.items() if len(spans) == 1)


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
    found = re.match(r"^\?\?0([A-Za-z_]\w*)@", symbol)
    if found:
        return found[1] + "::" + found[1]
    found = re.match(r"^\?\?1([A-Za-z_]\w*)@", symbol)
    return found[1] + "::~" + found[1] if found else None


def variant(text, mode, selected=None):
    edits = []
    spans = methods(text)
    if any(tag in mode for tag in ("assertions", "nonempty", "ternary", "index")):
        for token, (start, end) in spans.items():
            if selected is not None and token not in selected:
                continue
            old = text[start:end]
            new = without_assertions(old) if "assertions" in mode else old
            if "nonempty" in mode:
                pattern = r"!\s*([A-Za-z_]\w*(?:(?:\.|->)[A-Za-z_]\w*)*)(\.|->)empty\s*\(\s*\)"
                for found in reversed(list(re.finditer(pattern, masked_cpp(new)))):
                    new = new[:found.start()] + "(" + found[1] + found[2] + "size() > 0)" + new[found.end():]
            if "ternary" in mode:
                clean = masked_cpp(new)
                for found in reversed(list(re.finditer(r"\bif\s*\(", clean))):
                    start = clean.index("(", found.start())
                    end = closing(clean, start, "(", ")")
                    arms = re.match(r"\s*return\s+([^;{}]+);\s*else\s*return\s+([^;{}]+);", clean[end + 1:])
                    if arms:
                        yes, no = (new[end + 1 + arms.start(i):end + 1 + arms.end(i)].strip() for i in (1, 2))
                        new = new[:found.start()] + "return (%s) ? (%s) : (%s);" % (new[start + 1:end].strip(), yes, no) + new[end + 1 + arms.end():]
            if "index" in mode:
                pattern = r"\bfor\s*\(\s*(std::size_t|size_t|unsigned\s+int|unsigned|int)\s+\w+\s*="
                for found in reversed(list(re.finditer(pattern, masked_cpp(new)))):
                    new = new[:found.start(1)] + ("int" if "index-int" in mode else "size_t") + new[found.end(1):]
            if old != new:
                edits.append([old, new])
    if mode.startswith("runservice-outofline"):
        if not re.search(r"\bcreate\s*<\s*(?:RBX::)?RunService\s*>\s*\(", masked_cpp(text)):
            return text, []
        declaration = "template __declspec(noinline) RunService* ServiceProvider::create<RunService>() const;"
        namespace = re.search(r"\bnamespace\s+RBX\s*\{", masked_cpp(text))
        if not namespace:
            namespace = re.search(r"\busing\s+namespace\s+RBX\s*;", masked_cpp(text))
            before = masked_cpp(text[:namespace.start()]) if namespace else ""
            if not namespace or before.count("{") != before.count("}"):
                raise ValueError("RunService instantiation needs namespace RBX or its global using directive")
            declaration = "template __declspec(noinline) RBX::RunService* RBX::ServiceProvider::create<RBX::RunService>() const;"
        if declaration not in text:
            prefix = text[:namespace.end()]
            edits.insert(0, [prefix, prefix + "\n\t" + declaration + "\n"])
        if mode.endswith("-no-base"):
            for token, (start, end) in spans.items():
                if not token.endswith("::onServiceProvider") or selected is not None and token not in selected:
                    continue
                old = text[start:end]
                parameters = re.search(r"onServiceProvider\s*\(\s*(?:const\s+)?ServiceProvider\s*\*\s*(\w+)\s*,\s*(?:const\s+)?ServiceProvider\s*\*\s*(\w+)", masked_cpp(old))
                if not parameters:
                    continue
                pattern = r"\b(?:[A-Za-z_]\w*::)+onServiceProvider\s*\(\s*%s\s*,\s*%s\s*\)\s*;" % tuple(re.escape(p) for p in parameters.groups())
                new = old
                for found in reversed(list(re.finditer(pattern, masked_cpp(old)))):
                    new = new[:found.start()] + ";" + new[found.end():]
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
    method = symbol_method(hit["symbol"])
    if method and re.search(r"(?:@|\?\?[01])" + re.escape(method.split("::")[0]) + r"@RBX@@", hit["symbol"]):
        return "RBX::" + method.split("::")[0]
    # Mined factory/RTTI tags can wrap a class name. The compiled native method
    # supplies a real existing class; the scheduling label is not ownership proof.
    return unit if re.fullmatch(r"RBX::(?:\w+::)*\w+", unit) else "RBX::" + method.split("::")[0]


def experiments(text, modes=None):
    seen, result = set(), []
    if modes is not None and (not isinstance(modes, (list, tuple)) or not all(isinstance(m, str) for m in modes)):
        raise ValueError("native modes must be a list of mode names")
    for mode in ("baseline", *(MODES if modes is None else modes)):
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
        self.cache, self.cache_lock = {}, threading.Lock()
        functions = match._functions("2008-06")
        for addr in sorted(addresses):
            if addr in functions and functions[addr].get("kind", "code") == "code":
                self.index[functions[addr]["size"]].append(addr)

    def scan(self, obj):
        key = hashlib.sha256(obj).digest()
        cached = self.cache.get(key)
        if cached is not None:
            return [dict(hit) for hit in cached]
        found, data_index = {}, None
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
                    if data_index is None:
                        data_index = match._coff_data_index(obj)
                    refs = match.coff_data_refs(obj, symbol, index=data_index)
                _, bad = match.data_check("2008-06", addr, exe, refs)
                if not bad:
                    found[addr] = symbol
        hits = [{"addr": addr, "symbol": found[addr]} for addr in sorted(found)]
        with self.cache_lock:
            if len(self.cache) >= 128:
                self.cache.pop(next(iter(self.cache)))
            self.cache[key] = [dict(hit) for hit in hits]
        return hits


def ownership_candidates(obj, hits):
    """Use the server's whole-binary pairing, not the discovery target subset."""
    if not hits:
        return {}
    symbols = {h["symbol"] for h in hits}
    candidates = {symbol: addrs for symbol, _, addrs in rebuild.pair(
        "2008-06", [f for f in match.coff_functions(obj) if f[0] in symbols])}
    return {h["addr"]: candidates.get(h["symbol"], []) for h in hits}


def compile_unit(source, rel, label, output, tree, overlay, includes, defines, flags, translation_unit=None, related_headers=None):
    if related_headers:
        previous, hashes = {}, {}
        try:
            for name, edits in related_headers.items():
                header = (overlay / name).resolve()
                if not header.is_relative_to(overlay.resolve()) or header.suffix.lower() not in (".h", ".hpp", ".inl"):
                    raise ValueError("Paired edits must be headers inside the private overlay")
                if header not in previous:
                    previous[header] = header.read_bytes() if header.exists() else None
                original = header if header.exists() else tree / name
                if not edits:
                    continue
                changed = apply_edits(original.read_text(errors="replace"), edits)
                header.parent.mkdir(parents=True, exist_ok=True)
                header.write_text(changed, encoding="utf-8")
                hashes[name] = hashlib.sha256(changed.encode()).hexdigest()
            result = compile_unit(source, rel, label, output, tree, overlay, includes, defines, flags,
                                  translation_unit=translation_unit)
            result["related_header_sha256"] = hashes
            return result
        finally:
            for header, original in previous.items():
                if original is None:
                    header.unlink(missing_ok=True)
                else:
                    header.write_bytes(original)
    if translation_unit:
        # Trial the genuine header in the private overlay, then compile its real caller.
        # Restoring in finally keeps failed trials and later baselines independent.
        header = (overlay / rel).resolve()
        if not header.is_relative_to(overlay.resolve()):
            raise ValueError("Header trial must stay inside the private overlay")
        previous = header.read_bytes() if header.exists() else None
        header.parent.mkdir(parents=True, exist_ok=True)
        try:
            header.write_text(source, encoding="utf-8")
            caller = overlay / translation_unit
            if not caller.exists():
                caller = tree / translation_unit
            result = compile_unit(caller.read_text(errors="replace"), translation_unit, label + "-header-" +
                                  integration.digest(rel)[:8], output, tree, overlay, includes, defines, flags)
            result.update(file=rel, translation_unit=translation_unit,
                          header_sha256=hashlib.sha256(source.encode()).hexdigest())
            return result
        finally:
            if previous is None:
                header.unlink(missing_ok=True)
            else:
                header.write_bytes(previous)
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
    externals = rebuild.coff_externals(obj.read_bytes()) if ok else {}
    return {"file": rel, "mode": label, "ok": ok, "seconds": round(time.monotonic() - started, 3),
            "object": str(obj), "source_sha256": hashlib.sha256(source.encode()).hexdigest(),
            "object_sha256": hashlib.sha256(obj.read_bytes()).hexdigest() if ok else None,
            "defined_symbols": sorted(name for name, defined in externals.items() if defined),
            "undefined_symbols": sorted(name for name, defined in externals.items() if not defined),
            "error": message if not ok else None}


def foreign_claims(user, identity):
    """Classes with a live claim (claimed/submitted/parked) by any other worker, from the host server DB."""
    import sqlite3
    path = Path(os.environ.get("ROC_NATIVE_EVIDENCE_ROOT", ROOT)) / "work/server.db"
    if not path.exists():
        return set()  # contributor PC without the server DB: the server's claim checks still apply
    db = sqlite3.connect("file:%s?mode=ro" % path.as_posix(), uri=True, timeout=30)
    try:
        return {unit for unit, worker in db.execute("SELECT unit,worker FROM integration_claims WHERE expires>? "
                                                      "AND (state IN ('claimed','submitted') OR state LIKE 'parked:%')",
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
             "import sys\n"
             "sys.path.insert(0, str(Path(__file__).resolve().parents[3]))\n"
             "from roc.integration import merge_patches\n"
             "patches = merge_patches(patches, json.loads(%r))\n\n") % json.dumps(additions, sort_keys=True)
    generator.write_bytes(text.replace(OUTPUT_MARKER, block + OUTPUT_MARKER).encode("utf-8"))


def restore_submitted_baseline(identifier, log=print):
    """Durable submitted snapshots let discovery continue against the unchanged accepted baseline."""
    folder = ROOT / "work/integration-client/jobs" / identifier
    snapshot, base = folder / "submitted-generator.py", folder / "generator-base.py"
    if not snapshot.exists() or not base.exists():
        return
    generator = ROOT / "rebuild/2008-06/patches/make_rbxgs_client.py"
    current = generator.read_bytes()
    if current == base.read_bytes():
        return
    if current != snapshot.read_bytes():
        return log("generator changed after submission; preserved local edits")
    generator.write_bytes(base.read_bytes())
    subprocess.run([sys.executable, str(generator)], cwd=ROOT, check=True, capture_output=True)
    log("submitted snapshot retained; local baseline restored for next discovery")


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
Edit ONLY the file below. Reply with one or more blocks inside one ```cpp fence, nothing else:
<<<<<<< SEARCH
exact old text, copied verbatim from the file
=======
new text
>>>>>>> REPLACE
Each SEARCH text must occur exactly once in the file as shown. Blocks apply in order.
Prefer one target and 1-3 small blocks. Include enough unchanged method context to make every anchor unique.
The mined sources are byte-exact proofs written with placeholder types: copy their control flow, call order,
constants and evaluation order, but use the real classes, members and methods. "standins" maps each placeholder
to the real symbol, RTTI type or import the exe uses at that spot. Never add padding structs, offset views,
invented fields, inline asm or casts to raw offsets. Keep every other method unchanged."""


def strip_asm(source):
    return "\n".join(line for line in source.splitlines() if not re.match(r"//\s*[0-9a-f]{8}\s", line))


def target_files(texts, wanted, names, by_addr):
    """{file: [addr]}: a target goes to the file defining its rebuilt method. Only a target without a rebuilt
    method falls back to the file named for its class; a rebuilt method no file defines (declared, body elsewhere
    or absent) cannot be fixed here and is skipped."""
    spans = {rel: methods(text) for rel, text in texts.items()}
    stems = defaultdict(list)
    for rel in texts:
        stems[Path(rel).stem.lower()].append(rel)
    out = defaultdict(list)
    for addr in sorted(wanted):
        symbol = names.get(addr, {}).get("symbol")
        method = symbol_method(symbol) if symbol else None
        homes = [rel for rel in texts if method and method in spans[rel]]
        if not homes and method and method.split("::")[0] == method.split("::")[1]:
            homes = [rel for rel, text in texts.items() if re.search(r"\b" + re.escape(method) + r"\s*\(", masked_cpp(text))]
        if not homes and not symbol:
            homes = stems.get(by_addr.get(addr, {}).get("unit", "").rsplit("::", 1)[-1].lower(), [])
        if len(homes) == 1:
            out[homes[0]].append(addr)
    return out


def model_evidence(addr, names, by_addr):
    from roc import packet, standins
    source, origin, _ = packet._source("2008-06", addr)
    if not source:
        settings = worker.load_settings()
        if not settings.get("server"):
            raise ValueError("Mined source missing; configure the group server or run roc pull 2008-06")
        api = worker.Api(settings["server"], integration.native_token() or settings.get("native_token") or settings.get("token"))
        try:
            source, origin, _ = packet._source("2008-06", addr, api)
        finally:
            api.close()
        if not source:
            raise ValueError("No mined source available for " + addr + "; check the group server or run roc pull 2008-06")
    code = match.target("2008-06", addr)[0]
    rebuilt = names.get(addr) or {}
    displayed = strip_asm(source)
    reference = match.directives(source).get("lib", "")
    recipe, _, rel = reference.partition(" ")
    definition = libs.RECIPES.get(recipe, {})
    expanded = False
    if definition.get("src") and not definition.get("generate") and Path(rel.strip()).name.startswith("roc_"):
        try:
            folder = libs._case_path(libs.LIBS / definition["src"]).resolve()
            proof = (folder / rel.strip().replace("\\", "/")).resolve()
            if proof.is_relative_to(folder) and proof.is_file():
                displayed += "\n" + strip_asm(proof.read_text(errors="replace"))
                expanded = True
        except OSError:
            pass  # Optional local proof; the compiled library reference remains available.
    assembly = match.disasm(code, int(addr, 16))
    # native_score: how close the rebuild's own method compiles today (the mined source is always 100%)
    item = {"addr": addr, "size": by_addr.get(addr, {}).get("size"), "rebuilt_symbol": rebuilt.get("symbol"),
            "native_score": rebuilt.get("score"), "mined_source": displayed[:4000],
            "mined_source_origin": origin, "target_asm": assembly[:120]}
    if len(assembly) > 120:
        item["target_asm_truncated"] = {"shown": 120, "total": len(assembly)}
    if reference:
        item.update(mined_source_reference=reference, mined_source_expanded=expanded)
    calls = list(dict.fromkeys(m[1].lower().zfill(8) for line in assembly
                               if (m := re.search(r"\b(?:call|jmp) 0x([0-9a-fA-F]+)\s*$", line))
                               and not int(addr, 16) <= int(m[1], 16) < int(addr, 16) + len(code)))
    item["target_calls"] = [{"addr": a, "native_symbol_hint": names.get(a, {}).get("symbol"),
                             "native_score": names.get(a, {}).get("score"),
                             "inventory_unit_hint": by_addr.get(a, {}).get("unit")} for a in calls]
    try:
        item["standins"] = standins.mapping("2008-06", addr, source)
    except Exception as error:  # noqa: BLE001 - the map is optional evidence
        item["standins_error"] = str(error)[:200]
    return item


def body_diff(obj, symbol, addr, limit=40):
    """Show relocated operands as symbols, retaining genuine constants and pointer indirection."""
    import difflib
    function = {name: (body, relocs) for name, body, relocs in match.coff_functions(obj)}.get(symbol)
    if function is None:
        return "rebuilt symbol %s is not in this object" % symbol
    code, relocs = function
    target, target_relocs, _ = match.target("2008-06", addr)
    decoder = match.Cs(match.CS_ARCH_X86, match.CS_MODE_32)
    decoder.detail = True

    def memory_symbol(found):
        expression = found[1]
        if re.fullmatch(r"(?:0x[0-9a-f]+|\d+)", expression):
            return "[sym]"
        expression, count = re.subn(r"\s*[+-]\s*(?:0x[0-9a-f]+|\d+)$", " + sym", expression)
        return "[" + expression + ("" if count else " + sym") + "]"

    def norm(body, relocations):
        lines, relocations = [], set(relocations)
        for instruction in decoder.disasm(body, 0):
            mnemonic, operand = instruction.mnemonic, instruction.op_str
            if instruction.disp_offset and instruction.address + instruction.disp_offset in relocations:
                operand = re.sub(r"\[([^\]]+)\]", memory_symbol, operand)
            if instruction.imm_offset and instruction.address + instruction.imm_offset in relocations:
                operand = re.sub(r"(?:^|(?<=, ))-?(?:0x[0-9a-f]+|\d+)$", "sym", operand)
            elif re.fullmatch(r"0x[0-9a-f]+|\d+", operand):
                if mnemonic == "call" or mnemonic == "jmp" and not 0 <= int(operand, 0) < len(body):
                    operand = "sym"
                elif mnemonic.startswith("j"):
                    operand = "X"
            lines.append(mnemonic + " " + operand)
        return lines
    lines = list(difflib.unified_diff(norm(target, target_relocs), norm(code, relocs),
                                      "target", "rebuilt", n=1, lineterm=""))
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


def model_prompt(rel, shown, items):
    return ("%s\n\nFILE %s\n```cpp\n%s\n```\n\nTARGETS (exact 2008 functions this file should produce)\n%s"
            "\n\nReturn SEARCH/REPLACE blocks inside one ```cpp fence. Do not return the whole source file.") % (
        MODEL_RULES, rel, shown[:60000], json.dumps(items, separators=(",", ":")))


def method_prompt(rel, text, selected, method):
    return ("Repair ONLY %s in %s for the genuine VS2008 compiler. Return its complete qualified method "
            "definition in one ```cpp fence. Keep the signature unchanged. No SEARCH/REPLACE, extra methods, "
            "invented types/fields, raw offsets, assembly or prose. Use standins mappings to translate mined "
            "placeholders to real symbols. Match the target code AND data.\n\n"
            "CONTEXT\n```cpp\n%s\n```\nTARGET\n%s") % (
                method, rel, excerpt(text, [selected['rebuilt_symbol']], around=6)[:60000],
                json.dumps(selected, separators=(',', ':')))


def method_edits(text, reply, method):
    """Accept one complete method, retain its original declaration, and edit only its body."""
    code = providers_text(reply).strip()
    fenced = re.fullmatch(r"```(?:cpp|c\+\+)?\s*\n(.*?)\n```", code, re.S)
    if fenced:
        code = fenced[1]
    original, returned = methods(text), methods(code)
    if method not in original or set(returned) != {method}:
        raise ValueError("reply must contain only the unambiguous method " + method)
    start, end = original[method]
    new_start, new_end = returned[method]
    old_clean, new_clean = masked_cpp(text), masked_cpp(code)
    brace, new_brace = old_clean.index("{", start), new_clean.index("{", new_start)
    if re.sub(r"\s+", "", old_clean[start:brace]) != re.sub(r"\s+", "", new_clean[new_start:new_brace]):
        raise ValueError("method signature must stay unchanged")
    if not re.fullmatch(r"[\w\s:<>,*&~]*", new_clean[:new_start]) or new_clean[new_end:].strip() not in ("", ";"):
        raise ValueError("reply contains extra code outside the requested method")
    return [[text[start:end], text[start:brace] + code[new_brace:new_end]]]


def minimize(rel, text, edits, new, keep, compile_round, matcher, label, allow_empty=False, definitions=(), verified=None):
    """Only the edits the new exacts need, re-proved by a final compile; None if that proof fails. Models rewrite
    neighbouring methods too, and an unproven behaviour change in a method that was not exact would pass the
    loss check. keep: exacts this file already produced, which must survive."""
    edits = [pair for pair in edits if pair[0] != pair[1]]
    for pair in list(edits):
        rest = [other for other in edits if other is not pair]
        if not rest and not allow_empty:
            continue
        trial = compile_round(apply_edits(text, rest) if rest else text, "minimize-%s-%d" % (label, len(rest)))
        found = {h["addr"] for h in matcher.scan(Path(trial["object"]).read_bytes())} if trial["ok"] else set()
        if new <= found and not keep - found and not set(definitions).intersection(trial.get("undefined_symbols", ())):
            edits = rest
            verified = trial
    result = verified or compile_round(apply_edits(text, edits) if edits else text, "final-%s" % label)
    hits = matcher.scan(Path(result["object"]).read_bytes()) if result["ok"] else []
    found = {h["addr"] for h in hits}
    if not (new <= found and not keep - found) or set(definitions).intersection(result.get("undefined_symbols", ())):
        return None
    result.update(hits=hits, losses=[])
    return {"file": rel, "edits": edits, "mode": "model", "witnesses": [h for h in hits if h["addr"] in new],
            "proof": result}


def model_proposal(rel, text, addrs, baseline, owned, model, rounds, compile_round, matcher, evidence, log, options=None,
                   diff=None, shown=None):
    """Ask the model for anchored edits to one native file; keep the first that makes a new target exact and
    loses no owned exact in that file. Every round compiles the real TU; failures go back as feedback."""
    from roc import providers
    addrs = [addr for addr in addrs if addr not in baseline]
    if not addrs:
        return None, []
    generation = (options or {}).get("generation", "edits")
    if generation not in ("auto", "edits", "method"):
        raise ValueError("Unknown native generation mode: " + str(generation))
    spans = methods(text)
    items, selected = [], None
    for addr in addrs[:3]:
        item = evidence(addr)
        items.append(item)
        span = spans.get(symbol_method(item.get("rebuilt_symbol") or ""))
        if generation != "edits" and span and span[1] - span[0] <= 6000:
            selected = item
            break
    method = symbol_method(selected["rebuilt_symbol"]) if selected else None
    one_shot = generation != "edits" and method is not None
    prompt = model_prompt(rel, shown or text, items)
    if one_shot:
        prompt = method_prompt(rel, text, selected, method)
    if (options or {}).get('initial_feedback'):
        prompt += '\n\nPrevious worker batch diagnostics:\n' + options['initial_feedback'][-4000:]
    messages, trials = [{"role": "system", "content": "Repair native C++; return only the requested output inside one ```cpp fence. No tools or prose."},
                        {"role": "user", "content": prompt}], []
    seen_candidates = set()
    for n in range(rounds):
        # Edit blocks are short: no thinking and a small reply cap keep each round to seconds, not a minute.
        # With thinking on, reasoning shares max_tokens: an 8192 cap left 27 of 29 replies without any edit.
        settings = dict({"allow_cloud": True, "timeout": 180, "thinking": "disabled"}, **(options or {}))
        response_mode = "method" if one_shot and (n == 0 or generation == "method") else "edits"
        settings["edit_blocks"] = response_mode == "edits"
        if settings.get("before_request") and not settings["before_request"]():
            return None, trials
        settings.setdefault("max_tokens", 3072 if settings["thinking"] == "disabled" else 32768)
        log("Requesting %s · %s · round %d/%d" % (model, rel, n + 1, rounds))
        reply = providers.generate(model, messages, settings)
        log("Round %d/%d · AI %.1fs · %d in / %d out tokens" % (n + 1, rounds, getattr(reply, "latency_s", 0) or 0,
                                                              getattr(reply, "input_tokens", 0), getattr(reply, "output_tokens", 0)))
        messages.append({"role": "assistant", "content": providers_text(reply)})
        try:
            edits = method_edits(text, reply, method) if response_mode == "method" else parse_edits(reply)
            edits = [pair for pair in edits if pair[0] != pair[1]]
            if not edits:
                raise ValueError("Reply made no source change; target is still not exact")
            integration.validate_patches({rel: edits})
            candidate = apply_edits(text, edits)
            fingerprint = integration.digest(candidate)
            if fingerprint in seen_candidates:
                raise ValueError("Repeated failed candidate; choose a different correction")
            seen_candidates.add(fingerprint)
            result = compile_round(candidate, "model-" + fingerprint[:16])
            log("Round %d/%d · compile %.1fs · queue %.1fs" %
                (n + 1, rounds, result.get("seconds", 0), result.get("queue_seconds", 0)))
        except ValueError as error:
            trials.append({"file": rel, "mode": "model-%d" % n, "generation": response_mode, "ok": False, "error": str(error)[:500],
                           "reply": providers_text(reply)[:3000]})
            instruction = ("Return only the complete corrected method in one cpp fence." if generation == "method" and method else
                           "Return SEARCH/REPLACE blocks in one cpp fence: <<<<<<< SEARCH, exact original text, =======, new text, >>>>>>> REPLACE.")
            messages.append({"role": "user", "content": "Rejected: %s\n%s" % (error, instruction)})
            continue
        hits = matcher.scan(Path(result["object"]).read_bytes()) if result["ok"] else []
        found = {h["addr"] for h in hits}
        new, lost = (found & set(addrs)) - baseline, baseline - found
        result.update(hits=hits, losses=sorted(lost), reply=providers_text(reply)[:3000], generation=response_mode,
                      generation_seconds=getattr(reply, "latency_s", None),
                      input_tokens=getattr(reply, "input_tokens", None), output_tokens=getattr(reply, "output_tokens", None))
        trials.append(result)
        log("model %s round %d: %d new exact, %d lost" % (rel, n, len(new), len(lost)))
        if new and not lost:
            proposal = minimize(rel, text, edits, new, baseline, compile_round, matcher, "%d" % n,
                                definitions=result.get("defined_symbols", ()), verified=result)
            if not proposal:
                trials.append(dict(result, error="minimized edits lost the proof"))
            return proposal, trials
        feedback = result["error"][-1500:] if not result["ok"] else \
            "Compiled. Newly exact: %s. Still not exact: %s. Lost previously exact: %s." % (
                sorted(new) or "none", sorted(set(addrs) - found) or "none", (str(sorted(lost)[:12]) + (" (%d total)" % len(lost) if len(lost) > 12 else "")) if lost else "none")
        if result["ok"] and diff:
            data = Path(result["object"]).read_bytes()
            feedback += "".join("\n\n%s target vs your rebuilt code:\n%s" % (a, diff(data, a))
                                for a in sorted(set(addrs) - found)[:2])
        instruction = ("Return the complete corrected method in one cpp fence." if generation == "method" and method else
                       "Return the complete corrected set of SEARCH/REPLACE blocks against the ORIGINAL file in one cpp fence. "
                       "Use <<<<<<< SEARCH, exact original text, =======, new text, >>>>>>> REPLACE delimiters.")
        messages.append({"role": "user", "content": feedback + "\n" + instruction})
    return None, trials


def resolve_compile_workers(value, jobs):
    count = min(jobs, 8, max(1, (os.cpu_count() or 2) // 2)) if value == "auto" else int(value)
    if not 1 <= count <= 64:
        raise ValueError("Native compiler count must be auto or 1-64")
    return count


def model_discovery(config, texts, wanted, owned, by_addr, matcher, output, jobs, log, compile_source, names):
    """Near-exact targets first; smaller files break ties to reach the first result sooner."""
    from roc import providers
    if config.get("only_rebuilt", True):
        # Near misses first: the rebuild already compiles a body for the address, so the fix is local to that method.
        # Targets with no rebuilt body need new methods and header declarations; .cpp-only edits rarely reach them.
        wanted = {addr for addr in wanted if names.get(addr, {}).get("symbol")}
    homes = target_files(texts, wanted, names, by_addr)
    skip = set(config.get("exclude_files", []))
    homes = {rel: sorted(addrs, key=lambda a: (-(names.get(a, {}).get("score") or 0), by_addr.get(a, {}).get("size", 0))) for rel, addrs in homes.items()}
    files = sorted((rel for rel in homes if rel not in skip),
                   key=lambda rel: (-max(names.get(a, {}).get("score") or 0 for a in homes[rel]), len(texts[rel])))[:config.get("max_files")]
    model, rounds = config["llm"], config.get("rounds", 3)
    options = {key: config[key] for key in ("thinking", "max_tokens", "generation") if key in config}
    options.update(config.get("provider_options", {}))
    options.setdefault("gate", providers.CloudGate(jobs))
    compile_batch = int(config.get('compile_batch', 1))
    if not 1 <= compile_batch <= 32:
        raise ValueError('Methods per compile must be 1-32')
    provider_failed = threading.Event()
    event = options.pop("event", None)
    compile_workers = resolve_compile_workers(config.get("compile_workers", "auto"), jobs)
    compile_slots = threading.Condition()
    active, waiting_proofs = 0, 0
    raw_compile = compile_source
    def compile_source(source, rel, label):
        nonlocal active, waiting_proofs
        queued = time.monotonic()
        proof = label != "baseline"
        with compile_slots:
            if proof:
                waiting_proofs += 1
            try:
                compile_slots.wait_for(lambda: active < compile_workers and (proof or waiting_proofs == 0))
                active += 1
            finally:
                if proof:
                    waiting_proofs -= 1
        waited = time.monotonic() - queued
        try:
            return dict(raw_compile(source, rel, label), queue_seconds=round(waited, 2))
        finally:
            with compile_slots:
                active -= 1
                compile_slots.notify_all()
    context = config.get("context", "file")
    log("Native discovery: %d files · %d AI workers · %d compiler slots" % (len(files), jobs, compile_workers))

    def discover(rel, log, options):
        if provider_failed.is_set() or options.get("before_request") and not options["before_request"]():
            return None, []
        log("Compiling baseline")
        base = compile_source(texts[rel], rel, "baseline")
        if not base["ok"]:
            return None, [base]
        log("Baseline: compile %.1fs · queue %.1fs" % (base.get("seconds", 0), base.get("queue_seconds", 0)))
        data = Path(base["object"]).read_bytes()
        comparing = time.monotonic()
        baseline = {h["addr"] for h in matcher.scan(data)}
        log("Baseline comparison: %.1fs · %d exact" % (time.monotonic() - comparing, len(baseline)))
        if set(homes[rel]) <= baseline:
            log("Skipping AI: all %d targets already code/data exact locally" % len(homes[rel]))
            return None, [base]
        if provider_failed.is_set():
            return None, [base]
        pending = [addr for addr in homes[rel] if addr not in baseline]

        def diff(obj, addr):
            return body_diff(obj, names[addr]["symbol"], addr) if names.get(addr, {}).get("symbol") else "no rebuilt body"
        try:
            if compile_batch > 1 and options.get('generation', 'edits') != 'edits':
                from roc import native_batch
                groups = {}
                spans = methods(texts[rel])
                for addr in pending:
                    method = symbol_method(names.get(addr, {}).get('symbol') or '')
                    if addr not in baseline and method in spans and spans[method][1] - spans[method][0] <= 6000:
                        groups.setdefault(method, []).append(addr)
                if len(groups) > 1:
                    selected = dict(list(groups.items())[:compile_batch])
                    proposal, trials = native_batch.model_batch(rel, texts[rel], selected, baseline, model, rounds,
                        lambda source, label: compile_source(source, rel, label), matcher,
                        lambda addr: dict(model_evidence(addr, names, by_addr), current_diff=diff(data, addr)),
                        log, options, ai_pool, diff)
                    if any(t.get('error_category') in providers.FATAL_ERRORS for t in trials):
                        provider_failed.set()
                    if proposal or provider_failed.is_set() or options.get('generation') == 'method' or rounds <= 1:
                        return proposal, [base] + trials
                    feedback = '\n'.join(str(t.get('error', '')) for t in trials if t.get('error'))
                    diagnostic = next((t for t in trials if t.get('ok') and t.get('object')), None)
                    if diagnostic:
                        feedback += '\nBatch compiled; existing exact lost: %s.' % diagnostic.get('losses', [])[:12]
                        obj = Path(diagnostic['object']).read_bytes()
                        feedback += ''.join('\n%s target vs batch:\n%s' % (addr, diff(obj, addr)) for addr in pending[:2])
                    proposal, repairs = model_proposal(rel, texts[rel], pending, baseline, owned, model, rounds - 1,
                        lambda source, label: compile_source(source, rel, label), matcher,
                        lambda addr: dict(model_evidence(addr, names, by_addr), current_diff=diff(data, addr)),
                        log, dict(options, generation='edits', initial_feedback=feedback), diff,
                        excerpt(texts[rel], [names[a]['symbol'] for a in pending[:3]]) if context == 'methods' else None)
                    return proposal, [base] + trials + repairs
            proposal, trials = model_proposal(rel, texts[rel], pending, baseline, owned, model, rounds,
                                              lambda source, label: compile_source(source, rel, label), matcher,
                                              lambda addr: dict(model_evidence(addr, names, by_addr), current_diff=diff(data, addr)),
                                              log, options, diff,
                                              excerpt(texts[rel], [names[a]["symbol"] for a in pending[:3]
                                                                   if names.get(a, {}).get("symbol")])
                                              if context == "methods" else None)
        except Exception as error:  # noqa: BLE001 - one provider/compile failure must not stop the other files
            if getattr(error, "category", "") in providers.FATAL_ERRORS:
                provider_failed.set()
                log("Provider configuration failed; queued files skipped: " + str(error))
            return None, [base, {"file": rel, "mode": "model", "ok": False, "error": str(error)[:500], "error_category": getattr(error, "category", "")}]
        return proposal, [base] + trials

    slots, slots_lock = list(range(jobs)), threading.Lock()
    def one(rel):
        if provider_failed.is_set() or options.get("before_request") and not options["before_request"]():
            return None, []
        with slots_lock:
            slot = slots.pop(0)
        started = time.monotonic()
        if event:
            event("native_started", slot=slot, file=rel, model=model)
        def report(message):
            if event:
                event("native_progress", slot=slot, file=rel, message=str(message))
            else:
                log(message)
        try:
            proposal, trials = discover(rel, report, dict(options, log=report))
            if event:
                event("native_result", slot=slot, file=rel,
                      local_exact=len(proposal["witnesses"]) if proposal else 0,
                      error_category="" if proposal else next((t["error_category"] for t in reversed(trials) if t.get("error_category")), ""),
                      seconds=round(time.monotonic() - started, 1),
                      error="" if proposal else next((t.get("error", "") for t in reversed(trials) if t.get("error")), "")[:240])
            return proposal, trials
        finally:
            with slots_lock:
                slots.append(slot)

    proposals, records = [], []
    with ThreadPoolExecutor(max_workers=jobs) as ai_pool, ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = [pool.submit(one, rel) for rel in files]
        for n, future in enumerate(as_completed(futures)):
            proposal, trials = future.result()
            records.extend(trials)
            if proposal:
                try:
                    integration.validate_patches({proposal["file"]: proposal["edits"]})
                except ValueError as error:
                    integration.atomic_json(output / 'blocked-proposals' / (integration.digest(proposal['file'])[:16] + '.json'),
                                            dict(proposal=proposal, reason=str(error)))
                    records.append(dict(file=proposal["file"], error="Proposal retained, not staged: " + str(error)))
                    log("Proposal retained, not staged: %s: %s" % (proposal["file"], error))
                    continue
                for hit in proposal["witnesses"]:
                    hit["claim_unit"] = claim_unit(hit, by_addr[hit["addr"]])
                if config.get('base_revision'):
                    proposal['base_revision'] = config['base_revision']
                proposals.append(proposal)
                integration.atomic_json(output / 'proposals.json', proposals)
                log('Saved %d local exact across %d files; %d/%d files finished, linked preflight follows discovery' % (
                    sum(len(p['witnesses']) for p in proposals), len(proposals), n + 1, len(files)))
            integration.atomic_json(output / "trials.json", records)
            integration.atomic_json(output / "progress.json", {"phase": "model", "files_done": n + 1, "total": len(files),
                                                               "proposals": len(proposals)})
    return proposals, records


def native_context(config, api, addresses=None):
    """Compile settings, targets and owned exacts every native discovery shares (sweep, model pass, agent CLI)."""
    module = rebuild.load_module("2008-06", "rbxgs-app")
    tree, overlay = rebuild.build_overlay("2008-06", "RbxgsApp", module["overlay"])
    recipe = libs.RECIPES["rbxgs"]
    includes = [libs._case_path(libs.LIBS / path).resolve() for path in recipe["include"] if path != "WINSDK"]
    includes = rebuild._overlaid(includes, [], (tree, overlay))[0]
    defines = recipe["defines"] + " BOOST_ALL_NO_LIB"
    # Discovery reads installed manifests only. Mutable source/output trees stay private.
    evidence_root = Path(os.environ.get("ROC_NATIVE_EVIDENCE_ROOT", ROOT))
    manifest = Path(config.get("manifest", evidence_root / "rebuild/2008-06/manifests/functions.json"))
    names_path = evidence_root / "rebuild/2008-06/out/native-names.json"
    owned_path = Path(config.get("owned_report", evidence_root / "rebuild/2008-06/out/RbxgsApp/report.json"))
    linked_path = evidence_root / "work/integration/progress-native.json"
    if all(path.exists() for path in (manifest, names_path, owned_path, linked_path)):
        rows = json.loads(manifest.read_text(encoding="utf-8"))
        owned = set(json.loads(owned_path.read_text()).get("owned_addrs", []))
        integrated = set(json.loads(linked_path.read_text())["addresses"])
        names = json.loads(names_path.read_text())
    else:
        # Contributor PCs rarely hold the server's rebuild artifacts: take the same evidence from the server.
        evidence = server_evidence(api)
        rows = [{"addr": addr, "unit": unit, "size": size, "score": 100} for addr, (unit, size) in evidence["targets"].items()]
        owned, names = set(evidence["linked"]), evidence["names"]
        integrated = set(evidence["linked"])
    for job in api.call("/v1/integration")["jobs"]:
        if job["state"] == "accepted":
            owned.update(job["receipt"].get("gains", []))
            integrated.update(job["receipt"].get("gains", []))
    # Every byte-exact mined source kind (snippet, vendor-file, generated-unit) is a target: the linked
    # rebuild owns an address by exact bytes. Snippet-only targeting hid ~5k exact app functions.
    targets = {row["addr"] for row in rows if row.get("score") == 100 and row.get("unit", "").startswith("RBX::")}
    if addresses:
        targets &= set(addresses)
    return SimpleNamespace(tree=tree, overlay=overlay, includes=includes, defines=defines, flags=config.get("flags", FLAGS),
                           by_addr={row["addr"]: row for row in rows}, owned=owned, targets=targets,
                             matcher=Matcher(targets | owned), names=names, integrated=integrated)


EVIDENCE_CACHE = ROOT / "work/integration-client/evidence.json"


def server_evidence(api):
    """GET /v1/integration/evidence, cached for tools (roc standins) that run without an API handle."""
    evidence = api.call("/v1/integration/evidence", timeout=300)
    integration.atomic_json(EVIDENCE_CACHE, evidence)
    return evidence


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
    previous = output / 'proposals.json'
    if previous.exists():
        content = previous.read_bytes()
        archive = output / 'proposal-history' / (hashlib.sha256(content).hexdigest() + '.json')
        archive.parent.mkdir(exist_ok=True)
        if not archive.exists():
            archive.write_bytes(content)
    run_id = uuid.uuid4().hex
    integration.atomic_json(output / "summary.json", {"recipe": name, "state": "running", "run_id": run_id, "new_verified": 0})
    integration.atomic_json(output / "progress.json", {"phase": "setup", "run_id": run_id})
    def finish(summary):
        summary.update(run_id=run_id, state=summary.get("state") or ("queued" if summary.get("job") else "staged" if summary.get("applied_files") else "proposals" if summary.get("proposed_files") else "no-proposals"))
        integration.atomic_json(output / "summary.json", summary)
        integration.atomic_json(output / "runs" / (run_id + ".json"), summary)
        integration.atomic_json(output / "progress.json", {"phase": summary["state"], "run_id": run_id,
                                                           "job": summary.get("job"), "new_verified": summary.get("new_verified", 0)})
        return summary
    settings = worker.load_settings()
    api = worker.Api(server or settings["server"], integration.native_token() or settings.get("native_token") or settings.get("token"))
    claimed, used = [], set()
    keep_claims = False
    summary = {}
    generator = ROOT / "rebuild/2008-06/patches/make_rbxgs_client.py"
    try:
        if config.get("submit") and not config.get("model"):
            raise ValueError("Submission requires actual model identity")
        if config.get("after_job"):
            integration.atomic_json(output / "progress.json", {"phase": "waiting_for_job", "run_id": run_id,
                                                               "job": config["after_job"]})
            prior = wait_for_job(api, config["after_job"], config.get("verify_timeout", 4 * 3600), log)
            if prior["state"] != "accepted" or not prior["receipt"].get("accepted"):
                raise ValueError("Prerequisite native batch was rejected; discovery not started")
            integration.command(SimpleNamespace(action="sync", server=server, user=None, token=integration.native_token()))
        recovered = integration.resume_pending(api, ROOT / "work/integration-client", settings.get("user"))
        if recovered:
            result = recovered[0]
            restore_submitted_baseline(result["id"], log)
            return finish(dict(recipe=name, job=result["id"], state=result["state"],
                               applied_paths=result.get("applied_paths", []), files_tried=[],
                               applied_files=len(result.get("applied_paths", [])), new_verified=0))
        original = generator.read_bytes()
        base = api.call("/v1/integration/base")
        if hashlib.sha256(original).hexdigest() != base["generator"]:
            raise ValueError("Sync accepted work and preserve unsent generator edits before sweeping")
        overlay_file = generator.with_name("rbxgs-client.json")
        if json.loads(overlay_file.read_text()) != base["overlay"]:
            if not integration.sync_client_baseline(ROOT, base, only_if_clean=True):
                raise ValueError("Local overlay differs from server baseline; preserve local edits and sync first")
            log("accepted baseline advanced; clean local overlay refreshed")
        integration.atomic_json(ROOT / "work/integration-client/baseline.json", base)
        log("Native setup: materializing accepted source overlay and indexing target evidence")
        ctx = native_context(config, api, spec.get("targets", {}).get("addresses"))
        tree, overlay, includes, defines, flags = ctx.tree, ctx.overlay, ctx.includes, ctx.defines, ctx.flags
        by_addr, owned, targets, matcher = ctx.by_addr, ctx.owned, ctx.targets, ctx.matcher
        files = sorted({p.relative_to(tree).as_posix() for pattern in config.get("files", ["App/*/*.cpp"])
                        for p in tree.glob(pattern) if not p.name.startswith("roc_")})
        if limit and not config.get("targets_only"):
            files = files[:limit]
        log("Native setup: resolving historical compiler and source files")
        rebuild.toolchain()  # Resolve discovery once before compile workers start.
        texts = {rel: (overlay / rel if (overlay / rel).exists() else tree / rel).read_text(errors="replace") for rel in files}
        discovery_targets = targets - owned
        if config.get("targets_only"):
            discovery_targets -= getattr(ctx, "integrated", set())
            homes = target_files(texts, discovery_targets, ctx.names, by_addr)
            files = sorted(homes, key=lambda rel: (-len(homes[rel]), rel))
            if limit:
                files = files[:limit]
            texts = {rel: texts[rel] for rel in files}
        if config.get("proposals_file"):
            # Proposals an agent already proved with `roc native-try check`: claim, stage and submit them as one batch.
            saved_bytes = Path(config["proposals_file"]).read_bytes()
            archive = output / ("saved-proposals-" + hashlib.sha256(saved_bytes).hexdigest()[:20] + ".json")
            if not archive.exists():
                archive.write_bytes(saved_bytes)
            proposals, records = json.loads(saved_bytes), []
            final_checks, trials, rechecked = [], [], []
            seen = set()
            for proposal in proposals:
                proposal["file"] = next(iter(integration.canonical_patches({proposal["file"]: []}, base["overlay"])))
                rel = proposal["file"]
                if rel.casefold() in seen:
                    raise ValueError("Duplicate saved source proposals: " + rel)
                seen.add(rel.casefold())
                if proposal.get("related_headers"):
                    proposal["related_headers"] = integration.canonical_patches(proposal["related_headers"], base["overlay"])
                changes = {name: edits for name, edits in dict(proposal.get('related_headers', {}),
                           **{rel: proposal['edits']}).items() if edits}
                try:
                    integration.validate_patches(changes)
                except ValueError as error:
                    integration.atomic_json(output / 'blocked-proposals' / (integration.digest(rel)[:16] + '.json'),
                                            dict(proposal=proposal, reason=str(error)))
                    log('Proposal retained, not staged: %s: %s' % (rel, error))
                    continue
                if rel not in texts:
                    texts[rel] = (overlay / rel if (overlay / rel).exists() else tree / rel).read_text(errors="replace")
                log("native rechecking " + rel)
                if not proposal.get("base_revision"):
                    raise ValueError("Saved proof is unversioned; run roc native-try check " + rel)
                if proposal["base_revision"] != base["revision"]:
                    log("accepted baseline advanced; independently revalidating saved edits: " + rel)
                options = {"translation_unit": proposal["translation_unit"]} if proposal.get("translation_unit") else {}
                baseline = compile_unit(texts[rel], rel, "recheck-baseline", output, tree, overlay, includes, defines, flags, **options)
                if not baseline["ok"]:
                    raise ValueError("Saved proposal baseline compile failed: " + rel)
                keep = {h["addr"] for h in matcher.scan(Path(baseline["object"]).read_bytes())}
                final = compile_unit(apply_edits(texts[rel], proposal["edits"]) if proposal["edits"] else texts[rel], rel, "recheck-final", output,
                                     tree, overlay, includes, defines, flags,
                                     **dict(options, **({"related_headers": proposal["related_headers"]} if proposal.get("related_headers") else {})))
                if not final["ok"]:
                    raise ValueError("Saved proposal compile failed: " + rel)
                missing = set(proposal.get("proof", {}).get("defined_symbols", ())).intersection(final.get("undefined_symbols", ()))
                if missing:
                    raise ValueError("Saved proposal lost required definitions: " + ", ".join(sorted(missing)))
                hits = matcher.scan(Path(final["object"]).read_bytes())
                found = {h["addr"] for h in hits}
                wanted = {h["addr"] for h in proposal["witnesses"]}
                if not wanted <= found or keep - found:
                    raise ValueError("Saved proposal lost exact matches; rerun roc native-try check " + rel)
                ownership = ownership_candidates(Path(final["object"]).read_bytes(), [h for h in hits if h["addr"] in wanted])
                if not any(candidates == [addr] for addr, candidates in ownership.items()):
                    log("no unique module ownership candidates; proposal retained locally: " + rel)
                    continue
                proposal["proof"] = dict(final, hits=hits, losses=[])
                proposal["proof"]["ownership_candidates"] = ownership
                proposal["base_revision"] = base["revision"]
                final_checks.append(proposal["proof"])
                rechecked.append(proposal)
            proposals = rechecked
        elif config.get("llm"):
            proposals, records = model_discovery(dict(config, base_revision=base['revision']), texts, discovery_targets, owned, by_addr, matcher, output, jobs, log,
                                                 lambda source, rel, label: compile_unit(source, rel, label, output, tree,
                                                                                         overlay, includes, defines, flags),
                                                 ctx.names)
            final_checks = [p["proof"] for p in proposals]
            trials = []
        else:
            trials = [(rel, *trial) for rel in files for trial in experiments(texts[rel], config.get("modes"))]
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
                        new_hits = [h for h in result["hits"] if h["addr"] in discovery_targets - baseline_hits.get(rel, set())]
                        result["ownership_candidates"] = ownership_candidates(Path(result["object"]).read_bytes(), new_hits)
                        unique_hits = [h for h in new_hits if result["ownership_candidates"].get(h["addr"]) == [h["addr"]]]
                        proposal = proven_proposal(texts[rel], mode, unique_hits,
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
                    lost = baseline_hits[rel] - addresses
                    proposal["proof"] = dict(final, hits=hits, losses=sorted(lost))
                    final_checks.append(proposal["proof"])
                    proposal.pop("source")
                    if not lost and wanted <= addresses:
                        proposals.append(proposal)
                        break
        for proposal in proposals:
            proposal["base_revision"] = base["revision"]
        proposal_output = output / "proposals.json"
        if config.get("proposals_file") and Path(config["proposals_file"]).resolve() == proposal_output.resolve():
            proposal_output = output / "rechecked-proposals.json"
        integration.atomic_json(proposal_output, proposals)
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
        units, selected, blocked, routed = {}, [], set(), {}
        claim_state = api.call("/v1/integration?claims=1")
        inventory = claim_state.get("inventory")
        parked = set(claim_state.get("parked_units", [])) | {item["unit"] for item in claim_state.get("parked", [])}
        catalog_units = {addr: unit for unit, addresses in (inventory or {}).items() for addr in addresses}
        worker_name = settings["user"] + "@native-sweep:" + identity
        live = [c for c in claim_state.get("claims", []) if c["expires"] > time.time() or c["state"] == "submitted"]
        foreign = {c["unit"] for c in live if c["state"] in ("claimed", "submitted") and
                   (c["user"], c["worker"]) != (settings["user"], worker_name)}
        max_claims = base.get("limits", {}).get("claims", 16)
        for proposal in proposals:
            labels = {h["claim_unit"] for h in proposal["witnesses"]}
            labels.update(by_addr[h["addr"]]["unit"] for h in proposal["witnesses"] if h["addr"] in by_addr)
            needed = set()
            for hit in proposal["witnesses"]:
                unit = catalog_units.get(hit["addr"], by_addr.get(hit["addr"], {}).get("unit", hit["claim_unit"]))
                needed.add(unit if re.fullmatch(r"RBX::(?:\w+::)*\w+", unit) else hit["claim_unit"])
            if (labels | needed) & (parked | foreign):
                blocked.update((labels | needed) & (parked | foreign))
                continue
            if inventory is not None:
                absent = needed - inventory.keys()
                if absent:
                    log("Skipping unavailable claim units: " + ", ".join(sorted(absent)))
                needed &= inventory.keys()
            routed[proposal["file"]] = needed
            if len(set(units) | needed) > max_claims:
                continue
            for unit in sorted(needed - set(units)):
                log("native claiming " + unit)
                existing = next((c for c in live if c["unit"] == unit and c["user"] == settings["user"]
                                 and c["worker"] == worker_name and c["state"] == "claimed"
                                 and c["base_revision"] == base["revision"]), None)
                packet = ROOT / "work/integration-client/claims" / existing["id"] / "packet.json" if existing else None
                result = {"claims": [json.loads(packet.read_text())]} if packet and packet.exists() else api.call("/v1/integration/claim", {"user": settings["user"], "worker": worker_name,
                                                          "unit": unit, "count": 1})
                if result["claims"] and result["claims"][0]["base_revision"] != base["revision"] and \
                        api.call("/v1/integration/base")["revision"] == base["revision"]:
                    log("refreshing own stale claim: " + unit)
                    api.call("/v1/integration/release", {"user": settings["user"], "claim": result["claims"][0]["id"]})
                    result = api.call("/v1/integration/claim", {"user": settings["user"],
                                      "worker": settings["user"] + "@native-sweep:" + identity, "unit": unit, "count": 1})
                if result["claims"]:
                    claim = result["claims"][0]
                    claimed.append(claim)
                    if claim["base_revision"] != base["revision"]:
                        raise ValueError("Claim baseline changed; rerun discovery")
                    units[unit] = claim
            # Gains are credited from the linked rebuild, not per claim: take a proposal when it holds at least one
            # claim and no other worker holds a live claim on any class it touches (catalog-less classes and
            # sub-24-byte targets cannot be claimed at all).
            conflicts = (labels | needed) & foreign_claims(settings["user"], identity)
            if not conflicts:
                selected.append(proposal)  # rides on any claim this batch holds; at least one is required below
            else:
                blocked.update(conflicts)
        if selected and not units:
            result = api.call("/v1/integration/claim", {"user": settings["user"], "worker": settings["user"] + "@native-sweep:" + identity,
                                                      "count": 1})
            for claim in result["claims"]:
                claimed.append(claim)
                units[claim["unit"]] = claim
        used = {unit for p in selected for unit in routed[p["file"]]} & units.keys()
        if selected and not used and units:
            used = {sorted(units)[0]}  # carrier claim for catalog-less classes
        additions = {}
        for proposal in selected:
            for path, pairs in dict(proposal.get("related_headers", {}), **{proposal["file"]: proposal["edits"]}).items():
                for pair in pairs:
                    if pair not in additions.setdefault(path, []):
                        additions[path].append(pair)
        if not additions or not used:
            summary.update(state="blocked", blocked_units=sorted(blocked),
                           reason="Classes held by another worker" if blocked else "No native claim available")
            return finish(summary)
        additions = integration.canonical_patches(additions, base["overlay"])
        renewed = api.call("/v1/integration/renew", {"user": settings["user"], "claims": [units[u]["id"] for u in sorted(used)]})
        if not renewed.get("ok"):
            raise ValueError("Claims changed before linked preflight; saved proposals retained")
        from roc.integration_verify import linked_preflight
        linked = linked_preflight(ROOT, additions, output, log)
        if api.call("/v1/integration/base")["revision"] != base["revision"]:
            raise ValueError("Accepted baseline advanced during linked preflight; saved proposals retained, sync and retry")
        for unit in used:
            claim = units[unit]
            folder = ROOT / "work/integration-client/claims" / claim["id"]
            integration.atomic_json(folder / "packet.json", claim)
            (folder / "generator-base.py").write_bytes(original)
        notes = output / "batch-notes.txt"
        notes.write_text("Native integration: real C++ methods and related declarations.\n"
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
            integration.run_generator(generator, ROOT)
            integration.overlay_delta(base["overlay"], json.loads(overlay_file.read_text()))
        except BaseException:
            generator.write_bytes(original)
            integration.run_generator(generator, ROOT)
            raise
        summary.update(applied_files=len(selected), applied_paths=[p["file"] for p in selected],
                       batch=str(batch), evidence=str(notes))
        keep_claims = True
        if config.get("submit"):
            args = SimpleNamespace(action="submit", server=server, user=None, token=integration.native_token(),
                                   claim=None, all=False, batch=str(batch), model=config["model"], evidence_file=str(notes), retry=False, wait=False,
                                   applied_paths=summary["applied_paths"], preflight_artifacts=linked.get("artifacts") if linked else None)
            integration.command(args)
            marker = ROOT / "work/integration-client/claims" / units[sorted(used)[0]]["id"] / "job.json"
            summary["job"] = json.loads(marker.read_text())["id"]
            restore_submitted_baseline(summary["job"], log)
            finish(summary)
            if config.get("wait"):
                job = wait_for_job(api, summary["job"], config.get("verify_timeout", 4 * 3600), log)
                summary.update(state=job["state"], receipt=job["receipt"])
                if job["state"] == "accepted" and job["receipt"].get("accepted"):
                    summary["new_verified"] = job["receipt"].get("credits", 0)
                    integration.command(SimpleNamespace(action="sync", server=server, user=None, token=integration.native_token()))
        return finish(summary)
    except BaseException as error:
        state = summary.get("state") if summary.get("state") in ("accepted", "rejected") else "queued" if summary.get("job") else "failed"
        finish(dict(summary, recipe=name, state=state, error=str(error), new_verified=summary.get("new_verified", 0)))
        raise
    finally:
        for claim in claimed:
            if not keep_claims or claim["unit"] not in used:
                try:
                    api.call("/v1/integration/release", {"user": settings["user"], "claim": claim["id"]})
                except worker.ApiFailure as error:
                    log("Claim release failed (%s): %s" % (claim["id"], error))
        api.close()
