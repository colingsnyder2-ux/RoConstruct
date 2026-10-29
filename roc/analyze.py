"""Split a client exe into functions: work/<client>/functions.jsonl + meta.json.

Each row: addr, size, relocs (offsets of 4-byte fields the loader patches,
masked when diffing), calls (direct call count; 0 = leaf), call_targets/callers,
unit (RTTI class or seg_<64 KB block>).
"""
import hashlib
import json
import pefile
import re
from bisect import bisect_left
from capstone import CS_ARCH_X86, CS_MODE_32, Cs
from pathlib import Path

from roc import clients, match


ROOT = Path(__file__).resolve().parent.parent

STOP = {"ret", "retf", "int3", "hlt", "ud2"}

PRINTABLE = re.compile(rb"[ -~]{4,}")

def asm_shape(code, va):
    """Stable instruction shape for nearest-function retrieval."""
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    lines = []
    for insn in md.disasm(code, va):
        op = re.sub(r"0x[0-9a-f]+", "N", insn.op_str.lower())
        op = re.sub(r"\b\d+\b", "N", op)
        lines.append((insn.mnemonic + (" " + op if op else "")).strip())
    return " ; ".join(lines)

def reloc_sites(pe):
    """Virtual addresses of every HIGHLOW base relocation."""
    base = pe.OPTIONAL_HEADER.ImageBase
    return sorted(base + e.rva for block in getattr(pe, "DIRECTORY_ENTRY_BASERELOC", [])
                  for e in block.entries if e.type == 3)

def known_data(client, read):
    """Reviewed non-code spans, pinned to the exact binary bytes."""
    path = ROOT / "research" / "function-data.json"
    spans = []
    for row in json.loads(path.read_text()).get(client, []) if path.exists() else []:
        start = int(row["addr"], 16)
        if hashlib.sha256(read(start, row["size"])).hexdigest() != row["sha256"]:
            raise ValueError("Reviewed data bytes changed: %s %s" % (client, row["addr"]))
        spans.append((start, row["size"]))
    return spans


def seh_tail_entries(code, text_va, start, md):
    """Tail entries from a tiny frame-free dispatcher to an aligned SEH prologue.

    Inspect every local path; calls, stack changes, stores, nonvolatile writes
    and branches outside the 64-byte dispatcher invalidate the observation.
    This catches adjacent methods without an int3 gap (ToneMap's PS14/PS20).
    """
    todo, seen, entries = [start], set(), set()
    while todo:
        address = todo.pop()
        if address in seen:
            continue
        if not start <= address < min(start + 64, text_va + len(code)):
            return set()
        seen.add(address)
        insn = next(md.disasm_lite(code[address - text_va:address - text_va + 15], address, 1), None)
        if insn is None:
            return set()
        _, size, mnemonic, operands = insn
        if mnemonic == "ret":
            continue
        if mnemonic == "jmp":
            if not operands.startswith("0x"):
                return set()
            target = int(operands, 16)
            offset = target - text_va
            prefix = code[offset:offset + 21] if 0 <= offset < len(code) else b""
            if (target & 15 or len(prefix) != 21 or prefix[:3] != b"\x6a\xff\x68"
                    or prefix[7:] != b"\x64\xa1\0\0\0\0\x50\x64\x89\x25\0\0\0\0"
                    or not text_va <= int.from_bytes(prefix[3:7], "little") < text_va + len(code)):
                return set()
            entries.add(target)
            continue
        if mnemonic.startswith("j"):
            if not operands.startswith("0x"):
                return set()
            todo.append(int(operands, 16))
        elif mnemonic not in ("cmp", "test", "nop"):
            if (mnemonic not in ("mov", "lea", "add", "sub", "and", "or", "xor")
                    or operands.split(",", 1)[0] not in ("eax", "ecx", "edx")):
                return set()
        todo.append(address + size)
    return entries


def embedded_catch_entries(code, text_va, starts, conts, branches, called, protected, md):
    """Catch labels sharing a framed parent's normal exit are not new functions."""
    order = sorted(starts)
    merged = {}
    for continuation, last_mov in conts.items():
        parent_index = bisect_left(order, continuation + 1) - 1
        handler_index = bisect_left(order, last_mov + 1) - 1
        if parent_index < 0 or handler_index != parent_index + 1:
            continue
        parent, handler = order[parent_index], order[handler_index]
        stop = order[handler_index + 1] if handler_index + 1 < len(order) else text_va + len(code)
        if (parent in protected or handler in protected or handler in called or handler % 16 == 0
                or code[handler - text_va - 1] == 0xCC or stop - parent > 32768):
            continue
        prefix = list(md.disasm_lite(code[parent - text_va:handler - text_va], parent))
        if (len(prefix) < 2 or prefix[0][2:] != ("push", "ebp")
                or prefix[-1][0] + prefix[-1][1] != handler
                or prefix[1][2] not in ("mov", "lea") or not prefix[1][3].startswith("ebp,")
                or not any("fs:[0]" in op for _, _, _, op in prefix[:24])
                or any(m.startswith("ret") for _, _, m, _ in prefix)):
            continue
        handler_body = list(md.disasm_lite(code[handler - text_va:last_mov + 6 - text_va], handler))
        if (len(handler_body) < 2 or handler_body[-2][0] != last_mov
                or handler_body[-1][0:3] != (last_mov + 5, 1, "ret")
                or not any("[ebp" in op for _, _, _, op in handler_body)
                or any((m == "push" and op == "ebp") or op.startswith("ebp,")
                       for _, _, m, op in handler_body)):
            continue
        exits = [target for source, target in branches if parent <= source < handler
                 and last_mov + 6 <= target < stop]
        if not exits:
            continue
        tail = list(md.disasm_lite(code[last_mov + 6 - text_va:stop - text_va], last_mov + 6))
        epilogues = [a for (a, _, m, op), (_, _, m2, op2), (_, _, m3, _) in zip(tail, tail[1:], tail[2:])
                     if (m, op, m2, op2) == ("mov", "esp, ebp", "pop", "ebp") and m3 == "ret"]
        decoded = {a: (size, m, op) for a, size, m, op in tail}
        todo, seen, valid, reached_exit = list(exits), set(), True, False
        while todo and valid:
            address = todo.pop()
            if address in seen:
                continue
            seen.add(address)
            if address in epilogues:
                reached_exit = True
                continue
            if address not in decoded:
                valid = False
                break
            size, mnemonic, operands = decoded[address]
            if (mnemonic.startswith("ret") or mnemonic in ("int3", "hlt", "ud2")
                    or (mnemonic == "push" and operands == "ebp")
                    or (mnemonic in ("mov", "lea", "pop") and operands.split(",")[0] == "ebp")):
                valid = False
                break
            if mnemonic.startswith(("j", "loop")):
                if not operands.startswith("0x"):
                    valid = False
                    break
                todo.append(int(operands, 16))
                if mnemonic == "jmp":
                    continue
            todo.append(address + size)
        if not valid or not reached_exit:
            continue
        merged[handler] = dict(parent=parent, continuation=continuation, normal_entries=sorted(set(exits)))
    return merged


def find_functions(code, text_va, seeds, relocs, proven=(), keep=None, data=(), locked=()):
    """Recursive descent from seeds over .text (code at text_va).
    New starts: direct call targets and `push/mov offset fn` immediates.
    Tiny frame-free dispatchers also seed aligned, independently framed SEH
    tail entries, even when the preceding method has no int3 gap.
    Switch jump tables are followed so their case blocks count as reached.
    MSVC aligns functions to 16 after int3 padding, so aligned non-cc bytes
    after cc also seed (unless a jump table sits there).
    With `keep` (a set of trusted starts), a start that reached code falls into
    (no ret/jmp/call before it) or that a catch funclet returns to is an interior
    label, and is dropped unless it is a call target or in keep;
    trailing jump tables then no longer make a function "bad".
    Reviewed data spans remain in the inventory as data, without seeding code."""
    end = text_va + len(code)
    data = dict(data)
    in_data = lambda va: any(start <= va < start + size for start, size in data.items())
    reloc_set = set(relocs)
    rd = lambda va: int.from_bytes(code[va - text_va:va - text_va + 4], "little")
    pointed = set(seeds)  # entry + pointers from data: real starts even if a decode straddles them
    seeds = pointed | {text_va + i for i in range(16, len(code), 16)
                          if code[i - 1] == 0xCC and code[i] != 0xCC
                          and text_va + i not in reloc_set}
    starts = {s for s in seeds if text_va <= s < end and not in_data(s)} | set(data)
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    seen, calls, work, falls, called, tables, conts = set(data), set(), list(starts - data.keys()), set(), set(), set(), {}
    straddled, branches, callbacks = set(), [], set()
    while work:
        a = work.pop()
        if a in starts:
            entries = seh_tail_entries(code, text_va, a, md)
            starts.update(t for t in entries if not in_data(t))
            called.update(entries)
            work.extend(entries - seen)
        cont = None
        while text_va <= a < end and a not in seen and (not data or not in_data(a)):
            insn = next(md.disasm_lite(code[a - text_va:a - text_va + 15], a, 1), None)
            if insn is None:
                starts.discard(a)
                break
            seen.add(a)
            _, size, mnem, op = insn
            if (a | 15) + 1 < a + size:  # a 16-aligned "start" inside this instruction (cc displacement byte)
                straddled.add((a | 15) + 1)
            if mnem == "ret" and not op and cont:  # catch funclet: mov eax, offset continuation; ret
                conts[cont[0]] = cont[1]
            cont = (rd(a + 1), a) if mnem == "mov" and op.startswith("eax, 0x") and a + 1 in reloc_set else None
            for r in range(a, a + size - 3):
                if r not in reloc_set or not text_va <= rd(r) < end:
                    continue
                t = rd(r)
                if mnem == "jmp" and "[" in op:  # jmp [idx*4 + table]
                    tables.add(t)
                    while t in reloc_set and text_va <= rd(t) < end:
                        work.append(rd(t))
                        t += 4
                elif "[" not in op.split(",")[-1]:  # immediate code pointer: callback
                    starts.add(t)
                    callbacks.add(t)
                    work.append(t)
                else:  # switch index table or other data inside .text
                    tables.add(t)
            if mnem == "call" and op.startswith("0x"):
                t = int(op, 16)
                if text_va <= t < end:
                    starts.add(t)
                    work.append(t)
                    calls.add(a)
                    called.add(t)
            elif mnem.startswith(("j", "loop")):
                if op.startswith("0x"):
                    target = int(op, 16)
                    work.append(target)
                    branches.append((a, target))
                if mnem == "jmp":
                    break
                falls.add(a + size)
            elif mnem in STOP:
                break
            elif mnem != "call":  # a call may not return (throw, exit)
                falls.add(a + size)
            a += size
    if keep is not None:
        # A continuation right after its own catch funclet is a label inside that __catch$ symbol.
        order = sorted(starts)
        owner = lambda m: order[bisect_left(order, m + 1) - 1]
        starts -= (falls | {c for c, m in conts.items() if owner(m) == owner(c - 1)}) - called - keep
        # e.g. c6 84 24 cc 00 00 00 03 (mov byte [esp+0xcc],3): the cc seeded a fake start mid-instruction.
        invalid = straddled - called - pointed - callbacks
        starts -= invalid
        proven = [(start, size) for start, size in proven if start not in invalid]
    embedded = embedded_catch_entries(code, text_va, starts & seen, conts, branches, called,
                                      set(locked) | {start for start, _ in proven}, md) if keep is not None else {}
    starts -= embedded.keys()
    # Proven extents (a compiled function matched these bytes exactly): no start
    # inside one, and whatever follows it starts a new function.
    for start, size in proven:
        if in_data(start):
            continue  # An old source score cannot turn reviewed data back into code.
        starts -= {s for s in starts if start < s < start + size}
        starts.add(start)
        seen.add(start)
        if start + size < end and code[start + size - text_va] != 0xCC:
            starts.add(start + size)
            seen.add(start + size)
    starts = {s for s in starts if not in_data(s)} | set(data)
    order = sorted(s for s in starts if s in seen) + [end]
    call_sites = sorted(calls)
    tables = sorted(tables) if keep is not None else []
    out = []
    for start, nxt in zip(order, order[1:]):
        body = (code[start - text_va:start - text_va + data[start]] if start in data
                else code[start - text_va:nxt - text_va].rstrip(b"\xcc"))  # MSVC int3 padding
        if not body:
            continue
        stop = start + len(body)
        lo, hi = bisect_left(relocs, start), bisect_left(relocs, stop)
        rel = [r - start for r in relocs[lo:hi]]
        # Jump tables trail their switch inside the function: only the code before them must decode.
        t = bisect_left(tables, start + 1)
        code_len = tables[t] - start if t < len(tables) and tables[t] < stop else len(body)
        out.append({
            "addr": "%08x" % start,
            "size": len(body),
            "relocs": rel,
            "calls": bisect_left(call_sites, stop) - bisect_left(call_sites, start),
            "kind": "data" if start in data else "eh" if _catch_funclet(code, text_va, start, body, reloc_set, rd)
                    else kind_of(body[:code_len], [r for r in rel if r < code_len]),
        })
        joined = [dict(handler="%08x" % handler, continuation="%08x" % item["continuation"],
                       normal_entries=["%08x" % va for va in item["normal_entries"]])
                  for handler, item in embedded.items() if item["parent"] == start]
        if joined:
            out[-1]["embedded_catches"] = joined
    if keep is not None:
        from roc.boundaries import branch_merges
        repairs = branch_merges(code, text_va, out, pointed | called | callbacks)
        retired = {addr for repair in repairs for addr in repair["fragments"]}
        by_addr = {row["addr"]: row for row in out}
        for repair in repairs:
            row = by_addr[repair["addr"]]
            start, size = int(row["addr"], 16), repair["size"]
            lo, hi = bisect_left(relocs, start), bisect_left(relocs, start + size)
            row.update(size=size, relocs=[r - start for r in relocs[lo:hi]],
                       calls=bisect_left(call_sites, start + size) - bisect_left(call_sites, start),
                       boundary_fragments=repair["fragments"])
            row["kind"] = kind_of(code[start - text_va:start - text_va + size], row["relocs"])
        out = [row for row in out if row["addr"] not in retired]
    return out

def _catch_funclet(code, text_va, start, body, reloc_set, rd):
    """`mov eax, offset continuation; ret` that is a catch funclet, not a getter returning a code
    pointer: it returns to its own next byte, or sits unaligned inside its parent (no int3 pad)."""
    if body[:1] != b"\xb8" or body[5:6] != b"\xc3" or start + 1 not in reloc_set:
        return False
    target = rd(start + 1)
    end = text_va + len(code)
    return target == start + 6 or (text_va <= target < end and start % 16 != 0
                                   and code[start - text_va - 1] != 0xCC)

GENERATED = [re.compile(p) for p in (
    # __ehhandler$: security cookie check, then jump to __CxxFrameHandler3
    r"^mov edx, dword ptr \[esp \+ 8\] ; lea eax, \[edx(?: [+-] \w+)?\] ; .*xor ecx, eax ; call N ; mov eax, N ; jmp N$",
    # scalar deleting destructor (??_G): ~T(); if (flags & 1) delete this;
    r"^push esi ; mov esi, ecx ; (mov dword ptr \[esi\], N ; )?call (dword ptr \[N\]|N) ; test byte ptr \[esp \+ 8\], 1 ; "
    r"je N ; push esi ; call (dword ptr \[N\]|N) ; add esp, 4 ; mov eax, esi ; pop esi ; ret 4$",
    r"^test byte ptr \[esp \+ 4\], 1 ; push esi ; mov esi, ecx ; mov dword ptr \[esi\], N ; je N ; push esi ; "
    r"call (dword ptr \[N\]|N) ; add esp, 4 ; mov eax, esi ; pop esi ; ret 4$",
    # static-local guard reset in unwind code: $S &= ~bit
    r"^mov eax, dword ptr \[N\] ; and eax, N ; mov dword ptr \[N\], eax ; ret$",
    # EH-guarded dynamic initializer of a global object
    r"^mov eax, dword ptr fs:\[0\] ; push -1 ; push N ; push eax ; mov dword ptr fs:\[0\], esp ; mov ecx, N ; .* ; mov dword ptr fs:\[0\], ecx ; add esp, \w+ ; ret$",
)]

# Linker/compiler thunks no source can produce; workers would burn rounds on them.
THUNKS = [(k, re.compile(p)) for k, p in (
    ("thunk", r"^jmp dword ptr \[N\]( ; jmp dword ptr \[N\])+$"),               # glued import thunks
    ("thunk", r"^mov eax, dword ptr \[(ecx|esp \+ 4)\] ; jmp dword ptr \[eax( \+ \w+)?\]$"),  # vcall
    ("adjustor", r"^sub dword ptr \[esp \+ 4\], \w+ ; jmp N$"),                  # this-adjustor
    ("adjustor", r"^sub ecx, dword ptr \[ecx - 4\] ; sub ecx, \w+ ; jmp N$"),    # vtordisp
)]

def kind_of(code, relocs):
    """'thunk' (import jump), 'adjustor' (this-pointer fixup + jmp), 'gen' (EH handler, deleting dtor, guard reset), 'eh'
    (unwind funclet / exception handler stub) or 'code'. Only 'code' counts
    toward progress: the rest is generated by the compiler or linker.
    ponytail: pattern list, misses rarer generated shapes."""
    insns = list(Cs(CS_ARCH_X86, CS_MODE_32).disasm_lite(code, 0))
    if sum(i[1] for i in insns) != len(code):
        return "bad"  # split mid-instruction or data: not a real function
    if not insns:
        return "code"
    if len(insns) == 1 and code[0] == 0xEB:
        return "bad"  # lone short jump: the tail of another function
    if len(code) <= 4 and not insns[-1][2].startswith(("ret", "jmp")):
        return "bad"  # tiny and never returns: data bytes, not code
    shape = " ; ".join(re.sub(r"0x[0-9a-f]+", "N", "%s %s" % (m, o)).strip() for _, _, m, o in insns)
    if shape.count("add byte ptr [eax], al") >= 8:
        return "bad"  # 00 00 run density: a data table (GUID/dispatch/static array), not code
    if any(p.search(shape) for p in GENERATED):
        return "gen"
    for kind, p in THUNKS:
        if p.search(shape):
            return kind
    first, last = insns[0], insns[-1]
    if len(insns) == 1 and first[2] == "jmp" and first[3].startswith("dword ptr [0x"):
        return "thunk"
    if last[2] == "jmp" and len(insns) == 2 and first[2] in ("sub", "add") and first[3].startswith("ecx,"):
        return "adjustor"
    if any("[ebp" in o for _, _, _, o in insns[:2]) and not any(m == "push" and o == "ebp" for _, _, m, o in insns):
        return "eh"
    if len(insns) == 2 and first[2] == "mov" and first[3].startswith("eax, 0x") and last[2] == "jmp" and relocs == [1]:
        return "eh"
    return "code"

def demangle_class(raw):
    """'.?AVInstance@RBX@@' -> 'RBX::Instance'. Templates stay rough."""
    name = raw[4:].split("@@")[0]
    return "::".join(reversed([p for p in name.split("@") if p]))

def rtti_vtables(read, relocs, in_text):
    """[(class, vtable va, [slot function va])] from MSVC RTTI. read(va, n) -> bytes.
    vtable[-1] -> CompleteObjectLocator{sig 0, off, cdOff, TypeDescriptor*}."""
    reloc_set = set(relocs)
    rd = lambda va: int.from_bytes(read(va, 4), "little")
    out = []
    for site in relocs:
        if in_text(site):
            continue
        col = rd(site)
        if col + 12 not in reloc_set or rd(col) != 0:
            continue
        raw = read(rd(col + 12) + 8, 256).split(b"\0")[0]
        if not raw.startswith((b".?AV", b".?AU")):
            continue
        cls = demangle_class(raw.decode("latin-1"))
        vt, fns = site + 4, []
        while vt in reloc_set and in_text(rd(vt)):
            fns.append(rd(vt))
            vt += 4
        out.append((cls, site + 4, fns))
    return out

def msvc_unwind_actions(read, relocs, in_text):
    """Action provenance from validated x86 MSVC FuncInfo/unwind maps."""
    sites = set(relocs)
    actions = {}
    for site in sorted(sites):
        if not in_text(site) or read(site - 1, 1) != b"\xb8" or read(site + 4, 1) != b"\xe9":
            continue
        info = int.from_bytes(read(site, 4), "little")
        header = read(info, 12)
        if len(header) != 12 or header[:4] != b"\x22\x05\x93\x19" or info + 8 not in sites:
            continue
        count = int.from_bytes(header[4:8], "little", signed=True)
        table = int.from_bytes(header[8:12], "little")
        if count <= 0:
            continue
        entries = read(table, count * 8)
        if len(entries) != count * 8:
            continue
        parsed = [(int.from_bytes(entries[i:i + 4], "little", signed=True),
                   int.from_bytes(entries[i + 4:i + 8], "little")) for i in range(0, len(entries), 8)]
        if any(not -1 <= state < index or (action and
               (not in_text(action) or table + index * 8 + 4 not in sites))
               for index, (state, action) in enumerate(parsed)):
            continue
        for index, (state, action) in enumerate(parsed):
            if action:
                actions.setdefault(action, []).append(dict(handler=site - 1, func_info=info,
                    unwind_map=table, state=index, to_state=state))
    return actions


def mark_unwind_actions(funcs, actions, read):
    """Keep map provenance; classify only actions that require the parent's EBP."""
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    for row in funcs:
        start = int(row["addr"], 16)
        if start not in actions or row["kind"] == "data":
            continue
        row["unwind_context"] = actions[start]
        insns = list(md.disasm_lite(read(start, row["size"]), start))
        if row["kind"] == "code" and any("[ebp" in op for _, _, _, op in insns) and not any(
                (m == "push" and op == "ebp") or op.startswith("ebp,") for _, _, m, op in insns):
            row["kind"] = "eh"


def msvc_catch_handlers(read, relocs, in_text):
    """Catch entry provenance from validated x86 MSVC FuncInfo try maps."""
    sites, found = set(relocs), {}
    for site in sorted(sites):
        if not in_text(site) or read(site-1, 1) != b"\xb8" or read(site+4, 1) != b"\xe9":
            continue
        info = int.from_bytes(read(site, 4), "little")
        header = read(info, 20)
        if len(header) != 20 or header[:4] != b"\x22\x05\x93\x19" or info+16 not in sites:
            continue
        states = int.from_bytes(header[4:8], "little", signed=True)
        count = int.from_bytes(header[12:16], "little", signed=True)
        table = int.from_bytes(header[16:20], "little")
        if not 0 < states <= 65536 or not 0 < count <= 4096:
            continue
        entries = read(table, count*20)
        if len(entries) != count*20:
            continue
        pending, valid = [], True
        for index in range(count):
            entry = entries[index*20:index*20+20]
            low, high, catch_high, catches = [int.from_bytes(entry[i:i+4], "little", signed=True)
                                            for i in range(0, 16, 4)]
            handlers = int.from_bytes(entry[16:20], "little")
            if (not 0 <= low <= high <= catch_high < states or not 0 < catches <= 1024
                    or table+index*20+16 not in sites):
                valid = False
                break
            records = read(handlers, catches*16)
            if len(records) != catches*16:
                valid = False
                break
            for catch in range(catches):
                record = records[catch*16:catch*16+16]
                descriptor = int.from_bytes(record[4:8], "little")
                address = int.from_bytes(record[12:16], "little")
                if (not in_text(address) or handlers+catch*16+12 not in sites
                        or (descriptor and (handlers+catch*16+4 not in sites or len(read(descriptor, 8)) != 8))):
                    valid = False
                    break
                pending.append((address, dict(handler=site-1, func_info=info, try_map=table,
                    handler_array=handlers, try_low=low, try_high=high, catch_high=catch_high,
                    catch_type=descriptor, catch_object=int.from_bytes(record[8:12], "little", signed=True))))
            if not valid:
                break
        if valid:
            for address, context in pending:
                found.setdefault(address, []).append(context)
    return found


def mark_catch_handlers(funcs, handlers, read):
    """A mapped catch using its parent's EBP is not an independent function."""
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    for row in funcs:
        start = int(row["addr"], 16)
        if start not in handlers or row["kind"] == "data":
            continue
        row["catch_context"] = handlers[start]
        insns = list(md.disasm_lite(read(start, row["size"]), start))
        if any("[ebp" in op for _, _, _, op in insns) and not any(
                (m == "push" and op == "ebp") or op.startswith("ebp,") for _, _, m, op in insns):
            row["kind"] = "eh"


def rtti_classes(read, relocs, in_text):
    """{function va: class} from MSVC vtables.
    A function shared by several vtables goes to the smallest one (the base)."""
    best = {}
    for cls, _, fns in rtti_vtables(read, relocs, in_text):
        for fn in fns:
            if fn not in best or len(fns) < best[fn][0]:
                best[fn] = (len(fns), cls)
    return {fn: cls for fn, (_, cls) in best.items()}

def assign_units(funcs, classes, reach=0x4000):
    """Link order keeps one .obj contiguous, so a function inherits the class of
    the nearest labelled function before it (within `reach` bytes).
    ponytail: guesses .obj boundaries; real ones need map files or symbols."""
    cur, cur_end = None, 0
    for f in funcs:
        va = int(f["addr"], 16)
        if va in classes:
            cur, cur_end = classes[va], va + f["size"]
        elif cur and va - cur_end > reach:
            cur = None
        f["unit"] = cur or "seg_%08x" % (va - va % 0x10000)

def mark_matched_code(funcs, matched):
    """An exact match proves a "bad" split (jump-table data) is real code. Compiler- and
    linker-generated kinds (gen, thunk, adjustor) stay out: they are byproducts, not source."""
    for f in funcs:
        if f["addr"] in matched and f["kind"] == "bad":
            f["kind"] = "code"

def entry_ecx_constructors(body, start, imports):
    """Imported constructors reached from entry ECX before the first branch.

    These are observed addresses, not a declaration of the complete object layout.
    Loads through a pointer lose their origin; calls clobber volatile registers.
    """
    from capstone.x86_const import X86_OP_REG, X86_OP_MEM, X86_OP_IMM
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    origins, found = {"ecx": 0}, []
    for insn in md.disasm(body, start):
        if insn.mnemonic in STOP or insn.mnemonic.startswith(("j", "loop")):
            break
        ops, derived = insn.operands, None
        if insn.mnemonic == "call":
            if ops[0].type == X86_OP_MEM and not ops[0].mem.base and not ops[0].mem.index:
                name = imports.get(ops[0].mem.disp, "")
                if name.rsplit("!", 1)[-1].startswith("??0") and origins.get("ecx", -1) >= 0:
                    found.append(dict(offset=origins["ecx"], constructor=name[:256], call="%08x" % insn.address))
            for reg in ("eax", "ecx", "edx"):
                origins.pop(reg, None)
            if len(found) == 16:
                break
            continue
        if len(ops) == 2 and ops[0].type == X86_OP_REG and ops[0].size == 4:
            dest = insn.reg_name(ops[0].reg)
            if insn.mnemonic == "mov" and ops[1].type == X86_OP_REG:
                derived = origins.get(insn.reg_name(ops[1].reg))
            elif insn.mnemonic == "lea" and ops[1].type == X86_OP_MEM and not ops[1].mem.index:
                origin = origins.get(insn.reg_name(ops[1].mem.base))
                if origin is not None:
                    derived = origin + ops[1].mem.disp
            elif insn.mnemonic in ("add", "sub") and ops[1].type == X86_OP_IMM and dest in origins:
                derived = origins[dest] + ops[1].imm * (1 if insn.mnemonic == "add" else -1)
        for reg in insn.regs_access()[1]:
            name = insn.reg_name(reg)
            if name in ("si", "di", "bp", "sp"):
                name = "e" + name
            elif len(name) == 2 and name[0] in "abcd" and name[1] in "lhx":
                name = "e" + name[0] + "x"
            origins.pop(name, None)
        if derived is not None:
            origins[dest] = derived
    return found


def virtual_dispatch_slots(body, start):
    """Candidate vtable slots, requiring the same object in ECX at the call.

    Keep provenance inside basic blocks; these clues do not identify a class.
    """
    from capstone.x86_const import X86_OP_REG, X86_OP_MEM, X86_OP_IMM
    from capstone import x86_const
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    instructions = list(md.disasm(body, start))
    joins = {i.operands[0].imm for i in instructions
             if i.mnemonic.startswith(("j", "loop")) and i.operands
             and i.operands[0].type == X86_OP_IMM}
    registers = {name: getattr(x86_const, "X86_REG_" + name.upper())
                 for name in ("eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp")}
    values = {reg: (start, reg) for reg in registers.values()}
    tables, methods, found = {}, {}, []
    for insn in instructions:
        if insn.address in joins:
            tables.clear()
            methods.clear()
            values = {reg: (insn.address, reg) for reg in registers.values()}
        ops = insn.operands
        if insn.mnemonic in ("call", "jmp") and ops:
            method = None
            if ops[0].type == X86_OP_REG:
                method = methods.get(ops[0].reg)
            elif (ops[0].type == X86_OP_MEM and ops[0].mem.base in tables
                  and not ops[0].mem.index and ops[0].mem.disp >= 0
                  and ops[0].mem.disp % 4 == 0):
                method = (tables[ops[0].mem.base], ops[0].mem.disp // 4)
            if method is not None and method[0] == values[registers["ecx"]]:
                found.append(method[1])
        table, method, value = None, None, None
        if insn.mnemonic == "mov" and len(ops) == 2 and ops[0].type == X86_OP_REG and ops[0].size == 4:
            if ops[1].type == X86_OP_REG:
                table, method = tables.get(ops[1].reg), methods.get(ops[1].reg)
                value = values.get(ops[1].reg)
            elif ops[1].type == X86_OP_MEM and not ops[1].mem.index:
                mem = ops[1].mem
                if mem.base in tables and mem.disp >= 0 and mem.disp % 4 == 0:
                    method = (tables[mem.base], mem.disp // 4)
                elif mem.base in values and mem.disp == 0:
                    table = values[mem.base]
        for reg in insn.regs_access()[1]:
            name = insn.reg_name(reg)
            if name in ("si", "di", "bp", "sp"):
                name = "e" + name
            elif len(name) == 2 and name[0] in "abcd" and name[1] in "lhx":
                name = "e" + name[0] + "x"
            full = registers.get(name)
            if full is not None:
                tables.pop(full, None)
                methods.pop(full, None)
                values[full] = (insn.address, full)
        if value is not None:
            values[ops[0].reg] = value
        if table is not None:
            tables[ops[0].reg] = table
        if method is not None:
            methods[ops[0].reg] = method
        if insn.mnemonic == "call":
            for name in ("eax", "ecx", "edx"):
                reg = registers[name]
                tables.pop(reg, None)
                methods.pop(reg, None)
                values[reg] = (insn.address, reg)
        if insn.mnemonic in STOP or insn.mnemonic.startswith(("j", "loop")):
            tables.clear()
            methods.clear()
            values = {reg: (insn.address, reg) for reg in registers.values()}
    return sorted(set(found))[:8]


def binary_facts(pe, image, base, body, start, imports, local_targets=None):
    """Small structured clues from one function; bounded for prompt/index use."""
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    data_refs, strings, imported_names, external_calls, global_reads, global_writes = [], [], [], [], [], []
    stack_args, branches, constants = [], 0, []
    this_reads, this_writes = [], []
    seen = set()
    for insn in md.disasm(body, start):
        text = insn.op_str.lower()
        if insn.mnemonic in ("call", "jmp"):
            for address in re.findall(r"0x[0-9a-f]+", text):
                target = int(address, 16)
                if target in imports:
                    external_calls.append(imports[int(address, 16)])
                elif insn.mnemonic == "call" and local_targets is not None and target not in local_targets:
                    external_calls.append(address)
        for raw in re.findall(r"\[ecx(?: \+ (0x[0-9a-f]+|\d+))?\]", text):
            offset = int(raw or "0", 0)
            (this_writes if insn.mnemonic == "mov" and text.split(",", 1)[0].endswith("]")
             else this_reads).append(offset)
        if insn.mnemonic.startswith(("j", "loop")):
            branches += 1
        for raw in re.findall(r"0x[0-9a-f]+", text):
            value = int(raw, 16)
            if value in imports:
                data_refs.append(raw)
                imported_names.append(imports[value])
                continue
            if not (base <= value < base + len(image)):
                continue
            if value in seen:
                continue
            seen.add(value)
            data_refs.append(raw)
            (global_writes if insn.mnemonic == "mov" and text.split(",", 1)[0].startswith("dword ptr [")
             else global_reads).append(raw)
            if not ((insn.mnemonic == "push" and text == raw)
                    or (insn.mnemonic == "mov" and text.rsplit(",", 1)[-1].strip() == raw)
                    or (insn.mnemonic == "lea" and text.endswith("[" + raw + "]"))):
                continue  # pointer literals only: code destinations and float loads are not strings
            chunk = image[value - base:value - base + 256]
            literal, end, _ = chunk.partition(b"\0")
            if end and len(literal) >= 4 and all(c in (9, 10, 13) or 32 <= c < 127 for c in literal):
                strings.append(literal[:128].decode("ascii"))
        stack_args.extend(int(x, 0) for x in re.findall(r"\[esp \+ (0x[0-9a-f]+|\d+)\]", text))
        for raw in re.findall(r"(?<![+\w])-?\b\d+\b", text):
            try:
                n = int(raw)
                if n > 3:
                    constants.append(n)
            except ValueError:
                pass
    returns = [i for i in md.disasm(body, start) if i.mnemonic == "ret"]
    return {
        "imports": sorted(set(imported_names))[:12],
        "external_calls": sorted(set(external_calls))[:12],
        "strings": list(dict.fromkeys(strings))[:12],
        "entry_ecx_constructors": entry_ecx_constructors(body, start, imports),
        "data_refs": sorted(set(data_refs))[:16],
        "global_reads": sorted(set(global_reads))[:16],
        "global_writes": sorted(set(global_writes))[:16],
        "virtual_slots": virtual_dispatch_slots(body, start),
        "stack_args": sorted(set(stack_args))[:8],
        "this_reads": sorted(set(this_reads))[:16],
        "this_writes": sorted(set(this_writes))[:16],
        "calling_convention": "callee" if any(i.op_str.strip() for i in returns) else "caller",
        "return_stack_bytes": sorted({int(i.op_str or "0", 0) for i in returns}),
        "branches": branches,
        "constants": sorted(set(constants))[:16],
    }

def import_symbols(pe, functions, read):
    """Keep named/ordinal imports and exact one-instruction IAT jump stubs."""
    imports = {}
    for dll in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
        for item in dll.imports:
            if item.address:
                name = item.name.decode("latin-1") if item.name else "#%d" % item.ordinal
                imports[item.address] = "%s!%s" % (dll.dll.decode("latin-1"), name)
    thunks = {}
    for function in functions:
        if function["size"] != 6 or function.get("kind") in ("data", "bad", "eh"):
            continue
        start = int(function["addr"], 16)
        body = read(start, 6)
        if len(body) == 6 and body[:2] == b"\xff\x25":
            slot = int.from_bytes(body[2:], "little")
            if slot in imports:
                thunks[start] = imports[slot]
    imports.update(thunks)
    return imports


def analyze(client, exe):
    pe = pefile.PE(str(exe))
    base = pe.OPTIONAL_HEADER.ImageBase
    text = next(s for s in pe.sections if s.Name.rstrip(b"\0") == b".text")
    text_va = base + text.VirtualAddress
    code = text.get_data()[:text.Misc_VirtualSize]
    in_text = lambda va: text_va <= va < text_va + len(code)
    image = pe.get_memory_mapped_image()
    read = lambda va, n: image[va - base:va - base + n] if 0 <= va - base < len(image) else b""
    relocs = reloc_sites(pe)
    seeds = {base + pe.OPTIONAL_HEADER.AddressOfEntryPoint}
    # Pointers stored outside .text (vtables, callback tables) into .text.
    seeds.update(v for v in (int.from_bytes(read(s, 4), "little") for s in relocs if not in_text(s))
                 if in_text(v))
    from roc.boundaries import seh_entries
    seeds.update(seh_entries(code, text_va, read))
    bounds = ROOT / "work" / client / "bounds.json"
    proven = [(int(a, 16), n) for a, n in json.loads(bounds.read_text())] if bounds.exists() else ()
    scores_file = ROOT / "work" / client / "scores.json"
    matched = {a for a, s in json.loads(scores_file.read_text()).items() if s == 100} if scores_file.exists() else set()
    # Trusted starts a fallthrough cannot retire: entry, vtable slots, proven extents, exact matches.
    keep = ({base + pe.OPTIONAL_HEADER.AddressOfEntryPoint} | {s for s, _ in proven} | {int(a, 16) for a in matched}
            | {fn for _, _, fns in rtti_vtables(read, relocs, in_text) for fn in fns})
    funcs = find_functions(code, text_va, seeds, relocs, proven, keep, known_data(client, read),
                           locked={int(addr, 16) for addr in matched})
    imports = import_symbols(pe, funcs, read)
    # Persist direct-call edges so source retrieval can use neighboring functions.
    by_addr = {int(f["addr"], 16): f for f in funcs}
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    for f in funcs:
        if f["kind"] == "data":
            f.update(call_targets=[], shape="")
            continue
        start = int(f["addr"], 16)
        body = code[start - text_va:start - text_va + f["size"]]
        targets = []
        for insn in md.disasm(body, start):
            if insn.mnemonic == "call" and insn.op_str.startswith("0x"):
                target = int(insn.op_str, 16)
                if target in by_addr:
                    targets.append("%08x" % target)
        f["call_targets"] = sorted(set(targets))
        f["shape"] = asm_shape(body, start)
    callers = {}
    for f in funcs:
        for target in f["call_targets"]:
            callers.setdefault(target, []).append(f["addr"])
    for f in funcs:
        f["callers"] = callers.get(f["addr"], [])
        start = int(f["addr"], 16)
        body = code[start - text_va:start - text_va + f["size"]]
        if f["kind"] != "data":
            f.update(binary_facts(pe, image, base, body, start, imports, by_addr))
    mark_unwind_actions(funcs, msvc_unwind_actions(read, relocs, in_text), read)
    mark_catch_handlers(funcs, msvc_catch_handlers(read, relocs, in_text), read)
    classes = rtti_classes(read, relocs, in_text)
    assign_units(funcs, classes)
    siblings = {}
    for f in funcs:
        if f["kind"] == "data":
            continue
        siblings.setdefault(f["unit"], []).append(f["addr"])
    sibling_index = {unit: {addr: i for i, addr in enumerate(peers)} for unit, peers in siblings.items()}
    for f in funcs:
        if f["kind"] == "data":
            f["siblings"] = []
            continue
        peers = siblings.get(f["unit"], [])
        index = sibling_index[f["unit"]][f["addr"]]
        f["siblings"] = peers[max(0, index - 2):index] + peers[index + 1:index + 3]
    # Functions found in the compiler's own prebuilt libraries (`roc mass`) are not Roblox code.
    libmatch = ROOT / "work" / client / "libmatch.json"
    if libmatch.exists():
        runtime = set(json.loads(libmatch.read_text()))
        for f in funcs:
            if f["addr"] in runtime and f["kind"] != "data":
                f["kind"] = "gen"
    # Anything already byte-matched by real source is code, whatever a pattern guessed.
    mark_matched_code(funcs, matched)
    data = sum(s.Misc_VirtualSize for s in pe.sections
               if s.Name.rstrip(b"\0") in (b".rdata", b".data", b".tls"))
    out = ROOT / "work" / client
    out.mkdir(parents=True, exist_ok=True)
    from roc import tasks
    if (out / "functions.jsonl").exists() and scores_file.exists():
        from roc.boundaries import current_scores
        previous = [json.loads(line) for line in (out / "functions.jsonl").read_text().splitlines()]
        scores = json.loads(scores_file.read_text())
        corrected = current_scores(previous, funcs, scores)
        if corrected != scores:
            tasks.write_text(scores_file, json.dumps(corrected, indent=0, sort_keys=True))
    tasks.write_text(out / "functions.jsonl", "".join(json.dumps(f, separators=(",", ":")) + "\n" for f in funcs))
    tasks.write_text(out / "meta.json", json.dumps({"code_bytes": len(code), "data_bytes": data,
                                                   "classes": len(set(classes.values()))}))
    return out / "functions.jsonl", funcs


# --- audit ---
# Checks borrowed from reccmp (isledecomp), shaped for one-file-per-address source.

ADDR = re.compile(r"^[0-9a-f]{8}$")


NOTE_SYMBOL = re.compile(r"\(function (\S+)\)")


PARTIAL = re.compile(r"// from server: (\d+)% by ")


def _scores(client):
    path = ROOT / "work" / client / "scores.json"
    return json.loads(path.read_text()) if path.exists() else {}


def lint(client, show=5, log=print):
    """Problems as {category: [detail]}. Errors are categories starting with 'error'."""
    from roc import libs, setup
    funcs, scores = match._functions(client), _scores(client)
    known_builds = set(libs.BUILDS) | set(setup.compilers())
    problems = {}
    add = lambda kind, detail: problems.setdefault(kind, []).append(detail)
    folder = ROOT / "src" / client
    for path in sorted(folder.glob("*.cpp")) if folder.is_dir() else []:
        addr = path.stem
        if not ADDR.match(addr):
            add("error: file name is not an 8-digit lowercase address", path.name)
            continue
        if addr not in funcs:
            add("error: no function starts at this address", path.name)
        text = path.read_text(errors="replace")
        d = match.directives(text)
        if d.get("cl") and (not d["cl"].isdigit() or int(d["cl"]) not in known_builds):
            add("error: unknown compiler build in roc-cl", "%s (%s)" % (path.name, d["cl"]))
        for key in ("lib", "archive"):
            recipe = d.get(key, "").split(" ")[0]
            if recipe and recipe not in libs.RECIPES:
                add("error: roc-%s names an unknown recipe" % key, "%s (%s)" % (path.name, recipe))
        if d.get("lang") not in (None, "c", "cpp"):
            add("error: roc-lang must be c or cpp", path.name)
        partial = PARTIAL.match(text)
        if partial and int(partial.group(1)) < 100 and scores.get(addr) == 100:
            add("warning: scored 100 but file header says a partial attempt (roc check it)",
                "%s (%s%%)" % (path.name, partial.group(1)))
    have = {p.stem for p in folder.glob("*.cpp")} if folder.is_dir() else set()
    for addr, score in scores.items():
        if score == 100 and addr not in have:
            add("warning: scored 100 but no source file here (pull from the server)", addr)
    rows = sorted(funcs.values(), key=lambda r: int(r["addr"], 16))
    for a, b in zip(rows, rows[1:]):
        if int(a["addr"], 16) + a["size"] > int(b["addr"], 16):
            add("error: function bodies overlap (roadmap)", "%s+%d > %s" % (a["addr"], a["size"], b["addr"]))
    for kind in sorted(problems):
        items = problems[kind]
        log("%-70s %6d  e.g. %s" % (kind, len(items), ", ".join(items[:show])))
    log("data: %s" % data_coverage(client))
    return problems


def data_coverage(client):
    """Bytes of .rdata/.data/.tls pinned by verified data spans of matched functions."""
    work = ROOT / "work" / client
    spans = json.loads((work / "data.json").read_text()) if (work / "data.json").exists() else {}
    meta = json.loads((work / "meta.json").read_text()) if (work / "meta.json").exists() else {}
    covered = set()
    for rows in spans.values():
        for va, length in rows:
            covered.update(range(va, va + length))
    total = meta.get("data_bytes") or 0
    return "%d of %d bytes verified (%.2f%%)" % (len(covered), total, 100.0 * len(covered) / total if total else 0)


def vtables(client):
    """[{class, vtable, slots: [[addr, score]]}] read straight from the client exe."""
    import pefile
    from roc.analyze import reloc_sites, rtti_vtables
    pe = pefile.PE(str(clients.exe_path(client, clients.load()[client])))
    base = pe.OPTIONAL_HEADER.ImageBase
    text = next(s for s in pe.sections if s.Name.rstrip(b"\0") == b".text")
    lo = base + text.VirtualAddress
    hi = lo + text.Misc_VirtualSize
    image = pe.get_memory_mapped_image()
    read = lambda va, n: image[va - base:va - base + n] if 0 <= va - base < len(image) else b""
    scores = _scores(client)
    out = []
    for cls, vt, fns in rtti_vtables(read, reloc_sites(pe), lambda va: lo <= va < hi):
        slots = [["%08x" % fn, scores.get("%08x" % fn, 0)] for fn in fns]
        out.append({"class": cls, "vtable": "%08x" % vt, "slots": slots})
    return sorted(out, key=lambda v: v["vtable"])


def vtable_report(client, top=20, log=print):
    tables = vtables(client)
    (ROOT / "work" / client / "vtables.json").write_text(json.dumps(tables, indent=0))
    slots = sum(len(v["slots"]) for v in tables)
    done = sum(1 for v in tables for _, s in v["slots"] if s == 100)
    full = [v for v in tables if v["slots"] and all(s == 100 for _, s in v["slots"])]
    log("%s: %d vtables, %d slots, %d matched (%.1f%%), %d vtables fully matched"
        % (client, len(tables), slots, done, 100.0 * done / slots if slots else 0, len(full)))
    near = sorted((v for v in tables if v not in full and v["slots"]),
                  key=lambda v: -sum(s == 100 for _, s in v["slots"]) / len(v["slots"]))
    for v in near[:top]:
        missing = [a for a, s in v["slots"] if s < 100]
        log("  %s %-50s %d/%d  open: %s" % (v["vtable"], v["class"][:50], len(v["slots"]) - len(missing),
                                           len(v["slots"]), " ".join(missing[:6])))
    log("wrote work/%s/vtables.json" % client)
    return tables


def ghidra_names(client):
    """{addr: (name or "", comment)} from donor PDB names, library symbols and RTTI."""
    from roc import matchers
    scores, out = _scores(client), {}
    for addr, row in match._functions(client).items():
        name, notes = "", []
        same = matchers.hint(client, addr)
        if same and same["symbol"]:
            name = same["symbol"]
            notes.append("same bytes as WebService.dll 0x%s" % same["donor"])
        path = ROOT / "src" / client / ("%s.cpp" % addr)
        if path.exists():
            m = NOTE_SYMBOL.search(path.read_text(errors="replace")[:2000])
            name = name or (m.group(1) if m else "")
        if not row["unit"].startswith("seg_"):
            notes.append("class %s (RTTI)" % row["unit"])
        if scores.get(addr):
            notes.append("RoConstruct %d%%" % scores[addr])
        if name or notes:
            out[addr] = (name, "; ".join(notes))
    return out


GHIDRA = '''# RoConstruct names and match status for %(client)s. Run from Ghidra's Script Manager
# on the %(client)s exe. Decorated names are kept; run the Demangler analyzer afterwards.
# @category RoConstruct
from ghidra.program.model.symbol import SourceType
NAMES = %(names)s
fm = currentProgram.getFunctionManager()
named = 0
for va, (name, comment) in sorted(NAMES.items()):
    a = toAddr(va)
    f = fm.getFunctionAt(a) or createFunction(a, None)
    if f is None:
        continue
    if name:
        try:
            f.setName(name, SourceType.IMPORTED)
            named += 1
        except Exception:
            pass
    if comment:
        setPlateComment(a, "RoConstruct: " + comment)
print("RoConstruct: %%d functions annotated, %%d renamed" %% (len(NAMES), named))
'''


def ghidra(client):
    names = ghidra_names(client)
    body = "{\n%s}" % "".join("    0x%s: (%r, %r),\n" % (a, n, c) for a, (n, c) in sorted(names.items()))
    path = ROOT / "work" / client / ("ghidra_%s.py" % client.replace("-", "_"))
    path.write_text(GHIDRA % {"client": client, "names": body})
    return path, len(names)
