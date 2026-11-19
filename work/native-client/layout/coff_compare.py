"""Bounded x86 COFF comparison; unsupported formats fail closed."""
import hashlib
import struct
from collections import Counter
from pathlib import Path


def digest(data):
    return hashlib.sha256(data).hexdigest()


def parse(path):
    data = Path(path).read_bytes()

    def block(at, size):
        if at < 0 or size < 0 or at + size > len(data):
            raise ValueError('COFF range outside file')
        return data[at:at + size]

    machine, count, stamp, symptr, nsyms, optional, flags = struct.unpack('<HHIIIHH', block(0, 20))
    if machine != 0x14c or optional or not symptr:
        raise ValueError('expected ordinary x86 COFF object with symbols')
    stroff = symptr + nsyms * 18
    strlen = struct.unpack('<I', block(stroff, 4))[0]
    strings = block(stroff, strlen)

    def string(at):
        if not 4 <= at < len(strings):
            raise ValueError('bad COFF string offset')
        return strings[at:strings.index(b'\0', at)].decode('cp1252')

    def name(raw):
        return string(struct.unpack_from('<I', raw, 4)[0]) if raw[:4] == b'\0' * 4 else raw.rstrip(b'\0').decode('cp1252')

    sections = []
    for i in range(count):
        raw = block(20 + i * 40, 40)
        secname = raw[:8].rstrip(b'\0').decode('ascii')
        if secname.startswith('/'):
            secname = string(int(secname[1:]))
        virtualsize, va, size, ptr, relptr, lineptr, nrel, nline, chars = struct.unpack_from('<IIIIIIHHI', raw, 8)
        if chars & 0x1000000:
            raise ValueError('extended relocation counts unsupported')
        if size and not ptr and (not chars & 0x80 or chars & 0x60):
            raise ValueError('initialized COFF section has no raw data')
        payload = block(ptr, size) if ptr else b'\0' * size
        refs = [struct.unpack('<IIH', block(relptr + j * 10, 10)) for j in range(nrel)]
        sections.append({'name': secname, 'size': size, 'chars': chars, 'data': payload,
                         'relocations_raw': refs, 'virtualsize': virtualsize, 'va': va})
    symbols, indices, i = [], {}, 0
    while i < nsyms:
        raw = block(symptr + i * 18, 18)
        value, sec, typ, storage, aux = struct.unpack_from('<IhHBB', raw, 8)
        if i + aux >= nsyms:
            raise ValueError('COFF auxiliary symbols exceed table')
        symbol = {'name': name(raw[:8]), 'value': value, 'section': sec, 'type': typ,
                  'storage': storage, 'aux': block(symptr + (i + 1) * 18, aux * 18).hex()}
        indices[i] = symbol
        symbols.append(symbol)
        i += 1 + aux
    for section in sections:
        refs = []
        for off, idx, kind in section.pop('relocations_raw'):
            if idx not in indices:
                raise ValueError('relocation points at missing/auxiliary symbol')
            refs.append((off, indices[idx]['name'], kind))
        section['relocations'] = refs
    return {'sections': sections, 'symbols': symbols, 'sha256': digest(data)}


def strict(obj):
    return {'sections': [{**s, 'data': s['data'].hex()} for s in obj['sections']],
            'symbols': obj['symbols']}


def tu_signature(obj):
    # Discardable, non-executable debug records can contain the build path.
    sections = [s for s in obj['sections'] if not (
        s['name'].startswith('.debug') and s['chars'] & 0x02000000 and not s['chars'] & (0x20000000 | 0x20))]
    # An excluded section's own section symbol carries its length/checksum in aux: path-dependent too.
    skipped = {i + 1 for i, s in enumerate(obj['sections']) if not any(s is kept for kept in sections)}
    symbols = [{**s, 'aux': ''} if s['storage'] == 3 and s['section'] in skipped and s['name'].startswith('.debug')
               else s for s in obj['symbols']]
    return {'sections': [{**s, 'data': s['data'].hex()} for s in sections], 'symbols': symbols}


def defined(obj):
    result = []
    # Symbol extents are bounded by the next symbol or the containing section.
    # COFF function auxiliary records carry exact function size when present.
    for symbol in obj['symbols']:
        secnum = symbol['section']
        if symbol['storage'] == 2 and (secnum == -1 or (secnum == 0 and symbol['value'])):
            result.append({'name': symbol['name'], 'external': True,
                           'section': 'absolute' if secnum == -1 else 'common',
                           'data': struct.pack('<I', symbol['value']).hex(),
                           'refs': [], 'type': symbol['type']})
            continue
        if secnum <= 0 or symbol['storage'] not in (2, 3):
            continue
        section = obj['sections'][secnum - 1]
        if symbol['name'] == section['name'] and symbol['storage'] == 3 and symbol['aux']:
            continue
        if section['name'].startswith(('.debug', '.drectve')):
            continue
        start = symbol['value']
        ends = [s['value'] for s in obj['symbols'] if s['section'] == secnum and s['value'] > start]
        end = min(ends, default=section['size'])
        if symbol['type'] & 0x20 and symbol['aux']:
            aux = bytes.fromhex(symbol['aux'])
            length = struct.unpack_from('<I', aux, 4)[0]
            if length:
                end = start + length
        if not 0 <= start <= end <= section['size']:
            raise ValueError('invalid symbol extent: ' + symbol['name'])
        body = bytearray(section['data'][start:end])
        refs = []
        for off, target, kind in section['relocations']:
            if not start <= off < end:
                continue
            # Keep encoded addends: equal bytes + symbolic targets are stricter than masking.
            refs.append((off - start, target, kind))
        result.append({'name': symbol['name'], 'external': symbol['storage'] == 2,
                       'section': section['name'], 'data': bytes(body).hex(), 'refs': refs,
                       'type': symbol['type']})
    return result


def compare_merge(before, after, dedupe=False):
    left = [s for obj in before for s in defined(obj)]
    right = [s for obj in after for s in defined(obj)]
    # Local names can change, but only where each body uniquely establishes identity.
    def bodykey(s):
        return s['section'], s['type'], s['data']
    lnames, rnames = {}, {}
    for rows, names in ((left, lnames), (right, rnames)):
        for s in rows:
            if not s['external'] or '?A0x' in s['name']:
                names.setdefault(bodykey(s), set()).add(s['name'])
    mapping, lmapping = {}, {}
    locals_ = {n for names in (lnames, rnames) for group in names.values() for n in group}

    def shape(s):   # relocations with local targets blanked: what a body does besides its bytes
        return tuple((at, '<local>' if n in locals_ else n, kind) for at, n, kind in s['refs'])
    shapes = {}
    for s in left + right:
        shapes.setdefault(bodykey(s), set()).add(shape(s))
    for key in lnames.keys() | rnames.keys():
        old, new = lnames.get(key, set()), rnames.get(key, set())
        if old == new:
            continue
        if dedupe:
            # Names present on both sides already pair up (an unwind funclet is named after its
            # function); only the leftovers need pairing. Unpaired leftovers are not guessed at:
            # they stay as they are and the symbol comparison below reports them.
            old, new = old - new, new - old
            if not old or not new or (len(old) != 1 or len(new) != 1) and len(shapes[key]) != 1:
                continue
        if len(old) == 1 and len(new) == 1:
            mapping[next(iter(new))] = next(iter(old))
        elif dedupe and old and new and len(shapes[key]) == 1:
            # Several locals with the same bytes and the same relocations (two pieces' own copy of
            # one helper, per-unit anonymous-namespace names): interchangeable, so one shared name.
            token = 'local:' + digest(repr(key).encode())[:16]
            lmapping.update(dict.fromkeys(old, token))
            mapping.update(dict.fromkeys(new, token))
        else:
            return {'passed': False, 'reason': 'ambiguous local symbol body', 'before': sorted(old), 'after': sorted(new)}

    def canonical(s, rename):
        name = rename.get(s['name'], s['name'])
        refs = tuple((at, rename.get(n, n), kind) for at, n, kind in s['refs'])
        return name, s['external'], s['section'], s['type'], s['data'], refs
    old = [canonical(s, lmapping) for s in left]
    new = [canonical(s, mapping) for s in right]
    if dedupe:   # byte-identical COMDAT copies in several units fold to one at link
        old, new = set(old), set(new)
    old, new = Counter(old), Counter(new)
    return {'passed': old == new, 'before_symbols': len(left), 'after_symbols': len(right),
            'renamed_locals': mapping,
            'removed_or_changed': [s[0] for s in (old - new)],
            'added_or_changed': [s[0] for s in (new - old)],
            'limitations': ['Ambiguous extents/local identities fail rather than guess.',
                            'Full-link address and initializer proof is also mandatory.']}


def compare_images(before, after):
    import pefile
    old, new = pefile.PE(str(before)), pefile.PE(str(after))
    # Identical loaded sections prove unchanged initializer pointers and code/data addresses.
    def sections(pe):
        return [(s.Name, s.VirtualAddress, s.Misc_VirtualSize, s.Characteristics,
                 s.get_data()) for s in pe.sections if s.Characteristics & 0xe0000000]
    return old.OPTIONAL_HEADER.ImageBase == new.OPTIONAL_HEADER.ImageBase and sections(old) == sections(new)
