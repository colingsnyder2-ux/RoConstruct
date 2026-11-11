"""Reference-identity receipt for linker import thunks in the 2008-06 exe.

A native body compiled without __declspec(dllimport) calls `??0Exception@Ogre@@QAE@ABV01@@Z` directly; the original
links that call to a thunk `jmp dword ptr [__imp_...]`. This binds each decorated C++ import to its thunk address,
read from the exe: the bytes are FF 25 <IAT slot> and the slot's import name is that symbol. Only C++ names ('?'),
only when exactly one thunk jumps through the slot. Feed the output as native_bulk family evidence.

  python work/native-client/import_thunk_identities.py   -> work/native-client/import-thunk-identities.json
"""
import json
import struct
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from roc import match, standins  # noqa: E402

OUT = ROOT / 'work/native-client/import-thunk-identities.json'


def main():
    base, image = match._image('2008-06')
    imports = standins._imports('2008-06')            # IAT slot va -> 'dll!name'
    thunks = defaultdict(list)
    for slot, imported in imports.items():
        dll, name = imported.split('!', 1)
        if not name.startswith('?'):
            # C names: only the VS2008 CRT DLLs, whose exports are cdecl, so the COFF name is '_' + export name.
            if dll.lower() not in ('msvcr90.dll', 'msvcp90.dll') or name.startswith('#'):
                continue
            name = '_' + name
        pattern = b'\xff\x25' + struct.pack('<I', slot)
        at = image.find(pattern)
        while at >= 0:
            thunks[name].append(base + at)
            at = image.find(pattern, at + 1)
    rows = [{'symbol': name, 'address': '%08x' % sites[0], 'evidence': 'FF 25 jmp through IAT slot of this import'}
            for name, sites in sorted(thunks.items()) if len(sites) == 1]
    # Every RTTI type descriptor starts with a pointer to the CRT type_info vtable: bind it when all agree.
    from roc import rtti
    firsts = {struct.unpack_from('<I', image, va - base)[0] for va in rtti.descriptors('2008-06')}
    if len(firsts) == 1:
        rows.append({'symbol': '??_7type_info@@6B@', 'address': '%08x' % firsts.pop(),
                     'evidence': 'first word of every RTTI type descriptor in the exe'})
    OUT.write_text(json.dumps({'scope': __doc__.splitlines()[0], 'sources': {}, 'rows': rows,
                               'ambiguous': sorted(n for n, s in thunks.items() if len(s) > 1)}, indent=1) + '\n')
    print(json.dumps({'thunk_bindings': len(rows), 'ambiguous': sum(len(s) > 1 for s in thunks.values())}))


if __name__ == '__main__':
    main()
