"""Select link providers only when their cached native object proves target body exact."""
import argparse
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path[:0] = [str(ROOT), str(HERE)]
from roc.native_bulk import Targets
from roc import match, rebuild
import native_template_probe as probe


def provider_source(stem):
    """Native class source, or an explicitly inventoried local vendor wrapper."""
    native = ROOT / 'rebuild/2008-06/native-classes' / (stem + '.cpp')
    local = HERE / (stem + '.cpp')
    return native if native.is_file() else local if local.is_file() else None


def mfc_ordinal_bindings(receipt):
    """Verify MFC ordinal names and FF25 thunks directly before using them as identities."""
    from roc import standins
    definition = ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def'
    ordinals = {}
    for name, number in re.findall(r'^\s*(\?\S+)\s+@\s*(\d+)\s+NONAME\b',
                                   definition.read_text(errors='replace'), re.M | re.I):
        ordinals.setdefault(int(number), set()).add(name)
    imports = standins._imports('2008-06')
    base, image = match._image('2008-06')
    starts = set(match._functions('2008-06'))
    out = {}
    for row in receipt.get('rows', []):
        if row.get('dll', '').lower() != 'mfc90.dll':
            continue
        symbol, ordinal = row.get('symbol'), row.get('ordinal')
        try:
            slot, thunk = int(row['iat_address'], 16), int(row['address'], 16)
        except (KeyError, TypeError, ValueError):
            raise ValueError('invalid MFC ordinal identity')
        if (ordinals.get(ordinal) != {symbol} or
                imports.get(slot, '').lower() != f'mfc90.dll!#{ordinal}' or
                f'{thunk:08x}' not in starts or
                thunk < base or bytes(image[thunk - base:thunk - base + 6]) != b'\xff\x25' + struct.pack('<I', slot)):
            raise ValueError('MFC ordinal identity does not match original inputs: ' + str(symbol))
        if symbol in out and out[symbol] != f'{thunk:08x}':
            raise ValueError('ambiguous MFC ordinal identity: ' + symbol)
        out[symbol] = f'{thunk:08x}'
    return out


def live_definitions(raw):
    """External definitions in sections linker will retain after strip_symbols."""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', raw, 0)
    strtab = symptr + nsym * 18
    flags = {sec: struct.unpack_from('<I', raw, 20 + optsz + 40 * (sec - 1) + 36)[0]
             for sec in range(1, nsec + 1)}
    out, index = set(), 0
    while index < nsym:
        name, _, sec, _, cls, aux = struct.unpack_from('<8sIhHBB', raw, symptr + index * 18)
        if name[:4] == b'\0\0\0\0':
            at = strtab + struct.unpack_from('<I', name, 4)[0]
            name = raw[at:raw.index(b'\0', at)]
        else:
            name = name.rstrip(b'\0')
        if cls == 2 and sec > 0 and not flags[sec] & 0x800:
            out.add(name.decode('latin-1'))
        index += 1 + aux
    return out


def prune_unused_comdat_data(raw, roots=()):
    """Drop data COMDATs unreachable from retained sections; never drop code."""
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', raw, 0)
    sections = [struct.unpack_from('<8sIIIIIIHHI', raw, 20 + optsz + 40 * index) for index in range(nsec)]
    targets, index = {}, 0
    root_names = set(roots)
    root_sections = set()
    strtab = symptr + nsym * 18
    while index < nsym:
        name, _, sec, _, cls, aux = struct.unpack_from('<8sIhHBB', raw, symptr + index * 18)
        targets[index] = sec
        if cls == 2 and sec > 0:
            if name[:4] == b'\0\0\0\0':
                at = strtab + struct.unpack_from('<I', name, 4)[0]
                name = raw[at:raw.index(b'\0', at)]
            else:
                name = name.rstrip(b'\0')
            if name.decode('latin-1') in root_names:
                root_sections.add(sec)
        index += 1 + aux
    candidates = {index + 1 for index, section in enumerate(sections)
                  if section[9] & 0x1000 and not section[9] & (0x20 | 0x800)
                  and not section[0].startswith((b'.CRT', b'.tls'))}
    live = {index + 1 for index, section in enumerate(sections)
            if not section[9] & 0x800 and index + 1 not in candidates}
    live |= root_sections
    edges = {index: {targets.get(struct.unpack_from('<I', raw, section[5] + rel * 10 + 4)[0], 0)
                     for rel in range(section[7])}
             for index, section in enumerate(sections, 1)}
    index = 0
    while index < nsym:
        _, value, sec, _, cls, aux = struct.unpack_from('<8sIhHBB', raw, symptr + index * 18)
        if cls == 3 and aux and sec > 0 and value == 0:
            parent, selection = struct.unpack_from('<HB', raw, symptr + 18 * (index + 1) + 12)
            if selection == 5:
                edges.setdefault(parent, set()).add(sec)
        index += 1 + aux
    pending = list(live)
    while pending:
        for target in edges.get(pending.pop(), ()):
            if target > 0 and target not in live and not sections[target - 1][9] & 0x800:
                live.add(target)
                pending.append(target)
    drop, index = set(), 0
    strtab = symptr + nsym * 18
    while index < nsym:
        name, _, sec, _, cls, aux = struct.unpack_from('<8sIhHBB', raw, symptr + index * 18)
        if name[:4] == b'\0\0\0\0':
            at = strtab + struct.unpack_from('<I', name, 4)[0]
            name = raw[at:raw.index(b'\0', at)]
        else:
            name = name.rstrip(b'\0')
        if cls == 2 and sec in candidates - live:
            drop.add(name.decode('latin-1'))
        index += 1 + aux
    return rebuild.strip_symbols(raw, drop=drop) if drop else raw


def prune_orphan_initializers(raw):
    """Remove isolated compiler initializers only when no live non-debug section references them."""
    raw = bytearray(raw)
    _, count, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', raw, 0)
    sections = [struct.unpack_from('<8sIIIIIIHHI', raw, 20 + optsz + 40 * i) for i in range(count)]
    targets, initializers, index = {}, set(), 0
    strtab = symptr + nsym * 18
    while index < nsym:
        name, _, sec, _, cls, aux = struct.unpack_from('<8sIhHBB', raw, symptr + index * 18)
        targets[index] = sec
        if name[:4] == b'\0\0\0\0':
            start = strtab + struct.unpack_from('<I', name, 4)[0]
            name = bytes(raw[start:raw.index(0, start)])
        else:
            name = name.rstrip(b'\0')
        if sec > 0 and cls == 3 and name.startswith(b'??__E') and sections[sec - 1][0].startswith(b'.text$yc'):
            initializers.add(sec)
        index += 1 + aux
    incoming = {sec: set() for sec in initializers}
    for sec, section in enumerate(sections, 1):
        if section[9] & 0x800:
            continue
        for i in range(section[7]):
            target = targets.get(struct.unpack_from('<I', raw, section[5] + 10 * i + 4)[0])
            if target in incoming and target != sec:
                incoming[target].add(sec)
    remove = set()
    for sec, refs in incoming.items():
        if all(sections[parent - 1][0].startswith(b'.debug$F') for parent in refs):
            remove.add(sec)
            remove.update(refs)
    for sec in remove:
        offset = 20 + optsz + 40 * (sec - 1) + 36
        struct.pack_into('<I', raw, offset, sections[sec - 1][9] | 0x800)
    return bytes(raw)


def isolate_single_code_section(raw, root, size):
    """Experimental diagnostic only: MSVC linker still sees other section references."""
    raise RuntimeError('disabled: LNK_REMOVE does not prevent discarded-section unresolved references')
    raw = bytearray(rebuild.strip_symbols(raw, keep={root}))
    sections, symbols, definitions, _ = match._coff_data_index(bytes(raw))
    if root not in definitions:
        raise ValueError('root not defined')
    value, index = definitions[root]
    section = sections[index]
    if value != 0 or section[3] != size or not section[9] & 0x20 or section[9] & 0x800:
        raise ValueError('root does not occupy one complete live code section')
    for j in range(section[7]):
        _, target, _ = struct.unpack_from('<IIH', raw, section[5] + 10 * j)
        if target not in symbols:
            raise ValueError('missing relocation symbol')
        target_section = symbols[target][2]
        if target_section > 0 and target_section != index + 1:
            raise ValueError('root has local section dependency')
    _, _, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', raw, 0)
    i = 0
    while i < nsym:
        _, value, sec, _, cls, aux = struct.unpack_from('<8sIhHBB', raw, symptr + 18 * i)
        if cls == 3 and aux and sec > 0 and value == 0:
            parent, selection = struct.unpack_from('<HB', raw, symptr + 18 * (i + 1) + 12)
            if selection == 5 and parent == index + 1 and not sections[sec - 1][0].startswith(b'.debug'):
                raise ValueError('root has non-debug associative section')
        i += 1 + aux
    for i, entry in enumerate(sections):
        if i != index:
            offset = 20 + optsz + 40 * i + 36
            struct.pack_into('<I', raw, offset, entry[9] | 0x800)
    return bytes(raw)


def string_bindings(raw, symbols, functions):
    """Prove live compiler strings through retained exact-body relocations."""
    base, image = match._image('2008-06')
    _, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', raw, 0)
    strtab = symptr + nsym * 18
    entries, index = {}, 0
    while index < nsym:
        name, value, sec, _, cls, aux = struct.unpack_from('<8sIhHBB', raw, symptr + index * 18)
        if name[:4] == b'\0\0\0\0':
            at = strtab + struct.unpack_from('<I', name, 4)[0]
            name = raw[at:raw.index(b'\0', at)]
        else:
            name = name.rstrip(b'\0')
        entries[index] = (name.decode('latin-1'), value, sec, cls)
        index += 1 + aux
    headers = {sec: struct.unpack_from('<8sIIIIIIHHI', raw, 20 + optsz + 40 * (sec - 1))
               for sec in range(1, nsec + 1)}
    candidates = {name for name, _, sec, cls in entries.values()
                  if cls == 2 and sec > 0 and not headers[sec][9] & 0x800 and name.startswith('??_C@')}
    refs = {name: set() for name in candidates}
    for symbol in symbols:
        if symbol['kind'] != 'code' or symbol['symbol'] not in entries:
            continue
        owner = next((row for row in entries.values() if row[0] == symbol['symbol'] and row[3] == 2 and row[2] > 0), None)
        if not owner:
            continue
        _, value, sec, _ = owner
        section = headers[sec]
        _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = section
        size = functions.get(symbol['address'], {}).get('size', 0)
        if not rawptr or not size:
            continue
        for rel in range(nrel):
            off, target_index, kind = struct.unpack_from('<IIH', raw, relptr + rel * 10)
            if kind != 6 or not value <= off < value + size:
                continue
            target = entries.get(target_index, ('', 0, 0, 0))[0]
            if target not in refs:
                continue
            addend = struct.unpack_from('<i', raw, rawptr + off)[0]
            site = int(symbol['address'], 16) + off - value
            if not base <= site <= base + len(image) - 4:
                continue
            refs[target].add(struct.unpack_from('<I', image, site - base)[0] - addend)
    proved = []
    for name, targets in refs.items():
        owner = next((row for row in entries.values() if row[0] == name and row[3] == 2 and row[2] > 0), None)
        if not owner:
            continue
        _, value, sec, _ = owner
        section = headers[sec]
        _, _, _, rawsize, rawptr, relptr, _, nrel, _, _ = section
        if not rawptr or value >= rawsize:
            continue
        end = raw.find(b'\0', rawptr + value, min(rawptr + rawsize, rawptr + value + 1025))
        if end < 0:
            continue
        target = raw[rawptr + value:end + 1]
        if len(target) < 2 or any(byte not in (9, 10, 13) and not 0x20 <= byte <= 0x7e for byte in target[:-1]):
            continue
        if any(value <= struct.unpack_from('<I', raw, relptr + rel * 10)[0] < value + len(target) for rel in range(nrel)):
            continue
        if len(targets) != 1:
            found, at = [], 0
            while True:
                at = image.find(target, at)
                if at < 0:
                    break
                found.append(base + at)
                at += 1
            if len(found) != 1:
                continue
            targets = set(found)
        va = next(iter(targets))
        if not base <= va <= base + len(image) - len(target) or image[va - base:va - base + len(target)] != target:
            continue
        proved.append({'symbol': name, 'address': '%08x' % va, 'kind': 'string', 'bytes': len(target),
                       'evidence': 'exact-body DIR32 call-site plus exact printable NUL bytes' if refs[name]
                       else 'unique exact printable NUL bytes'})
    return proved


def string_coverage(output):
    """Whole native-object string pass; unique target bytes are the only identity gate."""
    rows, seen = [], set()
    for obj in sorted((HERE / 'obj').glob('*.obj')):
        object_path = str(obj.relative_to(ROOT)).replace('\\', '/')
        object_sha256 = hashlib.sha256(obj.read_bytes()).hexdigest()
        for binding in string_bindings(obj.read_bytes(), [], {}):
            key = binding['address'], binding['symbol']
            if key not in seen:
                seen.add(key)
                binding.update(object=object_path, object_sha256=object_sha256)
                rows.append(binding)
    by_address = {}
    for row in rows:
        by_address[row['address']] = max(row['bytes'], by_address.get(row['address'], 0))
    receipt = {'scope': 'native compiler strings: unique exact printable NUL bytes only',
               'selected': [{'source': 'native-string-coverage', 'object': 'multiple native objects',
                             'symbols': sorted(rows, key=lambda row: (row['address'], row['symbol']))}],
               'definitions': len(rows), 'proved_data_bytes': sum(by_address.values()), 'linked': False,
               'runtime_executed': False, 'p5_p6_executed': False}
    output.write_text(json.dumps(receipt, indent=1) + '\n')
    print(json.dumps({'string_definitions': receipt['definitions'], 'data_bytes': receipt['proved_data_bytes']}))


def guid_exact(raw, row, stem, targets):
    """Only authentic typed GUID definitions, exact 16 bytes without relocations."""
    if not row['symbol'].endswith('@@3U_GUID@@B'):
        return False
    source = provider_source(stem)
    text = source.read_text() if source else ''
    name = row['symbol'][1:].split('@@', 1)[0]
    if not re.search(r'extern\s+const\s+(?:IID|CLSID|GUID)\s+' + re.escape(name) + r'\s*=\s*\{', text):
        return False
    sections, _, definitions, _ = match._coff_data_index(raw)
    if row['symbol'] not in definitions:
        return False
    offset, sec = definitions[row['symbol']]
    _, _, _, size, ptr, relocptr, _, nrel, _, flags = sections[sec]
    va = int(row['address'], 16)
    if not ptr or offset + 16 > size or flags & 0x20000000 or targets.data_relocations(va, 16):
        return False
    if any(offset <= struct.unpack_from('<I', raw, relocptr + i * 10)[0] < offset + 16 for i in range(nrel)):
        return False
    return raw[ptr + offset:ptr + offset + 16] == targets.data(va, 16)


def objects(stem, engine_abi, native_headers=False, function_comdat=False):
    if function_comdat:
        path = HERE / 'obj-function-comdat' / (stem + '.obj')
        return [path] if path.is_file() else []
    if native_headers:
        path = HERE / 'obj' / (stem + '.obj')
        return [path] if path.is_file() else []
    if engine_abi:
        path = HERE / 'obj-engine-abi' / (stem + '.obj')
        return [path] if path.is_file() else []
    roots = ('claude-template-applied', 'claude-profile-applied')
    return [HERE / root / stem / 'after' / 'candidate.obj' for root in roots
            if (HERE / root / stem / 'after' / 'candidate.obj').is_file()]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--input', type=Path, default=HERE / 'claude-link-unresolved-providers.json')
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--limit', type=int, default=20)
    ap.add_argument('--engine-abi', action='store_true')
    ap.add_argument('--native-headers', action='store_true', help='compile providers with native 2008 headers, retaining engine-ABI link baseline')
    ap.add_argument('--function-comdat', action='store_true', help='native-header compile with /Gy for safe function-level isolation')
    ap.add_argument('--closure-from', type=Path, help='also prove introduced dependencies from a prior family trial')
    ap.add_argument('--closed-from', type=Path, help='trial the prior batch providers with no introduced dependencies')
    ap.add_argument('--exclude', type=Path, default=HERE / 'link' / 'selected-engine-cumulative.json')
    ap.add_argument('--unresolved', type=Path, default=HERE / 'link' / 'probe.json')
    ap.add_argument('--rejected', type=Path, default=HERE / 'link' / 'selected-engine-rejected.json')
    ap.add_argument('--include-multi', action='store_true',
                    help='also inspect multi-provider rows; prefer already-linked exact provider')
    ap.add_argument('--trial-link', action='store_true', help='compare cumulative baseline and selected batch link probes')
    ap.add_argument('--provider', action='append', help='restrict to one or more source families after an input repair')
    ap.add_argument('--identity-closure', type=Path, help='add exact closure bodies for --closure-provider')
    ap.add_argument('--closure-provider', action='append', help='source family supplying --identity-closure bodies')
    ap.add_argument('--closure-discover', type=Path, help='discover pre-isolatable providers from a closure and cached objects')
    ap.add_argument('--fresh-only', action='store_true', help='trial only providers compiled during this invocation')
    ap.add_argument('--reuse-current', action='store_true', help='reuse a hash-checked successful object after selector-only changes')
    ap.add_argument('--string-coverage', action='store_true', help='prove unique compiler string data across cached native objects')
    ap.add_argument('--audit-selected', type=Path, help='recheck named receipt bodies in existing selected objects without recompiling')
    ap.add_argument('--reference-evidence', type=Path, action='append', default=[],
                    help='also audit selected code references using these identity receipts')
    ap.add_argument('--mfc-ordinal-evidence', type=Path,
                    help='verify MFC ordinal thunk evidence and prefer it over conflicting closure votes')
    args = ap.parse_args()
    if args.string_coverage:
        string_coverage(args.output)
        return
    if args.audit_selected:
        sys.path.insert(0, str(HERE / 'ogre'))
        import ogre_convert as converter
        converter.BASE, converter.IMAGE = match._image('2008-06')
        selected = json.loads(args.audit_selected.read_text()).get('selected', [])
        names, bindings, targets, reference_inputs, identity_overrides = {}, {}, None, {}, []
        if args.mfc_ordinal_evidence and not args.reference_evidence:
            ap.error('--mfc-ordinal-evidence requires --reference-evidence')
        if args.reference_evidence:
            from roc import native_bulk
            names, bindings, blockers, reference_inputs = native_bulk.seed_evidence(ROOT, [str(p) for p in args.reference_evidence])
            if blockers:
                raise RuntimeError('reference evidence blocked: ' + '; '.join(blockers[:5]))
            if args.mfc_ordinal_evidence:
                _, _, errors, ordinal_inputs = native_bulk.seed_evidence(ROOT, [str(args.mfc_ordinal_evidence)])
                if errors:
                    raise RuntimeError('MFC ordinal receipt blocked: ' + '; '.join(errors[:5]))
                reference_inputs.update(ordinal_inputs)
                ordinal = mfc_ordinal_bindings(json.loads(args.mfc_ordinal_evidence.read_text()))
                for symbol, address in ordinal.items():
                    if symbol in bindings and bindings[symbol] != address:
                        identity_overrides.append({'symbol': symbol, 'previous': bindings[symbol],
                                                   'mfc_ordinal_thunk': address})
                    bindings[symbol] = address
            targets = Targets('2008-06')
        receipts = {}
        for path in (HERE / 'link').glob('selected-*.json'):
            if path.resolve() == args.audit_selected.resolve():
                continue
            try:
                entries = json.loads(path.read_text()).get('selected', [])
            except (OSError, ValueError):
                continue
            for entry in entries:
                key = (entry.get('source'), entry.get('object'))
                if entry.get('symbols'):
                    receipts.setdefault(key, []).extend(entry['symbols'])
        results = []
        for entry in selected:
            obj = ROOT / entry['object']
            key = (entry.get('source'), entry.get('object'))
            claims = entry.get('symbols') or receipts.get(key, [])
            if not obj.is_file():
                results.append({'source': entry.get('source'), 'status': 'object-missing'})
                continue
            raw = obj.read_bytes()
            emitted = {name: (body, relocs) for name, body, relocs in match.coff_functions(raw)}
            checks = []
            for claim in { (v.get('symbol'), v.get('address'), v.get('kind'), v.get('bytes')) for v in claims }:
                symbol, address, kind, size = claim
                if kind == 'data':
                    size = size or (16 if symbol and symbol.endswith('@@3U_GUID@@B') else None)
                    exact = bool(size and address and converter.data_proved(raw, symbol, int(address, 16), size))
                    checks.append({'symbol': symbol, 'address': address, 'bytes': size,
                                   'status': 'data-byte-exact' if exact else 'data-unproved'})
                    continue
                if not symbol or not address or symbol not in emitted:
                    checks.append({'symbol': symbol, 'address': address, 'status': 'symbol-or-address-missing'})
                    continue
                try:
                    original, original_relocs, _ = match.target('2008-06', address)
                    body, relocs = emitted[symbol]
                    exact = len(original) == len(body) and set(original_relocs) <= set(relocs) and match.exact_match(original, original_relocs, body, relocs)
                except (KeyError, ValueError, SystemExit):
                    exact = False
                result = {'symbol': symbol, 'address': address, 'status': 'byte-exact' if exact else 'byte-mismatch'}
                if exact and targets:
                    if address.lower() not in names.get(symbol, set()):
                        result['reference_status'] = 'identity-unproved'
                    else:
                        try:
                            refs, errors = native_bulk.audit_references(raw, symbol, body, original, original_relocs,
                                                                        int(address, 16), targets, bindings)
                            result.update(reference_status='unproved' if errors else 'exact',
                                          reference_errors=errors, reference_count=len(refs))
                        except (KeyError, ValueError, struct.error) as error:
                            result.update(reference_status='unproved', reference_errors=[str(error)])
                checks.append(result)
            results.append({'source': entry.get('source'), 'object': entry['object'],
                            'object_sha256': hashlib.sha256(raw).hexdigest(), 'checks': checks})
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps({'scope': 'current-object bytes and optional reference audit; not source freshness, type or ABI proof',
                                           'reference_inputs': reference_inputs,
                                           'mfc_identity_overrides': identity_overrides,
                                           'providers': results}, indent=1) + '\n')
        checks = [c for result in results for c in result.get('checks', [])]
        print(json.dumps({'providers': len(results), 'code_byte_exact': sum(c['status'] == 'byte-exact' for c in checks),
                          'data_byte_exact': sum(c['status'] == 'data-byte-exact' for c in checks),
                          'byte_unproved': sum(c['status'] not in ('byte-exact', 'data-byte-exact') for c in checks),
                          'references_exact': sum(c.get('reference_status') == 'exact' for c in checks),
                          'references_unproved': sum(c.get('reference_status') in ('unproved', 'identity-unproved') for c in checks)}))
        return
    if bool(args.identity_closure) != bool(args.closure_provider):
        ap.error('--identity-closure and --closure-provider must be used together')
    if args.closure_discover and args.identity_closure:
        ap.error('choose --closure-discover or --identity-closure')
    if args.closed_from:
        previous = json.loads(args.closed_from.read_text()).get('link_trial', {})
        if 'provider_dependencies' not in previous:
            ap.error('--closed-from needs a trial receipt with provider dependency attribution')
        args.provider = [row['source'] for row in previous['provider_dependencies'] if row['introduced_count'] == 0]
        args.trial_link = True
    if args.native_headers and not args.engine_abi:
        ap.error('--native-headers requires --engine-abi baseline')
    if args.function_comdat and not args.native_headers:
        ap.error('--function-comdat requires --native-headers')
    targets, _ = Targets('2008-06'), probe.runner()
    rows = json.loads(args.input.read_text())
    if args.closure_discover:
        unresolved_now = set(json.loads(args.unresolved.read_text()).get('unresolved', [])) if args.unresolved.is_file() else set()
        closure = {binding['symbol']: binding for binding in json.loads(args.closure_discover.read_text()).get('bindings', [])
                   if binding.get('body_exact') and binding.get('function_start')}
        rows = []
        root = HERE / ('obj' if args.native_headers else 'obj-engine-abi')
        for obj in sorted(root.glob('*.obj')):
            source = provider_source(obj.stem)
            if not source:
                continue
            raw = obj.read_bytes()
            _, _, definitions, _ = match._coff_data_index(raw)
            # Retain every directly proved external in this source, not merely
            # today's gaps: exact helper bodies are required for a safe source
            # closure and may be dependencies of the unresolved entrypoints.
            keep = set(definitions) & set(closure)
            if not (keep & unresolved_now):
                continue
            trimmed = prune_unused_comdat_data(rebuild.strip_symbols(raw, keep=keep), keep)
            left = live_definitions(trimmed)
            if any(name not in keep and not name.startswith(('$', '.')) for name in left):
                continue
            proof = probe.exact(trimmed, targets)
            for symbol in sorted(keep):
                binding = closure[symbol]
                if binding['addr'] in proof.get(symbol, []):
                    rows.append({'symbol': symbol, 'kind': 'native-source-defines',
                                 'providers': [obj.stem], 'address': binding['addr'],
                                 'identity_evidence': binding.get('evidence')})
    if args.identity_closure:
        unresolved_now = set(json.loads(args.unresolved.read_text()).get('unresolved', [])) if args.unresolved.is_file() else set()
        known = {(row['symbol'], tuple(row.get('providers', ()))) for row in rows}
        for binding in json.loads(args.identity_closure.read_text()).get('bindings', []):
            if not (binding.get('body_exact') and binding.get('function_start') and binding.get('symbol') in unresolved_now):
                continue
            for provider in args.closure_provider:
                row = {'symbol': binding['symbol'], 'kind': 'native-source-defines',
                       'providers': [provider], 'address': binding['addr'],
                       'identity_evidence': binding.get('evidence')}
                if (row['symbol'], tuple(row['providers'])) not in known:
                    rows.append(row)
    if args.provider is not None:
        rows = [dict(row, providers=[p for p in row.get('providers', []) if p in args.provider])
                for row in rows if set(row.get('providers', [])) & set(args.provider)]
    registry_path = ROOT / 'work/2008-06/identity-registry.json'
    registry = json.loads(registry_path.read_text()) if registry_path.is_file() else {}
    named = {r['name']: a for a, r in registry.items() if not r.get('placeholder')}
    for row in rows:
        if not row.get('address') and row['symbol'].endswith('@@3U_GUID@@B'):
            row['address'] = named.get(row['symbol'])
    guid_bindings = {row['symbol']: row for row in rows if row.get('address') and row['symbol'].endswith('@@3U_GUID@@B')}
    if args.unresolved.is_file():
        unresolved = set(json.loads(args.unresolved.read_text()).get('unresolved', []))
        if args.closure_from:
            unresolved |= set(json.loads(args.closure_from.read_text()).get('link_trial', {}).get('introduced', []))
        rows = [row for row in rows if row['symbol'] in unresolved]
    excluded = set()
    if args.exclude and args.exclude.is_file():
        excluded = {row['source'] for row in json.loads(args.exclude.read_text()).get('selected', [])}
    if args.rejected.is_file():
        excluded |= set(json.loads(args.rejected.read_text()).get('sources', []))
    eligible = lambda row: (row.get('kind') == 'native-source-defines' and row.get('address') and
                            (len(row.get('providers', [])) == 1 or args.include_multi))
    current_attempts, fingerprints, compiled_stems = {}, {}, set()
    if args.engine_abi:
        trials = HERE / 'link' / ('function-comdat-experimental.json' if args.function_comdat else
                                  'native-header-experimental.json' if args.native_headers else 'engine-abi-experimental.json')
        trial_data = json.loads(trials.read_text()) if trials.is_file() else {'stems': []}
        current_attempts = trial_data.setdefault('attempts', {})
        header_hash = hashlib.sha256()
        inputs = sorted(p for p in (ROOT / 'rebuild/2008-06/native-headers').rglob('*')
                        if p.is_file() and p.suffix.lower() in ('.h', '.hpp', '.inl', '.inc')) + [HERE / 'inventory_flags.py', HERE / 'inventory.py', Path(__file__)]
        for path in inputs:
            header_hash.update(str(path.relative_to(ROOT)).encode())
            header_hash.update(path.read_bytes())
        for row in rows:
            for stem in row.get('providers', []):
                source = provider_source(stem)
                if source:
                    fingerprints[stem] = hashlib.sha256(header_hash.digest() + source.read_bytes() +
                                                         (b'/Gy' if args.function_comdat else b'')).hexdigest()
        names, seen = [], set()
        for row in rows:
            providers = row.get('providers', [])
            if not eligible(row):
                continue
            for stem in providers:
                attempt = current_attempts.get(stem, {})
                obj = HERE / ('obj-function-comdat' if args.function_comdat else 'obj' if args.native_headers else 'obj-engine-abi') / (stem + '.obj')
                reusable = args.reuse_current and attempt.get('compile_ok') and obj.is_file() and \
                    hashlib.sha256(obj.read_bytes()).hexdigest() == attempt.get('object_sha256')
                if stem in seen or stem in excluded or stem not in fingerprints or attempt.get('fingerprint') == fingerprints[stem] or reusable:
                    continue
                source = provider_source(stem)
                # inventory compiles from its object directory, so wrappers
                # outside native-classes must be absolute source paths.
                names.append(str(source.resolve()))
                seen.add(stem)
                if len(names) == args.limit:
                    break
            if len(names) == args.limit:
                break
        # inventory.py writes a shared object cache.  Record all trial stems so
        # linkprobe cannot accidentally link a compiled-but-unproved provider.
        trial_data['stems'] = sorted(set(trial_data.get('stems', [])) | {Path(n).stem for n in names})
        trials.parent.mkdir(parents=True, exist_ok=True)
        trials.write_text(json.dumps(trial_data, indent=1) + '\n')
        env = dict(os.environ, ROC_ENGINE_ABI='0' if args.native_headers else '1')
        if args.function_comdat:
            env['ROC_NATIVE_OUT'] = str(HERE / 'obj-function-comdat')
            env['ROC_NATIVE_EXTRA_FLAGS'] = '/Gy'
        if names:
            compiled_stems = {Path(name).stem for name in names}
            run = subprocess.run([sys.executable, str(HERE / 'inventory.py')] + names, cwd=ROOT, env=env, check=False)
            if run.returncode:
                raise RuntimeError('provider inventory failed (exit %s)' % run.returncode)
            results = json.loads((HERE / 'inventory.json').read_text())
            for name in names:
                stem = Path(name).stem
                obj = HERE / ('obj-function-comdat' if args.function_comdat else 'obj' if args.native_headers else 'obj-engine-abi') / (stem + '.obj')
                result = results.get(Path(name).name, {})
                ok = result.get('ok', False) and obj.is_file()
                current_attempts[stem] = {'fingerprint': fingerprints[stem], 'compile_ok': ok,
                                          'object_sha256': hashlib.sha256(obj.read_bytes()).hexdigest() if ok else None,
                                          'errors': result.get('errors', [])}
            trials.write_text(json.dumps(trial_data, indent=1) + '\n')
    selected, blocked, cache = [], [], {}
    proof_version = hashlib.sha256((HERE / 'native_template_probe.py').read_bytes() +
                                   (ROOT / 'roc/match.py').read_bytes() +
                                   (ROOT / 'roc/native_bulk.py').read_bytes() +
                                   (ROOT / 'roc/native_sweep.py').read_bytes() +
                                   (ROOT / 'roc/fingerprint.py').read_bytes()).hexdigest()
    proof_folder = HERE / 'link/native-body-proof-cache'
    proof_folder.mkdir(exist_ok=True)
    used = set()
    for row in rows:
        providers = row.get('providers', [])
        if not eligible(row):
            continue
        if len(providers) == 1 and providers[0] in excluded:
            continue
        ordered = sorted(providers, key=lambda stem: (stem not in excluded, stem))
        exact, chosen, stem = False, None, None
        for candidate_stem in ordered:
            if args.fresh_only and candidate_stem not in compiled_stems:
                continue
            if args.engine_abi and candidate_stem not in excluded:
                attempt = current_attempts.get(candidate_stem, {})
                reusable = args.reuse_current and attempt.get('compile_ok') and any(
                    hashlib.sha256(obj.read_bytes()).hexdigest() == attempt.get('object_sha256')
                    for obj in objects(candidate_stem, args.engine_abi, args.native_headers, args.function_comdat))
                if (attempt.get('fingerprint') != fingerprints.get(candidate_stem) and not reusable) or not attempt.get('compile_ok'):
                    continue
            for obj in objects(candidate_stem, args.engine_abi, args.native_headers, args.function_comdat):
                if args.engine_abi and candidate_stem not in excluded and hashlib.sha256(obj.read_bytes()).hexdigest() != attempt.get('object_sha256'):
                    continue
                if row['symbol'].endswith('@@3U_GUID@@B'):
                    raw = obj.read_bytes()
                    _, _, definitions, _ = match._coff_data_index(raw)
                    guids = [name for name in definitions if name.endswith('@@3U_GUID@@B')]
                    if any(name not in guid_bindings or not guid_exact(raw, guid_bindings[name], candidate_stem, targets)
                           for name in guids):
                        continue
                key = str(obj)
                if key not in cache:
                    raw = obj.read_bytes()
                    proof_key = hashlib.sha256(raw + targets.identity.encode() + proof_version.encode()).hexdigest()
                    saved = proof_folder / (proof_key + '.json')
                    try:
                        cache[key] = json.loads(saved.read_text())
                    except (OSError, ValueError):
                        cache[key] = probe.exact(raw, targets)
                        saved.write_text(json.dumps(cache[key], sort_keys=True) + '\n')
                if row['address'] in cache[key].get(row['symbol'], []) or guid_exact(obj.read_bytes(), row, candidate_stem, targets):
                    exact, chosen, stem = True, obj, candidate_stem
                    break
            if exact:
                break
        if not exact:
            reason = 'no-current-native-object' if not any(objects(s, args.engine_abi, args.native_headers, args.function_comdat) for s in providers) else 'provider-body-not-exact'
            if args.engine_abi and all(not current_attempts.get(s, {}).get('compile_ok') for s in providers):
                reason = 'current-provider-compile-failed-or-unchecked'
            blocked.append(dict(row, reason=reason))
            continue
        if stem in excluded:
            continue
        if stem not in used and len(used) >= args.limit:
            continue
        if stem not in used:
            selected.append({'source': stem, 'object': str(chosen.relative_to(ROOT)).replace('\\', '/'),
                             'symbols': []})
            used.add(stem)
        next(item for item in selected if item['source'] == stem)['symbols'].append(
            {'symbol': row['symbol'], 'address': row['address'],
             'kind': 'data' if row['symbol'].endswith('@@3U_GUID@@B') else 'code'})
    args.output.parent.mkdir(parents=True, exist_ok=True)
    funcs = match._functions('2008-06')
    isolate_root = HERE / 'link' / 'native-isolated' / args.output.stem
    isolated = []
    for item in selected:
        raw = (ROOT / item['object']).read_bytes()
        keep = {symbol['symbol'] for symbol in item['symbols']}
        trimmed = prune_unused_comdat_data(rebuild.strip_symbols(raw, keep=keep), keep)
        definitions = live_definitions(trimmed)
        strings = string_bindings(trimmed, item['symbols'], funcs)
        allowed = keep | {string['symbol'] for string in strings}
        # `$LN*` is VS2008's local EH/debug label spelling.  It cannot satisfy
        # another object and has no target identity; all named link externals
        # remain subject to the strict residual-definition gate.
        extras = sorted(name for name in definitions if name not in allowed and not name.startswith(('$', '.')))
        if extras:
            blocked.extend({'symbol': symbol['symbol'], 'kind': symbol['kind'],
                            'providers': [item['source']], 'address': symbol['address'],
                            'reason': 'isolation-left-unproved-definitions', 'definitions': extras[:12]}
                           for symbol in item['symbols'])
            continue
        proof = probe.exact(trimmed, targets)
        lost = [symbol['symbol'] for symbol in item['symbols']
                if symbol['kind'] == 'code' and symbol['address'] not in proof.get(symbol['symbol'], [])]
        if lost:
            blocked.extend({'symbol': symbol['symbol'], 'kind': symbol['kind'],
                            'providers': [item['source']], 'address': symbol['address'],
                            'reason': 'isolation-reproof-failed', 'lost': lost[:12]}
                           for symbol in item['symbols'])
            continue
        path = isolate_root / (item['source'] + '.obj')
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(trimmed)
        copy = dict(item, object=str(path.relative_to(ROOT)).replace('\\', '/'), data_symbols=strings)
        isolated.append(copy)
    selected = isolated
    code_addresses = {symbol['address'] for item in selected for symbol in item['symbols'] if symbol['kind'] == 'code'}
    proved_bytes = sum(funcs.get(addr, {}).get('size', 0) for addr in code_addresses)
    data_bytes = sum(symbol['bytes'] for item in selected for symbol in item.get('data_symbols', []))
    args.output.write_text(json.dumps({'selected': selected, 'blocked': blocked,
                                       'candidate_proved_code_bytes': proved_bytes,
                                       'candidate_proved_data_bytes': data_bytes,
                                       'newly_compiled_sources': sorted(compiled_stems),
                                       'isolated_sources': [item['source'] for item in selected],
                                       'scope': 'cached native object direct body equality; link selection only'}, indent=1) + '\n')
    print(json.dumps({'sources': len(selected), 'symbols': sum(len(x['symbols']) for x in selected),
                      'blocked': len(blocked)}))
    if args.trial_link and selected:
        env = dict(os.environ)
        if args.engine_abi:
            env['ROC_ENGINE_ABI'] = '1'
        baseline = str(args.exclude.resolve()) if args.exclude and args.exclude.is_file() else ''
        probes = []
        for receipts in (baseline, os.pathsep.join(p for p in (baseline, str(args.output.resolve())) if p)):
            env['ROC_LINK_EXTRA'] = receipts
            run = subprocess.run([sys.executable, str(HERE / 'linkprobe.py')], cwd=ROOT, env=env,
                                 text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
            if run.returncode:
                raise RuntimeError('link probe failed: ' + run.stdout[-2000:])
            result = json.loads((HERE / 'link/probe.json').read_text())
            if result.get('link_exit_code') not in (0, 1120):
                raise RuntimeError('link trial has a non-unresolved linker error: ' + str(result.get('link_exit_code')))
            probes.append(result)
        before, after = probes
        resolved = sorted(set(before['unresolved']) - set(after['unresolved']))
        introduced = sorted(set(after['unresolved']) - set(before['unresolved']))
        comparison = {'unresolved_before': len(before['unresolved']), 'unresolved_after': len(after['unresolved']),
                      'resolved': resolved, 'introduced': introduced, 'duplicates': after['duplicates'],
                      'net_gain': len(resolved) - len(introduced),
                      'eligible_for_selection': len(resolved) > len(introduced) and not after['duplicates'],
                      'runtime_executed': False}
        attribution = []
        for item in selected:
            raw = (ROOT / item['object']).read_bytes()
            _, symbols, _, _ = match._coff_data_index(raw)
            undefined = {name for name, value, sec, typ in symbols.values() if sec == 0 and value == 0}
            deps = sorted(undefined & set(introduced))
            attribution.append({'source': item['source'], 'introduced_dependencies': deps,
                                'introduced_count': len(deps)})
        comparison['provider_dependencies'] = attribution
        receipt = json.loads(args.output.read_text())
        receipt['link_trial'] = comparison
        args.output.write_text(json.dumps(receipt, indent=1) + '\n')
        print(json.dumps({key: comparison[key] for key in ('unresolved_before', 'unresolved_after', 'net_gain', 'eligible_for_selection')} |
                         {'resolved_count': len(resolved), 'introduced_count': len(introduced),
                          'duplicate_count': len(after['duplicates']), 'receipt': str(args.output)}))
        if not comparison['eligible_for_selection']:
            env['ROC_LINK_EXTRA'] = baseline
            restore = subprocess.run([sys.executable, str(HERE / 'linkprobe.py')], cwd=ROOT, env=env,
                                     text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
            if restore.returncode:
                raise RuntimeError('baseline restore failed: ' + restore.stdout[-2000:])
            restored = json.loads((HERE / 'link/probe.json').read_text())
            if restored['unresolved'] != before['unresolved'] or restored['duplicates'] != before['duplicates']:
                raise RuntimeError('baseline input state changed during rejected trial')


if __name__ == '__main__':
    main()
