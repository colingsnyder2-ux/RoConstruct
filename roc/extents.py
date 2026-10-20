"""Function-extent detector: find near-misses whose recorded size includes padding.

A target whose bytes end in a run of `00 00` (decodes as `add byte ptr [eax], al`),
`CC` (int3) or `90` (nop) is padded inside its recorded extent: the function
really ends earlier. Every check against the padded extent shows a phantom
`add byte ptr [eax], al` block that no source change can ever fix (00700df0).
This scan lists those functions so their sizes can be corrected through
work/<client>/bounds.json — evidence, not invention: only report what the bytes
prove.
"""
import json
from pathlib import Path

from roc import match

ROOT = Path(__file__).resolve().parent.parent


def padding_tail(code):
    """(length, byte) of the trailing padding run: 00, CC or 90, at least 4 bytes."""
    if not code:
        return 0, 0
    last = code[-1]
    if last not in (0x00, 0xCC, 0x90):
        return 0, 0
    run = 0
    for byte in reversed(code):
        if byte != last:
            break
        run += 1
    return (run, last) if run >= 4 else (0, 0)


def merged_boundary(code, relocs):
    """Offset of an interior CC/00 wall with code after it: the extent spans two
    functions. The wall must sit at an instruction boundary and decode as whole
    padding instructions — `mov eax, fs:[0]` embeds 00 00 00 00 as an operand and
    must not count. Returns the suggested split offset, or None."""
    boundaries = set()
    md_start = {}
    for line in match.asm_lines(code, relocs):
        parts = line.split("  ", 1)
        if len(parts) == 2 and len(parts[0]) == 8 and all(c in "0123456789abcdef" for c in parts[0]):
            boundaries.add(int(parts[0], 16))
    if not boundaries:
        return None
    base = min(boundaries)
    for wall_byte, min_run in ((0xCC, 3), (0x00, 4)):
        pos = base + 8
        while True:
            hit = code.find(bytes([wall_byte]) * min_run, pos - base)
            if hit < 0 or hit >= len(code) - 16:
                break
            offset = base + hit
            # Every wall byte must start at a decoded instruction boundary.
            if all((offset + i) in boundaries for i in range(min_run)):
                end = offset
                while end - base < len(code) and code[end - base] == wall_byte:
                    end += 1
                # Real code must follow the wall (not just more padding).
                if end + 8 <= base + len(code) and code[end - base] not in (0x00, 0xCC, 0x90):
                    return offset - base
            pos = hit + 1
    return None


def scan(client, min_score=90):
    """Near-misses whose recorded target extent ends in padding, plus diff
    zero-run symptoms: the honest bounds.json candidate list."""
    scores_path = ROOT / "work" / client / "scores.json"
    scores = json.loads(scores_path.read_text()) if scores_path.exists() else {}
    rows = []
    with (ROOT / "work" / client / "functions.jsonl").open(encoding="utf-8") as stream:
        for line in stream:
            row = json.loads(line)
            addr = row["addr"]
            if row.get("kind", "code") != "code" or not min_score <= scores.get(addr, 0) < 100:
                continue
            code, relocs, meta = match.target(client, addr)
            run, byte = padding_tail(code)
            split = None if run else merged_boundary(code, relocs)
            if not run and split is None:
                continue
            rows.append({"addr": addr, "score": scores.get(addr, 0), "size": row.get("size", 0),
                         "padding": run, "pattern": {0: "00 (add [eax],al)", 0xCC: "CC (int3)",
                                                     0x90: "90 (nop)"}[byte] if run else "interior wall",
                         "suggested_size": row.get("size", 0) - run if run else split,
                         "unit": row.get("unit", "")})
    rows.sort(key=lambda r: (-r["score"], -r["padding"]))
    return rows
