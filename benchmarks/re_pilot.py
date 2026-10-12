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
import capstone

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


WRAPPER_SRC = """\
// roc-flags: /O2 /GS- /EHsc /MD
extern void sub_a_%(addr)s();
extern int sub_b_%(addr)s(void*);
extern int g_b_%(addr)s;

void func_%(addr)s()
{
    sub_a_%(addr)s();
    sub_b_%(addr)s(&g_b_%(addr)s);
}
"""

LOCKFREE_SRC = """\
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __stdcall release_%(addr)s(void*);
extern "C" void* _InterlockedExchange(void* volatile* target, void* value);
extern void* g_pool_%(addr)s;

void func_%(addr)s()
{
    void* p = _InterlockedExchange((void* volatile*)&g_pool_%(addr)s, 0);
    if (p)
        release_%(addr)s(p);
}
"""

GLOBAL_INIT_SRC = """\
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_ptr_%(addr)s;
extern "C" int init_fn_%(addr)s(void*);
extern void* g_target_%(addr)s;
extern int g_value_%(addr)s;

void func_%(addr)s()
{
    if (g_ptr_%(addr)s)
        init_fn_%(addr)s(g_ptr_%(addr)s);
    g_target_%(addr)s = &g_value_%(addr)s;
}
"""

FACTORY_SRC = """\
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_%(addr)s {
    T4_%(addr)s();
    virtual void f_%(addr)s();
    char m_a;
    char m_b;
};
T4_%(addr)s::T4_%(addr)s() : m_a(0), m_b(0) {}
extern "C" void* create_other_%(addr)s(void*, void*, int);
void* create_%(addr)s(void* unused, T4_%(addr)s* out, int type)
{
    if (type != 4)
        return create_other_%(addr)s(unused, out, type);
    out->T4_%(addr)s::T4_%(addr)s();
    return out;
}
"""

STATIC_REG_SRC = """\
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void seh_fn_%(addr)s(void*);
extern int g_a_%(addr)s;
extern int g_b_%(addr)s;
extern int g_arg_%(addr)s;
struct Reg_%(addr)s { Reg_%(addr)s() { g_a_%(addr)s = 0; g_b_%(addr)s = 0; seh_fn_%(addr)s(&g_arg_%(addr)s); } };
void func_%(addr)s()
{
    static Reg_%(addr)s reg;
}
"""

THREE_CALL_SRC = """\
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void init_fn_%(addr)s(void*, void*);
extern "C" void run_fn_%(addr)s(void);
extern "C" void tail_fn_%(addr)s(void*);
extern int g_a_%(addr)s;
extern int g_b_%(addr)s;
extern int g_c_%(addr)s;

void func_%(addr)s()
{
    init_fn_%(addr)s(&g_a_%(addr)s, &g_b_%(addr)s);
    run_fn_%(addr)s();
    tail_fn_%(addr)s(&g_c_%(addr)s);
}
"""

REG_WRAPPER_NOTE = "registration wrapper"


def reg_wrapper_source(client, addr, flags=None):
    """Source for the push-sequence registration family.

    push p1..pn ; [mov ecx, imm] ; call F ; push q ; call G ; pop ecx ; ret
    Args are the reversed pushes (MSVC pushes right-to-left); relocated pushes
    become pointers to fresh globals, immediates stay literals.
    """
    import capstone as cs
    code, relocs, row = match.target(client, addr)
    base_va = int(addr, 16)
    reloc_set = {base_va + r for r in relocs}
    md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
    pushes = []
    ecx_imm = None
    for off, _size, mnem, ops in md.disasm_lite(code, base_va):
        if mnem == "call":
            break
        if mnem == "push":
            value = int(ops, 0)
            pushes.append((off + 1 in reloc_set, value))
        elif mnem == "mov" and ops.startswith("ecx,"):
            ecx_imm = int(ops.split(",", 1)[1].strip(), 0)
    args, decls, types = [], [], []
    for index, (is_addr, value) in enumerate(reversed(pushes)):
        if is_addr:
            name = "g_%s_%d" % (addr, index)
            decls.append("extern int %s;" % name)
            args.append("(void*)&%s" % name)
            types.append("void*")
        else:
            args.append(str(value))
            types.append("int")
    lines = ["// roc-flags: %s" % (flags or client_creator_flags(client)),
             'extern "C" void tail_fn_%s(void*);' % addr,
             "struct O_%s { int m(%s); };" % (addr, ", ".join(types))]
    if ecx_imm is not None and any(p[0] for p in pushes):
        lines.append("extern O_%s g_obj_%s;" % (addr, addr))
        call = "g_obj_%s.m(%s)" % (addr, ", ".join(args))
    else:
        lines.append("struct Host_%s { int m(%s); };" % (addr, ", ".join(types)))
        call = "((Host_%s*)0)->m(%s)" % (addr, ", ".join(args))
    lines.append("extern int g_tail_%s;" % addr)
    lines.append("void func_%s()" % addr)
    lines.append("{")
    lines.append("    %s;" % call)
    lines.append("    tail_fn_%s(&g_tail_%s);" % (addr, addr))
    lines.append("}")
    return "\n".join(decls + lines), {"pushes": pushes, "ecx": ecx_imm}


TEMPLATE_CALLABLES = {
    "reg_wrapper": ("2010-06", "009c2dc0", reg_wrapper_source),
}

# Verified template families. Each entry: exemplar (client, addr) whose shape is
# matched byte-for-byte across clients, plus the source generator.
CTOR_ATEXIT_SRC = """\
// roc-flags: /O2 /GS- /EHsc /MD
extern void* g_a_%(addr)s;
extern void* g_b_%(addr)s;
extern void* g_c_%(addr)s;
extern "C" void atexit_fn_%(addr)s(void*);
struct X_%(addr)s {
    X_%(addr)s(int flags);
    virtual void f_%(addr)s();
    void* m_a;
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_b;
    void* m_c;
    void init_%(addr)s();
};
X_%(addr)s::X_%(addr)s(int flags) : m_a(&g_a_%(addr)s), m_b(&g_b_%(addr)s), m_c(&g_c_%(addr)s)
{
    init_%(addr)s();
    if (flags & 1)
        atexit_fn_%(addr)s(this);
}
"""

RECEIVER_ARG_SRC = r"""
// roc-flags: /O2 /GS- /EHsc /MD
struct Obj { void f4(void*); };
extern "C" void reg_fn(void*, void*);
extern "C" void* make_fn(void);
extern "C" Obj* init_fn();
extern void (*g_cb)(void);
extern void fn_a();
extern void fn_b();
extern void fn_c();
void func_%(addr)s()
{
    g_cb = &fn_c;
    reg_fn(&fn_a, &fn_b);
    void* local = make_fn();
    init_fn()->f4(&local);
}
"""

REG9_MI_SRC = r"""
// roc-flags: /O2 /GS- /EHsc /MD
struct A { int a; }; struct B { int b; };
struct Obj : A,B { void get(); void set(); void init(void*,void*,void (Obj::*)(),void (Obj::*)(),int,int); };
extern Obj obj;
extern int a,b,e;
extern "C" void tail(void*);
void func_%(addr)s() {
    obj.init(&a,&b,&Obj::set,&Obj::get,15,0);
    tail(&e);
}
"""

DYNAMIC_CAST_SRC = r"""
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance { public: virtual ~Instance(); char pad[0xc0]; Instance* next; };
class ServiceProvider : public Instance { public: ServiceProvider* finish(); };
}
RBX::ServiceProvider* func_%(addr)s(RBX::Instance* p) {
    while (p) {
        if (RBX::ServiceProvider* q = dynamic_cast<RBX::ServiceProvider*>(p)) return q->finish();
        p = p->next;
    }
    return 0;
}
"""

IMPORT_STORE_SRC = r"""
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_%(addr)s();
extern void* stored_%(addr)s;
void func_%(addr)s() { stored_%(addr)s = get_value_%(addr)s(); }
"""

CTOR_FIELD_SRC = r"""
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g0_%(addr)s,g8_%(addr)s,g20_%(addr)s,g2c_%(addr)s,g30_%(addr)s;
extern "C" void cleanup_%(addr)s(void*);
struct X_%(addr)s {
    void* f0; int pad4; void* f8; char padc[0x14]; void* f20; char pad24[8]; void* f2c; void* f30;
    void base();
    X_%(addr)s* init(int flags);
};
X_%(addr)s* X_%(addr)s::init(int flags) {
    f0=&g0_%(addr)s; f8=&g8_%(addr)s; f20=&g20_%(addr)s; f2c=&g2c_%(addr)s; f30=&g30_%(addr)s;
    base();
    if (flags & 1) cleanup_%(addr)s(this);
    return this;
}
"""

def ctor_field_source(client, addr):
    import capstone as cs
    import re
    code, _relocs, _row = match.target(client, addr)
    md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
    offsets = []
    for _off, _size, mnem, ops in md.disasm_lite(code, int(addr, 16)):
        if mnem == "mov" and ops.startswith("dword ptr [esi"):
            m = re.search(r"\+\s*(0x[0-9a-f]+|[0-9]+)", ops)
            off = int(m.group(1), 0) if m else 0
            if off not in offsets:
                offsets.append(off)
    offsets.sort()
    fields = []
    cur = 0
    for off in offsets:
        if off > cur:
            fields.append("    char pad_%x[%d];" % (cur, off - cur))
        fields.append("    void* f_%x;" % off)
        cur = off + 4
    assigns = "\n".join("    f_%x = &g_%x_%s;" % (off, off, addr) for off in offsets)
    decls = ", ".join("g_%x_%s" % (off, addr) for off in offsets)
    body = "\n".join(fields)
    text = """// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char %s;
extern \"C\" void cleanup_%s(void*);
struct X_%s {
%s
    void base();
    X_%s* init(int flags);
};
X_%s* X_%s::init(int flags) {
%s
    base();
    if (flags & 1) cleanup_%s(this);
    return this;
}
""" % (decls, addr, addr, body, addr, addr, addr, assigns, addr)
    return text, {"offsets": offsets}

def creator_tail_source(client, addr):
    import capstone as cs
    import re
    code, _relocs, _row = match.target(client, addr)
    md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
    writes = []
    for _off, _size, mnem, ops in md.disasm_lite(code, int(addr, 16)):
        if mnem != "mov" or not ops.startswith("dword ptr [ecx"):
            continue
        m = re.search(r"\+\s*(0x[0-9a-f]+|[0-9]+)", ops)
        off = int(m.group(1), 0) if m else 0
        imm = re.search(r",\s*(0x[0-9a-f]+|[0-9]+)$", ops)
        if imm:
            writes.append((off, int(imm.group(1), 0)))
    writes.sort()
    fields = []
    cur = 0
    for off, _ in writes:
        if off > cur:
            fields.append("    char pad_%x[%d];" % (cur, off - cur))
        fields.append("    void* f_%x;" % off)
        cur = off + 4
    assigns = "\n".join("    f_%x = (void*)0x%x;" % (off, imm) for off, imm in writes)
    body = "\n".join(fields)
    text = """// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_%s {
%s
    X_%s* base();
    X_%s* run() {
%s
        return base();
    }
};
X_%s* func_%s(X_%s* x) { return x->run(); }
""" % (addr, body, addr, addr, assigns, addr, addr, addr)
    return text, {"writes": writes}

def dynamic_cast_source(client, addr):
    import capstone as cs
    code, _relocs, _row = match.target(client, addr)
    md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
    offset = 0xc4
    for _off, _size, mnem, ops in md.disasm_lite(code, int(addr, 16)):
        if mnem == "mov" and ops.startswith("esi, dword ptr [esi +"):
            offset = int(ops.rsplit("+", 1)[1].rstrip("] "), 0)
            break
    text = DYNAMIC_CAST_SRC.replace("0xc0", "0x%x" % (offset - 4))
    return text % {"addr": addr}, {"offset": offset}

SEH_DESCRIPTOR_SRC = r"""
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc_%(addr)s(int, const char*, int);
struct Descriptor_%(addr)s { void attach(void*); };
extern Descriptor_%(addr)s global_desc_%(addr)s;
extern void register_desc_%(addr)s(void (*)());
extern void callback_%(addr)s();
struct Init_%(addr)s {
    Init_%(addr)s() {
        void* p = make_desc_%(addr)s(0, "Instance", 0);
        global_desc_%(addr)s.attach(p);
        register_desc_%(addr)s(&callback_%(addr)s);
    }
};
Init_%(addr)s* func_%(addr)s() { static Init_%(addr)s init; return &init; }
"""

SEH_POINTER_SRC = r"""
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_%(addr)s();
void* func_%(addr)s() {
    static void* value = make_value_%(addr)s();
    return value;
}
"""

STR_COPY_SRC = r"""
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Str_%(addr)s { int words[8]; };
extern void (__thiscall* str_ctor_%(addr)s)(Str_%(addr)s*, Str_%(addr)s*);
struct X_%(addr)s {
    char pad[0xd0];
    Str_%(addr)s value;
    Str_%(addr)s* copy(Str_%(addr)s* out);
};
Str_%(addr)s* X_%(addr)s::copy(Str_%(addr)s* out)
{
    volatile int zero = 0;
    str_ctor_%(addr)s(out, &value);
    return out;
}
"""

def str_copy_source(client, addr):
    import capstone as cs
    code, _relocs, _row = match.target(client, addr)
    md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
    offset = 0xd0
    for _off, _size, mnem, ops in md.disasm_lite(code, int(addr, 16)):
        if mnem == "add" and ops.startswith("ecx,"):
            offset = int(ops.split(",", 1)[1].strip(), 0)
            break
    text = STR_COPY_SRC.replace("0xd0", "0x%x" % offset)
    return text % {"addr": addr}, {"offset": offset}

def seh_descriptor_source(client, addr):
    row = next(r for r in load_rows(client) if r["addr"] == addr)
    names = [s for s in row.get("strings", []) if s != "8csm"]
    label = max(names, key=len) if names else "Instance"
    text = SEH_DESCRIPTOR_SRC.replace('"Instance"', '"%s"' % label)
    return text % {"addr": addr}, {"literal": label}

def nested_type_callback_source(client, addr):
    import capstone as cs
    import re
    code, _relocs, _row = match.target(client, addr)
    md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
    offs = []
    for _off, _size, mnem, ops in md.disasm_lite(code, int(addr, 16)):
        if mnem != "mov":
            continue
        m = re.search(r"\[(?:ecx|eax) \+ (0x[0-9a-f]+|[0-9]+)\]", ops)
        if m:
            offs.append(int(m.group(1), 0))
    if len(offs) < 3:
        raise ValueError("nested callback offsets missing")
    text = '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct P3 { char pad[0x%x]; void* value; };
struct P2 { char pad[0x%x]; P3* p; };
struct Obj { char pad[0x%x]; P2* p; bool f(); };
struct C {};
extern "C" void* helper(void*);
extern C c;
typedef bool (__thiscall *Fn)(C*,void*);
extern Fn slot;
bool Obj::f(){ void* x=p->p->value; if(x){ x=helper(x); return slot(&c,x); } return false; }
''' % (offs[2], offs[1], offs[0])
    return text, {"offsets": offs[:3]}

def creator_out_ctor_source(client, addr):
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" void* ctor(void*); extern void* out;
void func_%s(){ void* local=(void*)0xa5beca; out=ctor(&local); }
''' % addr, None

def selection_tree_branch_source(client, addr):
    import capstone as cs
    import re
    code, _relocs, _row = match.target(client, addr)
    tag = 0
    md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
    for _off, _size, mnem, ops in md.disasm_lite(code, int(addr, 16)):
        if mnem == "mov" and ops.startswith("dword ptr [eax],"):
            m = re.search(r",\s*(0x[0-9a-f]+|[0-9]+)$", ops)
            if m:
                tag = int(m.group(1), 0)
                break
    return '''// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
extern "C" void helper_%s(void*, int, int, int);
void func_%s(void* a, void* b, int c)
{
    if (c != 4) {
        int old = c;
        *(volatile unsigned char*)&c = 0;
        helper_%s((void*)a, (int)b, old, c);
        return;
    }
    *(int*)b = 0x%x;
    ((char*)b)[4] = 0;
    ((char*)b)[5] = 0;
}
''' % (addr, addr, addr, tag), {"tag": tag}

def field_ctor_source(client, addr):
    import capstone as cs
    import re
    code, _relocs, _row = match.target(client, addr)
    offs = []
    for _off, _size, mnem, ops in cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32).disasm_lite(code, int(addr, 16)):
        if mnem == "mov" and "dword ptr [esi" in ops:
            m = re.search(r"\[esi(?: \+ (0x[0-9a-f]+|[0-9]+))?\]", ops)
            if m:
                offs.append(int(m.group(1), 0) if m.group(1) else 0)
    if not offs:
        raise ValueError("constructor field offsets missing")
    fields, prev = [], -4
    for i, off in enumerate(offs):
        gap = off - prev - 4
        if gap:
            fields.append("char pad_%d[0x%x];" % (i, gap))
        fields.append("void* f_%d;" % i)
        prev = off
    text = "// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD\n"
    text += "struct B_%s { void ctor(); };\nextern int %s;\n" % (addr, ",".join("g_%d" % i for i in range(len(offs))))
    text += "struct X_%s : B_%s { %s X_%s(); };\n" % (addr, addr, " ".join(fields), addr)
    text += "X_%s::X_%s() { ctor(); %s }\n" % (addr, addr, " ".join("f_%d=&g_%d;" % (i, i) for i in range(len(offs))))
    return text, {"offsets": offs}

def factory_guard_source(client, addr):
    import capstone as cs
    code, _relocs, _row = match.target(client, addr)
    value = 27
    for _off, _size, mnem, ops in cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32).disasm_lite(code, int(addr, 16)):
        if mnem == "push":
            try:
                n = int(ops, 0)
            except ValueError:
                continue
            if 0 < n < 0x100:
                value = n
    text = '''// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_%s { void reg(void*); };
extern Obj_%s g_obj_%s;
extern void* g_arg_%s;
extern void cb_%s();
extern void tail_%s(void*);
extern void* __stdcall make_%s(void*, int);
struct X_%s { X_%s(); };
X_%s::X_%s() { void* p=make_%s(g_arg_%s,%d); g_obj_%s.reg(p); tail_%s((void*)&cb_%s); }
X_%s* func_%s() { static X_%s x; return &x; }
''' % ((addr,) * 13 + (value,) + (addr,) * 6)
    return text, {"value": value}

def audited_descriptor_source(client, addr):
    text = '''// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* __stdcall make_desc(const char*,int);
struct Descriptor { void attach(void*); };
extern Descriptor global_desc; extern int name; extern int callback_impl;
extern void register_desc(void(*)());
struct Init { Init(){void* p=make_desc((const char*)&name,0);global_desc.attach(p);register_desc((void(*)())&callback_impl);} };
Init* func_%s(){static Init init;return &init;}
''' % addr
    return text, {"evidence": "0040a710 factory argument order compiled exact"}


HOTPATCH_THUNK_SRC = '''// roc-flags: /O2 /GS- /EHsc /MD /Oy- /hotpatch
extern "C" int __stdcall helper(int);
extern "C" int __declspec(dllimport) tail(int);
int func_%(addr)s(int x){helper(1);return tail(x);}
'''


def audited_sret_init_source(client, addr):
    import capstone
    code, _relocs, _row = match.target(client, addr)
    instructions = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32).disasm(code, int(addr, 16))
    value = next(int(x.op_str.split(",")[1].strip(), 0) for x in instructions
                 if x.mnemonic == "mov" and x.op_str.startswith("dword ptr [0x"))
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct Obj { Obj* f4(); };
extern "C" __declspec(noinline) void __cdecl reg_fn(void*,void*);
extern "C" __declspec(noinline) void* __cdecl make_fn(void);
extern "C" __declspec(noinline) Obj* __stdcall init_fn(void*);
extern "C" __declspec(noinline) void __cdecl final_fn(int);
extern void* type_tag; extern int g_value; extern int final_arg;
extern void fn_a(); extern void fn_b();
void func_%s(){void* local;reg_fn(&fn_a,&fn_b);local=make_fn();Obj* o=init_fn(&local)->f4();*(void**)o=&type_tag;g_value=0x%x;final_fn((int)&final_arg);}
''' % (addr, value)
    return text, {"value": value, "evidence": "007ee760 stdcall init compiled exact"}


def audited_mi_registration_source(client, addr):
    import capstone
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    value = next((i.operands[0].imm for i in md.disasm(code, int(addr, 16))
                  if i.mnemonic == "push" and i.operands[0].type == 2 and 0 < i.operands[0].imm < 256), 9)
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct A { int a; }; struct B { int b; };
struct Obj : A,B { void get(); void set(); void init(void*,void*,void (Obj::*)(),void (Obj::*)(),int,int); };
extern Obj obj; extern int a,b,e; extern "C" void tail(void*);
void func_%s(){obj.init(&a,&b,&Obj::set,&Obj::get,%d,0);tail(&e);}
''' % (addr, value)
    return text, {"value": value, "evidence": "009c9790 server source + multiple inheritance"}


def shape122_mi_source(client, addr):
    import capstone
    row = next(r for r in load_rows(client) if r["addr"] == addr)
    bad = {"8csm", "<$Xf", "L$$j", "T$$P", "D$(VP", "SUVW"}
    vals = [s for s in (row.get("strings") or []) if s not in bad and
            len(s) >= 3 and any(c.islower() for c in s) and
            all(c.isalnum() or c in " _-" for c in s)]
    cats = {"Data", "General", "Debug", "Screen", "Physics", "Behavior"}
    cat = next((s for s in vals if s in cats), None)
    names = [s for s in vals if s != cat]
    if not cat or not names:
        raise ValueError("shape122 descriptor literals missing")
    code, _relocs, _ = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    flag = next((i.operands[0].imm for i in md.disasm(code, int(addr, 16))
                 if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM), 1)
    return '''// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct B1{virtual void a();}; struct B2{virtual void b();};
struct C:B1,B2{void m();}; void B1::a(){} void B2::b(){} void C::m(){}
struct Obj{void run(const char*,const char*,void(C::*)(),int,int);};
extern Obj obj; extern "C" void tail(void*);
void func(){obj.run("%s","%s",&C::m,0,%d);tail((void*)0x7785b0);}
''' % (names[-1], cat, flag), {"name": names[-1], "category": cat, "flag": flag, "evidence": "shape122 standalone MI PMF"}


def audited_global_store_call_source(client, addr):
    import capstone
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    pushes = [i.operands[0].imm for i in ins if i.mnemonic == "push" and i.operands[0].type == 2]
    store = next(i.operands[0].mem.disp for i in ins
                 if i.mnemonic == "mov" and i.operands[0].type == 3 and i.operands[1].type == 1)
    text = '// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD\nextern "C" int fn(void*,int);\nvoid func_%s(){ *(volatile int*)0x%x=fn((void*)0x%x,%d); }\n' % (addr, store, pushes[1], pushes[0])
    return text, {"evidence": "shape107 volatile absolute store + reversed cdecl pushes"}


def audited_string_copy_source(client, addr):
    import capstone
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32); md.detail = True
    offset = next(i.operands[1].imm for i in md.disasm(code, int(addr, 16))
                  if i.mnemonic == "add" and i.operands[0].reg == capstone.x86.X86_REG_ECX)
    text = '// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD\nstruct Str{int words[8];}; extern void (__thiscall* str_ctor)(Str*,Str*); struct X{char pad[0x%x]; Str value; Str* copy(Str* out);}; Str* X::copy(Str* out){volatile int zero=0; str_ctor(out,&value); return out;}\n' % offset
    return text, {"evidence": "0040e2a0 volatile local indirect thiscall string ctor"}


def audited_cursor_string_source(client, addr):
    row = next(r for r in load_rows(client) if r["addr"] == addr)
    literal = (row.get("strings") or [""])[0].replace("\\", "\\\\").replace('"', '\\"')
    text = '// roc-flags: /O2 /GS- /EHsc /MD\n#include <string>\nstruct Tool { virtual std::string name() const; };\nstd::string Tool::name() const { return "%s"; }\n' % literal
    return text, {"literal": literal, "evidence": "cursor string data recovered from shape236 return"}


def mi_bound_desc_source(client, addr):
    row = next(r for r in load_rows(client) if r["addr"] == addr)
    vals = [s for s in (row.get("strings") or []) if s not in {"<$Xf", "PQSVW", "QhHW", "SUVW", "D$dP", "hcyu", "<SUV3", "8csm"}]
    clean = [s for s in vals if sum(c.isalpha() for c in s) >= 3 and all(c.isalnum() or c in " _:-" for c in s)]
    if len(clean) >= 2:
        vals = clean
    if len(vals) < 2:
        raise ValueError("descriptor strings missing")
    name = max(vals, key=lambda s: (":" not in s, any(c.isupper() for c in s), len(s)))
    arg = next(s for s in vals if s != name)
    code, _relocs, _row = match.target(client, addr)
    security = code[1] if len(code) > 1 and code[0] == 0x6A else 1
    esc = lambda s: s.replace("\\", "\\\\").replace('"', '\\"')
    text = '''// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct B1{virtual void b();}; struct B2{virtual void c();}; inline void B1::b(){} inline void B2::c(){}
struct P:B1,B2{__declspec(noinline) void method();}; inline void P::method(){}
extern "C" void helper(void(P::*)(),const char*,const char*,int,void*);
struct D{D(void(P::*)(),const char*,const char*,int);~D();};
__declspec(noinline) D::D(void(P::*f)(),const char*n,const char*a,int s){helper(f,n,a,s,this);} D::~D(){}
static D d(&P::method,"%s","%s",%d);
''' % (esc(name), esc(arg), security)
    return text, {"name": name, "arg": arg, "evidence": "multiple-inheritance PMF ABI exact at 0076db20"}


def mi_two_pmf_source(client, addr):
    row = next(r for r in load_rows(client) if r["addr"] == addr)
    vals = [s for s in (row.get("strings") or []) if s not in {"<$Xf", "PQSVW", "QhHW", "SUVW", "D$dP", "hcyu", "<SUV3", "8csm"}]
    clean = [s for s in vals if sum(c.isalpha() for c in s) >= 3 and all(c.isalnum() or c in " _:-" for c in s)]
    if len(clean) >= 2:
        vals = clean
    if len(vals) < 2:
        raise ValueError("descriptor strings missing")
    name = max(vals, key=lambda s: (":" not in s, any(c.isupper() for c in s), len(s)))
    arg = next(s for s in vals if s != name)
    code, _relocs, _row = match.target(client, addr)
    security = 5
    for i in range(min(8, len(code) - 1)):
        if code[i] == 0x6A:
            security = code[i + 1]
            break
    esc = lambda s: s.replace("\\", "\\\\").replace('"', '\\"')
    text = '''// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct B1{virtual void b();}; struct B2{virtual void c();}; inline void B1::b(){} inline void B2::c(){}
struct P:B1,B2{__declspec(noinline) void get(); __declspec(noinline) void set();}; inline void P::get(){} inline void P::set(){}
extern "C" void helper(void(P::*)(),void(P::*)(),const char*,const char*,int,void*);
struct D{D(const char*,const char*,void(P::*)(),void(P::*)(),int);~D();};
__declspec(noinline) D::D(const char*n,const char*a,void(P::*f1)(),void(P::*f2)(),int sec){helper(f1,f2,a,n,sec,this);} D::~D(){}
static D d("%s","%s",&P::get,&P::set,%d);
''' % (esc(name), esc(arg), security)
    return text, {"name": name, "arg": arg, "security": security, "evidence": "two MI PMFs exact shape193"}


def mi_one_pmf_source(client, addr):
    row = next(r for r in load_rows(client) if r["addr"] == addr)
    bad = {"<$Xf", "PQSVW", "QhHW", "SUVW", "D$dP", "hcyu", "<SUV3", "8csm", "L$$PQ", "D$ V", "h:j|", "u4h`\"", "QSUVW", "L$$Q", "t$Sh"}
    vals = [s for s in (row.get("strings") or []) if s not in bad and sum(c.isalpha() for c in s) >= 3 and all(c.isalnum() or c in " _:-" for c in s)]
    if not vals:
        raise ValueError("descriptor literal missing")
    literal = max(vals, key=lambda s: (any(c.isupper() for c in s), len(s)))
    code, _relocs, _row = match.target(client, addr)
    security = 1
    for i in range(min(8, len(code) - 1)):
        if code[i] == 0x6A:
            security = code[i + 1]
            break
    esc = literal.replace("\\", "\\\\").replace('"', '\\"')
    text = '''// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
#pragma pointers_to_members(full_generality, multiple_inheritance)
struct B1{virtual void b();}; struct B2{virtual void c();}; inline void B1::b(){} inline void B2::c(){}
struct P:B1,B2{__declspec(noinline) void method();}; inline void P::method(){}
extern "C" void helper(void(P::*)(),const char*,int,void*);
struct D{D(void(P::*)(),const char*,int);~D();};
__declspec(noinline) D::D(void(P::*f)(),const char*n,int s){helper(f,n,s,this);} D::~D(){}
static D d(&P::method,"%s",%d);
''' % (esc, security)
    return text, {"literal": literal, "security": security, "evidence": "one MI PMF exact shape149"}


def shape154_source(client, addr):
    """154 creator wrapper; wrapper call is stdcall while registration is cdecl."""
    code, relocs, row = match.target(client, addr)
    vals = [int.from_bytes(code[i + 1:i + 5], "little")
            for i, b in enumerate(code[:-4]) if b == 0x68]
    tags = [int.from_bytes(code[i + 2:i + 6], "little")
            for i in range(len(code) - 5) if code[i:i + 2] == b"\xc7\x00"]
    if len(vals) < 3 or not tags:
        raise ValueError("shape154 constants missing")
    a2, a1, tail = vals[-3:]
    return '''// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{Obj* get();}; extern "C" void reg(void*,void*); extern "C" void* make();
extern "C" Obj* __stdcall wrap(void*); extern "C" void final(void*);
void func(){void* local; reg((void*)0x%x,(void*)0x%x); local=make(); Obj* o=wrap(&local)->get(); *(void**)o=(void*)0x%x; final((void*)0x%x);}
''' % (a1, a2, tags[0], tail), {"evidence": "shape154 cdecl registration + stdcall wrapper"}


def simple_wrapper_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    pushes = [int.from_bytes(code[i + 1:i + 5], "little")
              for i, b in enumerate(code[:-4]) if b == 0x68]
    if len(pushes) != 3:
        raise ValueError("simple wrapper constants missing")
    return '''// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void first(void*,void*);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.first((void*)0x%x,(void*)0x%x);tail((void*)0x%x);}
    ''' % (pushes[1], pushes[0], pushes[2]), {"evidence": "three relocated pushes, cdecl thiscall wrapper"}


def callpush_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    pushes = [int.from_bytes(code[i + 1:i + 5], "little")
              for i, b in enumerate(code[:-4]) if b == 0x68]
    stores = [(int.from_bytes(code[i + 2:i + 6], "little"),
               int.from_bytes(code[i + 6:i + 10], "little"))
              for i in range(len(code) - 9) if code[i:i + 2] == b"\xc7\x05"]
    if len(pushes) != 2 or not stores:
        raise ValueError("callpush constants missing")
    return '''// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" void* make(); struct Obj{void run(void*,void*);}; extern Obj obj; extern "C" void tail(void*);
void func(){void* x=make();obj.run(x,(void*)0x%x);*(void**)&obj=(void*)0x%x;tail((void*)0x%x);}
''' % (pushes[0], stores[0][1], pushes[1]), {"evidence": "call + eax push, thiscall, global store, tail"}


def getset_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    src = ins[0].operands[0].mem.disp
    dst = ins[4].operands[0].mem.disp
    value = ins[4].operands[1].imm
    return '''// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void call(void*);
void func(){call((void*)*(int*)0x%x);*(int*)0x%x=0x%x;}
''' % (src, dst, value), {"evidence": "global load, cdecl call, global immediate store"}


def fourpush_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    pushes = [i.operands[0].imm for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    if len(pushes) != 5:
        raise ValueError("fourpush constants missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*,int,int);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.run((void*)0x%x,(void*)0x%x,%d,%d);tail((void*)0x%x);}
''' % (pushes[3], pushes[2], pushes[1], pushes[0], pushes[4]), {"evidence": "four relocated thiscall pushes plus tail"}


def threepush_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    pushes = [i.operands[0].imm for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    if len(pushes) != 4:
        raise ValueError("threepush constants missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*,int);}; extern Obj obj; extern int a,b,e; extern "C" void tail(void*);
void func(){obj.run((void*)&a,(void*)&b,%d);tail((void*)&e);}
''' % pushes[2], {"evidence": "three relocated thiscall pushes plus tail"}


def twopush_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    pushes = [i.operands[0].imm for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    if len(pushes) != 3:
        raise ValueError("twopush constants missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*);}; extern Obj obj; extern int a,b,e; extern "C" void tail(void*);
void func(){obj.run((void*)&a,(void*)&b);tail((void*)&e);}
''', {"evidence": "two relocated thiscall pushes plus tail"}


def sixpush_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    pushes = [i.operands[0].imm for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    if len(pushes) != 7:
        raise ValueError("sixpush constants missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*,void*,void*,void*,void*);}; extern Obj obj; extern int a,b,c,d,e; extern "C" void tail(void*);
void func(){obj.run((void*)0x%x,(void*)&a,(void*)&b,(void*)&c,(void*)0x%x,(void*)0x%x);tail((void*)&e);}
''' % (pushes[5], pushes[1], pushes[0]), {"evidence": "six relocated thiscall pushes plus tail"}


def sevenpush_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    pushes = [i.operands[0].imm for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    if len(pushes) != 8:
        raise ValueError("sevenpush constants missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*,void*,void*,void*,void*,void*);}; extern Obj obj; extern int a,b,c,d,e,f; extern "C" void tail(void*);
void func(){obj.run((void*)0x%x,(void*)&a,(void*)&b,(void*)&c,(void*)&d,(void*)&e,(void*)0x%x);tail((void*)&f);}
''' % (pushes[6], pushes[0]), {"evidence": "seven relocated thiscall pushes plus tail"}


def load_call_tail_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
extern int g; extern "C" void helper(int);
struct Obj{void m();}; extern Obj obj;
void func(){helper(g); obj.m();}
''', {"evidence": "global load, helper call, then thiscall tail jump"}


def load2_tail_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
extern int a,b; extern "C" void helper(int);
struct Obj{void m();}; extern Obj obj;
void func(){if(a) helper(a); helper(b); obj.m();}
''', {"evidence": "conditional global helper, second helper, then thiscall tail jump"}


def push_store_call_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    pushes = [i.operands[0].imm for i in ins
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    stores = [i.operands[1].imm for i in ins
              if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_MEM
              and i.operands[1].type == capstone.x86.X86_OP_IMM]
    if not pushes or not stores:
        raise ValueError("push-store-call constants missing")
    return '''// roc-flags: /O2 /GS- /EHsc /MD
extern int g; extern "C" void f(void*);
void func(){g=0x%x; f((void*)0x%x);}
''' % (stores[0], pushes[0]), {"evidence": "one pushed pointer, global immediate store, call, pop ecx"}


def enumdesc_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
struct S{int f(int); int sub(int*);}; extern "C" int* sub1(int);
int S::f(int value){int v=*sub1(value+4); return sub(&v);}
''', {"evidence": "callee-cleanup enum getter: one helper, local, thiscall second helper"}


def store_call2_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    pushes = [i.operands[0].imm for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    if len(pushes) < 2:
        raise ValueError("store-call2 constants missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" int helper(const char*,int); extern int g;
void func(){g=helper((const char*)0x%x,%d);}
''' % (pushes[1], pushes[0]), {"evidence": "reversed two-argument helper plus global result store"}


def negthis_call_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    pushes = [i.operands[0].imm for i in ins
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    adds = [i.operands[1].imm for i in ins
            if i.mnemonic == "add" and len(i.operands) == 2
            and i.operands[0].type == capstone.x86.X86_OP_REG
            and i.operands[0].reg == capstone.x86.X86_REG_ECX
            and i.operands[1].type == capstone.x86.X86_OP_IMM]
    if not pushes or not adds:
        raise ValueError("adjusted-this constants missing")
    off = adds[0] if adds[0] < 0x80000000 else adds[0] - 0x100000000
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void sub(void*);}; struct S{void func();};
void S::func(){((B*)((char*)this+%d))->sub((void*)0x%x);}
''' % (off, pushes[0]), {"evidence": "adjusted this pointer then one-argument thiscall"}


def adjusted_arg_return_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    adds = [i.operands[1].imm for i in ins if i.mnemonic == "add" and len(i.operands) == 2
            and i.operands[0].type == capstone.x86.X86_OP_REG
            and i.operands[0].reg == capstone.x86.X86_REG_ECX
            and i.operands[1].type == capstone.x86.X86_OP_IMM]
    if not adds:
        raise ValueError("adjusted-this offset missing")
    off = adds[0] if adds[0] < 0x80000000 else adds[0] - 0x100000000
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void sub(void*);}; struct S{void* func(void*);};
void* S::func(void* p){((B*)((char*)this+%d))->sub(p); return p;}
''' % off, {"evidence": "adjusted-this call with stack argument and identity return"}


def global_int_thiscall_source(client, addr):
    return '''// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Obj{void run(int);}; extern Obj obj;
void func(int arg){obj.run(arg);}
''', {"evidence": "stack int forwarded through global thiscall object"}


def stdcall_fourarg_forward_source(client, addr):
    return '''// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" int __stdcall sub(int,void*,int,int); extern int g;
int __stdcall func(int a,int b,int c){return sub(a,&g,b,c);}
''', {"evidence": "stdcall three-argument forward with global pointer inserted"}


def bool_stdcall_typecheck_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    pushes = [i.operands[0].imm for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    if len(pushes) != 4:
        raise ValueError("typecheck constants missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" int helper(void*,int,void*,void*,int);
bool __stdcall func(void* p){return helper(p,0,(void*)0x%x,(void*)0x%x,0)!=0;}
''' % (pushes[2], pushes[1]), {"evidence": "stdcall bool wrapper normalizes five-argument helper result"}


def lua_double_scale_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
extern double get(void*,int); extern void push(void*,double); extern double g;
int func(void* s){double x=get(s,1); x*=g; push(s,x); return 1;}
''', {"evidence": "Lua-style numeric read, global double scale, numeric push"}


def aligned_alloc_link_source(client, addr):
    return '''// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
extern "C" void* alloc(int);
void* func(){void* p=alloc(0x54); if(p) *(void**)p=p; if((char*)p+4) *(void**)((char*)p+4)=p; return p;}
''', {"evidence": "fixed-size allocation then self-link two-word header"}


def aligned_alloc_link_var_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    vals = [i.operands[0].imm for i in md.disasm(code, int(addr, 16))
            if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    if not vals:
        raise ValueError("allocation size missing")
    return '''// roc-flags: /O2 /GS- /MD
extern "C" void* alloc(int);
void* func(){void* p=alloc(0x%x); if(p) *(void**)p=p; if((char*)p+4) *(void**)((char*)p+4)=p; return p;}
''' % vals[0], {"evidence": "variable-size allocation then self-link header"}


def adjusted_twoarg_return_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    adds = [i.operands[1].imm for i in ins if i.mnemonic == "add" and len(i.operands) == 2
            and i.operands[0].type == capstone.x86.X86_OP_REG
            and i.operands[0].reg == capstone.x86.X86_REG_ECX]
    pushes = [i.operands[0].imm for i in ins if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    if not adds or not pushes:
        raise ValueError("adjusted two-arg constants missing")
    off = adds[0] if adds[0] < 0x80000000 else adds[0] - 0x100000000
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void get(void*,int);}; struct S{void* f(void*);};
void* S::f(void* p){((B*)((char*)this+%d))->get(p,%d); return p;}
''' % (off, pushes[0]), {"evidence": "adjusted-this two-argument helper with identity return"}


def com_out3_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
int __stdcall func(void* self,int* out){if(!out)return 0x80004003; *out=3; return 0;}
''', {"evidence": "stdcall COM-style null output guard and fixed result"}


def vtable_bool_wrapper_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    fields = [i.operands[1].mem.disp for i in ins if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_REG
              and i.operands[0].reg == capstone.x86.X86_REG_ECX
              and i.operands[1].type == capstone.x86.X86_OP_MEM]
    slots = [i.operands[1].mem.disp for i in ins if i.mnemonic == "mov" and len(i.operands) == 2
             and i.operands[0].type == capstone.x86.X86_OP_REG
             and i.operands[0].reg == capstone.x86.X86_REG_EAX
             and i.operands[1].type == capstone.x86.X86_OP_MEM
             and i.operands[1].mem.base == capstone.x86.X86_REG_EAX]
    if not fields or not slots:
        raise ValueError("vtable wrapper offsets missing")
    field = fields[0]; slot = slots[0] // 4
    methods = "; ".join("virtual void v%d();" % i for i in range(slot))
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{%s virtual void m(void*,void*);}; struct S{char pad[0x%x]; B* p; bool f(void*,void*);};
bool S::f(void* a,void* b){p->m(a,b); return true;}
''' % (methods, field), {"evidence": "bool wrapper dispatches nested receiver virtual slot"}


def virtual_bool_negate_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    slots = [i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
             if i.mnemonic == "mov" and len(i.operands) == 2
             and i.operands[0].type == capstone.x86.X86_OP_REG
             and i.operands[0].reg == capstone.x86.X86_REG_EAX
             and i.operands[1].type == capstone.x86.X86_OP_MEM
             and i.operands[1].mem.base == capstone.x86.X86_REG_EAX]
    if not slots:
        raise ValueError("virtual bool slot missing")
    n = slots[0] // 4
    methods = ";".join("virtual void v%d();" % i for i in range(n))
    return '''// roc-flags: /O2 /GS- /MD
struct P{%s virtual bool isVisible(int); bool f(int);};
bool P::f(int value){return !isVisible(value);}
''' % methods, {"evidence": "virtual bool predicate negated to canonical byte result"}


def mixed_cleanup_twocall_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
extern "C" void __stdcall first(void*); extern "C" void second(void*);
struct S{void f(unsigned int);}; void S::f(unsigned int value){first((void*)value); second((void*)value);}
''', {"evidence": "member forwards same argument to stdcall then cdecl helpers"}


def adjusted_zero_call_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    adds = [i.operands[1].imm for i in ins if i.mnemonic == "add" and len(i.operands) == 2
            and i.operands[0].type == capstone.x86.X86_OP_REG
            and i.operands[0].reg == capstone.x86.X86_REG_ECX
            and i.operands[1].type == capstone.x86.X86_OP_IMM]
    if not adds:
        raise ValueError("adjusted zero offset missing")
    off = adds[0] if adds[0] < 0x80000000 else adds[0] - 0x100000000
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void f(int);}; struct S{void g();};
void S::g(){char x=0; ((B*)((char*)this+%d))->f(*(int*)&x);}
''' % off, {"evidence": "adjusted-this helper receives zero stack local"}


def nested_twoarg_dropfirst_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    fields = [i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_REG
              and i.operands[0].reg == capstone.x86.X86_REG_ECX
              and i.operands[1].type == capstone.x86.X86_OP_MEM]
    if not fields:
        raise ValueError("nested field offset missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct I{void method(int,int);}; struct O{char pad[0x%x]; I* p; void f(int,int,int);};
void O::f(int a,int b,int c){p->method(b,c);}
''' % fields[0], {"evidence": "nested receiver forwards trailing two arguments"}


def factory_offset_deref_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    adds = [i.operands[1].imm for i in md.disasm(code, int(addr, 16))
            if i.mnemonic == "add" and len(i.operands) == 2
            and i.operands[0].type == capstone.x86.X86_OP_REG
            and i.operands[0].reg == capstone.x86.X86_REG_ECX
            and i.operands[1].type == capstone.x86.X86_OP_IMM]
    if not adds:
        raise ValueError("factory offset missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct A{int** method();}; extern "C" A* __stdcall create(void*);
struct S{int* func();}; int* S::func(){return *(((A*)((char*)create(this)+0x%x))->method());}
''' % adds[0], {"evidence": "stdcall factory on this, adjusted receiver method, dereference result"}


def global_double_thiscall_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
typedef void (__thiscall *Fn)(void*); extern Fn release; extern int a,b;
void func(){release(&a); release(&b);}
''', {"evidence": "same imported thiscall applied to two globals, second tail call"}


def guarded_mixed_calls_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    fields = [i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_REG
              and i.operands[0].reg == capstone.x86.X86_REG_ESI
              and i.operands[1].type == capstone.x86.X86_OP_MEM]
    if not fields:
        raise ValueError("guarded field offset missing")
    return '''// roc-flags: /O2 /GS- /MD
extern "C" void __stdcall first(int); extern "C" void second(int*);
struct S{char pad[%d]; int* value; void f();}; void S::f(){int* p=value;if(p){first(*p);second(p);}}
''' % fields[0], {"evidence": "nullable field guarded before mixed-cleanup helper calls"}


def nested_onearg_return_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    fields = [i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_REG
              and i.operands[0].reg == capstone.x86.X86_REG_ECX
              and i.operands[1].type == capstone.x86.X86_OP_MEM]
    if not fields:
        raise ValueError("nested onearg field missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void f(void*);}; struct S{char pad[0x%x]; B* p; void* g(void*);};
void* S::g(void* x){p->f(x);return x;}
''' % fields[0], {"evidence": "nested receiver one-argument helper with identity return"}


def nullable_field_return_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    fields = [i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_REG
              and i.operands[0].reg == capstone.x86.X86_REG_EAX
              and i.operands[1].type == capstone.x86.X86_OP_MEM
              and i.operands[1].mem.base == capstone.x86.X86_REG_EAX]
    if not fields:
        raise ValueError("nullable result field missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct A{char pad[0x%x]; void* value;}; extern "C" A* get(void*);
void* func(void* x){A* p=get(x); return p ? p->value : 0;}
''' % fields[0], {"evidence": "nullable helper result returns fixed nested field or zero"}


def lua_pushnumber_float_extra_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
extern "C" void lua_pushnumber(int,double); struct S{int f(float,int);};
int S::f(float value,int unused){lua_pushnumber(*(int*)this,value);return 1;}
''', {"evidence": "Lua number push with float conversion and unused ABI slot"}


def lua_pushnumber_double_extra_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
extern "C" void lua_pushnumber(int,double); struct S{int f(double,int);};
int S::f(double value,int unused){lua_pushnumber(*(int*)this,value);return 1;}
''', {"evidence": "Lua number push with double conversion and unused ABI slot"}


def guarded_release_then_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    fields = [i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_REG
              and i.operands[0].reg == capstone.x86.X86_REG_ESI
              and i.operands[1].type == capstone.x86.X86_OP_MEM]
    if not fields:
        raise ValueError("release field offset missing")
    return '''// roc-flags: /O2 /GS- /EHsc /MD
struct B{void release();}; extern "C" void second(B*);
struct S{char pad[%d]; B* p; void f();}; void S::f(){B* q=p;if(q){q->release();second(q);}}
''' % fields[0], {"evidence": "nullable nested object release followed by cdecl cleanup"}


def nullable_offset_bool_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    fields = [i.operands[0].mem.disp for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "cmp" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_MEM]
    if not fields:
        raise ValueError("nullable bool offset missing")
    return '''// roc-flags: /O2 /GS- /MD
unsigned char __cdecl func(int p){return p!=0&&*(int*)((char*)p+0x%x)!=0;}
''' % fields[0], {"evidence": "cdecl nullable pointer field predicate"}


def nested_onearg_this_return_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    fields = [i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_REG
              and i.operands[0].reg == capstone.x86.X86_REG_ECX
              and i.operands[1].type == capstone.x86.X86_OP_MEM]
    if not fields:
        raise ValueError("nested this-return field missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{void f(void*);}; struct S{char pad[0x%x]; B* p; S* g(void*);};
S* S::g(void* x){p->f(x);return this;}
''' % fields[0], {"evidence": "nested one-argument helper returns original receiver"}


def compare_store_bool_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    stores = [i.operands[0].mem.disp for i in ins if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_MEM
              and i.operands[0].mem.base == capstone.x86.X86_REG_ESI]
    comps = [i.operands[1].mem.disp for i in ins if i.mnemonic == "cmp" and len(i.operands) == 2
             and i.operands[1].type == capstone.x86.X86_OP_MEM]
    flags = [i.operands[0].mem.disp for i in ins if i.mnemonic == "mov" and len(i.operands) == 2
             and i.operands[0].type == capstone.x86.X86_OP_MEM
             and i.operands[0].mem.base == capstone.x86.X86_REG_ESI
             and i.operands[0].mem.disp != (stores[0] if stores else -1)]
    if not stores or not comps:
        raise ValueError("compare-store offsets missing")
    value_off = stores[0]; flag_off = flags[0] if flags else 0x2c; cmp_off = comps[0]
    return '''// roc-flags: /O2 /GS- /EHsc /MD
struct A{char pad[0x%x]; int val;}; struct S{char pad[0x%x]; bool flag; char pad2[3]; int value; A* get(); void f(int);};
void S::f(int v){value=v; A* p=get(); flag=v!=p->val;}
''' % (cmp_off, flag_off), {"evidence": "stores argument, compares helper field, writes byte predicate"}


def float_sum_double_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
struct S{float f1(); float f2(); double f();}; double S::f(){float a=f1(); return a+f2();}
''', {"evidence": "two float member calls summed with double return ABI"}


def stdcall_probe_vtable_tail_source(client, addr):
    return '''// roc-flags: /O2 /GS- /MD
extern "C" void* __stdcall get(int); struct B{void* use();};
void* func(){B* p=(B*)get(8); return p?p->use():0;}
''', {"evidence": "stdcall fixed probe followed by nullable thiscall tail"}


def bounded_index_return_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    limits = [i.operands[1].imm for i in ins if i.mnemonic == "cmp" and len(i.operands) == 2
              and i.operands[1].type == capstone.x86.X86_OP_IMM]
    mems = [i.operands[1].mem.disp for i in ins if i.mnemonic == "mov" and len(i.operands) == 2
            and i.operands[1].type == capstone.x86.X86_OP_MEM
            and i.operands[1].mem.index != 0]
    if not limits or not mems:
        raise ValueError("bounded-index constants missing")
    return '''// roc-flags: /O2 /GS- /MD
struct S{void* f(int i);}; void* S::f(int i){if((unsigned)i<=0x%x)return *(void**)((char*)this+i*4+%d); return 0;}
''' % (limits[0], mems[0]), {"evidence": "callee-cleanup bounded indexed field return"}


def global_get_set_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    stores = [i.operands[0].mem.disp for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_MEM
              and i.operands[0].mem.base == capstone.x86.X86_REG_EAX]
    if not stores:
        raise ValueError("global get-set offset missing")
    return '''// roc-flags: /O2 /GS- /MD
struct O{char pad[0x%x]; void* value;}; struct G{O* get();}; extern G* g;
void func(void* p){O* o=g->get();o->value=p;}
''' % stores[0], {"evidence": "global singleton getter then argument field store"}


def guarded_global_call_source(client, addr):
    return '''// roc-flags: /O2 /GS- /EHsc /MD
extern unsigned count; extern void* ptr; extern "C" void call(void*);
void func(){if(count>0)call(ptr);}
''', {"evidence": "unsigned global count guard and pointer call"}


def nullable_nested_deref_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    fields = [i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
              if i.mnemonic == "mov" and len(i.operands) == 2
              and i.operands[0].type == capstone.x86.X86_OP_REG
              and i.operands[0].reg == capstone.x86.X86_REG_ECX
              and i.operands[1].type == capstone.x86.X86_OP_MEM]
    if not fields:
        raise ValueError("nested nullable field missing")
    return '''// roc-flags: /O2 /GS- /MD
struct A{void* value; A* get();}; struct S{char pad[0x%x]; A* p; void* f();};
void* S::f(){A* q=p; return q?q->get()->value:0;}
''' % fields[0], {"evidence": "nullable nested getter then first-field dereference"}


def virtual_adjust_tail_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    slots = [i.operands[1].mem.disp for i in ins if i.mnemonic == "mov" and len(i.operands) == 2
             and i.operands[0].type == capstone.x86.X86_OP_REG
             and i.operands[0].reg == capstone.x86.X86_REG_EAX
             and i.operands[1].type == capstone.x86.X86_OP_MEM
             and i.operands[1].mem.base == capstone.x86.X86_REG_EAX]
    adds = [i.operands[1].imm for i in ins if i.mnemonic == "add" and len(i.operands) == 2
            and i.operands[0].type == capstone.x86.X86_OP_REG
            and i.operands[1].type == capstone.x86.X86_OP_IMM]
    if not slots or not adds:
        raise ValueError("virtual adjusted tail constants missing")
    methods = ";".join("virtual void v%d();" % i for i in range(slots[0] // 4))
    return '''// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF- /GS- /EHsc /MT
struct S{%s virtual void m(void*); void f(void*);};
void S::f(void* p){m((char*)p+%d);}
''' % (methods, adds[0]), {"evidence": "virtual tail dispatch with adjusted stack argument"}


def import_tail_source(client, addr):
    import re
    row = next(r for r in load_rows(client) if r["addr"] == addr)
    names = row.get("imports") or []
    if not names:
        raise ValueError("import missing")
    name = names[0].rsplit("!", 1)[-1]
    if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", name):
        raise ValueError("import name not plain C identifier")
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void %s();
void func_%s(){%s();}
''' % (name, addr, name)
    return text, {"import": name}


def import_jump_source(client, addr):
    import re
    row = next(r for r in load_rows(client) if r["addr"] == addr)
    names = row.get("imports") or []
    if not names:
        raise ValueError("import missing")
    name = names[0].rsplit("!", 1)[-1]
    if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", name):
        raise ValueError("import name not plain C identifier")
    return ("// roc-flags: /O2 /GS- /MD\n"
            "extern \"C\" __declspec(dllimport) void %s();\n"
            "extern \"C\" void func_%s(){%s();}\n" % (name, addr, name), {"import": name})


def float_field_setter_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    off = next((i.operands[0].mem.disp for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "movss" and i.operands[0].type == capstone.x86.X86_OP_MEM), None)
    if off is None:
        raise ValueError("float setter offset missing")
    text = '''// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2
struct S{char pad[0x%x]; void f(float v);};
void S::f(float v){*(float*)((char*)this+0x%x)=v;}
''' % (off, off)
    return text, {"offset": off}


def cmp_field_bool_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    cmpi = next((i for i in ins if i.mnemonic == "cmp" and i.operands[0].type == capstone.x86.X86_OP_MEM), None)
    if cmpi is None or cmpi.operands[1].type != capstone.x86.X86_OP_IMM:
        raise ValueError("cmp bool fields missing")
    off, value = cmpi.operands[0].mem.disp, cmpi.operands[1].imm
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x%x]; bool f();};
bool S::f(){return *(int*)((char*)this+0x%x)==%d;}
''' % (off, off, value)
    return text, {"offset": off, "value": value}


def x87_float_product_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    offs = [i.operands[0].mem.disp for i in md.disasm(code, int(addr, 16))
            if i.mnemonic in ("fld", "fmul") and i.operands[0].type == capstone.x86.X86_OP_MEM]
    if len(offs) < 3:
        raise ValueError("float product fields missing")
    offs = offs[:3]
    first = min(offs)
    names = {off: "f%d" % n for n, off in enumerate(offs)}
    fields = ["char pad[0x%x];" % first]
    prev = first
    for off in sorted(offs):
        if off != prev:
            fields.append("char gap_%x[0x%x];" % (off, off - prev))
        fields.append("float %s;" % names[off])
        prev = off + 4
    expr = "*".join(names[o] for o in offs)
    text = "// roc-flags: /O2 /GS- /EHsc /MD\nstruct S{%s double f();};\ndouble S::f(){return %s;}\n" % ("".join(fields), expr)
    return text, {"offsets": offs}


def fldz_stdcall_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ret = next((i.operands[0].imm for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "ret" and i.operands), None)
    if ret is None or ret % 4:
        raise ValueError("fldz ret missing")
    args = ",".join("int a%d" % i for i in range(ret // 4))
    text = "// roc-flags: /O2 /GS- /EHsc /MD\ndouble __stdcall f(%s){return 0.0;}\n" % args
    return text, {"ret": ret}


def fld1_source(client, addr):
    return "// roc-flags: /O2 /GS- /EHsc /MD\ndouble f(){return 1.0;}\n", {"value": 1}


def thiscall_reg_tail_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    offs = {}
    for i in md.disasm(code, int(addr, 16)):
        if i.mnemonic != "mov" or len(i.operands) != 2 or i.operands[1].type != capstone.x86.X86_OP_MEM:
            continue
        if i.operands[0].reg in (capstone.x86.X86_REG_ECX, capstone.x86.X86_REG_EAX):
            offs[i.operands[0].reg] = i.operands[1].mem.disp
    if capstone.x86.X86_REG_ECX not in offs or capstone.x86.X86_REG_EAX not in offs:
        raise ValueError("tail fields missing")
    fn, ctx = offs[capstone.x86.X86_REG_EAX], offs[capstone.x86.X86_REG_ECX]
    gap = ctx - fn - 4
    extra = "char gap[0x%x];" % gap if gap else ""
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x%x]; void* fn;%s void* ctx; void f();};
void S::f(){typedef void(__thiscall* Fn)(void*);((Fn)fn)(ctx);}
''' % (fn, extra)
    return text, {"fn": fn, "ctx": ctx}


def import_this_string_source(client, addr):
    code, _relocs, row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    add = next((i.operands[1].imm for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "add" and i.operands[0].reg == capstone.x86.X86_REG_ECX), None)
    value = next((s for s in row.get("strings", []) if s != "8csm"), None)
    if add is None or value is None:
        raise ValueError("import string fields missing")
    literal = value.replace("\\", "\\\\").replace('"', '\\"')
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct S{void f();}; typedef void(__thiscall* Fn)(void*,const char*); extern Fn assign;
void S::f(){assign((char*)this+%d,"%s");}
''' % (add, literal)
    return text, {"add": add, "string": value}


def nested_this_offset_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    load = next((i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
                 if i.mnemonic == "mov" and i.operands[0].reg == capstone.x86.X86_REG_ECX
                 and i.operands[1].type == capstone.x86.X86_OP_MEM), None)
    add = next((i.operands[1].imm for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "add" and i.operands[0].reg == capstone.x86.X86_REG_ECX), None)
    if load is None or add is None:
        raise ValueError("nested this offsets missing")
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct T{void m(int);}; struct S{char pad[0x%x]; void* p; void f();};
void S::f(){((T*)((char*)p+0x%x))->m(0);}
''' % (load, add)
    return text, {"load": load, "add": add}


def virtual_forward_unused_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    slot = next((i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
                 if i.mnemonic == "mov" and i.operands[0].reg == capstone.x86.X86_REG_EDX
                 and i.operands[1].type == capstone.x86.X86_OP_MEM), None)
    ret = next((i.operands[0].imm for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "ret" and i.operands), 0)
    if slot is None or ret % 4:
        raise ValueError("virtual forward fields missing")
    methods = ";".join("virtual void v%d();" % i for i in range(slot // 4))
    args = ",".join("int a%d" % i for i in range(ret // 4))
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct S{%s virtual void m(); void f(%s);};
void S::f(%s){m();}
''' % (methods, args, args)
    return text, {"slot": slot, "ret": ret}


def nested_pointer_import_tail_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    loads = []
    for i in md.disasm(code, int(addr, 16)):
        if i.mnemonic == "mov" and i.operands[0].type == capstone.x86.X86_OP_REG and i.operands[1].type == capstone.x86.X86_OP_MEM:
            loads.append((i.operands[0].reg, i.operands[1].mem.base, i.operands[1].mem.disp))
    first = next((d for reg, base, d in loads if reg == capstone.x86.X86_REG_EAX and base == capstone.x86.X86_REG_ECX), None)
    second = next((d for reg, base, d in loads if reg == capstone.x86.X86_REG_ECX and base == capstone.x86.X86_REG_EAX), None)
    if first is None or second is None:
        raise ValueError("nested import loads missing")
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x%x]; void* vp; int f() const;};
typedef int(__thiscall* Fn)(void*); extern Fn fn;
int S::f()const{return fn(*(void**)((char*)vp+0x%x));}
''' % (first, second)
    return text, {"outer": first, "inner": second}


def adjusted_this_twoarg_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    add = next((i.operands[1].imm for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "add" and i.operands[0].reg == capstone.x86.X86_REG_ECX), None)
    ret = next((i.operands[0].imm for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "ret" and i.operands), None)
    if add is None or ret != 12:
        raise ValueError("adjusted twoarg fields missing")
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct T{void m(void*,void*);};
void __stdcall f(T* p,void* b,void* a){((T*)((char*)p%+d))->m(b,a);}
''' % add
    return text, {"add": add, "ret": ret}


def sum_indirect_thiscall_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    offs = {}
    for i in md.disasm(code, int(addr, 16)):
        if i.mnemonic == "mov" and i.operands[0].type == capstone.x86.X86_OP_REG and i.operands[1].type == capstone.x86.X86_OP_MEM:
            if i.operands[0].reg == capstone.x86.X86_REG_EAX:
                offs.setdefault("fn", i.operands[1].mem.disp)
            elif i.operands[0].reg == capstone.x86.X86_REG_ECX:
                offs.setdefault("a", i.operands[1].mem.disp)
        elif i.mnemonic == "add" and i.operands[0].reg == capstone.x86.X86_REG_ECX and i.operands[1].type == capstone.x86.X86_OP_MEM:
            offs["b"] = i.operands[1].mem.disp
    if set(offs) != {"fn", "a", "b"}:
        raise ValueError("sum indirect fields missing")
    field_parts = ["char pad[0x%x];" % offs["fn"], "void* fn;"]
    prev = offs["fn"] + 4
    for name, off in sorted((("a", offs["a"]), ("b", offs["b"])), key=lambda x: x[1]):
        if off > prev:
            field_parts.append("char gap_%s[0x%x];" % (name, off - prev))
        field_parts.append("int %s;" % name)
        prev = off + 4
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct S{%s void f(int x);};
void S::f(int x){typedef void(__thiscall* Fn)(void*);((Fn)fn)((void*)(a+b));}
''' % "".join(field_parts)
    return text, offs


def byte_field_setter_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    src = next((i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "mov" and i.operands[0].reg == capstone.x86.X86_REG_AL
                and i.operands[1].type == capstone.x86.X86_OP_MEM), None)
    dst = next((i.operands[0].mem.disp for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "mov" and i.operands[0].type == capstone.x86.X86_OP_MEM
                and i.operands[1].reg == capstone.x86.X86_REG_AL), None)
    ret = next((i.operands[0].imm for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "ret" and i.operands), None)
    if src is None or dst is None or ret is None:
        raise ValueError("byte setter fields missing")
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct S{char pad[0x%x]; void f(char v);};
void S::f(char v){*(char*)((char*)this+0x%x)=v;}
''' % (dst, dst)
    return text, {"src": src, "dst": dst, "ret": ret}


def nested_vtable_tail_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    off = next((i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "mov" and i.operands[0].reg == capstone.x86.X86_REG_ECX
                and i.operands[1].type == capstone.x86.X86_OP_MEM), None)
    if off is None:
        raise ValueError("nested vtable offset missing")
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct I{virtual void f();}; struct S{char pad[0x%x]; I* p; void g();};
void S::g(){p->f();}
''' % off
    return text, {"offset": off}


def vcall_signed_short_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    slot = next((i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
                 if i.mnemonic == "mov" and i.operands[0].reg == capstone.x86.X86_REG_EDX
                 and i.operands[1].type == capstone.x86.X86_OP_MEM), None)
    field = next((i.operands[1].mem.disp for i in md.disasm(code, int(addr, 16))
                  if i.mnemonic == "movsx" and i.operands[0].reg == capstone.x86.X86_REG_EAX), None)
    if slot is None or field is None or field < 4:
        raise ValueError("vcall short fields missing")
    methods = ";".join("virtual void v%d();" % i for i in range(slot // 4))
    text = '''// roc-flags: /O2 /GS- /EHsc /MD
struct S{%s virtual void m(); char pad[0x%x]; short value; int f();};
int S::f(){m(); return (short)value;}
''' % (methods, field - 4)
    return text, {"slot": slot, "field": field}


def indirect_init_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    pushes = [i.operands[0].imm for i in ins
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    movs = [i.operands[1].imm for i in ins
            if i.mnemonic == "mov" and len(i.operands) == 2
            and i.operands[0].type == capstone.x86.X86_OP_REG
            and i.operands[0].reg == capstone.x86.X86_REG_ECX
            and i.operands[1].type == capstone.x86.X86_OP_IMM]
    if len(pushes) < 2 or not movs:
        raise ValueError("indirect-init constants missing")
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
typedef void (__thiscall *Ctor)(void*,const char*); extern Ctor ctor; extern "C" void final(void*);
void func(){ctor((void*)0x%x,(const char*)0x%x);final((void*)0x%x);}
''' % (movs[0], pushes[0], pushes[1]), {"evidence": "indirect thiscall initializer plus final call"}


def twoarg_this_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    pushes = [i.operands[0].imm for i in ins
              if i.mnemonic == "push" and i.operands[0].type == capstone.x86.X86_OP_IMM]
    movs = [i.operands[1].imm for i in ins
            if i.mnemonic == "mov" and len(i.operands) == 2
            and i.operands[0].type == capstone.x86.X86_OP_REG
            and i.operands[0].reg == capstone.x86.X86_REG_ECX
            and i.operands[1].type == capstone.x86.X86_OP_IMM]
    if len(pushes) < 2 or not movs:
        raise ValueError("twoarg-this constants missing")
    return '''// roc-flags: /O2 /GS- /MD
struct Obj{void m(int,int);};
void func(){((Obj*)0x%x)->m(%d,%d);}
''' % (movs[0], pushes[1], pushes[0]), {"evidence": "two immediate args and fixed thiscall receiver"}


def vtable_tail_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    field = next((i.operands[1].mem.disp for i in ins if i.mnemonic == "mov"
                  and len(i.operands) == 2 and i.operands[0].type == capstone.x86.X86_OP_REG
                  and i.operands[0].reg == capstone.x86.X86_REG_ECX
                  and i.operands[1].type == capstone.x86.X86_OP_MEM), None)
    slot = next((i.operands[1].mem.disp for i in ins if i.mnemonic == "mov"
                 and len(i.operands) == 2 and i.operands[0].type == capstone.x86.X86_OP_REG
                 and i.operands[0].reg == capstone.x86.X86_REG_EDX
                 and i.operands[1].type == capstone.x86.X86_OP_MEM), None)
    if field is None or slot is None or slot % 4:
        raise ValueError("vtable-tail offsets missing")
    methods = "".join("virtual void v%d();" % i for i in range(slot // 4 + 1))
    return '''// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct B{%s}; struct S{char pad[0x%x]; B* p; void f();};
void S::f(){p->v%d();}
''' % (methods, field, slot // 4), {"evidence": "nested receiver and vtable tail jump"}


def ogre_dispatch_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ins = list(md.disasm(code, int(addr, 16)))
    slot = next((i.operands[1].mem.disp for i in ins if i.mnemonic == "mov"
                 and len(i.operands) == 2 and i.operands[0].reg == capstone.x86.X86_REG_EAX
                 and i.operands[1].type == capstone.x86.X86_OP_MEM
                 and i.operands[1].mem.base == capstone.x86.X86_REG_EAX), None)
    if slot is None or slot % 4:
        raise ValueError("ogre vtable slot missing")
    return '''// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF- /GS- /EHsc /MT
typedef void (__thiscall *F)(void*,int,void*);
extern void* g;
struct V{void** v; void f(int);};
void V::f(int a){((F)v[%d])(this,a,g);}
''' % (slot // 4), {"evidence": "Ogre scene-manager vtable dispatch slot"}


def global_member_frame_source(client, addr):
    return '''// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("g", off)
struct T{void m();}; extern T G; void f(){G.m();}
''', {"evidence": "global member call with preserved MSVC frame"}


def nested_member_frame_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    off = next((i.operands[1].imm for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "add" and len(i.operands) == 2
                and i.operands[0].reg == capstone.x86.X86_REG_ECX
                and i.operands[1].type == capstone.x86.X86_OP_IMM), None)
    if off is None:
        raise ValueError("nested member offset missing")
    return '''// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("g", off)
struct B{void f();}; struct S{char pad[0x%x]; B b; void g();};
void S::g(){b.f();}
''' % off, {"evidence": "nested member call with preserved MSVC frame"}


def two_call_frame_source(client, addr):
    return '''// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#pragma optimize("g", off)
struct T{void m();}; extern T G; extern "C" void tail(void*);
void f(){G.m(); tail((void*)0x7fc640);}
''', {"evidence": "two calls with preserved frame and caller cleanup"}


def weak_accessor_frame_source(client, addr):
    code, _relocs, _row = match.target(client, addr)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    off = next((i.operands[1].imm for i in md.disasm(code, int(addr, 16))
                if i.mnemonic == "add" and len(i.operands) == 2
                and i.operands[0].reg == capstone.x86.X86_REG_EAX
                and i.operands[1].type == capstone.x86.X86_OP_IMM), None)
    if off is None or off <= 0:
        raise ValueError("weak accessor offset missing")
    return '''// roc-flags: /O2 /GS- /MD
#pragma optimize("g", off)
struct VChunk{char pad[0x%x];}; char* f(VChunk* p){return p->pad+0x%x;}
''' % (off, off), {"evidence": "weak-reference accessor offset and preserved frame"}


def byvalue_string_base_source(client, addr):
    _code, _relocs, row = match.target(client, addr)
    strings = row.get("strings") or []
    values = [s for s in strings if s and not s.lower().startswith("d$")]
    value = values[1] if len(values) > 1 else (values[0] if values else None)
    if not value:
        raise ValueError("constructor string missing")
    import json as _json
    return '''// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B(%s,p){}
''' % _json.dumps(value), {"evidence": "by-value std::string base constructor and target literal"}


TEMPLATE_FAMILIES = {
    "hotpatch_thunk": ("2009-06", "0081b245", HOTPATCH_THUNK_SRC),
    "audited_mi_registration": ("2010-06", "009c97d0", audited_mi_registration_source),
    "audited_mi_registration_294": ("2010-06", "009cebd0", audited_mi_registration_source),
    "shape122_mi_pmf": ("2007-03", "00770260", shape122_mi_source),
    "audited_descriptor": ("2010-06", "0040a710", audited_descriptor_source),
    "audited_sret_init": ("2008-06", "007ee760", audited_sret_init_source),
    "receiver_arg": ("2010-06", "009da850", RECEIVER_ARG_SRC),
    "reg9_mi": ("2010-06", "009c6290", REG9_MI_SRC),
    "dynamic_cast_chain": ("2007-03", "004627a0", dynamic_cast_source),
    "import_store": ("2010-06", "009cf1e0", IMPORT_STORE_SRC),
    "ctor_fields": ("2007-03", "004106f0", ctor_field_source),
    "creator_tail": ("2009-06", "0040aa30", creator_tail_source),
    "creator_tail_5writes": ("2009-06", "00625260", creator_tail_source),
    "seh_descriptor": ("2010-06", "0040a710", seh_descriptor_source),
    "seh_pointer": ("2007-03", "00555400", SEH_POINTER_SRC),
    "str_copy": ("2007-03", "0040e2a0", str_copy_source),
    "two_call_wrapper": ("2009-06", "00884cb0", WRAPPER_SRC),
    "lockfree_pop": ("2011-06", "00a30290", LOCKFREE_SRC),
    "global_init": ("2011-06", "00a302f0", GLOBAL_INIT_SRC),
    "type_factory": ("2009-06", "0041b130", FACTORY_SRC),
    "static_reg": ("2009-06", "0042a030", STATIC_REG_SRC),
    "three_call_init": ("2010-06", "009c4110", THREE_CALL_SRC),
    "reg_wrapper": ("2010-06", "009c2dc0", reg_wrapper_source),
    "reg_wrapper4": ("2011-06", "00a17f10", reg_wrapper_source),
    "ctor_atexit": ("2010-06", "00409680", CTOR_ATEXIT_SRC),
    "nested_type_callback": ("2007-03", "00556eb0", nested_type_callback_source),
    "creator_out_ctor": ("2011-06", "00592cc0", creator_out_ctor_source),
    "selection_tree_branch": ("2009-06", "00422600", selection_tree_branch_source),
    "field_ctor": ("2007-03", "00414830", field_ctor_source),
    "factory_guard": ("2011-06", "0040e930", factory_guard_source),
    "audited_global_store_call": ("2007-03", "00772400", audited_global_store_call_source),
    "audited_string_copy": ("2007-03", "0040e2a0", audited_string_copy_source),
    "audited_cursor_string": ("2007-03", "00556e70", audited_cursor_string_source),
    "mi_bound_descriptor": ("2007-03", "0076db20", mi_bound_desc_source),
    "mi_bound_descriptor_2007_08": ("2007-08", "0076c8b0", mi_bound_desc_source),
    "mi_bound_descriptor_2008_06": ("2008-06", "007f0fa0", mi_bound_desc_source),
    "mi_bound_descriptor_2009_06": ("2009-06", "00886f50", mi_bound_desc_source),
    "mi_bound_descriptor_2010_06": ("2010-06", "009c6200", mi_bound_desc_source),
    "mi_bound_descriptor_2011_06": ("2011-06", "00a17720", mi_bound_desc_source),
    "mi_two_pmf_193": ("2007-03", "0076e220", mi_two_pmf_source),
    "mi_two_pmf_193_2007_08": ("2007-08", "0076d040", mi_two_pmf_source),
    "mi_two_pmf_193_2008_06": ("2008-06", "007ef430", mi_two_pmf_source),
    "mi_two_pmf_193_2009_06": ("2009-06", "00886fb0", mi_two_pmf_source),
    "mi_one_pmf_149": ("2007-03", "0076dbe0", mi_one_pmf_source),
    "mi_one_pmf_149_2007_08": ("2007-08", "0076c940", mi_one_pmf_source),
    "mi_one_pmf_149_2008_06": ("2008-06", "007f0f70", mi_one_pmf_source),
    "mi_one_pmf_149_2009_06": ("2009-06", "00886f20", mi_one_pmf_source),
    "mi_one_pmf_149_2010_06": ("2010-06", "009c61d0", mi_one_pmf_source),
    "mi_one_pmf_149_2011_06": ("2011-06", "00a175c0", mi_one_pmf_source),
    "shape154_creator": ("2007-03", "0076d830", shape154_source),
    "simple_wrapper": ("2007-08", "0076ca10", simple_wrapper_source),
    "callpush_wrapper": ("2007-03", "00770a20", callpush_source),
    "getset_global": ("2007-03", "00777a60", getset_source),
    "fourpush_wrapper": ("2007-03", "0076e0e0", fourpush_source),
    "threepush_wrapper": ("2009-06", "00887180", threepush_source),
    "twopush_wrapper": ("2008-06", "007f85e0", twopush_source),
    "sixpush_wrapper": ("2010-06", "009c6490", sixpush_source),
    "sevenpush_wrapper": ("2010-06", "009c76d0", sevenpush_source),
    "load_call_tail": ("2011-06", "00a39950", load_call_tail_source),
    "load2_tail": ("2012-06", "00b1fb60", load2_tail_source),
    "push_store_call": ("2009-06", "008841d0", push_store_call_source),
    "enumdesc": ("2012-06", "00468a60", enumdesc_source),
    "store_call2": ("2007-03", "0076e840", store_call2_source),
    "negthis_call": ("2009-06", "00660490", negthis_call_source),
    "indirect_init": ("2008-06", "007f8fb0", indirect_init_source),
    "twoarg_this": ("2011-06", "00a17570", twoarg_this_source),
    "vtable_tail": ("2007-03", "005af310", vtable_tail_source),
    "adjusted_arg_return": ("2007-03", "00458470", adjusted_arg_return_source),
    "global_int_thiscall": ("2007-03", "0046dc60", global_int_thiscall_source),
    "stdcall_fourarg_forward": ("2007-03", "00402c30", stdcall_fourarg_forward_source),
    "bool_stdcall_typecheck": ("2007-03", "004153e0", bool_stdcall_typecheck_source),
    "lua_double_scale": ("2007-03", "005c4580", lua_double_scale_source),
    "aligned_alloc_link": ("2012-06", "00708c60", aligned_alloc_link_source),
    "aligned_alloc_link_var": ("2012-06", "008b80e0", aligned_alloc_link_var_source),
    "adjusted_twoarg_return": ("2011-06", "006474a0", adjusted_twoarg_return_source),
    "com_out3": ("2011-06", "00459c70", com_out3_source),
    "vtable_bool_wrapper": ("2008-06", "0056e0e0", vtable_bool_wrapper_source),
    "virtual_bool_negate": ("2011-06", "00645c90", virtual_bool_negate_source),
    "mixed_cleanup_twocall": ("2012-06", "00963600", mixed_cleanup_twocall_source),
    "adjusted_zero_call": ("2007-03", "0057c9c0", adjusted_zero_call_source),
    "nested_twoarg_dropfirst": ("2007-03", "006669a0", nested_twoarg_dropfirst_source),
    "factory_offset_deref": ("2009-06", "00642600", factory_offset_deref_source),
    "global_double_thiscall": ("2012-06", "00b12830", global_double_thiscall_source),
    "guarded_mixed_calls": ("2010-06", "0042bb60", guarded_mixed_calls_source),
    "nested_onearg_return": ("2010-06", "0053c640", nested_onearg_return_source),
    "nullable_field_return": ("2008-06", "0049ac80", nullable_field_return_source),
    "lua_pushnumber_float_extra": ("2012-06", "0084c1a0", lua_pushnumber_float_extra_source),
    "lua_pushnumber_double_extra": ("2012-06", "0084c1c0", lua_pushnumber_double_extra_source),
    "guarded_release_then": ("2008-06", "0056bd40", guarded_release_then_source),
    "nullable_offset_bool": ("2011-06", "007a1950", nullable_offset_bool_source),
    "nested_onearg_this_return": ("2010-06", "0071cfb0", nested_onearg_this_return_source),
    "compare_store_bool": ("2012-06", "006355a0", compare_store_bool_source),
    "float_sum_double": ("2008-06", "00575040", float_sum_double_source),
    "stdcall_probe_vtable_tail": ("2007-03", "00680a30", stdcall_probe_vtable_tail_source),
    "bounded_index_return": ("2007-03", "006f5770", bounded_index_return_source),
    "global_get_set": ("2007-03", "006631d0", global_get_set_source),
    "guarded_global_call": ("2009-06", "008963a0", guarded_global_call_source),
    "nullable_nested_deref": ("2007-03", "00705c20", nullable_nested_deref_source),
    "virtual_adjust_tail": ("2008-06", "0068ca90", virtual_adjust_tail_source),
    "float_field_setter": ("2012-06", "004ea1e0", float_field_setter_source),
    "cmp_field_bool": ("2011-06", "007ab2c0", cmp_field_bool_source),
    "x87_float_product": ("2010-06", "006776e0", x87_float_product_source),
    "fldz_stdcall": ("2011-06", "00732f40", fldz_stdcall_source),
    "fld1": ("2011-06", "0046af60", fld1_source),
    "thiscall_reg_tail": ("2011-06", "00473cb0", thiscall_reg_tail_source),
    "import_this_string": ("2012-06", "0044fe80", import_this_string_source),
    "nested_this_offset": ("2012-06", "00811880", nested_this_offset_source),
    "virtual_forward_unused": ("2010-06", "00432850", virtual_forward_unused_source),
    "nested_pointer_import_tail": ("2008-06", "0066f910", nested_pointer_import_tail_source),
    "import_jump": ("2008-06", "00405e20", import_jump_source),
    "ogre_dispatch": ("2008-06", "0068b820", ogre_dispatch_source),
    "global_member_frame": ("2008-06", "007fc640", global_member_frame_source),
    "nested_member_frame": ("2008-06", "005404b0", nested_member_frame_source),
    "two_call_frame": ("2008-06", "007f26a0", two_call_frame_source),
    "weak_accessor_frame": ("2008-06", "00541d90", weak_accessor_frame_source),
    "byvalue_string_base": ("2008-06", "00413530", byvalue_string_base_source),
    "adjusted_this_twoarg": ("2010-06", "004194d0", adjusted_this_twoarg_source),
    "sum_indirect_thiscall": ("2011-06", "004925b0", sum_indirect_thiscall_source),
    "byte_field_setter": ("2011-06", "0051f760", byte_field_setter_source),
    "nested_vtable_tail": ("2011-06", "00592270", nested_vtable_tail_source),
    "vcall_signed_short": ("2012-06", "0089fbe0", vcall_signed_short_source),
}


def cmd_templates(args):
    """Propagate the verified template families (two-call wrapper, lock-free pop, global init)."""
    ledger = Ledger(args.out)
    totals = {}
    selected = set(args.families.split(",")) if args.families else None
    for name, (ex_client, ex_addr, generator) in TEMPLATE_FAMILIES.items():
        if selected and name not in selected:
            continue
        ex_row = next(r for r in load_rows(ex_client) if r["addr"] == ex_addr)
        shape = ex_row["shape"]
        total = submitted = 0
        for client in args.clients.split(","):
            if client in EXCLUDE or not (ROOT / "work" / client / "scores.json").exists():
                continue
            scores = load_scores(client)
            for row in load_rows(client):
                if row.get("shape") != shape or (row.get("kind") != "code" and
                                                   not (generator in (import_tail_source, import_jump_source) and
                                                        row.get("kind") == "thunk")):
                    continue
                addr = row["addr"]
                if scores.get(addr) == 100:
                    continue
                if callable(generator):
                    try:
                        text, info = generator(client, addr)
                    except (ValueError, StopIteration):
                        continue
                else:
                    text, info = generator % {"addr": addr}, None
                try:
                    score, _sym, _diff, _sp = match.check_text(client, addr, text)
                except match.CompileError:
                    continue
                if score != 100:
                    continue
                total += 1
                (Path(args.out) / ("%s_%s_%s.cpp" % (name, client, addr))).write_text(text)
                if args.submit and submitted < args.limit:
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
                    payload = {"user": args.user, "worker": "re-pilot", "client": client,
                               "addr": addr, "score": 100, "source": text}
                    if job:
                        payload["lease"] = job["lease"]
                    try:
                        r = api.call("/v1/submit", payload)
                    except worker.ApiFailure as error:
                        r = {"error": str(error)}
                    submitted += 1
                    ledger.record("attempts.jsonl", dict(
                        ts=time.time(), worker="re-pilot", client=client, addr=addr,
                        baseline=int(prior.get("score", 0) or 0), candidate=100,
                        status="exact" if r.get("verified") else "no-gain",
                        source_sha=hashlib.sha1(text.encode()).hexdigest(),
                        hypothesis="template family %s" % name,
                        evidence=["verified exemplar %s %s" % (ex_client, ex_addr)],
                        edits="generated from template", compile_result="ok", server_result=r,
                        mismatch=[], provenance=[], rejection="", discovery=name,
                        next_action="continue template propagation"))
                    print("   %s %s %s -> %s" % (name, client, addr, r.get("stored", r)))
        print("%s: %d exact candidates, %d submitted" % (name, total, submitted))
        totals[name] = (total, submitted)
    return 0


COMMANDS = {"select": cmd_select, "inspect": cmd_inspect, "status": cmd_status,
            "try": cmd_try, "submit": cmd_submit, "creator": cmd_creator,
            "templates": cmd_templates}


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
    p = sub.add_parser("templates")
    p.add_argument("--clients", default="2009-06,2010-06,2011-06,2012-06,2007-03,2007-08,2008-06")
    p.add_argument("--families", default=None,
                   help="comma-separated template family names; default all")
    p.add_argument("--submit", action="store_true")
    p.add_argument("--limit", type=int, default=1000)
    p.add_argument("--user", default="colin")
    p.add_argument("--server", default=None)
    p.add_argument("--out", default="work/re-pilot-20261010")
    args = ap.parse_args(argv)
    return COMMANDS[args.cmd](args)


if __name__ == "__main__":
    raise SystemExit(main())
