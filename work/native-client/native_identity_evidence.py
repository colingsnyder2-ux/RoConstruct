"""Make native-bulk evidence receipts from deterministic identity-closure bindings.

This does not generate code or grant proof.  It only carries a selected closed
symbol/address identity into native-bulk, with the closure hash as an input.
"""
import argparse
import hashlib
import json
import os
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))


def import_thunks(imports, duplicates):
    """(symbol, 'addr') for every IAT slot with exactly one ``FF 25 <slot>`` thunk in the 2008-06 exe's .text."""
    import re
    import struct
    import pefile
    pe = pefile.PE(str(ROOT / 'clients/2008-06/Roblox.exe'), fast_load=True)
    text = next(s for s in pe.sections if s.Name.rstrip(b'\0') == b'.text')
    data, base = text.get_data(), pe.OPTIONAL_HEADER.ImageBase + text.VirtualAddress
    thunks = {}
    for found in re.finditer(rb'\xff\x25(....)', data, re.S):
        at = found.start()
        # A thunk sits between thunks, or after ret/padding; a dllimport tail call inside a body does not.
        if not (data[at - 6:at - 4] == b'\xff\x25' or data[at + 6:at + 8] == b'\xff\x25' or data[at - 1:at] in (b'\xc3', b'\xcc', b'\x90')):
            continue
        thunks.setdefault(struct.unpack('<I', found.group(1))[0], []).append(base + found.start())
    for symbol, slot in imports.items():
        sites = thunks.get(slot, [])
        if symbol not in duplicates and len(sites) == 1:
            name = symbol[len('__imp_'):]
            yield (name if name.startswith('?') else '_' + name), f'{sites[0]:08x}'


CACHE = ROOT / 'work/cache/2008-06-exe-imports.json'


def exe_facts():
    """(imports {__imp_X: va}, duplicate spellings, [(thunk symbol, addr)]) from the 2008-06 exe, cached on disk by
    exe size+mtime: standins._imports() parses every PE relocation (~5-10 s) on each gate otherwise."""
    exe = ROOT / 'clients/2008-06/Roblox.exe'
    key = '%d-%d' % (exe.stat().st_size, exe.stat().st_mtime_ns)
    try:
        cached = json.loads(CACHE.read_text())
        if cached.get('key') == key:
            return cached['imports'], set(cached['duplicates']), [tuple(row) for row in cached['thunks']]
    except (OSError, ValueError, KeyError):
        pass
    from roc import standins
    imports, duplicates = {}, set()
    for address, imported in standins._imports('2008-06').items():
        symbol = '__imp_' + imported.split('!', 1)[1]
        if symbol in imports and imports[symbol] != address:
            duplicates.add(symbol)
        else:
            imports[symbol] = address
    thunks = list(import_thunks(imports, duplicates))
    CACHE.parent.mkdir(parents=True, exist_ok=True)
    tmp = CACHE.with_suffix('.%d.tmp' % os.getpid())
    tmp.write_text(json.dumps({'key': key, 'imports': imports, 'duplicates': sorted(duplicates), 'thunks': thunks}))
    os.replace(tmp, CACHE)
    return imports, duplicates, thunks


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--closure', type=Path, required=True)
    ap.add_argument('--addr', action='append', required=True)
    ap.add_argument('--extra-bindings', type=Path, action='append', default=[],
                    help='exact-owner reference-alias receipts')
    ap.add_argument('--output', type=Path, required=True)
    args = ap.parse_args()
    closure = args.closure.resolve()
    wanted = {f'{int(value, 16):08x}' for value in args.addr}
    closure_data = json.loads(closure.read_text())
    # Folded identical bodies share one address (JointInstance/AutoJoint::askSetParent 005e3790): the
    # function-start binding is the target; a later reference alias must not replace it.
    bindings = {}
    for row in closure_data['bindings']:
        if row.get('function_start') or row['addr'] not in bindings:
            bindings[row['addr']] = row
    missing = sorted(wanted - bindings.keys())
    if missing:
        raise ValueError('unbound addresses: ' + ', '.join(missing))
    rows = []
    for addr in sorted(wanted):
        row = bindings[addr]
        if not row.get('function_start'):
            raise ValueError('not a function-start binding: ' + addr)
        rows.append({'symbol': row['symbol'], 'address': addr,
                     'identity_evidence': row['evidence'], 'votes': row['votes']})
    # Reference auditing must also know a selected body's closure-bound
    # callees/data.  The closure has already removed conflicting symbols, so
    # carry its complete fixed point instead of guessing a dependency cut.
    selected_symbols = {row['symbol'] for row in rows}
    rows.extend({'symbol': row['symbol'], 'address': row['addr'],
                 'identity_evidence': row['evidence'], 'votes': row['votes']}
                for row in closure_data['bindings']
                if row['symbol'] not in selected_symbols)
    # The PE import table proves an IAT slot's exported spelling and target VA.
    # Keep only one-slot spellings: duplicate import spellings stay unbound just
    # like closure conflicts.
    imports, duplicates, thunk_rows = exe_facts()
    closure_symbols = {row['symbol'] for row in rows}
    rows.extend({'symbol': symbol, 'address': f'{address:08x}',
                 'identity_evidence': 'original-iAT', 'votes': 1}
                for symbol, address in sorted(imports.items())
                if symbol not in duplicates and symbol not in closure_symbols)
    # A CRT/DLL import called directly (``call ___CxxFrameHandler3``) goes through the
    # linker's one ``jmp dword ptr [IAT]`` thunk in .text.  A thunk that is the only
    # jump through its slot proves the import's object-level symbol at that address
    # (C exports gain the cdecl ``_`` prefix; mangled C++ names are unchanged).
    # Already-bound: __purecall 006a16be agrees.  New: ___CxxFrameHandler3 006a14c0.
    known = {row['symbol'] for row in rows}
    taken = {row['address'].lower() for row in rows}
    for symbol, address in thunk_rows:
        if symbol not in known and address not in taken:
            rows.append({'symbol': symbol, 'address': address, 'identity_evidence': 'original-iAT-jmp-thunk', 'votes': 1})
    by_symbol = {row['symbol']: row['address'].lower() for row in rows}
    for path in args.extra_bindings:
        extra = json.loads(path.read_text())
        for row in extra.get('identity_bindings', []):
            symbol, address = row['symbol'], row['address'].lower()
            if symbol in by_symbol and by_symbol[symbol] != address:
                raise ValueError('extra binding conflicts: ' + symbol)
            if symbol not in by_symbol:
                rows.append(dict(row, address=address))
                by_symbol[symbol] = address
    try:
        source = closure.relative_to(ROOT).as_posix()
    except ValueError:
        raise ValueError('closure must remain inside repository')
    out = {'scope': 'identity evidence only; native-bulk still compiles and byte-proves every body',
           'sources': {source: hashlib.sha256(closure.read_bytes()).hexdigest()},
           'identity_bindings': rows,
           'unbound_import_conflicts': sorted(duplicates)}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(out, separators=(',', ':')) + '\n')     # 33k rows: indent cost ~4 s/gate
    print('bindings', len(rows), 'output', args.output)


if __name__ == '__main__':
    main()
