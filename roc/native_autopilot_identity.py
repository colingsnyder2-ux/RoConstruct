"""Independent virtual-slot identities from original PE RTTI and native COFF.

Only complete, primary vtables with matching RTTI class names and slot counts
qualify. This proves a virtual-slot correspondence, never a class ABI/runtime
swap or original source declaration. Byte/data/call proof is still required.
"""
import hashlib
import json
from pathlib import Path
import re
import struct

from roc import analyze, match
from roc.integration import atomic_json


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def coff_tables(raw):
    sections, symbols, definitions, _ = match._coff_data_index(raw)
    relocations = {}
    for index, section in enumerate(sections):
        relocations[index] = {}
        for n in range(section[7]):
            offset, symbol, kind = struct.unpack_from('<IIH', raw, section[5] + n * 10)
            relocations[index][offset] = (symbols[symbol][0], kind)

    def data(name):
        value, section = definitions[name]
        table = sections[section]
        end = min([table[3]] + [v for v, s in definitions.values() if s == section and v > value])
        return raw[table[4] + value:table[4] + end], value, section

    def reference(section, offset):
        symbol, kind = relocations[section][offset]
        table = sections[section]
        if kind != 6 or struct.unpack_from('<I', raw, table[4] + offset)[0] != 0:
            raise ValueError('vtable identity requires zero-addend DIR32 references')
        return symbol

    result = []
    for name in definitions:
        if not name.startswith('??_7'):
            continue
        try:
            body, value, section = data(name)
            if value < 4 or not body or len(body) % 4:
                continue
            locator = reference(section, value - 4)
            col, col_value, col_section = data(locator)
            if len(col) != 20 or col[:12] != b'\0' * 12:
                continue  # Secondary/construction tables need separate ABI proof.
            descriptor = reference(col_section, col_value + 12)
            type_data, _, _ = data(descriptor)
            encoded = type_data[8:].split(b'\0')[0]
            if not encoded.startswith((b'.?AV', b'.?AU')):
                continue
            cls = analyze.demangle_class(encoded.decode('ascii'))
            methods = [reference(section, value + offset) for offset in range(0, len(body), 4)]
            result.append({'class': cls, 'symbol': name, 'methods': methods})
        except (KeyError, ValueError, struct.error, UnicodeError):
            continue
    return result


def bind_tables(compiled, original, checks):
    """A body match is insufficient without matching typed table and ordinal."""
    bindings = []
    for table in compiled:
        for target in original:
            if target['class'] != table['class'] or len(target['slots']) != len(table['methods']):
                continue
            for index, symbol in enumerate(table['methods']):
                owner = re.match(r'^\?[^?@$]+@([^?$]+?)@@', symbol)
                if not owner or analyze.demangle_class('.?AV' + owner[1] + '@@') != table['class']:
                    continue  # Inherited methods, templates and helpers need base/ABI proof.
                address = target['slots'][index][0]
                if (address, symbol) in checks:
                    bindings.append({'address': address, 'symbol': symbol, 'class': table['class'], 'slot': index,
                        'original_vtable': target['vtable'], 'original_slot': '%08x' % (int(target['vtable'], 16) + 4 * index),
                        'compiled_vtable': table['symbol'], 'slot_count': len(table['methods'])})
    return bindings


def discover(root, diagnostics, builds, output_dir):
    root, output_dir = Path(root).resolve(), Path(output_dir)
    original_path = root / 'clients/2008-06/Roblox.exe'
    original_hash, verifier_hash = sha(original_path), sha(__file__)
    original = analyze.vtables('2008-06')  # Read directly from the installed PE, never mined labels.
    base, image = match._image('2008-06')
    def primary(table):
        offset = int(table['vtable'], 16) - base
        if offset < 4 or offset > len(image):
            return False
        locator = struct.unpack_from('<I', image, offset - 4)[0] - base
        return 0 <= locator <= len(image) - 20 and bytes(image[locator:locator + 12]) == b'\0' * 12
    original = [table for table in original if primary(table)]
    counts = {}
    for table in original:
        counts[table['class']] = counts.get(table['class'], 0) + 1
    original = [table for table in original if counts[table['class']] == 1]
    checks = {(r['address'], r.get('symbol')) for r in diagnostics if r['status'] == 'exact'}
    prefixes = {('??_7' + owner[1] + '@@').encode('ascii') for _, symbol in checks if symbol
                for owner in [re.match(r'^\?[^?@$]+@([^?$]+?)@@', symbol)] if owner}
    import sys
    sys.path.insert(0, str(root / 'rebuild/2008-06/tests'))
    import native_check_runner as checker
    tables, inputs, rejected, include_contexts = [], {}, [], []
    seen = set()
    for build in builds:
        if build.get('status') != 'complete' or not build.get('object'):
            continue
        try:
            source, obj = Path(build['source']).resolve(), Path(build['object']).resolve()
            source.relative_to(root / 'rebuild/2008-06/native-classes')
            obj.relative_to(root / 'work/2008-06')
            if str(obj) in seen:
                continue
            seen.add(str(obj))
            raw = obj.read_bytes()
            if not any(prefix in raw for prefix in prefixes):
                continue
            expected = dict(build['dependencies'])
            expected[str(source)] = build['source_sha256']
            expected[str(obj)] = build['object_sha256']
            if not build.get('build_inputs') or any(sha(p) != digest for p, digest in expected.items()):
                raise ValueError('stale or incomplete compiler evidence')
            # Do not reuse an experimental compiler environment as baseline evidence.
            if checker.build_changes(build, checker.selected_toolchain({})):
                raise ValueError('compiler configuration changed')
            snapshot = checker.include_search_snapshot(source, build['flags'], obj.parent, build['build_inputs'])
            if not snapshot or snapshot != build.get('include_search_snapshot'):
                raise ValueError('include search context changed')
            found = coff_tables(raw)
            if found:
                tables.extend(dict(t, object=str(obj), object_sha256=build['object_sha256']) for t in found)
                inputs.update(expected)
                inputs.update(build['build_inputs'].get('compiler', {}))
                inputs.update(build['build_inputs'].get('build_tools', {}))
                include_contexts.append({key: build[key] for key in
                    ('source', 'object', 'flags', 'build_inputs', 'include_search_snapshot')})
        except (OSError, ValueError, KeyError, TypeError) as error:
            rejected.append({'source': build.get('source'), 'reason': str(error)})
    evidence = bind_tables(tables, original, checks)
    # Pin the exact context, including every parsed table object's real headers.
    changed = [name for name, digest in inputs.items() if sha(name) != digest]
    if changed:
        evidence = []
        rejected.append({'reason': 'identity inputs changed during verification', 'paths': changed})
    inputs[str(original_path)] = original_hash
    inputs[str(Path(__file__).resolve())] = verifier_hash
    if sha(original_path) != original_hash or sha(__file__) != verifier_hash:
        evidence = []
        rejected.append({'reason': 'original image or identity verifier changed during verification'})
    result = {'identities': evidence, 'inputs': inputs, 'include_contexts': include_contexts, 'rejected': rejected,
              'verifier_sha256': verifier_hash,
              'scope': 'Original PE RTTI class + complete primary vtable + matching compiled method ordinal. Code/data/calls remain separate; no ABI/runtime/server credit.'}
    atomic_json(output_dir / 'identity-vtables.json', result)
    return result
