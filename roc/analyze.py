"""Split a client exe into functions: work/<client>/functions.jsonl + meta.json.

Each row: addr, size, relocs (offsets of 4-byte fields the loader patches,
masked when diffing), calls (direct call count; 0 = leaf), call_targets/callers,
unit (RTTI class or seg_<64 KB block>).
"""
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

def find_functions(code, text_va, seeds, relocs, proven=(), keep=None):
    """Recursive descent from seeds over .text (code at text_va).
    New starts: direct call targets and `push/mov offset fn` immediates.
    Switch jump tables are followed so their case blocks count as reached.
    MSVC aligns functions to 16 after int3 padding, so aligned non-cc bytes
    after cc also seed (unless a jump table sits there).
    With `keep` (a set of trusted starts), a start that reached code falls into
    (no ret/jmp/call before it) or that a catch funclet returns to is an interior
    label, and is dropped unless it is a call target or in keep;
    trailing jump tables then no longer make a function "bad"."""
    end = text_va + len(code)
    reloc_set = set(relocs)
    rd = lambda va: int.from_bytes(code[va - text_va:va - text_va + 4], "little")
    pointed = set(seeds)  # entry + pointers from data: real starts even if a decode straddles them
    seeds = pointed | {text_va + i for i in range(16, len(code), 16)
                          if code[i - 1] == 0xCC and code[i] != 0xCC
                          and text_va + i not in reloc_set}
    starts = {s for s in seeds if text_va <= s < end}
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    seen, calls, work, falls, called, tables, conts = set(), set(), list(starts), set(), set(), set(), {}
    straddled, callbacks = set(), set()
    while work:
        a = work.pop()
        cont = None
        while text_va <= a < end and a not in seen:
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
                    callbacks.add(t)
                    work.append(t)
                    calls.add(a)
                    called.add(t)
            elif mnem.startswith(("j", "loop")):
                if op.startswith("0x"):
                    work.append(int(op, 16))
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
    # Proven extents (a compiled function matched these bytes exactly): no start
    # inside one, and whatever follows it starts a new function.
    for start, size in proven:
        starts -= {s for s in starts if start < s < start + size}
        starts.add(start)
        seen.add(start)
        if start + size < end and code[start + size - text_va] != 0xCC:
            starts.add(start + size)
            seen.add(start + size)
    order = sorted(s for s in starts if s in seen) + [end]
    call_sites = sorted(calls)
    tables = sorted(tables) if keep is not None else []
    out = []
    for start, nxt in zip(order, order[1:]):
        body = code[start - text_va:nxt - text_va].rstrip(b"\xcc")  # MSVC int3 padding
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
            "kind": "eh" if _catch_funclet(code, text_va, start, body, reloc_set, rd)
                    else kind_of(body[:code_len], [r for r in rel if r < code_len]),
        })
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

def binary_facts(pe, image, base, body, start, imports, local_targets=None):
    """Small structured clues from one function; bounded for prompt/index use."""
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    data_refs, strings, imported_names, external_calls, global_reads, global_writes = [], [], [], [], [], []
    virtual_slots, stack_args, branches, constants = [], [], 0, []
    this_reads, this_writes = [], []
    vtable_regs = set()
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
            (this_writes if insn.mnemonic == "mov" and text.startswith("mov") and text.split(",", 1)[0].endswith("]")
             else this_reads).append(offset)
        if insn.mnemonic.startswith(("j", "loop")):
            branches += 1
        mload = re.match(r"mov\s+(e[a-d]x|e[sd]i|e[bs]p),\s*dword ptr \[ecx\]", text)
        if mload:
            vtable_regs.add(mload.group(1))
        if insn.mnemonic in ("call", "jmp") and vtable_regs:
            m = re.search(r"\[(%s) \+ (0x[0-9a-f]+|\d+)\]" % "|".join(vtable_regs), text)
            if m:
                try:
                    virtual_slots.append(int(m.group(1), 0) // 4)
                except ValueError:
                    pass
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
            chunk = image[value - base:value - base + 128]
            match = PRINTABLE.search(chunk)
            if match:
                strings.append(match.group().decode("latin-1"))
        stack_args.extend(int(x, 0) for x in re.findall(r"\[esp \+ (0x[0-9a-f]+|\d+)\]", text))
        for raw in re.findall(r"(?<![+\w])-?\b\d+\b", text):
            try:
                n = int(raw)
                if n > 3:
                    constants.append(n)
            except ValueError:
                pass
    return {
        "imports": sorted(set(imported_names))[:12],
        "external_calls": sorted(set(external_calls))[:12],
        "strings": sorted(set(s for s in strings if len(s) >= 4))[:12],
        "data_refs": sorted(set(data_refs))[:16],
        "global_reads": sorted(set(global_reads))[:16],
        "global_writes": sorted(set(global_writes))[:16],
        "virtual_slots": sorted(set(virtual_slots))[:8],
        "stack_args": sorted(set(stack_args))[:8],
        "this_reads": sorted(set(this_reads))[:16],
        "this_writes": sorted(set(this_writes))[:16],
        "calling_convention": "callee" if any(i.mnemonic == "ret" and i.op_str.strip()
                                                 for i in md.disasm(body, start)) else "caller",
        "branches": branches,
        "constants": sorted(set(constants))[:16],
    }

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
    imports = {}
    for dll in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
        for item in dll.imports:
            if item.address and item.name:
                imports[item.address] = "%s!%s" % (dll.dll.decode("latin-1"), item.name.decode("latin-1"))
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
    funcs = find_functions(code, text_va, seeds, relocs, proven, keep)
    # Persist direct-call edges so source retrieval can use neighboring functions.
    by_addr = {int(f["addr"], 16): f for f in funcs}
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    for f in funcs:
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
        f.update(binary_facts(pe, image, base, body, start, imports, by_addr))
    classes = rtti_classes(read, relocs, in_text)
    assign_units(funcs, classes)
    siblings = {}
    for f in funcs:
        siblings.setdefault(f["unit"], []).append(f["addr"])
    sibling_index = {unit: {addr: i for i, addr in enumerate(peers)} for unit, peers in siblings.items()}
    for f in funcs:
        peers = siblings.get(f["unit"], [])
        index = sibling_index[f["unit"]][f["addr"]]
        f["siblings"] = peers[max(0, index - 2):index] + peers[index + 1:index + 3]
    # Functions found in the compiler's own prebuilt libraries (`roc mass`) are not Roblox code.
    libmatch = ROOT / "work" / client / "libmatch.json"
    if libmatch.exists():
        runtime = set(json.loads(libmatch.read_text()))
        for f in funcs:
            if f["addr"] in runtime:
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
