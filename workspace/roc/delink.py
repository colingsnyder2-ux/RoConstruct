"""Delink the original exe into one relocatable COFF object, so native objects can link
against the real 2008 code and data instead of an ABI-incompatible stand-in.

Link scaffolding only: the delinked object is original bytes and never a submission.
Every absolute pointer comes from the PE base-relocation table; IAT slots are rebound
to import libraries generated from the exe's own import directory.
"""
import argparse
import functools
import json
import re
import struct
from pathlib import Path

import capstone
import pefile

from roc import clients, rebuild

KEEP = ('.text', '.rdata', '.data', '.tls')
DIR32, REL32 = 0x06, 0x14
ALIGN_4096 = 0x00D00000
NRELOC_OVFL = 0x01000000
FLAGS = {'.text': 0x60000020, '.rdata': 0x40000040, '.data': 0xC0000040, '.tls': 0xC0000040}


class Coff:
    def __init__(self):
        self.sections, self.symbols, self.strings = [], [], bytearray()
        self.index, self.next = {}, 0  # next: raw symbol-table index, counting aux records

    def _name(self, name):
        raw = name.encode()
        if len(raw) <= 8:
            return raw.ljust(8, b'\0')
        offset = 4 + len(self.strings)
        self.strings += raw + b'\0'
        return struct.pack('<II', 0, offset)

    def section(self, name, data, flags):
        number = len(self.sections) + 1
        self.sections.append({'name': name, 'data': bytearray(data), 'flags': flags, 'relocs': []})
        self.index['$sec' + name] = self.next
        self.next += 2
        self.symbols.append((self._name(name), 0, number, 0, 3, number))
        return number

    def symbol(self, name, section=0, value=0, function=False):
        """External symbol; section 0 means undefined (resolved by another object or library)."""
        if name not in self.index:
            self.index[name] = self.next
            self.next += 1
            self.symbols.append((self._name(name), value, section, 0x20 if function else 0, 2, None))
        elif section:  # defined after an earlier reference in this object: upgrade that entry
            at = next(i for i, s in enumerate(self.symbols) if self._raw_index(i) == self.index[name])
            self.symbols[at] = (self.symbols[at][0], value, section, 0x20 if function else 0, 2, None)
        return self.index[name]

    def _raw_index(self, position):
        return sum(1 + (s[5] is not None) for s in self.symbols[:position])

    def write(self, path):
        nsym = sum(1 + (s[5] is not None) for s in self.symbols)
        pos = 20 + 40 * len(self.sections)
        headers, body = bytearray(), bytearray()
        for sec in self.sections:
            relocs = sec['relocs']
            ovfl = len(relocs) >= 0xFFFF
            table = bytearray()
            if ovfl:
                table += struct.pack('<IIH', len(relocs) + 1, 0, 0)
            for site, sym, kind in relocs:
                table += struct.pack('<IIH', site, sym, kind)
            data = bytes(sec['data'])
            raw_at, reloc_at = pos + len(body), pos + len(body) + len(data)
            body += data + table
            count = 0xFFFF if ovfl else len(relocs)
            flags = sec['flags'] | ALIGN_4096 | (NRELOC_OVFL if ovfl else 0)
            headers += struct.pack('<8sIIIIIIHHI', self._name(sec['name']), 0, 0, len(data), raw_at,
                                   reloc_at if relocs else 0, 0, count, 0, flags)
            sec['aux'] = (len(data), count)
        table = bytearray()
        for name, value, section, kind, cls, number in self.symbols:
            aux = number is not None
            table += struct.pack('<8sIhHBB', name, value, section, kind, cls, int(aux))
            if aux:
                length, count = self.sections[number - 1]['aux']
                table += struct.pack('<IHHIHB3x', length, count, 0, 0, number, 0)
        header = struct.pack('<HHIIIHH', 0x14C, len(self.sections), 0, pos + len(body), nsym, 0, 0)
        path.write_bytes(header + headers + body + table + struct.pack('<I', 4 + len(self.strings)) + self.strings)


def import_libs(pe, out, tc):
    """One import library per DLL from the exe's own import table; returns {iat_va: __imp_ symbol}."""
    base, slots = pe.OPTIONAL_HEADER.ImageBase, {}
    for entry in pe.DIRECTORY_ENTRY_IMPORT:
        dll = entry.dll.decode()
        stem = dll.rsplit('.', 1)[0]
        lines, names = ['LIBRARY "%s"' % dll, 'EXPORTS'], {}
        for imp in entry.imports:
            if imp.name:
                name = imp.name.decode()
                lines.append(name)
            else:
                name = 'roc_ord_%s_%d' % (stem, imp.ordinal)
                lines.append('%s @%d NONAME' % (name, imp.ordinal))
            names[imp.address] = name
        (out / (stem + '.def')).write_text('\n'.join(dict.fromkeys(lines)) + '\n')
        code, text = rebuild.run(tc, 'lib', ['/NOLOGO', '/MACHINE:X86', '/DEF:%s.def' % stem, '/OUT:%s.lib' % stem], out)
        if code:
            raise RuntimeError('lib %s: %s' % (dll, text))
        symbols = short_import_symbols((out / (stem + '.lib')).read_bytes())
        for va, name in names.items():
            slots[va] = '__imp_' + symbols[name]
    return slots


def short_import_symbols(lib):
    """{export name: public symbol} from the short-import members of a lib.exe import library."""
    found, pos = {}, 8
    while pos + 60 <= len(lib):
        size = int(lib[pos + 48:pos + 58])
        data = lib[pos + 60:pos + 60 + size]
        if data[:4] == b'\0\0\xff\xff':
            name_type = (struct.unpack_from('<H', data, 18)[0] >> 2) & 7
            symbol = data[20:].split(b'\0', 1)[0].decode()
            export = symbol
            if name_type in (2, 3) and export[:1] in '_@?':  # NOPREFIX / UNDECORATE
                export = export[1:]
            if name_type == 3:
                export = export.split('@', 1)[0]
            found[export] = symbol
            found[symbol] = symbol
            found.setdefault(symbol[1:] if symbol[:1] == '_' else symbol, symbol)  # ordinal entries
        pos += 60 + size + (size & 1)
    return found


@functools.lru_cache(maxsize=1)
def import_names():
    """{thunk symbol: (dll, export name or ordinal)} from the period import libraries."""
    tc = rebuild.toolchain()
    dirs = [d for d in (tc['vc_lib'], tc['atlmfc_lib'], tc['sdk_lib'], clients.ROOT / 'rebuild/2008-06/out/importlibs') if d]
    found = {}
    for d in dirs:
        for lib in Path(d).glob('*.lib'):
            data, pos = lib.read_bytes(), 8
            if data[:8] != b'!<arch>\n':
                continue
            while pos + 60 <= len(data):
                try:
                    size = int(data[pos + 48:pos + 58])
                except ValueError:
                    break
                member = data[pos + 60:pos + 60 + size]
                if member[:4] == b'\0\0\xff\xff' and struct.unpack_from('<H', member, 6)[0] == 0x14C:
                    hint, kind = struct.unpack_from('<HH', member, 16)
                    symbol, dll = member[20:].split(b'\0')[:2]
                    symbol, dll, name_type = symbol.decode('latin-1'), dll.decode('latin-1').lower(), (kind >> 2) & 7
                    export = symbol
                    if name_type == 0:
                        export = hint
                    elif name_type in (2, 3):
                        export = export[1:] if export[:1] in '?@_' else export
                        if name_type == 3:
                            export = export.split('@')[0]
                    found.setdefault(symbol, (dll, export))
                pos += 60 + size + (size & 1)
    return found


def write_res(pe, path):
    """The exe's resource tree as a .res file (type/name/language entries in order)."""
    out = bytearray(struct.pack('<II', 0, 32) + b'\xff\xff\0\0\xff\xff\0\0' + bytes(16))

    def ident(entry):
        if entry.name is not None:
            return str(entry.name).encode('utf-16-le') + b'\0\0'
        return struct.pack('<HH', 0xFFFF, entry.id)

    image = pe.get_memory_mapped_image()
    for kind in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        for name in kind.directory.entries:
            for lang in name.directory.entries:
                data = lang.data.struct
                blob = image[data.OffsetToData:data.OffsetToData + data.Size]
                head = ident(kind) + ident(name)
                head += b'\0' * (-(8 + len(head)) % 4)
                head += struct.pack('<IHHII', 0, 0x1030, lang.id, 0, 0)
                out += struct.pack('<II', len(blob), 8 + len(head)) + head + blob + b'\0' * (-len(blob) % 4)
    path.write_bytes(out)


def rel32_sites(code, start, target):
    """Offsets (from start) of rel32 operands of call/jmp/jcc whose destination is target."""
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    for ins in md.disasm(code, start):
        if ins.size >= 5 and ins.bytes[0] in (0xE8, 0xE9) or ins.size == 6 and ins.bytes[0] == 0x0F and 0x80 <= ins.bytes[1] <= 0x8F:
            if (ins.address + ins.size + struct.unpack_from('<i', ins.bytes, ins.size - 4)[0]) & 0xFFFFFFFF == target:
                yield ins.address + ins.size - 4 - start


def delink(client, out, swaps=(), exports=()):
    """Write orig.obj, import libs and orig.res into out; returns a receipt dict.

    swaps: (va, symbol) pairs. References to va become references to the external symbol.
    exports: (va, symbol) pairs defined in orig.obj so native code can call original functions.
    """
    out.mkdir(parents=True, exist_ok=True)
    tc = rebuild.toolchain()
    pe = pefile.PE(str(clients.exe_path(client, clients.load()[client])))
    base = pe.OPTIONAL_HEADER.ImageBase
    image = pe.get_memory_mapped_image()
    sections = {s.Name.rstrip(b'\0').decode(): s for s in pe.sections}
    spans = [(n, base + sections[n].VirtualAddress, sections[n].Misc_VirtualSize) for n in KEEP]
    iat = pe.OPTIONAL_HEADER.DATA_DIRECTORY[12]
    iat_lo, iat_hi = base + iat.VirtualAddress, base + iat.VirtualAddress + iat.Size
    slots = import_libs(pe, out, tc)
    (out / 'slots.json').write_text(json.dumps({'%08x' % va: s for va, s in sorted(slots.items())}, indent=0))

    coff = Coff()
    numbers = {}
    for name, va, size in spans:
        rva = va - base
        numbers[name] = coff.section(name, image[rva:rva + size], FLAGS[name])

    def locate(va):
        for name, lo, size in spans:
            if lo <= va < lo + size:
                return name, va - lo
        return None, None

    swapped = {va: symbol for va, symbol in swaps}
    bad_exports = []
    for va, symbol in exports:
        name, offset = locate(va)
        if name is None:  # one-past-the-end of a section, as the reloc pass allows
            name, offset = locate(va - 1)
            offset = None if name is None else offset + 1
        if name is None:
            bad_exports.append('%08x %s' % (va, symbol))
            continue
        coff.symbol(symbol, numbers[name], offset, function=name == '.text')
    entry = base + pe.OPTIONAL_HEADER.AddressOfEntryPoint
    coff.symbol('_roc_entry', numbers['.text'], locate(entry)[1], function=True)
    tls = pe.OPTIONAL_HEADER.DATA_DIRECTORY[9]
    name, offset = locate(base + tls.VirtualAddress)
    coff.symbol('__tls_used', numbers[name], offset)

    stats = {'bad_exports': bad_exports, 'dir32_section': 0, 'dir32_import': 0, 'dir32_image_base': 0, 'dir32_swap': 0, 'rel32_swap': 0,
             'unresolved': []}
    for block in pe.DIRECTORY_ENTRY_BASERELOC:
        for entry_ in block.entries:
            if entry_.type != 3:
                continue
            site = base + entry_.rva
            home, at = locate(site)
            if home is None:
                continue
            sec = coff.sections[numbers[home] - 1]
            value = struct.unpack_from('<I', sec['data'], at)[0]
            if value in swapped:
                sym, addend = coff.symbol(swapped[value]), 0
                stats['dir32_swap'] += 1
            elif iat_lo <= value < iat_hi and value in slots:
                sym, addend = coff.symbol(slots[value]), 0
                stats['dir32_import'] += 1
            elif base <= value < base + 0x1000:
                sym, addend = coff.symbol('___ImageBase'), value - base
                stats['dir32_image_base'] += 1
            else:
                target, addend = locate(value)
                if target is None and value - 1 >= base:
                    target, addend = locate(value - 1)  # one-past-the-end pointers
                    addend = None if target is None else addend + 1
                if target is None:
                    stats['unresolved'].append('%08x -> %08x' % (site, value))
                    continue
                sym = coff.index['$sec' + target]
                stats['dir32_section'] += 1
            struct.pack_into('<I', sec['data'], at, addend)
            sec['relocs'].append((at, sym, DIR32))

    if swapped:
        text = coff.sections[numbers['.text'] - 1]
        text_va = spans[0][1]
        rows = [json.loads(line) for line in open(clients.ROOT / 'work' / client / 'functions.jsonl')]
        for row in rows:
            hits = set(row.get('call_targets', [])) & {'%08x' % va for va in swapped}
            for hit in hits:
                start = int(row['addr'], 16)
                code = bytes(text['data'][start - text_va:start - text_va + row['size']])
                for off in rel32_sites(code, start, int(hit, 16)):
                    at = start - text_va + off
                    struct.pack_into('<i', text['data'], at, 0)  # link computes S - (P+4) + stored addend
                    text['relocs'].append((at, coff.symbol(swapped[int(hit, 16)]), REL32))
                    stats['rel32_swap'] += 1
    coff.write(out / 'orig.obj')
    write_res(pe, out / 'orig.res')
    o = pe.OPTIONAL_HEADER
    stats['link'] = ['/STACK:%d,%d' % (o.SizeOfStackReserve, o.SizeOfStackCommit),
                     '/HEAP:%d,%d' % (o.SizeOfHeapReserve, o.SizeOfHeapCommit),
                     '/BASE:0x%x' % base, '/SUBSYSTEM:WINDOWS,%d.%02d' % (o.MajorSubsystemVersion, o.MinorSubsystemVersion)]
    stats['libs'] = sorted(p.name for p in out.glob('*.lib'))
    return stats


def bind_objects(client, objects, candidates, slots, outdir):
    """Swap plan for native objects against candidate target addresses.

    Every function body in the objects is compared with every same-size candidate. A body
    relocation-masked exact against one candidate is swapped in; a body exact against
    several is taken only where its external references agree with addresses already
    proven by other swapped bodies, and that leaves exactly one candidate. Every reference
    a swapped body makes, other than to another swapped body or into its own slice, is
    bound to its original address, read from the target bytes at the same reloc offset
    (DIR32 value or rel32 destination), so nothing is guessed. External symbols keep their
    names unless two bodies bind one name to different addresses; statics, conflicts and
    section-relative references become $roc_va_<address>. Each object with swaps yields
    outdir/<stem>.swap.obj holding only the swapped slices.
    """
    from collections import defaultdict
    from roc import match
    targets = {}
    for va in candidates:
        try:
            targets[va] = match.target(client, '%08x' % va)
        except (SystemExit, match.CompileError):
            pass
    # A compiled body also carries its catch funclets, which the analysis may list as separate
    # adjacent 'eh' rows: offer function + following eh rows as one merged target as well.
    rows = match._functions(client)
    order = sorted(rows)
    position = {a: i for i, a in enumerate(order)}
    variants = {va: [targets[va]] for va in targets}
    for va in targets:
        code, relocs, _ = targets[va]
        i, end = position['%08x' % va], va + len(code)
        while i + 1 < len(order) and rows[order[i + 1]].get('kind') == 'eh' and int(order[i + 1], 16) == end:
            extra, extra_relocs, _ = match.target(client, order[i + 1])
            code, relocs = code + extra, list(relocs) + [end - va + r for r in extra_relocs]
            end += len(extra)
            variants[va].append((code, relocs, None))
            i += 1
    by_size, form_code = defaultdict(list), {}
    for va, forms in variants.items():
        for form in forms:
            by_size[len(form[0])].append((va, form))
            form_code[va, len(form[0])] = form[0]
    plan = dict(swaps=[], exports=[], alternate={}, objects=[], ambiguous=[], problems=[])

    def references(obj, va, name, size):
        """[(offset in slice, reloc kind, symbol index, original address)] of one body."""
        data, secs, syms = obj['data'], obj['secs'], obj['syms']
        value, sec = obj['defined'][name]
        rawptr, relptr, nrel = secs[sec][4], secs[sec][5], secs[sec][7]
        code, out = form_code[va, size], []
        for k in range(nrel):
            off, index, kind = struct.unpack_from('<IIH', data, relptr + 10 * k)
            if value <= off < value + size:
                at = off - value
                if kind == DIR32:
                    orig = struct.unpack_from('<I', code, at)[0]
                elif kind == REL32:
                    orig = (va + at + 4 + struct.unpack_from('<i', code, at)[0]) & 0xFFFFFFFF
                else:
                    orig = None
                out.append((at, kind, index, orig))
        return out

    def named(obj, index):
        """External symbol bound by name (not a static, section or import)."""
        symbol, _, secnum, _ = obj['syms'][index]
        return not symbol.startswith(('.', '__imp_')) and (secnum == 0 or obj['storage'][index] == 2)

    objs, pending, known, taken, names = [], [], {}, set(), set()
    for path in objects:
        data = Path(path).read_bytes()
        secs, syms, defined, _ = match._coff_data_index(data)
        symptr = struct.unpack_from('<I', data, 8)[0]
        obj = dict(path=Path(path), data=data, secs=secs, syms=syms, defined=defined, picks=[], rename={},
                   storage={i: data[symptr + 18 * i + 16] for i in syms})
        found = False
        for name, body, relocs in match.coff_functions(data):
            if name in defined:
                # also require the same relocated fields: a source that hard-codes an original
                # address as an integer matches the masked bytes but breaks once data moves
                hits = [va for va, form in by_size[len(body)]
                        if set(form[1]) <= set(relocs) and match.exact_match(form[0], form[1], body, relocs)]
                if hits:
                    pending.append((obj, name, len(body), hits))
                    found = True
        if found:  # objects with no candidate body are dropped (whole-exe runs read 20k+)
            objs.append(obj)
    # an absolute (DIR32) native field must be an absolute field of the original too: where the
    # original holds a plain constant there, the native body is not the same code
    form_relocs = {(va, len(form[0])): set(form[1]) for va, forms in variants.items() for form in forms}
    pending = [(obj, name, size, [va for va in hits
                                  if all(kind != DIR32 or at in form_relocs[va, size]
                                         for at, kind, _, _ in references(obj, va, name, size))])
               for obj, name, size, hits in pending]
    pending = [p for p in pending if p[3]]

    def bases(obj, va, name, size):
        out = {}
        for at, kind, index, orig in references(obj, va, name, size):
            if orig is not None and named(obj, index):
                stored = struct.unpack_from('<i', obj['data'], obj['secs'][obj['defined'][name][1]][4] + obj['defined'][name][0] + at)[0]
                out[obj['syms'][index][0]] = (orig - stored) & 0xFFFFFFFF
        return out

    image_base, image = match._image(client)
    imports = import_names()
    pe = pefile.PE(str(clients.exe_path(client, clients.load()[client])))
    by_slot = {imp.address: (entry.dll.decode().lower(), imp.name.decode() if imp.name else imp.ordinal)
               for entry in pe.DIRECTORY_ENTRY_IMPORT for imp in entry.imports}

    def import_of(va):
        """(dll, export name or ordinal) of an IAT slot, or of a jmp [slot] thunk, at an original address."""
        rva = va - image_base
        if va not in by_slot and 0 <= rva < len(image) - 6 and image[rva:rva + 2] == b'\xff\x25':
            va = struct.unpack_from('<I', image, rva + 2)[0]
        return by_slot.get(va)

    def agree(obj, index, stored, orig, depth=0):
        """Evidence that native symbol index (plus stored addend) is the original at orig:
        True agrees, False contradicts, None says nothing. Imports compare by DLL export;
        native data compares bytes, relocations followed recursively."""
        symbol, svalue, secnum, _ = obj['syms'][index]
        if symbol.startswith('__imp_') or secnum == 0:
            native = imports.get(symbol[len('__imp_'):] if symbol.startswith('__imp_') else symbol)
            original = import_of(orig)
            if native and original:
                return native == original
            return None
        secs, data = obj['secs'], obj['data']
        if secs[secnum - 1][9] & 0x20 or depth > 3:
            return None
        start = svalue + stored
        rawsize, rawptr, relptr, nrel = secs[secnum - 1][3], secs[secnum - 1][4], secs[secnum - 1][5], secs[secnum - 1][7]
        later = [v for s, v, n, _ in obj['syms'].values() if n == secnum and v > start]
        end = min(later + [rawsize])
        rva = orig - image_base
        native, original = data[rawptr + start:rawptr + end], bytes(image[rva:rva + end - start])
        if len(native) != len(original):
            return False
        mask, verdict = set(), True
        for k in range(nrel):
            off, inner, _ = struct.unpack_from('<IIH', data, relptr + 10 * k)
            if start <= off < end:
                mask.update(range(off - start, off - start + 4))
                deeper = agree(obj, inner, struct.unpack_from('<i', data, rawptr + off)[0],
                               struct.unpack_from('<I', original, off - start)[0], depth + 1)
                if deeper is False:
                    return False
        if not all(i in mask or a == b for i, (a, b) in enumerate(zip(native, original))):
            return False
        return verdict

    def data_agreement(obj, va, name, size):
        """True if every reference with evidence agrees, False if any contradicts, None if
        no reference carries evidence."""
        value, sec = obj['defined'][name]
        verdict = None
        for at, kind, index, orig in references(obj, va, name, size):
            if orig is None or obj['syms'][index][0] in names:
                continue
            stored = struct.unpack_from('<i', obj['data'], obj['secs'][sec][4] + value + at)[0]
            if kind == REL32:
                stored = 0
            result = agree(obj, index, stored, orig)
            if result is False:
                return False
            if result:
                verdict = True
        return verdict

    picked, owner = set(), {}  # owner: swapped symbol -> the original address it replaces
    imported = {s[len('__imp_'):] for s in slots.values()} | {s for s in imports}  # thunk names import libs define
    progress = True
    while progress:
        progress, rest = False, []
        for obj, name, size, hits in pending:
            free = [va for va in hits if va not in taken]
            if (id(obj), name) in picked or not free:
                continue
            stem = obj['path'].stem
            if len(free) > 1 and re.fullmatch('[0-9a-f]{8}', stem) and int(stem, 16) in free:
                free = [int(stem, 16)]  # a source stored for that very address
            if len(free) > 1:  # keep only candidates consistent with proven addresses and data
                scored = []
                for va in free:
                    b = bases(obj, va, name, size)
                    evidence = data_agreement(obj, va, name, size)
                    if all(known.get(s, v) == v for s, v in b.items()) and evidence is not False:
                        scored.append((va, any(s in known for s in b) or evidence is True))
                free = [va for va, evidence in scored if evidence]
            if len(free) == 1:
                va = free[0]
                taken.add(va)
                # an earlier object owns this name, or an import library defines it as a thunk
                # (the exe's own inline copy of a DLL export): keep this body under a unique name
                if name in names or name in imported:
                    obj['rename'][name] = '%s$roc_%08x' % (name, va)
                names.add(obj['rename'].get(name, name))
                owner[obj['rename'].get(name, name)] = va
                picked.add((id(obj), name))
                obj['picks'].append((va, name, size))
                for s, b in bases(obj, va, name, size).items():
                    known.setdefault(s, b)
                progress = True
            else:
                rest.append((obj, name, size, hits))
        pending = rest
    plan['ambiguous'] = ['%s %s: %s' % (o['path'].name, n, ' '.join('%08x' % h for h in hs if h not in taken))
                         for o, n, _, hs in pending if n not in names and any(h not in taken for h in hs)]

    exports, alternate, problems = {}, plan['alternate'], plan['problems']
    for number_, obj in enumerate(objs):
        if not obj['picks']:
            continue
        coff = Coff()
        for va, name, size in obj['picks']:
            value, sec = obj['defined'][name]
            rawptr, flags = obj['secs'][sec][4], obj['secs'][sec][9]
            slice_ = bytearray(obj['data'][rawptr + value:rawptr + value + size])
            number = coff.section('.text', b'', flags & ~0x00F01000)
            section_symbol = coff.next - 2
            coff.symbol(obj['rename'].get(name, name), number, 0, function=True)
            relocs = coff.sections[number - 1]['relocs']
            for at, kind, index, orig in references(obj, va, name, size):
                symbol, svalue, secnum, _ = obj['syms'][index]
                stored = struct.unpack_from('<i', slice_, at)[0]
                local_name = obj['rename'].get(symbol, symbol) if secnum > 0 else symbol
                if local_name in names and orig is not None and (orig - (stored if kind == DIR32 else 0)) & 0xFFFFFFFF == owner[local_name]:
                    relocs.append((at, coff.symbol(local_name), kind))  # another swapped body, proven by address
                    continue
                if secnum - 1 == sec and kind == DIR32 and value <= svalue + stored < value + size:
                    struct.pack_into('<i', slice_, at, svalue + stored - value)  # into its own slice
                    relocs.append((at, section_symbol, DIR32))
                    continue
                if orig is None:
                    problems.append('%s+%x: reloc type %x' % (name, at, kind))
                    continue
                if kind == DIR32 and '%08x' % orig in slots and not symbol.startswith('__imp_'):
                    # an original IAT slot under another native name: orig.obj's IAT copy is never
                    # filled by the loader, so bind to the slot's import symbol instead
                    struct.pack_into('<i', slice_, at, 0)
                    relocs.append((at, coff.symbol(slots['%08x' % orig]), kind))
                    continue
                if symbol.startswith('__imp_'):
                    want = slots.get('%08x' % orig)  # the slot's own import symbol, whatever the native name
                    if want is None:
                        problems.append('%s+%x: %s is not an import slot (%08x)' % (name, at, symbol, orig))
                        continue
                    relocs.append((at, coff.symbol(want), kind))
                    continue
                base = (orig - stored) & 0xFFFFFFFF
                if named(obj, index) and symbol not in imported and symbol not in names and exports.setdefault(symbol, base) == base:
                    relocs.append((at, coff.symbol(symbol), kind))
                else:  # static, section-relative or conflicting name: the exact original address
                    alias = '$roc_va_%08x' % orig
                    exports[alias] = orig
                    struct.pack_into('<i', slice_, at, 0)
                    relocs.append((at, coff.symbol(alias), kind))
            coff.sections[number - 1]['data'] = slice_
            plan['swaps'].append((va, obj['rename'].get(name, name)))
        # sources from different folders share stems (verified_0001.obj): keep each output distinct
        trimmed = Path(outdir) / ('%04d_%s.swap.obj' % (number_, obj['path'].stem))
        coff.write(trimmed)
        plan['objects'].append(str(trimmed))
        plan.setdefault('sources', []).append(str(obj['path']))
    linker_defined = {'___ImageBase'}
    plan['exports'] = sorted((v, s) for s, v in exports.items() if s not in names and s not in linker_defined)
    return plan


def link(out, objects=(), name='hybrid.exe', extra=()):
    receipt = json.loads((out / 'delink.json').read_text())
    args = ['/NOLOGO', '/MACHINE:X86', '/OUT:' + name, '/MAP', '/ENTRY:roc_entry', '/NODEFAULTLIB',
            '/SAFESEH:NO', '/DYNAMICBASE:NO', '/FIXED:NO', '/NXCOMPAT:NO', '/TSAWARE', '/INCREMENTAL:NO',
            '/OPT:NOREF', '/OPT:NOICF', '/MANIFEST:NO', *receipt['link'], 'orig.obj', 'orig.res',
            *[str(Path(o).resolve()) for o in objects], *receipt['libs'], *extra]
    (Path(out) / 'link.rsp').write_text('\n'.join('"%s"' % a if ' ' in a else a for a in args[2:]) + '\n')
    return rebuild.run(rebuild.toolchain(), 'link', args[:2] + ['@link.rsp'], out)  # 20k objects overflow the command line


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('client')
    p.add_argument('out', type=Path)
    p.add_argument('--swap', action='append', default=[], help='VA=SYMBOL: redirect references to a native symbol')
    p.add_argument('--export', action='append', default=[], help='VA=SYMBOL: define an original function symbol')
    p.add_argument('--link', nargs='*', help='link orig.obj plus these native objects into hybrid.exe')
    a = p.parse_args()
    pairs = lambda xs: [(int(x.split('=', 1)[0], 16), x.split('=', 1)[1]) for x in xs]
    stats = delink(a.client, a.out, pairs(a.swap), pairs(a.export))
    (a.out / 'delink.json').write_text(json.dumps(stats, indent=1))
    print({k: (len(v) if isinstance(v, list) else v) for k, v in stats.items()})
    if a.link is not None:
        code, text = link(a.out, a.link)
        print(text[-3000:] or 'link ok')
        raise SystemExit(code)


if __name__ == '__main__':
    main()
