"""Reverse-engineering pilot driver: unit selection, evidence dump, attempt ledger.

Offline helpers only: nothing here contacts the server by itself. `attempts`
records one JSONL row per candidate so the pilot stays reproducible.

    py -3.12 -m benchmarks.re_pilot select --out work/re-pilot-20261010
    py -3.12 -m benchmarks.re_pilot inspect --client 2008-06 --addr 005c0a20
    py -3.12 -m benchmarks.re_pilot status
"""
import argparse
import collections
import hashlib
import json
import random
import re
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from roc import clients, match  # noqa: E402

EXCLUDE = {"2009-12"}


def load_rows(client):
    with (ROOT / "work" / client / "functions.jsonl").open() as fh:
        return [json.loads(line) for line in fh]


def load_scores(client):
    return json.loads((ROOT / "work" / client / "scores.json").read_text())


def unit_table(client):
    """{unit: {n, exact, unresolved:[row], callers}} for code functions."""
    scores = load_scores(client)
    table = collections.defaultdict(lambda: {"n": 0, "exact": 0, "unresolved": [], "callers": 0})
    for row in load_rows(client):
        if row.get("kind") != "code":
            continue
        cell = table[row["unit"]]
        cell["n"] += 1
        cell["callers"] += len(row.get("callers") or [])
        if scores.get(row["addr"]) == 100:
            cell["exact"] += 1
        else:
            cell["unresolved"].append(row)
    return table


def eligible(client, low=0.90, high=1.0, min_n=12):
    """Units whose match rate is inside [low, high) with unresolved functions."""
    out = []
    for unit, cell in unit_table(client).items():
        if cell["n"] < min_n:
            continue
        rate = cell["exact"] / cell["n"]
        if low <= rate < high and cell["unresolved"]:
            out.append({"client": client, "unit": unit, "n": cell["n"], "exact": cell["exact"],
                        "rate": round(rate, 4), "unresolved": len(cell["unresolved"]),
                        "avg_callers": round(cell["callers"] / cell["n"], 1),
                        "targets": sorted(r["addr"] for r in cell["unresolved"])})
    return out


def rank(item):
    """Pilot score: match rate, siblings, reuse evidence, caller evidence."""
    return (round(item["rate"], 2), item["n"], item["unresolved"], item["avg_callers"])


def cmd_select(args):
    picked = []
    high = []
    for client in sorted(clients.load()):
        if client in EXCLUDE:
            continue
        if not (ROOT / "work" / client / "functions.jsonl").exists():
            continue
        high.extend(eligible(client, 0.90, 1.0, 20))

    def free(pool):
        return [p for p in pool if (p["client"], p["unit"]) not in
                {(q["client"], q["unit"]) for q in picked}]

    def pick(pool, role, why, min_unres=3, max_n=400):
        pool = [p for p in free(pool) if p["unresolved"] >= min_unres and p["n"] <= max_n]
        pool.sort(key=rank, reverse=True)
        for cand in pool:
            if len([c for c in picked if c["client"] == cand["client"]]) < 2:
                item = dict(cand, role=role, why=why)
                picked.append(item)
                return item
        return None

    a = pick(high, "high_reuse", ">=90% unit, most unresolved functions left")
    b = pick(high, "high_reuse", "second >=90% unit, distinct client/class") if a else None
    if a is None or b is None:
        print("not enough >=90% units with >=3 unresolved functions", file=sys.stderr)

    rest = free(high)
    random.seed(args.seed)
    random.shuffle(rest)
    dice = None
    for cand in rest:
        if cand["unresolved"] >= 2 and cand["n"] <= 400 and cand["client"] not in \
                {q["client"] for q in picked}:
            dice = cand
            break
    if dice:
        picked.append(dict(dice, role="random_high", why="seeded random >=90% unit"))

    medium = []
    for client in sorted(clients.load()):
        if client in EXCLUDE or not (ROOT / "work" / client / "functions.jsonl").exists():
            continue
        medium.extend(eligible(client, 0.70, 0.90, 25))
    named = [p for p in medium if "::" in p["unit"] and p["n"] <= 400]
    named.sort(key=lambda p: (-p["avg_callers"], -p["n"]))
    if named:
        cand = next((p for p in named if p["client"] not in {q["client"] for q in picked}), named[0])
        picked.append(dict(cand, role="medium_match_callers",
                           why="70-90% named unit, highest average caller count"))

    families = {p["unit"].split("::")[0] for p in picked}
    other = [p for p in free(medium)
             if p["unit"].split("::")[0] not in families and p["n"] <= 400
             and p["client"] not in {q["client"] for q in picked}]
    other.sort(key=lambda p: (-p["n"], -p["unresolved"]))
    if other:
        cand = other[0]
        picked.append(dict(cand, role="cross_family",
                           why="unrelated class family, lower match rate, library-shaped unit"))

    out = {"pilot": "re-pilot", "seed": args.seed, "excluded": sorted(EXCLUDE), "units": picked}
    if args.out:
        path = Path(args.out)
        path.mkdir(parents=True, exist_ok=True)
        (path / "units.json").write_text(json.dumps(out, indent=1))
    print(json.dumps(out, indent=1))
    return 0


def resolved_asm(client, addr):
    """Disassembly with real absolute addresses (reloc slots decode to targets)."""
    base, image = match._image(client)
    code, relocs, row = match.target(client, addr)
    va = int(addr, 16)
    lines = []
    md = __import__("capstone").Cs(__import__("capstone").CS_ARCH_X86,
                                   __import__("capstone").CS_MODE_32)
    rvas = set()
    from roc import analyze
    pe_relocs = analyze.reloc_sites(match.pefile.PE(str(clients.exe_path(client, clients.load()[client])),
                                                   fast_load=True))
    for a, size, mnem, ops in md.disasm_lite(code, va):
        text = "%08x  %-22s %s %s" % (a, code[a - va:a - va + size].hex(), mnem, ops)
        for value in re.findall(r"0x[0-9a-f]+", ops):
            v = int(value, 16)
            if base <= v < base + len(image):
                chunk = image[v - base:v - base + 96]
                text += "   ; -> %08x" % v
                for m in re.finditer(rb"[ -~]{4,}", chunk):
                    text += ' "%s"' % m.group().decode("latin-1")
                    break
        lines.append(text)
    return lines, row


def cmd_inspect(args):
    client, addr = args.client, args.addr
    base, image = match._image(client)
    lines, row = resolved_asm(client, addr)
    print("== %s %s  unit %s  size %d bytes  score %s" %
          (client, addr, row["unit"], row["size"], load_scores(client).get(addr)))
    print("\n".join(lines))
    print("-- facts")
    for key in ("calling_convention", "calls", "call_targets", "callers", "external_calls",
                "imports", "strings", "data_refs", "virtual_slots", "stack_args",
                "this_reads", "this_writes", "constants"):
        print("   %-20s %s" % (key, row.get(key)))
    print("-- siblings: %s" % (row.get("siblings") or []))
    for sib in row.get("siblings") or []:
        path = ROOT / "src" / client / ("%s.cpp" % sib)
        head = ""
        if path.exists():
            text = path.read_text(errors="replace")
            body = [l for l in text.splitlines() if not l.startswith("//")]
            head = "\n".join(body[:args.sibling_lines]) or "(template only)"
        print("   %s %s" % (sib, "EXACT" if load_scores(client).get(sib) == 100 else
                            load_scores(client).get(sib)))
        for line in head.splitlines():
            print("      " + line)
    print("-- local source")
    path = ROOT / "src" / client / ("%s.cpp" % addr)
    print(path.read_text(errors="replace") if path.exists() else "(none)")
    return 0


def cmd_status(args):
    for client in sorted(clients.load()):
        if client in EXCLUDE:
            continue
        if not (ROOT / "work" / client / "scores.json").exists():
            continue
        scores = load_scores(client)
        total = len(scores)
        exact = sum(1 for v in scores.values() if v == 100)
        print("%s  %d/%d matched (%.1f%%)" % (client, exact, total, 100.0 * exact / max(1, total)))
    return 0


class Ledger:
    """JSONL attempt + discovery ledger for the pilot (work/re-pilot-*/)."""

    def __init__(self, folder):
        self.dir = Path(folder)
        self.dir.mkdir(parents=True, exist_ok=True)

    def record(self, name, row):
        with (self.dir / name).open("a", encoding="utf-8") as fh:
            fh.write(json.dumps(row, separators=(",", ":")) + "\n")

    def paths(self):
        return [str(self.dir / n) for n in ("attempts.jsonl", "discoveries.jsonl") if
                (self.dir / n).exists()]


def base_facts(client, addr):
    """Everything a target record needs: score, unit, siblings, callers/callees, asm."""
    scores = load_scores(client)
    rows = load_rows(client)
    row = next((r for r in rows if r["addr"] == addr), None)
    lines, _ = resolved_asm(client, addr)
    return {
        "client": client,
        "addr": addr,
        "unit": row["unit"] if row else None,
        "size": row["size"] if row else None,
        "local_score": scores.get(addr),
        "siblings": (row.get("siblings") or []) if row else [],
        "callers": (row.get("callers") or []) if row else [],
        "call_targets": (row.get("call_targets") or []) if row else [],
        "strings": (row.get("strings") or []) if row else [],
        "constants": (row.get("constants") or []) if row else [],
        "asm": lines,
    }


def server_best(server, token, client, addr):
    from roc import worker
    try:
        item = worker.Api(server, token).call("/v1/source?client=%s&addr=%s" % (client, addr))
    except Exception as error:  # offline server: local evidence only
        return {"error": str(error)}
    return {"score": int((item or {}).get("score", 0) or 0),
            "user": (item or {}).get("user"), "source": (item or {}).get("source") or ""}


def cmd_try(args):
    """Compile one candidate locally and ledger the attempt (no server)."""
    text = Path(args.source).read_text()
    try:
        score, _sym, diff, _spans = match.check_text(args.client, args.addr, text)
    except match.CompileError as error:
        print("COMPILE ERROR: %s" % str(error).splitlines()[0])
        return 1
    print("SCORE %s" % score)
    print(diff)
    ledger = Ledger(args.out)
    ledger.record("attempts.jsonl", dict(
        ts=time.time(), worker="re-pilot", client=args.client, addr=args.addr,
        baseline=load_scores(args.client).get(args.addr), candidate=score,
        status="exact" if score == 100 else ("partial" if score > (load_scores(args.client).get(args.addr) or 0) else "no-gain"),
        source_sha=hashlib.sha1(text.encode()).hexdigest(), hypothesis=args.hypothesis,
        evidence=args.evidence.split(";") if args.evidence else [],
        edits=args.edits, compile_result="ok", server_result="local-only",
        mismatch=diff.splitlines()[:12], provenance=[], rejection="",
        discovery=args.discovery, next_action=args.next))
    if args.discovery:
        ledger.record("discoveries.jsonl", dict(ts=time.time(), discovery=args.discovery,
                                                client=args.client, addr=args.addr, evidence=args.evidence))
    return 0


def cmd_submit(args):
    """Lease one target, verify locally, submit to the server, ledger the outcome."""
    from roc import worker
    s = worker.load_settings()
    server = args.server or s.get("server")
    user = args.user or s.get("user")
    if not server or not user:
        print("need --server and --user (or roc config)")
        return 2
    api = worker.Api(server, args.token or s.get("token"))
    facts = base_facts(args.client, args.addr)
    prior = server_best(server, args.token or s.get("token"), args.client, args.addr)
    job = None
    try:
        job = api.call("/v1/lease", {"user": user, "worker": "re-pilot", "clients": [args.client],
                                     "mode": "ai", "max_size": 4096,
                                     "targets": [args.addr], "order": "random"})["job"]
    except worker.ApiFailure as error:
        print("lease failed: %s" % error)
    text = Path(args.source).read_text()
    try:
        score, _sym, diff, _spans = match.check_text(args.client, args.addr, text)
    except match.CompileError as error:
        print("COMPILE ERROR: %s" % str(error).splitlines()[0])
        return 1
    print("local score %s  (server best %s)" % (score, prior.get("score")))
    result = {"improved": False, "stored": score, "verified": False, "error": "not submitted"}
    if score == 100 or score > int(prior.get("score", 0) or 0):
        payload = {"user": user, "worker": "re-pilot", "client": args.client, "addr": args.addr,
                   "score": score, "source": text}
        if job:
            payload["lease"] = job["lease"]
        try:
            result = api.call("/v1/submit", payload)
        except worker.ApiFailure as error:
            result = {"error": str(error)}
    else:
        result = {"error": "not better than server; not submitted", "improved": False}
    print("server: %s" % result)
    ledger = Ledger(args.out)
    ledger.record("attempts.jsonl", dict(
        ts=time.time(), worker="re-pilot", client=args.client, addr=args.addr,
        baseline=int(prior.get("score", 0) or 0), candidate=score,
        status="exact" if result.get("verified") and result.get("stored") == 100 else
               ("improved" if result.get("improved") else "no-gain"),
        source_sha=hashlib.sha1(text.encode()).hexdigest(), hypothesis=args.hypothesis,
        evidence=args.evidence.split(";") if args.evidence else [],
        edits=args.edits, compile_result="ok", server_result=result,
        mismatch=diff.splitlines()[:12], provenance=[], rejection="",
        discovery=args.discovery, next_action=args.next,
        facts=facts, server_user=prior.get("user")))
    if args.discovery:
        ledger.record("discoveries.jsonl", dict(ts=time.time(), discovery=args.discovery,
                                                client=args.client, addr=args.addr, evidence=args.evidence))
    return 0



CREATOR_TEMPLATE = """\
// roc-flags: %(flags)s
struct Value { int x; };
%(decls)s

Value& func_%(addr)s()
{
    static Value& value = %(call)s;
    return value;
}
"""


def target_calls(client, addr):
    """Parse the guard-static prologue: (stack args, call target, store, fast path)."""
    base, image = match._image(client)
    code, relocs, row = match.target(client, addr)
    base_va = int(addr, 16)
    reloc_set = {base_va + r for r in relocs}
    md = __import__("capstone").Cs(__import__("capstone").CS_ARCH_X86,
                                   __import__("capstone").CS_MODE_32)
    pushes, call_target, store, fast = [], None, None, None
    seen_or = seen_call = False
    for offset, size, mnem, ops in md.disasm_lite(code, base_va):
        text = ops.lower()
        if mnem == "or" and text.startswith("dword ptr ["):
            seen_or = True
            continue
        if not seen_or:
            continue
        if mnem == "call":
            import re as _re
            m = _re.search(r"0x([0-9a-f]+)", text)
            call_target = int(m.group(1), 16) if m else None
            seen_call = True
            continue
        if mnem == "push":
            if offset + 1 in reloc_set:
                pushes.append(("addr", int(ops, 0)))
            else:
                pushes.append(("imm", int(ops, 0)))
            continue
        if seen_call and mnem == "mov" and text.startswith("dword ptr ["):
            store = int(_re.search(r"0x([0-9a-f]+)", text).group(1), 16)
        if seen_call and mnem == "mov" and text.startswith("eax, dword ptr ["):
            fast = int(_re.search(r"0x([0-9a-f]+)", text).group(1), 16)
    return {"pushes": pushes, "call": call_target, "store": store, "fast": fast,
            "ret": row["calling_convention"], "size": row["size"]}


def creator_source(client, addr, flags=None):
    """Source for one guard-static instance (the FactoryProduct::Creator template)."""
    info = target_calls(client, addr)
    decls, args, params = [], [], []
    for index, (kind, value) in enumerate(info["pushes"]):
        if kind == "addr":
            name = "g_%08x" % value
            decls.append("extern struct Desc%d { int pad[8]; } %s;" % (index, name))
            args.append("&%s" % name)
        else:
            args.append(str(value))
        params.append("void*" if kind == "addr" else "int")
    call = "sub_%08x(%s)" % (info["call"], ", ".join(args)) if info["call"] else "0(%s)" % args
    decls.append('Value& sub_%08x(%s);' % (info["call"] or 0, ", ".join(params) or "void*"))
    text = CREATOR_TEMPLATE % {"flags": flags or client_creator_flags(client), "decls": "\n".join(decls),
                               "call": call, "addr": addr}
    return text, info


def client_creator_flags(client):
    entry = clients.load()[client]
    base = (entry.get("flags") or match.DEFAULT_FLAGS).split()
    keep = [f for f in base if f != "/EHa"]
    return " ".join(keep + ["/Ob2", "/Oy", "/GF"])


def cmd_creator(args):
    """Propagate the solved guard-static reference template to same-shape targets."""
    ledger = Ledger(args.out)
    shape_ref = target_calls("2011-06", "00635dc0")
    total_exact = total_submit = 0
    for client in args.clients.split(","):
        rows = load_rows(client)
        scores = load_scores(client)
        for row in rows:
            if row.get("kind") != "code":
                continue
            addr = row["addr"]
            if scores.get(addr) == 100:
                continue
            try:
                text, info = creator_source(client, addr)
            except Exception as error:
                continue
            if len(info["pushes"]) > 2 or not info["call"]:
                continue
            if info["store"] is None or info["fast"] is None:
                continue
            try:
                score, _sym, diff, _spans = match.check_text(client, addr, text)
            except match.CompileError:
                continue
            if score != 100:
                continue
            total_exact += 1
            print("%s %s -> %d  (call %08x, args %s)" % (client, addr, score, info["call"],
                                                         info["pushes"]))
            ledger.record("attempts.jsonl", dict(
                ts=time.time(), worker="re-pilot", client=client, addr=addr,
                baseline=scores.get(addr), candidate=score, status="propagated-exact",
                source_sha=hashlib.sha1(text.encode()).hexdigest(),
                hypothesis="FactoryProduct::Creator guard-static reference template",
                evidence=["exact 2011-06 00635dc0 template", "pushes=%s" % info["pushes"],
                          "call=%08x" % info["call"]],
                edits="generated from template", compile_result="ok",
                server_result="local", mismatch=[], provenance=[], rejection="",
                discovery="guard-static reference template", next_action="submit"))
            (Path(args.out) / ("%s_%s.cpp" % (client, addr))).write_text(text)
            if args.submit and total_submit < args.limit:
                from roc import worker
                s = worker.load_settings()
                api = worker.Api(args.server or s["server"])
                prior = server_best(api.server, None, client, addr)
                if int(prior.get("score", 0) or 0) >= 100:
                    continue
                try:
                    job = api.call("/v1/lease", {"user": args.user, "worker": "re-pilot",
                                                 "clients": [client], "mode": "ai",
                                                 "max_size": 4096, "targets": [addr],
                                                 "order": "random"})["job"]
                except worker.ApiFailure:
                    job = None
                try:
                    r = api.call("/v1/submit", {"user": args.user, "worker": "re-pilot",
                                                "client": client, "addr": addr, "score": 100,
                                                "source": text,
                                                **({"lease": job["lease"]} if job else {})})
                except worker.ApiFailure as error:
                    r = {"error": str(error)}
                total_submit += 1
                print("   submitted: %s" % r)
                ledger.record("attempts.jsonl", dict(
                    ts=time.time(), worker="re-pilot", client=client, addr=addr,
                    baseline=int(prior.get("score", 0) or 0), candidate=100,
                    status="exact" if r.get("verified") else "no-gain",
                    source_sha=hashlib.sha1(text.encode()).hexdigest(),
                    hypothesis="FactoryProduct::Creator guard-static reference template",
                    evidence=["propagation from 2011-06 00635dc0"],
                    edits="generated from template", compile_result="ok", server_result=r,
                    mismatch=[], provenance=[], rejection="", discovery="propagation",
                    next_action="continue propagation"))
    print("exact candidates: %d, submitted: %d" % (total_exact, total_submit))
    return 0


COMMANDS = {"select": cmd_select, "inspect": cmd_inspect, "status": cmd_status,
            "try": cmd_try, "submit": cmd_submit, "creator": cmd_creator}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("select")
    p.add_argument("--seed", type=int, default=20261010)
    p.add_argument("--out", default="work/re-pilot-20261010")
    p = sub.add_parser("inspect")
    p.add_argument("--client", required=True)
    p.add_argument("--addr", required=True)
    p.add_argument("--sibling-lines", type=int, default=24)
    sub.add_parser("status")
    p = sub.add_parser("try")
    p.add_argument("--client", required=True)
    p.add_argument("--addr", required=True)
    p.add_argument("--source", required=True)
    p.add_argument("--hypothesis", default="")
    p.add_argument("--evidence", default="")
    p.add_argument("--edits", default="")
    p.add_argument("--discovery", default="")
    p.add_argument("--next", default="")
    p.add_argument("--out", default="work/re-pilot-20261010")
    p = sub.add_parser("submit")
    p.add_argument("--client", required=True)
    p.add_argument("--addr", required=True)
    p.add_argument("--source", required=True)
    p.add_argument("--hypothesis", default="")
    p.add_argument("--evidence", default="")
    p.add_argument("--edits", default="")
    p.add_argument("--discovery", default="")
    p.add_argument("--next", default="")
    p.add_argument("--server", default=None)
    p.add_argument("--user", default=None)
    p.add_argument("--token", default=None)
    p.add_argument("--out", default="work/re-pilot-20261010")
    p = sub.add_parser("creator")
    p.add_argument("--clients", default="2011-06,2012-06")
    p.add_argument("--submit", action="store_true")
    p.add_argument("--limit", type=int, default=10)
    p.add_argument("--user", default="colin")
    p.add_argument("--server", default=None)
    p.add_argument("--out", default="work/re-pilot-20261010")
    args = ap.parse_args(argv)
    return COMMANDS[args.cmd](args)


if __name__ == "__main__":
    raise SystemExit(main())
