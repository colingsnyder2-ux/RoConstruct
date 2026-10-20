"""Join basic blocks misidentified as independent functions, using control flow."""
from bisect import bisect_left
import re

from capstone import CS_ARCH_X86, CS_MODE_32, Cs


def current_scores(before, after, scores):
    """Old byte scores cannot certify a resized target; source files stay intact."""
    old_sizes = {row["addr"]: row["size"] for row in before}
    new_sizes = {row["addr"]: row["size"] for row in after}
    return {addr: score for addr, score in scores.items()
            if addr in new_sizes and old_sizes.get(addr) == new_sizes[addr]}


def seh_entries(code, base, read):
    """MSVC cookie-check/CxxFrameHandler stubs adjacent to unpadded guard resets.

    Stripped older clients lack PE relocations that normally seed these entries.
    Validate the FuncInfo argument, not just an opcode-shaped byte sequence.
    """
    pattern = rb"\x8b\x54\x24\x08(?:\x8d\x02|\x8d\x42.|\x8d\x82....)\x8b\x4a\xfc\x33\xc8\xe8....\xb8(....)\xe9...."
    entries = set()
    for hit in re.finditer(pattern, code, re.DOTALL):
        info = int.from_bytes(hit[1], "little")
        header = read(info, 12)
        if (len(header) == 12 and int.from_bytes(header[:4], "little") in (0x19930520, 0x19930521, 0x19930522)
                and 0 <= int.from_bytes(header[4:8], "little", signed=True) <= 65536):
            entries.add(base + hit.start())
    return entries


def branch_merges(code, base, rows, independent):
    """Prove contiguous owners; calls, code pointers and padded entries stay separate.

    An exact match to a block proves its bytes, not that it is a whole function.
    Require every byte and every retired start to belong to the owner's reachable
    control flow. Unreachable gaps, switch data and independent entries block a merge.
    """
    starts = [int(row["addr"], 16) for row in rows]
    anchors = sorted(set(starts) & (set(independent) | {
        start for start in starts if start > base and start % 16 == 0 and code[start - base - 1] == 0xCC}))
    decoder, merges = Cs(CS_ARCH_X86, CS_MODE_32), []
    for index, root in enumerate(anchors):
        limit = anchors[index + 1] if index + 1 < len(anchors) else base + len(code)
        lo, hi = bisect_left(starts, root), bisect_left(starts, limit)
        group = rows[lo:hi]
        if len(group) < 2 or any(row["kind"] == "data" for row in group):
            continue
        # Limit decoding to the existing inventory, without swallowing padding.
        limit = min(limit, starts[hi - 1] + group[-1]["size"])
        instructions = {a: (size, mnemonic, operands) for a, size, mnemonic, operands in
                        decoder.disasm_lite(code[root - base:limit - base], root)}
        todo, reached, valid = [root], {}, True
        while todo:
            address = todo.pop()
            if address in reached or not root <= address < limit:
                continue
            if address not in instructions:
                valid = False
                break
            size, mnemonic, operands = instructions[address]
            if mnemonic in ("int3", "hlt", "ud2"):
                valid = False
                break
            reached[address] = size
            if mnemonic.startswith(("j", "loop")):
                if operands.startswith("0x"):
                    todo.append(int(operands, 16))
                if mnemonic == "jmp":
                    continue
            if mnemonic not in ("ret", "retf"):
                if address + size == limit:
                    valid = False
                    break
                todo.append(address + size)
        if not valid or not reached:
            continue
        stop = max(address + size for address, size in reached.items())
        interior = [row for row in group[1:] if int(row["addr"], 16) < stop]
        if not interior or any(int(row["addr"], 16) not in reached or
                               int(row["addr"], 16) + row["size"] > stop for row in interior):
            continue
        if sum(reached.values()) != stop - root:
            continue  # No invented ownership of skipped bytes or embedded tables.
        merges.append(dict(addr=group[0]["addr"], size=stop - root,
                           fragments=[row["addr"] for row in interior]))
    return merges
