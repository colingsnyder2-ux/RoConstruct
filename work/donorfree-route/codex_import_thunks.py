"""Resolve original import thunks only when a DLL-specific symbol is unambiguous."""
import re
import struct
from collections import defaultdict


def import_symbols(linked_imports, map_lines, extra_imports):
    """Pair linked IAT symbols and declared extra-library aliases with their DLL exports."""
    result = defaultdict(set)
    for line in map_lines:
        fields = line.split()
        if len(fields) < 4 or not fields[1].startswith('__imp_'):
            continue
        try:
            imported = linked_imports.get(int(fields[2], 16))
        except ValueError:
            continue
        if imported:
            result[imported].add(fields[1][6:])
    for alias in extra_imports.get('aliases', []):
        left, separator, right = alias.partition('=')
        if not separator or not right.startswith('_'):
            continue
        export = right[1:]
        for dll, exports in extra_imports.get('per', {}).items():
            if export in exports:
                candidates = result[(dll.lower(), export)]
                candidates.discard(right)
                candidates.add(left)
    return result


def import_thunk_aliases(image, image_base, imports, names, symbols_by_import):
    aliases = {}
    for name in names:
        match = re.fullmatch(r'func_([0-9a-f]{8})', name)
        if not match:
            continue
        offset = int(match[1], 16) - image_base
        if offset < 0 or image[offset:offset + 2] != b'\xff\x25' or offset + 6 > len(image):
            continue
        imported = imports.get(struct.unpack_from('<I', image, offset + 2)[0])
        candidates = symbols_by_import.get(imported, set())
        if len(candidates) == 1:
            aliases[name] = next(iter(candidates))
    return aliases
