"""Conservative layout gate for Roblox's executable-local Ogre fork.

Inputs are binary-derived ABI evidence plus existing native header evidence.  It
never adds fields: a class is accepted only when allocation size, ctor/dtor
stores, and every observed nonzero vptr offset have an explicit header-evidence
offset.  The result is a native_llm preflight input, not a header generator.
"""
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ABI = ROOT / 'rebuild/2008-06/manifests/abi-evidence.json'
IDENTITY = ROOT / 'work/native-client/ogre-rbxscenemanager-shadow-merged-closure.json'
HEADERS = ROOT / 'rebuild/2008-06/native-headers'
OUT = ROOT / 'work/native-client/ogre-layout-solutions.json'


def addr_names():
    rows = json.loads(IDENTITY.read_text()).get('bindings', [])
    return {row.get('addr', row.get('address', '')).lower(): row['symbol'] for row in rows if row.get('symbol')}


def header_for(short):
    pattern = re.compile(r'\bclass\s+' + re.escape(short) + r'\b')
    for path in sorted(HEADERS.rglob('*.h')):
        text = path.read_text(errors='replace')
        if pattern.search(text):
            return path, text
    return None, ''


def comment_offsets(text):
    return {int(value, 16) for value in re.findall(r'\+0x([0-9a-fA-F]+)', text)}


def evidence_size(name, text, item):
    sizes = {int(value, 16) for value in item.get('alloc_sizes', {})}
    if len(sizes) == 1:
        return next(iter(sizes)), 'abi-evidence.alloc_sizes'
    short = name.rsplit('::', 1)[-1]
    match = re.search(r'sizeof\s*\(\s*' + re.escape(short) + r'\s*\)\s*==\s*(0x[0-9a-fA-F]+)', text)
    if match:
        return int(match.group(1), 16), 'header-size-assert'
    match = re.search(r'(?:allocation is|size)\s*(0x[0-9a-fA-F]+)', text, re.I)
    if match:
        return int(match.group(1), 16), 'header-binary-evidence'
    return None, None


def receiver_vptr_offsets(stores):
    """Only receiver-relative stores establish an object vptr offset.

    ``[+0x...]`` is an absolute image address in the ABI scanner output, not an
    offset from ``this``.  Treating it as a member offset can accidentally turn
    a global vtable assignment into a layout claim.
    """
    offsets = set()
    for entries in stores.values():
        for place, _ in entries:
            match = re.fullmatch(r'\[(?:ecx|esi|edi|eax)\+0x([0-9a-fA-F]+)\]', place)
            if match:
                offsets.add(int(match.group(1), 16))
    return sorted(offsets)


def main():
    abi, names = json.loads(ABI.read_text()), addr_names()
    rows = []
    for name, item in sorted(abi.items()):
        if not name.startswith('Ogre::Rbx'):
            continue
        short = name.rsplit('::', 1)[-1]
        header, text = header_for(short)
        stores = item.get('vptr_stores', {})
        offsets = receiver_vptr_offsets(stores)
        size, size_source = evidence_size(name, text, item)
        explained = comment_offsets(text)
        unexplained = [offset for offset in offsets if offset and offset not in explained]
        ctor = [address for address in stores if names.get(address.lower(), '').startswith('??0')]
        dtor = [address for address in stores if names.get(address.lower(), '').startswith('??1')]
        reason = []
        if not header:
            reason.append('no-native-header')
        if not size:
            reason.append('no-proven-allocation-size')
        if 'NO LAYOUT IS CLAIMED' in text:
            reason.append('header-explicitly-layout-incomplete')
        if unexplained:
            reason.append('unexplained-vptr-offsets:' + ','.join('0x%x' % x for x in unexplained))
        if not ctor:
            reason.append('no-identity-proved-ctor-store')
        if not dtor:
            reason.append('no-identity-proved-dtor-store')
        rows.append({'owner': name, 'header': str(header.relative_to(ROOT)) if header else None,
                     'allocation_size': size, 'allocation_size_source': size_source,
                     'ctor_store_addrs': ctor, 'dtor_store_addrs': dtor,
                     'observed_vptr_offsets': offsets, 'explained_offsets': sorted(explained),
                     'accepted': not reason, 'blocked': reason})
    OUT.write_text(json.dumps({'scope': 'Ogre executable-local fork; no generated layouts',
                               'rows': rows,
                               'accepted': sum(row['accepted'] for row in rows),
                               'blocked': sum(not row['accepted'] for row in rows)}, indent=1) + '\n')
    print(json.dumps({'classes': len(rows), 'accepted': sum(row['accepted'] for row in rows),
                      'blocked': sum(not row['accepted'] for row in rows), 'output': str(OUT)}, sort_keys=True))


if __name__ == '__main__':
    main()
