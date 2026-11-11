"""Build 2008-06 identity registry from recorded evidence only.

No declaration, field, or ABI is inferred here. A missing identity receives a
stable address placeholder so every converted object can still link by name.
"""
import argparse
import ast
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))


def load(path, default):
    try:
        return json.loads((ROOT / path).read_text())
    except (OSError, ValueError):
        return default


def addr(value):
    if value is None:
        return None
    if isinstance(value, int):
        return '%08x' % value
    value = str(value).lower().removeprefix('0x')
    return value.zfill(8) if all(c in '0123456789abcdef' for c in value) else None


def method_facts():
    facts = {}
    for cls in load('work/native-client/ogre-conversion-queue-v10.json', {}).get('classes', []):
        for method in cls.get('methods', []):
            key = addr(method.get('addr'))
            if key:
                facts[key] = (cls.get('owner'), method.get('declaration'))
    return facts


def add_name(rows, key, name, source, evidence, owner=None, signature=None, kind='code'):
    if not key or not name:
        return
    row = rows.get(key)
    if row is None:
        rows[key] = {'name': name, 'owner_class': owner, 'signature': signature, 'kind': kind,
                     'name_source': source, 'evidence': evidence, 'placeholder': False}
        return
    if row['placeholder']:
        row.update(name=name, name_source=source, evidence=evidence, placeholder=False)
    if owner and not row['owner_class']:
        row['owner_class'] = owner
    if signature and not row['signature']:
        row['signature'] = signature


def data_coverage():
    """Typed-data bytes, deduped by target address; unknown data stays uncovered."""
    covered = {}
    scalar_sizes = {'signed char': 1, 'char': 1, 'unsigned char': 1, 'short': 2, 'unsigned short': 2,
                    'int': 4, 'unsigned int': 4, 'long': 4, 'unsigned long': 4, 'float': 4, 'double': 8,
                    'bool': 1, '__int64': 8, 'unsigned __int64': 8, 'void*': 4}
    for path in (ROOT / 'work/native-client/ogre/batches').glob('*/*/link/data-metrics.json'):
        metric = load(path.relative_to(ROOT), {})
        if metric.get('status') != 'proved':
            continue
        addresses = metric.get('addresses', {})
        if not addresses:
            source = path.parent / 'roc_data.cpp'
            if source.is_file():
                for line in source.read_text(errors='replace').splitlines():
                    name = re.search(r'roc_data_([0-9a-f]{8})', line)
                    if not name:
                        continue
                    if 'const char' in line and '[]' in line:
                        literal = re.search(r'=\s*("(?:[^"\\]|\\.)*")\s*;', line)
                        if literal:
                            try:
                                addresses[name.group(1)] = len(ast.literal_eval(literal.group(1)).encode('ascii')) + 1
                            except (SyntaxError, UnicodeEncodeError):
                                pass
                        continue
                    declaration = re.fullmatch(r'extern "C"\s+(.+?)\s+roc_data_[0-9a-f]{8}\s*=.*;', line.strip())
                    if declaration:
                        ctype = re.sub(r'\bconst\b', '', declaration.group(1)).strip()
                        if ctype in scalar_sizes:
                            addresses[name.group(1)] = scalar_sizes[ctype]
        for key, size in addresses.items():
            if addr(key) and isinstance(size, int) and size > 0:
                key = addr(key)
                covered[key] = max(size, covered.get(key, 0))
    # Link-selected and coverage-only typed-data batches use the same compiler
    # proof gate, but sit outside converter scope directories.  Their receipts
    # record address and exact emitted storage size, so union them here rather
    # than reporting converter-local coverage as whole-client coverage.
    link = ROOT / 'work/native-client/link'
    for path in list(link.glob('selected-typed*.json')) + list(link.glob('typed-data-coverage-batch*.json')):
        for provider in load(path.relative_to(ROOT), {}).get('selected', []):
            for symbol in provider.get('symbols', []):
                key, size = addr(symbol.get('address')), symbol.get('bytes')
                if key and isinstance(size, int) and size > 0:
                    covered[key] = max(size, covered.get(key, 0))
    import pefile
    pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
    sections = {}
    for section in pe.sections:
        name = section.Name.rstrip(b'\0').decode()
        if name in ('.data', '.rdata'):
            sections[name] = {'raw_bytes': section.SizeOfRawData, 'virtual_bytes': section.Misc_VirtualSize}
    base = pe.OPTIONAL_HEADER.ImageBase
    intervals = {name: [] for name in sections}
    for key, size in covered.items():
        va = int(key, 16)
        for section in pe.sections:
            lo, hi = base + section.VirtualAddress, base + section.VirtualAddress + section.Misc_VirtualSize
            name = section.Name.rstrip(b'\0').decode()
            if name in intervals and lo <= va and va + size <= hi:
                intervals[name].append((va, va + size))
                break
    by_section = {}
    for name, ranges in intervals.items():
        end, count = 0, 0
        for lo, hi in sorted(ranges):
            count += max(0, hi - max(lo, end))
            end = max(end, hi)
        by_section[name] = count
    return {'typed_definition_addresses': len(covered), 'typed_definition_bytes': sum(by_section.values()),
            'covered_bytes_by_section': by_section, 'sections': sections}


def rtti_vtables(match, rtti):
    """Validated RTTI vtables; secondary tables deliberately retain placeholders."""
    base, image = match._image('2008-06')
    relocs, functions, types = match._base_relocs('2008-06'), match._functions('2008-06'), rtti.descriptors('2008-06')
    word = lambda va: int.from_bytes(image[va - base:va - base + 4], 'little') if base <= va <= base + len(image) - 4 else 0
    out = []
    for table in range(base + 4, base + len(image) - 4, 4):
        if table - 4 not in relocs or table not in relocs:
            continue
        locator = word(table - 4)
        if not base <= locator <= base + len(image) - 20 or word(locator) != 0 or locator + 12 not in relocs:
            continue
        descriptor = word(locator + 12)
        raw_type = types.get(descriptor)
        first = '%08x' % word(table)
        if not raw_type or first not in functions or functions[first].get('kind') not in ('code', 'gen'):
            continue
        offset = word(locator + 4)
        primary = offset == 0 and raw_type.startswith('.?AV')
        name = ('??_7' + raw_type[4:] + '6B@') if primary else None
        out.append((table, raw_type, offset, name, descriptor, locator))
    return out


def main():
    from roc import match, native_asm, rtti
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--output', default='work/2008-06/identity-registry.json')
    args = ap.parse_args()
    rows = {}
    methods = method_facts()
    for key, fact in match._functions('2008-06').items():
        owner, signature = methods.get(key, (None, None))
        kind = 'data' if fact.get('kind') == 'data' else 'code'
        rows[key] = {'name': ('data_' if kind == 'data' else 'func_') + key,
                     'owner_class': owner, 'signature': signature, 'kind': kind,
                     'name_source': 'placeholder',
                     'evidence': [{'kind': 'function-index', 'target_kind': fact.get('kind')}],
                     'placeholder': True}

    for binding in load('work/native-client/claude-identity-closure.json', {}).get('bindings', []):
        key = addr(binding.get('addr', binding.get('address')))
        add_name(rows, key, binding.get('symbol'), 'identity-closure',
                 [{'kind': 'identity-closure', 'body_exact': binding.get('body_exact', False),
                   'votes': binding.get('votes', 0), 'evidence': binding.get('evidence')}])
    for binding in load('work/2008-06/shared-layouts/identity-registry-batch.json', {}).get('identity_bindings', []):
        add_name(rows, addr(binding['address']), binding['symbol'], 'reviewed-reference-binding',
                 [binding['evidence']], kind=binding['kind'])
    for path, source in (('work/native-client/link/names.json', 'header-address'),
                         ('work/native-client/ogre/link/ogre_names.json', 'header-address')):
        for key, name in load(path, {}).items():
            add_name(rows, addr(key), name, source, [{'kind': source, 'path': path}])
    for value, name in native_asm.names('2008-06').items():
        add_name(rows, addr(value), name, 'import-table' if '!' in name else 'native-asm',
                 [{'kind': 'import-table' if '!' in name else 'native-asm-label'}])
    for value, name in rtti.descriptors('2008-06').items():
        add_name(rows, addr(value), '??_R0' + name[1:] + '@8', 'rtti',
                 [{'kind': 'rtti-type-descriptor', 'raw_name': name}], kind='rtti')
    for table, raw_type, offset, name, descriptor, locator in rtti_vtables(match, rtti):
        key = addr(table)
        evidence = [{'kind': 'rtti-complete-object-locator', 'raw_type': raw_type,
                     'type_descriptor': addr(descriptor), 'locator': addr(locator), 'offset': offset}]
        if name:
            add_name(rows, key, name, 'rtti-primary-vtable', evidence,
                     owner=raw_type, signature='vtable ' + raw_type, kind='vtable')
        elif key not in rows:
            rows[key] = {'name': 'data_' + key, 'owner_class': raw_type,
                         'signature': 'secondary vtable ' + raw_type, 'kind': 'vtable',
                         'name_source': 'placeholder', 'evidence': evidence, 'placeholder': True}
        else:
            rows[key]['kind'] = 'vtable'
            rows[key]['owner_class'] = rows[key]['owner_class'] or raw_type
            rows[key]['signature'] = rows[key]['signature'] or ('secondary vtable ' + raw_type)
            rows[key]['evidence'].extend(evidence)
    for path in sorted((ROOT / 'work/native-client/ogre/batches').glob('*/*/link/ogre_convert.json')):
        for key, result in json.loads(path.read_text()).items():
            if result.get('status') == 'renamed' and result.get('name_source') == 'lib':
                packet = ROOT / 'src/2008-06' / (key + '.cpp')
                text = packet.read_text(errors='replace') if packet.is_file() else ''
                replay = re.search(r'^//\s*roc-lib:\s*\S+\s+(.+)$', text, re.M)
                if not replay or Path(replay.group(1).strip().replace('\\', '/')).name.startswith('roc_'):
                    # Generated codegen analogs can invent class/type names.
                    # Their bytes are evidence, but the spelling needs an
                    # independent closure/header/library identity binding.
                    continue
                add_name(rows, addr(key), result['symbol'], 'library-replay',
                         [{'kind': 'byte-data-relocation-proof', 'path': path.relative_to(ROOT).as_posix()}])

    from native_conversion_queue import undecorate, owner
    for row in rows.values():
        if row['placeholder'] or row['kind'] != 'code' or not row['name'].startswith('?'):
            continue
        signature = undecorate(row['name'])
        if signature == row['name'] or '(' not in signature:
            continue
        if row['signature'] is None:
            row['signature'] = signature
            row['evidence'].append({'kind': 'decorated-signature', 'symbol': row['name']})
        # Namespaces can own free functions; only access-qualified member
        # signatures prove an owner class.
        if row['owner_class'] is None and re.match(r'^(public|protected|private):', signature):
            row['owner_class'] = owner(row['name']) or None

    # A name's presence in native_asm is not evidence that its storage is code.
    # PE section characteristics distinguish executable bodies from data slots.
    import pefile
    pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
    base = pe.OPTIONAL_HEADER.ImageBase
    for key, row in rows.items():
        va = int(key, 16)
        section = next((s for s in pe.sections if base + s.VirtualAddress <= va <
                        base + s.VirtualAddress + s.Misc_VirtualSize), None)
        if section is None:
            continue
        if row['name'].startswith('??_7'):
            kind = 'vtable'
        elif row['name'].startswith('??_R'):
            kind = 'rtti'
        elif row['name'].startswith('??_C@'):
            kind = 'string'
        else:
            kind = 'code' if section.Characteristics & 0x20000000 else 'data'
        if row['kind'] != kind:
            row['kind'] = kind
            row['evidence'].append({'kind': 'pe-section', 'section': section.Name.rstrip(b'\0').decode(),
                                    'executable': bool(section.Characteristics & 0x20000000)})
        if row['placeholder']:
            row['name'] = ('func_' if kind == 'code' else 'data_') + key

    output = ROOT / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(dict(sorted(rows.items())), indent=1, sort_keys=True) + '\n')
    totals = {'total': len(rows), 'proved': sum(not r['placeholder'] for r in rows.values()),
              'placeholder': sum(r['placeholder'] for r in rows.values()),
              'code': sum(r['kind'] == 'code' for r in rows.values()),
              'data': sum(r['kind'] == 'data' for r in rows.values()),
              'rtti': sum(r['kind'] == 'rtti' for r in rows.values())}
    totals['vtable'] = sum(r['kind'] == 'vtable' for r in rows.values())
    totals['string'] = sum(r['kind'] == 'string' for r in rows.values())
    totals['missing_owner'] = sum(r['kind'] == 'code' and r['owner_class'] is None for r in rows.values())
    totals['missing_signature'] = sum(r['kind'] == 'code' and r['signature'] is None for r in rows.values())
    coverage = data_coverage()
    (output.parent / 'identity-registry-data-metrics.json').write_text(json.dumps(coverage, indent=1, sort_keys=True) + '\n')
    print(json.dumps({**totals, 'typed_data_bytes': coverage['typed_definition_bytes']}, sort_keys=True))


if __name__ == '__main__':
    main()
