"""Small clean-room grouping for repeated machine-code function shapes."""
import re
import hashlib
from collections import defaultdict


_OP = re.compile(r"^\S+\s+\S+\s+([a-z][a-z0-9]*)\b", re.I)


def opcode_shape(asm):
    """Return opcode-only shape; operands/addresses stay target-specific."""
    return tuple(match.group(1).lower() for line in asm or ()
                 for match in [_OP.match(line)] if match)


def family_key(row, asm):
    """Group same-sized functions with the same opcode sequence."""
    return (int(row.get("size", 0) or 0), opcode_shape(asm))


def fingerprint(row, asm):
    """Stable wire-safe family id: size plus ordered opcode shape."""
    size, ops = family_key(row, asm)
    text = "%d:%s" % (size, ",".join(ops))
    return hashlib.sha256(text.encode("ascii")).hexdigest()[:24]


def representatives(rows, disassemble, minimum=2):
    """Return one deterministic representative per repeated family."""
    groups = defaultdict(list)
    for row in rows:
        key = family_key(row, disassemble(row))
        groups[key].append(row)
    out = []
    for key, members in groups.items():
        if len(members) >= minimum:
            out.append((key, sorted(members, key=lambda row: row["addr"])[0], members))
    return sorted(out, key=lambda item: (item[0][0], item[1]["addr"]))
