"""Reference-identity receipt for linker import thunks in the 2008-06 exe.

A native body compiled without __declspec(dllimport) calls `??0Exception@Ogre@@QAE@ABV01@@Z` directly; the original
links that call to a thunk `jmp dword ptr [__imp_...]`. This binds each decorated C++ import to its thunk address,
read from the exe: the bytes are FF 25 <IAT slot> and the slot's import name is that symbol. Only C++ names ('?'),
only when exactly one thunk jumps through the slot. Feed the output as native_bulk family evidence.

  python work/native-client/import_thunk_identities.py   -> work/native-client/import-thunk-identities.json
"""
import argparse
import hashlib
import json
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match, standins  # noqa: E402

OUT = ROOT / 'work/native-client/import-thunk-identities.json'


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--mfc-ordinals', action='store_true', help='resolve MFC ordinal imports through the RTM export definition')
    ap.add_argument('--output', type=Path, default=OUT)
    args = ap.parse_args()
    base, image = match._image('2008-06')
    imports = standins._imports('2008-06')            # IAT slot va -> 'dll!name'
    sources = {}
    ordinals = defaultdict(set)
    if args.mfc_ordinals:
        definition = ROOT / 'tools/libs/mfc-9.0-rtm/atlmfc/src/mfc/intel/mfc90.def'
        for name, number in re.findall(r'^\s*(\?\S+)\s+@\s*(\d+)\s+NONAME\b', definition.read_text(errors='replace'), re.M | re.I):
            ordinals[int(number)].add(name)
        sources[definition.relative_to(ROOT).as_posix()] = hashlib.sha256(definition.read_bytes()).hexdigest()
        executable = ROOT / 'clients/2008-06/Roblox.exe'
        sources[executable.relative_to(ROOT).as_posix()] = hashlib.sha256(executable.read_bytes()).hexdigest()
        starts = set(match._functions('2008-06'))
    thunks = defaultdict(list)
    ordinal_names = set()
    ordinal_metadata = defaultdict(set)
    for slot, imported in imports.items():
        dll, name = imported.split('!', 1)
        if args.mfc_ordinals and dll.lower() == 'mfc90.dll' and re.fullmatch(r'#\d+', name):
            matches = ordinals.get(int(name[1:]), set())
            if len(matches) != 1:
                continue
            ordinal = int(name[1:])
            name = next(iter(matches))
            ordinal_names.add(name)
            ordinal_metadata[name].add((ordinal, slot))
        if not name.startswith('?'):
            # C names: only the VS2008 CRT DLLs, whose exports are cdecl, so the COFF name is '_' + export name.
            if dll.lower() not in ('msvcr90.dll', 'msvcp90.dll') or name.startswith('#'):
                continue
            name = '_' + name
        pattern = b'\xff\x25' + struct.pack('<I', slot)
        at = image.find(pattern)
        while at >= 0:
            if name not in ordinal_names or f'{base + at:08x}' in starts:
                thunks[name].append(base + at)
            at = image.find(pattern, at + 1)
    rows = [{'symbol': name, 'address': '%08x' % sites[0], 'evidence': 'FF 25 jmp through IAT slot of this import'}
            for name, sites in sorted(thunks.items()) if len(sites) == 1]
    for row in rows:
        metadata = ordinal_metadata.get(row['symbol'], set())
        if len(metadata) == 1:
            ordinal, slot = next(iter(metadata))
            row.update(evidence='RTM mfc90.def ordinal and original IAT thunk',
                       dll='mfc90.dll', ordinal=ordinal, iat_address=f'{slot:08x}')
    # dllimport calls name the IAT slot itself (__imp_<COFF name>): bind each uniquely named slot.
    slots = defaultdict(set)
    for slot, imported in imports.items():
        dll, name = imported.split('!', 1)
        if name.startswith('?'):
            slots['__imp_' + name].add(slot)
        elif dll.lower() in ('msvcr90.dll', 'msvcp90.dll') and not name.startswith('#'):
            slots['__imp__' + name].add(slot)
    bound = {row['symbol'] for row in rows}
    rows += [{'symbol': s, 'address': '%08x' % next(iter(v)), 'evidence': 'original import address table slot'}
             for s, v in sorted(slots.items()) if len(v) == 1 and s not in bound]
    # Every RTTI type descriptor starts with a pointer to the CRT type_info vtable: bind it when all agree.
    from roc import rtti
    firsts = {struct.unpack_from('<I', image, va - base)[0] for va in rtti.descriptors('2008-06')}
    if len(firsts) == 1:
        rows.append({'symbol': '??_7type_info@@6B@', 'address': '%08x' % firsts.pop(),
                     'evidence': 'first word of every RTTI type descriptor in the exe'})
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps({'scope': __doc__.splitlines()[0], 'sources': sources, 'rows': rows,
                                       'ambiguous': sorted(n for n, s in thunks.items() if len(s) > 1)}, indent=1) + '\n')
    print(json.dumps({'thunk_bindings': len(rows), 'ambiguous': sum(len(s) > 1 for s in thunks.values())}))


if __name__ == '__main__':
    main()
