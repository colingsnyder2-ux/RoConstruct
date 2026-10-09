"""Conservative x86-32 live-register pressure estimate for ranking windows."""
import re

REGS = {"eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp"}
OP = re.compile(r"^\s*(\w+)\s+([^,]+)(?:,\s*(.*))?$", re.I)
TARGET = re.compile(r"\b(?:0x[0-9a-f]+|\d+)\b", re.I)


def registers(asm):
    return [set(re.findall(r"\b(eax|ebx|ecx|edx|esi|edi|ebp|esp)\b", line.lower()))
            for line in asm.splitlines()]


def estimate(asm):
    """Return max distinct register names in a short window.

    This is a ranking hint, not liveness proof: aliases, memory effects, and
    control flow are intentionally not guessed.
    """
    rows = registers(asm)
    live = set()
    peaks = []
    for used in reversed(rows):
        live |= used
        peaks.append(len(live))
    return {"instructions": len(rows), "max_registers": max((len(x) for x in rows), default=0),
            "max_live_hint": max(peaks, default=0),
            "distinct_registers": sorted(set().union(*rows) if rows else set())}


def estimate_killed(asm):
    """Backward hint that kills simple destination-register definitions."""
    live, peaks = set(), []
    for line in reversed(asm.splitlines()):
        m = OP.match(line)
        if not m:
            continue
        op, dst, src = m.group(1).lower(), m.group(2).lower(), m.group(3) or ""
        used = set(re.findall(r"\b(eax|ebx|ecx|edx|esi|edi|ebp|esp)\b", src))
        killed = {dst} if op in {"mov", "lea", "pop", "xor"} and dst in REGS else set()
        live = (live - killed) | used
        peaks.append(len(live))
    return max(peaks, default=0)


def blocks(asm):
    """Split linear text at simple terminators; labels/targets remain conservative."""
    out, cur = [], []
    for line in asm.splitlines():
        cur.append(line)
        op = (line.strip().split(None, 1) or [""])[0].lower()
        if op == "ret" or op == "jmp" or op.startswith("j"):
            out.append("\n".join(cur))
            cur = []
    if cur:
        out.append("\n".join(cur))
    return out


def branch_targets(asm):
    """Return numeric targets from simple jump lines; symbolic targets stay unknown."""
    out = []
    for line in asm.splitlines():
        parts = line.strip().split(None, 1)
        if parts and parts[0].lower().startswith("j") and len(parts) == 2:
            m = TARGET.search(parts[1])
            if m:
                out.append(int(m.group(0), 0))
    return out


def block_pressure(asm):
    """Per-block conservative pressure records for ranking/reporting."""
    return [{"index": i, "pressure": estimate_killed(block),
             "instructions": len(block.splitlines())}
            for i, block in enumerate(blocks(asm))]
