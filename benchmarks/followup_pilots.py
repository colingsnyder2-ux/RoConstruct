"""Independent data, compiler and config pilots; exact-only acceptance, resumable logs."""
import argparse
import ast
import json
import random
import re
import time
from collections import defaultdict
from pathlib import Path

from benchmarks.match_campaign import Campaign, digest
from roc import clients, fingerprint, libs, match

ROOT = Path("work/followup-pilots-20261010")
OLD = Path("work/match-campaign-20261010")
HANDOFF = [("2010-06", a) for a in ("009da850", "009c6290", "009c2ae0", "0041ade0")]
HANDOFF += [("2011-06", "00635e40")]


def excluded_shapes():
    return {match._functions(c).get(a, {}).get("shape") for c, a in HANDOFF} - {None, ""}


def live(campaign):
    return {c: {r["addr"]: r for r in campaign.api.call("/v1/sources?client=" + c, timeout=120)}
            for c in campaign.info["clients"]}


def save_source(stage, source):
    path = ROOT / "trials" / stage / (digest(source) + ".cpp")
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(source, encoding="utf-8")
    return str(path)


def declare_asm_helpers(source):
    """Turn assembly helper bodies into declarations; caller must recheck baseline."""
    tokens = list(re.finditer(r'"(?:[^"\\]|\\.)*"|\'(?:[^\'\\]|\\.)*\'|//[^\n]*|/\*.*?\*/|\b(?:__asm|_asm)\b|[{}]', source, re.S))
    stack, spans, marked = [], {}, set()
    for token in tokens:
        if token[0] == "{":
            stack.append(token.start())
        elif token[0] == "}" and stack:
            start = stack.pop()
            spans[start] = token.end()
        elif token[0] in ("__asm", "_asm") and stack:
            marked.add(stack[-1])
    for start in sorted(marked, reverse=True):
        if start not in spans or not re.search(r'\)\s*(?:const\s*)?$', source[:start]):
            raise ValueError("assembly outside recognizable helper function")
        source = source[:start] + ";" + source[spans[start]:]
    match.reject_asm(source)
    return source


def literal_repair(source, before, expected):
    """Repair complete narrow literals or explicitly sized scalar initializers only."""
    out = []
    for token in re.finditer(r'(?<![\w])"(?:[^"\\]|\\.)*"', source):
        try:
            value = ast.literal_eval(token[0]).encode("latin-1") + b"\0"
        except (ValueError, SyntaxError, UnicodeError):
            continue
        if not before.startswith(value) or any(before[len(value):]):
            continue
        stop = expected.find(b"\0")
        if stop < 0 or stop > 512:
            continue
        replacement = '"' + ''.join("\\%03o" % b for b in expected[:stop]) + '"'
        candidate = source[:token.start()] + replacement + source[token.end():]
        if candidate != source:
            out.append(("literal bytes read at target relocation", candidate))
    types = {"int": (4, True), "unsigned int": (4, False), "float": (4, None),
             "short": (2, True), "unsigned short": (2, False)}
    pattern = r'\b(int|unsigned int|float|short|unsigned short)\s+(\w+)\s*\[\s*(\d+)\s*\]\s*=\s*\{([^{}]+)\}'
    import struct
    for token in re.finditer(pattern, source):
        width, signed = types[token[1]]
        n = int(token[3]); parts = [v.strip() for v in token[4].split(",") if v.strip()]
        if len(parts) != n or n * width != len(before) or len(expected) != len(before):
            continue
        try:
            values = [float(v.rstrip("fF")) if signed is None else int(v, 0) for v in parts]
            data = b''.join(struct.pack("<f", v) if signed is None else v.to_bytes(width, "little", signed=signed) for v in values)
            if data != before or signed is None:
                continue  # Float formatting needs a separate exact-representation experiment.
            values = [str(int.from_bytes(expected[i:i+width], "little", signed=signed)) for i in range(0, len(expected), width)]
            candidate = source[:token.start(4)] + ", ".join(values) + source[token.end(4):]
            if candidate != source:
                out.append(("sized integer-array bytes read at target relocation", candidate))
        except (ValueError, OverflowError):
            continue
    return list(dict.fromkeys(out))


def data(campaign, limit):
    frozen = {(r["client"], r["addr"]): r for r in json.loads((OLD / "data-recovery-manifest.json").read_text())}
    rows = [json.loads(x) for x in (OLD / "data-recovery.jsonl").read_text().splitlines()]
    done = {(r["client"], r["addr"]) for r in campaign.previous("initialized-data-v2")}
    shapes = excluded_shapes()
    for row in [r for r in rows if r.get("qualified")][:limit]:
        c, a = row["client"], row["addr"]
        if c not in campaign.info["clients"] or (c, a) in done:
            continue
        result = dict(client=c, addr=a, variants=[], cost=0)
        try:
            current = campaign.current(c, a)
            if current["score"] == 100 or match._functions(c)[a].get("shape") in shapes:
                result["skip"] = "already exact or reserved handoff family"
            else:
                source = frozen[c, a]["source"]
                code, relocs, _ = match.target(c, a)
                obj = match.compile_text(c, source)
                exacts = [f for f in match.coff_functions(obj) if match.exact_match(code, relocs, f[1], f[2])]
                if not exacts:
                    raise ValueError("baseline no longer code exact")
                selected, _, bad = match.select_exact_data(c, a, code, obj, exacts)
                result.update(baseline=99 if bad else 100, data_errors=bad, symbol=selected[0])
                d = match.directives(source)
                if "lib" in d:
                    recipe, _, path = d["lib"].partition(" ")
                    body = libs.unit(recipe, path, int(d.get("cl", clients.load()[c]["compiler_build"])))
                    source = re.sub(r"(?m)^//\s*roc-lib:.*$", "", source) + "\n" + body
                    source = declare_asm_helpers(source)
                    normalized, _, _, _ = match.check_text(c, a, source)
                    result["materialized_baseline"] = normalized
                    if normalized != result["baseline"]:
                        raise ValueError("materialized helper declarations changed baseline; no repair attempted")
                base, image = match._image(c)
                hypotheses = []
                for off, before, inner in match.coff_data_refs(obj, selected[0]):
                    if inner or not 0 <= off <= len(code) - 4:
                        continue
                    va = int.from_bytes(code[off:off+4], "little")
                    pos = va - base
                    if not 0 <= pos < len(image):
                        continue
                    expected = bytes(image[pos:pos+max(len(before), 513)])
                    if expected[:len(before)] == before:
                        continue
                    for reason, candidate in literal_repair(source, before, expected):
                        hypotheses.append((reason, candidate, va))
                    for reason, candidate in literal_repair(source, before, expected[:len(before)]):
                        hypotheses.append((reason, candidate, va))
                seen = set()
                for reason, candidate, va in hypotheses:
                    if digest(candidate) in seen:
                        continue
                    seen.add(digest(candidate))
                    if len(seen) > 9:
                        break
                    trial = dict(hypothesis=reason, evidence_va=hex(va), path=save_source("data", candidate))
                    try:
                        score, _, diff, _ = match.check_text(c, a, candidate)
                        trial.update(score=score, rejection="" if score == 100 else diff[:600])
                        if score == 100:
                            result["winner"] = campaign.submit_exact("initialized-data", c, a, candidate)
                    except (RuntimeError, ValueError, SystemExit) as e:
                        trial["error"] = str(e)[-500:]
                    result["variants"].append(trial)
                    if "winner" in result:
                        break
                if not hypotheses:
                    result["rejection"] = "no supported literal/sized-array mapping; relocatable or ambiguous library data"
        except (RuntimeError, ValueError, OSError, SystemExit) as e:
            result["error"] = str(e)[-600:]
        campaign.record("initialized-data-v2", result)
        print("data", c, a, result.get("winner", {}).get("score"), len(result["variants"]), flush=True)


def flag_variants(current):
    groups = [["/O2", "/O1", "/Ox"], ["/Oy", "/Oy-"], ["/GS-", "/GS"],
              ["/EHsc", "/EHa"], ["/Ob0", "/Ob1", "/Ob2"], ["/Oi", "/Oi-"]]
    seen = {current}
    for group in groups:
        for option in group:
            trial = " ".join([v for v in current.split() if v not in group] + [option])
            if trial not in seen:
                seen.add(trial)
                yield trial


def compiler(campaign, limit):
    manifest = ROOT / "compiler-manifest.json"
    if not manifest.exists():
        rows = []
        shapes = excluded_shapes()
        for c, sources in live(campaign).items():
            for a, row in sources.items():
                source = row.get("source", "")
                if 70 <= row["score"] < 100 and 0 < len(source) < 6000 and not any(k in match.directives(source) for k in ("lib", "archive")):
                    if match._functions(c).get(a, {}).get("shape") not in shapes:
                        rows.append(dict(client=c, **row))
        random.Random(20261011).shuffle(rows)
        manifest.write_text(json.dumps(rows), encoding="utf-8")
    done = {(r["client"], r["addr"]) for r in campaign.previous("compiler-focus")}
    qualified = sum(bool(r.get("qualified")) for r in campaign.previous("compiler-focus"))
    allowed = {"stack-frame/layout mismatch", "register allocation difference", "code-size mismatch", "missing/extra instruction"}
    for row in json.loads(manifest.read_text()):
        c, a, source = row["client"], row["addr"], row["source"]
        if c not in campaign.info["clients"] or (c, a) in done:
            continue
        if qualified >= limit:
            break
        result = dict(client=c, addr=a, variants=[], qualified=False, cost=0)
        try:
            if campaign.current(c, a)["score"] == 100:
                result["skip"] = "already exact"
            else:
                baseline, _, _, _, diagnosis = match.check_text(c, a, source, include_diagnosis=True)
                result.update(baseline=baseline, diagnosis=diagnosis, source_path=save_source("compiler", source))
                steps = diagnosis.get("alignment", {}).get("steps", {})
                same = steps.get("same", 0) + steps.get("regalloc", 0)
                n = max(diagnosis.get("target_insns", 1), diagnosis.get("cand_insns", 1))
                result["qualified"] = baseline < 100 and diagnosis.get("mismatch_class") in allowed and same / n >= .70
                if result["qualified"]:
                    qualified += 1
                    current = match.directives(source).get("flags", clients.load()[c].get("flags", match.DEFAULT_FLAGS))
                    clean = re.sub(r"(?m)^//\s*roc-flags:.*$", "", source)
                    best = baseline
                    for round_no in range(2):
                        best_flags = current
                        for flags in flag_variants(current):
                            trial = dict(flags=flags, round=round_no+1)
                            candidate = "// roc-flags: " + flags + "\n" + clean
                            trial["path"] = save_source("compiler", candidate)
                            try:
                                score, _, diff, _ = match.check_text(c, a, candidate)
                                trial.update(score=score, rejection="" if score > best else "no improvement", diff=diff[:300])
                                if score > best:
                                    best, best_flags = score, flags
                                if score == 100:
                                    result["winner"] = campaign.submit_exact("compiler-focus", c, a, candidate)
                            except (RuntimeError, ValueError, SystemExit) as e:
                                trial["error"] = str(e)[-300:]
                            result["variants"].append(trial)
                            if "winner" in result:
                                break
                        if "winner" in result or best_flags == current:
                            break
                        current = best_flags
                    result["best"] = best
        except (RuntimeError, ValueError, OSError, SystemExit) as e:
            result["error"] = str(e)[-500:]
        campaign.record("compiler-focus", result)
        print("compiler", c, a, result.get("qualified"), result.get("baseline"), result.get("best"), flush=True)


def configs(campaign, limit, cross=False):
    stage = "config-cross" if cross else "config-unseen"
    manifest = ROOT / ("config-cross-manifest.json" if cross else "config-manifest.json")
    if not manifest.exists():
        groups = defaultdict(set)
        for line in (OLD / "configuration.jsonl").read_text().splitlines():
            row = json.loads(line)
            w = row.get("winner", {})
            if w.get("submission", {}).get("verified") and w.get("submission", {}).get("score") == 100:
                path = w.get("candidate_path")
                if path and Path(path).exists():
                    source = Path(path).read_text()
                    groups[row["client"], source].add(row["unit"])
        frozen = []
        scores = live(campaign)
        shapes = excluded_shapes()
        if cross:
            source_units = defaultdict(set)
            for (_, source), units in groups.items():
                source_units[source].update(units)
            groups = {(c, source): units for source, units in source_units.items() for c in campaign.info["clients"]}
        covered = set()
        if cross:
            for line in (OLD / "configuration.jsonl").read_text().splitlines():
                r = json.loads(line)
                for v in r.get("variants", []):
                    covered.add((r["client"], r["addr"], v.get("source_sha256")))
        for (c, source), units in groups.items():
            if c not in campaign.info["clients"]:
                continue
            rows = [a for a, r in match._functions(c).items()
                    if (r.get("unit", "").startswith("CXT") if cross else r.get("unit") in units) and r.get("kind") == "code"
                    and r.get("shape") not in shapes and scores[c].get(a, {}).get("score", 0) < (100 if cross else 1)
                    and (c, a, digest(source)) not in covered]
            if rows:
                frozen.append(dict(client=c, source=source, units=sorted(units), rows=rows))
        random.Random(20261011).shuffle(frozen)
        manifest.write_text(json.dumps(frozen), encoding="utf-8")
    done = {r["key"] for r in campaign.previous(stage)}
    scores = live(campaign)
    for group in json.loads(manifest.read_text())[:limit]:
        c, source = group["client"], group["source"]
        key = digest(c + source)
        if c not in campaign.info["clients"] or key in done:
            continue
        result = dict(key=key, client=c, units=group["units"], targets=len(group["rows"]), winners=[], cost=0)
        started = time.monotonic()
        try:
            target = fingerprint.Target(c)
            target.index = defaultdict(list)
            for a in group["rows"]:
                if scores[c].get(a, {}).get("score", 0) < 100:
                    target.index[match._functions(c)[a]["size"]].append(a)
            # Compile once per client/source. Reuse size index; retain full data verification.
            obj = match.compile_text(c, source)
            found = target.match_obj(obj, source)
            for a in found:
                winner = campaign.submit_exact(stage, c, a, source)
                result["winners"].append(winner)
                if winner.get("submission", {}).get("score") == 100 or winner.get("already_exact"):
                    scores[c][a] = dict(score=100)
        except (RuntimeError, ValueError, OSError, SystemExit) as e:
            result["error"] = str(e)[-500:]
        result["seconds"] = round(time.monotonic()-started, 3)
        campaign.record(stage, result)
        print("config", c, group["units"], result["targets"], len(result["winners"]), flush=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("stage", choices=["data", "compiler", "config", "config-cross"])
    ap.add_argument("--limit", type=int, default=12)
    ap.add_argument("--scale-if-wins", action="store_true")
    args = ap.parse_args()
    campaign = Campaign(str(ROOT), "http://127.0.0.1:8765")
    stage = {"data": "initialized-data-v2", "compiler": "compiler-focus", "config": "config-unseen", "config-cross": "config-cross"}[args.stage]
    runner = {"data": data, "compiler": compiler, "config": configs,
              "config-cross": lambda c, n: configs(c, n, cross=True)}[args.stage]
    runner(campaign, args.limit)
    rows = campaign.previous(stage)
    winners = [w for r in rows for w in ([r.get("winner", {})] + r.get("winners", []))]
    wins = sum(w.get("submission", {}).get("improved", False) for w in winners)
    pilot = dict(stage=stage, records=len(rows), new_exact=wins, cost=0,
                 scale=bool(args.scale_if_wins and wins >= (10 if args.stage == "config-cross" else 2)))
    campaign.record("pilot-decisions", pilot)
    print("PILOT", json.dumps(pilot), flush=True)
    if pilot["scale"]:
        runner(campaign, 1000000)


if __name__ == "__main__":
    main()
