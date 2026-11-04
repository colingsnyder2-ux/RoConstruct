"""Phase 4 evidence: field-offset maps from rbxgs (rebuilt) to 2008, per class.
An exact standalone 2008 source with real RBX names names the function at its address. When rbxgs-app's
rebuilt object defines the same symbol but its bytes differ, and both disassemble to the same instruction
sequence apart from memory displacements, each differing [reg+disp] pair is evidence that a field at disp in
rbxgs sits at the 2008 disp. Counts are aggregated per class (taken from the symbol's scope).
Read-only; writes rebuild/2008-06/out/layout-map.json.
usage: python rebuild/2008-06/layout_map.py [LIMIT]"""
import collections
import json
import re
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match  # noqa: E402
from capstone import Cs, CS_ARCH_X86, CS_MODE_32  # noqa: E402
from capstone.x86_const import X86_OP_MEM  # noqa: E402

CLIENT = "2008-06"
OUT = ROOT / "rebuild" / CLIENT / "out"
MD = Cs(CS_ARCH_X86, CS_MODE_32)
MD.detail = True


def key(symbol):
    """method@Class@...@@ without the signature: standalone analogs often mangle parameter types differently."""
    return symbol.split("@@", 1)[0] if symbol.startswith("?") else symbol


def rebuilt_index():
    index, seen = {}, collections.Counter()
    for obj in (OUT / "RbxgsApp").glob("layer-[!v]*/*.obj"):
        for name, body, relocs in match.coff_functions(obj.read_bytes()):
            if name not in index:
                index[name] = (body, relocs)
                seen[key(name)] += 1
    # unique by name+scope only (an overload set cannot be paired without the signature)
    return {key(n): v for n, v in index.items() if seen[key(n)] == 1}


def scope(symbol):
    """Class of a member function symbol: ?method@Class@RBX@@... -> Class."""
    m = re.match(r"\?\??[^@]*@([A-Za-z_]\w*)@", symbol)
    return m.group(1) if m else None


def shape(code):
    out = []
    for insn in MD.disasm(code, 0):
        mems = [(op.mem.base, op.mem.index, op.mem.disp) for op in insn.operands if op.type == X86_OP_MEM]
        out.append((insn.mnemonic, len(insn.operands), mems))
    return out


def displacement_pairs(target, cand):
    a, b = shape(target), shape(cand)
    if len(a) != len(b) or any(x[0] != y[0] or x[1] != y[1] or len(x[2]) != len(y[2]) for x, y in zip(a, b)):
        return None
    pairs = []
    for x, y in zip(a, b):
        for (tb, ti, td), (cb, ci, cd) in zip(x[2], y[2]):
            if td != cd and ti == ci == 0 and tb and cb and 0 <= td < 0x4000 and 0 <= cd < 0x4000:
                if MD.reg_name(tb) in ("esp", "ebp") or MD.reg_name(cb) in ("esp", "ebp"):
                    continue  # stack frames shift with locals, not fields
                pairs.append((cd, td))
    return pairs


def name_at(addr):
    path = ROOT / "src" / CLIENT / (addr + ".cpp")
    text = path.read_text(errors="replace")
    if "// roc-lib:" in text or "RBX" not in text:
        return addr, None
    try:
        value, symbol, _, _ = match.check_text(CLIENT, addr, text)
    except Exception:  # noqa: BLE001 - an uncompilable stored source names nothing
        return addr, None
    return addr, symbol if value == 100 else None


def main(limit=None):
    scores = json.loads((ROOT / "work" / CLIENT / "scores.json").read_text())
    addrs = sorted(a for a, v in scores.items() if (v if isinstance(v, int) else v.get("score", 0)) == 100
                   and (ROOT / "src" / CLIENT / (a + ".cpp")).exists())[:limit]
    index = rebuilt_index()
    classes = collections.defaultdict(collections.Counter)
    paired = differing = aligned = 0
    with ThreadPoolExecutor(8) as pool:
        for addr, symbol in pool.map(name_at, addrs):
            if not symbol or key(symbol) not in index:
                continue
            paired += 1
            code, relocs, _ = match.target(CLIENT, addr)
            body, crelocs = index[key(symbol)]
            if match.exact_match(code, relocs, body, crelocs):
                continue
            differing += 1
            pairs = displacement_pairs(code, body)
            if pairs is None:
                continue
            aligned += 1
            for rb, t in pairs:
                classes[scope(symbol) or "?"][(rb, t)] += 1
    rows = {cls: sorted(([hex(r), hex(t), n] for (r, t), n in c.items()), key=lambda x: int(x[0], 16))
            for cls, c in sorted(classes.items())}
    (OUT / "layout-map.json").write_text(json.dumps({"paired": paired, "differing": differing,
                                                     "aligned": aligned, "classes": rows}, indent=1))
    print("paired %d rebuilt symbols with exact 2008 names; %d differ; %d align by displacement; %d classes"
          % (paired, differing, aligned, len(rows)))


if __name__ == "__main__":
    main(int(sys.argv[1]) if len(sys.argv) > 1 else None)
